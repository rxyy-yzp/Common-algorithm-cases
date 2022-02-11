#include"iostream"
using namespace std;

void Swap(int &m,int &n)
{
	int temp;
	temp=m;
	m=n;
	n=temp;
}

int GCD(int m,int n)
{
	int r;
	r=m%n;
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	return n;
}

int main()
{
	int m,n;
	int gcd;
	cout<<"请输入两个数字：";
	cin>>m>>n;
	if(m<n)
	{
		Swap(m,n);
	}
	gcd=GCD(m,n);
	cout<<"最大公约数为"<<gcd<<endl;
	return 0; 
} 