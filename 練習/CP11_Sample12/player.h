#pragma once


//�v���C���[�f�[�^�\����
struct PLAYER
{
	float posx;//���݂�X���W
	float posy;//���݂�Y���W
	float pos_oldx;//�O���X���W
	float pos_oldy;//�O���Y���W

	float speedx;//���ւ̈ړ����x
	float speedy;//�c�ւ̈ړ����x

	int use;//�g�p���Ă��邩�g�p���Ă��Ȃ����̃t���O
};


void PlayerInit(void);
void PlayerUninit(void);
void PlayerUpdate(void);
void PlayerDraw(void);

PLAYER* GetPlayer();
