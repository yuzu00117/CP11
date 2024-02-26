#include <stdio.h>
#include <time.h>

int main() {
    printf("1分間のタイマーを起動します...\n");

    time_t start_time = time(NULL); // 現在時刻を取得
    time_t elapsed_time = 0; // 経過時間を保持する変数

    while (elapsed_time < 60) { // 60秒（1分）経過するまでループ
        time_t current_time = time(NULL); // 現在時刻を取得
        elapsed_time = current_time - start_time; // 経過時間を計算

        // 経過時間が偶数秒のときのみprintf
        if (elapsed_time % 2 == 0) {
            printf("経過時間: %ld秒\n", elapsed_time);
        }

        // 経過時間が1秒増えるのを待つ
        while (time(NULL) == current_time) {
            // 次の秒までループ
        }
    }

    printf("1分経過しました。\n");
    return 0;
}