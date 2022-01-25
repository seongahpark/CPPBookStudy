## 개념
---
1. **기본 생성자(Default constructor)**
프로그래머가 정의한 생성자가 없는, 자동적으로 컴파일러에 의해 생성되는 생성자를 가리킵니다.
C++의 경우에는 생성자가 자동으로 생성되었는지나 사용자가 정의했는지와 관련 없이, 인자를 제공하지 않은 생성자를 말합니다.

2. **복사 생성자(copy constructor)**
어떤 객체의 초기화를 위해 그와 같은 타입의 객체로부터 초기화할 때 호출되는 함수.
간단히 왜곡하자면 func A 에 func B 를 복사해주는 것이라고 할 수 있습니다.

3. **복사 대입 연산자(copy assignment operator)**
같은 타입의 다른 객체에 어떤 객체의 값을 복사하는 용도로 쓰이는 함수.
간단히 왜곡하자면 func A 에 func B 를 대입해주는 것이라고 할 수 있습니다.

</br>

## 선언

아래는 기본적인 선언 형식만 기술하였습니다. 실제 사용을 위해서는 구현부가 필요할 수 있습니다. 구현부 예시는 예제 코드에 기술하겠습니다.

---


1. **기본 생성자(Default constructor)**
```cpp
class Widget {
	...
	Widget();
	...
}
```

2. **복사 생성자(copy constructor)**
```cpp
class Widget {
	...
	Widget(const Widget& rhs);
    	...
}
```

3. **복사 대입 연산자(copy assignment operator)**
```cpp
class Widget {
	...
	Widget& operator = (const Widget& rhs);
    	...
}
```

</br>

## 사용법
---
```cpp
int main()
{
    Widget w1;  // 기본 생성자 호출

    Widget w2(w1);  // 복사 생성자 호출

    w1 = w2;    // 복사 대입 연산자(operator) 호출

    Widget w3 = w2;     // 복사 생성자 호출

    return 0;
}
```

1. ```Widget w1;``` Widget을 선언하는데 아무런 매개변수도 주지 않았고 클래스명만 주었습니다. 기본 생성자를 호출할 것이라고 쉽게 짐작이 가능합니다.

2. ```Widget w2(w1);``` 매개변수로 Widget 타입의 w1을 주었습니다. Widget 클래스에서 매개변수가 1개이고, Widget을 사용하고 있는 것은 바로 ```Widget(const Widget& rhs);``` 즉, 복사 생성자입니다.

3. ```Widget w3 = w2;``` w3를 선언함과 동시에 w2로 초기화 해주고 있습니다. 어떠한 객체가 새로 정의될 때는 생성자가 불려야 합니다. 즉, 복사 생성자를 호출합니다.

4. ```w1 = w2;``` w1에 w2를 넣고(대입하고) 있습니다. 새로운 객체가 정의되지 않는 상황에서는 생성자가 호출되지 않습니다. 따라서 복사 대입 연산자가 호출됩니다.


</br>

## 예제 코드
---
```cpp
#include <iostream>

using namespace std;

class Widget {
public:
    string str;
    int number;

public:
    // 기본 생성자
    Widget()
    {
        number = 1;
        str = "기본 생성자를 호출했습니다.";
        cout << str << endl;
    }   

    // 복사 생성자
    Widget(const Widget& rhs)
    {
        number = 2;
        str = "복사 생성자를 호출했습니다.";
        cout << str << endl;

        // 아래와 같이 rhs의 멤버 변수를 읽어올 수 있다.
        this->number = rhs.number;
        // 하지만 rhs.number = this->number 은 불가능하다. => rhs가 const 이므로
    }  

    // 복사 대입 연산자
    Widget& operator = (const Widget& rhs)
    {
        if (this != &rhs) //다를때만 복사 수행
        { 
            str = "복사 대입연산자를 호출했습니다.";
            cout << str << endl;
        }

        return *this;
    } 

};

int main()
{
    Widget w1;  // 기본 생성자 호출

    Widget w2(w1);  // 복사 생성자 호출

    w1 = w2;    // 복사 대입 연산자(operator) 호출

    Widget w3 = w2;     // 복사 생성자 호출

    return 0;
}
```

### 출력

```cpp
기본 생성자를 호출했습니다.
복사 생성자를 호출했습니다.
복사 대입연산자를 호출했습니다.
복사 생성자를 호출했습니다.
```

## 참고
Effective C++ 3판, 스콧 마이어스 저 / 곽용재 역