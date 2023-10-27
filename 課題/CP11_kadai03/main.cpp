//-------------------------------------------------------------------------------------
// #name CP11 kadai03
// #description 暗号化、復号化プログラム
// #make 2023/10/27
//-------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

int main()
{
    // 暗号化プログラム

    char angou[32] = "";
    char *p_char = NULL;

    // 暗号化する文章
    strcpy(angou, "Hello World!");

    p_char = angou;

    // 暗号化前の文章を印字
    printf("--------------------------------\n");
    printf("暗号化前\n");
    printf("%s\n", angou);

    // 暗号化
    while (*p_char != '\0')
    {
        (*p_char) += 1;

        p_char++;
    }
    
    // 暗号化後の文章を印字
    printf("暗号化後\n");
    printf("%s\n", angou);
    printf("--------------------------------\n");

    // 復号化
    p_char = angou;

    // 複合化前の文章を印字
    printf("複合化前\n");
    printf("%s\n", angou);

    // 復号化
    while (*p_char != '\0')
    {
        (*p_char) -= 1;

        p_char++;
    }

    // 復号化後の文章を印字
    printf("復号化後\n");
    printf("%s\n", angou);
    printf("--------------------------------\n");

    return 0;
}