//-----------------------------------------------------------------------------------------------------
// #name CP11 ルイーダの酒場改良版
// #description ルイーダの酒場にセーブとロード機能を追加する
// #make 2023/11/17
// #update 2023/11/17
//-----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// キャラクターデータ
struct CHARACTER_DATA
{
    char Name[128]; // 名前
    int HP;         // ヘルス
    int AD;         // 攻撃力
};

// 関数宣言
void ViewList(CHARACTER_DATA *pCharaData);          // キャラクターリスト表示
void CharacterView(CHARACTER_DATA *pCharaData);     // キャラクター閲覧
void CharacterCreate(CHARACTER_DATA *pCharaData);   // キャラクター作成
void CharacterDelete(CHARACTER_DATA *pCharaData);   // キャラクター削除
void CharacterSave(CHARACTER_DATA *pCharaData);     // キャラクター保存
void CharacterLoad(CHARACTER_DATA *pCharaData);     // キャラクター読み込み
int main()
{
    CHARACTER_DATA *p;

    // キャラクターの保存は10人まで
    int data_size = 10;
    p = (CHARACTER_DATA *)malloc(sizeof(CHARACTER_DATA) * data_size);

    // 初期化
    CHARACTER_DATA CharaData[10] = {};

    // キャラクターの読み込み
    CharacterLoad(CharaData);

    // TestCharacter 1
    strcpy(CharaData[0].Name, "Chara1");
    CharaData[0].HP = 100;
    CharaData[0].AD = 50;

    // TestCharacter 2
    strcpy(CharaData[1].Name, "Chara2");
    CharaData[1].HP = 200;
    CharaData[1].AD = 100;

    // TestCharacter 6
    strcpy(CharaData[5].Name, "Chara6");
    CharaData[5].HP = 500;
    CharaData[5].AD = 250;

    printf("---------------------------\n");
    printf("ギルガメッシュの酒場\n");
    printf("---------------------------\n");

    while (1)
    {
        printf("何をしますか\n\n");
        printf("1, キャラクターの閲覧\n");
        printf("2, キャラクターの作成\n");
        printf("3, キャラクターの削除\n");
        printf("4, キャラクターの保存\n");
        printf("5, 終了\n");

        int Select;
        scanf("%d", &Select);

        switch (Select)
        {
        case 1:
            CharacterView(CharaData); // CharaData の先頭アドレスを関数に渡す
            rewind(stdin);
            break;
        case 2:
            CharacterCreate(CharaData);
            rewind(stdin);
            break;
        case 3:
            CharacterDelete(CharaData);
            rewind(stdin);
            break;
        case 4:
            CharacterSave(CharaData);
            rewind(stdin);
            break;
        case 5:
            printf("終了します\n");
            exit(0);
            rewind(stdin);
            break;
        default:
            printf("正しい数字を入力してください\n");
            rewind(stdin);
            break;
        }
    }
    return 0;
}
//-------------------------------------------------------------------------------------
// リスト表示
void ViewList(CHARACTER_DATA *pCharaData)
{
    for (int i = 0; i < 10; i++)
    {
        char temp_str[256] = "";
        // 登録ナンバーの表示
        sprintf(temp_str, "%2d, ", i + 1);
        // 名前の表示
        strcat(temp_str, pCharaData[i].Name);
        printf("%s\n", temp_str);
    }
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// キャラクターデータの閲覧
void CharacterView(CHARACTER_DATA *pCharaData)
{
    // キャラクター閲覧
    ViewList(pCharaData);
    // キー入力
    printf("どのキャラクターを閲覧しますか\n");
    int Select = 0;
    scanf("%d", &Select);
    rewind(stdin);

    printf("Name : %s\n", pCharaData[Select - 1].Name);
    printf("HP   : %d\n", pCharaData[Select - 1].HP);
    printf("AD   : %d\n", pCharaData[Select - 1].AD);

    printf("キーを押して続行\n");
    getchar();
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// キャラクターデータの作成
void CharacterCreate(CHARACTER_DATA *pCharaData)
{
    // キャラクター閲覧
    ViewList(pCharaData);
    // キー入力
    printf("どの場所に作成しますか\n");
    int Select = 0;
    scanf("%d", &Select);
    rewind(stdin);

    printf("名前を設定してください：");
    scanf("%s", &pCharaData[Select - 1].Name);
    rewind(stdin);
    printf("HPを設定してください：");
    scanf("%d", &pCharaData[Select - 1].HP);
    rewind(stdin);
    printf("攻撃力を設定してください：");
    scanf("%d", &pCharaData[Select - 1].AD);
    rewind(stdin);

    printf("キャラクターを作成しました\n");
    printf("キーを押して続行\n");
    getchar();
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// キャラクターデータの削除
void CharacterDelete(CHARACTER_DATA *pCharaData)
{
    // キャラクター閲覧
    ViewList(pCharaData);
    // キー入力
    printf("どのキャラクターを削除しますか\n");
    int Select = 0;
    scanf("%d", &Select);
    rewind(stdin);

    strcpy(pCharaData[Select - 1].Name, "");
    pCharaData[Select - 1].HP = 0;
    pCharaData[Select - 1].AD = 0;

    printf("キーを押して続行\n");
    getchar();
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// キャラクターのセーブ
void CharacterSave(CHARACTER_DATA *pCharaData)
{
    FILE *file_p = NULL;

    file_p = fopen("characters.dat", "wb");

    //
    if (file_p == NULL)
    {
        printf("ファイルのオープンに失敗\n");
        exit(0);
    }

    fwrite(pCharaData, sizeof(CHARACTER_DATA), 10, file_p);

    fclose(file_p);

    printf("キャラクターデータを保存しました\n");
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// キャラクターのロード
void CharacterLoad(CHARACTER_DATA *pCharaData)
{
    FILE *file_p = NULL;

    file_p = fopen("characters.dat", "rb");

    if (file_p == NULL)
    {
        printf("ファイルのオープンに失敗\n");
        exit(0);
    }

    fread(pCharaData, sizeof(CHARACTER_DATA), 10, file_p);

    fclose(file_p);

    printf("キャラクターデータを読み込みしました\n");
}