#include"iostream"
#include"math.h"
using namespace std;

void Table(int k,int n,int **a)//k=log(n),n=队伍数量 
{
	int i,s,t,j;
	for(i=1;i<=n;i++)
	{
		a[1][i]=i;
	}
	int m=1;
	for(s=1;s<=k;s++)
	{
		n/=2;
		for(t=1;t<=n;t++)
		{
			for(i=m+1;i<=2*m;i++)
			{
				for(j=m+1;j<=2*m;j++)
				{
					a[i][j+(t-1)*2*m]=a[i-m][j+(t-1)*2*m-m];//左上角给右下角
					a[i][j+(t-1)*2*m-m]=a[i-m][j+(t-1)*2*m];//右上角给左下角 
				}
			}
		}
		m*=2;
	}
}

int main()
{
	int num,i,j;
	int k;
	int **a;
	
	cout<<"请输入比赛队伍数量：";
	cin>>num;
	a=new int*[num+1];
	for(i=0;i<num+1;i++)
	{
		a[i]=new int[num+1];
	}
	k=int(log2(num));	
	Table(k,num,a);
	cout<<"比赛日程表如下："<<endl;
	for(i=1;i<=num;i++)
	{
		for(j=1;j<=num;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	for(i=0;i<=num;i++)
	{
		delete []a[i];
	} 
	delete []a;
	a=0;
	return 0;
}