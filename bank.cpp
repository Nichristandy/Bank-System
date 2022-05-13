//bank atm
// Nama : Nicholas Christandy Onggosusilo
// NIM : 2440005132

#include <stdio.h>
#include <stdlib.h>

// declare struct
struct data
{
	char name[101];
	long long int cash;
} x;

void menu();

//setor dana
void setor()
{
	int saldo;
	printf("Nama: ");
	scanf("%[^\n]", &x.name);
	getchar();
	printf("jumlah yang akan disetor:");
	scanf("%d", &saldo);
	x.cash += saldo;
	printf("total saldo: %d\n",x.cash);
	getchar();
	getchar();
	menu();
}
//tarik dana
void tarik()
{
	int saldo;
	printf("jumlah yang akan ditarik:");
	scanf("%d", &saldo);
	if(x.cash >= saldo)
	{
		x.cash -= saldo;
	}
	else{
		printf("Saldo tidak cukup\n");
		tarik();
	}
	
	printf("total saldo: %d", x.cash);
	getchar();
	getchar();
	menu();
}
//exit
void exit()
{
	FILE *fp = fopen("bank.csv", "w");
	fprintf(fp,"%s,%d\n",x.name,x.cash);
	printf("Nama: %s\n", x.name);
	printf("sisa saldo: %d\n", x.cash);
	fclose(fp);
}
//menu
void menu()
{
	system("CLS");
	int task;
	printf("--------------------------------------------\n");
	printf("-                  WELCOME                 -\n");
	printf("- 1.Setor Dana                             -\n");
	printf("- 2.Tarik Dana                             -\n");
	printf("- 3.Exit                                   -\n");
	printf("--------------------------------------------\n");
	printf(">>");
	scanf("%d", &task);
	getchar();
	system("CLS");
	switch(task){
		case 1:
		setor();
		break;
		
		case 2:
		tarik();
		break;
		
		case 3:
		exit();
		break;	
	}
}



//main 
int main()
{
	FILE *fptr= fopen("bank.csv", "r");
	//cek file ada ato tidak
	if(!fptr){
		return 1;
	}
	// keluarin menu 
	menu();
	return 0;
}



