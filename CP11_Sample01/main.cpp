//------------------------------------------------------
// #name CL11 �T���v���v���O����
// #description �}�`�`��v���O����
// #make 2023/06/07
//------------------------------------------------------
#define _CRT_SECURE_NO_WORNINGS
#include <stdio.h>

int main() {

    void ResetArray(int* p, int data);

    int *pt; // �|�C���^�ϐ��A�A�h���X���i�[�ł���

    int data; // �ʏ�̕ϐ��ɂ͒l�����邱�Ƃ��ł���

    pt = &data; // �ϐ��� & ������ƃA�h���X�������o�����Ƃ��ł���

    int s_data[4] = {17, 24, 38, 45};

    //s_data[0] = 80;
    //s_data[1] = 100;

    pt = s_data; // �|�C���^�ϐ� pt �ɔz�� s_data �̐擪�A�h���X���i�[

    *pt = 100;
    printf("s_data[0]�� %d �ł���\n", s_data[0]);
    
    *(pt + 1) = 500;
    ResetArray(s_data, 4);

    printf("s_data[0]�� %d �ł���\n", s_data[1]);

    printf("pt�̃A�h���X�� %p �ł���\n", pt);
    printf("pt + 4�̃A�h���X�� %p �ł���\n", pt + 4);

    return 0;
}

void ResetArray(int *p, int data) {
    for (int i = 0; i < data; i++)
    {
        *(p + 1) = 0;
    }
}