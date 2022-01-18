#include <iostream>
class TEST
{
private:
       mutable int number;
public:
       void SetNumber(int n) const {
              number = n;
       }
       int GetNumber() const {
              return number;
       }
};
int main(void) {
       TEST test1;
       const TEST test2;
       test1.SetNumber(100);
       test2.SetNumber(200); // const로 선언됐지만 값 변경 가능
}
