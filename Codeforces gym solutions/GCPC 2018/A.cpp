/*
for:
Hussien , Ayman , Emad
Abanob , George , Genawy
Ka8eem , Mosta7il , Stawro
 
 ICPC DREAM
 */
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
//int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
//int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int dx[] = { 0,1,1,1,-1,1,0,0 };
int dy[] = { 0,0,-1,1,0,0,-1,1 };
const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int N = 1e6+10,M=22;
string grid[1005];
// par[j][i]    = the (2^j)-th ancestor of node number i. 
// dis[i]       = the distance to reach node i from the root (node 1). 
// LOG[i]       = floor(log2(i)). 
int n, m, u, v, dis[N], par[M][N], LOG[N];
vector<int> adj[N]; 
// Depth first traversal on the tree to fill par[j][i] and dis[i] arrays
// with the appropriate values .
// O(n.log(n)) 
void dfs(int u = 0, int p = 0, int lvl = 0) {
	//cout << u << " " << lvl << " " << p << endl;
	dis[u] = lvl; par[0][u] = p;
	for (int i = 1; (1 << i) <= lvl; ++i) {
		par[i][u] = par[i - 1][par[i - 1][u]];
	}
	for (int v : adj[u]) {
		if (v != p)
			dfs(v, u, lvl + 1); 
	}
}
// Computes the floor of the log of integer from 1 to n. 
// After calling this function, LOG[i] will be equals to floor(log2(i)). 
// O(n) 
void computeLog() {
	LOG[0] = -1;
	for (int i = 1; i < N; ++i) {
		LOG[i] = LOG[i - 1] + !(i & (i - 1)); 
	}
}
// Builds the LCA structure. 
// O(n.log(n)) 
void buildLCA() {
	dfs();
	computeLog();
}
// Returns the k-th ancestor of node u. 
// O(log(k)) 
int getAncestor(int u, int k) {
	while (k > 0) {
		int x = k & -k;
		k -= x;
		u = par[LOG[x]][u];
	}
	return u;
}
// Returns the lowest common ancestor of nodes u and v. 
// O(log(n)) 
int getLCA(int u, int v) {
	if (dis[u] > dis[v]) {
		swap(u, v);
	}
	v = getAncestor(v, dis[v] - dis[u]);
	if (u == v)
		return u;
	for (int i = LOG[dis[u]]; i >= 0; --i) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u]; v = par[i][v];
		}
	}
	return par[0][u];
}
// Returns the distance between any given pair of nodes 
// O(getLCA(u, v)) = O(log(log(n)))
int getDistance(int u, int v) {
	int l = getLCA(u, v);
	//cout << u << " " << v << " " << l << endl;
	//cout << dis[u] << " " << dis[v] << " " << dis[l] << endl;
	return dis[u] + dis[v] - 2 * dis[l];
} 
int main() {
	fast_in_out();
    //cout << fixed << setprecision(7);
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i <= n; i++) {
		getline(cin, grid[i]);
	}
	for (int i = 0; i < n; i++) {
		int col = 1;
		//cout << grid[i]<<endl;
		for (int j = 0; j < m; j++, col += 2) {
			int u = i * m + j;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = col + dy[k];
				int v = (i + dx[k + 4])*m + (j + dy[k + 4]);
	//			cout << x << " " << y << endl;
				if (grid[x][y] == ' ') {
			//		cout << grid[x][y] << endl;
					adj[u].push_back(v);
				//	cout << v << endl;
					//adj[v].push_back(u);
				}
			}	
		}
	}	
	/*for (int i = 0; i < n*m; i++) {
		if (adj[i].size()) {
			cout << "node : " << i/m<<" "<<i%m << endl;
			for (auto e : adj[i])
				cout << e/m<<" "<<e%m << "\n";
			cout << endl;
		}
	}
	*/buildLCA();
	int q; cin >> q;
	int x, y;
	cin >> x >> y;
	--x; --y; --q;
	int u = x * m + y;
	ll ans = 0;
	while (q--) {
		cin >> x >> y;
		--x; --y;
		int v = x * m + y;
		ans += getDistance(u, v);
//		cout << ans << endl;
		u = v;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}