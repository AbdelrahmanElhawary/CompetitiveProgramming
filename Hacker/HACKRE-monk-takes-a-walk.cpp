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
	char ch[] = { 'A', 'E', 'I', 'O', 'U' ,'a','e','i','o','u' };
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s; int ans = 0;
		for (int i = 0; i < s.size(); i++)
			for (int j = 0; j < 10; j++)
				if (s[i] == ch[j])ans++;
		cout << ans << endl;
	}
	
	//system("pause");
	return 0;
}