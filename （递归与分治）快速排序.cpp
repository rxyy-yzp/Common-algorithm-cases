#include"iostream"
#include"stdlib.h"
#include"time.h"
using namespace std;

template<class T>
int Partition(T a[],int p,int r)
{
	int i=p,j=r+1;
	T x=a[p];
	while(1)
	{
		while(a[++i]<x);
		while(a[--j]>x);
		if(i>=j)
			break;
		T temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}

template<class T>
int RandomizedPartition(T a[],int p,int r)
{
	srand(time(NULL)); 
	int i=p+(rand()%(r-p));
	T temp=a[i];
	a[i]=a[p];
	a[p]=temp;
	return Partition(a,p,r);
}

template<class T>
void RandomizedQuickSort(T a[],int p,int r)
{
	if(p<r)
	{
		int q=RandomizedPartition(a,p,r);
		RandomizedQuickSort(a,p,q-1);//¶Ô×ó°ë¶ÎÅÅÐò 
		RandomizedQuickSort(a,q+1,r);//¶ÔÓÒ°ë¶ÎÅÅÐò 
	}
} 

int main()
{
	int a[10]={57,13,64,89,96,4,23,6,78,45};
	RandomizedQuickSort(a,0,9);
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
} 
