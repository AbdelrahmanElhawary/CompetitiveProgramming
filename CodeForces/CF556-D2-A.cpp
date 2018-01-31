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
	int n; string s; cin >> n; cin >> s;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')c1++;
		else c2++;
		cout << abs(c1 - c2);
//	system("pause");
	return 0;
}