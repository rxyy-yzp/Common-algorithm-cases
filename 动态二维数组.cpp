#include"iostream"
using namespace std;

template<class T>
void Make2DArray(T** &x,int rows,int cols)
{
	x=new T*[rows];
	for(int i=0;i<rows;i++)
	{
		x[i]=new T[cols];
	}
} 
template<class T>
void Delete2DArray(T** &x,int rows,int cols)
{
	for(int i=0;i<rows;i++)
	{
		delete[]x[i];
	}
	delete[]x;
	x=0;
	cout<<"数组释放成功！"<<endl;
} 

int main()
{
	int **x;
	int rows,cols;
	cout<<"请输入要创建的二维数组的行数和列数："; 
	cin>>rows>>cols;
	Make2DArray(x,rows,cols);
	cout<<"请输入数据："<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cin>>x[i][j];
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<x[i][j]<<' ';
		}
		cout<<endl;
	}
	Delete2DArray(x,rows,cols);
	return 0;
}