// character_operations.h

#ifndef CHARACTER_OPERATIONS_H
#define CHARACTER_OPERATIONS_H

#include "file_operations.h"

// キャラクター作成
int askForCharacterCreation(struct CharacterStats *character);

// キャラ作成関数の宣言を追加
void CharacterCreate(struct CharacterStats* character);

// バーコードの数値をもとにステータスを生成
void GenerateStatusFromBarcode(struct CharacterStats* character, int barcode);

#endif // CHARACTER_OPERATIONS_H
