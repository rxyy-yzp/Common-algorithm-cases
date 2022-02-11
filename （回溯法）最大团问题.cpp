#include"iostream"
using namespace std;

class Clique
{
public:
	int **a;//图的邻接矩阵
	int n;//图的顶点数
	int *x;//当前解
	int *bestx;//最优解
	int cn;//当前完全子图顶点数
	int bestn;//最大团顶点数 
    void Backtrack(int i);
};

void Clique::Backtrack(int i)
{
	if(i>n)
	{
		for(int j=1;j<=n;j++)
		{
			bestx[j]=x[j];
		}
		bestn=cn;
		return ;
	}
	else
	{
		int OK=1;
		for(int j=1;j<i;j++)
		{
			if(x[j]&&a[i][j]==0)
			{
				OK=0;
				break;
			}
		}
		if(OK)
		{
			x[i]=1;
			cn++;
			Backtrack(i+1);
			x[i]=0;
			cn--;
		}
		if(cn+n-i>bestn)
		{
			x[i]=0;
			Backtrack(i+1);
		}
	}
} 

int main()
{
	Clique Y;
	int i,j;
	cout<<"请输入图的顶点数：";
	cin>>Y.n;
	

	Y.a=new int*[Y.n+1];
	for(i=0;i<=Y.n;i++)
	{
		Y.a[i]=new int[Y.n+1];
	}
	for(i=1;i<=Y.n;i++)
	{
		for(j=1;j<=Y.n;j++)
		{
			cin>>Y.a[i][j];
		}
	}
	Y.x=new int[Y.n+1];
	Y.bestx=new int[Y.n+1];
	for(i=0;i<=Y.n;i++)
	{
		Y.bestx[i]=0;
	}
	Y.cn=0;
	Y.bestn=0;
	Y.Backtrack(1);
	cout<<"最大团的顶点数有"<<Y.bestn<<"个"<<endl;
	for(int i=1;i<=Y.n;i++) 
	{
		if(Y.bestx[i]==1)
		{
			cout<<i<<' ';
		}
	}
	cout<<endl;
	return 0;
}

/*测试用例 
0 1 0 1 1
1 0 1 0 1
0 1 0 0 1
1 0 0 0 1
1 1 1 1 0
*/