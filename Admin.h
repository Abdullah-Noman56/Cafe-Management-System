#ifndef ADMIN_H
#define ADMIN_H

#include"Crediental.h"
#include"stock.h"
#include"order.h"

class Admin : public Credentials, public Stock,public Order 
{
  private: 
   int var;
   char* inputpassword;
   char* name;

  public:
   Admin(char*,char*);  
   void stock();  
   void seeorder();
   void bestemp();
   void Complaint();
   void notification();
   void details();
   void update();
   void threshold();
  ~Admin();


};

#endif