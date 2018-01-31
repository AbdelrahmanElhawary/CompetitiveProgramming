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
	string str = "CMY";
	int n, m; bool f = 1;
	cin >> n >> m; char ch;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> ch;
			if (str.find(ch) != -1)f = 0;
		}
	if (f)cout << "#Black&White\n";
	else cout << "#Color\n";
//	system("pause");
	return 0;
}