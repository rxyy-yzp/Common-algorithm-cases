#include"iostream"
using namespace std;

int Maxsum(int n,int *a)
{
	int sum=0;
	int b=0;
	for(int i=1;i<=n;i++)
	{
		if(b>0)
			b+=a[i];
		else
			b=a[i];
		if(b>sum)
			sum=b;
	}
	return sum;
} 

int main()
{
	cout<<"请输入数字个数和数组："<<endl;
	int n;
	int *a=new int[n+1];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	cout<<"最大子段和为："<<Maxsum(n,a)<<endl;
	return 0;
}

//测试样例：-1 11 -4 13 -5 -2 