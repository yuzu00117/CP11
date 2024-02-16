
#include <stdio.h>

#define CONIOEX	//main.cpp以外でconioex.hをインクルードするときは上にこれを入れる
#include "conioex.h"

#include "scene.h"

#include "player.h"
#include "main.h"


void GameInit(void)
{
	PlayerInit();
}

void GameUninit(void)
{
	PlayerUninit();
}

void GameUpdate(void)
{
	PlayerUpdate();
}

void GameDraw(void)
{
	PlayerDraw();
}
