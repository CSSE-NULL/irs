#pragma once
#include <iostream>
#include <cstdio>
#include <string.h>
#include <time.h>
#include "OsiManager.h"
using namespace osiris;

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#define LEN 1536

typedef struct {
	int p[3];		//三个随机位置
	char c[4];		//负数据改动信息
}Ent;

//所用到全局变量
//p-hidden算法概率初始化
extern double pridiction[4];
extern double r;

//functions
char* Transfer(OsiManager::Result &obj);

//void SeparateMaskCode(char scanResult[], char irisCode[], char maskCode[]);

void CreateNegativeString(char irisCode[], double r, char zeroNum[], char oneNum[]);

void GetBinaryArray(char irisCode[], int statisticCnt[][2]);

//tools
int Rand1(int n);

double Rand1();

void GenerateRandomNumbers(Ent &v, int l);
