/*


//-------------------------------------------------------------------------------------
// #name CP11 ���C�[�_�̎���
// #description �L�����N�^�[���i�[����\���̂̃������𓮓I�m�ۂ���
// #make 2023/10/20
//-------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �L�����N�^�[�f�[�^
struct CHARACTER_DATA
{
	char Name[10]; // ���O
	int HP;			// �w���X
	int AD;			// �U����
};

// �֐��錾
//void ViewList(CHARACTER_DATA* pCharaData);			// �L�����N�^�[���X�g�\��
//void CharacterView(CHARACTER_DATA* pCharaData);		// �L�����N�^�[�{��
//void CharacterCreate(CHARACTER_DATA* pCharaData);	// �L�����N�^�[�쐬
//void CharacterDelete(CHARACTER_DATA* pCharaData);	// �L�����N�^�[�폜

int main()
{
	CHARACTER_DATA *p;
	// �L�����N�^�[�̕ۑ���10�l�܂�
	p = (CHARACTER_DATA*)malloc(sizeof(CHARACTER_DATA)*10);

	CHARACTER_DATA CharaData[10] = {};

	// TestCharacter 1
	strcpy(CharaData[0].Name, "Chara1");
	CharaData[0].HP = 100;
	CharaData[0].AD = 50;

	// TestCharacter 2
	strcpy(CharaData[1].Name, "Chara2");
	CharaData[1].HP = 200;
	CharaData[1].AD = 100;

	// TestCharacter 6
	strcpy(CharaData[5].Name, "Chara6");
	CharaData[5].HP = 500;
	CharaData[5].AD = 250;

	printf("---------------------------\n");
	printf("�M���K���b�V���̎���\n");
	printf("---------------------------\n");

	// ���������
	free(p);
	return 0;
}
*/
//-------------------------------------------------------------------------------------
// #name CP11 �M���K���b�V���̎���
// #description �L�����N�^�[�̉{���ƒǉ��A�폜���ł���v���O�����B�Œ�3�̗v�f���Ǘ����邱��
// #make 2023/10/20
//-------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �L�����N�^�[�f�[�^
struct CHARACTER_DATA
{
	char Name[128]; // ���O
	int HP;			// �w���X
	int AD;			// �U����
};

// �֐��錾
void ViewList(CHARACTER_DATA* pCharaData);			// �L�����N�^�[���X�g�\��
void CharacterView(CHARACTER_DATA* pCharaData);		// �L�����N�^�[�{��
void CharacterCreate(CHARACTER_DATA* pCharaData);	// �L�����N�^�[�쐬
void CharacterDelete(CHARACTER_DATA* pCharaData);	// �L�����N�^�[�폜

int main()
{
	CHARACTER_DATA *p;
	// �L�����N�^�[�̕ۑ���10�l�܂�
	p = (CHARACTER_DATA*)malloc(sizeof(CHARACTER_DATA)*10);

	CHARACTER_DATA CharaData[10] = {};

	// TestCharacter 1
	strcpy(CharaData[0].Name, "Chara1");
	CharaData[0].HP = 100;
	CharaData[0].AD = 50;

	// TestCharacter 2
	strcpy(CharaData[1].Name, "Chara2");
	CharaData[1].HP = 200;
	CharaData[1].AD = 100;

	// TestCharacter 6
	strcpy(CharaData[5].Name, "Chara6");
	CharaData[5].HP = 500;
	CharaData[5].AD = 250;

	printf("---------------------------\n");
	printf("�M���K���b�V���̎���\n");
	printf("---------------------------\n");

	while (1)
	{
		printf("�������܂���\n\n");
		printf("1, �L�����N�^�[�̉{��\n");
		printf("2, �L�����N�^�[�̍쐬\n");
		printf("3, �L�����N�^�[�̍폜\n");
		printf("4, �I��\n");

		int Select;
		scanf("%d", &Select);

		switch (Select)
		{
		case 1:
			CharacterView(CharaData); // CharaData �̐擪�A�h���X���֐��ɓn��
			rewind(stdin);
			break;
		case 2:
			CharacterCreate(CharaData);
			rewind(stdin);
			break;
		case 3:
			CharacterDelete(CharaData);
			rewind(stdin);
			break;
		case 4:
			printf("�I�����܂�\n");
			exit(0);
			rewind(stdin);
			break;
		default:
			printf("��������������͂��Ă�������\n");
			rewind(stdin);
			break;
		}
	}
	// �L�����N�^�[�̍쐬
	// �L�����N�^�[�̍폜
	// �I������
	return 0;
}
//-------------------------------------------------------------------------------------
// ���X�g�\��
void ViewList(CHARACTER_DATA* pCharaData)
{
	for (int i = 0; i < 10; i++)
	{
		char temp_str[256] = "";
		// �o�^�i���o�[�̕\��
		sprintf(temp_str, "%2d, ", i + 1);
		// ���O�̕\��
		strcat(temp_str, pCharaData[i].Name);
		printf("%s\n", temp_str);
	}
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// �L�����N�^�[�f�[�^�̉{��
void CharacterView(CHARACTER_DATA* pCharaData)
{
	// �L�����N�^�[�{��
	ViewList(pCharaData);
	// �L�[����
	printf("�ǂ̃L�����N�^�[���{�����܂���\n");
	int Select = 0;
	scanf("%d", &Select);
	rewind(stdin);

	printf("Name : %s\n", pCharaData[Select - 1].Name);
	printf("HP   : %d\n", pCharaData[Select - 1].HP);
	printf("AD   : %d\n", pCharaData[Select - 1].AD);

	printf("�L�[�������đ��s\n");
	getchar();
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// �L�����N�^�[�f�[�^�̍쐬
void CharacterCreate(CHARACTER_DATA* pCharaData)
{
	// �L�����N�^�[�{��
	ViewList(pCharaData);
	// �L�[����
	printf("�ǂ̏ꏊ�ɍ쐬���܂���\n");
	int Select = 0;
	scanf("%d", &Select);
	rewind(stdin);

	printf("���O��ݒ肵�Ă��������F");
	scanf("%s", &pCharaData[Select - 1].Name);
	rewind(stdin);
	printf("HP��ݒ肵�Ă��������F");
	scanf("%d", &pCharaData[Select - 1].HP);
	rewind(stdin);
	printf("�U���͂�ݒ肵�Ă��������F");
	scanf("%d", &pCharaData[Select - 1].AD);
	rewind(stdin);

	printf("�L�����N�^�[���쐬���܂���\n");
	printf("�L�[�������đ��s\n");
	getchar();
}
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// �L�����N�^�[�f�[�^�̍폜
void CharacterDelete(CHARACTER_DATA* pCharaData)
{
	// �L�����N�^�[�{��
	ViewList(pCharaData);
	// �L�[����
	printf("�ǂ̃L�����N�^�[���폜���܂���\n");
	int Select = 0;
	scanf("%d", &Select);
	rewind(stdin);

	strcpy(pCharaData[Select - 1].Name, "");
	pCharaData[Select - 1].HP = 0;
	pCharaData[Select - 1].AD = 0;

	printf("�L�[�������đ��s\n");
	getchar();
}
//-------------------------------------------------------------------------------------