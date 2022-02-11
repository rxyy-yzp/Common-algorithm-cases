#include"iostream"
using namespace std;
template<class T>
int BinarySearch(T a[], const T& x, int low, int high)
{
	T mid;
	while(high>=low)
	{
		mid=(low+high)/2;
		if(a[mid]==x)
			return 1;
		if(a[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

int main()
{
	int n;
	int a[]={
		1,2,3,4,5,6,7,8,9,10
	};
	cout<<"请输入要查找的数字：";
	cin>>n;
	int flag=BinarySearch(a,n,0,9);
	if(flag==1)
		cout<<"查找成功！"<<endl;
	else
	{
		cout<<"查找失败！"<<endl;
	}
	return 0;
}