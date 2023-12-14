//-----------------------------------------------------------------------------------------------------
// #name CP11 ネームバトラー
// #description 名前からステータスのパラメーター（体力、攻撃力）を作成し、バトルをするプログラム
// #make 2023/12/01
// #update 2023/12/01
//-----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 関数定義
int battle(); // バトル関数

int main()
{
    battle();
}
int battle()
{
	int	hitpoint_monster;
	int	hitpoint_player;

	int	damage_monster;
	int	damage_player;

	int	command;

	int is_battle;

	is_battle = rand() % 100 + 1;
	if (is_battle <= 50)
	{
        while (1) {
			printf("モンスターが現れた\n");
			//　モンスターの体力を 50 ~ 80 に設定
			hitpoint_monster = rand() % 50 + 30;
			// プレイヤーの体力を 100 に設定
			hitpoint_player = 100;

			printf ("モンスターの体力:%d\n", hitpoint_monster);
			printf ("プレイヤーの体力:%d\n", hitpoint_player);

			while (1) {
				// 攻撃か逃げるかは1と2で選択
				printf ("実行するコマンドを入力してください(1:攻撃,2:逃げる):");
				scanf("%d", &command);

				if (command == 2) {
					printf ("モンスターから逃げました\n");
					break;
				}

				// モンスターの攻撃は 10 ~ 20 の乱数
				damage_monster = rand() % 10 + 10;
				// プレイヤーの攻撃は 10 ~ 30 の乱数
				damage_player = rand() % 20 + 10;

				printf ("プレイヤーの攻撃:%dのダメージ\n", damage_player);
				printf ("モンスターの攻撃:%dのダメージ\n", damage_monster);

				hitpoint_monster -= damage_monster;
				hitpoint_player -= damage_player;

				if (hitpoint_monster <= 0)
					hitpoint_monster = 0;

				if (hitpoint_player <= 0)
					hitpoint_player = 0;
				printf ("モンスターの体力:%d\n", hitpoint_monster);
				printf ("プレイヤーの体力:%d\n\n", hitpoint_player);

				// 勝ち負けの表示
				if (hitpoint_monster <= 0)
				{
					printf ("プレイヤーの勝利!\n");
					printf ("先へ進みます\n\n");
					command = 2;
					break;
				}
				else if (hitpoint_player <= 0)
				{
					printf ("プレイヤーの敗北\n");
					printf ("Game Over...");
					exit(0);
				}
			}
			if (command == 2)
				break;
		}
	}
	return 0;
}