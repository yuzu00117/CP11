//-----------------------------------------------------------------------------------------------------
// #name CP11 �o�[�R�[�h�o�g���[
// #description �o�g���v���O���������ǂ����O����L�����N�^�[�̃p�����[�^���쐬����@�\��ǉ�����
// #make 2023/11/17
// #update 2023/02/19
// #comment �ǉ��\��@�\
//          �E�^�C�g����ʂ̒ǉ�
//          �E�L�����N�^�[�̕����쐬���\�ɂ���
//          �E�o�g���v���O�����̉���
//          �@�E�A�C�e���A�o���l�̗v�f�ǉ�
//            �E�R�}���h�I�����ɂ���
//            �Eprint�����̐F����
//----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "file_operations.h"
#include "character_operations.h"
#include "character.h"
#include "title_screen.h"

//-------------------------------------------------------------
// �֐���`

// �o�g���֐�
void battle(struct CharacterStats *character);
//-------------------------------------------------------------

//-------------------------------------------------------------
// �L�����N�^�[�̃��[�h�A�ۑ�

// �t�@�C���� CharacterStats ��ۑ�
void SaveCharacterToFile(const char *filename, struct CharacterStats *character);


// �t�@�C������ CharacterStats ��ǂݍ���
void LoadCharacterFromFile(const char *filename, struct CharacterStats *character);
//-------------------------------------------------------------

//-------------------------------------------------------------
// main
int main()
{
    // �L�����N�^�[�̍\����
    struct CharacterStats character;

    // �^�C�g���\��
    displayTitleScreen();
    
    // �L�����N�^�[���쐬���邩�ǂ���
    askForCharacterCreation(&character);

    // �o�g�����s
    battle(&character);
}

//-------------------------------------------------------------
//-------------------------------------------------------------
// �o�g���v���O����
// �L�����N�^�[�ƃG�l�~�[�̃o�g��
// 5�^�[�� �o�ߌ�݂̌���HP��\��
void battle(struct CharacterStats *character)
{
    // �L�����N�^�[�̃X�e�[�^�X�͍\���̂���Q��
    
    // �G�l�~�[�̃X�e�[�^�X���`
    srand((unsigned)time(NULL));
    int enemyHP = rand() % 500 + 200;
    float enemyATK = rand() % 15 + 5;
    float enemyDEF = 3;

    // �^�[����
    int turn = 5; // �^�[�����͔C�ӂŕύX�\

    // �U���v�Z�p
    int characterDMG, enemyDMG;
    int randomDamage; // �_���[�W�̃����_�����Ɏg�p

    // 5�^�[��
    for (int i = 0; i < turn; i++)
    {
        // �_���[�W�̃����_����
        srand((unsigned)time(NULL));
        randomDamage = rand() & 3;

        // �U���͂Ɩh��͂̌v�Z
        characterDMG = (character->CharacterATK - enemyDEF) + randomDamage;
        enemyDMG = (enemyATK - character->CharacterDEF) + randomDamage;

        // �퓬
        printf("------------------\n");
        printf("%s�̍U���F%d�̃_���[�W\n", character->CharacterName, characterDMG);
        character->CharacterHP -= enemyDMG;
        printf("�G�̍U���F%d�̃_���[�W\n", enemyDMG);
        enemyHP -= characterDMG;
        printf("------------------\n");

        // ��b���ɏ���
        Sleep(2000);
        // system("clear");
    }

    printf("�^�[���I�����%s��HP�F%d\n", character->CharacterName, character->CharacterHP);
    printf("�^�[���I����̓G��HP�F%d\n", enemyHP);

    if (character->CharacterHP < enemyHP)
    {
        printf("�G�̏����I\n");
    }
    else if (character->CharacterHP > enemyHP)
    {
        printf("�v���C���[�̏����I\n");
    }
}
//-------------------------------------------------------------

//-------------------------------------------------------------
// �o�[�R�[�h�̐��l�����ƂɃX�e�[�^�X�𐶐�
void GenerateStatusFromBarcode(struct CharacterStats *character, int barcode);

//-------------------------------------------------------------
// �L�����쐬�֐�
void CharacterCreate(struct CharacterStats *character);

//-------------------------------------------------------------