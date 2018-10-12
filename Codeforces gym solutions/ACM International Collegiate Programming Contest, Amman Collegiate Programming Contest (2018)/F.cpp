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
#include <assert.h>
#include<complex>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
//int dx[] = { -1,0,1,0,-1,1,-1,1 };
//int dy[] = { 0,-1,0,1,1,1,-1,-1 };
ll mp[1000001];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		memset(mp, 0, sizeof mp);
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			mp[x]++;
		}
		ll ans = 0;
		for (int i=1;i<=1e6;i++)
		{
			if (!mp[i])
			continue;
			for (ll j = i*2; j <= 1e6; j += i)
			{
				if (mp[j])
					mp[i]+= mp[j], mp[j] = 0;
			}
			ans += mp[i]*i;
		}
		cout<<ans<<endl;
	}
	pause();
	return 0;
}