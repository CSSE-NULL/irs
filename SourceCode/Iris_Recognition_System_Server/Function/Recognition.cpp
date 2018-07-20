//在掩码和移位策略下，选择阈值C=0.364下误识率与拒识率达到较好水平
#include"recognition.h"
#include<qdebug.h>
using namespace std;
int t = 8;
int cn = (int)(LEN*t+0.5);
double p[4] = { 0,0.95,0.03 ,0.02 };//0位不使用 p1 p2 p3

/*
计算海明距离所需函数
*/
double h(int d)
{
    double nsame= (2*p[1]+p[2])/3*t*3;
    double ndiff= t*3-nsame;
    double t1 = 2*nsame*ndiff;
    double t2 = nsame*nsame+ndiff*ndiff;
    double res = (t1*LEN-d)/(t1-t2);
//    qDebug() << nsame << "   " << ndiff << "   " << t1 << "   " << t2 << "   " << res << endl;
    return res/LEN;

}
/*
计算海明距离
*/

double NDBHamDis(int init_longNDB[LEN][2],int longNDB[LEN][2]){
   int dis=0;
   int i;
   for (i = 0; i < LEN; i++){
       dis += init_longNDB[i][0]*longNDB[i][1]+init_longNDB[i][1]*longNDB[i][0];
   }
//   qDebug()<<dis<<"   "<<h(dis)<<endl;
   return h(dis);
}

double NDBHamDisShift(OsiManager::Result iris,int longNDB[LEN][2])
{
    int i;
    double dis = 1.0;
    for(i=0;i<STN;i++)
    {
        char* irisdata = Transfer(iris.shift_code[i]);
        int init_longNDB[LEN][2];
        GetBinaryArray(irisdata, init_longNDB);
        double temp = NDBHamDis(init_longNDB,longNDB);
        if(dis>temp) dis = temp;

    }

    return dis;
}

double Ham(OsiManager::Result iris,int init_longNDB[LEN][2], int longNDB[LEN][2])
{
    return NDBHamDisShift(iris,longNDB);
//    return NDBHamDis(init_longNDB,longNDB);
}

void GetBinaryArray(const char irisCode[], int statisticCnt[][2])
{
    //从字符串irisCode读取每一位上01的数量
    //记录到statisticCnt[M][2]
    //第一列统计0
    //第二列统计1
    //codeLen是统计汇总前irisCode长度

    memset(statisticCnt, 0, sizeof(int) * 2 * LEN);
    int i=0;
    int j=0;
    int num=0;

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

int Recognition(OsiManager::Result iris,int init_longNDB[LEN][2], int longNDB[LEN][2])
{
    double v = Ham(iris,init_longNDB, longNDB);
    qDebug() << QString::number(v)<<endl;
	if (v < THRESHOLD)
		return TRUE;
	else return FALSE;

}



