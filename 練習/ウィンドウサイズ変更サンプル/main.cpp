#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "screen.h"
#include "conioex.h"

DWORD g_Mode_default;


int main(void)
{
	//���Q�[���̏��������ɉ�ʃT�C�Y��ύX����
	//ScreenInit�֐�
	//��1���� ��ʉ��T�C�Y
	//��2���� ��ʏc�T�C�Y
	//��3���� �t�H���g�T�C�Y�i6�`24�̊ԂŐݒ�\�j
	ScreenInit(120, 30, 20);

	const HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &g_Mode_default);
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);

	printf("�����ŃQ�[�����s\n");

	while(1)
	{

		int x = inport(PM_CURX);
		int y = inport(PM_CURY);

		printf("X:%3d, Y:%3d\n", x, y);

		Sleep(1);
	}
	// getchar();

	SetConsoleMode(hStdin, g_Mode_default);

	//���Q�[���̏I�����ɃE�B���h�E�T�C�Y�A�t�H���g�T�C�Y�̐ݒ�����s�O�̏�Ԃɕ�������
	//ScreenEnd�֐�
	ScreenEnd();

	return 0;
}
