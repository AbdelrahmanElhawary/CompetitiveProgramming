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
int bellmanford(int n, int src, int dest) {
	vector<int>dist(n + 1, 1e9), prev(n + 1, -1);
	dist[src] = 0; prev[src] = -1;
	int modified = 1;
	for (int i = 0; modified&&i < n - 1; i++) {
		modified = 0;
		for (int i = 0; i < n; i++) { // iterate over graph o(E)
			for (auto nxt : adj[i]) {
				if (dist[i] != 1e9&&dist[i] + nxt.second < dist[nxt.first]) {
					dist[nxt.first] = dist[i] + nxt.second;
					prev[nxt.first] = i;
					modified = 1;
				}
			}
		}
	}
	//cout << dist[dest] << endl;
	int has_negcycle = -1;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < n; i++) { // iterate over graph o(E)
			for (auto nxt : adj[i]) {
				if (dist[i] != 1e9&&dist[i] + nxt.second < dist[nxt.first]) {
					dist[nxt.first] = -1e9;
					prev[nxt.first] = i;
					has_negcycle = nxt.first;
				}
			}
		}
	}
	return has_negcycle != -1;
	if (has_negcycle == -1) {
		cout << "No negative cycles\n";
	}
	else {
		int end = has_negcycle;
		for (int i = 0; i < n; i++) {
			end = prev[end];
		}
		vector<int> path;
		for (int cur = end;; cur = prev[cur])
		{
			path.push_back(cur);
			if (cur == end && path.size() > 1)
				break;
		}
		reverse(path.begin(), path.end());
		cout << "Negative cycle: ";
		for (int i = 0; i < path.size(); ++i)
			cout << path[i] << ' ';
	}
	return has_negcycle;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(1);
	int t; cin >> t;
	while (t--)
	{
		adj.clear();
		int n, m; cin >> n >> m;
		adj.resize(n);
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			adj[u].push_back({ v,d });
		}
		if (bellmanford(n, 0, n-1))
			cout << "possible\n";
		else cout << "not possible\n";
	}
	pause();
	return 0;
}