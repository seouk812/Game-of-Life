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
	int b[50][50] = {0};   // ������ ������ �������� (0�� ����, 1�� ��������, 2�� ������ ����)

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			int n = 0; //����ִ� ���� ��

			
			for (int k = -1; k <= 1; k++)   // �ֺ� 8���� ������ ���� ���� Ȯ��
			{
				for (int l = -1; l <= 1; l++)
				{
					if (  ( (i + k) < 0 || (j + l) < 0 ) || ( (i + k) >= 50 || (j + l) >= 50 ) ||  (k == 0 && l == 0)  )   // ������ �ε��� �Ǵ� ����� �ε����� ���ϰų� �ڱ� �ڽŰ� ���ϴ� ���� ���ϱ� ����
						continue;

					
					if (!strcmp(a[i + k][j + l].s, "��"))
					{
						n++;
					}
				}
			}
			
			// �ڽ��� ���� ���� ����
			if (!strcmp(a[i][j].s, "��"))
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
	//����
	for (int i = 0; i < 50; i++) 
	{
		for (int j = 0; j < 50; j++)
		{
			if (b[i][j] == 0)
				continue;
			else if (b[i][j] == 1)
				a[i][j].s = "��";
			else
				a[i][j].s = "��";
		}
	}
}

int main()
{

	for (int i = 0; i < 50; i++)      // �ʱ�ȭ
		for (int j = 0; j < 50; j++)
			a[i][j].s = "��";

	a[24][23].s = "��";
	a[24][24].s = "��";
	a[24][25].s = "��";
	a[25][23].s = "��";
	a[26][24].s = "��";


	while (1)
	{
		for (int i = 0; i < 50; i++)  // ���� ���
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