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
int n, m, st, en;
vector<pair<int, int>>adj[20005];
int dijkstra()
{
	set<pair<int, int>>s;
	s.insert({ 0,st });
	vector<int>v(n+1, -1);
	while (s.size())
	{
		auto cur = *s.begin();
		s.erase(s.begin());
		int u = cur.second, d = cur.first;
		if (v[u] != -1)continue;
		v[u] = d;
		if (u == en)return d;
		for (auto&e : adj[u])
			if (v[e.first] == -1)
				s.insert({ d + e.second,e.first });
	}
	return -1;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(2);
	int t,tt=1; cin >> t;
	while (t--)
	{
		cin >> n >> m>>st>>en;
		for (auto &v : adj)
			v.clear();
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			adj[u].push_back({ v,d });
			adj[v].push_back({ u,d });
		}
		int ans = dijkstra();
		cout << "Case #"<<tt++<<": ";
		if (ans == -1)
			cout << "unreachable\n";
		else cout << ans << endl;
	}
	pause();
	return 0;
}