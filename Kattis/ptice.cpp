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
	string s;
	string a = "ABC",b="BABC",c="CCAABB";
	int c1 = 0, c2 = 0, c3 = 0; //3 4 6
	cin >> s;
	int ans1 = 0, ans2 = 0, ans3 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == a[c1 % 3])ans1++;
		if (s[i] == b[c2 % 4])ans2++;
		if (s[i] == c[c3 % 6])ans3++;
		c1++; c2++; c3++;
	}
	int ans = max(max(ans1, ans2), ans3);
	cout << ans<<endl;
	if (ans == ans1)cout << "Adrian\n";
	if (ans == ans2)cout << "Bruno\n";
	if (ans == ans3)cout << "Goran\n";

	//system("pause");
	return 0;
}