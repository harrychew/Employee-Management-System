#include "mainmenu.h"
#include "employee.h"
#include <iostream>
using namespace std;

MainMenu::menu()
{
    
}

void MainMenu::mainmenu()
{
    cout<<"\nMain Menu:"<<endl;
    cout<<"1. List all employee records\n"<<"2. Create new employee record\n";
    cout<<"3. Delete employee record\n"<<"4. Search employee records\n";
    cout<<"5. Edit employee records\n"<<"6. Employee leave of absence\n";
    cout<<"7. Employee salary calculator\n"<<"8. Exit"<<endl;
   
    cout<<"\n";
    int selection;
    cout<<"Which option would you like to choose? : ";
    cin>>selection;
    cout<<"\n";

    if(selection == 1)
    {
        Employee employee;
        employee.listemployeerecords();
    }
    
    if(selection == 2)
    {
        Employee employee;
        employee.addemployeerecords();
    }
    
    if(selection == 3)
    {
        Employee employee;
        employee.deleteemployeerecords();
    }
    
    if(selection == 4)
    {
        Employee employee;
        employee.searchemployeerecord();
    }
    
    if(selection == 5)
    {
        Employee employee;
        employee.editemployeerecord();
    }
    
    if(selection == 6)
    {
        Employee employee;
        employee.leaveofabsence();
    }
    
    if(selection == 7)
    {
        
    }
    
    if(selection == 8)
    {
        cout<<"Exiting program......Done"<<endl;
        exit;
    }
    else if(selection >= 9)
    {
        cout<<"Please key in accordingly!"<<endl;
        mainmenu();
    }
}

void MainMenu::continueprogram()
{
    cout<<"What would you like to do now? "<<endl;
    cout<<"1. Back to main menu.\n"<<"2. Exit program."<<endl;
    int option;
    cout<<"Enter choice: ";
    cin>>option;
    cout<<"\n";
    
    if(option == 1)
    {
        MainMenu menu;
        menu.mainmenu();
    }
    if(option == 2)
    {
        cout<<"Exiting program......Done"<<endl;
        exit;
    }
}


