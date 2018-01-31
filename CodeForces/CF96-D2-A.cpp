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
	string s;
	cin >> s;
	if (s.find("1111111")!=-1 || s.find("0000000")!=-1)cout << "YES\n";
	else cout << "NO\n";
	//system("pause");
	return 0;
}