// GenWaveTable.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define SAMPLE_NUM	1024

int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;

	// �T�C���g�̐���
	printf("/*** sine wave ***/\n");
	for (i = 0; i < SAMPLE_NUM; i++) {
		printf("\t%d\n", (int)((sin(2.0 * M_PI * i / SAMPLE_NUM) / 2 + 0.5) * 0x0FFF));
	}
	printf("\n");

	// �O�p�g�̐���
	printf("/*** triangle wave ***/\n");
	for (i = 0, j = 0x0800; i < SAMPLE_NUM / 4; i++, j += 8) {
		printf("\t%d\n", j);
	}
	for (; i < 3 * SAMPLE_NUM / 4; i++, j -= 8) {
		printf("\t%d\n", j < 0x1000 ? j : 0x0FFF);
	}
	for (; i < SAMPLE_NUM; i++, j += 8) {
		printf("\t%d\n", j);
	}
	printf("\n");

	// ��`�g�̐���
	printf("/*** squre wave ***/\n");
	for (i = 0; i < SAMPLE_NUM / 2; i++) {
		printf("\t%d\n", 0x0FFF);
	}
	for (; i < SAMPLE_NUM; i++) {
		printf("\t%d\n", 0);
	}
	printf("\n");

	// �m�R�M���g�̐����i�㏸�j
	printf("/*** sawtooth upword wave ***/\n");
	for (i = 0, j = 0; i < SAMPLE_NUM; i++, j += 4) {
		printf("\t%d\n", j);
	}
	printf("\n");

	// �m�R�M���g�̐����i���~�j
	printf("/*** sawtooth downword wave ***/\n");
	for (i = 0, j = 0x0FFF; i < SAMPLE_NUM; i++, j -= 4) {
		printf("\t%d\n", j);
	}
	
	return 0;
}

