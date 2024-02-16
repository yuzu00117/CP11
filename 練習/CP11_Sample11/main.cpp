#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "conioex.h"
#include "main.h"
#include "player.h"
#include "enemy.h"

// �Q�[�����[�v
void Init(void);   // ������
void Uninit(void); // �I������
void Update(void); // �X�V
void Draw(void);   // �`��

DWORD g_Mode_default;
HANDLE g_hStdin;

int g_MouseX, g_MouseY;

PLAYER g_Player;

int main(void)
{
	// �Q�[���f�[�^�̏�����
	Init();

	// �擾���鎞�Ԃׂ̍����i����\�j���w�肷��֐�
	// �����1/1000���w�肷��
	timeBeginPeriod(1); // WindowsAPI

	// ��60FPS Frame Per Second�ŃQ�[���𓮂���
	//(1.0f / 60)��0.01666666666
	//(unsigned int)
	DWORD currentTime; // ���݃V�X�e������
	DWORD lastTime;	   // �O��V�X�e������

	// Windows�̃V�X�e�����Ԃ��w�肳�ꂽ����\�ŕԂ��֐�
	// �V�X�e�����ԁ�Windows���N�����Ă���̌o�ߎ���
	currentTime = timeGetTime();
	lastTime = currentTime; // �Q�[�������o�����O�̎��Ԃ�ۑ����Ă���

	// �Q�[�����[�v
	while (1)
	{
		// ���݃V�X�e�����Ԃ̍X�V
		currentTime = timeGetTime();

		// �Q�[���̍X�V�^�C�~���O��҂�
		if ((currentTime - lastTime) > (1000.0f / 60))
		{
			// �O��V�X�e�����Ԃ��X�V����
			lastTime = currentTime;

			// �Q�[���f�[�^�̍X�V
			Update();

			// �`��
			Draw();
		}
	}

	// �Q�[���f�[�^�̌�Еt��
	Uninit();

	// ����\�����ɖ߂�
	timeEndPeriod(1);

	return 0;
}

void Init()
{
	PlayerInit();
	EnemyInit();

	// �J�[�\�����\���ɕς���
	setcursortype(NOCURSOR);

	g_hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(g_hStdin, &g_Mode_default);
	SetConsoleMode(g_hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
}

void Uninit()
{
	PlayerUninit();
	EnemyUninit();

	SetConsoleMode(g_hStdin, g_Mode_default);
}
void Update()
{
	PlayerUpdate();
	EnemyUpdate();

	// �����蔻��
	// ���ׂẴL�����N�^�[�̍��W�X�V��ɔ�����s��
	g_Player.posx;

	ENEMY *pEnemy = GetEnemy();

	for (int i = 0; i < NUM_ENEMY; i++)
	{
		// �v���C���[�ƓG�� x,y���W�������ł����
		if (floatToInt(g_Player.posx) == pEnemy[i].posx && floatToInt(g_Player.posy) == pEnemy[i].posy)
		{
			EnemyDelete(i);
		}
	}
	g_MouseX = inport(PM_CURX);
	g_MouseY = inport(PM_CURY);
}
void Draw()
{
	PlayerDraw();
	EnemyDraw();

	gotoxy(1, 21);
	printf("X:%3d, Y:%3d", g_MouseX, g_MouseY)
}

int floatToInt(float f)
{
	return (int)(f + 0.5f);
}

// g_Player�̃Q�b�^�[�֐�
PLAYER *GetPlayer()
{
	return &g_Player;
}