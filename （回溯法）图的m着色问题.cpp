#include"iostream"
using namespace std;

class Color
{
public:
	int n;//ͼ�Ķ�����
	int m;//������ɫ��
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
	cout<<"������ͼ�Ķ�������";
	cin>>X.n;
	cout<<"��������õ���ɫ����";
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
�������� 
0 1 1 1 0
1 0 1 1 1
1 1 0 1 0
1 1 1 0 1
0 1 0 1 0
*/