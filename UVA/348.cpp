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
#define pb push_back
const ld eps = 1e-9;
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
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int n;
vector<pair<ll, ll>>v;
ll memo[12][12];
ll dis(int s,int i,int e)
{
	return v[s].first*v[i].second*v[e].second;
}
ll solve(int s=0,int e=n-1)
{
	if (s == e)
		return 0;
	ll &ret = memo[s][e];
	if (ret != -1)
		return ret;
	ret = 1e18;
	for (int i = s; i < e; i++)
		ret = min(ret, solve(s, i) + solve(i + 1, e) + dis(s,i, e));
	return ret;
}
void build(int s = 0, int e = n - 1)
{
	if (s == e) {
		cout << "A" << s + 1;
		return;
	}
	ll ans = memo[s][e];
	for (int i = s; i < e; i++) {
		ll ret = solve(s, i) + solve(i + 1, e) + dis(s,i, e);
		if (ret == ans)
		{
			cout << "(", build(s, i), cout << " x ", build(i + 1, e), cout << ")";
			return;
		}
	}
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(2);
	int tt = 1;
	while (cin>>n&&n)
	{
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin>> v[i].first >> v[i].second;	
		memset(memo, -1, sizeof memo);
		solve();
		cout <<"Case "<<tt++<<": ";
		build(); cout << endl;
	}
	
	pause();
	return 0;
}