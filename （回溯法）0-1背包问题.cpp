#include"iostream"
using namespace std;

class Obj
{
public:
	double c;   //背包容量
	int n;   //物品数
	double w[100]; //物品重量数组
	double p[100]; //物品价值数组
	double cw; //当前重量
	double cp; //当前价值
	double bestp; //当前最优价值
	double Bound(int i);
	void Backtrace(int i);
	
};

void Sort(int n,double v[],double w[])
{
	int i,j;
	double temp;
	double *pv=new double[n+1];
	for(i=1;i<=n;i++)
	{
		pv[i]=v[i]/w[i];
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(pv[j]<pv[j+1])
			{
				temp=pv[j];
				pv[j]=pv[j+1];
				pv[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	
}

double Obj::Bound(int i)
{
	double cleft=c-cw;//计算背包剩余重量 
	double b=cp;//b是最大可装价值 
	while(i<=n && w[i]<=cleft)
	{
		cleft-=w[i];
		b+=p[i];
		i++;
	}
	if(i<=n)
	{
		b+=(p[i]/w[i])*cleft;
	}
	return b;
}

void Obj::Backtrace(int i)
{
	if(i>n)
	{
		bestp=cp;
		return ;
	}
	if(cw+w[i]<=c)
	{
		cw+=w[i];
		cp+=p[i];
		Backtrace(i+1);
		cw-=w[i];
		cp-=p[i];
	}
	if(Bound(i+1)>bestp)
	{
		Backtrace(i+1);
	}
}

int main()
{
	Obj o;
	cout<<"请输入背包容量：";
	cin>>o.c;
	cout<<"请输入物品数量：";
	cin>>o.n;
	cout<<"请分别输入每个物品的价值和重量："<<endl;
	for(int i=1;i<=o.n;i++) 
	{
		cin>>o.p[i]>>o.w[i];
	}
	Sort(o.n,o.p,o.w);
	o.Backtrace(1);
	cout<<"背包能装载的最高价值为："<<o.bestp<<endl;
	return 0;
}

/*测试数据 
45 16
25 15
25 15
*/