
#include <stdio.h>

#define CONIOEX	//main.cpp以外でconioex.hをインクルードするときは上にこれを入れる
#include "conioex.h"

#include "scene.h"


void TitleInit(void)
{

}

void TitleUninit(void)
{

}

void TitleUpdate(void)
{
	//エンターキーが押されたら
	if (inport(PK_ENTER))
	{
		//シーンをゲーム本編へ切り替える
		SetScene(SCENE_GAME);
	}
}

void TitleDraw(void)
{
	gotoxy(1, 1);

	printf("***********************************\n");
	printf("*          タイトル画面           *\n");
	printf("***********************************\n");
}
