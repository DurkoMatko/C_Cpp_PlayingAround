#include "Manager.h"
#include <sstream>

using namespace std;

Manager::Manager():salaried(true)
{

};

Manager::Manager(string name,double payRate, bool isSalaried):Employee(name,payRate){
    salaried=isSalaried;
};

Manager::~Manager()
{
    //dtor
};

bool Manager::isSalaried(){
    return this->salaried;
};

void Manager::setIsSalaried(bool isSalaried){
    salaried=isSalaried;
};


double Manager::getGrossPay(int hours){
    if(salaried){
        return pay;
    }
    return hours*pay;
};

string Manager::toString(){
    stringstream stm;
    string salary;
    if(salaried){
        salary="Salaried";
    }
    else{
        salary="Hourly";
    }
    stm << name <<": "<<pay << " - " << salary << endl;
    return stm.str();

};
