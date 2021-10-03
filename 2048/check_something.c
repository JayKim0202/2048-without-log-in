#include "check_something.h"

// ȭ�鿡 ���ڸ� �����
void print_number(int x, int y, int num)
{
	// num�� 0�� ���� ������� �ʴ´�
	if (num == 0)
		return;

	// cmdâ�� ���ڸ� ����� ��ġ�� ��ǥ
	// 5x5�� ����鼭 ����ȭ �ؾ���
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

	// �˸´� ��ǥ�� ���ڸ� ����Ѵ�
	coord.X = grid[x][y].x;
	coord.Y = grid[x][y].y;
	SetConsoleCursorPosition(handle, coord);
	printf("%4d", num);
}

//3x3

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void up3(int number_table[][3], int* score)
{
	// �ι� �ݺ����ִ� ������ ������ ������ ��, ������ִ� ĭ�� ���� �� �ֱ� �����̴�.
	// ex) 2 | 2 | 2 -> 2 | 0 | 4
	// �Ʒ��� ����ó�� ����� �ֱ� ����
	// ex) 2 | 2 | 2 -> 2 | 0 | 4 -> 0 | 2 | 4
	for (int i2 = 0; i2 < 2; i2++)
	{
		// �ѹ��� �ݺ����� ��� ������ ���� ����� ���´�.
		// ex) 2 | 0 | 0 -> 0 | 2 | 0
		// �ι��� ���־��� ���
		// ex) 2 | 0 | 0 -> 0 | 2 | 0 -> 0 | 0 | 2
		// �̷� ��� ������ ������ �ݺ��� 2�� �����ش�.
		for (int r = 0; r < 2; r++)
		{
			// ��� ���� ���ؾ��ϱ� ������ 3�� �ݺ��Ѵ�.
			for (int j = 0; j < 3; j++)
			{
				// 0��� 1��, 1��� 2���� �ٲ��ֱ� ������ 2�� �ݺ��Ѵ�.
				for (int i = 0; i < 2; i++)
				{
					// i�� j�� ��ǥ�� ������� ��� �Ʒ��� ��(i+1�� j��)���� ���ڸ� ������´�.
					// i�� j���� i+1�� j���� ���ڸ� �Űܿ����� i+1�� j�� 0���� ����ش�.
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i + 1][j];
						number_table[i + 1][j] = 0;
					}
				}
			}
		}

		// ��� ���� ���ؾ��ϱ� ������ 3���� �ݺ��Ѵ�.
		for (int j = 0; j < 3; j++)
		{
			// i�� j���� i�� j���� �Ʒ�ĭ�� i+1�� j���� ���� ��� �� ���ش�.
			if (number_table[i2][j] == number_table[i2 + 1][j])
			{
				// ���� ���� i�� j���� ���� ���� ��
				number_table[i2][j] += number_table[i2 + 1][j];
				// ���ھ ���� �����ش�.
				*score += number_table[i2][j];
				// �Ʒ�ĭ�� ����ش�.
				number_table[i2 + 1][j] = 0;
			}
		}
	}
}

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void down3(int number_table[][3], int* score)
{
	// �ι� �ݺ����ִ� ������ ������ ������ ��, ������ִ� ĭ�� ���� �� �ֱ� �����̴�.
	// ex) 2 | 2 | 2 -> 4 | 0 | 2
	// �Ʒ��� ����ó�� ����� �ֱ� ����
	// ex) 2 | 2 | 2 -> 4 | 0 | 2 -> 4 | 2 | 0
	for (int i2 = 2; i2 > 0; i2--)
	{
		// �ѹ��� �ݺ����� ��� ������ ���� ����� ���´�.
		// ex) 0 | 0 | 2 -> 0 | 2 | 0
		// �ι��� ���־��� ���
		// ex) 0 | 0 | 2 -> 0 | 2 | 0 -> 2 | 0 | 0
		// �̷� ��� ������ ������ �ݺ��� 2�� �����ش�.
		for (int r = 0; r < 2; r++)
		{
			// ��� ���� ���ؾ��ϱ� ������ 3�� �ݺ��Ѵ�.
			for (int j = 0; j < 3; j++)
			{
				// 2��� 1��, 1��� 0���� �ٲ��ֱ� ������ 2�� �ݺ��Ѵ�.
				for (int i = 2; i > 0; i--)
				{
					// i�� j�� ��ǥ�� ������� ��� ����(i-1�� j��)���� ���ڸ� ������´�.
					// i�� j���� i-1�� j���� ���ڸ� �Űܿ����� i-1�� j�� 0���� ����ش�.
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i - 1][j];
						number_table[i - 1][j] = 0;
					}
				}
			}
		}

		// ��� ���� ���ؾ��ϱ� ������ 3���� �ݺ��Ѵ�.
		for (int j = 0; j < 3; j++)
		{
			// i�� j���� i�� j���� ��ĭ�� i-1�� j���� ���� ��� �� ���ش�.
			if (number_table[i2][j] == number_table[i2 - 1][j])
			{
				// ���� ���� i�� j���� ���� ���� ��
				number_table[i2][j] += number_table[i2 - 1][j];
				// ���ھ ���� �����ش�.
				*score += number_table[i2][j];
				// ��ĭ�� ����ش�.
				number_table[i2 - 1][j] = 0;
			}
		}
	}
}

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void left3(int number_table[][3], int* score)
{
	// �ι� �ݺ����ִ� ������ ������ ������ ��, ������ִ� ĭ�� ���� �� �ֱ� �����̴�.
	// ex) 2 | 2 | 2 -> 4 | 0 | 2
	// �Ʒ��� ����ó�� ����� �ֱ� ����
	// ex) 2 | 2 | 2 -> 4 | 0 | 2 -> 4 | 2 | 0
	for (int j2 = 0; j2 < 2; j2++)
	{
		// �ѹ��� �ݺ����� ��� ������ ���� ����� ���´�.
		// ex) 0 | 0 | 2 -> 0 | 2 | 0
		// �ι��� ���־��� ���
		// ex) 0 | 0 | 2 -> 0 | 2 | 0 -> 2 | 0 | 0
		// �̷� ��� ������ ������ �ݺ��� 2�� �����ش�.
		for (int r = 0; r < 2; r++)
		{
			// ��� ���� ���ؾ��ϱ� ������ 3�� �ݺ��Ѵ�.
			for (int i = 0; i < 3; i++)
			{
				// 0���� 1��, 1���� 2���� �ٲ��ֱ� ������ 2�� �ݺ��Ѵ�.
				for (int j = 0; j < 2; j++)
				{
					// i�� j�� ��ǥ�� ������� ��� �����ʿ�(i�� j+1��)���� ���ڸ� ������´�.
					// i�� j���� i�� j+1���� ���ڸ� �Űܿ����� i�� j+1�� 0���� ����ش�.
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i][j + 1];
						number_table[i][j + 1] = 0;
					}
				}
			}
		}

		// ��� ��� ���ؾ��ϱ� ������ 3�� �ݺ��Ѵ�.
		for (int i = 0; i < 3; i++)
		{
			// i�� j���� i�� j���� ������ĭ�� i�� j+1���� ���� ��� �� ���ش�.
			if (number_table[i][j2] == number_table[i][j2 + 1])
			{
				// ���� ���� i�� j���� ���� ���� ��
				number_table[i][j2] += number_table[i][j2 + 1];
				// ���ھ ���� �����ش�.
				*score += number_table[i][j2];
				// ������ĭ�� ����ش�.
				number_table[i][j2 + 1] = 0;
			}
		}
	}
}

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void right3(int number_table[][3], int* score)
{
	// �ι� �ݺ����ִ� ������ ������ ������ ��, ������ִ� ĭ�� ���� �� �ֱ� �����̴�.
	// ex) 2 | 2 | 2 -> 2 | 0 | 4
	// �Ʒ��� ����ó�� ����� �ֱ� ����
	// ex) 2 | 2 | 2 -> 2 | 0 | 4 -> 0 | 2 | 4
	for (int j = 2; j > 0; j--)
	{
		// �ѹ��� �ݺ����� ��� ������ ���� ����� ���´�.
		// ex) 2 | 0 | 0 -> 0 | 2 | 0
		// �ι��� ���־��� ���
		// ex) 2 | 0 | 0 -> 0 | 2 | 0 -> 0 | 0 | 2
		// �̷� ��� ������ ������ �ݺ��� 2�� �����ش�.
		for (int r = 0; r < 2; r++)
		{
			// ��� ���� ���ؾ��ϱ� ������ 3�� �ݺ��Ѵ�.
			for (int i = 0; i < 3; i++)
			{
				// 2���� 1��, 1���� 0���� �ٲ��ֱ� ������ 2�� �ݺ��Ѵ�.
				for (int j = 2; j > 0; j--)
				{
					// i�� j�� ��ǥ�� ������� ��� ���ʿ�(i�� j-1��)���� ���ڸ� ������´�.
					// i�� j���� i�� j-1���� ���ڸ� �Űܿ����� i�� j-1�� 0���� ����ش�.
					if (number_table[i][j] == 0)
					{
						number_table[i][j] = number_table[i][j - 1];
						number_table[i][j - 1] = 0;
					}
				}
			}
		}

		// ��� ��� ���ؾ��ϱ� ������ 3�� �ݺ��Ѵ�.
		for (int i = 0; i < 3; i++)
		{
			// i�� j���� i�� j���� ����ĭ�� i�� j-1���� ���� ��� �� ���ش�.
			if (number_table[i][j] == number_table[i][j - 1])
			{
				// ���� ���� i�� j���� ���� ���� ��
				number_table[i][j] += number_table[i][j - 1];
				// ���ھ ���� �����ش�.
				*score += number_table[i][j];
				// ����ĭ�� ����ش�.
				number_table[i][j - 1] = 0;
			}
		}
	}
}

// �� á���� Ȯ��
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

// �����¿�� ���� ���ڰ� �ִ��� Ȯ��
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

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
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

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
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

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
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

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
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

// �� á���� Ȯ��
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

// �����¿�� ���� ���ڰ� �ִ��� Ȯ��
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

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
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

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
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

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
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

// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
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

// �� á���� Ȯ��
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

// �����¿�� ���� ���ڰ� �ִ��� Ȯ��
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