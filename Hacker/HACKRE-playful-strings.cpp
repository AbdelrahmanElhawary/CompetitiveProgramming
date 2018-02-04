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
int main() {
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		bool f = 1;
		for (int i = 0; i < s.size()-1; i++)
			if (abs(s[i] - s[i + 1]) != 1 && abs(s[i] - s[i + 1]) != 25)
				f = 0;
		if (f)cout << "YES\n";
		else cout << "NO\n";
	}
	//system("pause");
	return 0;
}