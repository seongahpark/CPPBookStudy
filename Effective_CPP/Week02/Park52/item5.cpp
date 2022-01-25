#include <iostream>

template<class T>
class NamedObject {
public:
    NamedObject(std::string& name, const T& value);

private:
    std::string& nameValue;
    const T objectValue;
};

int main(int argc, char* argv[])
{
    std::string newDog("Persephone");
    std::string oldDog("Satch");

    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);

    p = s;

    return 0;
}