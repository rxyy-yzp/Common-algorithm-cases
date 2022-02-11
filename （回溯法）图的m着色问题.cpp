#include"iostream"
using namespace std;

class Color
{
public:
	int n;//图的顶点数
	int m;//可用颜色数
	int **a;
	int *x;
	long sum;
	bool Color::Ok(int k);
	void Color::Backtrack(int t);	
};

bool Color::Ok(int k)
{
	for(int j=1;j<=n;j++)
	{
		if((a[k][j]==1)&&(x[j]==x[k]))
		{
			return false;
		}
	}
	return true;
}

void Color::Backtrack(int t)
{
	if(t>n)
	{
		sum++;
		for(int i=1;i<=n;i++)
		{
			cout<<x[i]<<' ';
		} 
		cout<<endl;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			x[t]=i;
			if(Ok(t))
			{
				Backtrack(t+1);
			}
			x[t]=0;
		}
	}
}

int main()
{
	int i,j;
	Color X;
	cout<<"请输入图的顶点数：";
	cin>>X.n;
	cout<<"请输入可用的颜色数：";
	cin>>X.m;
	X.sum=0;
	int *p=new int[X.n+1];
	for(i=0;i<=X.n;i++)
	{
		p[i]=0;
	}
	X.x=p;

	X.a=new int*[X.n+1];
	for(i=0;i<=X.n;i++)
	{
		X.a[i]=new int[X.n+1];
	}
	for(i=1;i<=X.n;i++)
	{
		for(j=1;j<=X.n;j++)
		{
			cin>>X.a[i][j];
		}
	}
	
	X.Backtrack(1);
	delete []p;
	cout<<X.sum<<endl;
	return 0;
}

/*
测试用例 
0 1 1 1 0
1 0 1 1 1
1 1 0 1 0
1 1 1 0 1
0 1 0 1 0
*/