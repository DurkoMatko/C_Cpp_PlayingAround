#include <iostream>
#include "list_element.h"

using namespace std;

//LIST_ELEMENT CLASS

list_element::list_element(int n,list_element* ptr):
        d(n),
        next(ptr){}
