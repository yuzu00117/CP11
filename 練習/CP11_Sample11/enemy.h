#pragma once

//�G�̐����`����
#define NUM_ENEMY (20)

void EnemyInit(void);	//������
void EnemyUninit(void);	//�I������
void EnemyUpdate(void);	//�X�V
void EnemyDraw(void);	//�`��
void EnemyDelete(int id);