#include"iostream"
using namespace std;

template<class T>
void SelectSort(T w[],int *t,int n)
{
	T temp,temparray[n+1];
	int tp;
	memcpy(temparray,w,(n+1)*sizeof(T));
	int min;
	int i,j;
	for(i=1;i<=n;i++)
	{
		t[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		min=i;
		for(j=i+1;j<=n;j++)
		{
			if(temparray[min]>temparray[j])
			{
				min=j;
			}
		}
		temp=temparray[i];
		temparray[i]=temparray[min];
		temparray[min]=temp;
		tp=t[i];
		t[i]=t[min];
		t[min]=tp;
	}
}
template<class T>
void Loading(int x[], T w[], float c, int n)
{
	int *t=new int[n+1]; 
	SelectSort(w,t,n);//按照集装箱重量从轻到重的顺序
	for(int i=1; i<=n;i++) 
		x[i]=0;
	for(int i=1;i<=n&&w[t[i]]<=c;i++)
	{
		x[t[i]]=1;
		c-=w[t[i]];
	}
}

int main()
{
	int n,num=0,w[100],x[100];
	float c;
	cout<<"请输入船的载重量：";
	cin>>c;
	cout<<"请输入总集装箱数量：";
	cin>>n;
	cout<<"请输入每个箱子的重量："<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	Loading(x,w,c,n);
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1)
		{
			num++;
		}
	}
	cout<<"最多可装"<<num<<"个集装箱"<<endl;
	return 0;
} 