#include"iostream"
using namespace std;

template<class T>
void BubbleSort(int n,T s[],T f[])
{
	int i,j;
	int temp;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(f[j]>f[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
				temp=f[j];
				f[j]=f[j+1];
				f[j+1]=temp;
			}
		}
	}
}

template<class T>
void GreedySelector(int n,T s[],T f[],bool A[])
{
	int i,j;
	A[1]=true;
	j=1;//目前选中的
	for(i=2;i<=n;i++)
	{
		if(s[i]>f[j])
		{
			A[i]=true;
			j=i;
		}
		else{
			A[i]=false;
		}
	} 
} 

int main()
{
	int i,n;
	cout<<"请输入总共活动个数：";
	cin>>n;
	int s[100],f[100];
	bool A[100]={false};
	cout<<"请分别输入每个活动的起始时间："<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
		cin>>f[i];
	}
	BubbleSort(n,s,f);
	GreedySelector(n,s,f,A);
	cout<<endl<<"选中的活动编号为："<<endl;
	for(i=1;i<=n;i++)
	{
		if(A[i]==true)
			cout<<"选中活动起始时间："<<s[i]<<",选中活动结束时间："<<f[i]<<endl;
	} 
	return 0;
} 