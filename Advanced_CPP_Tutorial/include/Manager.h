#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"

class Manager : public Employee
{
    public:
        Manager();
        Manager(string name,double payRate, bool isSalaried);
        virtual ~Manager();
        void setIsSalaried(bool isSalaried);
        bool isSalaried();
        virtual double getGrossPay(int hours);
        virtual string toString();
    protected:
    private:
        bool salaried;
};

#endif // MANAGER_H
