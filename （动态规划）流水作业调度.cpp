
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
 
const int N = 5;
 
class Jobtype
{
    public:
        int operator <=(Jobtype a) const
        {
            return(key<=a.key);
        }
        int key,index;
        bool job;
};
 
int FlowShop(int n,int a[],int b[],int c[]);
void BubbleSort(Jobtype *d,int n);//本例采用冒泡排序
 
int main()
{
    int a[] = {2,4,3,6,1};
    int b[] = {5,2,3,1,7};
    int c[N];
 
    int minTime =  FlowShop(N,a,b,c);
 
    cout<<"作业在机器1上的运行时间为："<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"作业在机器2上的运行时间为："<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
 
    cout<<"完成作业的最短时间为："<<minTime<<endl;
    cout<<"编号从0开始，作业调度的顺序为："<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    return 0;
}
 
int FlowShop(int n,int a[],int b[],int c[])
{
    Jobtype *d = new Jobtype[n];
    for(int i=0; i<n; i++)
    {
        d[i].key = a[i]>b[i]?b[i]:a[i];//按Johnson法则分别取对应的b[i]或a[i]值作为关键字
        d[i].job = a[i]<=b[i];//给符合条件a[i]<b[i]的放入到N1子集标记为true
        d[i].index = i;
    }
 
    BubbleSort(d,n);//对数组d按关键字升序进行排序
 
    int j = 0,k = n-1;
 
    for(int i=0; i<n; i++)
    {
        if(d[i].job)//N1集合，ai<=bi
        {
            c[j++] = d[i].index;//将排过序的数组d，取其中作业序号属于N1的从前面进入
        }
        else//N2集合，ai>bi
        {
            c[k--] = d[i].index;//属于N2的从后面进入，从而实现N1的非减序排序，N2的非增序排序
        }
    }
 
    j = a[c[0]];
    k = j+b[c[0]];
    for(int i=1; i<n; i++)
    {
        j += a[c[i]];//M1在执行c[i]作业的同时，M2在执行c[i-1]号作业，最短执行时间取决于M1与M2谁后执行完
        k = j<k?k+b[c[i]]:j+b[c[i]];//计算最优加工时间
    }
 
    delete d;
    return k;
}
 
//冒泡排序
void BubbleSort(Jobtype *d,int n)
{
    int i,j,flag;
    Jobtype temp;
 
    for(i=0;i<n;i++){
        flag = 0;
        for(j=n-1;j>i;j--){
            //如果前一个数大于后一个数，则交换
            if(d[j]<=d[j-1]){
                temp = d[j];
                d[j] = d[j-1];
                d[j-1] = temp;
                flag = 1;
            }
        }
        //如果本次排序没有进行一次交换，则break，减少了执行时间。
        if(flag == 0){
            break;
        }
    }
}