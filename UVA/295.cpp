/*
for:
Hussien , Ayman , Emad
Abanob , George , Genawy
Ka8eem , Mosta7il , Stawro
Shahat , Omar
ICPC DREAM
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<unordered_map>
#include <random>
#include <complex> 
using namespace std;
#define ll long long
#define ld double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define holla(x) cout << #x << " is " << x << endl;
typedef complex<long double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(), (n).end()
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine 
enum STATE { IN, OUT, BOUNDRY };
const double PI = acos(-1.0);
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i < 23; i++)
		if (mask&(1 << i)) ++cnt;
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
const int N = 110, M = 1e4 + 10, mod = 1e9 + 7;
const ld eps = 1e-9;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int n;
int x[N], y[N];
int dis[105][105];
int h, w;
int vis[105];
int vid;
int calc(int i, int j) {
	int a = x[i] - x[j]; a *= a;
	int b = y[i] - y[j]; b *= b;
	return a + b;
}
bool check(int r) {
	++vid;
	queue<int>q;
	q.push(0);
	vis[0] = vid;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 1; i <= n + 1; i++) {
			if (vis[i] != vid && dis[u][i] < r)
				vis[i] = vid, q.push(i);
		}
	}
	return vis[n + 1] != vid;
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(4);
	//freopen("walk.in", "r", stdin);
	//kolo ray7 , ya 5rabyy
	//cout << 10 / 6. << endl;
	int t,tt=1; cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		for (int i = 1; i <= n; i++)
			cin >> x[i] >> y[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) 
				dis[i][j] = dis[j][i] = calc(i, j);
			dis[0][i] = dis[i][0] = y[i] * y[i];
			dis[n + 1][i] = dis[i][n + 1] = (w - y[i])*(w - y[i]);
		}
		dis[0][n + 1] = dis[n + 1][0] = w * w;
		int s = 0, e = w * w, ret = 0;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (check(mid))
				s = mid + 1, ret = mid;
			else e = mid - 1;
		}
		cout << "Maximum size in test case "<<tt++<<" is "<<sqrt(ret)<<".\n";
	}
	return 0;
}