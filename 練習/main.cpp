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
    file_p = fopen(file_name, "r+");
    if (file_p == NULL)
    {
        printf("�t�@�C���̃I�[�v���Ɏ��s");
        exit(0);
    }
}