#include <iostream>
#include "list.h"


using namespace std;

//CONSTRUCTOR
list::list():
    head(),
    cursor(){}

void list::prepend(int n){
        if(head==0){
            cursor=head=new list_element(n,head);
        }
        else{
            head=new list_element(n,head);
        }
    }


//FUNCTIONS
int list::get_element(){
    return cursor->d;
}

void list::advance(){
    cursor=cursor->next;
}

void list::print(){
    list_element* h = head;
    while(h!=0){
            cout << h->d << ",";
            h=h->next;
    }
    cout << "###" << endl;
}
