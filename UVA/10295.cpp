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
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
#define endl '\n'
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
map<string, int>mp;
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	int n,m;
	cin >> n >> m;
	ll ans = 0;	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int x; cin >> x;
		mp[s] = x;
	}
	while (cin >> s)
	{
		ans += mp[s];
		if (s == ".") { m--; cout << ans << endl; ans = 0; continue; }
		if (!m)break;
	}

	
//	system("pause");
	return 0;
}
