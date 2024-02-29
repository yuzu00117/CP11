#include "battle.h"

#include "Console_color.h"

void battle(struct CharacterStats *character)
{
    // キャラクターのステータスは構造体から参照
    
    // エネミーのステータスを定義
    srand((unsigned)time(NULL));
    int enemyHP = rand() % 100 + 50;
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
        // キャラクターの行動
        // キャラクター名を色分け
        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY); // 緑色
        printf("%s", character->CharacterName);
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("の攻撃：%dのダメージ\n",characterDMG);
        character->CharacterHP -= enemyDMG;

        // エネミーの行動
        // エネミーの名前を色分け
        setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // 赤色
        printf("Enemy");
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("の攻撃：%dのダメージ\n", enemyDMG);
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
