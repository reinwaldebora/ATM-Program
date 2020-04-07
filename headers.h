#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <time.h>

typedef struct{
	char fullname[50];
	char pin[50];
	float balance;
	int account_number;
}Bank;

int ValidateAcc();
void AccountHolder(Bank Info,int i);

void Deposit(Bank Info,int i);
void Withdrawal(Bank Info,int i);
void CheckBalance(Bank Info);

void CreateNewAccount();
void MainMenu();
void InitialDeposit();

void ViewAllAccounts(void);

