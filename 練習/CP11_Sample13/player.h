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

	int maxhp;//�ő�q�b�g�|�C���g
	int hp;//�q�b�g�|�C���g

	float jump_pow;	//�W�����v��
	float gravity;	//�d��
	int	is_ground;	//�ڒn�t���O

	int use;//�g�p���Ă��邩�g�p���Ă��Ȃ����̃t���O
};


void PlayerInit(void);
void PlayerUninit(void);
void PlayerUpdate(void);
void PlayerDraw(void);
void PlayerDrawHP(void);
void PlayerDamage(void);

PLAYER* GetPlayer();
int PlayerGetHP(void);
void PlayerHeal(void);
