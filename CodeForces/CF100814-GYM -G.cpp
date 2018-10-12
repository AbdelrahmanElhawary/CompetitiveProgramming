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
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)/length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
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
vector<vector<pair<int, pair<ll,int>>>>adj;
int n, m, k;
bool dijkstra(int mid)
{
	set<pair<ll, int>>s;
	s.insert({ 0,1 });
	vector<int>v(n + 1, -1);
	while (s.size())
	{
		int u = (*s.begin()).second;
		ll d = (*s.begin()).first;
		s.erase(s.begin());
		if (v[u] != -1)
			continue;
		v[u] = d;
		if (u == n)
			return 1;
		for (auto &e : adj[u])
			if (v[e.first] == -1 && d + e.second.first < k&&e.second.second <= mid)
				s.insert({ d + e.second.first,e.first });
	}
	return 0;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(1);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		int s=1e9, e=-1;
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v, c, w;
			cin >> u >> v >> c >> w;
			s = min(s, w);
			e = max(e, w);
			adj[u].push_back({ v,{c,w} });
			adj[v].push_back({ u,{ c,w } });
		}
		int ret = -1;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (dijkstra(mid))
				e = mid - 1, ret = mid;
			else s = mid + 1;
		}
		cout << ret << endl;
	}
	pause();
	return 0;
}