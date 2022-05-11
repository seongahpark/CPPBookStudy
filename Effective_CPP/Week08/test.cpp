#include <iostream>
using namespace std;

class Animal{
    public:
        void Func(){
            cout << "Animal" << endl;
        }
};

class Cat : public Animal{
    public:
        virtual void Func(){
            cout << "Cat" << endl;
        }
};

class Dog : public Cat{
    public:
        void Func(){
            cout << "Dog" << endl;
        }
};

int main(){
    Animal *aaa = new Dog();
    aaa->Func();
}