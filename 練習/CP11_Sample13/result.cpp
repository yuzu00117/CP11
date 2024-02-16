
#include <stdio.h>

#define CONIOEX	//main.cpp以外でconioex.hをインクルードするときは上にこれを入れる
#include "conioex.h"

#include "scene.h"
#include "main.h"


void ResultInit(void)
{

}

void ResultUninit(void)
{

}

void ResultUpdate(void)
{
	//バックスペースキーが押されたら
	if (inport(PK_BS))
	{
		//シーンをタイトル画面へ切り替える
		SetScene(SCENE_TITLE);
	}
}

void ResultDraw(void)
{
	gotoxy(1, 1);

	if (GetClearFlag() == 1)
	{
		printf("***********************************\n");
		printf("*          ゲームオーバー         *\n");
		printf("***********************************\n");
	}
	else
	{
		printf("***********************************\n");
		printf("*             クリア！            *\n");
		printf("***********************************\n");
	}
}
