//-------------------------------------------------------------------------------------
// #name CP11 kadai03
// #description �Í����A�������v���O����
// #make 2023/10/27
//-------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // �Í����v���O����

    char angou[32] = "";
    char *p_char = NULL;

    srand((unsigned int)time(NULL));
    int rand_num = rand();

    // �Í������镶��
    strcpy(angou, "Hello World!");

    p_char = angou;

    // �Í����O�̕��͂���
    printf("--------------------------------\n");
    printf("�Í����O\n");
    printf("%s\n", angou);

    // �Í���
    while (*p_char != '\0')
    {
        (*p_char) += rand_num;

        p_char++;
    }
    
    // �Í�����̕��͂���
    printf("�Í�����\n");
    printf("%s\n", angou);
    printf("--------------------------------\n");

    // ������
    p_char = angou;

    // �������O�̕��͂���
    printf("�������O\n");
    printf("%s\n", angou);

    // ������
    while (*p_char != '\0')
    {
        (*p_char) -= rand_num;

        p_char++;
    }

    // ��������̕��͂���
    printf("��������\n");
    printf("%s\n", angou);
    printf("--------------------------------\n");

    return 0;
}