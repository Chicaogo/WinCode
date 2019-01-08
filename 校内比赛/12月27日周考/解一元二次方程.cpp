#include<bits/stdc++.h>
using namespace std; 

double a,b,c,gen[3];
double derta;

void init()
{
	cin >> a >> b >> c;
	derta = b*b-4*a*c;
}

void find()
{
	if(derta > 0.0)
	{
		printf("2 ");
		gen[1] = (b + sqrt(derta)) / (-2.0 * a);
		gen[0] = (b - sqrt(derta)) / (-2.0 * a);
		
		printf("%.1lf ",min(gen[0],gen[1]));
		printf("%.1lf",max(gen[0],gen[1]));
	}
	else if(derta==0.0)
	{
		printf("1 ");
		derta = sqrt(derta);
		gen[0] = (b + sqrt(derta)) / (2 * a);
		
		printf("%.1lf ",gen[0]);
	}
	else
	{
		printf("0");
	}
}

int main(void)
{
	init();

	find();

	return 0;
}
