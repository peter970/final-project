#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
int main(){
	char suit[4]={'H','D','C','S'};										//��� 
	char face[13]={'A','2','3','4','5','6','7','8','9','0','J','Q','K'};//�P�� 
	int deck[4][13]={0};												//�C�i�P�Q��쪺���� 
	int x,y,z,o,p,l=2,sum=0,j=0,r,s=0,q=0,sum1=0,t=0,m=2;
	char d[5]={'\0','\0','\0','\0','\0'};								//���}�C 
	char f[5]={'\0','\0','\0','\0','\0'};								//�I�ư}�C 
	int c[]={1,2,3,4,5,6,7,8,9,10,10,10,10};							//�C�i�P���I�ƭ� 
	char e[5]={'\0','\0','\0','\0','\0'};								//���a���}�C 
	char g[5]={'\0','\0','\0','\0','\0'};								//���a�I�ư}�C 
	int row;
	int column;
	int card,card1;
	srand(time(NULL));
	
//---------------���a------------------- 
	for(card=1;card<=2;card++){       //����P���ʧ@�A�����i���P 
		do{
			row=rand()%4;
			column=rand()%13;
			d[card-1]=suit[row]; 
			f[card-1]=face[column];
			sum+=c[column];
		}while(deck[row][column]!=0);
		deck[row][column]=card; 
	}
	for(card1=1;card1<=2;card1++){    //���a����P���ʧ@�A�����i���P   
			do{
				row=rand()%4;
				column=rand()%13;
				e[card1-1]=suit[row]; 
				g[card1-1]=face[column];
				sum1+=c[column];
			}while(deck[row][column]!=0);
			deck[row][column]=card1; 
	}
	for(int i=0;i<5;i++){             //���a�p�G�_�⦳A�h�۰ʥH11�I���p�� 
			if(g[i]=='A'&&i>=t){       
				if(sum1<=11)
					sum1+=10;
					t=i+1;
			}
	}
	printf("-----------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------\n");
	printf("------------------------�ТڢϢѢ١@�آϢѢ�---------------------------\n");
	printf("-----------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------\n");
	printf("���a��P: ");
	for(int i=0;i<5;i++){            		//�L�X�A�{�����P 
		switch(d[i]){
			case'D':printf("�٧�");
				break;
			case'S':printf("�®�");
				break;
			case'H':printf("����");
				break;
			case'C':printf("����");
				break;
		}
		if(f[i]=='0')                
			printf("10 ");
		else
			printf("%c ",f[i]);
		if(f[i]=='A'&&i>=q){       			//�p�G���A��counter +1���ʧ@�A�n����A�����A�~�|�A +1 
			s=i+1;
			q=i;
		}
	}
	printf("\t\t���a��P(���i�t�P):");		//�L�X���a�����P 
	for(int i=0;i<1;i++){          
			switch(e[i]){
			case'D':printf("�٧�");
				break;
			case'S':printf("�®�");
				break;
			case'H':printf("����");
				break;
			case'C':printf("����");
				break;
			}
			if(g[i]=='0')
				printf("10 ");
			else
				printf("%c ",g[i]);
	}
	
		if(s>q){
			q++;                  			 //�]������L�@���P�_�ҥH +1 
			printf("\n�M�wA�O�n1�I�٬O11�I :");
			scanf("%d",&r);
			if(r==11){
				sum+=10;
			}
			if(r==1){
				sum+=0;
			}
		}
	printf("\n�I�ƩM %d�I\n",sum);			  //�C�����|���P���`�ȭp�� 
	printf("�O�_�n�P (0)���n(1)�n:");
	while(1){
		scanf("%d",&x);						  //�����O�_�n�P 
		if(x==1){                      		  //�p�G�n�P�h�A��@�� 
			for(int i=0;i<1;i++){
				do{
				row=rand()%4;
				column=rand()%13;
				d[l]=suit[row];
				f[l]=face[column];
				sum+=c[column];
				}while(deck[row][column]!=0);
				deck[row][column]=card;
			}
			if(l>=5){                 		  //�P�_��P�h�󤭱i�h���Xwhile�j�� 
				break;
			}
			l++;                     		  //�p�S���X�j��A�������P�ʧ@���ܡA��P��+1 
		}
		if(x==0) 
			break;                  		  //���n�P�h���Xwhile�j�� 
		printf("���a��P: ");
		for(int i=0;i<5;i++){          		  //�L�X�{����P 
			switch(d[i]){
			case'D':printf("�٧�");
				break;
			case'S':printf("�®�");
				break;
			case'H':printf("����");
				break;
			case'C':printf("����");
				break;
			}
			if(f[i]=='0')
				printf("10 ");
			else
				printf("%c ",f[i]);
			if(f[i]=='A'&&i>=q){
				s=i+1;
				q=i;
			}
		}
		printf("\t\t���a��P(���i�t�P):");	  //�L�X���a�����P
		for(int i=0;i<1;i++){          
				switch(e[i]){
				case'D':printf("�٧�");
					break;
				case'S':printf("�®�");
					break;
				case'H':printf("����");
					break;
				case'C':printf("����");
					break;
				}
				if(g[i]=='0')
					printf("10 ");
				else
					printf("%c ",g[i]);
		}
		if(s>q){
			q++;
			printf("\n�M�wA�O�n1�I�٬O11�I :");
			scanf("%d",&r);
			if(r==11){
				sum+=10;
			}
			if(r==1){
				sum+=0;
			}
		}
		printf("\n�I�ƩM %d�I\n",sum);
		if(sum>21){                             //�`�M�j��21�I���Xwhile�j�� 
				break;
			}
		printf("�O�_�n�P (0)���n(1)�n :");      //�S���j��21�I�h�A���߰ݬO�_�n�P 
		
		
	}
	
//---------------���a------------------
	while(sum1<21&&sum<21){
		if(sum1>=16){                           //�p�G���a�`�I�Ƥj��21�I���Xwhile�j�� 
			break;
		}
		if(sum1<16){							//���a�I�Ƥp��16�I����P���ʧ@ 
			for(int i=0;i<1;i++){
				do{
				row=rand()%4;
				column=rand()%13;
				e[m]=suit[row];
				g[m]=face[column];
				sum1+=c[column];
				}while(deck[row][column]!=0);
				deck[row][column]=card1;
			}
			m++;
			for(int i=0;i<5;i++){               
				if(g[i]=='A'&&i>=t){       		//�p�G������A�h�P�_�p�G�p�󵥩�10�h�H11�I���p�� 
					if(sum1<=11)                
						sum1+=10;
					t=i+1;
				}
			}	
		}	
	}	
	printf("\n���a���P : ");					//�L�X���a����P
	for(int i=0;i<5;i++){           
			switch(d[i]){
			case'D':printf("�٧�");
				break;
			case'S':printf("�®�");
				break;
			case'H':printf("����");
				break;
			case'C':printf("����");
				break;
			}
			if(f[i]=='0')
				printf("10 ");
			else
				printf("%c ",f[i]);
	}		
	printf("\t\t���a���P :");					//�L�X���a����P
	for(int i=0;i<5;i++){          
			switch(e[i]){
			case'D':printf("�٧�");
				break;
			case'S':printf("�®�");
				break;
			case'H':printf("����");
				break;
			case'C':printf("����");
				break;
			}
			if(g[i]=='0')
				printf("10 ");
			else
				printf("%c ",g[i]);
	} 
//----------------�ӭt�P�_����------------------	
	if(sum<=21&&j==0&&l>=5){					 
		printf("\n�ӤH�I�� : %d\t���a�I�� : %d\n",sum,sum1);
		printf("\n���ߧA�L���� WIN\n\n");
	}
	else if(sum==21&&j==0){
		printf("\n�ӤH�I�� : %d\t���a�I�� : %d\n",sum,sum1);
		printf("\n����21�I WIN\n\n");
	}
		
	else if(sum<21&&sum>sum1){
		printf("\n�ӤH�I�� : %d\t���a�I�� : %d\n",sum,sum1);
		printf("\n���ߧAĹ�o�ӧQ WIN\n\n");
	}	
	else if(sum<21&&sum1>21){
		printf("\n�ӤH�I�� : %d\t���a�I�� : %d\n",sum,sum1);
		printf("\n���ߧAĹ�o�ӧQ WIN\n\n");
	}
	else{ 
		printf("\n�ӤH�I�� : %d\t���a�I�� : %d\n",sum,sum1);
		printf("\n�ЦA���A�F LOSE\n\n");
		} 
	system("pause");
	return 0; 
}
