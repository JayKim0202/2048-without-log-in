#pragma once

#ifndef _CHECK_SOMETHING_H__
#define _CHECK_SOMETHING_H__

#include "main.h"
#include "structure.h"

// cmdâ�� �׸�ĭ�� �߽� ��ǥ�� ������ ����ü
typedef struct Grid {
	int x;
	int y;
}Grid;

// ȭ�鿡 ���ڸ� �����
void print_number(int x, int y, int num);

//3x3
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void up3(int number_table[][3], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void down3(int number_table[][3], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void left3(int number_table[][3], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void right3(int number_table[][3], int* score);
// �� á���� Ȯ��
int is_full3(int number_table[][3]);
// �����¿�� ���� ���ڰ� �ִ��� Ȯ��
int is_same3(int number_table[][3]);

//4x4
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void up4(int number_table[][4], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void down4(int number_table[][4], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void left4(int number_table[][4], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void right4(int number_table[][4], int* score);
// �� á���� Ȯ��
int is_full4(int number_table[][4]);
// �����¿�� ���� ���ڰ� �ִ��� Ȯ��
int is_same4(int number_table[][4]);

//5x5
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void up5(int number_table[][5], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void down5(int number_table[][5], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void left5(int number_table[][5], int* score);
// ���� ����Ű�� ������ �� ����Ǵ� �Լ�
void right5(int number_table[][5], int* score);
// �� á���� Ȯ��
int is_full5(int number_table[][5]);
// �����¿�� ���� ���ڰ� �ִ��� Ȯ��
int is_same5(int number_table[][5]);

// ���� ���
Player* calculate_rank(Player* palyer);

// ���� �������� ����
void asc_rank(Player* player, int size);

// top10 �� �߶� ����
Player* cut_10th(Player* player);

#endif // !_CHECK_SOMETHING_H__