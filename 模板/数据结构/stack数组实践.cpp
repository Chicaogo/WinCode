#include<bits/stdc++.h>
using namespace std;

const int maxStack = 10010;

int iStack[maxStack];
int iTop = -1; //ջ�Ķ���

bool fnisFull()//�ж�ջ�Ƿ���� 
{
	if(iTop >= maxStack)
		return true;
	else
		return false;
}

bool fnisEmpty()//�ж�ջ�Ƿ�Ϊ��
{
	if(iTop == -1)
		return true;
	else
		return false;
}

int Push(int num)//��ջ 
{
	if(fnisFull())
	{
		cout << "ջ�����" << endl;
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
		cout << "ջ�ѿգ�" << endl;
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
		cout << "�� " << number << " ѹ��ջ��" << endl; 
	}
	
	while(!fnisEmpty())
		cout << "��ǰջ��Ԫ��Ϊ �� " << Pop() << endl;
	
	return 0;
}
 