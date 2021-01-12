#include <iostream>
#include <fstream>
using namespace std;
bool islogged(string username,string password)
{
      ifstream file;
      file.open("testing1.txt");
      string s1=username+" "+password;
      string s2; // hey i changed something
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
    file.open("testing1.txt",ios::out);
    string s=username+" "+password;
    file<<s;
    file.close();
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
                cout<<"Enter New User Name: ";
               username=username_input();
               cout<<"Enter New Password: ";
               password=password_input();
               save(username,password);
               main();
        }
        else
        {
           cout<<"Exit";
           break;
        }
    }
}