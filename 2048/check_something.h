#pragma once

#ifndef _CHECK_SOMETHING_H__
#define _CHECK_SOMETHING_H__

#include "main.h"
#include "structure.h"

// cmd창의 네모칸의 중심 좌표를 저장할 구조체
typedef struct Grid {
	int x;
	int y;
}Grid;

// 화면에 숫자를 출력함
void print_number(int x, int y, int num);

//3x3
// ↑이 방향키를 눌렀을 때 실행되는 함수
void up3(int number_table[][3], int* score);
// ↓이 방향키를 눌렀을 때 실행되는 함수
void down3(int number_table[][3], int* score);
// ←이 방향키를 눌렀을 때 실행되는 함수
void left3(int number_table[][3], int* score);
// →이 방향키를 눌렀을 때 실행되는 함수
void right3(int number_table[][3], int* score);
// 꽉 찼는지 확인
int is_full3(int number_table[][3]);
// 상하좌우로 같은 숫자가 있는지 확인
int is_same3(int number_table[][3]);

//4x4
// ↑이 방향키를 눌렀을 때 실행되는 함수
void up4(int number_table[][4], int* score);
// ↓이 방향키를 눌렀을 때 실행되는 함수
void down4(int number_table[][4], int* score);
// ←이 방향키를 눌렀을 때 실행되는 함수
void left4(int number_table[][4], int* score);
// →이 방향키를 눌렀을 때 실행되는 함수
void right4(int number_table[][4], int* score);
// 꽉 찼는지 확인
int is_full4(int number_table[][4]);
// 상하좌우로 같은 숫자가 있는지 확인
int is_same4(int number_table[][4]);

//5x5
// ↑이 방향키를 눌렀을 때 실행되는 함수
void up5(int number_table[][5], int* score);
// ↓이 방향키를 눌렀을 때 실행되는 함수
void down5(int number_table[][5], int* score);
// ←이 방향키를 눌렀을 때 실행되는 함수
void left5(int number_table[][5], int* score);
// →이 방향키를 눌렀을 때 실행되는 함수
void right5(int number_table[][5], int* score);
// 꽉 찼는지 확인
int is_full5(int number_table[][5]);
// 상하좌우로 같은 숫자가 있는지 확인
int is_same5(int number_table[][5]);

// 순위 계산
Player* calculate_rank(Player* palyer);

// 순위 오름차순 정렬
void asc_rank(Player* player, int size);

// top10 만 잘라서 리턴
Player* cut_10th(Player* player);

#endif // !_CHECK_SOMETHING_H__