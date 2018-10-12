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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
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
const int N = 1e5 + 10;
int n, m;
vector<vector<pair<int, ld>>>adj(N);
int bellmanford(int n, int src, int dest) {
	vector<ld>dist(n + 1, 1e16), prev(n + 1, -1);
	dist[src] = 0; prev[src] = -1;
	int modified = 1;
	for (int i = 0; modified&&i < n - 1; i++) {
		modified = 0;
		for (int i = 0; i < n; i++) { // iterate over graph o(E)
			for (auto nxt : adj[i]) {
				if (dist[i] + nxt.second < dist[nxt.first]) {
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
				if (dist[i] + nxt.second < dist[nxt.first]) {
					dist[nxt.first] = -1e9;
					prev[nxt.first] = i;
					has_negcycle = 0;
				}
			}
		}
	}
	return has_negcycle;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; ld c;
		cin >> u >> v >> c;
		u--; v--;
		c = -log10(c);
		adj[u].push_back({ v,c });
	}
	if (bellmanford(n, 0, n - 1))
		cout << "admissible\n";
	else cout << "inadmissible\n";
	



	pause();
	return 0;
}