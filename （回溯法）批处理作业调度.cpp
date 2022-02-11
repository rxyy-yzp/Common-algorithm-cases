#include"iostream"
using namespace std;

class Flowshop
{
public:
	int M[100][100];
	int bestx[100];
	int f2[100];
	int x[100];
	int f1;
	int f;//完成时间和  
	int bestf;
	int n;
	
	void Backtrack(int);
};

void Flowshop::Backtrack(int i)
{
	if(i>n)
	{
		for(int j=1;j<=n;j++)
		{
			bestx[j]=x[j];
		}
		bestf=f;
	}
	else
	{
		for(int j=i;j<=n;j++)
		{
			f1+=M[x[j]][1];
			f2[i]=((f2[i-1]>f1)?f2[i-1]:f1)+M[x[j]][2];
			f+=f2[i];
			if(f<bestf)
			{
				int temp=x[i];
				x[i]=x[j];
				x[j]=temp;
				Backtrack(i+1);
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
			f1-=M[x[j]][1];
			f-=f2[i];
		}
	}
}

int main()
{
	Flowshop fl;
	fl.bestf=100000;
	fl.f=0;
	fl.f1=0;
	for(int i=0;i<100;i++)
	{
		fl.bestx[i]=0;
	    fl.f2[i]=0;
	    fl.x[i]=i;
	    for(int j=0;j<100;j++)
	    {
    		fl.M[i][j]=0;
    	}
	}
	cout<<"请输入作业数：";
	cin>>fl.n;
	cout<<"请输入各作业在个机器上所需处理时间："<<endl;
	for(int i=1;i<=fl.n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>fl.M[i][j];
		}
	} 
	
	
	fl.Backtrack(1);
	cout<<"加工顺序为："<<endl;
	for(int i=1;i<=fl.n;i++)
	{
		cout<<fl.bestx[i]<<' ';
	}
	cout<<endl;
	cout<<"最少所需时间为："<<fl.bestf<<endl;
	return 0;
} 