// file_operations.cpp
#define _CRT_SECURE_NO_WARNINGS

#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------
// ファイルに CharacterStats を保存する関数
void SaveCharacterToFile(const char* filename, struct CharacterStats* character)
{
    FILE* file = fopen(filename, "wb"); // バイナリモードでファイルを開く

    if (file == NULL)
    {
        perror("ファイルを開く際にエラーが発生しました");
        exit(EXIT_FAILURE);
    }
    // ファイルに CharacterStats の内容を書き込む
    fwrite(character, sizeof(struct CharacterStats), 1, file);

    // ファイルを閉じる
    fclose(file);
}
//-------------------------------------------------------------

//-------------------------------------------------------------
// ファイルから CharacterStats を読み込む関数
void LoadCharacterFromFile(const char* filename, struct CharacterStats* character)
{
    FILE* file = fopen(filename, "rb"); // バイナリモードでファイルを開く

    if (file == NULL)
    {
        perror("ファイルを開く際にエラーが発生しました");
        exit(EXIT_FAILURE);
    }

    // ファイルから CharacterStats の内容を読み込む
    fread(character, sizeof(struct CharacterStats), 1, file);

    fclose(file);
}
//-------------------------------------------------------------
