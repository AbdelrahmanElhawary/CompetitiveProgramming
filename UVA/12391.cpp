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
const int N = 16, M = 1e4 + 10, mod = 1e9 + 7;
const ld eps = 1e-9;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ld p, gp, tp, sp;
ld solve1(int s1, int s2, int n) {
	if (s1 == n && s1 - s2 >= 2)
		return 1; // i won
	if (s2 == n && s2 - s1 >= 2)
		return 0;// i lost
	if (s1 == s2 && s1 + 1 == n)// tie condition
	{
		// win win p*p
		// win lose "cycle" p*(1-p)*cycle
		// lose win "cycle" (1-p)*p*cycle
		// cycle=p*p+p*(1-p)*cycle+(1-p)*p*cycle;
		// cycle=p*p/(1-p*(1-p)-(1-p)*p);
		ld p1 = p * p; // win win
		ld p2 = p * (1 - p);// win lose
		ld p3 = (1 - p)*p;// lose win
		return p1 / (1 - p2 - p3);
	}
	return solve1(s1 + 1, s2, n)*p + solve1(s1, s2 + 1, n)*(1 - p);
}

ld solve2(int s1, int s2, int n) {
	if (s1 >= n && s1 - s2 >= 2)
		return 1; // i won
	if (s2 >= n && s2 - s1 >= 2)
		return 0;// i lost
	if (s1 == s2 && s1 == n)
		return tp; // tie condition
	return solve2(s1 + 1, s2, n)*gp + solve2(s1, s2 + 1, n)*(1 - gp);
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(11);
	//freopen("walk.in", "r", stdin);
	//kolo ray7 , ya 5rabyy
	//cout << 10 / 6. << endl;
	while (cin >> p&&p!=-1) {
		gp = solve1(0, 0, 4);
		tp = solve1(0, 0, 7);
		sp = solve2(0, 0, 6);
		// win win , win lose win ,lose win win
		ld mp = sp * sp + sp * sp*(1 - sp)+ sp * sp*(1 - sp);
		cout << gp << " " << sp << " " << mp << endl;
	}
	
	return 0;
}