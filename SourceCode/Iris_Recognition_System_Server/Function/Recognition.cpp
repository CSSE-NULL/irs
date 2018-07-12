//���������λ�����£�ѡ����ֵC=0.364����ʶ�����ʶ�ʴﵽ�Ϻ�ˮƽ
#include"recognition.h"
#include<qdebug.h>
using namespace std;
int cn = (int)(LEN*8+0.5);
double p[4] = { 0,0.95,0.03 ,0.02 };//0λ��ʹ�� p1 p2 p3

/*
���㺣���������躯��
*/
double h(double d)
{
	double tt = 1.0*d / cn;
	double t1 = 0.5;
	double t2 = 4 * p[1] + 2 * p[2] - 3;
	double t3 = 2 * tt - 3;
	double res = t1 * (1 + t3 / t2);
	return res;
}

/*
���㺣������
*/
//��������begin*******************************
//hamming distance with mask but without shift
double NDBHamDisMask(char s[], char sm[], int longNDB[][2], const char smask[])
{
	int i, k;
	int dis = 0;
	int dn = 0;
    for (i = 0; i < LEN; i++)
	{
		if ((smask[i] == '1') && (sm[i] == '1'))
			dn++;
	}
    for (i = 0; i < LEN; i++)
	{
		if ((smask[i] == '1') && (sm[i] == '1'))
		{
            if (s[i] == '0')
			{
				dis += longNDB[i][1];
			}
            else if (s[i] == '1') {
				dis += longNDB[i][0];
			}
		}
	}
    return h(dis*LEN / dn);
}


double NDBHamDisMaskShift(OsiManager::Result irs, int longNDB[][2], const char smask[])
{
    int i;
	double dis = 1.0;
	for (i = 0; i < STN; i++)
	{
        double temp = NDBHamDisMask(irs.shift_code[i],irs.mask, longNDB, smask);
		if (dis > temp)
			dis = temp;
	}
	return dis;
}


double Ham(OsiManager::Result irs, int longNDB[][2], const char smask[])
{
    return NDBHamDisMaskShift(irs, longNDB, smask);
    //return NDBHamDisMask(irs.code,irs.mask, longNDB, smask);
}
//�������� end*************************************

void GetBinaryArray(const char irisCode[], int statisticCnt[][2])
{
    //���ַ���irisCode��ȡÿһλ��01������
    //��¼��statisticCnt[M][2]
    //��һ��ͳ��0
    //�ڶ���ͳ��1
    //codeLen��ͳ�ƻ���ǰirisCode����

    memset(statisticCnt, 0, sizeof(int) * 2 * LEN);
    int i=0;
    int j=0;
    int num=0;

    //ͳ��0
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

    //ͳ��1
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

int Recognition(OsiManager::Result iris, int longNDB[][2], const char smask[])
{
	double v = Ham(iris, longNDB, smask);
    qDebug() << QString::number(v)<<endl;
	if (v < THRESHOLD)
		return TRUE;
	else return FALSE;

}



