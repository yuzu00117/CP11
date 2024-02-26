//-----------------------------------------------------------------------------------------------------
// #name CP11 バーコードバトラー
// #description バトルプログラムを改良し名前からキャラクターのパラメータを作成する機能を追加する
// #make 2023/11/17
// #update 2023/02/19
// #comment 追加予定機能
//          ・キャラクターの複数作成を可能にする
//          ・バトルプログラムの改良
//          　・アイテム、経験値の要素追加
//            ・コマンド選択式にする
//            ・print文字の色分け(半分完了)
//----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "file_operations.h"
#include "character_operations.h"
#include "character.h"
#include "title_screen.h"
#include "battle.h"
//-------------------------------------------------------------
// 関数定義

// バトル関数
void battle(struct CharacterStats *character);
//-------------------------------------------------------------

//-------------------------------------------------------------
// キャラクターのロード、保存

// ファイルに CharacterStats を保存
void SaveCharacterToFile(const char *filename, struct CharacterStats *character);


// ファイルから CharacterStats を読み込む
void LoadCharacterFromFile(const char *filename, struct CharacterStats *character);
//-------------------------------------------------------------

//-------------------------------------------------------------
// main
int main()
{
    // キャラクターの構造体
    struct CharacterStats character;

    // タイトル画面の表示
    displayTitleScreen();

    // キャラクターを作成するかどうか
    askForCharacterCreation(&character);

    // バトル実行
    battle(&character);
}

//-------------------------------------------------------------

//-------------------------------------------------------------
// バトルプログラム
// キャラクターとエネミーのバトル
// 5ターン 経過後の互いのHPを表示

//-------------------------------------------------------------

//-------------------------------------------------------------
// バーコードの数値をもとにステータスを生成
void GenerateStatusFromBarcode(struct CharacterStats *character, int barcode);

//-------------------------------------------------------------
// キャラ作成関数
void CharacterCreate(struct CharacterStats *character);

//-------------------------------------------------------------