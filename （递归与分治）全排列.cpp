#include"iostream"
using namespace std;
template<class T>
void Swap(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}
template<class T>
void Perm(T list[],int k,int m)
{
	if(k==m)
	{
		for(int i=0;i<=m;i++)
		{
			cout<<list[i];
		}
		cout<<endl;
	}
	else
	{
		for(int i=k;i<=m;i++)
		{
			Swap(list[k],list[i]);
			Perm(list,k+1,m);
			Swap(list[i],list[k]);
		}	
	}
}
int main()
{
	int list[3]={1,2,3};
	Perm(list,0,2);
	return 0;
}