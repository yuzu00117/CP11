#pragma once

//��ʂ̑傫�����`����
#define SCREEN_LEFT   1
#define SCREEN_TOP    1
#define SCREEN_RIGHT  40
#define SCREEN_BOTTOM 20

//�v���C���[�f�[�^�\����
struct PLAYER
{
	float posx;//���݂�X���W
	float posy;//���݂�Y���W
	float pos_oldx;//�O���X���W
	float pos_oldy;//�O���Y���W

	float speedx;//���ւ̈ړ����x
	float speedy;//�c�ւ̈ړ����x
};

PLAYER* GetPlayer();

int floatToInt(float f);

int floatToInt(float f)
{
	return (int)(f + 0.5f);
}
