#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
#include<fstream>
#include<direct.h>
#include<time.h>
#include<dos.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
string gg="";
/**************************************************/
void delay(unsigned int mseconds);
int display_files(string mm,string m);
bool checkemail(string email,string file);
bool checkpassword(string pass,string file);
int password(string mail,string pass);
void show_all_Students();
void Edit_student(string file);
void Edit_teacher(string file);
void show_teacher_dir(string file);
void show_students_dir(string file);
void show_all_teachers();
void remove_stu(string file);
/*****************************************************/
class teacher_signup
{
private:
   string first_name;
   string last_name;
   string department;
   string gmail;
   string classes;
   string password;
public:
    void get_teacher_data();

};
/////////////////////////////////////////////////////////////////
class student_signup
{
private:
   string first_name;
   string last_name;
   string father_name;
   string department;
   string gmail;
   string your_class;
   string mobile_no;
   string roll_no;
   string password;
public:
    void get_student_data();
};
////////////////////////////////////////////////////////////////////
int display_files(string mm,string m)
{
    m+=mm;
    mm=m;
    const int MAX = 80; //size of buffer
char buffer[mm.size()+1];
strcpy(buffer,mm.c_str());
char ch;
    ifstream outfile;
    outfile.open(buffer,ios::binary);
    while(!outfile.eof())
    {
        outfile.get(ch);
        cout<<ch;
    }
}
/////////////////////////////////////////////////////////////////////////
void teacher_signup::get_teacher_data()
{
    int n=0,n_o_cla;
      int c=1,s=1,nn=1,ss=1;
    ofstream fout,fpall;
   fstream fserial;
   string dummy;
   string conform_password;
   fpall.open("maiin/teacherlist.txt",ios::app);
   fpall<<endl;
   fserial.open("maiin/tsrial.txt",ios::in);
   fserial>>n;
   n++;
   fpall<<setw(34)<<n<<".";
   fserial.close();
   fserial.open("maiin/tsrial.txt",ios::out);
   fserial<<n;
   fserial.close();
   cin.ignore(100,'\n');
   cout<<"Your First Name :";
   getline(cin,first_name);fpall<<setw(18)<<first_name<<" ";
   cout<<"Your Last name :";
   getline(cin,last_name);fpall<<setw(1)<<last_name;

   /*--------------------------------------------------------------*/
   department:
       cout<<"Enter Your Department:-";
       getline(cin,department);fpall<<setw(18)<<department<<" ";

   /*--------------------------------------------------------------*/
    mail:
      cout<<"Enter Your Email:-";
      getline(cin,gmail);
      {
           for (int i=0;i<gmail.size();i++)
    {
         if(gmail[i]>=48 && gmail[i]<=57)
            nn=0;
         if(gmail[i]=='@' )
            ss=0;
    }
    if(nn==0 && ss==0){
       if(checkemail(gmail,"maiin/teachermail.txt"))
       {
           cout<<"YOU ALREADY HAVE ACCOUNT\n";
           goto mail;
       }

   fpall<<setw(26)<<gmail;
   ofstream femail;
   femail.open("maiin/teachermail.txt",ios::app);
   femail<<gmail<<endl;
   femail.close();}
   else{
        cout<<"\nEMAIL NID IS NOT VALID";
    goto mail;}}
   /*--------------------------------------------------------------*/
      dummy="Teachers/"+gmail+".txt";
      char filename[dummy.size()+1];
      strcpy(filename,dummy.c_str());
      fout.open(filename,ios::binary);
      fout<<first_name<<endl;
      fout<<last_name<<endl;
      fout<<department<<endl;
      fout<<gmail<<endl;
   /*--------------------------------------------------------------*/
    classes:
        //cout<<"Enter Number of Classes U ATTEND:-" ;cin>>n_o_cla;
        cout<<"\nENTER CLASSES THAT YOU ATTEND(seprate by comma's)";
       // for(int i=0;i<n_o_cla;i++)

             getline(cin,classes);fpall<<setw(20)<<classes<<" ";
            fout<<classes<<" ";

  /*--------------------------------------------------------------*/
    password:
        cout<<"\nENTER PASSWORD:-";
        getline(cin,password);
        {
           if(checkpassword(password,"maiin/teacherpasswrd.txt"))
            {
              cout<<"\nYOU HAVE ENTER THE SAME PASSWORD IN OUR DATEBASE!!..PLEASE TRY DIFFRENT PASSWORD\n";
              goto password;
            }
             if(password.size()>=12 ){
                cout<<"\nPASSWORD SHOULD BE OF MAXIMUM 12 DIGITS";
                goto password;}
            if(password.size()<5){
                cout<<"\nPASSWORD SHOULD BE OF MINIMUM 5 DIGITS";
                goto password;}
        }
         for (int i=0;i<password.size();i++)
    {
        if (password[i]>59 && password[i]<91)
           c=0;
         if(password[i]>90 && password[i]<123)
           s=0;
         if(password[i]>=48 && password[i]<=57)
            nn=0;
         if(password[i]=='@' || password[i]=='*')
            ss=0;
    }
    if(c==1)cout<<"\ncapital chracter is compulsry";
    if (s==1)cout<<"\nsmall cg is cmpulsry";
    if(nn==1)cout<<"\nnum cg is cmpulsry";
    if(ss==1)cout<<"\nspcial symbol cg is cmpulsry";
    if(c==0 && s==0 && nn==0 && ss==0)//cout<<"\naccepted";
{
            cout<<"\nCONFIRM PASSWORD";
            getline(cin,conform_password);
            if(conform_password != password)
            {
                cout<<"\nPASSWORD IS NOT SAME";
                goto password;
            }
}
            else
            goto password;
            ofstream fpass;
            fpass.open("maiin/teacherpasswrd.txt",ios::app);
            fpass<<password<<endl;
            fpass.close();
  /*--------------------------------------------------------------*/


}
/////////////////////////////////////////////////////////////////////////
bool checkemail(string email,string file)
{   vector<string> str;
   char page[file.size()+1];
    strcpy(page,file.c_str());

    ifstream fin;
    fin.open(page);
  while(!fin.eof()){
        string s="";
    getline(fin,s);
   str.push_back(s);

  }
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==email)
            return true;
    }
return false;
fin.close();
}
////////////////////////////////////////////////////////////////////////
bool checkpassword(string pass,string file)
{   vector<string> str;
    char page[file.size()+1];
    strcpy(page,file.c_str());

    ifstream fin;
    fin.open(page);
  while(!fin.eof()){
        string s="";
    getline(fin,s);
   str.push_back(s);

  }
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==pass)
            return true;
    }
return false;
fin.close();
}
////////////////////////////////////////////////////////////////////////
void student_signup::get_student_data()
{
    int n=0,n_o_cla,nn=1,ss=1,c=1,s=1;
    ofstream fout,fpall;
   fstream fserial;
   string dummy;
   string conform_password;
   fpall.open("maiin/studentlist.txt",ios::app);
   fpall<<endl;
   fserial.open("maiin/ssrial.txt",ios::in);
   fserial.open("maiin/ssrial.txt",ios::in);
   fserial>>n;
   n=n+1;
   fpall<<setw(6)<<n<<".";
   fserial.close();
   fserial.open("maiin/ssrial.txt",ios::out);
   fserial<<n;
   fserial.close();
   cin.ignore(100,'\n');
   cout<<"Your First Name :-";
   getline(cin,first_name);fpall<<setw(10)<<first_name<<" ";
   cout<<"Your Last name :-";
   getline(cin,last_name);fpall<<setw(1)<<last_name;

    /*--------------------------------------------------------------*/
   department:
       cout<<"Enter Your Department:-";
       getline(cin,department);fpall<<setw(18)<<department<<" ";
   /*--------------------------------------------------------------*/
    mail:
        cout<<"Enter Your Email:-";
        getline(cin,gmail);
      {
           for (int i=0;i<gmail.size();i++)
    {
         if(gmail[i]>=48 && gmail[i]<=57)
            nn=0;
         if(gmail[i]=='@' )
            ss=0;
    }
    if(nn==0 && ss==0){

       if(checkemail(gmail,"maiin/studentmail.txt"))
       {
           cout<<"YOU ALREADY HAVE ACCOUNT\n";
           goto mail;
       }
   fout<<gmail<<endl;
   fpall<<setw(26)<<gmail;
   ofstream femail;
   femail.open("maiin/studentmail.txt",ios::app);
   femail<<gmail<<endl;
   femail.close();
    }
    else{
            cout<<"\n EMAIL ID IS NOT VALID";
        goto mail;
        }}

   /*--------------------------------------------------------------*/
    your_class:
        cout<<"enter your class:-";
        getline(cin,your_class);fpall<<setw(18)<<your_class;
    /*--------------------------------------------------------------*/
    father_name:
        cout<<"enter fathers name:-";
        getline(cin,father_name);fpall<<setw(18)<<father_name;
    /*--------------------------------------------------------------*/
    roll_no:
        cout<<"enter roll no:-";
        getline(cin,roll_no);fpall<<setw(18)<<roll_no;
    /*--------------------------------------------------------------*/
     mobile_no:
        cout<<"enter mobile:-";
        getline(cin,mobile_no);{
        if(mobile_no.size()!=10){
            cout<<"PHONE NUMBER IS INVALID \nTRY AGAIN";
            goto mobile_no;}
        else
        fpall<<setw(18)<<mobile_no;}
     /*--------------------------------------------------------------*/
     password:
         cout<<"\n PASSWORD MUST CONTAIN:-\n 1.A CAPITAL LETTER\n2.A SMALL LETTER\n3.A NUMBER\n4.@ OR &:";
        cout<<"\nENTER PASSWORD:-";
        getline(cin,password);
        {
           if(checkpassword(password,"maiin/studentpasswrd.txt"))
            {
              cout<<"YOU HAVE ENTER THE SAME PASSWORD IN OUR DATEBASE!!..PLEASE TRY DIFFRENT PASSWORD\n";
              goto password;
            }}
             if(password.size()>=12 )
                {
                cout<<"\nPASSWORD SHOULD BE OF MAXIMUM 12 DIGITS";
                goto password;
               }
            if(password.size()<5)
            {
              cout<<"\nPASSWORD SHOULD BE OF MINIMUM 5 DIGITS";
              goto password;
            }


    for (int i=0;i<password.size();i++)
    {
        if (password[i]>59 && password[i]<91)
           c=0;
         if(password[i]>90 && password[i]<123)
           s=0;
         if(password[i]>=48 && password[i]<=57)
            nn=0;
         if(password[i]=='@' || password[i]=='*')
            ss=0;
    }
    if(c==1)cout<<"\ncapital chracter is compulsry";
    if (s==1)cout<<"\nsmall cg is cmpulsry";
    if(nn==1)cout<<"\nnum cg is cmpulsry";
    if(ss==1)cout<<"\nspcial symbol cg is cmpulsry";
    if(c==0 && s==0 && nn==0 && ss==0)//cout<<"\naccepted";
{
            cout<<"\nCONFIRM PASSWORD:-";
            getline(cin,conform_password);
            if(conform_password != password)
            {
                cout<<" \n PASSWORD IS NOT SAME";
            }
            ofstream fpass;
            fpass.open("maiin/studentpasswrd.txt",ios::app);
            fpass<<password<<endl;
            fpass.close();}
            else
goto password;
    /*--------------------------------------------------------------*/
      dummy="Students/"+gmail+".txt";
   char filename[dummy.size()+1];
   strcpy(filename,dummy.c_str());
   fout.open(filename,ios::binary);
   fout<<first_name<<endl;
   fout<<last_name<<endl;
   fout<<department<<endl;
   fout<<your_class<<endl;
   fout<<roll_no<<endl;
   fout<<father_name<<endl;
   fout<<mobile_no<<endl;
   fout<<gmail<<endl;
   fout<<password;
    /*--------------------------------------------------------------*/

}
////////////////////////////////////////////////////////////////////////
void Sign_in(string mail,string pass)
{   static int counte=0;

	string email;
	cout<<"\n\n\t\t\t\t\t\t\t\t\tEmail     : ";
	cin>>email;
	if(checkemail(email,mail)){
	int n=password(mail,pass);
	 if(n==1)
     {

      gg=email;
      return;
     }
	}
	else
      if(counte<2)
	{
	    counte++;
	cout<<"\n wrong email try again please!!! \n ";
	_getch();
	//system("pause");
	system("cls");
	gg="";
	Sign_in(mail,pass);
	}
  else
  {
     cout<<"\nYou have crossed the limit to enter wrong email!!!!\n\n\n";
     _getch();
    exit(0);
  }

}
////////////////////////////////////////////////////////////////////////
int password(string mail,string pass)
{   static int countp=0;
	string passw="";
cout<<"\n\t\t\t\t\t\t\t\t\tPassword  : ";
    char ch;
    ch=_getch();
    while(ch != 13 && ch!=8)
    {

    	passw.push_back(ch);
    	cout<<"*";
    	ch=_getch();
    	if(passw.size()>=13)
    	break;

    }
    if(checkpassword(passw,pass))
    { cout<<"\ngranted!!\n";

    _getch();
     return 1;
    }
	else
        if(countp<=2)
	{   countp++;
	    cout<<" \n\t\t\t\t\t\t\t\t\t wrong password\n\t\t\t\t\t\t\t\t\tTRY AGAIN!!!!!!!!\n\n\n\n";
	//system("pause");
	//system("cls");
	//Sign_in(mail,pass);
	password(mail,pass);
	}
    else
    {
      cout<<"\n\nYOU HAVE CROSSED THE LIMIT TO ENTER WRONG PASSWORD!!!!!!\n\n\n\n";
      exit(0);
    }
}
////////////////////////////////////////////////////////////////////////
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
/////////////////////////////////////////////////////////////////////////
void gotoxy (int x, int y)
{
         COORD coordinates;
         coordinates.X = x;
         coordinates.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
/////////////////////////////////////////////////////////////////////////
void add_teacher()
{
    teacher_signup T;
    T.get_teacher_data();
}
////////////////////////////////////////////////////////////////////////
void add_student()
{
    student_signup S;
    S.get_student_data();
}
///////////////////////////////////////////////////////////////////////
void show_all_Students()
{
   char ch;
    ifstream fin;
    fin.open("maiin/studentlist.txt",ios::binary);
   while(!fin.eof())
   {
       fin.get(ch);
       cout<<ch;
    }
    fin.close();
}
///////////////////////////////////////////////////////////////////////
void show_all_teachers()
{
   char ch;
    ifstream fin;
    fin.open("maiin/teacherlist.txt",ios::binary);
   while(!fin.eof())
   {
       fin.get(ch);
       cout<<ch;
    }
    fin.close();
}
///////////////////////////////////////////////////////////////////////
void show_teacher_dir(string file)
{
    system("cls");
   file="Teachers/"+file+".txt";
//cout<<file;
   ifstream fin;
  vector <string> str;
   char filename[file.size()+1];
   strcpy(filename,file.c_str());
   fin.open(filename,ios::in);

   if(!fin)
		{
		cout<<"\nError while opening the file\n";
		system("pause");
		system("cls");
		exit(0);
		}
		else
        {
while(!fin.eof()){
        string s="";
    getline(fin,s);
   str.push_back(s);

  }
  cout<<"\n\n\n\n\n\n\n\n\n\n";
   cout<<"\t\t\t\t*******************************************************************************************************************\n";
  cout<<"\t\t\t\t\t\t\t\t\t  "<<str[0]+" "+str[1]<<"'S PROFILE"<<endl;
  cout<<"\t\t\t\t*******************************************************************************************************************\n\n\n";
   cout<<"\t\t\t\t\t\t\t\t\t1. First Name   :-"<<str[0]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t2. Last Name    :-"<<str[1]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t3. Department   :"<<str[2]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t4. Email        :"<<str[3]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t5. Classes      :"<<str[4]<<endl;
   cout<<"\n\n\n\t\t\t\t\t\t\t.........................ENDING OF FILE....................................\n\n";
   fin.close();
    }
}
////////////////////////////////////////////////////////////////////////
void show_students_dir(string file)
{
    system("cls");
   file="Students/"+file+".txt";
//cout<<file;
   ifstream fin;
  vector <string> str;
   char filename[file.size()+1];
   strcpy(filename,file.c_str());
   fin.open(filename);

   if(!fin)
		{
		cout<<"\nError while opening the file\n";
		system("pause");
		system("cls");
		exit(0);
		}
		else
        {
while(!fin.eof()){
        string s="";
    getline(fin,s);
   str.push_back(s);

  }
   cout<<"\n\n\n\n\n\n\n\n";
  cout<<"\t\t\t\t*******************************************************************************************************************\n";
  cout<<"\t\t\t\t\t\t\t\t\t\t"<<str[0]<<" "<<str[1]<<"'s profile"<<endl;
  cout<<"\t\t\t\t*******************************************************************************************************************\n\n\n";
  cout<<"\n\n";
   cout<<"\t\t\t\t\t\t\t\t\t1. First Name   :-"<<str[0]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t2. Last Name    :-"<<str[1]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t3. Department   :-"<<str[2]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t4. Class        :-"<<str[3]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t5. Roll-NO.     :-"<<str[4]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t6. Fathers Name :-"<<str[5]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t7. Mobile-No.   :-"<<str[6]<<endl;
   cout<<"\t\t\t\t\t\t\t\t\t8. Email        :-"<<str[7]<<endl;
   cout<<"\n\n\n\n\t\t\t\t\t\t  .........................ENDING OF FILE......................................\n\n";
   fin.close();
    }
}
///////////////////////////////////////////////////////////////////////
void Edit_teacher(string file)
{   show_teacher_dir(file);
    file="Teachers/"+file+".txt";
    char filename[file.size()+1];
   strcpy(filename,file.c_str());
    vector<string> s;
    ifstream fin;
    fin.open(filename);
    while(!fin.eof()){
     string temp="";
     getline(fin,temp);
     s.push_back(temp);
    }
     fin.close();
     ofstream out;
     out.open(filename,ios::binary);
    A:
    cout<<"\nEnter choice you want to edit : ";
    int n;
    string ss;
    cin>>n;
    cin.ignore(1,'\n');
    system("cls");
    cout<<"\n\n\n";


if(n==1)
    {
        for(int i=0;i<s.size();i++)
    {   if(i==n-1){
    cout<<"1.Teacher First Name :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    }
else
    if(n==2)
{
 for(int i=0;i<s.size();i++)
    {   if(i==n-1){
    cout<<"2. Teacher Last Name :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
}
else
    if(n==3)
for(int i=0;i<s.size();i++)
    {   if(i==n-1){
    cout<<"3. Department:";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    else
        if(n==4)
     for(int i=0;i<s.size();i++)
    {   if(i==n-1){
    cout<<"4. email :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    else
    if(n==5)
    for(int i=0;i<s.size();i++)
    {   if(i==n-1){
     cout<<"5. clases :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;}
   cout<<"\nyou have change information successfully\n\n\n\n";
   _getch();
}
///////////////////////////////////////////////////////////////////////
/*void chnge_pss_stu(string file)
{
    file="maiin/"+file+".txt";
    char filename[file.size()+1];
   strcpy(filename,file.c_str());
    vector<string> s;
    ifstream fin;
    fin.open(filename);
    while(!fin.eof()){
     string temp="";
     getline(fin,temp);
     s.push_back(temp);
    }
     fin.close();
     ofstream out;
     out.open(filename,ios::binary);
       for(int i=0;i<s.size();i++)
    {   if(i==n-1)
    cout<<"1.enter psswrd :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
}*/
////////////////////////////////////////////////////////////////////////
void Edit_student(string file)
{   show_students_dir(file);
    file="Students/"+file+".txt";
    char filename[file.size()+1];
   strcpy(filename,file.c_str());
    vector<string> s;
    ifstream fin;
    fin.open(filename);
    while(!fin.eof()){
     string temp="";
     getline(fin,temp);
     s.push_back(temp);
    }
     fin.close();
     ofstream out;
     out.open(filename,ios::binary);
    A:
    cout<<"\nEnter choice you want to edit : ";
    int n;
    string ss;
    cin>>n;
    cin.ignore(1,'\n');
    system("cls");
    cout<<"\n\n\n";

if(n==1)
    {
        for(int i=0;i<s.size();i++)
    {   if(i==n-1){
    cout<<"1.stu First Name :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    }
else
    if(n==2)
{
 for(int i=0;i<s.size();i++)
    {   if(i==n-1){
    cout<<"2. stu Last Name :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
}
else
    if(n==3)
for(int i=0;i<s.size();i++)
    {   if(i==n-1){
    cout<<"3. Department:";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    else
        if(n==4)
     for(int i=0;i<s.size();i++)
    {   if(i==n-1){
    cout<<"4. class :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    else
    if(n==5)
    for(int i=0;i<s.size();i++)
    {   if(i==n-1){
     cout<<"5. rollno :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    else
    if(n==6)
    for(int i=0;i<s.size();i++)
    {   if(i==n-1){
     cout<<"6. father name";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    else
    if(n==7)
    for(int i=0;i<s.size();i++)
    {   if(i==n-1){
     cout<<"7. mobile no :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }
    else
    if(n==8)
    for(int i=0;i<s.size();i++)
    {   if(i==n-1){
     cout<<"8. email :";
    getline(cin,ss);
    out<<ss<<endl;
    }
    else
        out<<s[i]<<endl;
    }


   cout<<"\nyou have change information successfully\n\n\n\n";
   _getch();
}

///////////////////////////////////////////////////////////////////////
int main ()
{
    int choose,menu_choose,stu_in_choose,tea_in_choose,pc;
    string mm,pp;
main:
    display_files("logo.txt","maiin/");
    //cout<<"\n\n\n\n\n";
     gotoxy(65,26);
    for(int process=0;process<35;process++)
  {
   delay(200);
    printf(".");
  }
  gotoxy(87,40);
  cout<<"Press any key to continue.......";
  getchar();
  system("cls");
  do{
    system("cls");
  display_files("main.txt","maiin/");
  cin>>choose;
  switch(choose)
  {
  case 2://as a student
      do{
    system("cls");
     display_files("options.txt","maiin/");
      cout<<"\n\t\t\tchoose an option";
      cin>>menu_choose;
     switch(menu_choose)
      {
      case 1://student signin
          system("cls");
          display_files("signinstu.txt","maiin/");
          Sign_in("maiin/studentmail.txt","maiin/studentpasswrd.txt");
          ss:
          system("cls");
          display_files("student.txt","maiin/");
          //cout<<"\n\t\t\tchoose an option";
          cin>>stu_in_choose;
          switch(stu_in_choose)
          {
          case 1:
              show_students_dir(gg);
              _getch();
              goto ss;
          case 2:
              Edit_student(gg);
              _getch();
              goto ss;
          case 3:
            cout<<"\nlogout..";cout<<"\a";
            Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";
            Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";
            cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);
            cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";
            system("cls");
            gg="";
            goto main;
         }
          _getch();
        break;
      case 2://sttuddent signup
          add_student();
      cout<<"\nSIGN UP SUCESSFULLY AS A STUDENT";
      getchar();
        break;
      }}while(menu_choose != 3);
      break;
  case 3://as a teacher
      do{
      system("cls");
     display_files("options.txt","maiin/");
     cout<<"\n\t\t\tchoose an option";
      cin>>menu_choose;
      switch(menu_choose)
      {
      case 1:
          system("cls");
          display_files("signintea.txt","maiin/");
          Sign_in("maiin/teachermail.txt","maiin/teacherpasswrd.txt");
          system("cls");
          tt:
              system("cls");
          display_files("teacher.txt","maiin/");
           //cout<<"\n\t\t\tchoose an option";
          cin>>tea_in_choose;
          switch(tea_in_choose)
          {
          case 1:
              show_teacher_dir(gg);
              _getch();
              goto tt;
            break;
          case 2:
              Edit_teacher(gg);
              _getch();
              goto tt;
            break;
          case 3://show all students
              system("cls");
              show_all_Students();
              _getch();
                goto tt;
          case 4:
            cout<<"\nlogout..";cout<<"\a";
            Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";
            Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";
            cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);
            cout<<".";Sleep(500);cout<<"\a";cout<<".";Sleep(500);cout<<".";Sleep(500);cout<<"\a";cout<<".";
            system("cls");
            gg="";
            goto main;
          }
          _getch();
        break;
      case 2://teacher signup
          add_teacher();
          cout<<"\nSIGN UP SUCESSFULLY AS A TEACHER";
          getchar();
        break;
      }}while(menu_choose!=3);
      break;
      case 1://as a admin
      do{
         Sign_in("maiin/adminemail.txt","maiin/adminpasswrd.txt");
    aa:
        system("cls");
     display_files("admin.txt","maiin/");
         cin>>menu_choose;
     switch(menu_choose)
      {
      case 1://show students
           system("cls");
            show_all_Students();
            _getch();
            goto aa;
      case 2://show teachers
         system("cls");
            show_all_teachers();
            _getch();
            goto aa;
      }}while(menu_choose != 3);
  }}while(choose != 4);
  system("pause");
  _getch();
  system("cls");
  return 0;

}
