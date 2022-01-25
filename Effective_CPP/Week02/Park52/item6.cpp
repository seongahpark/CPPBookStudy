#include <iostream>

class HomeForSale{
public:
    HomeForSale();
private:
    HomeForSale(const HomeForSale&);
    HomeForSale& operator=(const HomeForSale&);
};
int main(int argc, char* argv[])
{
    HomeForSale h1;
    HomeForSale h2;

    HomeForSale h3(h1);
    h2 = h1;

    return 0;
}