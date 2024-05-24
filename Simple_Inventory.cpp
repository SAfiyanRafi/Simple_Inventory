#include<iostream>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
struct stock
{
  string item_Name;
  string item_category;
  int item_Quantity;
  double item_Price;
};
class inventory
{
    private:
    //-------------------------
    // ADMIN LOGIN CREDIENTIALS
    //-------------------------
    string Admin_Username_Saved = "s"; 
    string Admin_Password_Saved = "s";
    //-------------------------
    //         ITEMS
    //-------------------------
vector <stock> product = {{"Beans","Vegetable",50,12.76},{"Bananas","Fruit",100,15.3},
                          {"Potato","Vegetable",70,20.9},{"Mangoes","Fruit",90,25.1}
                          ,{"Tomato","Vegetable",30,14},{"Strawberry","Fruit",85,17.9}
                          ,{"Shampoo","Cosmetics",90,25.1},{"Lotion","Cosmetics",30,14},
                          {"Hair Oil","Cosmetics",85,17.9}};
    //-------------------------
    //    Usning Mapping
    //-------------------------
   // map<string, vector<stock>> categorized_Items;
    public:
    //-------------------------
    //      ADMIN LOGIN
    //-------------------------
   void Admin_Authorization() {
        system("cls");
        string Admin_Username; 
        string Admin_password;
        cout << "\t\t=================  "<<endl;
        cout << "\t\t   ADMIN LOGIN  "<<endl;
        cout << "\t\t=================  \n\n"<<endl;
        cout << "ENTER USERNAME : ";
        cin >> Admin_Username;
        cout << "ENTER PASSWORD : ";
        cin >> Admin_password;
        if (Admin_Username == Admin_Username_Saved &&
            Admin_password == Admin_Password_Saved) 
        {
            system("cls");

            cout << "\t\t\t==============" << endl ;
            cout << "\t\t\t  LOGIN DONE." << endl ;
            cout<< "\t\t\t=============="<<endl;
            cout << endl;
            cout << endl;
            system("pause");
            Admin_Menu();
        } else 
        {
            cout << "Wrong Info ! \nAccess Denied!"<<endl;
            cout << " 1) Try Again : "<<endl;
            cout << " 2) Exit : ";
            int choice;
            cin >> choice;
            switch (choice) 
            {
                case 1:
                    Admin_Authorization();
                    break;
                case 2:
                    execute();
                    break;
                default:
                    cout << "Invalid Choice : "<<endl;
                    cout << "Press Any Key to Exit  : "<<endl;
                    exit(0);
            }
        }
    }
    //-------------------------
    //      ADMIN MENU
    //-------------------------
void Admin_Menu()
{
    system("cls");
    int choice;
    cout << "\t\t================" << endl;
    cout << "\t\t  WELCOME BACK" << endl;
    cout << "\t\t================\n\n" << endl;
    cout<<" 1) VIEW STOCK : "<<endl;
    cout<<" 2) CHANGE AN EXISTING STOCK : "<<endl;
    cout<<" 3) ADD A NEW STOCK : "<<endl;
    cout<<" 4) DISPLAY CATOGRIZED STOCKS : "<<endl;
    cout<<" 5) LOGOUT : \n"<<endl;
    cout<<"ENTER A CHOICE : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        Display_Stock();
        break;
        case 2:
        Existing_Stock_Change();
        break;
        case 3:
        Add_New_Stock();
        break;
        case 4:
        Display_Categories();
        break;
        case 5:
        execute();
        break;
        default:
        system("cls");
        cout<<"Invalid Choice !";
        system("pause");
        execute();
        break;
    }

}
void Existing_Stock_Change()
{
    system("cls");
     cout<< setw(10) << left << "No" << setw(20) << left << "Item Name " 
        << setw(15) << left <<"Category" << setw(15) << left <<"Quantity"<< setw(10) << left << "Price";
        cout<<endl;
        cout<<endl;
         for (size_t i = 0; i < product.size(); i++)
        {
            cout<< setw(10) << left << i + 1 << setw(20) << left << product[i].item_Name
            << setw(15) << left << product[i].item_Quantity << "$ "<< product[i].item_Price<<endl;
        }
    int stockitem;
    cout<<endl;
    cout<<endl;
    cout<<"Enter The Stock Number To Be Replaced : ";
    cin>>stockitem;
    if(stockitem < 1 || stockitem > product.size())
    {
        system("cls");
        int Verify;
        cout << "The Number Your Entered Is Out of Range ! " << endl;
              cout << " 1) Try Again : " ;
              cout << " 2) Exit : " ;
              cin >> Verify;
              if(Verify == 1)
              {
                  Existing_Stock_Change();
              }
              else if(Verify == 2)
              {
                  Admin_Menu();
              }
              else
              {
                  cout << "Wrong Choice ! "<<endl;
                  system("pause");
               Admin_Menu();              
              }
         }

         int i = stockitem -1; 
        string new_stock_name;
        string new_stock_category;
        int new_stock_quantity;
        double new_stock_price;
         cin.ignore();
               cout << "Enter The New Name For " << product[i].item_Name<< " : " ;
               getline(cin,new_stock_name);
               cout << "Enter The Category : ";
               cin>>new_stock_category;
               cout << "Enter The Quantity : ";
               cin>>new_stock_quantity;
               cout << "Enter The Price : ";
               cin>>new_stock_price;
         product[i].item_Name = new_stock_name;
         product[i].item_category = new_stock_category;
         product[i].item_Quantity = new_stock_quantity ;
        product[i].item_Price = new_stock_price;
        cout<<"NEW ITEM ADDED !! "<<endl;
        system("pause");
        Admin_Menu();
         
}
void Add_New_Stock()
{
    system("cls");
    string new_item_name;
    string new_item_category;
    int new_item_quantity;
    double new_item_price;
    cin.ignore();
    cout<<"ENTER A NEW STOCK NAME : " ;
    getline(cin,new_item_name); 
    cout<<"ENTER A NEW STOCK QUANTITY : " ; 
    cin >> new_item_quantity; 
    cout<<"ENTER A NEW STOCK CATEGORY : " ; 
    cin >> new_item_category; 
    cout<<"ENTER A NEW STOCK PRICE : " ; 
    cin >> new_item_price;
    stock values;
    values.item_Name = new_item_name;
    values.item_Quantity = new_item_quantity;
    values.item_category = new_item_category;
    values.item_Price = new_item_price;
    product.push_back(values);
    cout<<"STOCK ITEM ADDED SUCCESFULLY !! "<<endl;
    cout<<endl;
    system("pause");
    Admin_Menu();
}
//-------------------------
//     SUPPLIER MENU
//-------------------------
void supplier_Menu()
{
    system("cls");
    int choice;
    cout<<" 1) VIEW COMPLETE STOCK : "<<endl;
    cout<<" 2) VIEW CATEGORIZED STOCK : "<<endl;
    cout<<" 3) BUY PRODUCTS : "<<endl;
    cout<<" 4) EXIT : "<<endl;
    cout<<"ENTER A CHOICE : ";
    cin >> choice;
    switch(choice)
    {
        case 1:
        Display_Stock();
        break;
        case 2:
        Display_Categories();
        break;
        case 3:
        purchase_Products();
        break;
        case 4:
        exit(0);
        break;
        default:
        cout << "Invalid Choice !! " << endl;
        cout << endl;
        system("pause");
        supplier_Menu();
    }
}
void purchase_Products()
{

}
void Display_Stock()
{
    system("cls");
    cout << "\t\t======================" << endl;
    cout << "\t\t WARHOUSE STOCK ITEMS" << endl;
    cout << "\t\t======================\n\n" << endl;
      cout<< setw(10) << left << "No" << setw(20) << left << "Item Name " 
        << setw(15) << left <<"Category" << setw(15) << left <<"Quantity"<< setw(10) << left << "Price";
        cout<<endl;
        cout<<endl;
          for (size_t i = 0; i < product.size(); i++)
        {
            cout<< setw(10) << left << i +1 << setw(20) << left << product[i].item_Name
                << setw(15) << left << product[i].item_category << setw(15) << left << product[i].item_Quantity 
                <<"$ "<< product[i].item_Price<<endl;
        }
    cout<<endl;
    cout<<endl;
    system("pause");
    Admin_Menu();
}
//---------------------------
// DISPLAY CATOGORIED ITEMS 
//---------------------------
void Display_Categories()
{
    system("cls");
    cout << "\t\t====================" << endl;
    cout<<  "\t\t     CATEGORIES"<<endl;
    cout << "\t\t====================\n\n" << endl;
    int choice;
    cout<<" 1) FRUITS : "<<endl;
    cout<<" 2) VEGETABLES : "<<endl;
    cout<<" 3) COSMETICS : "<<endl;
    cout<<" 4) EXIT : "<<endl;
    cout<<"ENTER A CHOICE : ";
    cin >> choice;
    system("cls");
    int count = 1;
    switch(choice)
    {
        case 1:
        cout << "\t\t\t=============" << endl;
        cout << "\t\t\t   FRUITS" << endl;
        cout << "\t\t\t=============\n\n" << endl;
           cout << setw(10) << left << "No" << setw(20) << left << "Item Name "
         << setw(15) << left << "Category" << setw(15) << left << "Quantity" << setw(10) << left << "Price";
    cout << endl;
    cout << endl;
    for (size_t i = 0; i < product.size(); i++)
    {
        if (product[i].item_category == "fruit" ||
            product[i].item_category == "Fruit")
        {
            cout << setw(10) << left << count << setw(20) << left << product[i].item_Name
                 << setw(15) << left << product[i].item_category << setw(15) << left << product[i].item_Quantity
                 << "$ " << product[i].item_Price << endl;
            count++;
        }
    }
        cout << endl;
        cout << endl;
        system("pause");
        Display_Categories();
        break;
        case 2:
        cout << "\t\t\t=============" << endl;
        cout << "\t\t\t  VEGETABLES" << endl;
        cout << "\t\t\t=============\n\n" << endl;
        cout << setw(10) << left << "No" << setw(20) << left << "Item Name "
         << setw(15) << left << "Category" << setw(15) << left << "Quantity" << setw(10) << left << "Price";
    cout << endl;
    cout << endl;
    for (size_t i = 0; i < product.size(); i++)
    {
        if (product[i].item_category == "Vegetable"||
            product[i].item_category == "vegetable")
        {
             cout << setw(10) << left << count << setw(20) << left << product[i].item_Name
                 << setw(15) << left << product[i].item_category << setw(15) << left << product[i].item_Quantity
                 << "$ " << product[i].item_Price << endl;
            count++;
        }
    }
        cout << endl;
        cout << endl;
        system("pause");
        Display_Categories();
        break;
        case 3:
        cout << "\t\t\t=============" << endl;
        cout << "\t\t\t  COSMETICS" << endl;
        cout << "\t\t\t=============\n\n" << endl;
        cout << setw(10) << left << "No" << setw(20) << left << "Item Name "
         << setw(15) << left << "Category" << setw(15) << left << "Quantity" << setw(10) << left << "Price";
    cout << endl;
    cout << endl;
    for (size_t i = 0; i < product.size(); i++)
    {
        if (product[i].item_category == "Cosmetics"||
            product[i].item_category == "cosmetics")
        {
             cout << setw(10) << left << count << setw(20) << left << product[i].item_Name
                 << setw(15) << left << product[i].item_category << setw(15) << left << product[i].item_Quantity
                 << "$ " << product[i].item_Price << endl;
            count++;
        }
    }
        cout << endl;
        cout << endl;
        system("pause");
        Display_Categories();
        break;
        case 4:
        Admin_Menu();
        break;
        default:
        cout << "INVALID CHOICE !! "<<endl;
        system("pause");
        Admin_Menu();
    }
}
//---------------------------
// Program Execute FUNCTION
//---------------------------
void execute()
{
    system("cls");
    int choice;
    cout << "\t\t===========================" << endl;
    cout << "\t\t WELCOME TO THE INVENTORY" << endl;
    cout << "\t\t===========================" << endl;
    cout<<" 1) ADMIN : "<<endl;
    cout<<" 2) SUPPLIER : "<<endl;
    cout<<" 3) EXIT : "<<endl<<endl;
    cout<<"ENTER A CHOICE : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        Admin_Authorization();
        break;
        case 2:
        supplier_Menu();
        break;
        case 3:
        exit(0);
        break;
        default:
        system("cls");
        cout<<"Invalid Choice !";
        system("pause");
        execute();
        break;
    }
}
};
//-------------------------
//     MAIN FUNCTION
//-------------------------
int main()
{
    inventory s1;
    s1.execute();
return 0;
}
