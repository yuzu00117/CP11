
#define	CONIOEX
#include <windows.h>
#include <stdio.h>


//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define FONT_MIN		6		// 最小フォントサイズ
#define FONT_MAX		24		// 最大フォントサイズ

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
static void set_font_size(int font_size);
static void set_window_size(int width, int height);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static HANDLE						stdout_h;	// 標準出力のハンドル値用
static CONSOLE_FONT_INFOEX			save_font;	// フォント情報退避用
static CONSOLE_SCREEN_BUFFER_INFO	save_screen;// 画面/バッファ情報退避用

static int		ScreenWidth;		// 調整後の画面幅
static int		ScreenHeight;		// 調整後の画面高さ


//===================================================================
// 内部関数：指定したフォントサイズに設定する(横サイズは1/2)
//===================================================================
static void set_font_size(int font_size)
{
	CONSOLE_FONT_INFOEX	font;	// フォントサイズ変更用

	if (font_size < FONT_MIN) {
		printf("%dは範囲外のため%dに変更\n", font_size, FONT_MIN);
		font_size = FONT_MIN;
	}
	else if (font_size > FONT_MAX) {
		printf("%dは範囲外のため%dに変更\n", font_size, FONT_MAX);
		font_size = FONT_MAX;
	}

	font = save_font;
	font.dwFontSize.X = font_size / 2;	// 横ピクセル値はフォントサイズの半分
	font.dwFontSize.Y = font_size;		// 縦ピクセル値はフォントサイズと同じ
	if (!SetCurrentConsoleFontEx(stdout_h, FALSE, &font)) {
		printf("SetCurrentConsoleFontExでエラーが発生しました\n");
	}
}
//===================================================================
// 内部関数：指定した画面サイズを設定する
// ※ バッファサイズが大きいと動きが遅くなるため、
// 　 バッファサイズは画面サイズと同じにする(画面サイズが最小サイズ)
// (注)SetConsoleWindowInfoは、以下の場合にエラーになる
//    ・バッファサイズより大きな画面サイズを指定した
//    ・最大バッファサイズより大きな画面サイズを指定した
//===================================================================
static void set_window_size(int width, int height)
{
	CONSOLE_SCREEN_BUFFER_INFO	now;	// 画面の現状値入手用
	SMALL_RECT					screen;	// 画面サイズ変更用
	COORD						coord;	// バッファサイズ変更用
	DWORD						error;

	// バッファサイズを指定された画面サイズと同じ大きさにする
	coord.X = width;
	coord.Y = height;
	if (!SetConsoleScreenBufferSize(stdout_h, coord)) {
		//printf("SetConsoleScreenBufferSizeでエラーが発生しました\n");
		error = GetLastError();
	}

	// 指定値が最大画面サイズより大きい場合、最大画面サイズに変更
	GetConsoleScreenBufferInfo(stdout_h, &now);		// 現状値を入手
	screen.Left = screen.Top = 0;
	screen.Right = ((width > now.dwMaximumWindowSize.X) ?
		now.dwMaximumWindowSize.X : (SHORT)(width)) - 1;
	screen.Bottom = ((height > now.dwMaximumWindowSize.Y) ?
		now.dwMaximumWindowSize.Y : (SHORT)(height)) - 1;

	ScreenWidth = screen.Right + 1;	// 他モジュールからの問い合わせ用に記録
	ScreenHeight = screen.Bottom + 1;

	if (!SetConsoleWindowInfo(stdout_h, TRUE, &screen)) {
		printf("SetConsoleWindowInfoでエラーが発生しました\n");
	}
}

void ScreenInit(int width, int height, int fontsize)
{
	stdout_h = GetStdHandle(STD_OUTPUT_HANDLE);	// 標準出力ハンドルをセット

	GetConsoleScreenBufferInfo(stdout_h, &save_screen);	// 現画面情報を退避

	save_font.cbSize = sizeof(save_font);
	GetCurrentConsoleFontEx(stdout_h, FALSE, &save_font);// 現フォント情報を退避

	set_window_size(width, height);

	set_font_size(fontsize);
}

void ScreenEnd(void)
{
	COORD		coord;	// バッファ変更用
	SMALL_RECT	screen;	// 画面サイズ変更用

	// 退避していたバッファサイズに戻す
	coord.X = save_screen.dwSize.X;
	coord.Y = save_screen.dwSize.Y;
	SetConsoleScreenBufferSize(stdout_h, coord);

	// 退避していた画面サイズに戻す
	screen.Left = screen.Top = 0;
	screen.Right = save_screen.srWindow.Right;
	screen.Bottom = save_screen.srWindow.Bottom;
	SetConsoleWindowInfo(stdout_h, TRUE, &screen);

	// 退避していたフォントサイズに戻す
	SetCurrentConsoleFontEx(stdout_h, FALSE, &save_font);
}
