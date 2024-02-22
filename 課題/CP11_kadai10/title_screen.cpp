#include "title_screen.h"

// タイトル画面の表示
void displayTitleScreen()
{
    // タイトル画面の表示内容を記述
    /*
    printf("=== タイトル画面 ===\n");
    printf("1. 新しいゲームを始める\n");
    printf("2. 以前のゲームを続ける\n");
    printf("3. ゲームを終了する\n");
    */
   	printf("***********************************\n");
	printf("*          タイトル画面           *\n");
	printf("***********************************\n");

    getchar();
}

// ユーザー入力の処理
// ※使用しない
void handleUserInput()
{
    printf("入力してください\n");

    // ユーザーの入力を格納する変数
    int choice;
    scanf("%d", choice);

    // 入力された選択肢に応じて処理を行う
    switch (choice)
    {
    case 1:
        printf("新しいゲームを始めます\n");
        break;
    case 2:
        printf("以前のゲームを続けます\n");
    case 3:
        printf("ゲームを終了します\n");
    default:
        printf("無効な選択です\n");
        break;
    }
}