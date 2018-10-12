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
const int N = 1e3 + 10;
vector<vector<pair<int, int>>>adj(N);
vector<int>dist;
void bellmanford(int n, int src, int dest) {
	dist[src] = 0;
	int modified = 1;
	for (int i = 0; modified&&i < n - 1; i++) {
		modified = 0;
		for (int i = 0; i < n; i++) { // iterate over graph o(E)
			for (auto nxt : adj[i]) {
				if (dist[i] != 1e9&&dist[i] + nxt.second < dist[nxt.first]) {
					dist[nxt.first] = dist[i] + nxt.second;
					modified = 1;
				}
			}
		}
	}
//	for (int i = 0; i < n; i++)
	//	cout << dist[i] << endl;
		//cout << dist[dest] << endl;
	int has_negcycle = -1;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < n; i++) { // iterate over graph o(E)
			for (auto nxt : adj[i]) {
				if (dist[i] != 1e9&&dist[i] + nxt.second < dist[nxt.first]) {
					dist[nxt.first] = -1e9;
					has_negcycle = nxt.first;
				}
			}
		}
	}
}
int calc(int u, int v)
{
	int k = u - v;
	return k * k * k;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(1);
	int n,tt=1;
	while (cin >> n)
	{
		vector<int>cost(n + 1);
		adj.clear();
		adj.resize(n + 1);
		dist.clear();
		dist.resize(n + 1, 1e9); 
		for (int i=0; i < n; i++)
			cin >> cost[i];
		int m; cin >> m;
		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			u--; v--;
		//	cout << calc(cost[v], cost[u])<<endl;
			adj[u].push_back({ v,calc(cost[v], cost[u]) });
		//	adj[v].push_back({ u,calc(cost[u], cost[v]) });
		}
		bellmanford(n, 0, 1);
		//for (int i = 0; i < dist.size(); i++)
	//		cout << dist[i] << " "; cout << endl;
		int q; cin >> q;
		cout << "Set #"<<tt++ << endl;
		while (q--)
		{
			int k; cin >> k;
			k--;
			if (dist[k] < 3||dist[k]==1e9) cout << "?\n";
			else cout << dist[k] << endl;
		}
	}
	pause();
	return 0;
}