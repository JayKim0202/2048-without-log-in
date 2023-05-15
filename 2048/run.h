#pragma once

#ifndef __RUN_H__
#define __RUN_H__

#include "main.h"

// 키 코드
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define ENTER '\r'

// 커서 깜빡임
void cursor_view_f();
void cursor_view_t();

// 시작화면 작동부
void run_starting_screen();

// 모드화면 작동부
void run_mode_screen();

// 3x3 게임 작동부
void run_real_game3();

// 4x4 게임 작동부
void run_real_game4();

// 5x5 게임 작동부
void run_real_game5();

// 커서 숨김
void cursor_view_f();

#endif // !__RUN_H__
