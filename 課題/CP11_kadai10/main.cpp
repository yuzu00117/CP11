//-----------------------------------------------------------------------------------------------------
// #name CP11 �o�[�R�[�h�o�g���[
// #description �o�g���v���O���������ǂ����O����L�����N�^�[�̃p�����[�^���쐬����@�\��ǉ�����
// #make 2023/11/17
// #update 2023/02/19
// #comment �ǉ��\��@�\
//          �E�L�����N�^�[�̕����쐬���\�ɂ���
//          �E�o�g���v���O�����̉���
//          �@�E�A�C�e���A�o���l�̗v�f�ǉ�
//            �E�R�}���h�I�����ɂ���
//            �Eprint�����̐F����(��������)
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
#include "battle.h"
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

    // �^�C�g����ʂ̕\��
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

//-------------------------------------------------------------

//-------------------------------------------------------------
// �o�[�R�[�h�̐��l�����ƂɃX�e�[�^�X�𐶐�
void GenerateStatusFromBarcode(struct CharacterStats *character, int barcode);

//-------------------------------------------------------------
// �L�����쐬�֐�
void CharacterCreate(struct CharacterStats *character);

//-------------------------------------------------------------