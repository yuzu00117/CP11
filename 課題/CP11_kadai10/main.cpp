//-----------------------------------------------------------------------------------------------------
// #name CP11 �l�[���o�g���[
// #description �o�g���v���O���������ǂ����O����L�����N�^�[�̃p�����[�^���쐬����@�\��ǉ�����
// #make 2023/11/17
// #update 2023/12/18
// #comment �L�����N�^�[�̃Z�[�u�ƃ��[�h�������B���C�[�_�̎���̋@�\��ǉ�������
// �o�[�R�[�h�o�g���[�̂悤�ȃQ�[�����ɂ��Ahew�Ɏg�p
//-----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "file_operations.h"

//-------------------------------------------------------------
// �֐���`

// �o�g���֐�
void battle(struct CharacterStats* character);

// �o�[�R�[�h�̐��l�����ƂɃX�e�[�^�X�𐶐�
void GenerateStatusFromBarcode(struct CharacterStats* character, int barcode);

// �L�����쐬�֐�
void CharacterCreate(struct CharacterStats* character);
//-------------------------------------------------------------



//-------------------------------------------------------------
// �t�@�C���� CharacterStats ��ۑ�����֐�
void SaveCharacterToFile(const char* filename, struct CharacterStats* character);
//-------------------------------------------------------------

//-------------------------------------------------------------
// �t�@�C������ CharacterStats ��ǂݍ��ފ֐�
void LoadCharacterFromFile(const char* filename, struct CharacterStats* character);
//-------------------------------------------------------------



//-------------------------------------------------------------
// main
int main()
{
    struct CharacterStats character;

    // �V�����L�����N�^�[���쐬���邩�ǂ�����I��
    char createNewCharacter;
    printf("�V�����L�����N�^�[���쐬���܂����H (y/n): \n");
    printf("���ۑ����Ă���L�����N�^�[�͍폜����܂�");
    scanf("%c", &createNewCharacter);

    if (createNewCharacter == 'y' || createNewCharacter == 'Y')
    {
        rewind(stdin);
        // �V�����L�����N�^�[���쐬
        CharacterCreate(&character);
        // �t�@�C���ɕۑ�
        SaveCharacterToFile("character.dat", &character);
    }
    else if (createNewCharacter == 'n' || createNewCharacter == 'N')
    {
        LoadCharacterFromFile("character.dat", &character);

        // �ǂݍ��܂ꂽ�f�[�^�̕\��
        printf("�ǂݍ��܂ꂽ�L�����N�^�[�̖��O: %s\n", character.CharacterName);
        printf("�ǂݍ��܂ꂽ�L�����N�^�[��HP: %d\n", character.CharacterHP);
        printf("�ǂݍ��܂ꂽ�L�����N�^�[��ATK: %d\n", character.CharacterATK);
        printf("�ǂݍ��܂ꂽ�L�����N�^�[��DEF: %d\n", character.CharacterDEF);

        // �o�g�����s
        battle(&character);
    }
    else {
        printf("���������͂��s���ĉ������B\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------



//-------------------------------------------------------------
// �o�g���v���O����
// �L�����N�^�[�ƃG�l�~�[�̃o�g��
// 5�^�[�� �o�ߌ�݂̌���HP��\��
void battle(struct CharacterStats* character)
{
    // �L�����N�^�[�̃X�e�[�^�X�͍\���̂���Q��

    // �G�l�~�[�̃X�e�[�^�X���`
    int enemyHP = rand() % 500 + 200;
    float enemyATK = rand() % 15 + 5;
    float enemyDEF = 3;

    // �^�[����
    int turn = 5; // �^�[�����͔C�ӂŕύX�\

    // �U���v�Z�p
    int characterDMG, enemyDMG;

    // 5�^�[��
    for (int i = 0; i < turn; i++)
    {
        // �_���[�W�𗐐��Ő���
        // �_���[�W�͔C�ӂŕύX�\
        characterDMG = rand() % 21;
        enemyDMG = rand() % 21;

        // �U���͂Ɩh��͂̌v�Z
        characterDMG *= (character->CharacterATK - enemyDEF);
        enemyDMG *= (enemyATK - character->CharacterDEF);

        // �퓬
        printf("------------------\n");
        printf("%s�̍U���F%d�̃_���[�W\n", character->CharacterName, characterDMG);
        character->CharacterHP -= enemyDMG;
        printf("�G�̍U���F%d�̃_���[�W\n", enemyDMG);
        enemyHP -= characterDMG;
        printf("------------------\n");

        // ��b���ɏ���
        Sleep(2000);
        //system("clear");
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
void GenerateStatusFromBarcode(struct CharacterStats* character, int barcode);

//-------------------------------------------------------------
// �L�����쐬�֐�
void CharacterCreate(struct CharacterStats* character);

//-------------------------------------------------------------