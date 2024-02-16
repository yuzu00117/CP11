#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "screen.h"
#include "conioex.h"

DWORD g_Mode_default;


int main(void)
{
	//※ゲームの初期化時に画面サイズを変更する
	//ScreenInit関数
	//第1引数 画面横サイズ
	//第2引数 画面縦サイズ
	//第3引数 フォントサイズ（6～24の間で設定可能）
	ScreenInit(120, 30, 20);

	const HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &g_Mode_default);
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);

	printf("ここでゲーム実行\n");

	while(1)
	{

		int x = inport(PM_CURX);
		int y = inport(PM_CURY);

		printf("X:%3d, Y:%3d\n", x, y);

		Sleep(1);
	}
	// getchar();

	SetConsoleMode(hStdin, g_Mode_default);

	//※ゲームの終了時にウィンドウサイズ、フォントサイズの設定を実行前の状態に復元する
	//ScreenEnd関数
	ScreenEnd();

	return 0;
}
