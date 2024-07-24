#include <bits/stdc++.h>
using namespace std; 
class user
{
private:
  string  name;
  string  password;
public:
double balance; 
  user(string n , string p)
  {
  name=n;
  password=p;
  balance=0;
 }
 bool check_username(string n)
{
  if(n==name){ return true;}
  else {  return false;}
}
bool check_password(string p)
{
  if(p==password){ return true;}
  else { return false;}
}
void savedata()
{
  ofstream out("MY data.txt");
  out<<"Balance: "<<balance<<endl; 

   out.close();
}
};
int main_menu(){
  int op;
  cout<<"_________MAIN MENU_________\n\n";
  cout<<"1. Balance\n2. Deposit\n3. Withdraw\n4. Exit\nEnter your choice: ";
  cin>>op;
  return op;
  
}
int main()
{
 string n,p;
 char response;
while (true){
 user u1= user("Abdullah","1234");
cout<<"*_*_*_*_WELCOME TO THE BANK_*_*_*_*\n\n";
  cout<<"Enter your Username: ";
  cin>>n;
  cout<<"Enter your Password: ";
  cin>>p;
  
  Start:
  if (u1.check_username (n) && u1.check_password(p))
  {
    int menu;
    menu=main_menu();

    switch(menu)
      {
        case 1:
        {
            cout<<"Your balance is: "<<u1.balance<<"PKR\t"<<endl;
            break;
          }
        case 2:
        {
          double deposit;
          cout<<"How much money you want to deposit? \n=";
          cin>>deposit;
          
          u1.balance+=deposit;
          break;
        }
        case 3:
        {
          double withdraw;
          cout<<"How much money you want to Withdraw? \n=";
          cin>>withdraw;
          if(withdraw > u1.balance) {
            cout << "You don't have sufficient balance!!\n";
          } else {
            u1.balance -= withdraw;
          } 
          break;
        }
        case 4:
        {
          cout<<"Thanks for visiting!! \n"<<endl;
          break;
        }
      }          
  }
  else {  
    cout<<"Incorrect Username and Password\n";
  } 
      cout<<"Would you like to continue? (y/n): ";
      cin>>response;
  // {system("cls") ;}---> you can use this to clear the screen before goto start
      if (response=='y') { system("cls"); goto Start;}
      else  { cout<<"Thanks for visiting!!\n\n";}             
  u1.savedata();
  system("cls");
}  
system("Pause");
  return 0;
}
  
  
  
  
  







 

