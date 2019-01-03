#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
int main(){
	char suit[4]={'H','D','C','S'};										//花色 
	char face[13]={'A','2','3','4','5','6','7','8','9','0','J','Q','K'};//牌面 
	int deck[4][13]={0};												//每張牌被抽到的次數 
	int x,y,z,o,p,l=2,sum=0,j=0,r,s=0,q=0,sum1=0,t=0,m=2;
	char d[5]={'\0','\0','\0','\0','\0'};								//花色陣列 
	char f[5]={'\0','\0','\0','\0','\0'};								//點數陣列 
	int c[]={1,2,3,4,5,6,7,8,9,10,10,10,10};							//每張牌的點數值 
	char e[5]={'\0','\0','\0','\0','\0'};								//莊家花色陣列 
	char g[5]={'\0','\0','\0','\0','\0'};								//莊家點數陣列 
	int row;
	int column;
	int card,card1;
	srand(time(NULL));
	
//---------------玩家------------------- 
	for(card=1;card<=2;card++){       //做抽牌的動作，先抽兩張當手牌 
		do{
			row=rand()%4;
			column=rand()%13;
			d[card-1]=suit[row]; 
			f[card-1]=face[column];
			sum+=c[column];
		}while(deck[row][column]!=0);
		deck[row][column]=card; 
	}
	for(card1=1;card1<=2;card1++){    //莊家做抽牌的動作，先抽兩張當手牌   
			do{
				row=rand()%4;
				column=rand()%13;
				e[card1-1]=suit[row]; 
				g[card1-1]=face[column];
				sum1+=c[column];
			}while(deck[row][column]!=0);
			deck[row][column]=card1; 
	}
	for(int i=0;i<5;i++){             //莊家如果起手有A則自動以11點做計算 
			if(g[i]=='A'&&i>=t){       
				if(sum1<=11)
					sum1+=10;
					t=i+1;
			}
	}
	printf("-----------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------\n");
	printf("------------------------ＢＬＡＣＫ　ＪＡＣＫ---------------------------\n");
	printf("-----------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------\n");
	printf("玩家手牌: ");
	for(int i=0;i<5;i++){            		//印出你現有的牌 
		switch(d[i]){
			case'D':printf("菱形");
				break;
			case'S':printf("黑桃");
				break;
			case'H':printf("紅心");
				break;
			case'C':printf("梅花");
				break;
		}
		if(f[i]=='0')                
			printf("10 ");
		else
			printf("%c ",f[i]);
		if(f[i]=='A'&&i>=q){       			//如果抽到A做counter +1的動作，要直到再次抽到A才會再 +1 
			s=i+1;
			q=i;
		}
	}
	printf("\t\t莊家手牌(有張暗牌):");		//印出莊家的明牌 
	for(int i=0;i<1;i++){          
			switch(e[i]){
			case'D':printf("菱形");
				break;
			case'S':printf("黑桃");
				break;
			case'H':printf("紅心");
				break;
			case'C':printf("梅花");
				break;
			}
			if(g[i]=='0')
				printf("10 ");
			else
				printf("%c ",g[i]);
	}
	
		if(s>q){
			q++;                  			 //因為執行過一次判斷所以 +1 
			printf("\n決定A是要1點還是11點 :");
			scanf("%d",&r);
			if(r==11){
				sum+=10;
			}
			if(r==1){
				sum+=0;
			}
		}
	printf("\n點數和 %d點\n",sum);			  //每次都會做牌面總值計算 
	printf("是否要牌 (0)不要(1)要:");
	while(1){
		scanf("%d",&x);						  //偵測是否要牌 
		if(x==1){                      		  //如果要牌則再抽一次 
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
			if(l>=5){                 		  //判斷手牌多於五張則跳出while迴圈 
				break;
			}
			l++;                     		  //如沒跳出迴圈，有執行抽牌動作的話，手牌數+1 
		}
		if(x==0) 
			break;                  		  //不要牌則跳出while迴圈 
		printf("玩家手牌: ");
		for(int i=0;i<5;i++){          		  //印出現有手牌 
			switch(d[i]){
			case'D':printf("菱形");
				break;
			case'S':printf("黑桃");
				break;
			case'H':printf("紅心");
				break;
			case'C':printf("梅花");
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
		printf("\t\t莊家手牌(有張暗牌):");	  //印出莊家的明牌
		for(int i=0;i<1;i++){          
				switch(e[i]){
				case'D':printf("菱形");
					break;
				case'S':printf("黑桃");
					break;
				case'H':printf("紅心");
					break;
				case'C':printf("梅花");
					break;
				}
				if(g[i]=='0')
					printf("10 ");
				else
					printf("%c ",g[i]);
		}
		if(s>q){
			q++;
			printf("\n決定A是要1點還是11點 :");
			scanf("%d",&r);
			if(r==11){
				sum+=10;
			}
			if(r==1){
				sum+=0;
			}
		}
		printf("\n點數和 %d點\n",sum);
		if(sum>21){                             //總和大於21點跳出while迴圈 
				break;
			}
		printf("是否要牌 (0)不要(1)要 :");      //沒有大於21點則再次詢問是否要牌 
		
		
	}
	
//---------------莊家------------------
	while(sum1<21&&sum<21){
		if(sum1>=16){                           //如果莊家總點數大於21點跳出while迴圈 
			break;
		}
		if(sum1<16){							//莊家點數小於16點做抽牌的動作 
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
				if(g[i]=='A'&&i>=t){       		//如果偵測到A則判斷如果小於等於10則以11點做計算 
					if(sum1<=11)                
						sum1+=10;
					t=i+1;
				}
			}	
		}	
	}	
	printf("\n玩家的牌 : ");					//印出玩家的手牌
	for(int i=0;i<5;i++){           
			switch(d[i]){
			case'D':printf("菱形");
				break;
			case'S':printf("黑桃");
				break;
			case'H':printf("紅心");
				break;
			case'C':printf("梅花");
				break;
			}
			if(f[i]=='0')
				printf("10 ");
			else
				printf("%c ",f[i]);
	}		
	printf("\t\t莊家的牌 :");					//印出莊家的手牌
	for(int i=0;i<5;i++){          
			switch(e[i]){
			case'D':printf("菱形");
				break;
			case'S':printf("黑桃");
				break;
			case'H':printf("紅心");
				break;
			case'C':printf("梅花");
				break;
			}
			if(g[i]=='0')
				printf("10 ");
			else
				printf("%c ",g[i]);
	} 
//----------------勝負判斷部分------------------	
	if(sum<=21&&j==0&&l>=5){					 
		printf("\n個人點數 : %d\t莊家點數 : %d\n",sum,sum1);
		printf("\n恭喜你過五關 WIN\n\n");
	}
	else if(sum==21&&j==0){
		printf("\n個人點數 : %d\t莊家點數 : %d\n",sum,sum1);
		printf("\n恭喜21點 WIN\n\n");
	}
		
	else if(sum<21&&sum>sum1){
		printf("\n個人點數 : %d\t莊家點數 : %d\n",sum,sum1);
		printf("\n恭喜你贏得勝利 WIN\n\n");
	}	
	else if(sum<21&&sum1>21){
		printf("\n個人點數 : %d\t莊家點數 : %d\n",sum,sum1);
		printf("\n恭喜你贏得勝利 WIN\n\n");
	}
	else{ 
		printf("\n個人點數 : %d\t莊家點數 : %d\n",sum,sum1);
		printf("\n請再接再厲 LOSE\n\n");
		} 
	system("pause");
	return 0; 
}
