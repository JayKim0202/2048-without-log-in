#include "run.h"

// 시작화면 작동부
// 받을 수 있는 모든 키에 대한 경우의 수를 모두 넣어놓음
// 방향키는 2바이트
void run_starting_screen()
{
	int kb_input;	// 키받는 변수
	int box_location[3] = { 8, 10, 12 };	// 네모 칸들의 생성 위치 좌표
	int location_count = 0;	// 네모 칸들의 생성 위치 좌표의 인덱스

	cursor_view_f();
	starting_screen();	// 시작화면 출력용
	vertical_selection_box(box_location[location_count]);	// 시작화면에 네모칸 출력용

	// 네모칸을 방향키로 움직이기 위해 무한으로 키를 받음
	while (1)
	{
		kb_input = _getch();	// 키받음
		if (kb_input == ESC)	// ESC는 1bit이기 때문에 한번 입력받고 확인 해줌
		{
			exit(0);
		}
		else if (kb_input == ENTER)	// ENTER도 1bit이기 때문에 한번 입력바도 확인 해줘야함
		{
			// 엔터를 누르면 그 칸에 맞는 함수들이 실행된다.
			switch (location_count)
			{
			case 0:		// START
				run_mode_screen();	// 3x3 4x4 5x5 선택지로 넘어감
				system("cls");	// 위의 함수가 끝나면 다시 시작화면을 출력하기 위해 화면은 클리어 해줘야함
				// 시작화면 출력
				starting_screen();
				vertical_selection_box(box_location[location_count]);
				break;
			case 1:		// RULE
				rule();		// 룰 설명으로 넘어감
				system("cls");	// 위의 함수가 끝나면 다시 시작화면을 출력하기 위해 화면은 클리어 해줘야함
				// 시작화면 출력
				starting_screen();
				vertical_selection_box(box_location[location_count]);
				break;
			case 2:		// RANK
				rank_frame();
				rank_print(fread_allPlayers(), fread_playerNum());
				system("cls");	// 위의 함수가 끝나면 다시 시작화면을 출력하기 위해 화면은 클리어 해줘야함
				// 시작화면 출력
				starting_screen();
				vertical_selection_box(box_location[location_count]);
				break;
			}
		}
		// 위의 메뉴가 실행되고 나면 kb_input에는 여전히 ENTER가 입력되어있음
		// continue를 안넣으면 엔터나 ESC를 눌러도 작동되지 않는 오류가 생길 수 있음
		if (kb_input == ENTER)
			continue;
		else
			kb_input = _getch();
		if (kb_input == 224)	// 방향키를 뜻하는 224가 눌리지 않았다면 ESC나 ENTER임으로 키를 받지 않고 다시 처음으로 돌아가 다시 반복한다.
			kb_input = _getch();	// 방향키가 맞을 경우 입력된 값을 받아옴

		// 네모칸을 위아래로 움직이기 위한 것들
		switch (kb_input)
		{
		case UP:
			if (location_count == 0)break;		// 가장 위에 네모가 위치해있을 때 더 이상 이동을 하지 못해게 막음
			// 네모박스가 이동한 것 처럼 보이기 위한 트릭
			system("cls");
			starting_screen();
			vertical_selection_box(box_location[--location_count]);
			break;
		case DOWN:
			if (location_count == 2)break;		// 가장 아래에 네모가 위치해있을 때 더 이상 이동을 하지 못하게 막음
			// 네모박스가 이동한 것 처럼 보이기 위한 트릭
			system("cls");
			starting_screen();
			vertical_selection_box(box_location[++location_count]);
			break;
		}
	}
}

// 모드화면 작동부
// start에서 엔터 누른 후
void run_mode_screen()
{
	int box_location[3] = { 2, 12, 22 };	// 네모 칸들의 생성 위치 좌표
	int kb_input;	// 키받는 변수
	int location_count = 0;		// 네모 칸들의 생성 위치 좌표의 인덱스

	mode_screen();	// 모드 화면 출력용
	horizon_selection_box(box_location[location_count]);	// 네모칸 생성

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

// 3x3 게임 작동부
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

		// 2048이 만들어졌나 확인
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
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(21, 13, 34, score);
		}
		// 여기서 else if로 9칸중에 2048이 된 칸이 있으면 win 화면 띄어줌
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			// 스코어 저장하기
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
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
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
					// ++location_count로 하면 경고 뜸..? 왠지 모르겠음
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

// 4x4 게임 작동부
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

		// 2048이 만들어졌나 확인
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

			// 스코어 저장하기
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
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(30, 21, 43, score);
		}
		// 여기서 else if로 9칸중에 2048이 된 칸이 있으면 win 화면 띄어줌
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			// 스코어 저장하기
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
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
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
					// ++location_count로 하면 경고 뜸..? 왠지 모르겠음
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

// 5x5 게임 작동부
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

		// 2048이 만들어졌나 확인
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

			// 스코어 저장하기
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
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
					location_count++;
					game_over_box(box_location[location_count]);
					break;
				}
			}
			play_screen(39, 26, 52, score);
		}
		// 여기서 else if로 9칸중에 2048이 된 칸이 있으면 win 화면 띄어줌
		if (is_2048 == 1)
		{
			int box_location[2] = { 6, 18 };
			int location_count = 0;
			int temp_kb;
			system("cls");
			win_screen(score);
			game_over_box(box_location[location_count]);

			// 스코어 저장하기
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
					// 경고	C6385	'box_location'에서 잘못된 데이터를 읽고 있습니다.읽기 가능한 크기는 '8'바이트인데 실제로는 '12'바이트만 읽을 수 있습니다.
					// box_location[++location_count] or box_location[location_count += 1]라고 하면 위의 경고 뜸
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
					// ++location_count로 하면 경고 뜸..? 왠지 모르겠음
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

// 커서 숨김 - 커서 깜빡이는거 없애는 코드
void cursor_view_f()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}