class Widget{
    void swap(Widget& rhs);
};

Widget& Widget::operator=(const Widget& rhs)
{
    Widget temp(rhs);
    swap(temp);

    return *this;
}

Widget& Widget::operator=(Widget rhs)
{
    swap(rhs);

    return *this;
}