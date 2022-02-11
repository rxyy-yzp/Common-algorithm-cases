#include"iostream"
using namespace std;

int equationCount(int n,int m)
{
	if(n<0||m<0)
		return 0;
	else if(n==1||m==1)
		return 1;
	else if(n<m)
		return equationCount(n,n);
	else if(n==m)
		return 1+equationCount(n,n-1);
	else
		return equationCount(n-m,m)+equationCount(n,m-1);	
}

int main()
{
	int n,num;
	cout<<"请输入一个整数：";
	cin>>n;
	num=equationCount(n,n);
	cout<<"该整数有"<<num<<"个整数划分"<<endl;
	return 0;
}