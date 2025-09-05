#include "project.h"
#include "Admin.h"
Admin::Admin(char* adname,char* password) 
{ 
  char Header[30];
  inputpassword = new char[20];
  name = new char[20];

		    fstream myFile;
		    myFile.open("Admin.txt", ios::in|ios::app);

		    myFile.getline(Header, 30, '\n');

		    myFile.getline(name, 51, ' ');   
		    myFile.getline(inputpassword, 21, '\n');
		    myFile.ignore();
      
		    myFile.close();
		if((strcmp(password,inputpassword) == 0)&&(strcmp(name,adname) == 0))
		{
					myFile.open("Login.txt",ios::out|ios::app);
					myFile<<"Admin Login Successfully\n";
					myFile.close(); 
		}
		else
		{
			myFile.open("Login.txt",ios::out|ios::app);
			myFile<<"Admin Login Failed\n";
			myFile.close();
			cout << "\t\t Invalid username or passsword\n\n";
			exit(-1);
		}
}



Admin::~Admin()
{}

void Admin::seeorder()
{
	Order::seeorder();
}
 void Admin::bestemp()
 {
   Credentials::bestemp();
 }
 void Admin::Complaint()
 {
    fstream myFile;
   myFile.open("Complaints.txt");
   char a[1000];
   int i=1;
   while(!myFile.eof())
    {
     myFile.getline(a,1000,'\n');
     cout<<"\t\tComplaints no : "<<i<<" "<<a<<endl;
     i++;
    }
    myFile.close();

 }

void Admin::notification()
{
    fstream myFile;
    myFile.open("Notification.txt", ios::out | ios::app);

    char notification[100];
    cout << "\n\t\tEnter notifications of cafe items, promotions and packages : ";
    cin.ignore(); 
    cin.getline(notification, 100, '\n');

    myFile << "\n\t\tNew Notification\n\t" << notification << "\n\n";

    myFile.close();

}
void Admin::details()
{
	Stock::details();
}

void Admin::stock()
{
	Stock::stock();
}

void Admin::threshold()
{
  fstream myFile;
    myFile.open("menu.txt", ios::in | ios::app);

    char Header[30], stock[20][20], temp[20];
    int no_items[20], price[20];
    int i = 0;

    myFile.getline(Header, 30, '\n');
    while (myFile.getline(stock[i], 20, ' '), myFile >> price[i] >> no_items[i]) {
        myFile.ignore();
        i++;
    }

    myFile.close();
    cout << Header << endl;
    for (int k = 0; k < i; k++)
     { 
      if(no_items[k] <= 15  && no_items[k] > 0 )
       {
         cout <<"\033[1;31m"<< stock[k] << " \t" << price[k] << " \t" << no_items[k] <<"\033[0m"<<endl;
        }
        else if(no_items[k] == 0)
       {
	cout << "\033[1;33m" << stock[k] << " \t" << price[k] << " \t" << no_items[k] << "\033[0m" << endl;
        }
       else 
        {
        cout << stock[k] << " " << price[k] << " " << no_items[k] << endl;
        }
    }
    myFile.close();
    int num;
  
  cout << "\t\tIf you want to add stocks in low stock item press 1 "<<endl;
  cout << "\t\tIf you want to continue press any other number than 1 "<<endl;
  cin>>num;
  if (num == 1)
   {
    update();
   }
 }
void Admin::update()
{
 Stock::update();
}