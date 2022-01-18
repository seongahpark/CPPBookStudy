//
//  항목3: 낌새만 보이면 cosnt를 들이대 보자!
//
#include <iostream>
#include <vector>

class Widget{};
void f1(const Widget *pw);  //  f1은 상수 Widget 객체에 대한
                            //  포인터를 매개변수로 취합니다.
void f1(Widget const *pw);  //  f2도 그렇다

class Rational{};
const Rational operator*(const Rational& lhs, const Rational& rhs);     // 실수 방지

//  상수 멤버 함수
class TextBlock {
public:
    TextBlock(const char* param1)
    :   text(param1)
    {
    }
    const char& operator[] (std::size_t position) const
    {   return text[position];    }

    char& operator[] (std::size_t position)
    { return text[position];}

private:
    std::string text;
};

void print(const TextBlock& ctb)
{
    std::cout << ctb[0];
}

//  mutable
class CTextBlock{
public:
    std::size_t length() const;

private:
    char* pText;
    mutable std::size_t textlength;
    mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const{
    if(!lengthIsValid)
    {
        textlength = std::strlen(pText);
        lengthIsValid = true;
    }

    return textlength;
}

int main(void)
{
    char greeting[] = "Hello";
    char *p = greeting;                 //  비상수 포인터,
                                        //  비상수 데이터
    
    const char *p = greeting;           //  비상수 포인터,
                                        //  상수 데이터

    char *const p = greeting;           //  상수 포인터,
                                        //  비상수 데이터

    const char *const p = greeting;     //  상수 포인터,
                                        //  비상수 데이터

    std::vector<int> vec;
    const std::vector<int>::iterator iter = vec.begin();
    *iter = 10;
    ++iter;         // Error

    std::vector<int>::const_iterator cIter = vec.begin();
    *cIter = 10;    // Error
    ++cIter;

    Rational a,b,c;
    (a*b) = c;      //  Error

    TextBlock tb("Hello");
    std::cout << tb[0];

    const TextBlock ctb("World");
    std::cout << ctb[0];

    std::cout << tb[0];
    tb[0] = 'x';

    std::cout << ctb[0];
    ctb[0] = 'x';



     return 0;
}