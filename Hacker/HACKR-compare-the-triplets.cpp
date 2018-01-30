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
#include<vector>
#include<string.h>
#define F first
#define S second
#define ll long long
using namespace std;
int main()
{
	int n,ar1[3],ar2[3],x=0,y=0;
	for (int i = 0; i < 3; i++)cin >> ar1[i];
	for (int i = 0; i < 3; i++) {
		cin >> ar2[i];
		if (ar2[i] > ar1[i])
			y++;
		else if (ar1[i] > ar2[i])
			x++;
	}
	cout << x << " " << y << endl;
	//system("pause");
	return 0;
}