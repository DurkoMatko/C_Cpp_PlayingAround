#include "Employee.h"
#include <sstream>

using namespace std;

Employee::Employee()
{
    name="s";
    pay = 0;
}

Employee::Employee(string empName, double payRate){
    name = empName;
    pay = payRate;
}

Employee::~Employee()
{
    //dtor
}

string Employee::getName(){
    return this->name;
};

void Employee::setName(string empName){
    name=empName;
};

double Employee::getPay(){
    return this->pay;
};

void Employee::setPay(double payRate){
    this->pay=payRate;
};

string Employee::toString(){
    stringstream stm;
    stm << name << ": " << pay;
    return stm.str();
};

double Employee::getGrossPay(int hours){
    return pay*hours;
};
