#include "default_frame.h"

// 시작화면
void starting_screen()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	system("cls");

	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(handle, coord);

	// ■ □ → ← ↑ ↓
	// ─ │ ┌ ┐ ┘ └

	for (int i = 0; i < 24; i++)
		printf("□");
	printf("\n");
	printf("□□■■■□□□■■□□■□□□□□■■■□□□\n");
	printf("□□□□□■□■□□■□■□□□□■□□□■□□\n");
	printf("□□□□■□□■□□■□■□■□□□■■■□□□\n");
	printf("□□□■□□□■□□■□■■■■□■□□□■□□\n");
	printf("□□■■■■□□■■□□□□■□□□■■■□□□\n");
	for (int i = 0; i < 24; i++)
		printf("□");

	coord.X = 2;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("→ ← ↑ ↓ : MOVE");

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

// 3x3, 4x4, 5x5 중 선택하는 화면
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
	printf("→ ← ↑ ↓ : MOVE");

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

// 게임의 기본 틀
// x, y : 가장 끝상자의 좌표
// other : 조작키의  x좌표
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
			printf("┌──────┐");
			coord.X = j;
			coord.Y = i + 1;
			SetConsoleCursorPosition(handle, coord);
			printf("│");
			coord.X = j;
			coord.Y = i + 2;
			SetConsoleCursorPosition(handle, coord);
			printf("│");
			coord.X = j + 7;
			coord.Y = i + 1;
			SetConsoleCursorPosition(handle, coord);
			printf("│");
			coord.X = j + 7;
			coord.Y = i + 2;
			SetConsoleCursorPosition(handle, coord);
			printf("│");
			coord.X = j;
			coord.Y = i + 3;
			SetConsoleCursorPosition(handle, coord);
			printf("└──────┘");
		}
	}

	coord.X = other;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("→ ← ↑ ↓ : MOVE");

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

// starting_screen에서 사용되는 네모칸
void vertical_selection_box(int y)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 34;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
	printf("┌────────┐");
	coord.X = 34;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = 43;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = 34;
	coord.Y = y + 2;
	SetConsoleCursorPosition(handle, coord);
	printf("└────────┘");
}

// starting_screen에서 사용되는 네모칸
void horizon_selection_box(int x)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("┌──────┐");

	coord.X = x;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = x + 7;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = x;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("└──────┘");
}

// 게임 설명
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
		printf("■");
	}

	coord.X = 0;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.X = 38;
	coord.Y = 1;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.X = 0;
	coord.Y = 21;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
	}

	coord.X = 3;
	coord.Y = 2;
	SetConsoleCursorPosition(handle, coord);
	printf("시작 시 2개의 2(또는 4)가 나타난다.");

	coord.X = 3;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("키보드의 방향키를 누르면 블록이");

	coord.X = 3;
	coord.Y = 4;
	SetConsoleCursorPosition(handle, coord);
	printf("전부 그 방향으로 이동하면서 같은");

	coord.X = 3;
	coord.Y = 5;
	SetConsoleCursorPosition(handle, coord);
	printf("숫자가 있을 경우 합쳐지며, 빈자리");

	coord.X = 3;
	coord.Y = 6;
	SetConsoleCursorPosition(handle, coord);
	printf("중 한 칸에 램덤하게 2 또는 4가 나");

	coord.X = 3;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("온다. 이를 반복해서 2로부터 2048을");

	coord.X = 3;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("만들면 게임 CLEAR");

	coord.X = 3;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("2048을 만들기 전 16칸이 꽉 차있");

	coord.X = 3;
	coord.Y = 11;
	SetConsoleCursorPosition(handle, coord);
	printf("으면서 인접한 두 칸이 같이 않을 때,");

	coord.X = 3;
	coord.Y = 12;
	SetConsoleCursorPosition(handle, coord);
	printf("GAME OVER");

	// 출처 위키피디아

	_getch();
}

// 게임안에서 ESC를 눌렀을 때 뜨는 화면
void done_game_screen()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 10;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("게임을 끝내시겠습니까?");

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

// done_game_screen에서 사용되는 네모칸
void yes_no_box(int x)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("┌────┐");

	coord.X = x;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = x + 5;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = x;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("└────┘");
}

// 's' or 'S'를 눌렀을 때 뜨는 화면
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

// pause_screen에서 사용되는 네모칸
void pause_box(int y)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 13;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
	printf("┌──────────┐");

	coord.X = 13;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = 13 + 11;
	coord.Y = y + 1;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = 13;
	coord.Y = y + 2;
	SetConsoleCursorPosition(handle, coord);
	printf("└──────────┘");
}





// 여기서 부터 수정해야 될 수도

// 시간을 넣을지는 고민 중
// 나중에 로그인 창까지 만들면
// 플레이어 아이디도 매개변수로 넣야함
// 일단은 스코어만


// 9칸, 16칸, 25칸이 다 찼을 때 뜨는 화면
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

// 2048을 만들었을 때 뜨는 화면
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

// game_over_screen와 win_screen에서 사용되는 네모칸
void game_over_box(int x)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = x;
	coord.Y = 8;
	SetConsoleCursorPosition(handle, coord);
	printf("┌───────┐");

	coord.X = x;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = x + 8;
	coord.Y = 9;
	SetConsoleCursorPosition(handle, coord);
	printf("│");
	coord.X = x;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("└───────┘");
}