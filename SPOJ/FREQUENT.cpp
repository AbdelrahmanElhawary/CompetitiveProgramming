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
#include<chrono>
#include<unordered_map>
#include <random>
#include <complex> 
using namespace std;
#define ll long long
#define ld double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define holla(x,y) cout <<"# holla "<<y<<" "<< #x << " is " << x << endl;
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
#define reflect(p,m) ((conj((p)/(n)))*(n))
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
const ld eps = 1e-9;
const int N = 2e5 + 50, M = 500 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
// for each query (L, R) to find the number of distinct values in the array from L to R.
const int  Q = 100100;
int n, m, a[N],cnt[N], ans[N], curL, curR, curAns, blockSize;
int last_resort[N],ansy;
struct query {
	int l, r, i;
	bool operator<(const query& rhs) const {
		if (l / blockSize != rhs.l / blockSize) {
			return l < rhs.l;
		}
		return r < rhs.r;
	}
}queries[Q];
// Inserts the given index into our current answer
void insert(int k) {
	cnt[a[k]]++;
	last_resort[cnt[a[k]]]++;
	ansy = max(cnt[a[k]], ansy);
}
// Removes the given index from our current answer
void remove(int k) {
	last_resort[cnt[a[k]]]--;
	if (!last_resort[cnt[a[k]]])ansy--;
	cnt[a[k]]--;
}
// Solves all queries according to Mo's algorithm.
void solveMO() {
	// Set Mo's algorithms variables
	blockSize = sqrt(n) + 1; curL = 0, curR = -1, curAns = 0;
	// Sort queries
	ansy = 0;
	sort(queries, queries + m);
	// Solve each query and save its answer
	for (int i = 0; i < m; ++i) {
		query& q = queries[i];
		while (curL > q.l) insert(--curL);
		while (curR < q.r) insert(++curR);
		while (curL < q.l) remove(curL++);
		while (curR > q.r) remove(curR--);
	//	cout << curL << " " << curR << endl;
		ans[q.i] = ansy;
	}
}
void read() {
	while (cin >> n) {
		if (n == 0)return; cin >> m;
		memset(last_resort, 0 ,sizeof last_resort);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i] += 100000;
		}
		for (int i = 0; i < m; ++i) {
			query& q = queries[i];
			q.i = i;
			cin >> q.l >> q.r;
			q.l--; q.r--;
		}
		solveMO();
		for (int i = 0; i < m; ++i) {
			cout << ans[i] << endl;
		}
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	//freopen("fetiera.in", "r", stdin);
	//kolo ray7 , ya 5rabyy
	read();
	return 0;
}