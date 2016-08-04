#include <iostream>
#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "Shape.h"
#include "Stack.h"

using namespace std;

template <typename T>
void displayArray(T arr[],int size){
    for (int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T max(T &arg1, T &arg2){
    if(arg1>arg2){
        return arg1;
    }
    else{
        return arg2;
    }
}

int main()
{
    Employee* emp1 = new Employee("Martin",4.4);
    Employee emp2("Peter",2);

    cout << emp1->getName()<<endl;      //is pointer so using -> instead of .
    //cout<< emp2.getName() << " has gross pay "<< emp2.getGrossPay(40) << endl;

    Manager man1("Robert",3,true);
    //cout<< man1.getName() << " has gross pay "<< man1.getGrossPay(40) << endl;
    cout << man1.toString() << endl;


    ///POLYMOPHISM DEMONSTRATION - NOT WORKING! - manager calls getGrossPay from Employee -> Solution: add virtual to overloaded method declarations
    vector <Employee*> emps;        //container
    emps.push_back(&emp2);
    emps.push_back(&man1);
    for(int i=0;i<emps.size();i++){
        cout << emps[i]->toString() << endl;    //can be emps.at(i) as well
    }


    ///ABSTACT CLASS - Shape
    cout << endl << "ABSTACT CLASS - Shape" << endl;
    Circle c1(4,7,3);
    c1.draw();
    cout << endl;


    /// GENERIC PROGRAMMING
    cout << endl << "GENERIC PROGRAMMING" << endl;
    const int size = 10;
    int numbers[size];
    for(int i=0;i<size;i++){
        numbers[i]=i;
    }
    displayArray(numbers,size);

    string names[]={"Jim","Ted","Bil","Peter","Johny","Jim","Ted","Bil","Peter","Johny"};
    displayArray(names,size);

    double x=0.25;
    double y=2.23;
    cout << max(x,y) <<endl;

    string s1="test1";
    string s2="test2";
    cout << max(s1,s2) <<endl;

    ///CLASS TEMPLATES
    cout << endl <<"CLASS TEMPLATES" << endl;
    Stack<int> stack;
    stack.push(12);
    stack.push(22);
    cout << stack.peek() << endl;
    stack.pop();
    cout << stack.peek() << endl;

    Stack<string> stringStack;
    stringStack.push("Hello ");
    stringStack.push("world");
    cout << stringStack.peek() << endl;
    stringStack.pop();
    cout << stringStack.peek() << endl;

    return 0;
}
