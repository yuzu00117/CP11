//-----------------------------------------------------------------------------------------------------
// #name CP11 ネームバトラー
// #description バトルプログラムを改良し名前からキャラクターのパラメータを作成する機能を追加する
// #make 2023/11/17
// #update 2023/12/18
// #comment キャラクターのセーブとロードを実装。ルイーダの酒場の機能を追加したい
// バーコードバトラーのようなゲーム感にし、hewに使用
//-----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "file_operations.h"

//-------------------------------------------------------------
// 関数定義

// バトル関数
void battle(struct CharacterStats* character);

// バーコードの数値をもとにステータスを生成
void GenerateStatusFromBarcode(struct CharacterStats* character, int barcode);

// キャラ作成関数
void CharacterCreate(struct CharacterStats* character);
//-------------------------------------------------------------



//-------------------------------------------------------------
// ファイルに CharacterStats を保存する関数
void SaveCharacterToFile(const char* filename, struct CharacterStats* character);
//-------------------------------------------------------------

//-------------------------------------------------------------
// ファイルから CharacterStats を読み込む関数
void LoadCharacterFromFile(const char* filename, struct CharacterStats* character);
//-------------------------------------------------------------



//-------------------------------------------------------------
// main
int main()
{
    struct CharacterStats character;

    // 新しいキャラクターを作成するかどうかを選択
    char createNewCharacter;
    printf("新しいキャラクターを作成しますか？ (y/n): \n");
    printf("※保存してあるキャラクターは削除されます");
    scanf("%c", &createNewCharacter);

    if (createNewCharacter == 'y' || createNewCharacter == 'Y')
    {
        rewind(stdin);
        // 新しいキャラクターを作成
        CharacterCreate(&character);
        // ファイルに保存
        SaveCharacterToFile("character.dat", &character);
    }
    else if (createNewCharacter == 'n' || createNewCharacter == 'N')
    {
        LoadCharacterFromFile("character.dat", &character);

        // 読み込まれたデータの表示
        printf("読み込まれたキャラクターの名前: %s\n", character.CharacterName);
        printf("読み込まれたキャラクターのHP: %d\n", character.CharacterHP);
        printf("読み込まれたキャラクターのATK: %d\n", character.CharacterATK);
        printf("読み込まれたキャラクターのDEF: %d\n", character.CharacterDEF);

        // バトル実行
        battle(&character);
    }
    else {
        printf("正しい入力を行って下さい。\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------



//-------------------------------------------------------------
// バトルプログラム
// キャラクターとエネミーのバトル
// 5ターン 経過後の互いのHPを表示
void battle(struct CharacterStats* character)
{
    // キャラクターのステータスは構造体から参照

    // エネミーのステータスを定義
    int enemyHP = rand() % 500 + 200;
    float enemyATK = rand() % 15 + 5;
    float enemyDEF = 3;

    // ターン数
    int turn = 5; // ターン数は任意で変更可能

    // 攻撃計算用
    int characterDMG, enemyDMG;

    // 5ターン
    for (int i = 0; i < turn; i++)
    {
        // ダメージを乱数で生成
        // ダメージは任意で変更可能
        characterDMG = rand() % 21;
        enemyDMG = rand() % 21;

        // 攻撃力と防御力の計算
        characterDMG *= (character->CharacterATK - enemyDEF);
        enemyDMG *= (enemyATK - character->CharacterDEF);

        // 戦闘
        printf("------------------\n");
        printf("%sの攻撃：%dのダメージ\n", character->CharacterName, characterDMG);
        character->CharacterHP -= enemyDMG;
        printf("敵の攻撃：%dのダメージ\n", enemyDMG);
        enemyHP -= characterDMG;
        printf("------------------\n");

        // 一秒毎に処理
        Sleep(2000);
        //system("clear");
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
void GenerateStatusFromBarcode(struct CharacterStats* character, int barcode);

//-------------------------------------------------------------
// キャラ作成関数
void CharacterCreate(struct CharacterStats* character);

//-------------------------------------------------------------