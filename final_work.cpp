#include <iostream>
#include <fstream>
using namespace std;
bool islogged(string username,string password)
{
      ifstream file;
      file.open("testing1.txt");
      string s1=username+" "+password;
      string s2;
      while(getline(file,s2))
      {
          if(s2==s1)
          {
              return true;
          }
      }
      return false;
}
void intro()
{
    cout<<"\n1. login \n2. Registration\n";
    cout<<"\n3. Exit\n";
}
string username_input()
{
    string username;
    cin>>username;
    return username;
}
string password_input()
{
    string password;
    cin>>password;
    return password;
}
void save(string username,string password)
{
    ofstream file;
    file.open("testing1.txt",ios::app);
    string s=username+" "+password;
    file<<s<<endl;
}
bool check_already_exist(string username)
{
    ifstream file;
    file.open("testing1.txt",ios::in);
    string s;
    while(getline(file,s))
    {
        int n=s.length();
        string u="";
    
       int i=0;
        for(;i<n && s[i]!=' ' ;++i)
        {
            u+=s[i];
        }
        //cout<<u<<" "<<i<<endl;
        if(u==username)
        return true;
    }
    return false;
}
int main()
{
    while(true)
    {
           intro();
        int select;cin>>select;
         string username,password;
         if(select == 1)
        {
            cout<<"\nEnter userame: ";
            username=username_input();
            cout<<"\nEnter password: ";
            password=password_input();
          bool check=islogged(username,password);
          if(check)
           {
              cout<<"\n Welcome to the  acoount"<<":"<<username;
              exit(0);
           }
           else
           {
               cout<<"! Wrong Login username and password"<<endl;
               main();
           }
        }
        else
        if(select ==2)
        {
                while(true)
              {
                cout<<"Enter New User Name: ";
                username=username_input();
                if(check_already_exist(username))
                 {
                    cout<<"\nUser Name already exist try again !!!: ";
                 }
                 else
                 {
                     break;
                 }
               }
               cout<<"Enter New Password: ";
               password=password_input();
               save(username,password);
               main();
        }
        else
        {
           cout<<"Exit";
           exit(0);
        }
    }
}