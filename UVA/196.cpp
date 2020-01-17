#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include<random>
#include<complex> 
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i < 23; i++)
		if (mask & (1 << i)) ++cnt;
	return cnt;
}
#endif
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 1e3 + 50, M = 1e5 + 10, mod = 998244353;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
struct node {
	int x, y, pos;
};
string grid[N][N];
int ans[N][N];
int vis[N][N];
int tt;
int n, m;
int dfs(int x, int y) {
	if (vis[x][y] == tt)
		return ans[x][y];
	vis[x][y] = tt;
	if (grid[x][y][0] == '=') {
		int xx = 0, yy = 0;
		int ret = 0;
		for (int i = 1; i < grid[x][y].size(); i++) {
			if (isdigit(grid[x][y][i])) {
				xx *= 10;
				xx += grid[x][y][i] - '0';
			}
			else if (isalpha(grid[x][y][i])) {
				yy *= 26;
				yy += grid[x][y][i] - 'A' + 1;
			}
			else {
		//		cout << x << " " << y << " " << xx << " " << yy << endl;
				ret += dfs(xx, yy);
				xx = 0, yy = 0;
			}
		}
		ret += dfs(xx, yy);
		return ans[x][y] = ret;
	}
	else {
		return ans[x][y] = stoi(grid[x][y]);
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int t; cin >> t;
	while (t--) {
		cin >> m >> n;
		tt++;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> grid[i][j];
		//		cout << grid[i][j] << " ";
			}
			//cout << endl;
		}
	//	return 0;
		for (int i= 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (vis[i][j] != tt)
				dfs(i, j);
				cout << ans[i][j] << " \n"[j == m];
			}
		}
	}
	return 0;
}