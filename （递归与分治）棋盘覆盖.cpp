#include"iostream"
#include"math.h"
using namespace std;

int tile=0;
int Board[10000][10000]={0};

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{//tr:棋盘左上角行号, tc:棋盘左上角列号,dr:特殊方格行号,dc:特殊方格列号,size:棋盘边长 
	if(size==1)
	{
		return;
	} 
	int t=tile++,s=size/2;
	if(dr<tr+s&&dc<tc+s)//如果特殊方格在左上角棋盘 
	{
		ChessBoard(tr,tc,dr,dc,s);
	}
	else//左上角棋盘无特殊方格 
	{
		Board[tr+s-1][tc+s-1]=t;
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	if(dr<tr+s&&dc>=tc+s)//如果特殊方格在右上角棋盘 
	{
		ChessBoard(tr,tc+s,dr,dc,s);
	}
	else//右上角棋盘无特殊方格
	{
		Board[tr+s-1][tc+s]=t;
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	} 
	if(dr>=tr+s&&dc<tc+s)//如果特殊方格在左下角棋盘
	{
		ChessBoard(tr+s,tc,dr,dc,s);
	} 
	else//左下角棋盘无特殊方格
	{
		Board[tr+s][tc+s-1]=t;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	} 
	if(dr>=tr+s&&dc>=tc+s)//如果特殊方格在左下角棋盘
	{
		ChessBoard(tr+s,tc+s,dr,dc,s);
	} 
	else//左下角棋盘无特殊方格
	{
		Board[tr+s][tc+s]=t;
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
	} 
}
int main()
{
	int size,dr,dc;
	cout<<"请输入棋盘的边长：";
	cin>>size; 
	flag=log(double(size));
	
	cout<<"请输入特殊方格的左上角的行号和列号：(下标从0开始)";
	cin>>dr>>dc;
	ChessBoard(0,0,dr,dc,size);
	cout<<"需要的骨牌数："<<tile<<endl;
	return 0;
}