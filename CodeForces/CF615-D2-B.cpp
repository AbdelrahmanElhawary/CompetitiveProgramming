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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
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
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int n, m;
vector<int>adj[100005];
ll ans[100005];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll ansy = 0;
	for (int i = 1; i <= n; i++)
	{
		ans[i] = 1;
		for (auto &e : adj[i])
			if (i > e)
				ans[i] = max(ans[i], ans[e] + 1);
		ansy = max(ansy, ans[i] * (ll)adj[i].size());
	}
	cout << ansy << endl;
	pause();
	return 0;
}