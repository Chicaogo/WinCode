#include<bits/stdc++.h>
using namespace std;

const int maxStack = 10010;

int iStack[maxStack];
int iTop = -1; //栈的顶端

bool fnisFull()//判断栈是否溢出 
{
	if(iTop >= maxStack)
		return true;
	else
		return false;
}

bool fnisEmpty()//判断栈是否为空
{
	if(iTop == -1)
		return true;
	else
		return false;
}

int Push(int num)//进栈 
{
	if(fnisFull())
	{
		cout << "栈溢出！" << endl;
		return false; 
	}
	else
	{
		iStack[++iTop] = num;
		return iStack[iTop];
	}
}

int Pop()
{
	if(fnisEmpty())
	{
		cout << "栈已空！" << endl;
		return false;
	}
	else
	{
		return iStack[iTop--];
	} 
}

int main(void)
{
	int number;
	for(int i = 0;i < 10;i++)
	{
		number = rand() % 100;
		Push(number);
		cout << "将 " << number << " 压入栈。" << endl; 
	}
	
	while(!fnisEmpty())
		cout << "当前栈顶元素为 ： " << Pop() << endl;
	
	return 0;
}
 