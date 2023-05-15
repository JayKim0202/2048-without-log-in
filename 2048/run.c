#include "run.h"

// ����ȭ�� �۵���
// ���� �� �ִ� ��� Ű�� ���� ����� ���� ��� �־����
// ����Ű�� 2����Ʈ
void run_starting_screen()
{
	int kb_input;	// Ű�޴� ����
	int box_location[3] = { 8, 10, 12 };	// �׸� ĭ���� ���� ��ġ ��ǥ
	int location_count = 0;	// �׸� ĭ���� ���� ��ġ ��ǥ�� �ε���

	cursor_view_f();
	starting_screen();	// ����ȭ�� ��¿�
	vertical_selection_box(box_location[location_count]);	// ����ȭ�鿡 �׸�ĭ ��¿�

	// �׸�ĭ�� ����Ű�� �����̱� ���� �������� Ű�� ����
	while (1)
	{
		kb_input = _getch();	// Ű����
		if (kb_input == ESC)	// ESC�� 1bit�̱� ������ �ѹ� �Է¹ް� Ȯ�� ����
		{
			exit(0);
		}
		else if (kb_input == ENTER)	// ENTER�� 1bit�̱� ������ �ѹ� �Է¹ٵ� Ȯ�� �������
		{
			// ���͸� ������ �� ĭ�� �´� �Լ����� ����ȴ�.
			switch (location_count)
			{
			case 0:		// START
				run_mode_screen();	// 3x3 4x4 5x5 �������� �Ѿ
				system("cls");	// ���� �Լ��� ������ �ٽ� ����ȭ���� ����ϱ� ���� ȭ���� Ŭ���� �������
				// ����ȭ�� ���
				starting_screen();
				vertical_selection_box(box_location[location_count]);
				break;
			case 1:		// RULE
				rule();		// �� �������� �Ѿ
				system("cls");	// ���� �Լ��� ������ �ٽ� ����ȭ���� ����ϱ� ���� ȭ���� Ŭ���� �������
				// ����ȭ�� ���
				starting_screen();
				vertical_selection_box(box_location[location_count]);
				break;
			case 2:		// RANK
				rank_frame();
				rank_print(fread_allPlayers(), fread_playerNum());
				system("cls");	// ���� �Լ��� ������ �ٽ� ����ȭ���� ����ϱ� ���� ȭ���� Ŭ���� �������
				// ����ȭ�� ���
				starting_screen();
				vertical_selection_box(box_location[location_count]);
				break;
			}
		}
		// ���� �޴��� ����ǰ� ���� kb_input���� ������ ENTER�� �ԷµǾ�����
		// continue�� �ȳ����� ���ͳ� ESC�� ������ �۵����� �ʴ� ������ ���� �� ����
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();
		if (kb_input == 224)	// ����Ű�� ���ϴ� 224�� ������ �ʾҴٸ� ESC�� ENTER������ Ű�� ���� �ʰ� �ٽ� ó������ ���ư� �ٽ� �ݺ��Ѵ�.
			kb_input = _getch();	// ����Ű�� ���� ��� �Էµ� ���� �޾ƿ�

		// �׸�ĭ�� ���Ʒ��� �����̱� ���� �͵�
		switch (kb_input)
		{
		case UP:
			if (location_count == 0)break;		// ���� ���� �׸� ��ġ������ �� �� �̻� �̵��� ���� ���ذ� ����
			// �׸�ڽ��� �̵��� �� ó�� ���̱� ���� Ʈ��
			system("cls");
			starting_screen();
			vertical_selection_box(box_location[--location_count]);
			break;
		case DOWN:
			if (location_count == 2)break;		// ���� �Ʒ��� �׸� ��ġ������ �� �� �̻� �̵��� ���� ���ϰ� ����
			// �׸�ڽ��� �̵��� �� ó�� ���̱� ���� Ʈ��
			system("cls");
			starting_screen();
			vertical_selection_box(box_location[++location_count]);
			break;
		}
	}
}

// ���ȭ�� �۵���
// start���� ���� ���� ��
void run_mode_screen()
{
	int box_location[3] = { 2, 12, 22 };	// �׸� ĭ���� ���� ��ġ ��ǥ
	int kb_input;	// Ű�޴� ����
	int location_count = 0;		// �׸� ĭ���� ���� ��ġ ��ǥ�� �ε���

	mode_screen();	// ��� ȭ�� ��¿�
	horizon_selection_box(box_location[location_count]);	// �׸�ĭ ����

	while (1)
	{
		kb_input = _getch();
		if (kb_input == ESC)
			return;
		else if (kb_input == ENTER)
		{
			// 3x3 (17, 13)
			// 4x4 (24, 17)
			// 5x5 (31, 21)
			switch (location_count)
			{
			case 0:
				system("cls");
				run_real_game3();
				system("cls");
				mode_screen();
				horizon_selection_box(box_location[location_count]);
				break;
			case 1:
				system("cls");
				run_real_game4();
				system("cls");
				mode_screen();
				horizon_selection_box(box_location[location_count]);
				break;
			case 2:
				system("cls");
				run_real_game5();
				system("cls");
				mode_screen();
				horizon_selection_box(box_location[location_count]);
				break;
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();

		switch (kb_input)
		{
		case LEFT:
			if (location_count == 0) break;
			system("cls");
			mode_screen();
			horizon_selection_box(box_location[--location_count]);
			break;
		case RIGHT:
			if (location_count == 2) break;
			system("cls");
			mode_screen();
			horizon_selection_box(box_location[++location_count]);
			break;
		}
	}
}

// 3x3 ���� �۵���
void run_real_game3()
{
	int number_table[3][3] = { 0 };
	int rand_x = 0;
	int rand_y = 0;
	int is_x_empty[3] = { 0 };
	int is_y_empty[3] = { 0 };
	int score = 0;
	int is_2048 = 0;

	int kb_input = 0;

	while (1)
	{
		play_screen(21, 13, 34, score);

		while (1)
		{
			rand_x = rand() % 3;
			while (is_x_empty[rand_x] == 1)
			{
				rand_x = rand() % 3;
				if (is_full3(number_table) == 9) break;
			}
			is_x_empty[rand_x] = 1;
			rand_y = rand() % 3;
			while (is_y_empty[rand_y] == 1 && number_table[rand_x][rand_y] != 0)
			{
				rand_y = rand() % 3;
				if (is_full3(number_table) == 9) break;
			}
			is_y_empty[rand_y] = 1;

			for (int i = 0; i < 3; i++)
			{
				is_x_empty[i] = 0;
				is_y_empty[i] = 0;
			}

			if (is_full3(number_table) == 9 || number_table[rand_x][rand_y] == 0) break;
		}

		// 2048�� ��������� Ȯ��
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (number_table[i][j] == 2048)
				{
					is_2048 = 1;
					break;
				}
			}
			if (is_2048 == 1) break;
		}

		if (is_full3(number_table) != 9)
		{
			number_table[rand_x][rand_y] = (rand() % 2 + 1) * 2;
			print_number(rand_x, rand_y, number_table[rand_x][rand_y]);
			score += number_table[rand_x][rand_y];
		}
		else if (is_full3(number_table) == 9 && is_same3(number_table) == 0)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			game_over_screen(score);
			fwrite_score(score);
			game_over_box(box_location[location_count]);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					game_over_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					game_over_screen(score);
					// ���	C6385	'box_location'���� �߸��� �����͸� �а� �ֽ��ϴ�.�б� ������ ũ��� '8'����Ʈ�ε� �����δ� '12'����Ʈ�� ���� �� �ֽ��ϴ�.
					// box_location[++location_count] or box_location[location_count += 1]��� �ϸ� ���� ��� ��
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(21, 13, 34, score);
		}
		// ���⼭ else if�� 9ĭ�߿� 2048�� �� ĭ�� ������ win ȭ�� �����
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			// ���ھ� �����ϱ�
			fwrite_score(score);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					win_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					win_screen(score);
					// ���	C6385	'box_location'���� �߸��� �����͸� �а� �ֽ��ϴ�.�б� ������ ũ��� '8'����Ʈ�ε� �����δ� '12'����Ʈ�� ���� �� �ֽ��ϴ�.
					// box_location[++location_count] or box_location[location_count += 1]��� �ϸ� ���� ��� ��
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(21, 13, 34, score);
		}

		if ((kb_input != 's' && kb_input != 'S') && kb_input != ESC)
			kb_input = _getch();

		if (kb_input == ESC)
		{
			int location_count = 0;
			int box_location[2] = { 15, 24 };
			system("cls");
			done_game_screen();
			yes_no_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ESC || (kb_input == ENTER && location_count == 0))
					return;
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					kb_input = 0;
					break;
				}
				kb_input = _getch();
				switch (kb_input)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					done_game_screen();
					yes_no_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					done_game_screen();
					// ++location_count�� �ϸ� ��� ��..? ���� �𸣰���
					yes_no_box(box_location[location_count = +1]);
					break;
				}
			}
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
		}
		else if (kb_input == 's' || kb_input == 'S')
		{
			int location_count = 0;
			int box_location[3] = { 4, 7, 10 };
			system("cls");
			pause_screen();
			pause_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ENTER && location_count == 0)
				{
					system("cls");
					play_screen(21, 13, 34, score);
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							if (number_table[i][j] != 0)
								print_number(i, j, number_table[i][j]);
						}
					}
					kb_input = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					for (int i = 0; i < 3; i++)
						for (int j = 0; j < 3; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 2)
				{
					return;
				}
				if (kb_input == 224)
					kb_input = _getch();
				switch (kb_input)
				{
				case UP:
					if (location_count == 0) break;
					system("cls");
					pause_screen();
					pause_box(box_location[--location_count]);
					break;
				case DOWN:
					if (location_count == 2) break;
					system("cls");
					pause_screen();
					pause_box(box_location[++location_count]);
					break;
				}
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();
		else if ((kb_input == 's' || kb_input == 'S') || kb_input == ESC)
			continue;

		switch (kb_input)
		{
		case UP:
			up3(number_table, &score);
			system("cls");
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);

				}
			}
			break;
		case DOWN:
			down3(number_table, &score);
			system("cls");
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case LEFT:
			left3(number_table, &score);
			system("cls");
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case RIGHT:
			right3(number_table, &score);
			system("cls");
			play_screen(21, 13, 34, score);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		}
	}
}

// 4x4 ���� �۵���
void run_real_game4()
{
	int number_table[4][4] = { 0 };
	int rand_x = 0;
	int rand_y = 0;
	int is_x_empty[4] = { 0 };
	int is_y_empty[4] = { 0 };
	int score = 0;
	int is_2048 = 0;

	int kb_input = 0;

	while (1)
	{
		play_screen(30, 21, 43, score);

		while (1)
		{
			rand_x = rand() % 4;
			while (is_x_empty[rand_x] == 1)
			{
				rand_x = rand() % 4;
				if (is_full4(number_table) == 16) break;
			}
			is_x_empty[rand_x] = 1;
			rand_y = rand() % 4;
			while (is_y_empty[rand_y] == 1 && number_table[rand_x][rand_y] != 0)
			{
				rand_y = rand() % 4;
				if (is_full4(number_table) == 16) break;
			}
			is_y_empty[rand_y] = 1;

			for (int i = 0; i < 4; i++)
			{
				is_x_empty[i] = 0;
				is_y_empty[i] = 0;
			}

			if (is_full4(number_table) == 16 || number_table[rand_x][rand_y] == 0) break;
		}

		// 2048�� ��������� Ȯ��
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (number_table[i][j] == 2048)
				{
					is_2048 = 1;
					break;
				}
			}
			if (is_2048 == 1) break;
		}

		if (is_full4(number_table) != 16)
		{
			number_table[rand_x][rand_y] = (rand() % 2 + 1) * 2;
			print_number(rand_x, rand_y, number_table[rand_x][rand_y]);
			score += number_table[rand_x][rand_y];
		}
		else if (is_full4(number_table) == 16 && is_same4(number_table) == 0)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			game_over_screen(score);
			game_over_box(box_location[location_count]);

			// ���ھ� �����ϱ�
			fwrite_score(score);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 4; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					game_over_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					game_over_screen(score);
					// ���	C6385	'box_location'���� �߸��� �����͸� �а� �ֽ��ϴ�.�б� ������ ũ��� '8'����Ʈ�ε� �����δ� '12'����Ʈ�� ���� �� �ֽ��ϴ�.
					// box_location[++location_count] or box_location[location_count += 1]��� �ϸ� ���� ��� ��
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(30, 21, 43, score);
		}
		// ���⼭ else if�� 9ĭ�߿� 2048�� �� ĭ�� ������ win ȭ�� �����
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			// ���ھ� �����ϱ�
			fwrite_score(score);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 4; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					win_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					win_screen(score);
					// ���	C6385	'box_location'���� �߸��� �����͸� �а� �ֽ��ϴ�.�б� ������ ũ��� '8'����Ʈ�ε� �����δ� '12'����Ʈ�� ���� �� �ֽ��ϴ�.
					// box_location[++location_count] or box_location[location_count += 1]��� �ϸ� ���� ��� ��
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(30, 21, 43, score);
		}

		if ((kb_input != 's' && kb_input != 'S') && kb_input != ESC)
			kb_input = _getch();

		if (kb_input == ESC)
		{
			int location_count = 0;
			int box_location[2] = { 15, 24 };
			system("cls");
			done_game_screen();
			yes_no_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ESC || (kb_input == ENTER && location_count == 0))
					return;
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					kb_input = 0;
					break;
				}
				kb_input = _getch();
				switch (kb_input)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					done_game_screen();
					yes_no_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					done_game_screen();
					// ++location_count�� �ϸ� ��� ��..? ���� �𸣰���
					yes_no_box(box_location[location_count = +1]);
					break;
				}
			}
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
		}
		else if (kb_input == 's' || kb_input == 'S')
		{
			int location_count = 0;
			int box_location[3] = { 4, 7, 10 };
			system("cls");
			pause_screen();
			pause_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ENTER && location_count == 0)
				{
					system("cls");
					play_screen(30, 21, 43, score);
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (number_table[i][j] != 0)
								print_number(i, j, number_table[i][j]);
						}
					}
					kb_input = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 4; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 2)
				{
					return;
				}
				if (kb_input == 224)
					kb_input = _getch();
				switch (kb_input)
				{
				case UP:
					if (location_count == 0) break;
					system("cls");
					pause_screen();
					pause_box(box_location[--location_count]);
					break;
				case DOWN:
					if (location_count == 2) break;
					system("cls");
					pause_screen();
					pause_box(box_location[++location_count]);
					break;
				}
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();
		else if ((kb_input == 's' || kb_input == 'S') || kb_input == ESC)
			continue;

		switch (kb_input)
		{
		case UP:
			up4(number_table, &score);
			system("cls");
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case DOWN:
			down4(number_table, &score);
			system("cls");
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case LEFT:
			left4(number_table, &score);
			system("cls");
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case RIGHT:
			right4(number_table, &score);
			system("cls");
			play_screen(30, 21, 43, score);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		}
	}
}

// 5x5 ���� �۵���
void run_real_game5()
{
	int number_table[5][5] = { 0 };
	int rand_x = 0;
	int rand_y = 0;
	int is_x_empty[5] = { 0 };
	int is_y_empty[5] = { 0 };
	int score = 0;
	int is_2048 = 0;

	int kb_input = 0;

	while (1)
	{
		play_screen(39, 26, 52, score);

		while (1)
		{
			rand_x = rand() % 5;
			while (is_x_empty[rand_x] == 1)
			{
				rand_x = rand() % 5;
				if (is_full5(number_table) == 25) break;
			}
			is_x_empty[rand_x] = 1;
			rand_y = rand() % 5;
			while (is_y_empty[rand_y] == 1 && number_table[rand_x][rand_y] != 0)
			{
				rand_y = rand() % 5;
				if (is_full5(number_table) == 25) break;
			}
			is_y_empty[rand_y] = 1;

			for (int i = 0; i < 5; i++)
			{
				is_x_empty[i] = 0;
				is_y_empty[i] = 0;
			}

			if (is_full5(number_table) == 25 || number_table[rand_x][rand_y] == 0) break;
		}

		// 2048�� ��������� Ȯ��
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (number_table[i][j] == 2048)
				{
					is_2048 = 1;
					break;
				}
			}
			if (is_2048 == 1) break;
		}

		if (is_full5(number_table) != 25)
		{
			number_table[rand_x][rand_y] = (rand() % 2 + 1) * 2;
			print_number(rand_x, rand_y, number_table[rand_x][rand_y]);
			score += number_table[rand_x][rand_y];
		}
		else if (is_full5(number_table) == 25 && is_same5(number_table) == 0)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			game_over_screen(score);
			game_over_box(box_location[location_count]);

			// ���ھ� �����ϱ�
			fwrite_score(score);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 5; i++)
						for (int j = 0; j < 5; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					game_over_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					game_over_screen(score);
					// ���	C6385	'box_location'���� �߸��� �����͸� �а� �ֽ��ϴ�.�б� ������ ũ��� '8'����Ʈ�ε� �����δ� '12'����Ʈ�� ���� �� �ֽ��ϴ�.
					// box_location[++location_count] or box_location[location_count += 1]��� �ϸ� ���� ��� ��
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(39, 26, 52, score);
		}
		// ���⼭ else if�� 9ĭ�߿� 2048�� �� ĭ�� ������ win ȭ�� �����
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			// ���ھ� �����ϱ�
			fwrite_score(score);

			while (1)
			{
				temp_kb = _getch();
				if (temp_kb == ESC || (temp_kb == ENTER && location_count == 1))
					return;
				else if (temp_kb == ENTER && location_count == 0)
				{
					system("cls");
					for (int i = 0; i < 5; i++)
						for (int j = 0; j < 5; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				temp_kb = _getch();
				switch (temp_kb)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					win_screen(score);
					game_over_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					win_screen(score);
					// ���	C6385	'box_location'���� �߸��� �����͸� �а� �ֽ��ϴ�.�б� ������ ũ��� '8'����Ʈ�ε� �����δ� '12'����Ʈ�� ���� �� �ֽ��ϴ�.
					// box_location[++location_count] or box_location[location_count += 1]��� �ϸ� ���� ��� ��
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(39, 26, 52, score);
		}

		if ((kb_input != 's' && kb_input != 'S') && kb_input != ESC)
			kb_input = _getch();

		if (kb_input == ESC)
		{
			int location_count = 0;
			int box_location[2] = { 15, 24 };
			system("cls");
			done_game_screen();
			yes_no_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ESC || (kb_input == ENTER && location_count == 0))
					return;
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					kb_input = 0;
					break;
				}
				kb_input = _getch();
				switch (kb_input)
				{
				case LEFT:
					if (location_count == 0) break;
					system("cls");
					done_game_screen();
					yes_no_box(box_location[--location_count]);
					break;
				case RIGHT:
					if (location_count == 1) break;
					system("cls");
					done_game_screen();
					// ++location_count�� �ϸ� ��� ��..? ���� �𸣰���
					yes_no_box(box_location[location_count = +1]);
					break;
				}
			}
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
		}
		else if (kb_input == 's' || kb_input == 'S')
		{
			int location_count = 0;
			int box_location[3] = { 4, 7, 10 };
			system("cls");
			pause_screen();
			pause_box(box_location[location_count]);
			while (1)
			{
				kb_input = _getch();
				if (kb_input == ENTER && location_count == 0)
				{
					system("cls");
					play_screen(39, 26, 52, score);
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 5; j++)
						{
							if (number_table[i][j] != 0)
								print_number(i, j, number_table[i][j]);
						}
					}
					kb_input = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 1)
				{
					system("cls");
					for (int i = 0; i < 5; i++)
						for (int j = 0; j < 5; j++)
							number_table[i][j] = 0;
					score = 0;
					break;
				}
				else if (kb_input == ENTER && location_count == 2)
				{
					return;
				}
				if (kb_input == 224)
					kb_input = _getch();
				switch (kb_input)
				{
				case UP:
					if (location_count == 0) break;
					system("cls");
					pause_screen();
					pause_box(box_location[--location_count]);
					break;
				case DOWN:
					if (location_count == 2) break;
					system("cls");
					pause_screen();
					pause_box(box_location[++location_count]);
					break;
				}
			}
		}
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();

		if (kb_input == 224)
			kb_input = _getch();
		else if ((kb_input == 's' || kb_input == 'S') || kb_input == ESC)
			continue;

		switch (kb_input)
		{
		case UP:
			up5(number_table, &score);
			system("cls");
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case DOWN:
			down5(number_table, &score);
			system("cls");
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case LEFT:
			left5(number_table, &score);
			system("cls");
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		case RIGHT:
			right5(number_table, &score);
			system("cls");
			play_screen(39, 26, 52, score);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (number_table[i][j] != 0)
						print_number(i, j, number_table[i][j]);
				}
			}
			break;
		}
	}
}

// Ŀ�� ���� - Ŀ�� �����̴°� ���ִ� �ڵ�
void cursor_view_f()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}