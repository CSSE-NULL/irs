#pragma once
#define LEN 1536
#define EN 400
#define IN 2700
#define THRESHOLD 0.364
#define TRUE 1
#define FALSE 0
#include "OsiManager.h"
using namespace osiris;

double h(double d);

double NDBHamDisMask(char s[], char sm[], int longNDB[][2], const char smask[]);

double NDBHamDisMaskShift(OsiManager::Result irs, int longNDB[][2], const char smask[]);

double Ham(OsiManager::Result irs, char** longNDB, const char smask[]);

void GetBinaryArray(const char irisCode[], int statisticCnt[][2]);

int Recognition(OsiManager::Result iris, int longNDB[][2], const char smask[]);//µ÷ÓÃËû
