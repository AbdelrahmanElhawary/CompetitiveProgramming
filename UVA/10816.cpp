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
vector<pair<int, pair<ld,ld>>>adj[20005];
vector<int>par;
vector<ld>v;
bool check(ll mii)
{
	ld mid = (ld)mii / 10.0;
	set<pair<ld, pair<int,int>>>s;
	s.insert({ 0.0,{st,-1} });
	while (s.size())
	{
		auto cur = *s.begin();
		s.erase(s.begin());
		int u = cur.second.first,vv=cur.second.second;
		ld d = cur.first;
		if (v[u] != -1)
				continue;
		v[u] = d;
		par[u] = vv;
		if (u == en)
			return 1;
		for (auto &e : adj[u])
			if (v[e.first] == -1 && e.second.first <= mid)
				s.insert({ d + e.second.second,{e.first,u} });
	}
	return 0;
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(1);
	while(cin>>n>>m)
	{
		for (auto&v : adj)
			v.clear();
		cin >>st>>en;
		ll s=1e9, e=-1;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			ld d; ld dd;
			cin >> u >> v >> d >> dd;
			s = min(s, (ll)(d*10));
			e = max(e, (ll)(d*10));
			adj[u].push_back({ v,{d,dd} });
			adj[v].push_back({ u,{d,dd} });
		}
		ll temp = 0;ld dis = 0;
		vector<int>path;
		while (s <= e)
		{
			par.clear(); v.clear();
			v.resize(n + 1, -1);
			par.resize(n + 1);
			ll mid = (s + e) / 2;
			if (check(mid))
			{
				path.clear();
				path = par;
				e = mid - 1;
				temp = mid; 
				dis = v[en];
			}
			else s = mid + 1;
		}
		vector<int>ansy;
		for (int i = en; i != st; i = path[i])
			ansy.push_back(i);
		cout << st;
		reverse(ansy.begin(), ansy.end());
		for (auto &e : ansy)
			cout << " " << e;
		cout << endl;
		cout << dis << " " << (ld)temp/10.0 << endl;
		
	}
	pause();
	return 0;
}