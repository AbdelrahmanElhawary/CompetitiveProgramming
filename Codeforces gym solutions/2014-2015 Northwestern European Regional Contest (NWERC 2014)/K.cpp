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
ll gcd(ll a, ll b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
const double EPS = 1e-9;
//int dx[] = { -1,0,1,0,-1,1,-1,1 };
//int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	ll n, s, t;
	cin >> n >> s >> t;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	ll last = v[n - 1] - s;
	ll mn = 1e18, mx = 0, avg = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == last)
			continue;
		multiset <ll>S;
		for (int j = 0; j < n; j++)
			S.insert(v[j]);
		ll cur_pos = v[i], cost = 0;
		while (S.size())
		{
			
			auto it = S.lower_bound(cur_pos);
			if (it == S.end())
				it = S.begin();
			auto next_pos = *(it);
			cost += ((next_pos - cur_pos + s) % s)+t;
		//	cout << cost << endl;
			cur_pos = (next_pos + t) % s;
			S.erase(it);
		}
		ll dif = v[i] - last;
		mn = min(mn, cost);
		mx = max(mx, cost + dif - 1);
		avg += cost * dif + (dif*(dif - 1)) / 2;
		last = v[i];
	//	cout << "wow"<< endl;
	}
	ll g = gcd(avg, s);
	cout << mn << endl << mx << endl << avg / g << "/" << s / g << endl;
	pause();
	return 0;
}