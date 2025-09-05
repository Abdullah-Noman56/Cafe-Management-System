#ifndef STUDENT_H
#define STUDENT_H

#include "order.h"

class Student : public Order
{
 private:
  int var;
  char* name;
  
 public:
  Student(char*); 
  void search();
  void order();
  void Complaints();
  void Notification();
  void scheduled();
  ~Student();
};

#endif