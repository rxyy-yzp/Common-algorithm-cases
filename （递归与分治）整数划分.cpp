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
	cout<<"������һ��������";
	cin>>n;
	num=equationCount(n,n);
	cout<<"��������"<<num<<"����������"<<endl;
	return 0;
}