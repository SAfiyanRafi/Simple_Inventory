{
    system("cls");
    char choice;
    cout << "\t===========================" << endl;
    cout << "\t WELCOME TO THE INVENTORY" << endl;
    cout << "\t===========================\n\n" << endl;
    cout<<" 1) ADMIN : "<<endl;
    cout<<" 2) SUPPLIER : "<<endl;
    cout<<" 3) EXIT : "<<endl<<endl;
    cout<<"ENTER A CHOICE : ";
    cin>>choice;
    switch(choice)
    {
        case '1':
        Admin_Authorization();
        break;
        case '2':
        Supplier_Menu();
        break;
        case '3':
        exit(0);
        break;
        default:
        system("cls");
        cout<<"Invalid Choice !\n\n";
        system("pause");
        execute();
    }
}