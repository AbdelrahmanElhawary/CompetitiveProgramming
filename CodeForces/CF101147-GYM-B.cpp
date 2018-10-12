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
vector<vector<pair<int, ld>>>adj;
int n;
ld dis(ld x1, ld y1, ld x2, ld y2)
{
	ld x = x1 - x2;
	ld y = y1 - y2;
	return sqrt(x*x + y * y);
}
ld dijkstra()
{
	set<pair<ld, int>>s;
	s.insert({ 0.0,0 });
	vector<ld>v(n + 2, -1.0);
	while (s.size())
	{
		int u = (*s.begin()).second;
		ld d = (*s.begin()).first;
		s.erase(s.begin());
		if (v[u] != -1)continue;
		v[u] = d;
		if (u == n + 1)
			return v[n + 1];
		for (auto &e : adj[u])
			if (v[e.first] == -1)
				s.insert({ d + e.second,e.first });
	}
}
bool cmp(pair<pair<ll, ll>, pair<ll, bool>> a, pair<pair<ll, ll>, pair<ll, bool>>b)
{
	
	return a.second.first < b.second.first;
}

bool check(pair<ll,ll> l1, pair<ll, ll>r1, pair<ll, ll> l2, pair<ll, ll> r2)
{
	swap(l1, r1);
	swap(l2, r2);
	if (l1.first > r2.first || l2.first > r1.first)
		return 0;

	if (l1.second < r2.second|| l2.second < r1.second)
		return 0;

	return 1;
}
struct rectangle { ld x, h, ws, we; };
ld calc(rectangle rec1, rectangle rec2)
{
	if (rec1.x > rec2.x)
		swap(rec1, rec2);
	if (rec1.x + rec1.h >= rec2.x)
		if (rec1.ws < rec2.ws) 
			return rec2.ws - (rec1.ws + rec1.we);
		else
			return rec1.ws - (rec2.ws + rec2.we);
	if (rec1.ws > rec2.ws)
		swap(rec1, rec2);
	if (rec1.ws + rec1.we >= rec2.ws) 
		if (rec1.x < rec2.x) 
			return rec2.x - (rec1.x + rec1.h);
		else 
			return rec1.x - (rec2.x + rec2.h);
	if (rec1.x > rec2.x)
		swap(rec1, rec2);
	if (rec1.ws < rec2.ws)
		return hypot(rec2.x - (rec1.x + rec1.h), rec2.ws - (rec1.ws + rec1.we));
	else
		return hypot(rec2.x - (rec1.x + rec1.h), (rec2.ws + rec2.we) - rec1.ws);
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	freopen("street.in", "r", stdin);
	int t; cin >> t;
	while (t--)
	{
		ll H, W;
		cin >> n >> H >> W;
		vector<pair<pair<ld, ld>, pair<ld,ld>>>v(n);
		adj.clear();
		adj.resize(n + 2);
		for (int i = 0; i < n; i++)
		{
			ll h, w, d; bool f;
			cin >> h >> w >> d >> f;
			ld ws;
			if (f)
				ws = W - w; else ws = 0;
			v[i] = { { d,h },{ ws,w } };
			adj[0].push_back({ i + 1,d });
			adj[i + 1].push_back({ 0,d });
			adj[n + 1].push_back({ i+1,max(0LL,(H - (d + h))) });
			adj[i+1].push_back({ n + 1,max(0LL,(H - (d + h))) });
		}
		adj[0].push_back({ n + 1,H });
		adj[n + 1].push_back({ 0,H });
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
			{
				ld d;
				ld h1, ws1, we1, d1;
				ld h2, ws2, we2, d2;
				d1 = v[i].first.first; h1 = v[i].first.second;
				ws1 = v[i].second.first; we1 = v[i].second.second;
				d2 = v[j].first.first; h2 = v[j].first.second;
				ws2 = v[j].second.first; we2 = v[j].second.second;
				d = max((ld)0, calc({ d1,h1,ws1,we1 }, { d2,h2,ws2,we2 }));
				adj[i + 1].push_back({ j + 1,d });
				adj[j + 1].push_back({ i + 1,d });
			}
		}
		cout << dijkstra() << endl;
	}
	pause();
	return 0;
}