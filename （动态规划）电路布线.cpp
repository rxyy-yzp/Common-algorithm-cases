#include"iostream"
using namespace std;

const int N=10;

void MNS(int C[],int n,int **size)
{
	for(int j=0;j<C[1];j++)
	{
		size[1][j]=0;
	}
	for(int j=C[1];j<=n;j++)
	{
		size[1][j]=1;
	}
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<C[i];j++)
		{
			size[i][j]=size[i-1][j];
		}
		for(int j=C[i];j<=n;j++)
		{
			size[i][j]=max(size[i-1][j],size[i-1][C[i]-1]+1);
		}
	}
	size[n][n]=max(size[n-1][n],size[n-1][C[n]-1]+1);
}

void Traceback(int C[],int **size,int n,int Net[],int &m)
{
	int j=n;
	m=0;
	for(int i=n;i>1;i--)
	{
		if(size[i][j]!=size[i-1][j])
		{
			Net[m++]=i;
			j=C[i]-1;
		}
	}
	if(j>C[1])
	{
		Net[m++]=1;
	}
}

int main()  
{  
    int C[] = {0,8,7,4,2,5,1,9,3,10,6};//下标从1开始  
    int **size = new int *[N+1];  
    int k;
    for(int i=0;i<=N;i++)  
    {  
        size[i]=new int[N+1];  
    }  
    MNS(C,N,size);  
    cout<<"电路布线最大不相交连线数目为："<<size[N][N]<<endl;  
    int Net[N],m;  
    Traceback(C,size,N,Net,m);
    cout<<"最大不相交连线分别为："<<endl;  
    for(int i=m-1; i>=0; i--)  
    {  
            k=Net[i];
        cout<<"("<<k<<","<<C[k]<<") ";  
    }  
    cout<<endl;  
    return 0;  
} 