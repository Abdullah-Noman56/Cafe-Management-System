#ifndef LOGIN_H
#define  LOGIN_H

#include "project.h"
class Login 
{
    
  public:
   
    Login();
    virtual void details();
    virtual void stock();
    virtual void update();
    virtual void search();
    virtual void seeorder();
    virtual void order();
    virtual void scheduled();
    virtual void credentials();
    virtual void bestemp();
    virtual void threshold();
    virtual void Complaint();
    virtual void notification();
    virtual void transaction(char*);
    virtual void Notification();
    virtual void Complaints();
    virtual ~Login();
    

};

#endif