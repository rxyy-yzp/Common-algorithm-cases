#include"iostream"
using namespace std;
void Sort(int n,float v[],float w[])
{
	int i,j;
	float temp;
	float *pv=new float[n+1];
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
void KnapSack(int n,float M,float v[],float w[],float x[])
{
	int i;
	float c=M;
	Sort(n,v,w);
	for(i=1;i<=n;i++)
	{
		x[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		if(w[i]>c)
			break;
		x[i]=1;
		c-=w[i];
	}
	if(i<=n)
	{
		x[i]=c/w[i];
	}
}

int main()
{
	int i,n;
	float M,sv=0;
	float v[100],w[100],x[100];
	cout<<"请输入背包承重：";
	cin>>M;
	cout<<"请输入物品个数：";
	cin>>n;
	cout<<"请分别输入每个物品的价值和重量："<<endl;
	for(i=1;i<=n;i++) 
	{
		cin>>v[i]>>w[i];
	}
	KnapSack(n,M,v,w,x);
	for(i=1;i<=n;i++)
	{
		cout<<"价值为"<<v[i]<<",重量为"<<w[i]<<"的货物装："<<x[i]*w[i]<<endl;
		sv+=x[i]*v[i];
	}
	cout<<"总价值为："<<sv<<endl; 
	return 0;
} 
