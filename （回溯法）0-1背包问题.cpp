#include"iostream"
using namespace std;

class Obj
{
public:
	double c;   //��������
	int n;   //��Ʒ��
	double w[100]; //��Ʒ��������
	double p[100]; //��Ʒ��ֵ����
	double cw; //��ǰ����
	double cp; //��ǰ��ֵ
	double bestp; //��ǰ���ż�ֵ
	double Bound(int i);
	void Backtrace(int i);
	
};

void Sort(int n,double v[],double w[])
{
	int i,j;
	double temp;
	double *pv=new double[n+1];
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

double Obj::Bound(int i)
{
	double cleft=c-cw;//���㱳��ʣ������ 
	double b=cp;//b������װ��ֵ 
	while(i<=n && w[i]<=cleft)
	{
		cleft-=w[i];
		b+=p[i];
		i++;
	}
	if(i<=n)
	{
		b+=(p[i]/w[i])*cleft;
	}
	return b;
}

void Obj::Backtrace(int i)
{
	if(i>n)
	{
		bestp=cp;
		return ;
	}
	if(cw+w[i]<=c)
	{
		cw+=w[i];
		cp+=p[i];
		Backtrace(i+1);
		cw-=w[i];
		cp-=p[i];
	}
	if(Bound(i+1)>bestp)
	{
		Backtrace(i+1);
	}
}

int main()
{
	Obj o;
	cout<<"�����뱳��������";
	cin>>o.c;
	cout<<"��������Ʒ������";
	cin>>o.n;
	cout<<"��ֱ�����ÿ����Ʒ�ļ�ֵ��������"<<endl;
	for(int i=1;i<=o.n;i++) 
	{
		cin>>o.p[i]>>o.w[i];
	}
	Sort(o.n,o.p,o.w);
	o.Backtrace(1);
	cout<<"������װ�ص���߼�ֵΪ��"<<o.bestp<<endl;
	return 0;
}

/*�������� 
45 16
25 15
25 15
*/