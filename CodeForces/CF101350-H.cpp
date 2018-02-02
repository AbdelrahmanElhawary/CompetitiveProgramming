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
		string s,s2; bool f = 1;
		char ch[] = { 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y' };
		cin >> s;
		s2 = s; 
		for (int i = 0; i < s.size(); i++)
		{
			bool f2 = 0;
			for (int j = 0; j < 11; j++)
				if (s[i] == ch[j])f2 = 1;
			if (!f2)f = 0;
		}
		reverse(s.begin(), s.end());
		if (s == s2&&f)cout << "yes\n";
		else cout << "no\n";
	}	//system("pause");
	return 0;
}