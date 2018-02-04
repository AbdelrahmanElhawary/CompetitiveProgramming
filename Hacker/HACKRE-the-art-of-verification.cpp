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
	/*
	username: From the URL.
pwd: From the URL.
profile: From the URL.
role: From the URL.
key: From the URL.
	*/
	string str[4] = { "pwd","profile","role","key" };
	bool f = 1; int j = 0;
	for (int i = s.find("username"); i < s.size(); i++)
	{
	//	cout << s.substr(i + 1,str[j].size()) << endl;
		if (!f&&s.substr(i + 1, str[j].size()) == str[j]) { f = 1; j++; cout << endl; i++; }
		if (f&&s[i] == '=') { f = 0; cout << ": "; continue; }
		cout << s[i];
	}
	cout << endl;
	//system("pause");
	return 0;
}