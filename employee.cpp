#include "Employee.h"
 
Employee::Employee(char* username, char* password)
{ 
	       char Header[30];
		    int i = 0;
			       fstream myFile;
		    myFile.open("Employee.txt", ios::in);


		    myFile.getline(Header, 30, '\n');
            name = new char*[7];
            inputpassword = new char*[7];
            for (int i = 0; i < 7; i++)
            {
                name[i] = new char[30];
                inputpassword[i] = new char[30];
            }

		    while (myFile >> name[i] >> inputpassword[i]) 
		    {
			i++;
		    }

		      myFile.close();
		      int c = 0;
		    bool userFound = false;

		    while (c < i) 
		    {
		    
			if ((strcmp(inputpassword[c], password) == 0) && (strcmp(name[c], username) == 0)) 
			{
			    userFound = true;
			    break;
			}
			c++;
		    }

	if (userFound == true) 
	{
		   
			fstream fv;
			system("clear");
			fv.open("Login.txt", ios::out|ios::app);

			fv << " Employee Login Successfully\n";
			fv.close();
            
	}

  

        else
		{
		    fstream fv;
			system("clear");
			fv.open("Login.txt", ios::out|ios::app);

			fv << " Employee Login Failed\n";
			fv.close();
            cout << "Invalid Username or Password\n";
            exit(-1);
		     
		}

}


Employee::~Employee()
{
   for(int i = 0;i<7;i++)
   {
    delete [] name[i];
    delete [] inputpassword[i];
   }
   delete [] name;
   delete []  inputpassword;
}

void Employee::search()
{
  Order::search(); 
}

void Employee::seeorder()
{
  Order::seeorder();
}

void Employee::order()
{
  Order::order();
}

void Employee::transaction(char username[]) 
{

    
	
    fstream myFile;
    myFile.open("menu.txt", ios::in);

    char Header[30], stock[100][20];
    int quantity[20], price[20];
    int i = 0;


    // Read the header
    myFile.getline(Header, 30, '\n');

    // Read menu items, prices, and quantities
    while (myFile >> stock[i] >> price[i] >> quantity[i]) 
    {
        myFile.ignore(); // Ignore newline character
        i++;
    }
    myFile.close();
    int size = i;
    myFile.close();

    cout << "\n\t\t********Cafe stock*********\n";
    cout << "\n\t" << Header << endl;
    for (int k = 0; k < i; k++) {
        cout << "\t\t" << stock[k] << "\t" << price[k] << endl;
    }
    cout << "\n\n\t*********End stock**********\n\n";


    cout << "\t\tEnter item name: ";
    char search[20];
    cin >> search;

    // Search for the item in the stock
    int itemIndex = -1;
    for (int j = 0; j < size; j++) {
        if (strcmp(stock[j], search) == 0) {
            itemIndex = j;
            break;
        }
    }

    // If item found in the stock
    if (itemIndex != -1) {
        cout << "\nFound at location : " << itemIndex+1 << endl;
         fstream fx;
        fx.open("transaction.txt",ios::out|ios::app);
        int quantity1;
        cout << "\t\tEnter quantity: ";
        cin >> quantity1;

        // Check if there is enough stock available
        if (quantity1 > quantity[itemIndex]) {
            cout << "\t\tError: Not enough stock available." << endl;
            return;
        } else {
            // Calculate bill
            int bill[2];
        bill[0] = price[itemIndex] * quantity1;
        cout << "Your Bill = " << bill[0] << endl;
        cout<<"Enter recieve Cash : ";
        cin>>bill[1];
           fx<<"Staff Order\n"<<search<<"  Quantity : "<<quantity1<<"\nBill : "<<bill[0]<<endl<<"recieve Cash : "<<bill[1]<<endl;
            SalesUpdate(username);
            // Write order details to "Orders.txt"
            fstream fx;
            fx.open("Orders.txt", ios::out | ios::app);
            fx << "Student Order\n" << stock[itemIndex] << " Quantity : " << quantity1 << "\nBill : " << bill << endl << endl;
            fx.close(); // Close the file after writing

            // Update stock in stock file
            quantity[itemIndex] -= quantity1;

            // Rewrite stock file with updated quantities
            myFile.open("stock.txt", ios::out);
            myFile << Header << '\n';
            for (int j = 0; j < size; j++) {
                myFile << stock[j] << " " << price[j] << " " << quantity[j] << '\n';
            }
            myFile.close();
        }
    } else {
        cout << "\n\t\tNot found in the stock." << endl;
    }
}

  
void Employee::SalesUpdate(char* username)
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
       

        int p = 0;
        bool found = false;

        //cout << "\n" << Header << endl;
        int a=0;
        for (; a < i; a++)
        {
            if (strcmp(Uname[a], username) == 0)
            { 
             
                p = a;
                found = true;
            }
        }
     if(found == true)
      {
	 
            myFile.open("Sales.txt", ios::out);
            sales[p] += 1;

            // Write the updated content to the file
            myFile << Header << endl;
            for (int b = 0; b < i; b++)
            {
                myFile << Uname[b] << " " << sales[b] << endl;
            }

            myFile.close();
      }
        else
        {
            cout << "username not found." << endl;
        }
  }
