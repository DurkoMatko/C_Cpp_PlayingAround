#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string empName, double payRate);
        virtual ~Employee();
        string getName();
        void setName(string empName);
        double getPay();
        void setPay(double payRate);
        virtual string toString();
        virtual double getGrossPay(int hours);

    protected:
        string name;
        double pay;
};

#endif // EMPLOYEE_H
