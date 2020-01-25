#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#includebitsstdc++.h
#includechrono
#includeunordered_map
#includerandom
#includecomplex 
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl 'n'
#define mk make_pair
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i  23; i++)
		if (mask & (1  i)) ++cnt;
	return cnt;
}
#endif
void fast_in_out() {
	stdios_basesync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen(input.txt, r, stdin);
	freopen(output.txt, w, stdout);
#endif
}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 1e5 + 50, M = 1e5 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) {  return b gcd(b, a % b)  a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t  (a  t  b)  0; }
int vis[5005][5005];
int dp[5005][5005];
int vid;
int ar[N];
int n, k;
int solve(int i,int j,int cnt=0) {
	if (cnt  k)return cnt;
	if (i = (n - j - 1))return 0;
	int& ret = dp[i][j];
	if (vis[i][j] == vid)
		return ret;
	ret = 1e9;
	if (ar[i] == ar[n - j - 1])
		return ret = solve(i + 1, j + 1,cnt);
	ret = min(ret, solve(i + 1, j,cnt+1) + 1);
	ret = min(ret, solve(i, j + 1,cnt+1) + 1);
	return ret;
}
int main() {
	fast_in_out();
	cout  fixed  setprecision(6);
	int t; cin  t;
	while (t--) {
		cout  Case ++vid ;
		cin  n  k;
		for (int i = 0; i  n; i++)
			cin  ar[i];
		int x = solve(0, 0);
		if (x == 0)cout  Too easyn;
		else if (x = k)cout  x  endl;
		else cout  Too difficultn;
	}

	return 0;
}