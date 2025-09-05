#include "Crediental.h"
 
Credentials::Credentials()
{  

   size = 20;
   name = new char*[size];
   password =  new char*[size]; 
   for(int i = 0;i<size;i++)
   {
    name[i] = new char[size];
    password[i] =  new char[size];
   }

}


Credentials::~Credentials()
{


}


void Credentials::credentials()
 {
    int num;
    cout<<"\t\tEmployee    Press 1"<<endl;
    cout<<"\t\tStudent     Press 2"<<endl;
    cout<<"Enter a number for whom you can remove : ";
    cin>>num;
    switch(num)
    {
    case 1:
        { 
        int var;
        cout << "If you want to add    Press 1 \n";
        cout << "If you want to remove Press 2 \n";
        cout << " Enter number : ";
        cin >> var;
    if(var == 1 )
        {
        char Header[30];

        int i = 0;

        fstream myFile;
        myFile.open("Employees.txt", ios::in);


        myFile.getline(Header, 30, '\n');

        while (myFile >> name[i] >> password[i]) 
        {
            i++;
        }

        myFile.close();
        
        
        char newemployee[size],newpassword[size];
        cout << "Enter its Name : ";
        cin >> newemployee;
        cout << "Enter its Password : ";
        cin >> newpassword;
        myFile.open("Employee.txt",ios::out|ios::app);
        
        myFile << newemployee << " " << newpassword <<endl;
            myFile.close();
        }
    else if(var == 2 )
        {

        char Header[30];

        int i = 0;

        fstream myFile;
        myFile.open("Employees.txt", ios::in);


        myFile.getline(Header, 30, '\n');

        while (myFile >> name[i] >> password[i]) 
        {
            i++;
        }

        myFile.close();

        char search[50];
        cout<<"Enter Name of the Employee : ";
        cin>>search;
        int p=0;
        while (p < i && strcmp(name[p], search) != 0)
        {
            p++;
        }

        if (p < i)
        {

            myFile << Header << endl;
            for(int a = 0; a < i; a++)
            {
                if(a == p)
                    continue;
                myFile << name[a] << " " << password[a] << endl;
            }

            myFile.close();
            cout << "Employee removed successfully." << endl;
        }
        else
        {
            cout << "Name not found." << endl;
        }
        
        }
        
        else 
        {
        cout << "Invalid number \n\n";
        }
        break;
    }
        case 2:
        { 


                char Header[30];
                
                int i = 0;

                fstream myFile;
                myFile.open("student.txt", ios::in);


                myFile.getline(Header, 30, '\n');

                while (myFile >> name[i] >> password[i]) 
                {
                    i++;
                }

                myFile.close();
                int var;
                cout << "If you want to add    Press 1 \n";
                cout << "If you want to remove Press 2 \n";
                cout << " Enter number : ";
                cin >> var;
                if(var == 1 )
                    {
                    
                    char Header[30];
                    

                    int i = 0;

                    fstream myFile;
                    myFile.open("student.txt", ios::in);


                    myFile.getline(Header, 30, '\n');

                        while (myFile >> name[i] >> password[i]) 
                        {
                            i++;
                        }

                    myFile.close();
                    
                    
                    char newstudent[30],newpassword[20];
                    cout << "\t\tEnter its Name : ";
                    cin >> newstudent;
                    cout << "\t\tEnter its Password : ";
                    cin >> newpassword;
                    myFile.open("Employee.txt",ios::out|ios::app);
                    
                    myFile << newstudent << " " << newpassword <<endl;
                        myFile.close();
                    }
                    else if(var == 2)
                    {
                    char search[50];
                    cout<<"\t\tEnter Name of the Student : ";
                    cin>>search;
                    int p=0;
                    while (p < i && strcmp(name[p], search) != 0)
                    {
                        p++;
                    }

                    if (p < i)
                    {

                        myFile.open("student.txt", ios::out); 

                        myFile << Header << endl;
                        for (int a = 0; a < i; a++)
                        {
                            if (a == p)
                                continue;
                            myFile << name[a] << " " << password[a] << endl;
                        }

                        myFile.close();
                        cout << "\t\tStudent removed successfully." << endl;
                    }
                    else
                    {
                        cout << "\t\tName not found." << endl;
                    }
                
            }
            break;
    }
        
            default:
            {
                cout<<"\t\tEnter a right number"<<endl;
            }    
        }
  }

// Best seller employee
  void Credentials::bestemp()
   {   
       
       fstream myFile;
       myFile.open("Sales.txt",ios::in);
       char Header[30],Uname[10][20];
        int sales[10];
        int i = 0;

        myFile.getline(Header, 30, '\n');
        while (myFile >> Uname[i] >> sales[i])
        {
            myFile.ignore();
            i++;
        }

        myFile.close();
       
        int highest = 0;
        int H_index;

        //cout << "\n" << Header << endl;
        int a=0;
        for (; a < i; a++)
        {
            if (sales[a] > highest)
            { 
             
                highest = sales[a];
                H_index = a;
            }
        }
        
        cout <<"\t\t"<< Uname[H_index] << " is the Best Sale Employee." << endl;
     }
