// file_operations.h

#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "character.h"

// キャラクターのセーブ&ロード
void SaveCharacterToFile(const char* filename, struct CharacterStats* character);
void LoadCharacterFromFile(const char* filename, struct CharacterStats character);

// キャラクターのステータス生成
void GenerateStatusFromBarcode(struct CharacterStats* character, int barcode);
void CharacterCreate(struct CharacterStats* character);

#endif // FILE_OPERATION_H