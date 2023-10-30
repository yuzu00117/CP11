//-------------------------------------------------------------------------------------
// #name CP11 Sample03
// #description sizeof, typedef �̗��K
// #make 2023/10/20
//-------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

// int typedef
typedef int INT2; // �^�̕ʖ����쐬����@�\

// struct
struct CHARA_DATA
{
    char ID;
    char No;
    int HP;
    int STR;
    int DEX;
};

// �֐��錾
void sizeof_Sample();
void cast_Sample();
void shift_Sample();
void bit_Sample();

int main()
{
    // ���K�v���O����
    //sizeof_Sample();
    //cast_Sample();
    //shift_Sample();
    bit_Sample();
}

//-------------------------------------------------------------------------------------

// sizeof���Z�q�̃T���v���v���O����
void sizeof_Sample()
{
    printf ("sizeof Sample Program\n\n");
    int data = 100;
    int size = 0;

    CHARA_DATA chara_data;

    size = sizeof(CHARA_DATA);

    printf("data �̒l�� %d �ł���\n", data);
    printf("size �̒l�� %d �ł���\n", size);
}

// �L���X�g���Z�q�̃T���v���v���O����
void cast_Sample()
{
    printf("cast_Sample_Program\n\n");
    char *p_char = NULL;   
    int data[10];
    int *p = NULL;

    p = data;
    p_char = (char*)data; // �L���X�g���Z�q�A�����^�ϊ�

    int size = 0;
    size = sizeof(p_char);

    printf("size �̒l�� %d �ł���\n", size);
}

// �V�t�g���Z�̃T���v���v���O����
void shift_Sample()
{
    int data = 100;

    data = data << 1;
    printf("data �̒l�� %d �ł���\n", data);

    
    data = data >> 1;
    printf("data �̒l�� %d �ł���\n", data);
}

// �r�b�g���Z�q�̃T���v���v���O����
void bit_Sample()
{
    unsigned char data = 0x10; // 0001 0000

    // & �� AND���Z�q
    data = data & 0x33;
    printf("data �̒l�� %d �ł�\n", data);

    // | �� OR���Z�q
    data = data | 0x33;
    printf("data �̒l�� %d �ł�\n", data);

    // ^ �� XOR���Z�q
    data = data ^ 0x33;
    printf("data �̒l�� %d �ł�\n", data);

    // ~ �� NOT���Z�q
    data = ~0x33;
    printf("data �̒l�� %d �ł�\n", data);
}