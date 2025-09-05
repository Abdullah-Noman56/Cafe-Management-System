#include "Student.h"
 
Student::Student(char* a)
{
    name = new char[20];
    name = a;
	       fstream fx;
		   fx.open("Login.txt",ios::out|ios::app); 
		  

		  cout<<endl;
		  fx<<"Student\n";
		  fx<<"Customer Name : "<<name<<endl;
		  fx.close();


}

Student::~Student()
{

}

void Student::search()
{
    Order::search();
}
void Student::order()
{
    Order::order();
}
void Student::Complaints() 
{
    cin.ignore(); 
    char a[150];
    cout << "Enter your complaint: ";
    cin.getline(a, 150);
    fstream myFile;
    myFile.open("Complaints.txt", ios::in | ios::app);
    myFile << "Student : " << a <<endl ;
}

void Student::Notification()
 {
   fstream myFile;
    myFile.open("Notification.txt", ios::in);

    int i = 0;
    char noti[1000][100];

    while (myFile.getline(noti[i], 100, '\n')) {
        i++;
    }

    for (int k = 0; k < i; k++) {
        cout << noti[k] << endl;
    }

    myFile.close();
  }

  void Student::scheduled()
  {
    Order::scheduled();
  }