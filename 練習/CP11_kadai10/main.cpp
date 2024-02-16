//-----------------------------------------------------------------------------------------------------
// #name CP11 ネームバトラー
// #description バトルプログラムを改良し名前からキャラクターのパラメータを作成する機能を追加する
// #make 2023/11/17
// #update 2023/12/18
// #comment キャラクターのセーブとロードを実装。ルイーダの酒場の機能を追加したい
// バーコードバトラーのようなゲーム感にし、hewに使用
//-----------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct CharacterStats
{
    // 名前、HP、ATKはランダム生成で定義
    char CharacterName[100];
    int CharacterHP;
    int CharacterATK;
    // DEFは固定値で定義
    int CharacterDEF; // ランダム生成に変更予定
};


//-------------------------------------------------------------
// 関数定義

// バトル関数
void battle(struct CharacterStats* character);
// 名前入力
void CharacterCreate(struct CharacterStats* character);
// 名前からステータスを生成
void GenerateRandomValue(struct CharacterStats* character);

//-------------------------------------------------------------



//-------------------------------------------------------------
// ファイルに CharacterStats を保存する関数
void SaveCharacterToFile(const char* filename, struct CharacterStats* character)
{
    FILE* file = fopen(filename, "wb"); // バイナリモードでファイルを開く

    if (file == NULL)
    {
        perror("ファイルを開く際にエラーが発生しました");
        exit(EXIT_FAILURE);
    }
    // ファイルに CharacterStats の内容を書き込む
    fwrite(character, sizeof(CharacterStats), 1, file);

    // ファイルを閉じる
    fclose(file);
}
//-------------------------------------------------------------



//-------------------------------------------------------------
// ファイルから CharacterStats を読み込む関数
void LoadCharacterFromFile(const char* filename, struct CharacterStats* character)
{
    FILE* file = fopen(filename, "rb"); // バイナリモードでファイルを開く

    if (file == NULL)
    {
        perror("ファイルを開く際にエラーが発生しました");
        exit(EXIT_FAILURE);
    }

    // ファイルから CharacterStats の内容を読み込む
    fread(character, sizeof(CharacterStats), 1, file);

    fclose(file);
}
//-------------------------------------------------------------



//-------------------------------------------------------------
// main
int main()
{
    struct CharacterStats character;

    // 新しいキャラクターを作成するかどうかを選択
    char createNewCharacter;
    printf("新しいキャラクターを作成しますか？ (y/n): ");
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
        sleep(2);
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
// キャラ作成関数
void CharacterCreate(struct CharacterStats* character)
{
    // 文字列を格納するための配列を定義
    // struct CharacterStats character; // 不要な行

    // ユーザーに対して入力のプロンプトを表示
    printf("キャラクターの名前を入力してください: ");

    // fgets関数を使用して文字列を入力
    // 第一引数には文字列を格納する配列、第二引数には最大読み込み文字数、第三引数には入力元（通常は標準入力）を指定
    fgets(character->CharacterName, sizeof(character->CharacterName), stdin);

    // fgetsは改行文字も読み込むため、必要な場合は削除する
    // 現在は削除しヌル文字に変換
    int length = strlen(character->CharacterName);
    if (length > 0 && character->CharacterName[length - 1] == '\n')
    {
        character->CharacterName[length - 1] = '\0'; // 改行文字をヌル文字に置き換え
    }

    // 入力された文字列を表示
    printf("入力されたキャラクターの名前: %s\n", character->CharacterName);

    // HPとATKを生成し表示
    GenerateRandomValue(character);

    // CharacterDEFを固定値で代入
    character->CharacterDEF = 3;

    printf("生成されたランダムなHP: %d\n", character->CharacterHP);
    printf("生成されたランダムなATK: %d\n", character->CharacterATK);
}
//-------------------------------------------------------------



//-------------------------------------------------------------
// HPとATKを名前をもとにランダム生成
void GenerateRandomValue(struct CharacterStats* character)
{
    srand((unsigned)time(NULL));

    // CharacterNameをもとにしてランダムなHPとATKを生成
    int seed = 0;
    for (int i = 0; i < strlen(character->CharacterName); i++)
    {
        seed += character->CharacterName[i];
    }
    srand(seed);

    character->CharacterHP = rand() % 500 + 200;
    character->CharacterATK = rand() % 15 + 5;
}
//-------------------------------------------------------------