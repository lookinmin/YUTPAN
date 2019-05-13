#include <stdio.h>
#include <Windows.h>

void gotoxy(int x, int y);
void draw_basic_square(x, y);
void draw_score(int x, int y);
void draw_yutpan(int x, int y);
void board(int x, int y);
void mal_pan(int x, int y);
void draw_large_square(int x, int y);
void YutNori(int x, int y);
void setcolor(unsigned short text, unsigned short back);
void unsetcolor();
void yut(int x, int y);
void whatyut(int x, int y);
void explain();

int YUT = 0;

int main(void)							//출력하는 창의 순서 중요(x,y좌표가 흔들립니다.)
{
	int k = 1; //1,2 팀표현
	int a;
	int x, y;
	x = 0, y = 0;
	YutNori(x, y);						//윷놀이 판 출력

	printf("\n");

	x = 70;
	y = 1;
	printf("\n\n\n");
	mal_pan(x, y);
	gotoxy(x + 5, y + 1);
	printf("현재순서");
	gotoxy(x + 5, y + 3);
	setcolor(11, 0);
	printf("=<%d팀>=", k);					//1팀 2팀 번갈아가며 표현하는 위치(순서)
	unsetcolor();

	printf("\n\n\n");

	y = 6;
	draw_yutpan(x, y);
	gotoxy(x + 6, y + 1);
	printf("<<모>>");					//도개걸윷모 중 뭐가 나왔는 지 표현하는 위치
	YUT = 5;							//무엇이 나왔는지?
	whatyut(x, y);

	y = 25;
	draw_score(x, y);
	gotoxy(x + 4, y + 1);
	setcolor(11, 0);
	printf("<<점수판>>");
	unsetcolor();
	gotoxy(x + 3, y + 3);				//현재 각 팀의 점수를 나타내주는 위치
	printf("팀 1 : ");
	gotoxy(x + 3, y + 5);
	printf("팀 2 : ");

	y = 32;
	mal_pan(x, y);						//말이 현재 얼마나 남았는 지 알려주는 위치
	gotoxy(x + 2, y + 1);
	printf("팀 1 : ");
	gotoxy(x + 2, y + 3);
	printf("팀 2 : ");

	x = 1;
	y = 35;
	board(x, y);						//설명문 나오는 위치
	gotoxy(x + 2, y + 3);
	explain();

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return 0;
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


void YutNori(int x, int y) {					//윷놀이 판 출력함수
	x = 1, y = 1;
	gotoxy(x, y);
	draw_large_square(x, y);
	draw_basic_square(x + 12, y);
	draw_basic_square(x + 24, y);
	draw_basic_square(x + 36, y);
	draw_basic_square(x + 48, y);
	draw_large_square(x + 56, y);
	y = 6;
	draw_basic_square(x + 10, y);
	draw_basic_square(x + 50, y);
	y = 7;
	draw_basic_square(x, y);
	draw_basic_square(x + 60, y);
	y = 11;
	draw_basic_square(x + 20, y);
	draw_basic_square(x + 42, y);
	y = 13;
	draw_basic_square(x, y);
	draw_basic_square(x + 60, y);
	y = 15;
	draw_large_square(x + 29, y);
	y = 19;
	draw_basic_square(x, y);
	draw_basic_square(x + 60, y);
	y = 21;
	draw_basic_square(x + 20, y);
	draw_basic_square(x + 42, y);
	y = 25;
	draw_basic_square(x, y);
	draw_basic_square(x + 60, y);
	y = 26;
	draw_basic_square(x + 10, y);
	draw_basic_square(x + 50, y);
	y = 31;
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

void draw_large_square(int x, int y) {			//큰 사각형
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

void draw_yutpan(int x, int y)					//윷이 무엇인 지 출력되는 판
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);					//윗변
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 15; n++)
	{
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 16, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 18; k++)	//세로
	{
		gotoxy(x, y + k);
		printf("%c%c", a, b[2]);
		gotoxy(x + 16, y + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(x, y + 18);				//아랫변
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

void board(int x, int y)					//설명문 출력되는 창
{
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	for (int n = 1; n < 63; n++)		//가로
	{
		gotoxy(x + (n + 1), y);
		printf("%c%c", a, b[1]);
	}
	gotoxy(x + 64, y);
	printf("%c%c", a, b[4]);
	for (int k = 1; k < 6; k++)			//세로
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

void mal_pan(int x, int y)		//현재 각팀의 말 상황을 나타내 주는 판
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

void yut(int x, int y)						//기본적인 윷 모양 막대기 4개
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
	for (int k = 1; k < 6; k++)			//세로
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
}				//윷막대기

void whatyut(int x, int y)				//도개걸윷모 or 빽도 표현
{
	if (YUT == 1) {						//도가 나오면
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 11);
	}
	else if (YUT == 2) {					//개가 나오면
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		yut(x + 10, y + 11);
	}
	else if (YUT == 3) {				//걸이 나오면
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		yut(x + 10, y + 3);
		yut(x + 10, y + 11);
	}
	else if (YUT == 4) {				//윷이 나오면
		yut(x + 2, y + 3);
		yut(x + 2, y + 11);
		yut(x + 10, y + 3);
		yut(x + 10, y + 11);
	}
	else if (YUT == 5) {				//모나오면
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
	}
	else if (YUT == -1) {						//빽도가 나오면
		yut(x + 2, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 2, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 5));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 3);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 4, y + (i + 13));
			setcolor(14, 0);
			printf("Χ");
			unsetcolor();
		}
		yut(x + 10, y + 11);
		for (int i = 0; i < 3; ++i)
		{
			gotoxy(x + 12, y + (i + 13));
			setcolor(12, 0);
			printf("Φ");
			unsetcolor();
		}
	}
}

void explain()
{
	if (YUT == 1) {
		setcolor(10, 0);
		printf("'도'가 나왔습니다 말을 한칸 이동합니다.");
		unsetcolor();
	}
	else if (YUT == 2) {
		setcolor(13, 0);
		printf("'개'가 나왔습니다 말을 두칸 이동합니다.");
		unsetcolor();
	}
	else if (YUT == 3) {
		setcolor(6, 0);
		printf("'걸'이 나왔습니다 말을 세칸 이동합니다.");
		unsetcolor();
	}
	else if (YUT == 4) {
		setcolor(11, 0);
		printf("'윷'이 나왔습니다 윷을 한번 더 던지고 말을 네칸 이동합니다.");
		unsetcolor();
	}
	else if (YUT == 5) {
		setcolor(14, 0);
		printf("'모'가 나왔습니다 윷을 한번 더 던지고 말을 다섯칸 이동합니다.");
		unsetcolor();
	}

	else if (YUT == -1) {
		setcolor(12, 0);
		printf("'빽도'가 나왔습니다 말을 뒤로 한칸 움직입니다.");
		unsetcolor();
	}

	//if ()	//골인지점 들어왔을 시
	//	printf("말이 골인지점에 들어왔습니다 +1점");
	//if ()	//말을 업었으면
	//	printf("말을 업었습니다. 지금부터 말을 2개씩 이동합니다.");
	//if ()	//말을 잡았으면
	//	printf("상대팀의 말을 잡았습니다. 잡힌 말은 말판으로 이동합니다.");
}