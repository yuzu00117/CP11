#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char file_name[40];
    FILE *file_p;

    printf("ファイル名を入力\n");
    scanf("%s", file_name);

    // ファイル読み込み設定でオープンする
    // オープン成功→file_pにアドレスが入る
    // オープン失敗（ファイルが存在しない）→file_pにNULLが入る
    file_p = fopen(file_name, "wt");
    if (file_p == NULL)
    {
        printf("ファイルのオープンに失敗");
        exit(0);
    }

    putc('H', file_p);

    /*

    // ファイルの読み書き
    char text;
    while (text != EOF)
    {
        text = getc(file_p);
        printf("%c", text);
    }

    */

    // ファイルをクローズ
    if (fclose(file_p) == EOF)
    {
        printf("ファイルのクローズに失敗");
        exit(0);
    }
    return 0;
}
