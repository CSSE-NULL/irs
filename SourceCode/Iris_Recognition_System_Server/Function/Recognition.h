#pragma once
#define LEN 1536
#define EN 400
#define IN 2700
#define THRESHOLD 0.364
#define TRUE 1
#define FALSE 0
#include "Scan/OsiManager.h"
#include "Function/NDBManipulate.h"
using namespace osiris;
/*
虹膜相关信息
*/
typedef struct {
    char code[M];
    char shift_code[STN][M];
    char mask[M];
}IRIS;

double h(double d);

double NDBHamDisMask(char s[], char sm[], int longNDB[LEN][2], const char smask[]);

double NDBHamDisMaskShift(OsiManager::Result irs, int longNDB[LEN][2], const char smask[]);

double NDBHamDis(int init_longNDB[][2],int longNDB[LEN][2]);

double NDBHamDisShift(OsiManager::Result iris,int longNDB[LEN][2]);

double Ham(OsiManager::Result iris,int init_longNDB[LEN][2], int longNDB[LEN][2]);

void GetBinaryArray(const char irisCode[], int statisticCnt[][2]);

int Recognition(OsiManager::Result iris,int init_longNDB[LEN][2], int longNDB[LEN][2]);
