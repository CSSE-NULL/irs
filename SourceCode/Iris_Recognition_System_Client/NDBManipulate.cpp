#include "NDBManipulate.h"
using namespace std;

/******************************
登记：
虹膜扫描给出一个scanResult[]（包括虹膜信息明文+掩码）
调用Register()登记

识别：
调用GetBinaryArray得到一个虹膜图像的负数据信息统计结果statisticCnt[][]
送到识别函数计算海明距离

******************************/
double pridiction[4] = { 0, 0.95, 0.03, 0.02 };
double r = 8;		//负数据库生成参数

//functions
char* Transfer(OsiManager::Result &obj) {

    char irisCode[10000];

	//初始化随机种子
    //srand((unsigned)(time_t(0)));
	
	//生成负数据库字符串
	char zeroNum[10001] = { 0 };
	char oneNum[10001] = { 0 };
    CreateNegativeString(obj.code, r, zeroNum, oneNum);

    //拼接到irisCode
	strcpy(irisCode, zeroNum);
	strcat(irisCode, oneNum);
    return irisCode;
}

void CreateNegativeString(char irisCode[], double r, char zeroNum[], char oneNum[])
{
	//对于给定参数r（确定NDB中负数据条数）和虹膜编码irisCode
	//统计NDB中负数据每一位上01的数量
	//每两位之间以'#'分隔
	//01数量信息保存到zeroNum,oneNum字符串
	//返回irisCode长度

	int codeLen = strlen(irisCode);
	int num = int(codeLen*r + 0.5);
	int zeroCnt[2001];
	int oneCnt[2001];
	memset(zeroCnt, 0, sizeof(zeroCnt));
	memset(oneCnt, 0, sizeof(oneCnt));
	double randPbt;
	char curNum[101] = { 0 };
	//控制变量
	int i, u, cn = 0;
	Ent v;											//structures.h

	do
	{
		GenerateRandomNumbers(v, codeLen);			//tools.h
		randPbt = Rand1();							//tools.h
        if (randPbt < pridiction[1])
		{
			//一位不同
			//另外两位相同
			u = Rand1(3);
			for (i = 0; i < 3; i++)
			{
				v.c[i] = irisCode[v.p[i]];
			}
			v.c[u] = '1' + '0' - irisCode[v.p[u]];
		}
        else if (randPbt < pridiction[1] + pridiction[2])
		{
			//一位相同
			//另外两位不同
			u = Rand1(3);
			for (i = 0; i < 3; i++)
			{
				v.c[i] = '1' + '0' - irisCode[v.p[i]];
			}
			v.c[u] = irisCode[v.p[u]];
		}
		else
		{
			//三位不同
			for (i = 0; i < 3; i++)
			{
				v.c[i] = '1' + '0' - irisCode[v.p[i]];
			}
		}

		//统计01
		for (i = 0; i < 3; i++) {
			if (v.c[i] == '0')
				zeroCnt[v.p[i]]++;
			else
				oneCnt[v.p[i]]++;
		}

		cn++;
	} while (cn < num);


	//统计结果写入字符串
	//每位统计结果以'#'分割
	for (int i = 0; i < codeLen; i++) {
		//0
		itoa(zeroCnt[i], curNum, 10);
		strcat(curNum, "#");
		strcat(zeroNum, curNum);
		//1
		itoa(oneCnt[i], curNum, 10);
		strcat(curNum, "#");
		strcat(oneNum, curNum);
	}

	return;
}

void GetBinaryArray(char irisCode[], int statisticCnt[][2])
{
	//从字符串irisCode读取每一位上01的数量
	//记录到statisticCnt[M][2]
	//第一列统计0
	//第二列统计1
	//codeLen是统计汇总前irisCode长度

    memset(statisticCnt, 0, sizeof(int) * 2 * LEN);
	int i, j, num;

	//统计0
	for (i = j = 0; ; j++) {
		num = 0;
		while (irisCode[j] != '#') {
			num = num * 10 + irisCode[j] - '0';
			j++;
		}
		statisticCnt[i++][0] = num;
        if (i >= LEN) break;
	}
	j++;

	//统计1
	for (i = 0; ; j++) {
		num = 0;
		while (irisCode[j] != '#') {
			num = num * 10 + irisCode[j] - '0';
			j++;
		}
		statisticCnt[i++][1] = num;
        if (i >= LEN) break;
	}

	return;
}

//tools
int Rand1(int n)
{
	return (int)(((double)rand() / (RAND_MAX + 1.0))*n);
}

double Rand1()
{
	return (double)rand() / (RAND_MAX + 1.0);
}

void GenerateRandomNumbers(Ent &v, int l)
{
	int temp;
	v.p[0] = Rand1(l);
	temp = Rand1(l);
	while (temp == v.p[0])
	{
		temp = Rand1(l);
	}
	v.p[1] = temp;
	temp = Rand1(l);
	while ((temp == v.p[0]) || (temp == v.p[1]))
	{
		temp = Rand1(l);
	}
	v.p[2] = temp;

	return;
}



