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
ll tree1[5554432],tree2[5554432], n; //2 power (log(10000000)+2)
void update(int ind, int s, int e,ll core,ll cost)
{
	if (cost > e || cost < s) return;
	tree1[ind] += (core * cost*1LL);
	tree2[ind] += core;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update(ind * 2, s, mid, core, cost);
	update(ind * 2 + 1, mid + 1, e, core, cost);
	return;
}
ll solve(int ind, int s, int e, ll core)
{
	//if (s == e)cout << core << " " << ind << endl;
	if (s == e)
		return 1LL*core * s;
	int mid = (s + e) / 2;
	ll ret = 0;
	if (tree2[ind*2] > core)
		ret = solve(ind * 2, s, mid, core);
	else ret = solve(ind * 2 + 1, mid + 1, e, core - tree2[ind * 2]) + tree1[ind * 2];
//	cout << ret << endl;
	return ret;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, m;
	cin >> n >> k >> m;
	unordered_map<int, vector<pair<int, int>>>mp1, mp2;
	for (int i = 0; i < m; i++)
	{
		int l, r, c, p;
		cin >> l >> r >> c >> p;
		mp1[l].push_back({ c,p });
		mp2[r+1].push_back({ c,p });
	}
	ll mx = 0,ans=0;
	for (int i = 1; i <= n; i++)
	{
		for (auto& e : mp2[i])
		{
			mx -= e.first;
			update(1, 1, 1e6+1, -e.first, e.second);
		}
		for (auto& e : mp1[i])
		{
			mx += e.first;
			update(1, 1, 1e6+1, e.first, e.second);
		}		
		ans += solve(1, 1,1e6+1, min((ll)k, mx));
		//cout << ans << endl;
	}

	cout << ans << endl;
	pause();
	return 0;
}