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
bool check(string str, string s)
{
	for (int i = 0; i < s.size() - str.size() + 1;i+=str.size())
		if (s.substr(i, str.size()) != str)return 0;
	return 1;
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() < s2.size())swap(s1, s2);
	int ans = 0;
	for (int i = 1; i <= s2.size(); i++)
	{
		if (s1.size() % i || s2.size() % i)continue;
		string str = s2.substr(0, i);
		if (check(str, s2) && check(str, s1))ans++;
	}
	cout << ans << endl;

	//system("pause");
	return 0;
}