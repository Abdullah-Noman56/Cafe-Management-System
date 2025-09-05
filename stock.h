#ifndef STOCK_H
#define STOCK_H

#include "project.h"
#include "login.h"
class Stock : public virtual Login
{
  private:
    char** menu;
    int size;
    int* price;
    int* quantity;
    
  public: 
    Stock();
    void details();
    void stock();
    void update();
    ~Stock();
};


#endif
