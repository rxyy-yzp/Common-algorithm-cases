#include"iostream"
using namespace std;

int w[100]={0};
int r=0;
int n;
int c;
int bestw=0;
int cw=0;


void Backtrack(int i)
{
	if(i>n)
 	{
	  	if(bestw>cw);
    	{
    		bestw=cw; 
			return;
		}
 	}
  	r-=w[i];
    if(cw+w[i]<=c)
 	{// 搜索左子树
 		cw += w[i];
 		Backtrack(i + 1);
 		cw -= w[i];      
 	}
 	if(cw+r>bestw)
 	{
      	Backtrack(i + 1);     
	}
	r+=w[i];
}

int main()
{
	cout<<"请输入集装箱数量：";
	cin>>n;
	cout<<"请输入船的负载量：";
	cin>>c;
	cout<<"请输入货物重量:";
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		r+=w[i]; 
	}
	Backtrack(1);
	cout<<"最多可装载重量为"<<bestw<<"的货物"<<endl;
}
