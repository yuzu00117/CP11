#include <stdio.h>
#include <time.h>

int main() {
    printf("1���Ԃ̃^�C�}�[���N�����܂�...\n");

    time_t start_time = time(NULL); // ���ݎ������擾
    time_t elapsed_time = 0; // �o�ߎ��Ԃ�ێ�����ϐ�

    while (elapsed_time < 60) { // 60�b�i1���j�o�߂���܂Ń��[�v
        time_t current_time = time(NULL); // ���ݎ������擾
        elapsed_time = current_time - start_time; // �o�ߎ��Ԃ��v�Z

        // �o�ߎ��Ԃ������b�̂Ƃ��̂�printf
        if (elapsed_time % 2 == 0) {
            printf("�o�ߎ���: %ld�b\n", elapsed_time);
        }

        // �o�ߎ��Ԃ�1�b������̂�҂�
        while (time(NULL) == current_time) {
            // ���̕b�܂Ń��[�v
        }
    }

    printf("1���o�߂��܂����B\n");
    return 0;
}