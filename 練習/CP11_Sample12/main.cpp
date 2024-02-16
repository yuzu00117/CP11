#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "conioex.h"
#include "main.h"
#include "player.h"
#include "enemy.h"


//�Q�[�����[�v
void Init(void);	//������
void Uninit(void);	//�I������
void Update(void);	//�X�V
void Draw(void);	//�`��

//�O���[�o���ϐ�
DWORD g_Mode_default;   //���̃E�B���h�E���[�h��ۑ����Ă����ꏊ
HANDLE g_hStdin;        //�����̃E�B���h�E����肷��
int g_MouseX, g_MouseY; //�}�E�X�J�[�\���̍��W��ۑ�����

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
	//�v���C���[�̏�����
	PlayerInit();

	//�G�l�~�[�̏�����
	EnemyInit();

	//�J�[�\�����\���ɕς���
	setcursortype(NOCURSOR);

	g_hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(g_hStdin, &g_Mode_default);	//�I�����Ƀf�t�H���g��Ԃɖ߂����߁A�f�t�H���g�̏���ێ�
	SetConsoleMode(g_hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
}

void Uninit()
{
	//�E�B���h�E���[�h�����ɖ߂�
	SetConsoleMode(g_hStdin, g_Mode_default);

	//�I�������͏������̋t���ɍs��
	EnemyUninit();

	PlayerUninit();
}

void Update()
{
	PlayerUpdate();

	EnemyUpdate();

	//�S�ẴL�����N�^�[�̍��W�X�V���I����Ă��瓖���蔻����s��
	PLAYER* pPlayer = GetPlayer();
	ENEMY* pEnemy = GetEnemy();

	for (int i = 0; i < NUM_ENEMY; i++)
	{
		//���łɏ����Ă���G�Ƃ͓����蔻������Ȃ�
		if (pEnemy[i].use == 0)
			continue;

		//�v���C���[�ƓG��i�Ԗڂ̍��W���������ǂ����𒲂ׂ�
		if (floatToInt(pPlayer->posx) == floatToInt(pEnemy[i].posx) &&
			floatToInt(pPlayer->posy) == floatToInt(pEnemy[i].posy) )
		{
			//�����ł���Ἀ����萬���œG������
			EnemyDelete(i);
		}
	}

	g_MouseX = inport(PM_CURX); //�}�E�X�J�[�\��X���W�̍X�V
	g_MouseY = inport(PM_CURY); //�}�E�X�J�[�\��Y���W�̍X�V
}


void Draw()
{
	//��ʃN���A
	//system("cls");

	PlayerDraw();

	EnemyDraw();

	gotoxy(1, 21);
	printf("X:%3d,Y:%3d", g_MouseX, g_MouseY);
}


int floatToInt(float f)
{
	return (int)(f + 0.5f);
}
