// class Widget{
//     void swap(Widget& rhs);
// };

// Widget& Widget::operator=(const Widget& rhs)
// {
//     Widget temp(rhs);
//     swap(temp);

//     return *this;
// }

// Widget& Widget::operator=(Widget rhs)
// {
//     swap(rhs);

//     return *this;
// }

#include <iostream>

class Bitmap {};
class Widget {
public:
	Widget();
	~Widget();
	Widget& operator=(const Widget &rhs);
private:
	Bitmap *pb;
};

Widget::Widget()
{
	pb = new Bitmap();
}

Widget::~Widget()
{
	if (nullptr != pb)
	{
		delete pb;
		pb = nullptr;
	}
}

Widget& Widget::operator=(const Widget &rhs)
{
	Bitmap *pOrig = pb;
	pb = new Bitmap(*rhs.pb);
	delete pOrig;

	return *this;
}

int main()
{
	Widget a;
	Widget b;
	a = b;

	return 0;
}