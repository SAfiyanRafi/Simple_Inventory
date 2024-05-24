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
vector <stock> product = {{"Beans","Groceries",10,12.76},{"Bananas","Fruit",20,15.3}};
    //-------------------------
    //    Usning Mapping
    //-------------------------
    map<string, vector<stock>> categorized_Items;
    public:
    //-------------------------
    //      ADMIN LOGIN
    //-------------------------
   void Admin_Authorization() {
        system("cls");
        string Admin_Username; 
        string Admin_password;
        cout << "Enter Username: ";
        cin >> Admin_Username;
        cout << "Enter Password: ";
        cin >> Admin_password;
        if (Admin_Username == Admin_Username_Saved &&
            Admin_password == Admin_Password_Saved) 
        {
            system("cls");

            cout << "\t\t\t===========" << endl ;
            cout << "\t\t\tLOGIN DONE." << endl ;
            cout<< "\t\t\t==========="<<endl;
            cout << endl;
            cout << endl;
            cout<< "Press Any Key To Enter Admin Menu.\n\n";
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
    cout<<"Enter a Choice : "<<endl;
    cout<<" 1) VIEW STOCK : "<<endl;
    cout<<" 2) CHANGE AN EXISTING STOCK : "<<endl;
    cout<<" 3) ADD A NEW STOCK : "<<endl;
    cout<<" 4) DISPLAY CATOGRIZED STOCKS : "<<endl;
    cout<<" 5) EXIT : "<<endl;
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
        Display_Categorized_Items();
        break;
        case 5:
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
            << setw(15) << left << product[i].item_Quantity << "$"<< product[i].item_Price<<endl;
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
               cout << "Enter The New Name For " << product[i].item_Name<< " : " ;
               cin>>new_stock_name;
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
    cout<<"ENTER A NEW STOCK NAME : " ;
    cin >> new_item_name; 
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

}
void Display_Stock()
{
    system("cls");
    cout << "\t\t======================" << endl;
    cout << "\t\t WARHOUSE STOCK ITEMS" << endl;
    cout << "\t\t======================" << endl;
    cout<<endl;
    cout<<endl;
      cout<< setw(10) << left << "No" << setw(20) << left << "Item Name " 
        << setw(15) << left <<"Category" << setw(15) << left <<"Quantity"<< setw(10) << left << "Price";
        cout<<endl;
        cout<<endl;
          for (size_t i = 0; i < product.size(); i++)
        {
            cout<< setw(10) << left << i +1 << setw(20) << left << product[i].item_Name
                << setw(15) << left << product[i].item_category << setw(15) << left << product[i].item_Quantity 
                <<"$"<< product[i].item_Price<<endl;
        }
    cout<<endl;
    cout<<endl;
    system("pause");
    Admin_Menu();
}

//---------------------------
// DISPLAY CATOGORIED ITEMS 
//---------------------------
  void Display_Categorized_Items()
    {
        system("cls");
        cout << "\t\t\t======================" << endl;
        cout << "\t\t\t CATEGORIZED STOCK ITEMS" << endl;
        cout << "\t\t\t======================" << endl;
        cout<<endl;
        cout<<endl;   
        cout<< setw(10) << left << "No" << setw(20) << left << "Item Name " 
            << setw(15) << left <<"Category" << setw(15) << left <<"Quantity"<< setw(10) << left << "Price";
        cout<<endl;
        cout<<endl;
        // for (size_t i = 0; i < product.size(); i++)
        // {
        //     cout<< setw(10) << left << i +1  << setw(20) << left << product[i].item_Name
        //         << setw(15) << left << product[i].item_category << setw(15) << left << product[i].item_Quantity 
        //         <<"$"<< product[i].item_Price<<endl;
        // }
        
        for ( auto categoryItems : categorized_Items)
        {
            cout << "Category: " << categoryItems.first << endl;
            cout<< setw(10) << left << "No" << setw(20) << left << "Item Name " 
                << setw(15) << left <<"Quantity"<< setw(10) << left << "Price";
            cout<<endl;
            cout<<endl;
            int count = 1;
            for ( auto item : categoryItems.second)
            {
                cout << setw(10) << left << count << setw(20) << left << item.item_Name
                    << setw(15) << left << item.item_Quantity << "$" << item.item_Price << endl;
                count++;
            }
            cout << endl;
        }
            cout << endl;
            cout << endl;
    
        system("pause");
        Admin_Menu();
    }
//---------------------------
// Program Execute FUNCTION
//---------------------------
void execute()
{
    system("cls");
    int choice;
    cout<<"Enter a Choice : "<<endl;
    cout<<" 1) Admin : "<<endl;
    cout<<" 2) Supplier : "<<endl;
    cout<<" 3) Exit : "<<endl<<endl;
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
