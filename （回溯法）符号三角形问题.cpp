#include"iostream"
using namespace std;

class Triangle
{
public:
	int n;//符号个数
	int count;//+的个数 
	int p[100][100];
	int half;
	long sum;
	void Backtrack(int t);
};

void Triangle::Backtrack(int t)
{
	if((count>half)||(t*(t-1)/2-count>half))
		return;
	if(t>n)
		sum++;
	else
	{
		for(int i=0;i<2;i++)
		{
			p[1][t]=i;
			count+=i;
			for(int j=2;j<=t;j++)
			{
				p[j][t-j+1]=p[j-1][t-j+1]^p[j-1][t-j+2];
				count+=p[j][t-j+1];
			}
			Backtrack(t+1);
			for(int j=2;j<=t;j++)
			{
				count-=p[j][t-j+1];
			}
			count-=i;
		}
	}
}

int main()
{
	Triangle t;
	cout<<"请输入符号三角形第一行个数：";
	cin>>t.n;
	t.sum=0;
	for(int i=0;i<t.n;i++)
	{
		for(int j=0;j<t.n;j++)
		{
			t.p[i][j]=0;
		}
	}
	t.half=t.n*(t.n+1)/2;
	if(t.half%2==1)
	{
		cout<<"无解！"<<endl;
		return 0;
	}
	t.half/=2;
	t.Backtrack(1);
	cout<<t.sum<<endl;
	return 0;
} 