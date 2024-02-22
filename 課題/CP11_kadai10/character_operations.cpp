// character_operations.cpp
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_operations.h"
#include "character_operations.h"
#include "character.h"

//-------------------------------------------------------------
// キャラクター作成
int askForCharacterCreation(struct CharacterStats *character)
{
    // 新しいキャラクターを作成するかどうかを選択

    // ユーザーからの入力(y/n)を格納する変数
    char createNewCharacter;

    printf("新しいキャラクターを作成しますか？ (y/n): \n");
    printf("※保存してあるキャラクターは削除されます");

    // ユーザー入力(y/n)
    rewind(stdin);
    scanf("%c", &createNewCharacter);

    if (createNewCharacter == 'y' || createNewCharacter == 'Y')
    {
        rewind(stdin);
        // 新しいキャラクターを作成
        CharacterCreate(character);
        // ファイルに保存
        SaveCharacterToFile("character.dat", character);
    }
    else if (createNewCharacter == 'n' || createNewCharacter == 'N')
    {
        LoadCharacterFromFile("character.dat", character);

        // 読み込まれたデータの表示
        printf("読み込まれたキャラクターの名前: %s\n", character->CharacterName);
        printf("読み込まれたキャラクターのHP: %d\n", character->CharacterHP);
        printf("読み込まれたキャラクターのATK: %d\n", character->CharacterATK);
        printf("読み込まれたキャラクターのDEF: %d\n", character->CharacterDEF);
    }
    else
    {
        printf("正しい入力を行って下さい。\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

//-------------------------------------------------------------
// バーコードの数値をもとにステータスを生成
void GenerateStatusFromBarcode(struct CharacterStats *character, int barcode)
{
    // バーコード番号をもとにランダムなHPとATKを生成
    srand(barcode);
    character->CharacterHP = rand() % 500 + 200;
    character->CharacterATK = rand() % 15 + 5;

    printf("バーコードから生成されたHP: %d\n", character->CharacterHP);
    printf("バーコードから生成されたATK: %d\n", character->CharacterATK);
}
//-------------------------------------------------------------

//-------------------------------------------------------------
// キャラ作成関数
void CharacterCreate(struct CharacterStats *character)
{
    int barcode;

    // ユーザーからのキャラクター名入力
    printf("キャラクター名を入力してください: ");

    // fgets関数を使用して文字列を入力
    // 第一引数には文字列を格納する配列、第二引数には最大読み込み文字数、第三引数には入力元（通常は標準入力）を指定
    fgets(character->CharacterName, sizeof(character->CharacterName), stdin);

    // 改行文字が含まれている場合、改行文字をヌル文字に置き換える
    char *newline = strchr(character->CharacterName, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
    else
    {
        // バッファが溢れて余分な文字が残っている可能性があるため、不要な文字をクリアする
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // ユーザーからのバーコード入力
    printf("バーコードの数値を入力してください: ");
    scanf("%d", &barcode);

    // 改行文字をクリア
    getchar();

    // バーコードからステータスを生成
    GenerateStatusFromBarcode(character, barcode);

    // characterDEFを固定値で代入
    // ※※※　DEFもランダムで生成できるように変更予定
    character->CharacterDEF = 3;
}