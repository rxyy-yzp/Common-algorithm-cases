#include"iostream"
using namespace std;
void Sort(int n,float v[],float w[])
{
	int i,j;
	float temp;
	float *pv=new float[n+1];
	for(i=1;i<=n;i++)
	{
		pv[i]=v[i]/w[i];
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(pv[j]<pv[j+1])
			{
				temp=pv[j];
				pv[j]=pv[j+1];
				pv[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	
}
void KnapSack(int n,float M,float v[],float w[],float x[])
{
	int i;
	float c=M;
	Sort(n,v,w);
	for(i=1;i<=n;i++)
	{
		x[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		if(w[i]>c)
			break;
		x[i]=1;
		c-=w[i];
	}
	if(i<=n)
	{
		x[i]=c/w[i];
	}
}

int main()
{
	int i,n;
	float M,sv=0;
	float v[100],w[100],x[100];
	cout<<"�����뱳�����أ�";
	cin>>M;
	cout<<"��������Ʒ������";
	cin>>n;
	cout<<"��ֱ�����ÿ����Ʒ�ļ�ֵ��������"<<endl;
	for(i=1;i<=n;i++) 
	{
		cin>>v[i]>>w[i];
	}
	KnapSack(n,M,v,w,x);
	for(i=1;i<=n;i++)
	{
		cout<<"��ֵΪ"<<v[i]<<",����Ϊ"<<w[i]<<"�Ļ���װ��"<<x[i]*w[i]<<endl;
		sv+=x[i]*v[i];
	}
	cout<<"�ܼ�ֵΪ��"<<sv<<endl; 
	return 0;
} 
