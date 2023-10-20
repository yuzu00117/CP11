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
	// 構造体が持つ要素にアクセスする場合には . を使う
	g_BirthDay.year = 2000;
	g_BirthDay.month = 1;
	g_BirthDay.day = 31;

	printf("誕生日は%d年%d月%d日です", g_BirthDay.year, g_BirthDay.month, g_BirthDay.day);

	int data = 0;

	g_pBirth = &g_BirthDay;

	// ポインタ変数からメンバにアクセスするときは -> アロー演算子を使う
	printf("誕生日は%d年%d月%d日です", g_pBirth->year, g_pBirth->month, g_pBirth->day);

	return 0;
}