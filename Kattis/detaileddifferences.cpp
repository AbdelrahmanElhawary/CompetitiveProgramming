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
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s1, s2; cin >> s1 >> s2;
		cout << s1 << endl << s2 << endl;
		for (int j = 0; j < min(s1.size(), s2.size()); j++)
			if (s1[j] != s2[j])cout << '*'; else cout << '.';
		for (int j = min(s1.size(), s2.size()); j < max(s1.size(), s2.size()); j++)
			cout << '*';
		cout << endl << endl;
	}
	//system("pause");
	return 0;
}