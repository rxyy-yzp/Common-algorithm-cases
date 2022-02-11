#include"iostream"
#include"string.h"
using namespace std;

void LCSLength(int m,int n,char *x,char *y,int **c,int **b)
{  
	int i,j;
    for(i=1;i<=m;i++) 
	   	c[i][0]=0;
    for(i=1;i<=n;i++) 
    	c[0][i]=0;
    for(i=1;i<=m;i++)
    {
		for(j=1;j<=n;j++) 
		{
        	if(x[i]==y[j]) 
	 		{ 
    			c[i][j]=c[i-1][j-1]+1; 
				b[i][j]=1;
		    }
            else if (c[i-1][j]>=c[i][j-1]) 
		 	{
                c[i][j]=c[i-1][j]; 
		  		b[i][j]=2;
		    }
            else 
			{ 
			 	c[i][j]=c[i][j-1]; 
    			b[i][j]=3; 
			}
        }
    }
}


void LCS(int i,int j,char *x,int **b)
{
	if(i==0||j==0)
	{
		return ;
	}
	if(b[i][j]==1)
	{
		LCS(i-1,j-1,x,b);
		cout<<x[i];
	}
	else if(b[i][j]==2)
	{
		LCS(i-1,j,x,b);
	}
	else
	{
		LCS(i,j-1,x,b);
	}
}

int main()
{
	int m,n;
	char *x=new char[m+2];
	char *y=new char[n+2];
	cout<<"请输入第一串字符串的长度：";
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i];
	}
	cout<<"请输入第二串字符串的长度：";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>y[i];
	}
	int **b=new int *[m+2];
	for(int i=0;i<=m+1;i++)
	{
		b[i]=new int[n+2];
	}
	int **c=new int *[m+2];
	for(int i=0;i<=m+1;i++)
	{
		c[i]=new int[n+2];
	}
	LCSLength(m,n,x,y,c,b);
	cout<<"最长公共字串为："; 
	LCS(m,n,x,b);
	cout<<endl;
	return 0;
} 


/*
测试样例
请输入第一串字符串的长度：7
ABCBDAB
请输入第二串字符串的长度：6
BDCABA 
*/