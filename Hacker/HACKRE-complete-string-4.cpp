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
	int t; cin >> t;
	while (t--) {
		cin >> s;
	int ar[26]{ 0 };
	for (int i = 0; i < s.size(); i++)
		ar[s[i] - 'a']++;
	bool f = 1;
	for (int i = 0; i < 26; i++)
		if (ar[i] == 0)f = 0;
	if (f)cout << "YES\n"; else cout << "NO\n";
}
	//system("pause");
	return 0;
}