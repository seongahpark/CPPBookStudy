//
//  항목4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자
//
#include <iostream>
#include <list>

class PhoneNumber{};
class ABEntry{
public:
    ABEntry();
    ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones);

private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int numTimesConsulted;
};
ABEntry::ABEntry()
    : theName(),
      theAddress(),
      thePhones(),
      numTimesConsulted(0)
{

}

ABEntry::ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
:   theName(name),
    theAddress(address),
    thePhones(phones),
    numTimesConsulted(0)
{

}