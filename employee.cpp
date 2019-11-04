#include "employee.h"
#include "mainmenu.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Employee::employee()
{
    
}

Employee::employee(int days, int workdays, double rate, double amount)
{
    ActualWorkDays = days;
    MonthlyWorkingDays = workdays;
    MonthlyGrossRate = rate;
    MonthlySalary = amount;
}

void Employee::listemployeerecords()
{
    cout<<"You have chosen option 1."<<endl;
    cout<<"Listing all employee records.......Done."<<endl;
    cout<<"\n";
    ifstream input("employee.txt");
   
    string name;
    while(!input.eof())
    {
        getline(input, name);
        if(name == "") continue;
        cout<<name<<endl;
    }	
    
    input.close();
    cout<<"\n";
    MainMenu menu;
    menu.continueprogram();
}

void Employee::addemployeerecords()
{
    cout<<"You have chosen option: 2. Create new employee record. What would you like to do?"<<endl;
    cout<<"1. Create a different new record\n"<<"2. Add records to existing record"<<endl;
    cout<<"3. Back to main menu"<<endl;
	  
    int option;
    cout<<"Enter your choice: ";
    cin>>option;
	  
    if(option == 1)
    {
        cout<<"\n";
        cout<<"You have chosen option 1."<<endl;
        ofstream output("employee.txt");
   
        const int ROW_SIZE = 100;
        const int COLUMN_SIZE = 5; 
        string test[ROW_SIZE][COLUMN_SIZE];
        output<<"Name";
        output<<setw(25)<<"Age";
        output<<setw(13)<<"Position";
        output<<setw(23)<<"Department";
        output<<setw(38)<<"Annual Salary(RM)"<<endl;
        output<<string(110, '=')<<endl;
        for(int row = 0; row<ROW_SIZE; row++)
	{
	    cout<<"\n";
            for(int column = 0; column<1; column++)
	    {
	        string name;
		test[row][column] = name;
		cout<<"Enter name: ";
	        cin.sync();
		getline(cin, test[row][column]);
		output<<left<<setw(25)<<test[row][column];
            }	 
            
	    for(int column = 1; column<2; column++)
            {
	        string age;
		test[row][column] = age;
		cout<<"Enter age: ";
		getline(cin, test[row][column]);
		output<<left<<"|"<<setw(7)<<test[row][column];
            }
	  
	    for(int column = 2; column<3; column++)
	    {
	        string position;
		test[row][column] = position;
		cout<<"Enter position: ";
		getline(cin, test[row][column]);
		output<<left<<"|"<<setw(20)<<test[row][column];
            }
	  
	    for(int column = 3; column<4; column++)
	    {
	        string department;
		test[row][column] = department;
		cout<<"Enter department: ";
		getline(cin, test[row][column]);
		output<<left<<"|"<<setw(30)<<test[row][column];
            }
            
            for(int column = 4; column<5; column++)
            {
                string annualsalary;
                test[row][column] = annualsalary;
                cout<<"Enter annual salary: ";
                getline(cin, test[row][column]);
                output<<left<<"|"<<test[row][column]<<endl;  
            }
            cout<<"\n";
            char cont;
	    cout<<"Do you wish to continue?(y/n): ";
	    cin>>cont;
            if(cont == 'n')
            {		    
		output.close();
                cout<<"\n";
                MainMenu menu;
                menu.continueprogram();
                break;
            }
	    else if(cont =='y')
            {
		continue;
            }
	    output.close();
        }
    }
	  
    else if(option == 2)
    {    
        cout<<"\n";
        cout<<"You have chosen option 2."<<endl;
        const int ROW_SIZE = 100;
        const int COLUMN_SIZE = 5; 
        string test[ROW_SIZE][COLUMN_SIZE];
        for(int row = 0; row<ROW_SIZE; row++)
        {
            fstream output;
            output.open("employee.txt", ios::out | ios::app);  
            const int ROW_SIZE = 100;
            const int COLUMN_SIZE = 4;
            string test[ROW_SIZE][COLUMN_SIZE];
            for(int column = 0; column<1; column++)
	    {
                cout<<"\n";
	        string name;
		test[row][column] = name;
		cout<<"Enter name: ";
                cin.sync();
		getline(cin, test[row][column]);
		output<<left<<setw(25)<<test[row][column];          
            }
	  
	    for(int column = 1; column<2; column++)
	    {
	        string age;
		test[row][column] = age;
		cout<<"Enter age: ";
		getline(cin, test[row][column]);
		output<<left<<"|"<<setw(7)<<test[row][column];
            }
	  
	    for(int column = 2; column<3; column++)
	    {
	        string position;
		test[row][column] = position;
		cout<<"Enter position: ";
		getline(cin, test[row][column]);
		output<<left<<"|"<<setw(20)<<test[row][column];
            }
	  
	    for(int column = 3; column<4; column++)
	    {
	        string department;
		test[row][column] = department;
		cout<<"Enter department: ";
	        getline(cin, test[row][column]);
		output<<left<<"|"<<setw(30)<<test[row][column];
            }
            
            for(int column = 4; column<5; column++)
            {
                string annualsalary;
                test[row][column] = annualsalary;
                cout<<"Enter annual salary: ";
                getline(cin, test[row][column]);
                output<<left<<"|"<<test[row][column]<<endl;  
            }
            output.close();
            cout<<"\n";
            char cont;
            cout<<"Do you wish to continue?(y/n): ";
            cin>>cont;
            if(cont == 'n')
            {
                cout<<"\n";
                MainMenu menu;
                menu.continueprogram();
                break;
            }
            else if(cont =='y')
            {
		continue;
            }
	  
        }     
    }
    
    else if(option == 3)
    {
        MainMenu menu;
        menu.mainmenu();
    }
    
    else if(option >= 4)
    {
        cout<<"Please key in accordingly!"<<endl;
        MainMenu menu;
        menu.mainmenu();
    }
}

void Employee::deleteemployeerecords()
{
    cout<<"You have chosen option: 3. Delete employee record. What would you like to do?"<<endl;
    cout<<"1. Delete entire employee record.\n"<<"2. Delete an employee record."<<endl;
    cout<<"3. Back to main menu."<<endl;
    
    int option;
    cout<<"Enter your choice: ";
    cin>>option;
    
    if(option == 1)
    { 
       cout<<"This will delete all the contents in the record. Continue? (y/n): ";
       char cont;
       cin>>cont;
       if(cont == 'y')
       {
          ofstream input("employee.txt", ios::out | ios::trunc);
          input.close();
          cout<<"Done."<<endl;
          cout<<"\n";
          MainMenu menu;
          menu.continueprogram();
       }
   
       if(cont == 'n')
       {
          cout<<"\n";
          MainMenu menu;
          menu.continueprogram();
       }
    }
       if(option == 2)
       {
          cout<<"\n";
          ifstream input;
	  string line;
	  string deleteline;
          input.open("employee.txt");
          ofstream temp;
          temp.open("temp.txt");
          cout << "Which employee record do you want to remove?: ";
	  cin.sync();
          getline(cin, deleteline);
	
	  size_t pos;
          while (input.good())
          {
	     getline(input, line);
	     pos = line.find(deleteline);
            if (pos == string::npos)
            {
               temp << line << endl;
            }
          }
          
          temp.close();
          input.close();
          remove("employee.txt");
          rename("temp.txt","employee.txt");
          cout <<"Record of employee "<<deleteline<<" has been deleted."<<endl;
          MainMenu menu;
          menu.continueprogram();
       }
    
    if(option == 3)
    {
        MainMenu menu;
        menu.mainmenu();
    }
    
    else if(option >= 4)
    {
        cout<<"Please key in accordingly!"<<endl;
        MainMenu menu;
        menu.mainmenu();
    }
}

void Employee::searchemployeerecord()
{
    cout<<"You have chosen option: 4. Search employee record. What would you like to do?"<<endl;
    cout<<"1. Search employee record.\n"<<"2. Back to main menu."<<endl;
    int option;
    cout<<"Enter your choice: ";
    cin>>option;
    if(option == 1)
    {
       string search;
       ifstream inFile;
       string line;
        
       inFile.open("employee.txt");
        
       cout << "Enter keyword to search for: ";
       cin.sync();
       getline(cin, search);
        
       size_t pos; 
       cout<<"\n";
       cout<<"Name"<<setw(25)<<"Age"<<setw(13)<<"Position"<<setw(23)<<"Department"<<endl;
       cout<<string(90, '=')<<endl;
       while(inFile.good())
       {
          getline(inFile, line);
          pos = line.find(search); 
          if(pos != string::npos) 
          { 
             cout<< line <<endl;         
          }
       }
    
       cout<<"\n";
       char cont;
       cout<<"Do you wish to continue?(y/n): ";
       cin>>cont;
       cout<<"\n";
       if(cont == 'n')
       {	
          MainMenu menu;
          menu.continueprogram();
       }
       else if(cont =='y')
       {
          Employee employee;
          employee.searchemployeerecord();
       }
       else
       {
          MainMenu menu;
          menu.continueprogram();
       }
    }
    
    if(option == 2)
    {
        MainMenu menu;
        menu.mainmenu();
    }
    
    else if(option >= 3)
    {
        cout<<"Please key in accordingly!"<<endl;
        MainMenu menu;
        menu.mainmenu();
    }
}

void Employee::leaveofabsence()
{
    cout<<"You have chosen option: 6. Employee leave of absence. What would you like to do?"<<endl;
    cout<<"1. List employee leave of absence.\n"<<"2. Add employee leave of absence."<<endl;
    cout<<"3. Search employee leave of absence record.\n"<<"4. Back to main menu."<<endl;
    
    int option;
    cout<<"Enter your choice: ";
    cin>>option;
    
    if(option == 1)
    {
        cout<<"\n";
        cout<<"You have chosen option 1."<<endl;
        cout<<"Listing all employee leave of absence.......Done."<<endl;
        cout<<"\n";
        ifstream input("absence.txt");
   
        string absence;
        while(!input.eof())
        {
           getline(input, absence);
           cout<<absence<<endl;
        }
	  
        input.close();
        MainMenu menu;
        menu.continueprogram();
    }

    if(option == 2)
    {
        cout<<"\n";
        cout<<"You have chosen option 2."<<endl;
        cout<<"\n";
        const int ROW_SIZE = 100;
        const int COLUMN_SIZE = 3; 
        string test[ROW_SIZE][COLUMN_SIZE];
        for(int row = 0; row<ROW_SIZE; row++)
        {
            fstream output;
            output.open("absence.txt", ios::out | ios::app);
            const int ROW_SIZE = 100;
            const int COLUMN_SIZE = 3; 
            string test[ROW_SIZE][COLUMN_SIZE];
            for(int column = 0; column<1; column++)
	    {
	        string name;
                test[row][column] = name;
	        cout<<"Enter name: ";
	        cin.sync();
	        getline(cin, test[row][column]);
	        output<<left<<setw(25)<<test[row][column];
            }	 
            
	    for(int column = 1; column<2; column++)
            {
	        string department;
                test[row][column] = department;
	        cout<<"Enter department: ";
	        getline(cin, test[row][column]);
	        output<<left<<"|"<<setw(40)<<test[row][column];
            }
	  
	    for(int column = 2; column<3; column++)
	    {
	        string date;
                test[row][column] = date;
	        cout<<"Enter date: ";
                getline(cin, test[row][column]);
                output<<left<<"|"<<setw(25)<<test[row][column]<<endl;
            }
	  
            cout<<"\n";
            char cont;
	    cout<<"Do you wish to continue?(y/n): ";
	    cin>>cont;
            if(cont == 'n')
            {	
                cout<<"\n";
                output.close();
                MainMenu menu;
                menu.continueprogram();
                break;
            }
	    else if(cont =='y')
            {
	        continue;
            }
            else
            {
                cout<<"\n";
                output.close();
                MainMenu menu;
                menu.continueprogram();
                break;
            }
	    output.close();
        }
    }
    
    if(option == 3)
    {
        string search;
        ifstream inFile;
        string line;
        
        inFile.open("absence.txt");
        
        cout<<"\n";
        cout << "Enter word to search for: ";
        cin.sync();
        getline(cin, search);
        
        size_t pos; 
        cout<<"\n";
	cout<<"Name"<<setw(32)<<"Department"<<setw(35)<<"Date"<<endl;
	cout<<string(90, '=')<<endl;
        while(inFile.good())
        {
           getline(inFile, line);
           pos = line.find(search); 
           if(pos != string::npos) 
           { 
              cout<< line <<endl;         
           }
        }
        cout<<"\n";
        MainMenu menu;
        menu.continueprogram();
    }
    
    if(option == 4)
    {
        MainMenu menu;
        menu.mainmenu();
    }
    
    else if(option >= 5)
    {
        cout<<"Please key in accordingly!"<<endl;
        MainMenu menu;
        menu.mainmenu();
    }
    
}

void Employee::editemployeerecord()
{
    cout<<"You have chosen option: 5. Edit employee record. What would you like to do?"<<endl;
    cout<<"1. Edit employee record.\n"<<"2. Back to main menu."<<endl;
    
    int option;
    cout<<"Enter your choice: ";
    cin>>option;
    
    if(option == 1)
    {
        cout<<"\n";
        cout<<"You have chosen option 1."<<endl;
        
        cout<<"\n";
        ifstream input;
	string line;
	string deleteline;
        input.open("employee.txt");
        ofstream temp;
        temp.open("temp.txt");
        cout << "Which employee record do you want to edit?: ";
	cin.sync();
        getline(cin, deleteline);
	
	size_t pos;
        while (input.good())
        {
	   getline(input, line);
	   pos = line.find(deleteline);
           if (pos == string::npos)
           {
              temp << line << endl;
           }
        }
          
        temp.close();
        input.close();
        remove("employee.txt");
        rename("temp.txt","employee.txt");
        
        const int ROW_SIZE = 100;
        const int COLUMN_SIZE = 5; 
        string test[ROW_SIZE][COLUMN_SIZE];
        for(int row = 0; row<ROW_SIZE; row++)
        {
            fstream output;
            output.open("employee.txt", ios::out | ios::app);  
            const int ROW_SIZE = 100;
            const int COLUMN_SIZE = 4;
            string test[ROW_SIZE][COLUMN_SIZE];
            for(int column = 0; column<1; column++)
	    {
                cout<<"\n";
	        string name;
		test[row][column] = name;
		cout<<"Enter name: ";
                cin.sync();
		getline(cin, test[row][column]);
		output<<left<<setw(25)<<test[row][column];          
            }
	  
	    for(int column = 1; column<2; column++)
	    {
	        string age;
		test[row][column] = age;
		cout<<"Enter age: ";
		getline(cin, test[row][column]);
		output<<left<<"|"<<setw(7)<<test[row][column];
            }
	  
	    for(int column = 2; column<3; column++)
	    {
	        string position;
		test[row][column] = position;
		cout<<"Enter position: ";
		getline(cin, test[row][column]);
		output<<left<<"|"<<setw(20)<<test[row][column];
            }
	  
	    for(int column = 3; column<4; column++)
	    {
	        string department;
		test[row][column] = department;
		cout<<"Enter department: ";
	        getline(cin, test[row][column]);
		output<<left<<"|"<<setw(30)<<test[row][column];
            }
            
            for(int column = 4; column<5; column++)
            {
                string annualsalary;
                test[row][column] = annualsalary;
                cout<<"Enter annual salary: ";
                getline(cin, test[row][column]);
                output<<left<<"|"<<test[row][column]<<endl;
                
            }
            output.close();
            cout<<"\n";
            char cont;
            cout<<"Do you wish to continue?(y/n): ";
            cin>>cont;
            cout<<"\n";
            if(cont == 'n')
            {	
                cout<<"\n";
                output.close();
                MainMenu menu;
                menu.continueprogram();
                break;
            }
            else if(cont =='y')
            {
                continue;
            }
            else
            {
                cout<<"\n";
                output.close();
                MainMenu menu;
                menu.continueprogram();
                break;
            }
        }
        
    }
    
    if(option == 2)
    {
        MainMenu menu;
        menu.mainmenu();
    }
    
    else if(option >= 3)
    {
        cout<<"Please key in accordingly!"<<endl;
        MainMenu menu;
        menu.mainmenu();
    }
}


