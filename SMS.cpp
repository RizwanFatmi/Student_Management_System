/*-----------------------STUDENT MANAGEMENT SYSTEM-------------------------------*/


//IMPORING PACKAGES:

# include <iostream>
# include <fstream>
# include <stdlib.h>
# include <cstdlib>
# include <conio.h>

using namespace std;




//CREATING CLASS FOR STUDENT :
class student
{
private:
 string  First_Name,Last_Name,Class,Roll_No,Section,City,Mobile_No;
   
public:
 void menu();         // MENU FUNCTION
 void insert();       // INSERT FUNCTION
 void update();       // UPDATE FUNCTION
 void del();          // DELETE FUNCTION
 void search();       // SEARCH FUNCTION
 void display();      // DISPLAY FUNCTION
};



// FUNCTION FOR MENU:

void student::menu()
{
menustart:

system("cls");
int option;
char x;

cout<<"\n\n\n\n"<<endl;
cout<<"\t     --------------------------------"<<endl;
cout<<"\t\tSTUDENT MANAGEMENT SYSTEM"<<endl;
cout<<"\t     --------------------------------"<<endl;
cout<<"\t\t1. Enter Record"<<endl;
cout<<"\t\t2. Update Record"<<endl;
cout<<"\t\t3. Delete Record"<<endl;
cout<<"\t\t4. Search Record"<<endl;
cout<<"\t\t5. Display Record"<<endl;
cout<<"\t\t6. Exit"<<endl;
cout<<"\t     --------------------------------"<<endl;
cout<<"\n"<<endl;
cout<<"Choose Your Option [1/2/3/4/5/6] : ";
cin>>option;
cout<<"\n"<<endl;

switch (option)
{
    case 1: // INSERT RECORD
    do
    {
    insert();
    cout<<"\t      Do You Want To Add Another Student Record?(Y/N) : ";
    cin>>x;
    }
    while (x=='y'||x=='Y');
    break;

    case 2:  // UPDATE RECORD
    update();  
    break;

    case 3:  // DELETE RECORD
    del();
    break;

    case 4:  // SEARCH RECORD
    search();
    break;

    case 5:  // DISPLAY RECORD
    display();
    break;

    case 6:  // EXIT
  
    system("cls");
    cout<<"Program is Closed!!"<<endl<<"Thank You.\n\n\n"<<endl;
    exit(0);
    break;


default:  // INVALID CHOICE

 system("cls");

int a;
  cout<<"\n"<<endl;
  cout<<"\t---------------------"<<endl;
  cout<<"\t  Invalid Input!!"<<endl;
  cout<<"\t  Please try again."<<endl;
  cout<<"\t---------------------"<<endl;
  }
  
  getch();
  goto menustart;
  }



// FUNCTION FOR INSERTING THE RECORD:

void student::insert()
{

  system("cls");
  fstream file;

cout<<"\n\n\n\n"<<endl;
cout<<"\t     -----------------------------------------------------"<<endl;
cout<<"\t\t                ADD STUDENT RECORD"<<endl;
cout<<"\t     -----------------------------------------------------"<<endl;
cout<<"\t\t Enter First Name    :           ";
cin>>First_Name;
cout<<"\t\t Enter Last Name     :           ";
cin>>Last_Name;
cout<<"\t\t Enter Class         :           ";
cin>>Class;
cout<<"\t\t Enter Roll          :           ";
cin>>Roll_No;
cout<<"\t\t Enter Section       :           ";
cin>>Section;
cout<<"\t\t Enter City          :           ";
cin>>City;
cout<<"\t\t Enter Mobile        :           ";
cin>>Mobile_No;
cout<<"\t     -----------------------------------------------------"<<endl;
cout<<"\t      Record Saved Successfully."<<endl;


file.open("Record.txt", ios::app | ios::out);
file<<" "<< First_Name<<" "<<Last_Name <<" "<< Class <<" "<< Roll_No<<" "<< Section<<" "<< City <<" "<< Mobile_No<<"\n";
file.close();

}



// FUNCTION FOR DISPLAY THE RECORD:

void student::display()
{
system("cls");
  fstream file;
int a=0;
cout<<"\n\n\t     ---------------------------------------------"<<endl;
cout<<"\t\t              STUDENT RECORD"<<endl;
cout<<"\t     ---------------------------------------------"<<endl;

file.open("Record.txt", ios::in);

if (!file)
{
 cout<<"\n\n\t\tData Not Available!!"<<endl;
 file.close();
}

else{

file >> First_Name >> Last_Name >> Class >> Roll_No>> Section>> City >> Mobile_No;

while (!file.eof())
{

cout<<"\t\t Name          :    "<<First_Name<<" "<<Last_Name<<endl;
cout<<"\t\t Class         :    "<<Class<<endl;
cout<<"\t\t Roll          :    "<<Roll_No<<endl;
cout<<"\t\t Section       :    "<<Section<<endl;
cout<<"\t\t City          :    "<<City<<endl;
cout<<"\t\t Mobile        :    "<<Mobile_No<<endl;
cout<<"\t     ---------------------------------------------"<<endl;
file >> First_Name >> Last_Name >> Class >> Roll_No>> Section>> City >> Mobile_No;

}

if(a==0)
  {
 cout<<"\t      Press Any Key To Exit ";

}
file.close();

}
}


// FUNCTION FOR UPDATING THE RECORD:

void student::update(){

system("cls");
fstream file, file1;
string rn;
int f=0;

cout<<"\n\n\n\n"<<endl;
cout<<"\t     ---------------------------------------------"<<endl;
cout<<"\t                 UPDATE STUDENT RECORD"<<endl;
cout<<"\t     ---------------------------------------------"<<endl;

file.open("Record.txt", ios::in);
if (!file)
{

 cout<<"\n\n\t\tData Not Available!!"<<endl;
 file.close();
}


else{
cout<<"\n\t\t Enter Roll Number   :           ";
cin>>rn;
cout<<"\n\t     ---------------------------------------------"<<endl;

file1.open("SRecord.txt", ios::app | ios::out);
file >> First_Name >> Last_Name >> Class >> Roll_No>> Section>> City >> Mobile_No;
while (!file.eof())
{
 
if (rn != Roll_No)
{
  file1<<" "<< First_Name<<" "<<Last_Name <<" "<< Class <<" "<< Roll_No<<" "<< Section<<" "<< City <<" "<< Mobile_No<<"\n";
}

else{
cout<<"\t\t Enter First Name    :      ";
cin>>First_Name;
cout<<"\t\t Enter Last Name     :      ";
cin>>Last_Name;
cout<<"\t\t Enter Class         :      ";
cin>>Class;
cout<<"\t\t Enter Roll          :      ";
cin>>Roll_No;
cout<<"\t\t Enter Section       :      ";
cin>>Section;
cout<<"\t\t Enter City          :      ";
cin>>City;
cout<<"\t\t Enter Mobile        :      ";
cin>>Mobile_No;
cout<<"\t     ---------------------------------------------"<<endl;
cout<<"\t      Record Updated Successfully."<<endl;
cout<<"\t      Press Any Key To Exit ";


file1<<" "<< First_Name<<" "<<Last_Name <<" "<< Class <<" "<< Roll_No<<" "<< Section<<" "<< City <<" "<< Mobile_No<<"\n";


f++;

}

file >> First_Name >> Last_Name >> Class >> Roll_No>> Section>> City >> Mobile_No;


}
  if (f==0)
{
  cout<<"\n                Invalid Roll Number!!"<<endl;
  cout<<"\n\t     ---------------------------------------------"<<endl;
}
file1.close();
file.close();
remove("Record.txt");
rename("SRecord.txt","Record.txt");


}
}



// FUNCTION FOR DELETING THE RECORD:

void student::del(){

system("cls");
fstream file, file1;
string rn;
int f=0;

cout<<"\n\n\n\n"<<endl;
cout<<"\t     ---------------------------------------------"<<endl;
cout<<"\t                DELETE STUDENT RECORD"<<endl;
cout<<"\t     ---------------------------------------------"<<endl;

file.open("Record.txt", ios::in);
if (!file)
{

 cout<<"\n\n\t\tData Not Available!!"<<endl;
 file.close();
}


else{

cout<<"\n\t\t Enter Roll Number   :           ";
cin>>rn;
cout<<"\n\t     ---------------------------------------------"<<endl;


file1.open("SRecord.txt", ios::app | ios::out);
file >> First_Name >> Last_Name >> Class >> Roll_No>> Section>> City >> Mobile_No;
while (!file.eof())
{
 
if (rn != Roll_No)
{
  file1<<" "<< First_Name<<" "<<Last_Name <<" "<< Class <<" "<< Roll_No<<" "<< Section<<" "<< City <<" "<< Mobile_No<<"\n";
}

else{
cout<<"\t\t Name          :    "<<First_Name<<" "<<Last_Name<<endl;
cout<<"\t\t Class         :    "<<Class<<endl;
cout<<"\t\t Roll          :    "<<Roll_No<<endl;
cout<<"\t\t Section       :    "<<Section<<endl;
cout<<"\t\t City          :    "<<City<<endl;
cout<<"\t\t Mobile        :    "<<Mobile_No<<endl;
cout<<"\t     ---------------------------------------------"<<endl;
cout<<"\t      Record Deleted Successfully."<<endl;
cout<<"\t      Press Any Key To Exit ";


f++;

}

file >> First_Name >> Last_Name >> Class >> Roll_No>> Section>> City >> Mobile_No;


}
  if (f==0)
{
  cout<<"\n                Invalid Roll Number!!"<<endl;
  cout<<"\n\t     ---------------------------------------------"<<endl;
}
file1.close();
file.close();
remove("Record.txt");
rename("SRecord.txt","Record.txt");


}
}


// FUNCTION FOR SEARCHING THE RECORD:

void student::search()
{

  system("cls");
  fstream file;
  string rn;
  int f=0;

cout<<"\n\n\n"<<endl;
cout<<"\t     ---------------------------------------------"<<endl;
cout<<"\t                SEARCH STUDENT RECORD"<<endl;
cout<<"\t     ---------------------------------------------"<<endl;

file.open("Record.txt", ios::in);

if (!file)
{
 cout<<"\n\n\t\tData Not Available!!"<<endl;
 file.close();
}


else{

cout<<"\n\t\t Enter Roll Number   :           ";
cin>>rn;
cout<<"\n\t     ---------------------------------------------"<<endl;


file >> First_Name >> Last_Name >> Class >> Roll_No>> Section>> City >> Mobile_No;

while (!file.eof())
{

if (rn == Roll_No)
{
 
cout<<"\t\t Name          :    "<<First_Name<<" "<<Last_Name<<endl;
cout<<"\t\t Class         :    "<<Class<<endl;
cout<<"\t\t Roll          :    "<<Roll_No<<endl;
cout<<"\t\t Section       :    "<<Section<<endl;
cout<<"\t\t City          :    "<<City<<endl;
cout<<"\t\t Mobile        :    "<<Mobile_No<<endl;
cout<<"\t     ---------------------------------------------"<<endl;
cout<<"\t      Press Any Key To Exit ";

f++;
}
file >> First_Name >> Last_Name >> Class >> Roll_No>> Section>> City >> Mobile_No;
} 

if (f==0)
{
  cout<<"\n                Invalid Roll Number!!"<<endl;
  cout<<"\n\t     ---------------------------------------------"<<endl;

}
}

file.close();
}


// MAIN FUNCTION:

main(){

  student project;
  project.menu();
  return 0;


}


















