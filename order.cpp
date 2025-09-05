#include "order.h"
 
Order::Order()
{ 
  
  fstream myFile;
    myFile.open("menu.txt", ios::in); 

     

    char Header[30];
    int i = 0;
    size = 30;
    menu = new char*[size];
    for(int  i=0;i<size;i++)
    {
      menu[i] = new char[size];
    } 
    char temp[size];
    quantity = new int[size]; 
    price = new int [size];

    myFile.getline(Header, 30, '\n');
    while (myFile.getline(menu[i], 20, ' ') && myFile >> price[i] >> quantity[i]) 
    {
        myFile.ignore();
        i++;
    }
    myFile.close();

    
}



Order::~Order()
{
for(int i = 0;i<size;i++)
 {

  delete [] menu[i];
 }
 delete[] menu;
 delete[] price;
 delete[] quantity;

 
}


void Order::search()
{
     
 fstream myFile;
    myFile.open("menu.txt", ios::in);

    char Header[30];
    int i = 0;
    myFile.getline(Header, 30, '\n');
    while ( myFile >> menu[i] >>price[i] >> quantity[i])
    {
        myFile.ignore();
        i++;
    }

    char search[50];

    int p = 0;
         cout<<"\t\tEnter item name : ";
         cin>>search;
         cout << "\t\t********************\n\n";
     while (true)
     { 
        if (strcmp(menu[p], search) == 0) 
        {
            break;
        } else
            p++;
    }

    if (p < i) 
    { 
        cout << "\n\t\tFound at location : " << p+1 << endl<<endl<<endl;
    } 
    else
       {
        cout << "\n\t\tNot found in the stock." << endl<<endl<<endl;
    }
}

void Order::seeorder()
{
    fstream myFile;
  myFile.open("Orders.txt",ios::in|ios::app);
  int i = 0;
    char a[1000][100];

    while (myFile.getline(a[i], 100, '\n'))
     {
      
        i++;
    }

    for (int k = 0; k < i; k++) 
    {
        cout << a[k] << endl;
    }

    myFile.close();
}

void Order::order() {
    fstream myFile;
    myFile.open("menu.txt", ios::in);

    char Header[30];
    int i = 0;

    // Read the header
    myFile.getline(Header, 30, '\n');

    // Read menu items, prices, and quantities
    while (myFile >> menu[i] >> price[i] >> quantity[i]) {
        myFile.ignore(); // Ignore newline character
        i++;
    }
    myFile.close();
    size = i;

    // Prompt user to enter item name
    cout << "\t\tEnter item name: ";
    char search[20];
    cin >> search;

    // Search for the item in the menu
    int itemIndex = -1;
    for (int j = 0; j < size; j++) {
        if (strcmp(menu[j], search) == 0) {
            itemIndex = j;
            break;
        }
    }

    // If item found in the menu
    if (itemIndex != -1) {
        cout << "\n\t\tFound at location: " << itemIndex + 1 << endl;
        int quantity1;
        cout << "\t\tEnter quantity: ";
        cin >> quantity1;

        // Check if there is enough stock available
        if (quantity1 > quantity[itemIndex]) {
            cout << "\t\tError: Not enough stock available." << endl;
            return;
        } else {
            // Calculate bill
            long bill = price[itemIndex] * quantity1;
            cout << "\t\tYour Bill = " << bill << endl;

            // Write order details to "Orders.txt"
            fstream fx;
            fx.open("Orders.txt", ios::out | ios::app);
            fx << "Student Order\n" << menu[itemIndex] << " Quantity : " << quantity1 << "\nBill : " << bill << endl << endl;
            fx.close(); // Close the file after writing

            // Update stock in menu file
            quantity[itemIndex] -= quantity1;

            // Rewrite menu file with updated quantities
            myFile.open("menu.txt", ios::out);
            myFile << Header << '\n';
            for (int j = 0; j < size; j++) {
                myFile << menu[j] << " " << price[j] << " " << quantity[j] << '\n';
            }
            myFile.close();
        }
    } else {
        cout << "\n\t\tNot found in the stock." << endl;
    }
}


void Order::scheduled() 
{
    const int MAX_student = 10;
    const int MAX_NAME_LENGTH = 50;
    const int MAX_PASSWORD_LENGTH = 20;

    char Header[30];
    char student[MAX_student][MAX_NAME_LENGTH];
    char password[MAX_student][MAX_PASSWORD_LENGTH];

    int i = 0;

    fstream myFile;
    myFile.open("student.txt", ios::in);


    myFile.getline(Header, 30, '\n');

    while (myFile >> student[i] >> password[i]) 
    {
        i++;
    }

    myFile.close();

    char inputpassword[MAX_PASSWORD_LENGTH], username[MAX_NAME_LENGTH];
    cout << "\t\tEnter username: ";
    cin >> username;
    cout << "\t\tEnter Password: ";
    cin >> inputpassword;

    int c = 0;
    bool userFound = false;

    while (c < i) 
    {
        if ((strcmp(password[c], inputpassword) == 0) && (strcmp(student[c], username) == 0)) 
        {
            userFound = true;
            break;
        }
        c++;
    }

    if (userFound == true)
    {
     myFile.open("menu.txt", ios::in);

    

    char Header[30], name[20][20];
    int no_Items[20];
    int i = 0;
    double price[20];

    myFile.getline(Header, 30, '\n');
    while (myFile.getline(name[i], 20, ' ') && myFile >> price[i] >> no_Items[i]) 
    {
        myFile.ignore();
        i++;
    }
    myFile.close();

    int p = 0;
    cout << "\t\tEnter item name: ";
    char search[50];
    cin >> search;

    while (p < i) 
    {
        if (strcmp(name[p], search) == 0) 
        {
            break;
        } else
            p++;
    }

    if (p < i) 
    {
        cout << "\n\t\tFound at location: " << p+1 << endl;
        int quantity;
        cout << "\t\tEnter quantity : ";
        cin >> quantity;
         fstream fx;
        fx.open("Scheduled_Order.txt",ios::out);
        if (quantity > no_Items[p]) 
        {
            cout << "\t\tError: Not enough stock available." << endl;
            return;
        }
       else
       {
        
        int bill;
        bill = price[p] * quantity;
        cout << "\t\tYour Bill = " << bill << endl;
        char time[20];
        char date[10];
        cout<<"\t\tEnter the time(am/pm) of your order : ";
        cin>>time; 
        cout<<"\t\tEnter Date : ";
        cin>>date;
        cout << "\t\tYour Bill = " << bill << endl;
           fx<<"Scheduled Order\n"<<"Student Order\n"<<search<<"Quantity : "<<quantity<<"\nBill : "<<bill<<endl<<"Time : "<<time<<endl<<"Date : "<<date<<endl<<endl;
        myFile.open("menu.txt", ios::out);
        
        myFile << Header << '\n';
        for (int j = 0; j < i; j++) {
            if (j == p) {
                myFile << name[j] << ' ' << price[j] << ' ' << no_Items[j] - quantity << '\n';
            } else {
                myFile << name[j] << ' ' << price[j] << ' ' << no_Items[j] << '\n';
            }
        }
       }
       fx.close();
        myFile.close();
    } 
    else 
    {
        cout << "\n\t\tNot found in the stock." << endl;
    }
   }
   else
   {
    cout << "\t\tInvalid username or password\n\n";
    exit(-1);

   }
}
