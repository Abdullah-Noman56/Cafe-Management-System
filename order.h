#ifndef ORDER_H
#define ORDER_H

#include"project.h"
#include"login.h"

class Order : public virtual Login
{
  private:
   char** menu;
   int* price;
   int* quantity;
   int size;
  public:
   Order();
   
  void search();
  void seeorder();
  void order();
  void scheduled();

  ~Order(); 
};

#endif
