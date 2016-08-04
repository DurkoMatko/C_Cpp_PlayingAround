#include <iostream>
#include "point.h"
#include "list.h"
#include "point.cpp"
#include "list.cpp"




int main()
{
    //points part
    point a = point();
    point b = point{4,5};
    cout << "a=" << a << " b=" << b << endl;
    cout << "sum = " << a + b << endl;


    //list part
    list c,d;
    c.prepend(9);c.prepend(8);
    cout << "list c:" << endl;
    c.print();

    for(int i=0; i<40; ++i){
        d.prepend(i*i);
    }
    cout << "list b:" << endl;
    d.print();
    return 0;
}
