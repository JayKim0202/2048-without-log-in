#pragma once

#ifndef __SAVE_PLAYER__
#define __SAVE_PLAYER__

#include "main.h"
#include "structure.h"

// 플레이어 수 읽어오기
int fread_playerNum();

// 점수 입력
void fwrite_score(int score);

// 플레이어, 점수 전체 가져오기
Player* fread_allPlayers();

#endif // !__SAVE_PLAYER__