#include "stock.h"
 
Stock::Stock()
{  
  fstream myFile;
    myFile.open("menu.txt", ios::in | ios::app);

    char Header[30];
    size = 30;
    menu = new char*[size];
    for(int  i=0;i<size;i++)
    {
      menu[i] = new char[size];
    } 
    char temp[size];
    quantity = new int[size];  
    price = new int [size];
    int i = 0;

    myFile.getline(Header, 30, '\n');
    while (myFile.getline(menu[i], 20, ' '), myFile >> price[i] >> quantity[i]) {
        myFile.ignore();
        i++;
    }

    myFile.close();

   
}

Stock :: ~Stock()
{
 for(int i = 0;i<size;i++)
 {

  delete [] menu[i];
 }
 delete[] menu;
 delete[] price;
 delete[] quantity;

}

void Stock::details() 
 {
    fstream myFile;
    myFile.open("menu.txt", ios::in | ios::app);

    char Header[30],temp[20];
    int i = 0;

    myFile.getline(Header, 30, '\n');
    while ( myFile >> menu[i] >> price[i] >> quantity[i]) 
    {
        myFile.ignore();
        i++;
    }

    myFile.close();

    cout << "\t\t**Cafe Menu\n";
    cout << "\n\t Name\t\tPrice \tQuantity     Total price " <<endl;
    for (int k = 0; k < i; k++) 
    {
        cout << "\t  " << menu[k] << " \t " << price[k] << " \t " << quantity[k] << "\t" << price[k]*quantity[k]<<endl;
    }
    cout << "\n\t\t**End Menu*\n";


    for(int j = 0; j < i - 1; j++) 
    {
        for(int k = 0; k < i - j - 1; k++)
         {
            
            if(quantity[k] > quantity[k + 1]) 
             {
                strcpy(temp, menu[k]);
                strcpy(menu[k], menu[k + 1]);
                strcpy(menu[k + 1], temp);
                       
                       
                int tempPrice = price[k];
                price[k] = price[k + 1];
                price[k + 1] = tempPrice;
                
                int tempNoItems = quantity[k];
                quantity[k] = quantity[k + 1];
                quantity[k + 1] = tempNoItems;
             }
        }
    }

    myFile.open("menu.txt", ios::out);
    myFile << Header << endl;
    for (int k = 0; k < i; k++) {
        myFile << menu[k] << " " << price[k] << " " << quantity[k] << endl;
    }
    myFile.close();
}

void Stock::stock()
{

    int num;
    cout << "\t\t1. Search\n";
    cout << "\t\t2. Add \n";
    cout << "\t\t3. Remove \n";
    cout << "\t\t4. Update\n";
    cout << "\t\tEnter a number for what you want to do: ";
    cin >> num;

    switch (num)
    {
    case 1:
    {
        fstream myFile;
        myFile.open("menu.txt", ios::in); 
        
        char Header[30];
        int i = 0;

        myFile.getline(Header, 30, '\n');
        while (myFile >> menu[i] >> price[i] >> quantity[i])
        {
            myFile.ignore();
            i++;
        }

        myFile.close(); 

        char search[50];
        cout << "\nEnter item to search: ";
        cin >> search;

        int p = 0;
        bool found = false;

        for (int a = 0; a < i; a++)
        {
            if (strcmp(menu[a], search) == 0)
            {
                p = a;
                found = true;
            }
            cout << menu[a] << " : " << price[a] << " : " << quantity[a] << endl;
        }

        if (found)
        {
            cout << "\nFound at location : " << p << endl;
        }
        else
        {
            cout << "\nItem not found." << endl;
        }
    }
    break;

    case 2:
    {
        char menu1[10];
        int quantity1,price1;
        int i = 0;


        cout << "Enter the thing that you want to add : ";
        cin >> menu1;
        cout << "Enter quantity of it : ";
        cin >> quantity1;
        cout << "Enter price of it : ";
        cin >> price1;

        fstream myFile;
        myFile.open("menu.txt", ios::out | ios::app); 

        

        myFile << menu1 << " " << price1 << " " << quantity1 << endl; 

        myFile.close(); 
    }
    break;

    case 3:
    {
     fstream myFile;
    myFile.open("menu.txt", ios::in);

    if (!myFile)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    char Header[30];
    int i = 0;

    myFile.getline(Header, 30, '\n');
    while (myFile.getline(menu[i],20,' ') ,myFile >> price[i] >> quantity[i])
    {
        myFile.ignore();
        i++;
    }

    myFile.close();

    char search[50];
    int p = 0;
    cout << "Enter item to remove: ";
    cin >> search;

    while (p < i && strcmp(menu[p], search) != 0)
    {
        p++;
    }

    if (p < i)
    {
        cout << "\nFound at location: " << p << endl;

        myFile.open("menu.txt", ios::out); // Open file for writing

        if (!myFile)
        {
            cerr << "Error opening file!" << endl;
            return;
        }

        myFile << Header << endl;
        for (int a = 0; a < i; a++)
        {
            if (a == p)
                continue;
            myFile << menu[a] << " " << price[a] << " " << quantity[a] << endl;
        }

        myFile.close();
        cout << "\n\t\tItem removed successfully." << endl;
    }
    else
    {
        cout << "\n\t\tItem not found." << endl;
    }
    break;
    }
    case 4:
      {
       fstream myFile;
       myFile.open("menu.txt",ios::in);
       char Header[30], menu[20][20];
        int quantity[20], price[20];
        int i = 0;

        myFile.getline(Header, 30, '\n');
        while (myFile.getline(menu[i],20,' '),myFile >> price[i] >> quantity[i])
        {
            myFile.ignore();
            i++;
        }

        myFile.close();
       char search[50];
        cout << "\n\t\tEnter item to search: ";
        cin >> search;

        int p = 0;
        bool found = false;

        int a=0;
        for (; a < i; a++)
        {
            if (strcmp(menu[a], search) == 0)
            {
                p = a;
                found = true;
            }
        }
     if(found == true)
      {
       int var;
        cout << "\t\t1. Update price" << endl;
        cout << "\t\t2. Add menu" << endl;
        cout << "\n\t\tEnter what you want to do: ";
        cin >> var;

        if (var == 1)
        {
            int newprice;
            cout << "Enter new price: ";
            cin >> newprice;

            myFile.open("menu.txt", ios::out);

            // Update the price for the found item
            price[p] = newprice;

            // Write the updated content to the file
            myFile << Header << endl;
            for (int b = 0; b < i; b++)
            {
                myFile << menu[b] << " " << price[b] << " " << quantity[b] << endl;
            }

            myFile.close();
            cout << "\t\tPrice updated successfully." << endl;
        }
        else if (var == 2)
        {
            int newquantity;
             do{
            cout << "\t\tEnter Quantity you want to Add: ";
            cin >> newquantity;
            if(newquantity > 1000)
             {
            	cout << "\t\tLimit Exceed, Should not be greater than 1000" << endl;
            }
           	
           	 
           }
	      while(newquantity > 1000);
            if(newquantity > 0)
            {
            myFile.open("menu.txt", ios::out);

            // Update the quantity for the found item
            quantity[p]+= newquantity;

            // Write the updated content to the file
            myFile << Header << endl;
            for (int b = 0; b < i; b++)
            {
                myFile << menu[b] << " " << price[b] << " " << quantity[b] << endl;
            }

            myFile.close();
            cout << "\t\tQuantity updated successfully." << endl;
            }
           else
           {
            cout << "\t\tEnter a positive number\n";
            }
        }
        else
        {
            cout << "\t\tInvalid choice." << endl;
        }
    }
    else
    {
        cout << "\t\tItem not found in menu." << endl;
    }

         break;
       }
       
    default:
        cout << "\t\tInvalid choice" << endl;
    }
}

void Stock::update()
{
    fstream myFile;
       myFile.open("menu.txt",ios::in);
       char Header[30], menu[20][20];
        int quantity[20], price[20];
        int i = 0;

        myFile.getline(Header, 30, '\n');
        while (myFile.getline(menu[i],20,' '),myFile >> price[i] >> quantity[i])
        {
            myFile.ignore();
            i++;
        }

        myFile.close();
       char search[50];
        cout << "\nEnter item to search: ";
        cin >> search;

        int p = 0;
        bool found = false;

        cout << "\n" << Header << endl;
        int a=0;
        for (; a < i; a++)
        {
            if (strcmp(menu[a], search) == 0)
            {
                p = a;
                found = true;
            }
        }
     if(found == true)
      {
       int newquantity = 0;
       do{
            cout << "Enter Quantity you want to Add: ";
            cin >> newquantity;
            if(newquantity > 1000)
            {
            	cout << "Limit Exceed, Should not be greater than 1000" << endl;
            }
          
            }
	while(newquantity > 1000);
	 if(newquantity > 0)
	 { 
            myFile.open("menu.txt", ios::out);
            quantity[p]+= newquantity;

            // Write the updated content to the file
            myFile << Header << endl;
            for (int b = 0; b < i; b++)
            {
                myFile << menu[b] << " " << price[b] << " " << quantity[b] << endl;
            }

            myFile.close();
            cout << "Quantity updated successfully." << endl;
        }
        else
         {
          cout << "Enter a positive number \n";
          }
      }
        else
        {
            cout << "Invalid choice." << endl;
        }
}
