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
#include<queue>
#include<list>
#include <iterator>
#include <functional> 
#include<iomanip>
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int ar[26];
int main()
{
	fast_in_out();
	int n; cin >> n; string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')s[i] += 32;
		ar[s[i] - 'a']++;
	}
	bool f = 1;
	for (int i = 0; i < 26; i++)
		if (!ar[i])f = 0;
	if (!f)cout << "NO\n"; else cout << "YES\n";
	//system("pause");
	return 0;
}