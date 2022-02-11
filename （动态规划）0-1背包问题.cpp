#include"iostream"
using namespace std;

void Knapsack(int *v,int *w,int c,int n,int **m) 
{
	int jMax=min(w[n]-1,c);
	for(int j=0;j<=jMax;j++)
		m[n][j]=0;
	for(int j=w[n];j<=c;j++)
		m[n][j]=v[n];
	for(int i=n-1;i>1;i--)
	{
		jMax=min(w[n]-1,c);
		for(int j=0;j<=jMax;j++)
			m[i][j]=m[i+1][j];
		for(int j=w[i];j<=c;j++)
			m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
	}
	m[1][c]=m[2][c];
	if(c>=w[1])
		m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
}

void Traceback(int **m,int *w,int c,int n,int *x)
{
	for(int i=1;i<n;i++)
	{
		if(m[i][c]==m[i+1][c])
			x[i]=0;
		else
		{
			x[i]=1;
			c-=w[i];
		}
	}
	x[n]=(m[n][c])?1:0;
}

int main()
{
	int n,c;
	cout<<"请输入物品数量和背包承重：";
	cin>>n>>c;
	int *x=new int[n+1];
	for(int i=0;i<=n;i++)
		x[i]=0;
	int *w=new int[n+1];
	int *v=new int[n+1];
	cout<<"请输入每件物品重量和价值："<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	int **m=new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		m[i]=new int[c+1];
	}
	Knapsack(v,w,c,n,m);
	Traceback(m,w,c,n,x);
	for(int i=1;i<=n;i++)
	{
		cout<<x[i]<<' ';
	}
	cout<<endl;
	return 0;
}

/*
5 10

2 6
2 3
6 5
5 4
4 6
*/