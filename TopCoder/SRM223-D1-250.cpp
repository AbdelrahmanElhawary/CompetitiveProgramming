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
class QuizShow {
public:
	int wager(vector<int>scores, int wager1, int wager2){
		int ans = 0, mx = 0;
		for (int i = 0; i <= scores[0]; i++) {
			int cnt = 0;
			for (int mask = 0; mask < 8; mask++) {
				int money, mx = 0;
				if (mask & 1)money = scores[0] + i;
				else money = scores[0] - i;
				if (mask & 2)mx = max(mx, scores[1] + wager1);
				else mx = max(mx, scores[1] - wager1);
				if (mask & 4)mx = max(mx, scores[2] + wager2);
				else mx = max(mx, scores[2] - wager2);
				cnt += (money > mx);
			}
			if (cnt > mx)
				mx = cnt, ans = i;
		}
		return ans;
	}
};