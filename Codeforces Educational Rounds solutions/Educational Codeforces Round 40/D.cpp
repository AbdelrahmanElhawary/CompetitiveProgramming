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
const int N = 1e3 + 10;
vector<int>adj[N];
bool adj2[N][N];
int vis1[N], vis2[N];
int n, m, s, t;
void bfs()
{
	// from s to all
	vis1[s] = 0;
	queue<int>q;
	q.push(s);
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for(auto &v:adj[u])
			if (vis1[v] == -1)
			{
				vis1[v] = vis1[u] + 1;
				q.push(v);
			}
	}
	// from t to all
	vis2[t] = 0;
	q.push(t);
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (auto &v : adj[u])
			if (vis2[v] == -1)
			{
				vis2[v] = vis2[u] + 1;
				q.push(v);
			}
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj2[u][v] = adj2[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(vis1, -1, sizeof vis1);
	memset(vis2, -1, sizeof vis2);
	bfs();
	int dis = vis1[t];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (adj2[i][j] || vis1[i] + vis2[j] < dis - 1 || vis1[j] + vis2[i] < dis - 1)
				continue;
			ans++;
			//cout << vis1[i] << " " << vis2[j] << " " << dis << endl;
			//cout << i << " " << j << endl;
		}
	}
	cout << ans << endl;
	pause();
	return 0;
}