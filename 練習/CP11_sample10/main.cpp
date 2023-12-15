#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "conioex.h"
#include "main.h"

//�G�̐����`����
#define NUM_ENEMY (20)

//�Q�[�����[�v
void Init(void);	//������
void Uninit(void);	//�I������
void Update(void);	//�X�V
void Draw(void);	//�`��
int floatToInt(float f);//���W���������琮���ɕϊ�����


PLAYER g_Player;
PLAYER g_Enemy[NUM_ENEMY];


int main(void)
{
	//�Q�[���f�[�^�̏�����
	Init();

	//�擾���鎞�Ԃׂ̍����i����\�j���w�肷��֐�
	//�����1/1000���w�肷��
	timeBeginPeriod(1);//WindowsAPI

	//��60FPS Frame Per Second�ŃQ�[���𓮂���
	//(1.0f / 60)��0.01666666666
	//(unsigned int)
	DWORD currentTime;//���݃V�X�e������
	DWORD lastTime;//�O��V�X�e������

	//Windows�̃V�X�e�����Ԃ��w�肳�ꂽ����\�ŕԂ��֐�
	//�V�X�e�����ԁ�Windows���N�����Ă���̌o�ߎ���
	currentTime = timeGetTime();
	lastTime = currentTime;//�Q�[�������o�����O�̎��Ԃ�ۑ����Ă���

	//�Q�[�����[�v
	while (1)
	{
		//���݃V�X�e�����Ԃ̍X�V
		currentTime = timeGetTime();

		//�Q�[���̍X�V�^�C�~���O��҂�
		if ((currentTime - lastTime) > (1000.0f / 60))
		{
			//�O��V�X�e�����Ԃ��X�V����
			lastTime = currentTime;

			//�Q�[���f�[�^�̍X�V
			Update();

			//�`��
			Draw();
		}
	}

	//�Q�[���f�[�^�̌�Еt��
	Uninit();

	//����\�����ɖ߂�
	timeEndPeriod(1);

	return 0;
}


void Init()
{
	//�G�l�~�[���W�������_���ɃZ�b�g����
	for (int i = 0; i < NUM_ENEMY; i++)
	{
		g_Enemy[i].posx = rand() % SCREEN_RIGHT + 1;//1�`40�̃����_��
		g_Enemy[i].posy = rand() % SCREEN_BOTTOM + 1;//1�`20�̃����_��
		g_Enemy[i].pos_oldx = g_Enemy[i].posx;
		g_Enemy[i].pos_oldy = g_Enemy[i].posy;
		g_Enemy[i].speedx = (float)(rand() % 1000) / 10000;
		g_Enemy[i].speedy = (float)(rand() % 1000) / 20000;

		//���݂̏ꏊ�ɃG�l�~�[��`�悷��
		gotoxy(floatToInt(g_Enemy[i].posx), floatToInt(g_Enemy[i].posy));
		printf("#");
	}


	//�J�[�\�����\���ɕς���
	setcursortype(NOCURSOR);
}
void Uninit()
{
}
void Update()
{
	//�O����W��ۑ�����
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;

	//�L�[�{�[�h�̃J�[�\���L�[���������ꂽ
	if (inport(PK_LEFT))
	{
		g_Player.posx -= g_Player.speedx;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posx < SCREEN_LEFT)
	{
		g_Player.posx = SCREEN_LEFT;
	}

	//�L�[�{�[�h�̃J�[�\���L�[�E�������ꂽ
	if (inport(PK_RIGHT))
	{
		g_Player.posx += g_Player.speedx;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posx > SCREEN_RIGHT)
	{
		g_Player.posx = SCREEN_RIGHT;
	}

	//�L�[�{�[�h�̃J�[�\���L�[�オ�����ꂽ
	if (inport(PK_UP))
	{
		g_Player.posy -= g_Player.speedy;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posy < SCREEN_TOP)
	{
		g_Player.posy = SCREEN_TOP;
	}

	//�L�[�{�[�h�̃J�[�\���L�[���������ꂽ
	if (inport(PK_DOWN))
	{
		g_Player.posy += g_Player.speedy;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posy > SCREEN_BOTTOM)
	{
		g_Player.posy = SCREEN_BOTTOM;
	}




	//---------------------------------------------------------------------

	for (int i = 0; i < NUM_ENEMY; i++)
	{
		//�O����W��ۑ�����
		g_Enemy[i].pos_oldx = g_Enemy[i].posx;
		g_Enemy[i].pos_oldy = g_Enemy[i].posy;

		//�G�l�~�[���W��g_Enemy.speed�̂Ԃ񑝂₷
		g_Enemy[i].posx += g_Enemy[i].speedx;
		g_Enemy[i].posy += g_Enemy[i].speedy;

		//SCREEN_RIGHT��SCREEN_LEFT�Œ��˕Ԃ�
		if (g_Enemy[i].posx > SCREEN_RIGHT || g_Enemy[i].posx < SCREEN_LEFT)
		{
			//X�̈ړ������𔽓]������
			g_Enemy[i].speedx *= -1;
		}

		//SCREEN_TOP��SCREEN_BOTTOM�Œ��˕Ԃ�
		if (g_Enemy[i].posy > SCREEN_BOTTOM || g_Enemy[i].posy < SCREEN_TOP)
		{
			//Y�̈ړ������𔽓]������
			g_Enemy[i].speedy *= -1;
		}
	}
}


void Draw()
{
	//��ʃN���A
	//system("cls");

	//�������W���X�V����Ă�����`����s��
	if ((floatToInt(g_Player.pos_oldx) != floatToInt(g_Player.posx)) ||
		(floatToInt(g_Player.pos_oldy) != floatToInt(g_Player.posy)))
	{
		//�ЂƂO�̏ꏊ
		gotoxy(floatToInt(g_Player.pos_oldx), floatToInt(g_Player.pos_oldy));
		printf(" ");

		//���݂̏ꏊ
		gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
		printf("@");
	}

	//----------------------------------------------------------------------------

	for (int i = 0; i < NUM_ENEMY; i++)
	{
		//�������W���X�V����Ă�����`����s��
		if ((floatToInt(g_Enemy[i].pos_oldx) != floatToInt(g_Enemy[i].posx)) ||
			(floatToInt(g_Enemy[i].pos_oldy) != floatToInt(g_Enemy[i].posy)))
		{
			//�ЂƂO�̏ꏊ
			gotoxy(floatToInt(g_Enemy[i].pos_oldx), floatToInt(g_Enemy[i].pos_oldy));
			printf(" ");

			//���݂̏ꏊ
			gotoxy(floatToInt(g_Enemy[i].posx), floatToInt(g_Enemy[i].posy));
			printf("#");
		}
	}
}

PLAYER* GetPlayer()
{
	return &g_Player;
}