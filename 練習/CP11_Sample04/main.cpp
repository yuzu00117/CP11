#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char file_name[40];
    FILE *file_p;

    printf("�t�@�C���������\n");
    scanf("%s", file_name);

    // �t�@�C���ǂݍ��ݐݒ�ŃI�[�v������
    // �I�[�v��������file_p�ɃA�h���X������
    // �I�[�v�����s�i�t�@�C�������݂��Ȃ��j��file_p��NULL������
    file_p = fopen(file_name, "wt");
    if (file_p == NULL)
    {
        printf("�t�@�C���̃I�[�v���Ɏ��s");
        exit(0);
    }

    putc('H', file_p);

    /*

    // �t�@�C���̓ǂݏ���
    char text;
    while (text != EOF)
    {
        text = getc(file_p);
        printf("%c", text);
    }

    */

    // �t�@�C�����N���[�Y
    if (fclose(file_p) == EOF)
    {
        printf("�t�@�C���̃N���[�Y�Ɏ��s");
        exit(0);
    }
    return 0;
}
