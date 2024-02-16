// =============================================================================
// 
// �A�N�V�����Q�[���T���v�� [main.cpp]
// 
// ����ҁF			���t�F2024/02/02
// =============================================================================
#include "main.h"
#include "conioex.h"
#include "scene.h"


// *****************************************************************************
// �}�N����`
// *****************************************************************************


// *****************************************************************************
// �v���g�^�C�v�錾
// *****************************************************************************
#ifdef _DEBUG
void DispFPS(void);
#endif
void WindowConsoleInitialize(void);


// *****************************************************************************
// �O���[�o���ϐ�
// *****************************************************************************
int CountFps;				// FPS�J�E���^

int clearFlag = 0;


// =============================================================================
//  ���C���֐�
// =============================================================================
int main(void)
{
	int ExecLastTime;
	int FPSLastTime;
	int CurrentTime;
	int FrameCount;

	// ��ʂ��N���A
	clrscr();

	// �J�[�\����\��
	setcursortype(NOCURSOR);

	// ����\��ݒ�
	timeBeginPeriod(1);

	ExecLastTime = 
	FPSLastTime = timeGetTime();
	CurrentTime =
	FrameCount = 0;

	// �E�B���h�E�ݒ�̏������iHEW�p�ݒ�j
	WindowConsoleInitialize();


	//�Q�[������������
	SceneInit();


	// �Q�[�����C������
	do
	{
		CurrentTime = timeGetTime();
		if((CurrentTime - FPSLastTime) >= 500)	// 0.5�b���ƂɎ��s
		{
			CountFps = FrameCount * 1000 / (CurrentTime - FPSLastTime);
			FPSLastTime = CurrentTime;
			FrameCount = 0;
		}

		if((CurrentTime - ExecLastTime) >= (1000 / 60))	// 60fps�Ńt���[���Ǘ�
		{
			ExecLastTime = CurrentTime;

			// �Q�[���X�V����
			SceneUpdate();//g_Scene��TITLE�Ȃ�^�C�g����ʂ�����
						  //         GAME��������Q�[���{�҂����� 

			// �Q�[���`�揈��
			SceneDraw();

#ifdef _DEBUG
			// FPS�\��
			DispFPS();
#endif
			//�ڍs��V�[�������邩���`�F�b�N����
			CheckScene();

			FrameCount++;
		}
	} while(!inport(PK_ESC));

	// ����\��߂�
	timeEndPeriod(1);

	// ��ʂ��N���A
	clrscr();
	// �J�[�\���\��
	setcursortype(NORMALCURSOR);

	printf("Enter�L�[�ŏI�����܂�\n");
	rewind(stdin);
	getchar();

	return 0;
}

#ifdef _DEBUG
// =============================================================================
// FPS�\��
// =============================================================================
void DispFPS(void)
{
	// �F�ݒ�
	textcolor(WHITE);

	gotoxy(1, 1);
	printf("FPS:%d", CountFps);
}
#endif

// =============================================================================
// �E�B���h�E�ݒ�̏������iHEW�p�ݒ�j
// =============================================================================
void WindowConsoleInitialize(void)
{
	// Set console window position
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// Set console window size
	SMALL_RECT windowSize = { 0, 0, 80, 25 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

	// Set console buffer size
	// �E�B���h�E�T�C�Y��80, 25�ŌŒ肷�邱��
	COORD coord;
	coord.X = 80;
	coord.Y = 25;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	// Set console font style and size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	// ���t�H���g�T�C�Y�̂ݕύX��
	cfi.dwFontSize.X = 15;                   // Width of each character in the font
	cfi.dwFontSize.Y = 30;                   // Height
	// ���t�H���g�T�C�Y�̂ݕύX��
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"MS Gothic");       // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int floatToInt(float f)
{
	return (int)(f + 0.5f);
}

//�N���A�t���O�̃Z�b�g
void SetClearFlag(int flag)
{
	clearFlag = flag;
}

//�N���A�t���O�̃Q�b�g
int GetClearFlag(void)
{
	return clearFlag;
}

//�t�@�C����ǉ�����
//explosion.cpp, explosion.h
