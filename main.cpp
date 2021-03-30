#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <cctype>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Account{

  private:
    double balance;
    int accountNum;
    string firstname;
    string lastname;

    int generateAccountNum(){
      int iSecret, iGuess;
      srand (time(NULL));
      iSecret = rand();
      return time(NULL) + iSecret;
    }


  public:
    Account(string firstname = "", string lastname = "")
    :firstname{firstname},lastname{lastname}{
        this->balance = 0;
        this->accountNum = abs(generateAccountNum());
        numAccounts++;
        cout<<"You name is "<<firstname+" "+lastname<<", and your balance is "<<"$"<<balance<<"."<<endl;
    }

    static int numAccounts;

    static int getNumAccounts(){
      return numAccounts;
    }
    double getBalance(){
      return balance;
    }
    double withdraw(double num){
      if(num > balance){
        cout<<"Error - account cannot have negative balance."<<endl;
        return balance;
      }else{
        
        balance = balance - num;
        return balance;
      }
    }
    int getAccountNum(){
      return accountNum;
    }
    //increments the account
    double deposit(double num = 0){
      balance = balance + num;
      return balance;
    }
};

int Account::numAccounts{0};



void accountActions(Account user){
  cout<<"-----------"<<endl<<endl;
  cout<<"What would you like to do? (pick an option)"<<endl;
  cout<<" (A) Withdraw"<<endl;
  cout<<" (B) Deposit"<<endl;
  cout<<" (C) View Balance"<<endl;
  cout<<" (D) Exit"<<endl;

  char userInput;
  cin>>userInput;

   switch(userInput) {
     //withdraw
      case 'A' :
         cout << "How much would you like to withdraw?" << endl; 
         int withdrawAmt;
         cin>>withdrawAmt;
         user.withdraw(withdrawAmt);
         accountActions(user);
         break;
      case 'B' :
         cout << "How much would you like to deposit?" << endl; 
         int depositAmt;
         cin>>depositAmt;
         user.deposit(depositAmt);
         accountActions(user);
         break;
      case 'C' :
         cout << "Your balance is $"<<user.getBalance()<<"."<< endl;
         accountActions(user);
         break;
      case 'D' :
         cout << "Thanks for doing business!" << endl;
         exit(0);
         break;
      default :
         cout << "Invalid input. Try a capital letter between A and D." << endl;
         accountActions(user);
   }
}

void initAccount(){
  cout<<"Welcome. To create an account, please type your first name."<<endl;
  string firstname, lastname;
  cin>>firstname;
  cout<<"Now enter your last name."<<endl;
  cin>>lastname;
  Account user(firstname, lastname);
  cout<<"Welcome to your new account, "+firstname+" "+lastname+"."<<endl;
  cout<<"Your balance is $"<<user.getBalance()<<", and your account number is "<<user.getAccountNum()<<"."<<endl<<endl;
  
  accountActions(user);
}

int main() {
  initAccount();
}