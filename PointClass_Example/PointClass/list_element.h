#ifndef LIST_ELEMENT_H_INCLUDED
#define LIST_ELEMENT_H_INCLUDED

using namespace std;

// LIST ELEMENT
class list_element{
public:
    list_element(int n=0,list_element* ptr=0):
        d(n),next(ptr){}
    int d;
    list_element* next;
};



#endif // LIST_ELEMENT_H_INCLUDED
