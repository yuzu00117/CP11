
#define	CONIOEX
#include <windows.h>
#include <stdio.h>


//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define FONT_MIN		6		// �ŏ��t�H���g�T�C�Y
#define FONT_MAX		24		// �ő�t�H���g�T�C�Y

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
static void set_font_size(int font_size);
static void set_window_size(int width, int height);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static HANDLE						stdout_h;	// �W���o�͂̃n���h���l�p
static CONSOLE_FONT_INFOEX			save_font;	// �t�H���g���ޔ�p
static CONSOLE_SCREEN_BUFFER_INFO	save_screen;// ���/�o�b�t�@���ޔ�p

static int		ScreenWidth;		// ������̉�ʕ�
static int		ScreenHeight;		// ������̉�ʍ���


//===================================================================
// �����֐��F�w�肵���t�H���g�T�C�Y�ɐݒ肷��(���T�C�Y��1/2)
//===================================================================
static void set_font_size(int font_size)
{
	CONSOLE_FONT_INFOEX	font;	// �t�H���g�T�C�Y�ύX�p

	if (font_size < FONT_MIN) {
		printf("%d�͔͈͊O�̂���%d�ɕύX\n", font_size, FONT_MIN);
		font_size = FONT_MIN;
	}
	else if (font_size > FONT_MAX) {
		printf("%d�͔͈͊O�̂���%d�ɕύX\n", font_size, FONT_MAX);
		font_size = FONT_MAX;
	}

	font = save_font;
	font.dwFontSize.X = font_size / 2;	// ���s�N�Z���l�̓t�H���g�T�C�Y�̔���
	font.dwFontSize.Y = font_size;		// �c�s�N�Z���l�̓t�H���g�T�C�Y�Ɠ���
	if (!SetCurrentConsoleFontEx(stdout_h, FALSE, &font)) {
		printf("SetCurrentConsoleFontEx�ŃG���[���������܂���\n");
	}
}
//===================================================================
// �����֐��F�w�肵����ʃT�C�Y��ݒ肷��
// �� �o�b�t�@�T�C�Y���傫���Ɠ������x���Ȃ邽�߁A
// �@ �o�b�t�@�T�C�Y�͉�ʃT�C�Y�Ɠ����ɂ���(��ʃT�C�Y���ŏ��T�C�Y)
// (��)SetConsoleWindowInfo�́A�ȉ��̏ꍇ�ɃG���[�ɂȂ�
//    �E�o�b�t�@�T�C�Y���傫�ȉ�ʃT�C�Y���w�肵��
//    �E�ő�o�b�t�@�T�C�Y���傫�ȉ�ʃT�C�Y���w�肵��
//===================================================================
static void set_window_size(int width, int height)
{
	CONSOLE_SCREEN_BUFFER_INFO	now;	// ��ʂ̌���l����p
	SMALL_RECT					screen;	// ��ʃT�C�Y�ύX�p
	COORD						coord;	// �o�b�t�@�T�C�Y�ύX�p
	DWORD						error;

	// �o�b�t�@�T�C�Y���w�肳�ꂽ��ʃT�C�Y�Ɠ����傫���ɂ���
	coord.X = width;
	coord.Y = height;
	if (!SetConsoleScreenBufferSize(stdout_h, coord)) {
		//printf("SetConsoleScreenBufferSize�ŃG���[���������܂���\n");
		error = GetLastError();
	}

	// �w��l���ő��ʃT�C�Y���傫���ꍇ�A�ő��ʃT�C�Y�ɕύX
	GetConsoleScreenBufferInfo(stdout_h, &now);		// ����l�����
	screen.Left = screen.Top = 0;
	screen.Right = ((width > now.dwMaximumWindowSize.X) ?
		now.dwMaximumWindowSize.X : (SHORT)(width)) - 1;
	screen.Bottom = ((height > now.dwMaximumWindowSize.Y) ?
		now.dwMaximumWindowSize.Y : (SHORT)(height)) - 1;

	ScreenWidth = screen.Right + 1;	// �����W���[������̖₢���킹�p�ɋL�^
	ScreenHeight = screen.Bottom + 1;

	if (!SetConsoleWindowInfo(stdout_h, TRUE, &screen)) {
		printf("SetConsoleWindowInfo�ŃG���[���������܂���\n");
	}
}

void ScreenInit(int width, int height, int fontsize)
{
	stdout_h = GetStdHandle(STD_OUTPUT_HANDLE);	// �W���o�̓n���h�����Z�b�g

	GetConsoleScreenBufferInfo(stdout_h, &save_screen);	// ����ʏ���ޔ�

	save_font.cbSize = sizeof(save_font);
	GetCurrentConsoleFontEx(stdout_h, FALSE, &save_font);// ���t�H���g����ޔ�

	set_window_size(width, height);

	set_font_size(fontsize);
}

void ScreenEnd(void)
{
	COORD		coord;	// �o�b�t�@�ύX�p
	SMALL_RECT	screen;	// ��ʃT�C�Y�ύX�p

	// �ޔ����Ă����o�b�t�@�T�C�Y�ɖ߂�
	coord.X = save_screen.dwSize.X;
	coord.Y = save_screen.dwSize.Y;
	SetConsoleScreenBufferSize(stdout_h, coord);

	// �ޔ����Ă�����ʃT�C�Y�ɖ߂�
	screen.Left = screen.Top = 0;
	screen.Right = save_screen.srWindow.Right;
	screen.Bottom = save_screen.srWindow.Bottom;
	SetConsoleWindowInfo(stdout_h, TRUE, &screen);

	// �ޔ����Ă����t�H���g�T�C�Y�ɖ߂�
	SetCurrentConsoleFontEx(stdout_h, FALSE, &save_font);
}
