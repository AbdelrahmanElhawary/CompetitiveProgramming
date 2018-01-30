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
	
	int t; cin >> t;
	string s = "MARGIT";
	int ar[] = { 1,3,2,1,1,1 };
	while (t--)
	{
		string str; cin >> str;
		int cnt[6]{ 0 };
		for (int i = 0; i < str.size(); i++)
			for (int j = 0; j < s.size(); j++)
				if (str[i] == s[j])cnt[j]++;
		int ans = 1e9;
		for (int i = 0; i < 6; i++)
			ans = min(ans, cnt[i] / ar[i]);
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}