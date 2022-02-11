#include"iostream"
using namespace std;

void MatrixChain(int *p,int n,int **m,int **s)
{
	for(int i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	for(int r=2;r<=n;r++)//���ƶԽ���
	{
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
				
			m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	} 
}

void Traceback(int i,int j,int **s)
{
	if(i==j)
	{
		return ;
	}
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Mulitiply A"<< i<<","<<s[i][j];
	cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}

int main()
{
	int n,i,j;
	cout<<"��������������";
	cin>>n;
	cout<<"���������ά�����飺"<<endl;
	int *p=new int[n+1];
	for(i=0;i<=n;i++)
	{
		cin>>p[i];
	}
	int **m=new int*[n+1];
	for(i=0;i<=n;i++)
	{
		m[i]=new int[n+1];
	}
	int **s=new int*[n+1];
	for(i=0;i<=n;i++)
	{
		s[i]=new int[n+1];
	}
	MatrixChain(p,n,m,s);
	Traceback(1,n,s);
	cout<<"�����������ٴ���Ϊ��"<<m[1][n]<<endl;
	return 0;
} 

/* 
��������1
n=6
p[7]:30 35 15 5 10 20 25

��������2
n=4
p[5]:50 10 40 30 5
*/