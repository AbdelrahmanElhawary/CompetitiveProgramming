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
const int N = 2e5 + 10;
vector<int>adj[N];
int lvl1[N],lvl2[N];
int ans;
void dfs(int u = 1, int par = -1, int lv = 1,bool f=0)
{
	if(!f)lvl1[u] = lv;
	if (f) { lvl2[u] = lv; if(lvl1[u]>lvl2[u])ans = max(ans, lvl1[u] * 2-2); }
	for (auto&e : adj[u])
		if (e != par)
			dfs(e, u, lv + 1, f);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int n; cin >> n;
	int x; cin >> x;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	dfs(x, -1, 1, 1);
	cout << ans << endl;
	pause();
	return 0;
}