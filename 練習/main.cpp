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
    file_p = fopen(file_name, "r+");
    if (file_p == NULL)
    {
        printf("ファイルのオープンに失敗");
        exit(0);
    }
}