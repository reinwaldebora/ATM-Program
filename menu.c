#include "headers.h"

int ValidateAcc(){
	Bank Info;
	int temp_acc,temp_pin,secret,found,i=0;
	FILE *fp;	
	system("cls");
	fp=fopen("account_info.dat","rb");

	printf("\nPlease enter your account number: ");
	scanf("%d",&temp_acc);
	fseek(fp,0,SEEK_SET);
	while(!feof(fp))
	{
		fread(&Info,sizeof(Info),1,fp);
		if(temp_acc==Info.account_number)
		{
			found=1;
			break;
		}
		i++;
	}
	if(found==1)
	{
		secret=atoi(Info.pin);	
		printf("\nInput the 4-digit PIN: ");
		if(scanf("%d",&temp_pin)==0)
		{
			printf("\nInvalid PIN!!\n");
			fflush(stdin);
 			system("pause");
 			main();
		}
		if(temp_pin>9999)
		{
			printf("\nEnter a 4-Digit PIN only.\n");
			fflush(stdin);
			system("pause");
 			main();
		}
		if(secret!=temp_pin)
		{
			printf("Wrong PIN!\n");
			fflush(stdin);
			system("pause");
			main();
 
		}

		printf("\n\nSuccessfully Logged In!");
		getch();

		fclose(fp);
		AccountHolder(Info,i);
	}
	else
	{		
		printf("\nInvalid Account Number!");
		fflush(stdin);
	}
	fclose(fp);
	getch();
	system("cls");				

}

void CreateNewAccount(){
	system("cls");
	int secret,i;
	Bank Info;
	printf("\n\tCreate New Account.\n");

	FILE *fp;	
	fp=fopen("account_info.dat","ab");
	
	srand((unsigned)time(NULL));
	Info.account_number=abs(rand()*rand())%999999;

	printf("Your account number is %d.", Info.account_number);
	printf("\n\nEnter Full Name: ");
	gets(Info.fullname);
	    for(i=0;i<strlen(Info.fullname);i++)
		{
			if((!isalpha(Info.fullname[i]))&&Info.fullname[i]!=' ')
			{
				printf("Invalid Input!\n");
				system("pause");
 				main();
			}
		}
	

	do{
	system("cls");
	printf("\n\tCreate New Account.\n");
	printf("Your account number is %d.", Info.account_number);
	printf("\n\nInput security PIN(Must contain 4 digits.): ");
	gets(Info.pin);
	secret=atoi(Info.pin);
	}while(secret<1000||secret>9999);
	
	system("cls");
	printf("\n\tCreate New Account.\n");
	printf("Your account number is %d.", Info.account_number);
	printf("\n\nEnter Initial Deposit: ");
	if(scanf("%f",&Info.balance)==0){
		printf("\nInvalid Input!\n");
		system("pause");
 		main();
	}
	if(Info.balance<500)
	{
		printf("Initial deposit must be a minimum of 500Php.\n");
		system("pause");
 		main();

	}
	
	system("cls");
	printf("\n\tAccount Information.\n");
	printf("\n-------------------------------------------------");
	printf("\n| Account Number|   Full Name\t|   Balance\t|");
	printf("\n-------------------------------------------------");
	printf("\n| %6d\t| %s\t|   %.2f\t|",Info.account_number,Info.fullname,Info.balance);
	printf("\n-------------------------------------------------\n");
	system("pause");
	fwrite(&Info,sizeof(Info),1,fp);
	fclose(fp);
	main();

}


void ViewAllAccounts(void){
	Bank Info;
	printf("\n\n\tAll Accounts.\n");
	FILE *fp;	
	system("cls");

	fp=fopen("account_info.dat","rb");
	if(fopen("account_info.dat","rb")==NULL)
	{		
		printf("Cannot Open File");
		getch();
		return;
	}
	fseek(fp,0,SEEK_SET);
	fread(&Info,sizeof(Info),1,fp);

	printf("\n-------------------------------------------------");
	printf("\n| Account Number|   Full Name\t|   Balance\t|");
	printf("\n-------------------------------------------------");
	while(!feof(fp))
	{
		printf("\n| %6d\t| %s\t|   %.2f\t|",Info.account_number,Info.fullname,Info.balance);
		fread(&Info,sizeof(Info),1,fp);	
	}
	printf("\n-------------------------------------------------\n\n");
	fclose(fp);
	system("pause");
	main();

}
