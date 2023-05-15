#pragma once

#ifndef __RUN_H__
#define __RUN_H__

#include "main.h"

// Ű �ڵ�
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER '\r'

// Ŀ�� ������
void cursor_view_f();
void cursor_view_t();

// ����ȭ�� �۵���
void run_starting_screen();

// ���ȭ�� �۵���
void run_mode_screen();

// 3x3 ���� �۵���
void run_real_game3();

// 4x4 ���� �۵���
void run_real_game4();

// 5x5 ���� �۵���
void run_real_game5();

// Ŀ�� ����
void cursor_view_f();

#endif // !__RUN_H__
