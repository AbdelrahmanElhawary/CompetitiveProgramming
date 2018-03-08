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
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	int n, m;
	while (cin >> n >> m)
	{
		map<ll, bool>mp;
		if (!n && !m)break;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			mp[x]=1;
		}
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			int x; cin >> x;
			if (mp[x])ans++;
		}
		cout << ans << endl;
	}
	
	//system("pause");
	return 0;
}
