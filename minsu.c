#include <stdio.h>
#include <Windows.h>
#include "minsu.h"

int YUT = 0;
int r = -1;

int main(void)							//����ϴ� â�� ���� �߿�(x,y��ǥ�� ��鸳�ϴ�.)
{
	system("title ������ ����");
	all();
}

void all()
{
	int k = 1; //1,2 ��ǥ��
	int a;
	int x, y;
	x = 5, y = 3;
	gotoxy(x, y+15);
	Print_Game();

	x = 3, y = 3;
	YutNori();						//������ �� ���

	printf("\n");

	x = 73;
	y = 4;
	printf("\n\n\n");
	mal_pan(x, y);
	gotoxy(x + 5, y + 1);
	printf("�������");
	gotoxy(x + 5, y + 3);
	setcolor(11, 0);
	printf("=<%d��>=", k);					//1�� 2�� �����ư��� ǥ���ϴ� ��ġ(����)
	unsetcolor();

	printf("\n\n\n");

	y = 9;
	draw_yutpan(x, y);
	gotoxy(x + 6, y + 1);
	printf("<<��>>");					//���������� �� ���� ���Դ� �� ǥ���ϴ� ��ġ
	YUT = 5;							//������ ���Դ���?
	whatyut(x, y);

	y = 28;
	draw_score(x, y);
	gotoxy(x + 4, y + 1);
	setcolor(13, 0);
	printf("<<������>>");
	unsetcolor();
	gotoxy(x + 3, y + 3);				//���� �� ���� ������ ��Ÿ���ִ� ��ġ
	printf("�� 1 : ");
	gotoxy(x + 3, y + 5);
	printf("�� 2 : ");

	y = 35;
	mal_pan(x, y);						//���� ���� �󸶳� ���Ҵ� �� �˷��ִ� ��ġ
	gotoxy(x + 2, y + 1);
	printf("�� 1 : ");
	gotoxy(x + 2, y + 3);
	printf("�� 2 : ");

	x = 4;
	y = 38;
	board(x, y);						//���� ������ ��ġ
	gotoxy(x + 2, y + 3);
	r = 0;
	explain(x + 2, y + 2);

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1 , y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setcolor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void unsetcolor() {
	unsigned short back = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | (back << 4));
}


void YutNori() {					//������ �� ����Լ�
	int x = 4;
	int y = 4;
	gotoxy(x, y);
	draw_large_square(x, y);
	draw_basic_square(x + 12, y);
	draw_basic_square(x + 24, y);
	draw_basic_square(x + 36, y);
	draw_basic_square(x + 48, y);
	draw_large_square(x + 56, y);
	y = 8;
	draw_basic_square(x + 10, y);
	draw_basic_square(x + 50, y);
	y = 10;
	draw_basic_square(x, y);
	draw_basic_square(x + 60, y);
	y = 14;
	draw_basic_square(x + 20, y);
	draw_basic_square(x + 42, y);
	y = 16;
	draw_basic_square(x, y);
	draw_basic_square(x + 60, y);
	y = 18;
	draw_large_square(x + 29, y);
	y = 22;
	draw_basic_square(x, y);
	draw_basic_square(x + 60, y);
	y = 24;
	draw_basic_square(x + 20, y);
	draw_basic_square(x + 42, y);
	y = 28;
	draw_basic_square(x, y);
	draw_basic_square(x + 60, y);
	y = 29;
	draw_basic_square(x + 10, y);
	draw_basic_square(x + 50, y);
	y = 34;
	gotoxy(x + 57, y - 1);
	setcolor(11, 0);
	printf("<START>");
	unsetcolor();
	draw_large_square(x, y - 2);
	draw_basic_square(x + 12, y);
	draw_basic_square(x + 24, y);
	draw_basic_square(x + 36, y);
	draw_basic_square(x + 48, y);
	draw_large_square(x + 56, y - 2);
}

void draw_basic_square(int x, int y)			//no touch
{
	unsigned char a = 0xa6, b[7], i;
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	gotoxy(x + 2, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y);
	printf("%c%c", a, b[4]);
	gotoxy(x, y + 1);
	printf("%c%c", a, b[2]);
	gotoxy(x + 4, y + 1);
	printf("%c%c", a, b[2]);
	gotoxy(x, y + 2);
	printf("%c%c", a, b[6]);
	gotoxy(x + 2, y + 2);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y + 2);
	printf("%c%c", a, b[5]);
}

void draw_large_square(int x, int y) {			//ū �簢��
	unsigned char a = 0xa6, b[7], i;
	//setcolor(16, 0);
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	gotoxy(x + 2, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 6, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 8, y);
	printf("%c%c", a, b[4]);
	gotoxy(x, y + 1);
	printf("%c%c", a, b[2]);
	gotoxy(x + 8, y + 1);
	printf("%c%c", a, b[2]);
	gotoxy(x, y + 2);
	printf("%c%c", a, b[2]);
	gotoxy(x + 8, y + 2);
	printf("%c%c", a, b[2]);
	gotoxy(x, y + 3);
	printf("%c%c", a, b[2]);
	gotoxy(x + 8, y + 3);
	printf("%c%c", a, b[2]);
	gotoxy(x, y + 4);
	printf("%c%c", a, b[6]);
	gotoxy(x + 2, y + 4);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y + 4);
	printf("%c%c", a, b[1]);
	gotoxy(x + 6, y + 4);
	printf("%c%c", a, b[1]);
	gotoxy(x + 8, y + 4);
	printf("%c%c", a, b[5]);
	//unsetcolor();
}

void draw_score(int x, int y)
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 15; n++) {
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 6; k++) {
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);
		gotoxy(x + 16, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 6);
	printf("%c%c", a, b[6]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y + 6);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y + 6);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

void draw_yutpan(int x, int y)					//���� ������ �� ��µǴ� ��
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);					//����
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 18; k++)	//����
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);
		gotoxy(x + 16, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 18);				//�Ʒ���
	printf("%c%c", a, b[6]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y + 18);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y + 18);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

void board(int x, int y)					//���� ��µǴ� â
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 63; n++)		//����
	{
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 64, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 6; k++)			//����
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);

		gotoxy(x + 64, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 6);
	printf("%c%c", a, b[6]);
	for (int m = 1; m < 63; m++)
	{
		gotoxy(x + (m + 1), y + 6);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 64, y + 6);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

void mal_pan(int x, int y)		//���� ������ �� ��Ȳ�� ��Ÿ�� �ִ� ��
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 4; k++)
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);

		gotoxy(x + 16, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 4);
	printf("%c%c", a, b[6]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y + 4);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y + 4);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

void yut(int x, int y)						//�⺻���� �� ��� ����� 4��
{
	unsigned char a = 0xa6, b[7], i;
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	gotoxy(x + 2, y);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 6; k++)			//����
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);

		gotoxy(x + 4, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 6);
	printf("%c%c", a, b[6]);
	gotoxy(x + 2, y + 6);
	printf("%c%c", a, b[1]);
	gotoxy(x + 4, y + 6);
	printf("%c%c", a, b[5]);
}				//�������

void whatyut(int x, int y)				//���������� or ���� ǥ��
{
	if (YUT == 1) {						//���� ������
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 10, y + 11);
	}
	else if (YUT == 2) {					//���� ������
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		yut(x + 10, y + 11);
	}
	else if (YUT == 3) {				//���� ������
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		yut(x + 10, y + 3);
		yut(x + 10, y + 11);
	}
	else if (YUT == 4) {				//���� ������
		yut(x + 2, y + 3);
		yut(x + 2, y + 11);
		yut(x + 10, y + 3);
		yut(x + 10, y + 11);
	}
	else if (YUT == 5) {				//�𳪿���
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
	}
	else if (YUT == -1) {						//������ ������
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("��");
			unsetcolor();
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			setcolor(12, 0);
			printf("��");
			unsetcolor();
		}
	}
}

void explain(int x, int y)
{
	gotoxy(x, y);
	if (YUT == 1) {
		setcolor(10, 0);
		printf("'��'�� ���Խ��ϴ� ���� ��ĭ �̵��մϴ�.");
		unsetcolor();
	}
	else if (YUT == 2) {
		setcolor(13, 0);
		printf("'��'�� ���Խ��ϴ� ���� ��ĭ �̵��մϴ�.");
		unsetcolor();
	}
	else if (YUT == 3) {
		setcolor(6, 0);
		printf("'��'�� ���Խ��ϴ� ���� ��ĭ �̵��մϴ�.");
		unsetcolor();
	}
	else if (YUT == 4) {
		setcolor(11, 0);
		printf("'��'�� ���Խ��ϴ� ���� �ѹ� �� ������ ���� ��ĭ �̵��մϴ�.");
		unsetcolor();
	}
	else if (YUT == 5) {
		setcolor(14, 0);
		printf("'��'�� ���Խ��ϴ� ���� �ѹ� �� ������ ���� �ټ�ĭ �̵��մϴ�.");
		unsetcolor();
	}

	else if (YUT == -1) {
		setcolor(12, 0);
		printf("'����'�� ���Խ��ϴ� ���� �ڷ� ��ĭ �����Դϴ�.");
		unsetcolor();
	}

	//if (basic[22]) {	//�������� ������ ��
	//	gotoxy(x + 3, y + 2);
	//	setcolor(11, 0);
	//	printf("���� ���������� ���Խ��ϴ� +1��");
	//	unsetcolor();
	//}
	if (r == 0) {	//���� ��������
		gotoxy(x + 3, y + 2);
		setcolor(13, 0);
		printf("���� �������ϴ�. ���ݺ��� ���� 2���� �̵��մϴ�.");
		unsetcolor();
	}
	if (r == 1) {	//���� �������
		gotoxy(x + 3, y + 2);
		setcolor(12, 0);
		printf("������� ���� ��ҽ��ϴ�. ���� ���� �������� �̵��մϴ�.");
		unsetcolor();
	}
}

void Print_Game()
{
	int i;
	for (i = 0; i < 4; i++)
	{
		system("cls");
		setcolor(11, 0);
		printf("\n\t������������������������������������ LOADING... ������������������������������������");
		Sleep(300);
		unsetcolor();
		system("cls");
		setcolor(14, 0);
		printf("\n\t������������������������������������ LOADING... ������������������������������������");
		unsetcolor();
		Sleep(300);	
		system("cls");
		setcolor(13, 0);
		printf("\n\t������������������������������������ LOADING... ������������������������������������");
		Sleep(300);
		unsetcolor();
		system("cls");
	}
	setcolor(11, 0);
	printf("\n\t�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ٢� GAME START ���١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�");
	unsetcolor();
}