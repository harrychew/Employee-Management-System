#include <iostream>
#include <fstream>
#include <iomanip>
#include "mainmenu.h"
using namespace std;

int main() 
{
    cout<<"Welcome to Employee Management System version 1.0"<<endl;
    cout<<string(50, '=')<<endl;
    MainMenu menu;
    menu.mainmenu();
        
    return 0;
}

