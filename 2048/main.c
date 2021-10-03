#include "main.h"

int main()
{
	// 숫자들의 위치를 랜덤을 선언하기 위해 시드를 바꿔줌
	srand((unsigned)time(NULL));
	// 커서의 반짝임을 지워줌
	cursor_view_f();
	// 시작 화면
	run_starting_screen();
}