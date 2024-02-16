// =============================================================================
// 
// アクションゲームサンプル [main.cpp]
// 
// 制作者：			日付：2024/02/02
// =============================================================================
#include "main.h"
#include "conioex.h"
#include "scene.h"


// *****************************************************************************
// マクロ定義
// *****************************************************************************


// *****************************************************************************
// プロトタイプ宣言
// *****************************************************************************
#ifdef _DEBUG
void DispFPS(void);
#endif
void WindowConsoleInitialize(void);


// *****************************************************************************
// グローバル変数
// *****************************************************************************
int CountFps;				// FPSカウンタ

int clearFlag = 0;


// =============================================================================
//  メイン関数
// =============================================================================
int main(void)
{
	int ExecLastTime;
	int FPSLastTime;
	int CurrentTime;
	int FrameCount;

	// 画面をクリア
	clrscr();

	// カーソル非表示
	setcursortype(NOCURSOR);

	// 分解能を設定
	timeBeginPeriod(1);

	ExecLastTime = 
	FPSLastTime = timeGetTime();
	CurrentTime =
	FrameCount = 0;

	// ウィンドウ設定の初期化（HEW用設定）
	WindowConsoleInitialize();


	//ゲーム初期化処理
	SceneInit();


	// ゲームメイン処理
	do
	{
		CurrentTime = timeGetTime();
		if((CurrentTime - FPSLastTime) >= 500)	// 0.5秒ごとに実行
		{
			CountFps = FrameCount * 1000 / (CurrentTime - FPSLastTime);
			FPSLastTime = CurrentTime;
			FrameCount = 0;
		}

		if((CurrentTime - ExecLastTime) >= (1000 / 60))	// 60fpsでフレーム管理
		{
			ExecLastTime = CurrentTime;

			// ゲーム更新処理
			SceneUpdate();//g_SceneがTITLEならタイトル画面が動く
						  //         GAMEだったらゲーム本編が動く 

			// ゲーム描画処理
			SceneDraw();

#ifdef _DEBUG
			// FPS表示
			DispFPS();
#endif
			//移行先シーンがあるかをチェックする
			CheckScene();

			FrameCount++;
		}
	} while(!inport(PK_ESC));

	// 分解能を戻す
	timeEndPeriod(1);

	// 画面をクリア
	clrscr();
	// カーソル表示
	setcursortype(NORMALCURSOR);

	printf("Enterキーで終了します\n");
	rewind(stdin);
	getchar();

	return 0;
}

#ifdef _DEBUG
// =============================================================================
// FPS表示
// =============================================================================
void DispFPS(void)
{
	// 色設定
	textcolor(WHITE);

	gotoxy(1, 1);
	printf("FPS:%d", CountFps);
}
#endif

// =============================================================================
// ウィンドウ設定の初期化（HEW用設定）
// =============================================================================
void WindowConsoleInitialize(void)
{
	// Set console window position
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// Set console window size
	SMALL_RECT windowSize = { 0, 0, 80, 25 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

	// Set console buffer size
	// ウィンドウサイズは80, 25で固定すること
	COORD coord;
	coord.X = 80;
	coord.Y = 25;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	// Set console font style and size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	// ↓フォントサイズのみ変更可↓
	cfi.dwFontSize.X = 15;                   // Width of each character in the font
	cfi.dwFontSize.Y = 30;                   // Height
	// ↑フォントサイズのみ変更可↑
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"MS Gothic");       // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int floatToInt(float f)
{
	return (int)(f + 0.5f);
}

//クリアフラグのセット
void SetClearFlag(int flag)
{
	clearFlag = flag;
}

//クリアフラグのゲット
int GetClearFlag(void)
{
	return clearFlag;
}

//ファイルを追加する
//explosion.cpp, explosion.h
