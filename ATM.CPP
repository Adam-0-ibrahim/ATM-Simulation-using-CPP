#include <iostream>
using namespace std;
class ATM
{
private:
  int balance;
  int password;

public:
  ATM(int bal, int pass)
  {
    balance = bal;   // to take the value of the private password
    password = pass; // to take the value of the private password
  }
  int getpassword()
  {
    return (password);
  }
  void getbalance()
  {
    cout << "\t\t\tyour balance is:" << balance << "." << endl;
  }
  void withdraw()
  {
    double amount;
  w:
    cout << "\t\t\tEnter the withdrawal amount." << endl;
    cout << "\t\t\t";
    cin >> amount;
    if (amount > balance)
      cout << "\t\t\tThe process could not be done. Insufficient funds." << endl;
    else if (amount != (int)amount || amount <= 0) // to ensure that the entered number is a whole number and greater than zero
    {
      cout << "\t\t\tInvalid amount, please enter a valid amount." << endl;
      goto w;
    }
    else
    {
      balance -= amount;
      cout << "\t\t\tProcess has been successfully done, Your balance now is: " << balance << "." << endl;
    }
  }
  void deposit()
  {
    double amount;
  d:
    cout << "\t\t\tEnter the deposit amount." << endl;
    cout << "\t\t\t";
    cin >> amount;
    if (amount != (int)amount || amount <= 0) // to ensure that the entered number is a whole number and greater than zero
    {
      cout << "\t\t\tplease enter a valid amount." << endl;
      goto d;
    }
    else
    {
      balance += amount;
      cout << "\t\t\tDeposit done successfully, Your balance now is: " << balance << "." << endl;
    }
  }
};
int main()
{
  ATM atm(1000, 0000); // 1000 is the balance , 0000 is the password
  char op;             // for the operation that will be done
  int pass;
  int attempts = 3; // to limit the attempts of inserting a wrong pin
n:
  cout << "\t\t\t=========================================" << endl;
  cout << "\t\t\tPlease enter your PIN." << endl;
  cout << "\t\t\t=========================================" << endl;
  cout << "\t\t\t";
  cin >> pass;
  if (pass == atm.getpassword())
  {
  m:
    cout << "\t\t\tplease select the operation." << endl;
    cout << "\t\t\t=========================================" << endl;
    cout << "\t\t\tEnter (W) to withdraw." << endl;
    cout << "\t\t\tEnter (D) to deposit." << endl;
    cout << "\t\t\tEnter (B) to display your balance." << endl;
    cout << "\t\t\t====================================" << endl;
    cout << "\t\t\t";
    cin >> op;
    switch (op)
    {
    case 'W':
    case 'w': // to accept both upper and lower-case
      atm.withdraw();
      break;
    case 'D':
    case 'd':
      atm.deposit();
      break;
    case 'B':
    case 'b':
      atm.getbalance();
      break;
    default:
      cout << "\t\t\tinvalid option." << endl;
    }
  o:
    cout << "\t\t\tDo you want to make another transaction? (Y/N)" << endl;
    char option;
    cout << "\t\t\t";
    cin >> option;
    if (option == 'Y' || option == 'y')
    {
      goto m;
    }
    else if (option == 'N' || option == 'n')
      return 0;
    else
    {
      cout << "\t\t\tPlease enter a valid letter." << endl;
      goto o;
    }
  }
  else // if the PIN is inserted wrong the user have 2 more attempts before the card gets blocked.
  {
    attempts--;
    if (attempts == 0) // to block the card when the user reaches the 3 attempts.
    {
      cout << "\t\t\tToo many incorrect PIN attempts, Card blocked.";
    }
    else
    {
      cout << "\t\t\tIncorrect pin you have more " << attempts << " attempts." << endl;
      goto n;
    }
  }
}