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
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
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
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,0,1,-1,-1,0,1 };
const int N = 2e6 + 10;
bool prime[N];
int vis[N];
void sieve()
{
	prime[1] = prime[0] = 1;
	for (ll i = 2; i < N; i++)
		for (ll j = i * i; j < N&&!prime[i]; j += i)
			prime[j] = 1;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	ll x, y, l, r;
	cin >> x >> y >> l >> r;
	ll num1 = 1, num2 = 1;
	ll mx = 1e18;
	vector<ll>v1,v2;
	v1.push_back(1); v2.push_back(1);
	while (num1 <= mx / x) {
		num1 *= x;
		v1.push_back(num1);
	}
	while (num2 <= mx / y) {
		num2 *= y;
		v2.push_back(num2);
	}
	map<ll, bool>mp;
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			
			if (v1[i] + v2[j] >= l && v1[i] + v2[j] <= r) {
		//		cout << v1[i] << " " << v2[j] << endl;
				mp[v1[i] + v2[j]];
			}
		}
	}
	ll last = l;
	ll ans = 0;
	for (auto &e : mp)
	{
		ll cur = e.first;
	//	cout << cur<<" "<<last << endl;
		ans = max(ans, cur - last);
		last = cur + 1;
	}
//	cout << last << " " << r << " " << endl;
	ans = max(ans, r - last+1);
	cout << ans << endl;
	pause();
	return 0;
}