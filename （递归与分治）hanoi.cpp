#include"iostream"
using namespace std;
void move(int a,int b)
{
	cout<<"��"<<a<<"������˵����ӷŷŵ�->"<<b<<"������"<<endl;
}
void hanoi(int n,int a,int b,int c)
{ 
	if(n>0)
	{
		hanoi(n-1,a,c,b);
		move(a,b);
		hanoi(n-1,c,b,a);
	}	
} 

int main()
{
	hanoi(3,1,2,3);
	return 0;
}