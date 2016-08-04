#include "list_element.h"

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


using namespace std;

// LIST CLASS
class list{
public:
    list();
    void prepend(int n);
    int get_element();
    void advance();
    void print();
private:
   list_element* head;
   list_element* cursor;
};

#endif // LIST_H_INCLUDED
