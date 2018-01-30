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
vector<char>v;
map<string, bool>mp;
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		mp[s] = 1;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s; cin >> s;
		if (mp[s])continue;
		else { v.push_back(s[0] - 32); v.push_back('.');}
	}
	for (int i = 0; i < v.size() - 1; i++)
		cout << v[i]; cout << endl;
	
	
	//system("pause");
	return 0;
}