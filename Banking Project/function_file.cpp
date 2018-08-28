#include "header_file.h"
void validInput(double *b){
    while(*b<0 || cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.\nEnter positive number: ";
        cin >> *b;
        cout << "\n";
    }
}
void validInput(int *b){
    while(*b<0 || cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.\nEnter positive number: ";
        cin >> *b;
        cout << "\n";
    }
}

void menu(int *inputPtr){
    int select = 0;
    cout << "\nWelcome to MadeUp Banking. Select options below:" << endl;
    cout << "\t1. Make new account." << "\n\t2. Display all accounts."
            << "\n\t3. Deposit to an account." << "\n\t4. Withdraw from an account."
            << "\n\t5. Print account." << "\n\t6. Delete an account."
            << "\n\t7. Quit." << endl;
    cout << "Selection: ";
    cin >> select;
    cout << "\n";
    validInput(&select);
    *inputPtr = select;
}

void makeAccount(vector <Account>& bAccounts){

    int aNumber = rand()%9000+1000;
    double balance;
    string lName;
    string fName;

    cout << "Creating bank account number: " << aNumber << endl;

    cout << "Enter first Name: ";
    cin >> fName;
    cout << "Enter last Name: ";
    cin >> lName;
    cout << "Enter starting balance: ";
    cin >> balance;
    validInput(&balance);

    Account newAccount {
        aNumber,
        lName,
        fName,
        balance
    };

    bAccounts.push_back(newAccount);
}

void printAllAccounts(vector <Account>& b){
    for(unsigned int i=0; i<b.size(); i++){
        cout<< "Account Number: "<< b.at(i).accountNumber<< "\t Balance: " << b.at(i).accountBalance << endl;
        cout<< "Last Name: "<< b.at(i).lastName<< "\t First Name: " << b.at(i).firstName << "\n\n";
    }

}

void printAccount(vector <Account>& b, int accountNum){
    bool match = false;
    unsigned int found;
    for(unsigned int i=0; i<b.size(); i++){
        if(b.at(i).accountNumber == accountNum){
            match = true;
            found = i;
        }
    }

    if(match == true){
        cout<< "\nAccount Number: "<< b.at(found).accountNumber<< "\t Balance: " << b.at(found).accountBalance << endl;
        cout<< "Last Name: "<< b.at(found).lastName<< "\t First Name: " << b.at(found).firstName << "\n\n";
    }else
        cout << "This account does not exist in the bank.";


}

void depositAccount(vector <Account>& b, int accountNum, double depositAmount){
    bool match = false;
    unsigned int found;
    for(unsigned int i=0; i<b.size(); i++){
        if(b.at(i).accountNumber == accountNum){
            match = true;
            found = i;
            }
    }

    if(match == true){
        b.at(found).accountBalance += depositAmount;
    }else
        cout << "\nThis account does not exist in the bank.\n";
}

void withdrawAccount(vector <Account>& b, int accountNum, double withdrawAmount){
    bool match = false;
    unsigned int found;
    for(unsigned int i=0; i<b.size(); i++){
        if(b.at(i).accountNumber == accountNum){
            match = true;
            found = i;
        }
    }

    if(match == true){
        b.at(found).accountBalance -= withdrawAmount;
    }else
        cout << "\nThis account does not exist in the bank.\n";

}

void deleteAccount(vector <Account>& b, int accountNum){
    bool match = false;
    unsigned int found;
    for(unsigned int i=0; i<b.size(); i++){
        if(b.at(i).accountNumber == accountNum){
            match = true;
            found = i;
        }
    }
    if(match == true){
        b.erase(b.begin()+found);
    }else
        "\nThis account does not exist in the bank.\n";
}

void sortAccounts(vector <Account>& b){
    if(b.size()>1){
    for(unsigned int i = 0; i<b.size(); i++){
        for(unsigned int j = 0; j<b.size(); j++){
            if(b.at(i).accountNumber < b.at(j).accountNumber){
                Account temp = b.at(i);
                b.at(i) = b.at(j);
                b.at(j) = temp;
            }
        }
    }
    }
}



