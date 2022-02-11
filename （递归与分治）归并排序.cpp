#include"iostream"
using namespace std;

int b[7]={0};

template<class T>
void Merge(T a[],T b[],int left,int mid,int right)
{   int j,k;
    for(j=mid+1,k=left;left<=mid&&j<=right;)
    {   
		if(a[left]<=a[j])    
			b[k++]=a[left++];
   		else                                      
		    b[k++]=a[j++];
    }
    if(left<=mid)//如有剩余记录，复制
    {
    	for(;left<=mid;left++,k++) 
			b[k]=a[left]; 
    }
    if(j<=right)//如有剩余记录，复制
    {
    	for(;j<=right;j++,k++)  
			b[k]=a[j]; 
    }
}

template<class T>
void Copy(T a,T b,int left,int right)
{
	int i;
	for(i=left;i<=right;i++)
	{
		a[i]=b[i];
	}
}

template<class T>
void MergeSort(T a[],int left,int right)
{
	int i;
	if(left<right)
	{
		i=(left+right)/2;
		MergeSort(a,left,i);
		MergeSort(a,i+1,right);
		Merge(a,b,left,i,right);
		Copy(a,b,left,right);
	}
}

int main()
{
	int a[7]={49,38,65,97,76,13,27};
	MergeSort(a,0,6);
	for(int i=0;i<7;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}
