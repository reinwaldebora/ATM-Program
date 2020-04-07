#include "headers.h"

void MainMenu(void){
	system("cls");
	printf("-------------------------------");
	printf("\n| [1] Deposit.\t\t\t|");
	printf("\n| [2] Withdraw.\t\t\t|");
	printf("\n| [3] Check account information.|");
	printf("\n| [4] Back to main menu.\t|");
	printf("\n------------------------------");
}


void AccountHolder(Bank Info,int i){
	int choice;
	do{
		MainMenu();
		printf("\n\n Enter Choice: ");
		scanf("%d",&choice);
		fflush(stdin);			
		switch(choice){
			case 1:{

				Deposit(Info,i);
				break;
			} 
			case 2:{
				Withdrawal(Info,i);
				break;
			}
			case 3:{ 	
				CheckBalance(Info);
				break;
			} 
			case 4:{
			system("cls");
			printf("\nSuccessfully Logged Out!");
        	getch();
        	system("cls");
			main();
			break;
			} 
          default : 
                    printf("\nPlease enter one of the options: ");
                    printf("(1/2/3/4) to continue \n ");
                    system("pause");
                    break;
		}			
	}while(choice!=4);
	getch();
	system("cls");

}



void Deposit(Bank Info,int i){

	float deposit;
	FILE *fp;	

	system("cls");
	fp = fopen("account_info.dat", "r+b");

	printf("Enter amount to deposit: ");

	if (scanf("%f",&deposit)==0)
	{
		printf("Invalid Input!\n");
		system("pause");
		system("cls");
		fflush(stdin);

	}
	fseek(fp,i*sizeof(Info),0);
	Info.balance+=deposit;
	fwrite(&Info,sizeof(Info),1,fp);
	
	printf("\nNew account balance : %.2fphp\n",Info.balance);
	system("pause");
	fclose(fp);
    
    
}


void Withdrawal(Bank Info,int i){

	float withdraw;
	FILE *fp;	


	system("cls");
	fp = fopen("account_info.dat", "r+b");

	printf("Enter amount to withdraw: ");
	if (scanf("%f",&withdraw)==0)
	{
		printf("Invalid Input!\n");
		system("pause");
		fflush(stdin);

	}
	
	if(withdraw>Info.balance)
	{
		printf("\nInsufficient funds.\n");
		system("pause");
		fflush(stdin);

	}
	
	fseek(fp,i*sizeof(Info),0);
	Info.balance-=withdraw;
	fwrite(&Info,sizeof(Info),1,fp);
	
	printf("\nNew account balance : %.2fphp\n",Info.balance);
	system("pause");
	fclose(fp);

}


void CheckBalance(Bank Info){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

	system("cls");
	printf("%s",asctime(tm));
	printf("\nYour current balance is %.2f.\n\n",Info.balance);
	system("pause");

    }
