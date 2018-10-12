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
int arr[2002][2002],ans[2002][2002],par[2002],rnk[2002],N;
vector<pair<ll, int>>adj[2002];
void dijkstra(int n)
{

	set<pair<ll, int>>s;
	s.insert({ 0,n });
	while (s.size())
	{
		pair<ll, int>cur = *s.begin();
		s.erase(s.begin());
		ans[n][cur.second] = cur.first;
		for (auto &v : adj[cur.second])
			if(ans[n][v.second]==-1)
			s.insert({ v.first + cur.first, v.second });
	}
}
int mst1()
{
	ll ret = 0;
	pair<ll, int> cur;
	set<pair<ll, int>>s;
	s.insert(make_pair(0, 0));
	vector<bool>vis(N);
	while (s.size())
	{
		auto cur = *s.begin();
		s.erase(s.begin());
		if (vis[cur.second]) continue;
		vis[cur.second] = 1;
		ret += cur.first;
		for (int i = 0; i<N; i++)
			if (!vis[i])
				s.insert(make_pair(arr[cur.second][i], i));
	}
	return ret;
}
int mst2()
{
	ll ret = 0;
	pair<ll, int> cur;
	set<pair<ll, int>>s;
	s.insert(make_pair(0, 0));
	vector<bool>vis(N);
	while (s.size())
	{
		auto cur = *s.begin();
		s.erase(s.begin());
		if (vis[cur.second]) continue;
		vis[cur.second] = 1;
		ret += cur.first;
		for (int i = 0; i<N; i++)
			if (!vis[i])
				s.insert(make_pair(ans[cur.second][i], i));
	}
	return ret;
}
int find(int ind)
{
	if (par[ind] == ind) return ind;
	return par[ind]=find(par[ind]);
}
void merge(int x, int y)
{
	int xRoot = find(x);
	int yRoot = find(y);

	if (rnk[xRoot] > rnk[yRoot])
		par[yRoot] = xRoot;
	if (rnk[xRoot] < rnk[yRoot])
		par[xRoot] = yRoot;
	if (rnk[xRoot] == rnk[yRoot])
	{
		par[xRoot] = yRoot;
		rnk[yRoot]++;
	}
	return;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(2);
	int n; cin >> N;
	n = N;
	bool f = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (i==j&&arr[i][j])
				f = 1;
			if (i != j && !arr[i][j])
				f = 1;
		}
	priority_queue<pair<int, pair<int, int>>>pq;
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != arr[j][i])
				f = 1;
			if (j > i)
				pq.push({ -arr[i][j],{ -i,-j } });

		}
	}
	if (f)
		cout << "NO\n";
	else
	{
		int k = n - 1;
		while (k&&pq.size())
		{
			auto cur = pq.top();
			pq.pop();
			if (find(-cur.second.first) == find(-cur.second.second)) continue;
			k--;
			merge(-cur.second.first, -cur.second.second);
			adj[-cur.second.first].push_back({ -cur.first,-cur.second.second });
			adj[-cur.second.second].push_back({ -cur.first,-cur.second.first });
		}
		memset(ans, -1, sizeof ans);
		for (int i = 0; i < n; i++)
			dijkstra(i);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (ans[i][j] != arr[i][j])
					f = 1;
		}
		if(f)
			cout << "NO\n";
		else cout << "YES\n";
	}
		
		pause();
	return 0;
}