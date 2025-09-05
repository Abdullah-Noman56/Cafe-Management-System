#ifndef CREDIENTAL_H
#define CREDIENTAL_H

#include "project.h"
#include "login.h"
class Credentials : public virtual Login
{
 private:
   char** name;
   char** password;
   int size;
  
 public:
  
   Credentials();
   void credentials();
   void bestemp();
   ~Credentials();
};


#endif
