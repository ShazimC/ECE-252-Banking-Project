#ifndef HEADER_FILE_H_INCLUDED
#define HEADER_FILE_H_INCLUDED
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <typeinfo>
#include <limits>

using namespace std;

struct Account{

    int accountNumber;
    string lastName;
    string firstName;
    double accountBalance;

};
template <typename Account>

void menu(int*);

void makeAccount();

void printAccount();

void printAllAccounts();

void depositAccount();

void withdrawAccount();

void sortAccounts();

void deleteAccount();


#endif // HEADER_FILE_H_INCLUDED
