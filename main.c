#include "headers.h"

int main(){

	int proceed,i;
	system("cls");
	printf(" ------------WELCOME!-----------");
	printf("\n| [1] Account Holder Login.	|");
	printf("\n| [2] Create Account.		|");
	printf("\n| [3] View All Transactions.	|");
	printf("\n| [4] Quit.			|");
	printf("\n -------------------------------");

	do{
		printf("\n\n Enter Choice: ");
		scanf("%d",&proceed);
		fflush(stdin);	
				
		switch(proceed){
			case 1:{
				ValidateAcc();
				break;
			} 
			case 2:{	
				CreateNewAccount();
				i++;
				break;
			} 
			case 3:{
				ViewAllAccounts();
				break;
			} 
			case 4:{

				exit;
				break;
			} 
          default: 
                   printf("\nPlease enter one of the options: ");
                    printf("(1/2/3/4) to continue \n ");
                    system("pause");
                    break;
		}			
	}while(proceed!=4);
	return 0;	
}

