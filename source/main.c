#include <stdio.h>

#include <stdlib.h>
#include<time.h>


#include <conio.h>

#include <windows.h>



int x, y; // 飛機位置
int chose = 5;
int bullet_x, bullet_y; // 子彈位置

int enemy_x, enemy_y; // 敵機位置

int high, width; // 遊戲畫面尺寸
int n = 20;
int score; // 得分

//--------------------------------------------------------網路找的
void gotoxy(int x, int y) //光標移動到(x,y)位置

{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos;

	pos.X = x;

	pos.Y = y;

	SetConsoleCursorPosition(handle, pos);

}

void HideCursor() // 用於隱藏光標

{

	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}
//-----------------------------------------------------------------------------網路找的

void startup() // 數據初始化

{
	srand(time(NULL));
	high = 20;

	width = 30;

	x = 15;

	y = 15;

	bullet_y = y;

	bullet_x = -2;

	enemy_x = rand()%20;

	enemy_y = 0;

	score = 0;

	HideCursor(); // 隱藏光標???????????????????????

}

void show() // 顯示畫面

{

	gotoxy(0, 0); // 光標移動到原點位置，清屏。????????????????

	int i, j;

	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++)
		{
			if ((i == y) && (j == x))
				printf("^"); // 輸出飛機
			else if ((i == enemy_y) && (j == enemy_x))
				printf("O"); // 輸出敵機
			else if ((i == bullet_y) && (j == bullet_x))
				printf("|"); // 輸出子彈
			else
				printf(" "); // 輸出空格
		}
		printf("\n");
	}

	printf("得分：%d\n", score);

}

void genaral() 

{
	
	if (bullet_y > -1)
		bullet_y--;
	
	if ((bullet_x == enemy_x) && (bullet_y == enemy_y)) // 子彈擊中敵機
	{
		score++; // 分數加1
		enemy_y = -1; // 產生新的飛機
		enemy_x = rand() % width;
		bullet_y = -2; // 子彈無效

	}

	if (enemy_y > high) // 敵機跑出顯示螢幕
	{
		enemy_y = -1; // 產生新的飛機
		enemy_x = rand() % width;
	}

	// 用來控制敵機向下移動的速度。
	
	
		static int speed =0;
		if (speed < n)
			speed++;
		if (speed == n)
		{
			enemy_y++;
			speed = 0;

		}
}

void move() 
{
	char input;

	if (_kbhit()) // 判斷是否有輸入
	{
		input = _getch();
		if (input == 'j')
		{
			score++; // 分數加1
			enemy_y = -1; // 產生新的飛機
			enemy_x = rand() % 26;
			bullet_y = -2; // 子彈無效

		}
		if ( x <width ) {
			if (input == 'a')
				x--;
			if (input == 'd')
				x++;
		}
		else x = width-1;
		if (y < high) {
			if (input == 'w')
				y--;
			if (input == 's')
				y++;
		}
		else y = high-1;
		if (x <= 0)x = 0;
		if (y <= 0)y = 0;
		if (input == ' ') // 發射子彈
		{
			bullet_y = y - 1; // 發射子彈的初始位置在飛機的正上方
			bullet_x = x;
		}
	}
}

int main()
{
	
			
			while (chose != 0) {
				system("cls");
				printf("按1開始遊戲 按0結束遊戲");
				scanf_s("%d", &chose);
				srand(time(NULL));
				startup(); // 數據初始化
				switch (chose) {
				case 1:
					while (1) // 遊戲循環執行
					{
						show();// 顯示畫面
						n = 5 + rand() % 10;
						genaral();
						move();

						if ((x == enemy_x) && (y == enemy_y))break;// 飛機撞到敵機
						if (enemy_y == 20)break;// 敵機撞到底部
						
					}
					system("cls");
					printf("\n\n\nGAME OVER\n\n\n\n");
					system("pause");
				case 0:
					break;
				}
				
			}
		system("pause");
		return 0;
	}
