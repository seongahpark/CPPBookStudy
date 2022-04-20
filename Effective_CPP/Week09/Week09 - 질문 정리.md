# Week 9 - 질문 정리

#### 성아

1. [항목 42] 중첩 의존 이름에서 typename을 사용할 수 없는 예외 사례

   > - 중첩 의존 타입 이름이 기본 클래스의 리스트에 있는 경우
   >
   > - 중첩 의존 타입 이름이 멤버 초기화 리스트 내의 기본 클래스 식별자로 있는 경우
   
2. [항목 43] 호출할 함수가 기본 클래스의 함수라는 점을 명시적으로 지정하는 방법을 지양해야되는 이유 

   > 호출되는 함수가 가상 함수인 경우에 명시적 한정을 해버리면 가상 함수 바인딩이 무시된다
   
3. [항목 44] 비타입 매개변수의 특징을 설명해보시오

   > 타입이 아닌 값. class, typename 키워드 대신 특정 타입을 지정하여 사용
   >
   > 정수형과 boolean 형만 가능하다
   >
   > 상수만 가능하다


<br>

#### 재현


<br>

#### 현준

1. [항목 44] 해당 함수 템플릿의 문제점과 해결 방안

   ```cpp
   #include <iostream>
   using namespace std;

   template <typename T, int n>
   void PrintSize()
   {
      for (int i = 0; i < 40; i++)
         cout << sizeof(T) * n << endl;
   }

   int main()
   {
      PrintSize<double, 1>();
      PrintSize<double, 2>();
      PrintSize<double, 3>();
      PrintSize<double, 4>();
      PrintSize<double, 5>();
      PrintSize<double, 6>();
      PrintSize<double, 7>();
      PrintSize<double, 8>();
      PrintSize<double, 9>();
      PrintSize<double, 10>();
   }
   ```

   > 정답
   ```cpp
   #include <iostream>
   using namespace std;

   template <typename T> // 변경점 1 : 불필요한 템플릿 매개변수 삭제
   void PrintSize(int n) // 변경점 2
   {
      for (int i = 0; i < 40; i++)
         cout << sizeof(T) * n << endl;
   }

   int main()
   {
      // 이제는 함수 템플릿 코드가 1개만 존재한다.
      PrintSize<double>(1); // 변경점 3
      PrintSize<double>(2);
      PrintSize<double>(3);
      PrintSize<double>(4);
      PrintSize<double>(5);
      PrintSize<double>(6);
      PrintSize<double>(7);
      PrintSize<double>(8);
      PrintSize<double>(9);
      PrintSize<double>(10);
   }
   ```
   - [참고 링크](https://www.ikpil.com/556)

2. [항목 43] 템플릿으로 만들어진 기본 클래스 안의 이름에 접근하는 방법

   > 1. Using 키워드 사용
   > 2. this 키워드 사용
   > 3. 기본 클래스 이름과 범위 지정 연산자를 통해 접근

3. [항목 42] 해당 코드는 컴파일이 되지 않는데, 그 이유는?

   ```cpp
   #include <vector>
   #include <iostream>
   using namespace std;

   template <typename T>
   void print(T &container)
   {
      T::const_iterator iter(container.begin());
      cout << *iter << endl;
   }

   int main()
   {
      vector<int> vec = {1, 2, 3};
      print(vec);
   }
   ```

   > 정답
   ```cpp
   #include <vector>
   #include <iostream>
   using namespace std;

   template <typename T>
   void print(T &container)
   {
      // typename 키워드를 사용해서 T::const_iterator는 '타입'임을 명시해준다.
      typename T::const_iterator iter(container.begin());
      cout << *iter << endl;
   }

   int main()
   {
      vector<int> vec = {1, 2, 3};
      print(vec);
   }
   ```

