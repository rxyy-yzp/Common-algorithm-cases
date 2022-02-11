#include"iostream"
#include"math.h"
using namespace std;

int tile=0;
int Board[10000][10000]={0};

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{//tr:�������Ͻ��к�, tc:�������Ͻ��к�,dr:���ⷽ���к�,dc:���ⷽ���к�,size:���̱߳� 
	if(size==1)
	{
		return;
	} 
	int t=tile++,s=size/2;
	if(dr<tr+s&&dc<tc+s)//������ⷽ�������Ͻ����� 
	{
		ChessBoard(tr,tc,dr,dc,s);
	}
	else//���Ͻ����������ⷽ�� 
	{
		Board[tr+s-1][tc+s-1]=t;
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	if(dr<tr+s&&dc>=tc+s)//������ⷽ�������Ͻ����� 
	{
		ChessBoard(tr,tc+s,dr,dc,s);
	}
	else//���Ͻ����������ⷽ��
	{
		Board[tr+s-1][tc+s]=t;
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	} 
	if(dr>=tr+s&&dc<tc+s)//������ⷽ�������½�����
	{
		ChessBoard(tr+s,tc,dr,dc,s);
	} 
	else//���½����������ⷽ��
	{
		Board[tr+s][tc+s-1]=t;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	} 
	if(dr>=tr+s&&dc>=tc+s)//������ⷽ�������½�����
	{
		ChessBoard(tr+s,tc+s,dr,dc,s);
	} 
	else//���½����������ⷽ��
	{
		Board[tr+s][tc+s]=t;
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
	} 
}
int main()
{
	int size,dr,dc;
	cout<<"���������̵ı߳���";
	cin>>size; 
	flag=log(double(size));
	
	cout<<"���������ⷽ������Ͻǵ��кź��кţ�(�±��0��ʼ)";
	cin>>dr>>dc;
	ChessBoard(0,0,dr,dc,size);
	cout<<"��Ҫ�Ĺ�������"<<tile<<endl;
	return 0;
}