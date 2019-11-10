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
#include <random>
#include <complex> 
using namespace std;
#define ll long long
#define ld long double
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
const int N = 1e4 + 40, M = 30, mod = 1e9 + 7;
const ld eps = 1e-9;
int v[N][M];
ll gcd(ll a, ll b)
{
	if (!b)return a;
	return gcd(b, a%b);
}

int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	//kolo ray7 , ya 5rabyy
	//cout << 10 / 6. << endl;
	int n, m, t = 1;
	while (cin >> n >> m && n) {
		int last = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				if (v[i][j])
					last = max(last, j);
			}
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += v[i][last];
		for (int i = 0; i < n;i++) {
			ll x = v[i][last];
			if (sum == 0)
				cout << "1 / 1\n";
			else if (x == 0)
				cout << "0 / 1\n";
			else {
				ll g = gcd(x, sum);
				cout << x / g << " / " << sum / g << endl;
			}
		}
	}
	return 0;
}