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
 	{// ����������
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
	cout<<"�����뼯װ��������";
	cin>>n;
	cout<<"�����봬�ĸ�������";
	cin>>c;
	cout<<"�������������:";
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		r+=w[i]; 
	}
	Backtrack(1);
	cout<<"����װ������Ϊ"<<bestw<<"�Ļ���"<<endl;
}
