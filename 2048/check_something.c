#include "check_something.h"

// 화면에 숫자를 출력함
void print_number(int x, int y, int num)
{
	// num이 0일 때는 출력하지 않는다
	if (num == 0)
		return;

	// cmd창에 숫자를 출력할 위치의 좌표
	// 5x5는 만들면서 최적화 해야함
	Grid grid[5][5] = {
		{{.x = 5, .y = 4}, {.x = 13, .y = 4}, {.x = 21, .y = 4}, {.x = 30, .y = 4}, {.x = 38, .y = 4}},
		{{.x = 5, .y = 9}, {.x = 13, .y = 9}, {.x = 21, .y = 9}, {.x = 30, .y = 9}, {.x = 38, .y = 9}},
		{{.x = 5, .y = 14}, {.x = 13, .y = 14}, {.x = 21, .y = 14}, {.x = 30, .y = 14}, {.x = 38, .y = 14}},
		{{.x = 5, .y = 19}, {.x = 13, .y = 19}, {.x = 21, .y = 19}, {.x = 30, .y = 19}, {.x = 38, .y = 19}},
		{{.x = 5, .y = 24}, {.x = 13, .y = 24}, {.x = 21, .y = 24}, {.x = 30, .y = 24}, {.x = 38, .y = 24}}
	};

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	// 알맞는 좌표에 숫자를 출력한다
	coord.X = grid[x][y].x;
	coord.Y = grid[x][y].y;
	SetConsoleCursorPosition(handle, coord);
	printf("%4d", num);
}

//3x3

// ↑이 방향키를 눌렀을 때 실행되는 함수
void up3(int number_table[][3], int* score)
{
	// 두번 반복해주는 이유는 더셈을 진행한 후, 비워져있는 칸이 생길 수 있기 때문이다.
	// ex) 2 | 2 | 2 -> 2 | 0 | 4
	// 아래의 예시처럼 만들어 주기 위해
	// ex) 2 | 2 | 2 -> 2 | 0 | 4 -> 0 | 2 | 4
	for (int i2 = 0; i2 < 2; i2++)
	{
		// 한번만 반복했을 경우 다음과 같은 결과가 나온다.
		// ex) 2 | 0 | 0 -> 0 | 2 | 0
		// 두번을 해주었을 경우
		// ex) 2 | 0 | 0 -> 0 | 2 | 0 -> 0 | 0 | 2
		// 이런 결과 나오기 때문에 반복을 2번 돌려준다.
		for (int r = 0; r < 2; r++)
		{
			// 모든 열을 비교해야하기 때문에 3번 반복한다.
			for (int j = 0; j < 3; j++)
			{
				// 0행과 1행, 1행과 2행을 바꿔주기 때문에 2번 반복한다.
				for (int i = 0; i < 2; i++)
				{
					// i행 j열 좌표가 비어있을 경우 아래의 행(i+1행 j열)에서 숫자를 가지고온다.
					// i행 j열에 i+1행 j열의 숫자를 옮겨왔으니 i+1행 j을 0으로 비워준다.
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i + 1][j];
						number_table[i + 1][j] = 0;
					}
				}
			}
		}

		// 모든 열을 비교해야하기 때문에 3번을 반복한다.
		for (int j = 0; j < 3; j++)
		{
			// i행 j열과 i행 j열의 아래칸인 i+1행 j열이 같을 경우 더 해준다.
			if (number_table[i2][j] == number_table[i2 + 1][j])
			{
				// 더한 값은 i행 j열에 저장 해준 후
				number_table[i2][j] += number_table[i2 + 1][j];
				// 스코어에 값을 더해준다.
				*score += number_table[i2][j];
				// 아래칸은 비워준다.
				number_table[i2 + 1][j] = 0;
			}
		}
	}
}

// ↓이 방향키를 눌렀을 때 실행되는 함수
void down3(int number_table[][3], int* score)
{
	// 두번 반복해주는 이유는 더셈을 진행한 후, 비워져있는 칸이 생길 수 있기 때문이다.
	// ex) 2 | 2 | 2 -> 4 | 0 | 2
	// 아래의 예시처럼 만들어 주기 위해
	// ex) 2 | 2 | 2 -> 4 | 0 | 2 -> 4 | 2 | 0
	for (int i2 = 2; i2 > 0; i2--)
	{
		// 한번만 반복했을 경우 다음과 같은 결과가 나온다.
		// ex) 0 | 0 | 2 -> 0 | 2 | 0
		// 두번을 해주었을 경우
		// ex) 0 | 0 | 2 -> 0 | 2 | 0 -> 2 | 0 | 0
		// 이런 결과 나오기 때문에 반복을 2번 돌려준다.
		for (int r = 0; r < 2; r++)
		{
			// 모든 열을 비교해야하기 때문에 3번 반복한다.
			for (int j = 0; j < 3; j++)
			{
				// 2행과 1행, 1행과 0행을 바꿔주기 때문에 2번 반복한다.
				for (int i = 2; i > 0; i--)
				{
					// i행 j열 좌표가 비어있을 경우 윗행(i-1행 j열)에서 숫자를 가지고온다.
					// i행 j열에 i-1행 j열의 숫자를 옮겨왔으니 i-1행 j을 0으로 비워준다.
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i - 1][j];
						number_table[i - 1][j] = 0;
					}
				}
			}
		}

		// 모든 열을 비교해야하기 때문에 3번을 반복한다.
		for (int j = 0; j < 3; j++)
		{
			// i행 j열과 i행 j열의 윗칸인 i-1행 j열이 같을 경우 더 해준다.
			if (number_table[i2][j] == number_table[i2 - 1][j])
			{
				// 더한 값은 i행 j열에 저장 해준 후
				number_table[i2][j] += number_table[i2 - 1][j];
				// 스코어에 값을 더해준다.
				*score += number_table[i2][j];
				// 윗칸은 비워준다.
				number_table[i2 - 1][j] = 0;
			}
		}
	}
}

// ←이 방향키를 눌렀을 때 실행되는 함수
void left3(int number_table[][3], int* score)
{
	// 두번 반복해주는 이유는 더셈을 진행한 후, 비워져있는 칸이 생길 수 있기 때문이다.
	// ex) 2 | 2 | 2 -> 4 | 0 | 2
	// 아래의 예시처럼 만들어 주기 위해
	// ex) 2 | 2 | 2 -> 4 | 0 | 2 -> 4 | 2 | 0
	for (int j2 = 0; j2 < 2; j2++)
	{
		// 한번만 반복했을 경우 다음과 같은 결과가 나온다.
		// ex) 0 | 0 | 2 -> 0 | 2 | 0
		// 두번을 해주었을 경우
		// ex) 0 | 0 | 2 -> 0 | 2 | 0 -> 2 | 0 | 0
		// 이런 결과 나오기 때문에 반복을 2번 돌려준다.
		for (int r = 0; r < 2; r++)
		{
			// 모든 행을 비교해야하기 때문에 3번 반복한다.
			for (int i = 0; i < 3; i++)
			{
				// 0열과 1열, 1열과 2열을 바꿔주기 때문에 2번 반복한다.
				for (int j = 0; j < 2; j++)
				{
					// i행 j열 좌표가 비어있을 경우 오른쪽열(i행 j+1열)에서 숫자를 가지고온다.
					// i행 j열에 i행 j+1열의 숫자를 옮겨왔으니 i행 j+1을 0으로 비워준다.
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i][j + 1];
						number_table[i][j + 1] = 0;
					}
				}
			}
		}

		// 모든 행과 비교해야하기 때문에 3번 반복한다.
		for (int i = 0; i < 3; i++)
		{
			// i행 j열과 i행 j열의 오른쪽칸인 i행 j+1열이 같을 경우 더 해준다.
			if (number_table[i][j2] == number_table[i][j2 + 1])
			{
				// 더한 값은 i행 j열에 저장 해준 후
				number_table[i][j2] += number_table[i][j2 + 1];
				// 스코어에 값을 더해준다.
				*score += number_table[i][j2];
				// 오른쪽칸은 비워준다.
				number_table[i][j2 + 1] = 0;
			}
		}
	}
}

// →이 방향키를 눌렀을 때 실행되는 함수
void right3(int number_table[][3], int* score)
{
	// 두번 반복해주는 이유는 더셈을 진행한 후, 비워져있는 칸이 생길 수 있기 때문이다.
	// ex) 2 | 2 | 2 -> 2 | 0 | 4
	// 아래의 예시처럼 만들어 주기 위해
	// ex) 2 | 2 | 2 -> 2 | 0 | 4 -> 0 | 2 | 4
	for (int j = 2; j > 0; j--)
	{
		// 한번만 반복했을 경우 다음과 같은 결과가 나온다.
		// ex) 2 | 0 | 0 -> 0 | 2 | 0
		// 두번을 해주었을 경우
		// ex) 2 | 0 | 0 -> 0 | 2 | 0 -> 0 | 0 | 2
		// 이런 결과 나오기 때문에 반복을 2번 돌려준다.
		for (int r = 0; r < 2; r++)
		{
			// 모든 행을 비교해야하기 때문에 3번 반복한다.
			for (int i = 0; i < 3; i++)
			{
				// 2열과 1열, 1열과 0열을 바꿔주기 때문에 2번 반복한다.
				for (int j = 2; j > 0; j--)
				{
					// i행 j열 좌표가 비어있을 경우 왼쪽열(i행 j-1열)에서 숫자를 가지고온다.
					// i행 j열에 i행 j-1열의 숫자를 옮겨왔으니 i행 j-1을 0으로 비워준다.
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i][j - 1];
						number_table[i][j - 1] = 0;
					}
				}
			}
		}

		// 모든 행과 비교해야하기 때문에 3번 반복한다.
		for (int i = 0; i < 3; i++)
		{
			// i행 j열과 i행 j열의 왼쪽칸인 i행 j-1열이 같을 경우 더 해준다.
			if (number_table[i][j] == number_table[i][j - 1])
			{
				// 더한 값은 i행 j열에 저장 해준 후
				number_table[i][j] += number_table[i][j - 1];
				// 스코어에 값을 더해준다.
				*score += number_table[i][j];
				// 왼쪽칸은 비워준다.
				number_table[i][j - 1] = 0;
			}
		}
	}
}

// 꽉 찼는지 확인
int is_full3(int number_table[][3])
{
	int full = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (number_table[i][j] > 0)
				full++;
		}
	}

	return full;
}

// 상하좌우로 같은 숫자가 있는지 확인
int is_same3(int number_table[][3])
{
	int same = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (number_table[i][j] == number_table[i][j + 1])
				same++;
		}
	}

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (number_table[i][j] == number_table[i + 1][j])
				same++;
		}
	}

	return same;

}




//4x4

// ↑이 방향키를 눌렀을 때 실행되는 함수
void up4(int number_table[][4], int* score)
{
	for (int i2 = 0; i2 < 3; i2++)
	{
		for (int r = 0; r < 3; r++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int i = 0; i < 3; i++)
				{
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i + 1][j];
						number_table[i + 1][j] = 0;
					}
				}
			}
		}

		for (int j = 0; j < 4; j++)
		{
			if (number_table[i2][j] == number_table[i2 + 1][j])
			{
				number_table[i2][j] += number_table[i2 + 1][j];
				*score += number_table[i2][j];
				number_table[i2 + 1][j] = 0;
			}
		}
	}
}

// ↓이 방향키를 눌렀을 때 실행되는 함수
void down4(int number_table[][4], int* score)
{
	for (int i2 = 3; i2 > 0; i2--)
	{
		for (int r = 0; r < 3; r++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int i = 3; i > 0; i--)
				{
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i - 1][j];
						number_table[i - 1][j] = 0;
					}
				}
			}
		}

		for (int j = 0; j < 4; j++)
		{
			if (number_table[i2][j] == number_table[i2 - 1][j])
			{
				number_table[i2][j] += number_table[i2 - 1][j];
				*score += number_table[i2][j];
				number_table[i2 - 1][j] = 0;
			}
		}
	}
}

// ←이 방향키를 눌렀을 때 실행되는 함수
void left4(int number_table[][4], int* score)
{
	for (int j2 = 0; j2 < 3; j2++)
	{
		for (int r = 0; r < 3; r++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i][j + 1];
						number_table[i][j + 1] = 0;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (number_table[i][j2] == number_table[i][j2 + 1])
			{
				number_table[i][j2] += number_table[i][j2 + 1];
				*score += number_table[i][j2];
				number_table[i][j2 + 1] = 0;
			}
		}
	}
}

// →이 방향키를 눌렀을 때 실행되는 함수
void right4(int number_table[][4], int* score)
{
	for (int j = 3; j > 0; j--)
	{
		for (int r = 0; r < 3; r++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j > 0; j--)
				{
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i][j - 1];
						number_table[i][j - 1] = 0;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (number_table[i][j] == number_table[i][j - 1])
			{
				number_table[i][j] += number_table[i][j - 1];
				*score += number_table[i][j];
				number_table[i][j - 1] = 0;
			}
		}
	}
}

// 꽉 찼는지 확인
int is_full4(int number_table[][4])
{
	int full = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (number_table[i][j] > 0)
				full++;
		}
	}

	return full;
}

// 상하좌우로 같은 숫자가 있는지 확인
int is_same4(int number_table[][4])
{
	int same = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (number_table[i][j] == number_table[i][j + 1])
				same++;
		}
	}

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (number_table[i][j] == number_table[i + 1][j])
				same++;
		}
	}

	return same;
}




//5x5

// ↑이 방향키를 눌렀을 때 실행되는 함수
void up5(int number_table[][5], int* score)
{
	for (int i2 = 0; i2 < 4; i2++)
	{
		for (int r = 0; r < 4; r++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i + 1][j];
						number_table[i + 1][j] = 0;
					}
				}
			}
		}

		for (int j = 0; j < 5; j++)
		{
			if (number_table[i2][j] == number_table[i2 + 1][j])
			{
				number_table[i2][j] += number_table[i2 + 1][j];
				*score += number_table[i2][j];
				number_table[i2 + 1][j] = 0;
			}
		}
	}
}

// ↓이 방향키를 눌렀을 때 실행되는 함수
void down5(int number_table[][5], int* score)
{
	for (int i2 = 4; i2 > 0; i2--)
	{
		for (int r = 0; r < 4; r++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int i = 4; i > 0; i--)
				{
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i - 1][j];
						number_table[i - 1][j] = 0;
					}
				}
			}
		}

		for (int j = 0; j < 5; j++)
		{
			if (number_table[i2][j] == number_table[i2 - 1][j])
			{
				number_table[i2][j] += number_table[i2 - 1][j];
				*score += number_table[i2][j];
				number_table[i2 - 1][j] = 0;
			}
		}
	}
}

// ←이 방향키를 눌렀을 때 실행되는 함수
void left5(int number_table[][5], int* score)
{
	for (int j2 = 0; j2 < 4; j2++)
	{
		for (int r = 0; r < 4; r++)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i][j + 1];
						number_table[i][j + 1] = 0;
					}
				}
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (number_table[i][j2] == number_table[i][j2 + 1])
			{
				number_table[i][j2] += number_table[i][j2 + 1];
				*score += number_table[i][j2];
				number_table[i][j2 + 1] = 0;
			}
		}
	}
}

// →이 방향키를 눌렀을 때 실행되는 함수
void right5(int number_table[][5], int* score)
{
	for (int j = 4; j > 0; j--)
	{
		for (int r = 0; r < 4; r++)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 4; j > 0; j--)
				{
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i][j - 1];
						number_table[i][j - 1] = 0;
					}
				}
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (number_table[i][j] == number_table[i][j - 1])
			{
				number_table[i][j] += number_table[i][j - 1];
				*score += number_table[i][j];
				number_table[i][j - 1] = 0;
			}
		}
	}
}

// 꽉 찼는지 확인
int is_full5(int number_table[][5])
{
	int full = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (number_table[i][j] > 0)
				full++;
		}
	}

	return full;
}

// 상하좌우로 같은 숫자가 있는지 확인
int is_same5(int number_table[][5])
{
	int same = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (number_table[i][j] == number_table[i][j + 1])
				same++;
		}
	}

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (number_table[i][j] == number_table[i + 1][j])
				same++;
		}
	}

	return same;
}