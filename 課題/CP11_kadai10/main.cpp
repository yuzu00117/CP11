//-----------------------------------------------------------------------------------------------------
// #name CP11 バーコードバトラー
// #description バトルプログラムを改良し名前からキャラクターのパラメータを作成する機能を追加する
// #make 2023/11/17
// #update 2023/02/19
// #comment 追加予定機能
//          ・タイトル画面の追加
//          ・キャラクターの複数作成を可能にする
//          ・バトルプログラムの改良
//          　・アイテム、経験値の要素追加
//            ・コマンド選択式にする
//            ・print文字の色分け
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

    // タイトル表示
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
void battle(struct CharacterStats *character)
{
    // キャラクターのステータスは構造体から参照
    
    // エネミーのステータスを定義
    srand((unsigned)time(NULL));
    int enemyHP = rand() % 500 + 200;
    float enemyATK = rand() % 15 + 5;
    float enemyDEF = 3;

    // ターン数
    int turn = 5; // ターン数は任意で変更可能

    // 攻撃計算用
    int characterDMG, enemyDMG;
    int randomDamage; // ダメージのランダム化に使用

    // 5ターン
    for (int i = 0; i < turn; i++)
    {
        // ダメージのランダム化
        srand((unsigned)time(NULL));
        randomDamage = rand() & 3;

        // 攻撃力と防御力の計算
        characterDMG = (character->CharacterATK - enemyDEF) + randomDamage;
        enemyDMG = (enemyATK - character->CharacterDEF) + randomDamage;

        // 戦闘
        printf("------------------\n");
        printf("%sの攻撃：%dのダメージ\n", character->CharacterName, characterDMG);
        character->CharacterHP -= enemyDMG;
        printf("敵の攻撃：%dのダメージ\n", enemyDMG);
        enemyHP -= characterDMG;
        printf("------------------\n");

        // 一秒毎に処理
        Sleep(2000);
        // system("clear");
    }

    printf("ターン終了後の%sのHP：%d\n", character->CharacterName, character->CharacterHP);
    printf("ターン終了後の敵のHP：%d\n", enemyHP);

    if (character->CharacterHP < enemyHP)
    {
        printf("敵の勝利！\n");
    }
    else if (character->CharacterHP > enemyHP)
    {
        printf("プレイヤーの勝利！\n");
    }
}
//-------------------------------------------------------------

//-------------------------------------------------------------
// バーコードの数値をもとにステータスを生成
void GenerateStatusFromBarcode(struct CharacterStats *character, int barcode);

//-------------------------------------------------------------
// キャラ作成関数
void CharacterCreate(struct CharacterStats *character);

//-------------------------------------------------------------