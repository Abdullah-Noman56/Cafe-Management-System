#include "project.h"
#include "login.h"
#include "Admin.h"
#include "Student.h"
#include "stock.h"
#include "order.h"
#include "Crediental.h"
#include "Employee.h"
int main()
{  
   string blue = "\033[1;34m";
    string green = "\033[1;32m";
    string yellow = "\033[1;33m";
    string reset = "\033[0m"; 

    cout << blue << "\t\t   ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗" << endl;
    cout << "\t\t  ██╔════╝██║  ██║██╔════╝██╔════╝██║  ██║██╔════╝" << endl;
    cout << "\t\t  ██║     ███████║█████╗  ██║     ███████║███████╗" << endl;
    cout << "\t\t  ██║     ██╔══██║██╔══╝  ██║     ██╔══██║╚════██║" << endl;
    cout << "\t\t  ╚██████╗██║  ██║███████╗╚██████╗██║  ██║███████║" << endl;
    cout << "\t\t   ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝" << endl;
    cout << endl;
    cout << blue << "\t\t\t _____________________________" << endl;
    cout << "\t\t\t|                             |" << endl;
    cout << "\t\t\t|                             |" << endl;
    cout << "\t\t\t|                             |" << reset << endl;
    cout << "\t\t\t  " << green << "Welcome to FAST(NUCES) CAFE" << reset << endl;
    cout << blue << "\t\t\t|                             |" << endl;
    cout << "\t\t\t|                             |" << endl;
    cout << "\t\t\t|                             |" << endl;
    cout << "\t\t\t|_____________________________|" << reset << endl;

   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
    int var;
    Login* l1;
   do
   {
       cout << "\t\tAdmin     Press 1 " << endl;
	      cout << "\t\tEmployee  Press 2 " << endl;
	      cout << "\t\tStudent   Press 3 " << endl;
	      cout << "\t\tEXIT      Press 4 " << endl;
	      cout<<"\t\tEnter a corresponding number of you   :   ";
	      cin>>var;
	      system("clear");
         char name[20];
         char password[20];
         switch (var)
         {
            case 1:
            {
               cout << "\t\tEnter your Name : ";
               cin >> name;
               cout << "\t\tEnter your Password : ";
               cin >> password;
               l1 = new Admin(name,password);
               int var1;
           do
	    {
		  cout << green << "\n\t\tGo to Details of the stock    							Press 1"<<endl;
		  cout <<"\n\t\tGo to search, add, remove and update any items in the stock   			Press 2 "<<endl;
		  cout <<"\n\t\tGo to generate a notification for lower items than its threshold value           Press 3"<<endl;
	          cout <<"\n\t\tGo to remove credentials of Employees and Student/Staff  			Press 4"<<endl;
		  cout <<"\n\t\tGo to Display notifications of cafe items, promotions and packages               Press 5"<<endl;
		  cout <<"\n\t\tGo to see online orders and responds     					Press 6 "<<endl;
	        cout <<"\n\t\tGo to see complaints of everything   					        Press 7"<<endl;
		cout <<"\n\t\tGo to see best seller Employee         						Press 8"<<endl;
		cout <<"\n\t\tFor Exit										Press 0"<< reset <<endl; 
		cout<<"\t\tEnter a number corresponding to what you can do : ";
		cin>>var1;
						system("clear");
		switch(var1)
		{
                     case 1:
                     {
                     l1->details();
                     break;
                     }
                  
                     case 2:
                     {
                     l1->stock();
                     
                     break;
                     }
                     case 3:
                     { 
                     l1->threshold();
                     break;
                     }
                     case 4:
                     { 
                     l1->credentials();
                     break;
                     }
                     case 5:
                     {
                     l1->notification();
                     break;
                     }
                     case 6:
                     {
                     l1->seeorder();
                     break;
                     }
                     case 7:
                     {
                     l1->Complaint();
                     break;
                     }
                     case 8:
                     {
                     l1->bestemp();
                     break;
                     }
                     default:
                     {
                      cout<<"\t\t::Program Ends Here::" << endl;
                      break;
                     }
	        }
	}while( (var1>0)  &&  (var1<9));
               delete l1;
               break;
            }
            case 2:
            {
               cout << "\t\tEnter your Name : ";
               cin >> name;
               cout << "\t\tEnter your Password : ";
               cin >> password;
               l1 = new Employee(name,password);
               int var1;
               do 
               { 
                  cout << yellow << "\n\t\tGo to search an item                  		  Press 1" << endl;
                  cout << "\n\t\tGo to see online Orders and Responds  		  Press 2" << endl;
                  cout << "\n\t\tGo to Generate a transaction slip for Student/Staff  Press 3" << endl;
                  cout << "\n\t\tGo to take Order                                     Press 4" << endl;
                  cout << "\n\t\tFor Exit                             Press 0" << reset << endl;
                  cout << "\n\t\tEnter a corresponding number to what you want to do: ";
                  cin >> var1;
                  system("clear");
                  switch (var1) 
                  {
                     case 1: 
                     {
                        l1->search();
                        break;
                     }
                     case 2: 
                     {
                        l1->seeorder();
               
                        break;
                     }
                     case 3:
                        { 
                           
                           l1->transaction(name);
                           system("clear");
                           break;
                           }
                     case 4:
                        {
                        l1->order();
                        break;
                        }
               
                  }
               } while (var1 > 0 && var1 < 5);

               delete l1;
               break;
            }
            case 3:
            {
               cout << "\t\tEnter your Name : ";
               cin >> name;
               
               l1 = new Student(name);
               int var1;
               do 
                { 
                  cout << green << "\n\t\tGo to search items          	  Press 1" << endl;
                  cout << "\n\t\tGo to give complaints        	  Press 2" << endl;
                  cout << "\n\t\tGo to search items & order Food  Press 3" << endl;
                  cout << "\n\t\tGo to see notification       	  Press 4" << endl;
                  cout << "\n\t\tGo to give scheduled orders  	  Press 5" << endl;
                  cout << "\n\t\tFor Exit                     	  Press 0" << reset << endl << endl;
                  cout << "\n\t\tEnter a corresponding number of what you can do : ";
                  cin >> var1;
                  system("clear");
                  switch (var1) 
                  {
                        case 1: 
                        {
                           l1->search();
                           break;
                           }
                        case 2:
                        {
                           l1->Complaints();
                           system("clear");
                           break;
                           }
                        case 3:
                        {
                           l1->order();
                           system("clear");
                           break;
                           }
                        case 4:
                        {
                           l1->Notification();
                           break;
                        }
                        case 5:
                        {
                           l1->scheduled();
                           system("clear");
                        }
                           break;
                     
                        default:
                           cout << "\n\t\tThank You\n\n" << endl;
                  }
               } while (var1 > 0  &&  var1 < 6 );
               delete l1;
               break;
            }
            case 4:
            {
               exit(0);
               break;
            }
          
         }
   } while(var>=1 && var<=4);

   return 0;
}
