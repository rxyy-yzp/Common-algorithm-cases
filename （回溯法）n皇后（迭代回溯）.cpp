#include"iostream"
using namespace std;

class Queen
{
public:
	int n;//皇后个数
	int x[100];
	long sum;
	bool Place(int k);
	void Backtrack();

};
bool Queen::Place(int k)
{
	for(int j=1;j<k;j++)
	{
		if((abs(j-k)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	}
	return true;
}
void Queen::Backtrack()
{
	//k表示t层,x[k]表示第k层摆的位置
	int k=1;
	x[1]=0;
	while(k>0)
	{
		x[k]+=1;
		while(x[k]<=n && !Place(k))
			x[k]+=1;
		if(x[k]<=n)
		{
			if(k==n)
			{
				sum++;
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
		{
			k--;
		}
	} 
}

int main()
{
	Queen q;
	q.sum=0;
	cout<<"请输入n皇后的个数：";
	cin>>q.n;
	q.Backtrack();
	cout<<q.sum<<endl;
	return 0;
} 