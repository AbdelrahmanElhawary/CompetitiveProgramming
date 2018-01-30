#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
using namespace std;
int main()
{
	int n,x,y,mx=0,c=0; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		c -= x; c += y;
		mx = max(mx, c);
	}
	cout << mx << endl;
	//system("pause");
	return 0;
}