#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct
{
	char *s; // Square
}Square;

Square a[50][50];

void Calc(Square a[50][50])
{  //50*50 = 2500
	int b[50][50] = {0};   // 적용할 세포의 생존여부 (0은 없음, 1은 죽은세포, 2는 생존한 세포)

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			int n = 0; //살아있는 세포 수

			
			for (int k = -1; k <= 1; k++)   // 주변 8개의 세포의 생존 여부 확인
			{
				for (int l = -1; l <= 1; l++)
				{
					if (  ( (i + k) < 0 || (j + l) < 0 ) || ( (i + k) >= 50 || (j + l) >= 50 ) ||  (k == 0 && l == 0)  )   // 음수의 인덱스 또는 벗어나는 인덱스와 비교하거나 자기 자신과 비교하는 것을 피하기 위해
						continue;

					
					if (!strcmp(a[i + k][j + l].s, "■"))
					{
						n++;
					}
				}
			}
			
			// 자신의 생존 여부 결정
			if (!strcmp(a[i][j].s, "□"))
			{
				if (n == 3)
					b[i][j] = 2;
			}
			else
			{
				if (!(n==2 || n==3))
					b[i][j] = 1;
			}
		}
	}
	//적용
	for (int i = 0; i < 50; i++) 
	{
		for (int j = 0; j < 50; j++)
		{
			if (b[i][j] == 0)
				continue;
			else if (b[i][j] == 1)
				a[i][j].s = "□";
			else
				a[i][j].s = "■";
		}
	}
}

int main()
{

	for (int i = 0; i < 50; i++)      // 초기화
		for (int j = 0; j < 50; j++)
			a[i][j].s = "□";

	a[24][23].s = "■";
	a[24][24].s = "■";
	a[24][25].s = "■";
	a[25][23].s = "■";
	a[26][24].s = "■";


	while (1)
	{
		for (int i = 0; i < 50; i++)  // 원소 찍기
		{
			for (int j = 0; j < 50; j++)
				printf("%s", a[i][j].s);
			printf("\n");
		}

		Calc(a);  // 

		Sleep(500);
		system("cls");
	}

	system("pause");
	return 0;
}