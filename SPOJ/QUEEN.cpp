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
string grid[N];
int vis[N][N];
int mask[N][N];
int getbit(int mask, int ind)
{
	return((1 << ind) & mask) == (1 << ind);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int sx, sy, ex, ey;
		for (int i = 0; i < n; i++) {
			cin >> grid[i];
			for (int j = 0; j < m; j++)
				if (grid[i][j] == 'S')sx = i, sy = j;
				else if (grid[i][j] == 'F')ex = i, ey = j;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				vis[i][j] = 1e9, mask[i][j] = 0;
		mask[sx][sy] = (1 << 8) - 1;
		int ans = -1;
		queue<pair<int, int>>q;
		q.push({ sx,sy });
		vis[sx][sy] = 0;
		while (q.size()) {
			int x = q.front().first;
			int y = q.front().second;
			int cost = vis[x][y];
			q.pop();
			if (grid[x][y] == 'F') {
				ans = cost; break;
			}
			for (int i = 0; i < 8; i++) {
				int xx = x;
				int yy = y;
				while (true) {
					xx += dx[i]; yy += dy[i];
					if (xx < 0 || xx >= n || yy < 0 || yy >= m)break;
					if (grid[xx][yy] == 'X')break;
					if (getbit(mask[xx][yy], i))break;
					if (!mask[xx][yy])vis[xx][yy] = cost + 1, q.push({ xx,yy });
					mask[xx][yy] |= (1 << i);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}