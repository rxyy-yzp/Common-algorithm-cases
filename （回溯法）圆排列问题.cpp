#include"iostream"

using namespace std;
#include"math.h"

class Circle
{
public:
	float min;//当前最优值 
	float *x;//当前圆排列圆心横坐标，第一个为0
	float *r;//当前圆排列圆的半径
	int n;//圆的总数
	float Center(int t);
    void Compute();
    void Backtrack(int t);
};

void Swap(float &a,float &b)
{
	float temp;
	temp=a;
	a=b;
	b=temp;
}

float Circle::Center(int t)
{
	float temp=0;
	for(int j=1;j<t;j++)
	{
		float value=x[j]+2.0*sqrt(r[t]*r[j]);
		if(value>temp)
		{
			temp=value;
		}
	}
	return temp;
}

void Circle::Compute()
{
	float low=0;
	float high=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]-r[i]<low)
		{
			low=x[i]-r[i];
		}
		if(x[i]+r[i]>high)
		{
			high=x[i]+r[i];
		}
	}
	if(high-low<min)
	{
		min=high-low;
	}
}

void Circle::Backtrack(int t)
{
	if(t>n)
	{
		Compute();
	}
	else
	{
		for(int j=t;j<=n;j++)
		{
			Swap(r[t],r[j]);
			float centerx=Center(t);
			if(centerx+r[t]+r[1]<min)
			{
				x[t]=centerx;
				Backtrack(t+1);
			} 
			Swap(r[t],r[j]);
		} 
	}
}

int main()
{
	Circle X;
	cout<<"请输入圆的个数："; 
	cin>>X.n;
	cout<<"请输入圆的半径："<<endl; 
	for(int i=1;i<=X.n;i++)
	{
		cin>>X.r[i];
	}
	X.min=10000;
	float *xx=new float[X.n+1];
	X.x=xx;
	X.Backtrack(1);
	cout<<"最小长度的圆排列长度为："<<X.min<<endl;
	delete[]xx;
	
	return 0;
}