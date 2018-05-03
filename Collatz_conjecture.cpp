//编程题＃2：角谷猜想
//逻辑很简单：终止条件为：当n为1;递归过程为：调用process（n），
//若为偶数则返回process(n/2);若为奇数则process(n*3+1)
#include <iostream>
using namespace std;
int  process(int n)
{
	if (n == 1)   //终止条件
	{
		cout << "End" << endl;
		return 1;
	}
	if (n % 2 == 0)
	{
		cout << n << "/2=" << n / 2 << endl;
		return process(n / 2); //若为偶数则返回process(n / 2)
	}
	else
	{
		cout << n << "*3+1=" << n*3 + 1 << endl;
		return process(n * 3 + 1);//若为奇数则返回process(n*3+1)
	}
}
int main()
{
	int n = 0;
	cin >> n;
	process(n);
	return 0;
}