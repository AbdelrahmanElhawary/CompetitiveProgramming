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
	string s; cin >> s;
	int p1 = 0, p2 = s.size() - 1;
	bool f = 1;
	while (p1 < p2)
	{
		if (s[p1++] != s[p2--])f = 0;
	}
	if (f)cout << "YES\n"; else cout << "NO\n";
	//system("pause");
	return 0;
}