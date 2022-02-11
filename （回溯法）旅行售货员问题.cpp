#include"iostream"
using namespace std;

class Traveling
{
public:
	int n;
	int *x;//��ǰ�� 
	int *bestw;//��ǰ���Ž� 
	Type **a;//ͼG���ڽӾ��� 
	int cc;//��ǰ����
	int bestc;//��ǰ����ֵ
	int NoEdge;//�ޱ߱�� 
}

template<class Type>
void Traveling<Type>::Backtrack(int i)
{
	if(i==n)
	{
		if(a[x[n-1]][n]!=NoEdge && a[x[n]][1]!=NoEdge && (cc+a[x[n-1]][x[n]]+a[x[n]][1]<bestc || bestc == NoEdge))
		{
			for(int j=1;j<=n;j++)
			{
				bestx[j]=x[j];
			}
		}
		bestc=cc+a[x[n-1]][x[n]]+a[x[n]][1];
	}
	else
	{
		for(int j=i;j<=n;j++)
		{
			if(a[x[i-1]][x[j]]!=NoEdge && (cc+a[x[i-1]][x[j]]<bestc || bestc==NoEdge))
			{
				Swap(x[i],x[j]);
				cc+=a[x[i-1]][x[i]];
				Backtrack(i+1);
				cc-=a[x[i-1]][x[i]];
				Swap(x[i],x[j]);
			}
		}
	}
} 

int main()
{
	
	return 0;
} 