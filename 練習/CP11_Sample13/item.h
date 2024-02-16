#pragma once


//�A�C�e���̐����`����
#define NUM_ITEM (3)


//�v���C���[�f�[�^�\����
struct ITEM
{
	float posx;//���݂�X���W
	float posy;//���݂�Y���W

	int use;//�g�p���Ă��邩�g�p���Ă��Ȃ����̃t���O
};

void ItemInit(void);
void ItemUninit(void);
void ItemUpdate(void);
void ItemDraw(void);

void ItemCreate(void);
void ItemDelete(int id);

ITEM* GetItem();
