#include<iostream>
#include<fstream>
using namespace std;
class seq_file{
struct stud{
int roll;
string name;
}s;
int i; //count var
public:
void create();
void display();
void search();
void modify();
void del();
};
void seq_file::create()
{
ofstream out;
out.open("student.data", ios::out|ios::binary);
char ans='y';
i=0;
do{
cout<<"\nEnter Details of Student Record "<<i+1<<" below: ";
cout<<"\nEnter roll number: ";
cin>>s.roll;
cout<<"Enter Name: ";
cin>>s.name;
out.write((char *)&s,sizeof(s));
i++;
cout<<"\nDo you want to continue(Y/N): ";
cin>>ans;
}while(ans=='y'||ans=='Y');
out.close();
cout<<"\n\tSuccessfully Entered "<<i<<" records in file.";
}
void seq_file::display()
{
ifstream in;
in.open("student.data", ios::in|ios::binary);
i=0;
while(in.read((char *)&s,sizeof(s))){
cout<<"\nDetails of Student Record "<<i+1<<" are:";
cout<<"\nName: "<<s.name;
cout<<"\nRoll number: "<<s.roll<<endl;
i++;
}
in.close();
cout<<"\n\tSuccessfully Displayed "<<i<<" Records from File.";
}
void seq_file::search()
{
int key, flag=0;
cout<<"\nEnter roll number to search: ";
cin>>key;
ifstream in;
in.open("student.data", ios::binary);
while(in.read((char *)&s, sizeof(s)))
{
if(s.roll==key)
{
flag=1;
break;
}
}
if(flag==1)
cout<<"\nRecord found in File with name: "<<s.name;
else
cout<<"\nRecord not found!";
}
void seq_file::del()
{
int key;
cout<<"\nEnter roll number to delete respective record: ";
cin>>key;
ifstream in;
ofstream out;
in.open("student.data",ios::binary);
out.open("temp.data",ios::binary);
while(in.read((char*)&s, sizeof(s)))
if(s.roll!=key)
out.write((char*)&s, sizeof(s));
in.close();
out.close();
remove("student.data");
if(!rename("temp.data","student.data"))
cout<<"\nDeletion successful";
else
cout<<"\nDeletion failed while renaming new file.";
}
void seq_file::modify()
{
int key, flag=0;
string nm;
cout<<"\nEnter roll number to be modified: ";
cin>>key;
cout<<"\nEnter new name to be recorded: ";
cin>>nm;
fstream x;
x.open("student.data",ios::in|ios::out|ios::binary);
while(x.read((char*)&s, sizeof(s)))
{
if(s.roll==key)
{
flag=1;
x.seekp(x.tellg()-sizeof(s));
s.name=nm;
x.write((char*)&s, sizeof(s));
break;
}
}
if(flag==1)
cout<<"\nChange was successful!";
else
cout<<"\nRecord not found!";
}
int main()
{
int ch;
seq_file obj;
while(true)
{
cout<<"\n**************MENU***************";
cout<<"\n\t1.Create File";
cout<<"\n\t2.Display File";
cout<<"\n\t3.Search in File";
cout<<"\n\t4.Modify File Entry";
cout<<"\n\t5.Delete File record";
cout<<"\n\t6.Exit";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch)
{
case 1: obj.create();
break;
case 2: obj.display();
break;
case 4: obj.modify();
break;
case 3: obj.search();
break;
case 5: obj.del();
break;
case 6: cout<<"\nProgram ends!";
return 0;
default: cout<<"\nEntered invalid choice number, try again... ";
break;
}
}
}
