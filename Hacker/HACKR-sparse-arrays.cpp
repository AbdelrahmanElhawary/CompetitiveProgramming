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
map<string, int>mp;
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		mp[s]++;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s; cin >> s;
		cout << mp[s] << endl;
	}
	//system("pause");
	return 0;
}