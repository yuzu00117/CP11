#include <stdio.h>

struct BIRTHDAY
{
	int year;
	char month;
	char day;
};

BIRTHDAY g_BirthDay = { 2000, 1, 31 };
BIRTHDAY *g_pBirth = NULL;

int main() {
	// �\���̂����v�f�ɃA�N�Z�X����ꍇ�ɂ� . ���g��
	g_BirthDay.year = 2000;
	g_BirthDay.month = 1;
	g_BirthDay.day = 31;

	printf("�a������%d�N%d��%d���ł�", g_BirthDay.year, g_BirthDay.month, g_BirthDay.day);

	int data = 0;

	g_pBirth = &g_BirthDay;

	// �|�C���^�ϐ����烁���o�ɃA�N�Z�X����Ƃ��� -> �A���[���Z�q���g��
	printf("�a������%d�N%d��%d���ł�", g_pBirth->year, g_pBirth->month, g_pBirth->day);

	return 0;
}