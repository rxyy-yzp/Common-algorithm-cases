#include"iostream"
using namespace std;

template<class T>
void BubbleSort(int n,T s[],T f[])
{
	int i,j;
	int temp;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(f[j]>f[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
				temp=f[j];
				f[j]=f[j+1];
				f[j+1]=temp;
			}
		}
	}
}

template<class T>
void GreedySelector(int n,T s[],T f[],bool A[])
{
	int i,j;
	A[1]=true;
	j=1;//Ŀǰѡ�е�
	for(i=2;i<=n;i++)
	{
		if(s[i]>f[j])
		{
			A[i]=true;
			j=i;
		}
		else{
			A[i]=false;
		}
	} 
} 

int main()
{
	int i,n;
	cout<<"�������ܹ��������";
	cin>>n;
	int s[100],f[100];
	bool A[100]={false};
	cout<<"��ֱ�����ÿ�������ʼʱ�䣺"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
		cin>>f[i];
	}
	BubbleSort(n,s,f);
	GreedySelector(n,s,f,A);
	cout<<endl<<"ѡ�еĻ���Ϊ��"<<endl;
	for(i=1;i<=n;i++)
	{
		if(A[i]==true)
			cout<<"ѡ�л��ʼʱ�䣺"<<s[i]<<",ѡ�л����ʱ�䣺"<<f[i]<<endl;
	} 
	return 0;
} 