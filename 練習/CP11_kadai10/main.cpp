//-----------------------------------------------------------------------------------------------------
// #name CP11 �l�[���o�g���[
// #description �o�g���v���O���������ǂ����O����L�����N�^�[�̃p�����[�^���쐬����@�\��ǉ�����
// #make 2023/11/17
// #update 2023/12/18
// #comment �L�����N�^�[�̃Z�[�u�ƃ��[�h�������B���C�[�_�̎���̋@�\��ǉ�������
// �o�[�R�[�h�o�g���[�̂悤�ȃQ�[�����ɂ��Ahew�Ɏg�p
//-----------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct CharacterStats
{
    // ���O�AHP�AATK�̓����_�������Œ�`
    char CharacterName[100];
    int CharacterHP;
    int CharacterATK;
    // DEF�͌Œ�l�Œ�`
    int CharacterDEF; // �����_�������ɕύX�\��
};


//-------------------------------------------------------------
// �֐���`

// �o�g���֐�
void battle(struct CharacterStats* character);
// ���O����
void CharacterCreate(struct CharacterStats* character);
// ���O����X�e�[�^�X�𐶐�
void GenerateRandomValue(struct CharacterStats* character);

//-------------------------------------------------------------



//-------------------------------------------------------------
// �t�@�C���� CharacterStats ��ۑ�����֐�
void SaveCharacterToFile(const char* filename, struct CharacterStats* character)
{
    FILE* file = fopen(filename, "wb"); // �o�C�i�����[�h�Ńt�@�C�����J��

    if (file == NULL)
    {
        perror("�t�@�C�����J���ۂɃG���[���������܂���");
        exit(EXIT_FAILURE);
    }
    // �t�@�C���� CharacterStats �̓��e����������
    fwrite(character, sizeof(CharacterStats), 1, file);

    // �t�@�C�������
    fclose(file);
}
//-------------------------------------------------------------



//-------------------------------------------------------------
// �t�@�C������ CharacterStats ��ǂݍ��ފ֐�
void LoadCharacterFromFile(const char* filename, struct CharacterStats* character)
{
    FILE* file = fopen(filename, "rb"); // �o�C�i�����[�h�Ńt�@�C�����J��

    if (file == NULL)
    {
        perror("�t�@�C�����J���ۂɃG���[���������܂���");
        exit(EXIT_FAILURE);
    }

    // �t�@�C������ CharacterStats �̓��e��ǂݍ���
    fread(character, sizeof(CharacterStats), 1, file);

    fclose(file);
}
//-------------------------------------------------------------



//-------------------------------------------------------------
// main
int main()
{
    struct CharacterStats character;

    // �V�����L�����N�^�[���쐬���邩�ǂ�����I��
    char createNewCharacter;
    printf("�V�����L�����N�^�[���쐬���܂����H (y/n): ");
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
        sleep(2);
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
// �L�����쐬�֐�
void CharacterCreate(struct CharacterStats* character)
{
    // ��������i�[���邽�߂̔z����`
    // struct CharacterStats character; // �s�v�ȍs

    // ���[�U�[�ɑ΂��ē��͂̃v�����v�g��\��
    printf("�L�����N�^�[�̖��O����͂��Ă�������: ");

    // fgets�֐����g�p���ĕ���������
    // �������ɂ͕�������i�[����z��A�������ɂ͍ő�ǂݍ��ݕ������A��O�����ɂ͓��͌��i�ʏ�͕W�����́j���w��
    fgets(character->CharacterName, sizeof(character->CharacterName), stdin);

    // fgets�͉��s�������ǂݍ��ނ��߁A�K�v�ȏꍇ�͍폜����
    // ���݂͍폜���k�������ɕϊ�
    int length = strlen(character->CharacterName);
    if (length > 0 && character->CharacterName[length - 1] == '\n')
    {
        character->CharacterName[length - 1] = '\0'; // ���s�������k�������ɒu������
    }

    // ���͂��ꂽ�������\��
    printf("���͂��ꂽ�L�����N�^�[�̖��O: %s\n", character->CharacterName);

    // HP��ATK�𐶐����\��
    GenerateRandomValue(character);

    // CharacterDEF���Œ�l�ő��
    character->CharacterDEF = 3;

    printf("�������ꂽ�����_����HP: %d\n", character->CharacterHP);
    printf("�������ꂽ�����_����ATK: %d\n", character->CharacterATK);
}
//-------------------------------------------------------------



//-------------------------------------------------------------
// HP��ATK�𖼑O�����ƂɃ����_������
void GenerateRandomValue(struct CharacterStats* character)
{
    srand((unsigned)time(NULL));

    // CharacterName�����Ƃɂ��ă����_����HP��ATK�𐶐�
    int seed = 0;
    for (int i = 0; i < strlen(character->CharacterName); i++)
    {
        seed += character->CharacterName[i];
    }
    srand(seed);

    character->CharacterHP = rand() % 500 + 200;
    character->CharacterATK = rand() % 15 + 5;
}
//-------------------------------------------------------------