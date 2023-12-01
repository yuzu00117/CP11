//-----------------------------------------------------------------------------------------------------
// #name CP11 ���K
// #description
// #make 2023/11/17
// #update 2023/11/17
//-----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conioex.h>

// �v���C���[�f�[�^
struct PLAYER_DATA
{
    int posX = 0;
    int posY = 0;

    int speed = 1;
};

PLAYER_DATA player;

// ��ʃT�C�Y
#define SCREEN_LEFT 1
#define SCREEN_RIGHT 40
#define SCREEN_TOP 1
#define SCREEN_BOTTOM 20

// �Q�[�����[�v
void init();    // ������
void un_init(); // �I������
void update();  // �X�V
void draw();    // �`��

int main()
{
    // ������
    init();

    // �Q�[�����[�v
    while (1)
    {
        update();

        draw();
    }

}

//-----------------------------------------------------------------------------------------------------
// ������
void init()
{
    // �v���C���[����ʂ̒��S���炢�Ɉړ�
    player.posX = SCREEN_RIGHT / 2;
    player.posY = SCREEN_BOTTOM / 2;
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// �I������
void un_init()
{
    // null
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// �X�V
void update()
{
    player.posX += player.speed;

    if (player.posX > SCREEN_RIGHT || player.posX < SCREEN_LEFT)
        player.speed *= -1;
    Sleep(100);
}

//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// �`��
void draw()
{
    // ��ʃN���A
    system("cls");

    // ��ʕ`��
    /*
    for (int y = SCREEN_TOP; y <= SCREEN_BOTTOM; y++)
    {
        for (int x = SCREEN_LEFT; x <= SCREEN_RIGHT; x++)
        {
            if (y == player.posY && x == player.posX)
            {
                printf("P");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    */
   gotoxy(player.posX, player.posY);
   printf("P");
}
//-----------------------------------------------------------------------------------------------------