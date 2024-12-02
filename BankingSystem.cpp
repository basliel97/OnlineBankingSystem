#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define bank_h
class Bank
{
private:
  string accountNumbers;
  struct BankAccount
  {
    string firstName;
    string lastName;
    string accountNumber;
    string address;
    string contact;
    char accountType;
    int balance;
  } person[300];

public:
  int total;
  Bank()
  {
    total = 0;
  }
  void createAccount();
  void modifyAccount();
  void showList();
  void search();
  void transaction();
  void remove();
  void openFile();
  void saveFile();
  void backToMenu();
};
void aboutSystem();
void Bank ::createAccount()
{
  char exit;
  do
  {
    system("cls");
    cout << setw(40) << right << "Create Account" << endl;
    cout << setfill('=') << setw(80) << "" << endl
         << setfill('=') << setw(80) << "" << setfill(' ') << endl;
    cout << "Enter First Name :";
    cin >> person[total].firstName;
    cout << "Enter Last Name :";
    cin >> person[total].lastName;
    do
    {
      cout << "Enter Account Number : ";
      cin >> person[total].accountNumber;
      try
      {
         if (person[total].accountNumber.length() != 14)
 throw "Account Number Must Be 14 Digits";
      }
      catch (const char *msg)
      {
         cout << msg << endl;
      }
    } while (person[total].accountNumber.length() != 14);
    cin.ignore();
    cout << "Enter Address :";
    getline(cin, person[total].address);
    do
    {
      cout << "Enter Contact :";
      cin >> person[total].contact;
      try
      {
         if (person[total].contact.length() != 10)
 throw "Account Number Must Be 10 Digits";
      }
      catch (const char *msg)
      {
         cout << msg << endl;
      }
    } while (person[total].contact.length() != 10);
    do
    {
      cout << "Enter Account Type (S = saving / C = current):";
      cin >> person[total].accountType;
      try
      {
         if (person[total].accountType != 'S' &&person[total].accountType != 'C')
 throw "Account Type Only Can Be S Or C (S = Saving & C = current)";
      }
      catch (const char *msg)
      {
         cout << msg << endl;
      }
    } while (person[total].accountType != 'S' && person[total].accountType != 'C');
    cout << "Enter An Initial Amount :";
    cin >> person[total].balance;
    if (person[total].accountType == 'S' && person[total].balance >= 1000)
    {
      total++;
      saveFile();
    }
    else cout << "Initial Balance For Saving Account Must Be 1000 And Above" << endl
 << "Opration Terminated " << endl;
    cout << "Enter 'S' to Goback to Main Menu \nPress Any other Button To Create More Accounts : ";
    cin >> exit;
  } while (exit != 'S');
}
void Bank::showList()
{
  char ch;
  system("cls");
  cout << setw(65) << "Existing Accounts " << endl;
  cout << setfill('=') << setw(120) << "" << endl
       << setfill('=') << setw(120) << "" << setfill(' ') << endl;
  cout << left << setw(15) << "First Name" << setw(16) << "Last Name" << setw(19) << "Account Number" << setw(17)
<< "Account Type" << setw(17) << "Phone Number" << setw(15) << "Address" << setw(15) << "Balance" << endl;
  cout << setfill('+') << setw(120) << "" << setfill(' ') << endl;
  cout << endl;
  for (int i = 0; i < total; i++)
  {
    cout << left << setw(15) << person[i].firstName << setw(16) << person[i].lastName
 << setw(19) << person[i].accountNumber << setw(17) << person[i].accountType << setw(17) << person[i].contact
 << setw(15) << person[i].address << setw(15) << person[i].balance;
    cout << endl;
    cout << setfill('-') << setw(120) << "" << setfill(' ') << " " << endl;
  }
  backToMenu();
}
void Bank::modifyAccount()
{
  cout << right << setw(40) << "Modify Account" << endl;
  cout << setfill('=') << setw(80) << "" << endl
       << setfill('=') << setw(80) << "" << setfill(' ') << endl;
  cout << "Enter Account Number : ";
  cin >> accountNumbers;
  for (int i = 0; i < total; i++)
  {
    if (accountNumbers == person[i].accountNumber)
    {
      cout << setw(40) << "The Previous Data" << endl;
      cout << "First Name : " << person[i].firstName
 << endl;
      cout << "Last Name: " << person[i].lastName
           << endl;
      cout << "Account Number: " << person[i].accountNumber
 << endl;
      cout << "Account Type : " << person[i].accountType
 << endl;
      cout << "Address : " << person[i].address
 << endl;
      cout << "Contact : " << person[i].contact
 << endl;
      cout << "Balance : " << person[i].balance
 << endl;
      cout << setw(40) << "Modify The Data" << endl;
      cout << "Enter First Name :";
      cin >> person[i].firstName;
      cout << "Enter Last Name : ";
      cin >> person[i].lastName;
      cout << "Enter Account Number:";
      cin >> person[i].accountNumber;
      cin.ignore();
      cout << "Enter Address :";
      getline(cin, person[i].address);
      cout << "Enter Phone Number :";
      cin >> person[i].contact;
      cout << "Enter Balance :";
      cin >> person[i].balance;
      backToMenu();
      saveFile();
      break;
    }
    if (i == total - 1)
    {
      cout << "No Such Record Found";
      backToMenu();
    }
  }
}
void Bank::search()
{
  system("cls");
  cout << setw(40) << "Search An Account" << endl;
  cout << setfill('=') << setw(80) << "" << endl
       << setfill('=') << setw(80) << "" << setfill(' ') << endl;
  cout << "Enter Account Number : ";
  cin >> accountNumbers;
  for (int i = 0; i < total; i++)

  {
    if (accountNumbers == person[i].accountNumber)

    {
      cout << setw(40) << "Account Holder Detail " << endl;
      cout << "First Name : " << person[i].firstName << endl;
      cout << "Last Name: " << person[i].lastName << endl;
      cout << "Account Number : " << person[i].accountNumber << endl;
      cout << "Account Type : " << person[i].accountType << endl;
      cout << "Address : " << person[i].address << endl;
      cout << "Contact : " << person[i].contact << endl;
      cout << "Balance : " << person[i].balance << endl;
       backToMenu();

      break;
    }
    if (i == total - 1)
    {
      cout << "No Such Record Found " << endl;
      backToMenu();
    }
  }
}
void Bank ::transaction()
{

  string recieverAccNo;
  int transferCash;
  char choice;
  int cash;
  cout << setw(40) << "Transactions " << endl;
  cout << setfill('=') << setw(80) << "" << endl
       << setfill('=') << setw(80) << "" << setfill(' ') << endl;
  cout << "Enter The Account Number To Make Transaction : ";
  cin >> accountNumbers;
  for (int i = 0; i < total; i++)

  {
    if (accountNumbers == person[i].accountNumber)

    {
       system("cls");
      cout << setw(40) << "Account Holders Detail" << endl;
      cout << "First Name : "<< person[i].firstName << endl;
      cout << "Last Name:" << person[i].lastName << endl;
      cout << "Address : "<< person[i].address << endl;
      cout << "Contact : "<< person[i].contact << endl;
      cout << "Balance : "<< person[i].balance << endl;
      cout << setw(40) << "Transaction Lists" << endl;
      cout << setfill('=') << setw(80) << "" << endl
           << setfill('=') << setw(80) << "" << setfill(' ') << endl;
      cout << "Press 1 To Deposit" << endl;
      cout << "Press 2 To Wirhdraw " << endl;
      cout << "press 3 To Transfer " << endl;
      cout << "Enter Your Choice : ";
      cin >> choice;
      switch (choice)
        {
        case '1':
          system("cls");
          cout << "How Much Cash You Want To Deposit :";
          cin >> cash;
          person[i].balance += cash;
          cout << "succesfuly Deposited!" << endl;
          cout << "Balance = " << person[i].balance;
          saveFile();
          backToMenu();

          break;
        case '2':
           system("cls");
          cout << "How Much Cash You Want To Withdraw :";
          cin >> cash;
          if (cash < person[i].balance)
  
            {
               person[i].balance -= cash;
               cout << "Success Fully Witdrawal!" << endl;
               cout << "Balance = " << person[i].balance;
               saveFile();
               backToMenu();

    
            }
          else
             cout << "The Customer Dont Have That Much Money" << endl;
          backToMenu();

          break;
        case '3':
          system("cls");
          cout << "Enter The Reciever Account Number : ";
          cin >> recieverAccNo;
          for (int j = 0; j < total; j++)
  
            {
               if (recieverAccNo == person[j].accountNumber)

              {
                cout << "Enter Amount Of Cash To Transfer : ";
                cin >> transferCash;
                 if (transferCash < person[i].balance)

                {
                  person[i].balance -= transferCash;
                  person[j].balance += transferCash;
                  cout << "Succesfuly Transfered!" << endl;
                  cout << person[i].firstName << "'s Balance= " << person[i].balance << endl;
                  cout << person[j].firstName << "'s Balance= " << person[j].balance << endl;
                  saveFile();
                  backToMenu();
                  
                }
                else cout << "The Customer Dont Have That Much Money" << endl;
                backToMenu();
                
              }
              if (j == total - 1)
              {
                cout << "No Such Record Found" << endl;
      backToMenu();
                
              }
    
            }

          break;
        default:
          cout << "Invalid input " << endl;
          backToMenu();
          break;

        }
      break;
    }
    if (i == total - 1)

    {
      cout << "No Such Record Found" << endl;
      backToMenu();
    }
  }
}

void Bank::remove()
{

  char choice;
  cout << right << setw(60) << "Delete Account" << endl;
  cout << setfill('=') << setw(80) << "" << endl
       << setfill('=') << setw(80) << "" << setfill(' ') << endl;

  cout << "Press 1 To Delete AnAccount\n";
  cout << "Press 2 to Delete All Accounts \n";
  cout << "Enter Your Choice : ";
  cin >> choice;
  switch (choice){
  case '1':
    cout << "Enter The Account Number : " << endl;
    cin >> accountNumbers;
    for (int i = 0; i < total; i++)
    {
      if (accountNumbers == person[i].accountNumber)
      {
        person[i].firstName = person[i + 1].firstName;
        person[i].lastName = person[i + 1].lastName;
        person[i].accountNumber = person[i + 1].accountNumber;
        person[i].address = person[i + 1].address;
        person[i].contact = person[i + 1].contact;
        person[i].accountType = person[i + 1].accountType;
        person[i].balance = person[i + 1].balance;
        --total;
        cout << "Account is Deleted succesfuly!" << endl;
        backToMenu();
        saveFile();
         break;
      }
      if (i == total - 1)
      {
        cout << "No Such Record Found" << endl;
        backToMenu();
      }
    }
    saveFile();
    break;
  case '2':
    total = 0;
    cout << "Total Record Is Deleted" << endl;
    backToMenu();
    break;
  default:
    cout << "Invalid Input" << endl;
    backToMenu();

    break;
  }
}

void Bank::openFile()
{
  ifstream account("AccountInfo.txt");
  if (account.is_open())
  {
    account >> total;
    for (int i = 0; i < total; i++)
    {
      account >> person[i].firstName >> person[i].lastName >> person[i].accountNumber >> person[i].accountType >> person[i].contact >> person[i].address >> person[i].balance;
    }
  }
  else
    cout << "file could not opened!" << endl;
}
void Bank::saveFile()
{
  ofstream account("AccountInfo.txt");
  if (account.is_open())
  {
    account << total << endl;
    for (int i = 0; i < total; i++)
    {
      account << person[i].firstName << " " << person[i].lastName
 << " " << person[i].accountNumber << " " << person[i].accountType << " " << person[i].contact
 << " " << person[i].address << " " << person[i].balance << endl;
    }
  }
  else
    cout << "file could not saved!" << endl;
}

void Bank ::backToMenu()
{
  char ch;
  cout << "press any Button TO go Back to Main Menu : ";
  cin >> ch;
}

void aboutSystem()
{
   char choice;
  system("cls");
  cout << setw(60) << " About The Bank \n";
  cout << setfill('=') << setw(120) << "" << endl
       << setfill('=') << setw(120) << "" << setfill(' ') << endl;

  cout << "This system is provided by WKU software engineering students. \n The system is for a bank teller to access customers account.\n";
  cout << setw(60) << "The Functionalities of the system are \n";
  cout << "creating Account:-you can create a bank account for a customer\n";
  cout << "an account has Name, AccountNumber, Account Type, Address, Phone number, Balance\n";
  cout << "Making Transactions:-you can transfer, deposit, and withdraw money to or from an account\n";
  cout << "Displaying Accounts:-you can show or display all account records\n";
  cout << "Search An Account:- you can search customer's Account using its account number\n";
  cout << "Modifying An Account:- you can update every information of a customer's account\n ";
  cout << "Deleting An Account:-you can delete specific account by searching it using account number or\n";
  cout << "you can delete all the records\n";
  cout << "press Any Key To Go Back To Login Page ...";
  cin >> choice;
}

int main()
{
  Bank bank;
  bank.openFile();
  char choice;
  string userName;
  string Password;
  do
  {
    system("cls");
    cout << setw(80) << "W E L C O M ET OY E G N AB A N KS Y S T E M " << endl;
    cout << setfill('=') << setw(120) << " " << setfill(' ') << endl;
    cout << setw(60) << "L O G I N P A G E " << endl;
    cout << setfill('+') << setw(120) << " " << setfill(' ') << endl;
    cout << "1. Log In\n";
    cout << "2. About System\n";
    cout << "3. Exit \n";
    cout << "Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case '1':
      do
      {
         system("cls");
        cout << setw(40) << "Teller's Page " << endl;
        cout << setfill('=') << setw(80) << "" << endl
             << setfill('=') << setw(80) << "" << setfill(' ') << endl;
        cout << "Enter User Name : ";
        cin.ignore();
        getline(cin, userName);
        cout << "Enter Password: ";
        getline(cin, Password);
        try     
        {
          if (userName != "teller" && Password != "teller123")

            throw "Incorrect User Name Or Password";

        }
        catch (const char *msg)
        {
          cout <<msg << endl;
          cout << "Press Any Key To Try Again ...";
          cin >> choice;

        }

      } while (userName != "teller" && Password != "teller123");

      system("cls");
      do
      {
        system("cls");
        cout << right << setw(40) << "Main Menu" << endl;
        cout << setfill('=') << setw(80) << "" << endl
             << setfill('=') << setw(80) << "" << setfill(' ');
        cout << endl
 << " 1. Create Bank Account";
        cout << endl
 << " 2. View Account List";
        cout << endl
 << " 3. Modify Bank Account";
        cout << endl
 << " 4. Search An Account";
        cout << endl
 << " 5. Make A Transaction";
        cout << endl
 << " 6. DeleteAn Account";
        cout << endl
 << " 7. Back To Login Page";
        cout << endl
 << "Enter your Choice : ";
        cin >> choice;
        switch (choice)

        {
        case '1':
          bank.createAccount();
          break;
        case '2':
          system("cls");
          if (bank.total == 0)
  
            {
              cout << "No Records Found" << endl;
              bank.backToMenu();
    
            }
           else bank.showList();
          break;
        case '3':
          system("cls");
          if (bank.total == 0)
  
            {
              cout << "No Records Found" << endl;
              bank.backToMenu();
            }
          else
            bank.modifyAccount();
          break;
        case '4':
          system("cls");
          if (bank.total == 0)
          {
            cout << "No Records Found" << endl;
            bank.backToMenu();
  
          }
           else  bank.search();
          break;
        case '5':
          system("cls");
          if (bank.total == 0)
  
            {
               cout << "No Records Found" << endl;
               bank.backToMenu();
    
            }
          else
             bank.transaction();
          break;
        case '6':
          system("cls");
          if (bank.total == 0)

          {
            cout << "No Record Found" << endl;
            bank.backToMenu();
          }
          else
            bank.remove();
          break;
        case '7':
          break;
        }

      } while (choice != '7');
      break;
    case '2':
      aboutSystem();
      break;
    case '3':
      exit(0);
    }
  } while (choice != 3);
  return 0;
}