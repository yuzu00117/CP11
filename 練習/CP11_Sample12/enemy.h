#pragma once


//�G�̐����`����
#define NUM_ENEMY (20)


//�v���C���[�f�[�^�\����
struct ENEMY
{
	float posx;//���݂�X���W
	float posy;//���݂�Y���W
	float pos_oldx;//�O���X���W
	float pos_oldy;//�O���Y���W

	float speedx;//���ւ̈ړ����x
	float speedy;//�c�ւ̈ړ����x

	int use;//�g�p���Ă��邩�g�p���Ă��Ȃ����̃t���O
};


void EnemyInit(void);
void EnemyUninit(void);
void EnemyUpdate(void);
void EnemyDraw(void);

void EnemyDelete(int id);

ENEMY* GetEnemy();
