#include "function_file.cpp"

using namespace std;

int main()
{
    srand(time(NULL));

    vector <Account> bankAccounts;
    int input = 0;
    int *n = &input;

    do{
        menu(n);

        switch(input){
            case 1:{
                makeAccount(bankAccounts);
                sortAccounts(bankAccounts);
                break;
            }
            case 2:{
                printAllAccounts(bankAccounts);
                break;
            }
            case 3:{
                int accountNum;
                double deposit;

                cout << "Enter account number for deposit: ";
                cin >> accountNum;
                validInput(&accountNum);
                cout << "\nEnter amount to be deposited: ";
                cin >> deposit;
                validInput(&deposit);

                depositAccount(bankAccounts, accountNum, deposit);
                break;
            }
            case 4:{
                int accountNum2;
                double withdraw;

                cout << "Enter account number for withdrawel: ";
                cin >> accountNum2;
                validInput(&accountNum2);
                cout << "\nEnter amount to be withdrawn: ";
                cin >> withdraw;
                validInput(&withdraw);

                withdrawAccount(bankAccounts, accountNum2, withdraw);
                break;
            }
            case 5:{
                int accountNum3;

                cout<< "Enter account number to print: ";
                cin >> accountNum3;
                validInput(&accountNum3);

                printAccount(bankAccounts, accountNum3);
                break;
            }
            case 6:{
                int accountNum4;

                cout<< "Enter account number to be deleted: ";
                cin >> accountNum4;
                validInput(&accountNum4);

                deleteAccount(bankAccounts, accountNum4);
                break;
            }
        }
    }while(input<7);




}
