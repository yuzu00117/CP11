#include "title_screen.h"

// �^�C�g����ʂ̕\��
void displayTitleScreen()
{
    // �^�C�g����ʂ̕\�����e���L�q
    printf("=== �^�C�g����� ===\n");
    printf("1. �V�����Q�[�����n�߂�\n");
    printf("2. �ȑO�̃Q�[���𑱂���\n");
    printf("3. �Q�[�����I������\n");
}

// ���[�U�[���͂̏���
void handleUserInput()
{
    printf("���͂��Ă�������\n");

    // ���[�U�[�̓��͂��i�[����ϐ�
    int choice;
    scanf("%d", choice);

    // ���͂��ꂽ�I�����ɉ����ď������s��
    switch (choice)
    {
    case 1:
        printf("�V�����Q�[�����n�߂܂�\n");
        break;
    case 2:
        printf("�ȑO�̃Q�[���𑱂��܂�\n");
    case 3:
        printf("�Q�[�����I�����܂�\n");
    default:
        printf("�����ȑI���ł�\n");
        break;
    }
}

int main()
{
    // �^�C�g����ʂ̕\��
    displayTitleScreen();

    // ���[�U�[���͂̏���
    handleUserInput();

    return 0;
}
