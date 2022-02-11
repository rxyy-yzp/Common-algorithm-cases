
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
void BubbleSort(Jobtype *d,int n);//��������ð������
 
int main()
{
    int a[] = {2,4,3,6,1};
    int b[] = {5,2,3,1,7};
    int c[N];
 
    int minTime =  FlowShop(N,a,b,c);
 
    cout<<"��ҵ�ڻ���1�ϵ�����ʱ��Ϊ��"<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"��ҵ�ڻ���2�ϵ�����ʱ��Ϊ��"<<endl;
    for(int i=0; i<N; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
 
    cout<<"�����ҵ�����ʱ��Ϊ��"<<minTime<<endl;
    cout<<"��Ŵ�0��ʼ����ҵ���ȵ�˳��Ϊ��"<<endl;
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
        d[i].key = a[i]>b[i]?b[i]:a[i];//��Johnson����ֱ�ȡ��Ӧ��b[i]��a[i]ֵ��Ϊ�ؼ���
        d[i].job = a[i]<=b[i];//����������a[i]<b[i]�ķ��뵽N1�Ӽ����Ϊtrue
        d[i].index = i;
    }
 
    BubbleSort(d,n);//������d���ؼ��������������
 
    int j = 0,k = n-1;
 
    for(int i=0; i<n; i++)
    {
        if(d[i].job)//N1���ϣ�ai<=bi
        {
            c[j++] = d[i].index;//���Ź��������d��ȡ������ҵ�������N1�Ĵ�ǰ�����
        }
        else//N2���ϣ�ai>bi
        {
            c[k--] = d[i].index;//����N2�ĴӺ�����룬�Ӷ�ʵ��N1�ķǼ�������N2�ķ���������
        }
    }
 
    j = a[c[0]];
    k = j+b[c[0]];
    for(int i=1; i<n; i++)
    {
        j += a[c[i]];//M1��ִ��c[i]��ҵ��ͬʱ��M2��ִ��c[i-1]����ҵ�����ִ��ʱ��ȡ����M1��M2˭��ִ����
        k = j<k?k+b[c[i]]:j+b[c[i]];//�������żӹ�ʱ��
    }
 
    delete d;
    return k;
}
 
//ð������
void BubbleSort(Jobtype *d,int n)
{
    int i,j,flag;
    Jobtype temp;
 
    for(i=0;i<n;i++){
        flag = 0;
        for(j=n-1;j>i;j--){
            //���ǰһ�������ں�һ�������򽻻�
            if(d[j]<=d[j-1]){
                temp = d[j];
                d[j] = d[j-1];
                d[j-1] = temp;
                flag = 1;
            }
        }
        //�����������û�н���һ�ν�������break��������ִ��ʱ�䡣
        if(flag == 0){
            break;
        }
    }
}