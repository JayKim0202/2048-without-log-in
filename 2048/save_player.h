#pragma once

#ifndef __SAVE_PLAYER__
#define __SAVE_PLAYER__

#include "main.h"
#include "structure.h"

// �÷��̾� �� �о����
int fread_playerNum();

// ���� �Է�
void fwrite_score(int score);

// �÷��̾�, ���� ��ü ��������
Player* fread_allPlayers();

#endif // !__SAVE_PLAYER__