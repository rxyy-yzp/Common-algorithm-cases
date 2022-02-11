#include"iostream"
using namespace std;

class Queen
{
public:
	int n;//皇后个数
	int x[100];
	long sum;
	bool Place(int k);
	void Backtrack(int t);
};
bool Queen::Place(int k)
{
	for(int j=1;j<k;j++)
	{
		if((abs(k-j)==abs(x[k]-x[j]))||(x[j]==x[k]))
		{
			return false;
		}
	}
	return true;
}
void Queen::Backtrack(int t)
{
	if(t>n)
	{
		sum++;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			x[t]=i;
			if(Place(t))
			{
				Backtrack(t+1);
			}
		}
	}
}

int main()
{
	Queen q;
	q.sum=0;
	cout<<"请输入n皇后的个数：";
	cin>>q.n;
	q.Backtrack(1);
	cout<<q.sum<<endl;
	return 0;
}