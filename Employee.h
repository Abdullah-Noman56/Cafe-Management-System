#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "order.h"
#include "project.h"
class Employee : public Order
{
  int var;
  char** name;
  char** inputpassword;
   public:
    
    Employee(char*,char* );
    void search();
    void seeorder();
    void order();
    void SalesUpdate(char*);
    void transaction(char*);

    ~Employee();
}; 

#endif