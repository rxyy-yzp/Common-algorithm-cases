#include"iostream"
#include"stdio.h"
using namespace std;

#define N 6        //������/����

int weight[][N]={{0,2,2,3,1,4},{2,0,1,5,2,3},{2,1,0,2,1,4},{3,5,2,0,6,2},
{1,2,1,6,0,1},{4,3,4,2,1,0}};

int t[N][N];    //t[i][j]��ʾ�����{Vi-1VkVj}������Ȩֵ
int s[N][N];    //s[i][j]��¼Vi-1��Vj���������ʷֵ��м��K

int getweight(const int a,const int b,const int c)
{
    return weight[a][b]+weight[b][c]+weight[c][a];
}

void MinWeightTriangulation()
{
    int i,r,k,j;
    int min;
    for(i=1;i<N;i++)
    {
        t[i][i]=0;
    }
    for(r=2;r<N;r++)
    {
        for (i=1;i<N-r+1;i++)
        {
            j=i+r-1;
            min=9999;        //������Сֵ
            for(k=i;k<j;k++)
            {
                t[i][j]=t[i][k]+t[k+1][j]+getweight(i-1,k,j);
                if(t[i][j]<min)        //�ж��Ƿ�����Сֵ
                {
                    min=t[i][j];
                    s[i][j]=k;    
                }
            }
            t[i][j]=min;        //ȡ�ö����{Vi-1��Vj}�Ļ���������СȨֵ
        }
    }
}

void Traceback(int a, int b)
{
    if (a==b) return;
    Traceback(a,s[a][b]);
    Traceback(s[a][b]+1,b);    //�ǵ�����Ҫ��һ
    printf("��������: V%d V%d V%d.\n",a-1,s[a][b],b);
}

int main()
{
    MinWeightTriangulation();
    Traceback(1,5);
    return 0;
}

/*
0 2 2 3 1 4
2 0 1 5 2 3
2 1 0 2 1 4
3 5 2 0 6 2
1 2 1 6 0 1
4 3 4 2 1 0
*/