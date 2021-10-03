#include "default_frame.h"

// ����ȭ��
void starting_screen()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	system("cls");

	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);

	// �� �� �� �� �� ��
	// �� �� �� �� �� ��

	for (int i = 0; i < 24; i++)
		printf("��");
	printf("\n");
	printf("�������������������������\n");
	printf("�������������������������\n");
	printf("�������������������������\n");
	printf("�������������������������\n");
	printf("�������������������������\n");
	for (int i = 0; i < 24; i++)
		printf("��");

	coord.X = 2;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("�� �� �� �� : MOVE");

	coord.X = 10;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("ESC : QUIT");

	coord.X = 6;
	coord.Y = 12;
	SetConsoleCursorPosition(handle, coord);
	printf("s or S : PAUSE");

	coord.X = 9;
	coord.Y = 13;
	SetConsoleCursorPosition(handle, coord);
	printf("ENTER : RUN");

	coord.X = 37;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("START");

	coord.X = 37;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("RULES");

	coord.X = 37;
	coord.Y = 13;
	SetConsoleCursorPosition(handle, coord);
	printf("RANK");
}

// 3x3, 4x4, 5x5 �� �����ϴ� ȭ��
void mode_screen()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	system("cls");

	coord.X = 4;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("3 X 3");

	coord.X = 14;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("4 X 4");

	coord.X = 24;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("5 X 5");

	coord.X = 40;
	coord.Y = 2;
	SetConsoleCursorPosition(handle, coord);
	printf("�� �� �� �� : MOVE");

	coord.X = 40;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("ESC : QUIT");

	coord.X = 40;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("s or S : PAUSE");

	coord.X = 40;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("ENTER : PLAY");
}

// ������ �⺻ Ʋ
// x, y : ���� �������� ��ǥ
// other : ����Ű��  x��ǥ
void play_screen(int x, int y, int other, int score)
{
	// 3x3 (21, 16, 34)
	// 4x4 (30, 21, 43)
	// 5x5 (39, 26, 52)

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	//system("cls");

	coord.X = 5;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	printf("2048");

	for (int i = 3; i <= y; i += 5)
	{
		for (int j = 3; j <= x; j += 8)
		{
			coord.X = j;
			coord.Y = i;
			SetConsoleCursorPosition(handle, coord);
			printf("����������������");
			coord.X = j;
			coord.Y = i + 1;
			SetConsoleCursorPosition(handle, coord);
			printf("��");
			coord.X = j;
			coord.Y = i + 2;
			SetConsoleCursorPosition(handle, coord);
			printf("��");
			coord.X = j + 7;
			coord.Y = i + 1;
			SetConsoleCursorPosition(handle, coord);
			printf("��");
			coord.X = j + 7;
			coord.Y = i + 2;
			SetConsoleCursorPosition(handle, coord);
			printf("��");
			coord.X = j;
			coord.Y = i + 3;
			SetConsoleCursorPosition(handle, coord);
			printf("����������������");
		}
	}

	coord.X = other;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("�� �� �� �� : MOVE");

	coord.X = other;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("ESC : QUIT");

	coord.X = other;
	coord.Y = 6;
	SetConsoleCursorPosition(handle, coord);
	printf("s or S : PAUSE");

	coord.X = other;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("ENTER : PLAY");

	coord.X = other;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("SCORE : %d", score);
}

// starting_screen���� ���Ǵ� �׸�ĭ
void vertical_selection_box(int y)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 34;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
	printf("��������������������");
	coord.X = 34;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = 43;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = 34;
	coord.Y = y + 2;
	SetConsoleCursorPosition(handle, coord);
	printf("��������������������");
}

// starting_screen���� ���Ǵ� �׸�ĭ
void horizon_selection_box(int x)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("����������������");

	coord.X = x;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = x + 7;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = x;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("����������������");
}

// ���� ����
void rule()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	system("cls");

	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("��");
	}

	coord.X = 0;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.X = 38;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.X = 0;
	coord.Y = 21;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("��");
	}

	coord.X = 3;
	coord.Y = 2;
	SetConsoleCursorPosition(handle, coord);
	printf("���� �� 2���� 2(�Ǵ� 4)�� ��Ÿ����.");

	coord.X = 3;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("Ű������ ����Ű�� ������ �����");

	coord.X = 3;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("���� �� �������� �̵��ϸ鼭 ����");

	coord.X = 3;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("���ڰ� ���� ��� ��������, ���ڸ�");

	coord.X = 3;
	coord.Y = 6;
	SetConsoleCursorPosition(handle, coord);
	printf("�� �� ĭ�� �����ϰ� 2 �Ǵ� 4�� ��");

	coord.X = 3;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("�´�. �̸� �ݺ��ؼ� 2�κ��� 2048��");

	coord.X = 3;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("����� ���� CLEAR");

	coord.X = 3;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("2048�� ����� �� 16ĭ�� �� ����");

	coord.X = 3;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("���鼭 ������ �� ĭ�� ���� ���� ��,");

	coord.X = 3;
	coord.Y = 12;
	SetConsoleCursorPosition(handle, coord);
	printf("GAME OVER");

	// ��ó ��Ű�ǵ��

	_getch();
}

// ���Ӿȿ��� ESC�� ������ �� �ߴ� ȭ��
void done_game_screen()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 10;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("������ �����ðڽ��ϱ�?");

	coord.X = 17;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("YES");

	coord.X = 22;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("or");

	coord.X = 26;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("NO");
}

// done_game_screen���� ���Ǵ� �׸�ĭ
void yes_no_box(int x)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("������������");

	coord.X = x;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = x + 5;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = x;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("������������");
}

// 's' or 'S'�� ������ �� �ߴ� ȭ��
void pause_screen()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 15;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("KEEP PLAY");

	coord.X = 16;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("REPLAY");

	coord.X = 17;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("QUIT");
}

// pause_screen���� ���Ǵ� �׸�ĭ
void pause_box(int y)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 13;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
	printf("������������������������");

	coord.X = 13;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = 13 + 11;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = 13;
	coord.Y = y + 2;
	SetConsoleCursorPosition(handle, coord);
	printf("������������������������");
}





// ���⼭ ���� �����ؾ� �� ����

// �ð��� �������� ��� ��
// ���߿� �α��� â���� �����
// �÷��̾� ���̵� �Ű������� �־���
// �ϴ��� ���ھ


// 9ĭ, 16ĭ, 25ĭ�� �� á�� �� �ߴ� ȭ��
void game_over_screen(int score)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 11;
	coord.Y = 6;
	SetConsoleCursorPosition(handle, coord);
	printf("GAME OVER");

	coord.X = 10;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("SCORE : %d", score);

	// 6
	coord.X = 8;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("REPLAY");

	coord.X = 16;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("or");

	// 18
	coord.X = 21;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("QUIT");
}

// 2048�� ������� �� �ߴ� ȭ��
void win_screen(int score)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 11;
	coord.Y = 6;
	SetConsoleCursorPosition(handle, coord);
	printf("YOUR WIN");

	coord.X = 10;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("SCORE : %d", score);

	// 6
	coord.X = 8;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("REPLAY");

	coord.X = 16;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("or");

	// 18
	coord.X = 21;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("QUIT");
}

// game_over_screen�� win_screen���� ���Ǵ� �׸�ĭ
void game_over_box(int x)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("������������������");

	coord.X = x;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = x + 8;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	coord.X = x;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("������������������");
}