#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include<random>
#include<complex> 
using namespace std;
typedef complex<long double> point;
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

#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define PI acos(-1.)
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
const ld eps = 1e-3;
const int N = 1e3 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int n;
bool dis[N][N];
void warshall()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] |= (dis[i][k] & dis[k][j]);
	return;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	int tt = 1;
	while (cin >> n && n) {
		int id = 0;
		vector<string>v;
		map<string, int>mp;
		memset(dis, 0, sizeof dis);
	//	cout << n << endl;
		for (int i = 0; i < n; i++) {
			int m; cin >> m;
			int last = id;
			//cout << m;
			for (int j = 0; j < m; j++) {
				string s; cin >> s;
		//		cout << " " << s;
				v.emplace_back(s);
				mp[s] = id++;
			}
			//cout << endl;
			for (int j = last; j < id - 1; ++j)
				dis[j][j + 1] = 1;
		}
		n = v.size();
		int m; cin >> m;
	//	cout << m << endl;
		for (int i = 0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
		//	cout << s1 << " " << s2 << endl;
			dis[mp[s1]][mp[s2]] = 1;
		}
		warshall();
		vector<pair<int, int>>ans;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (!(dis[i][j] | dis[j][i])) {
					if (cnt < 2) {
						ans.emplace_back(i, j);
					}
					++cnt;
				}
			}
		}
		if (cnt) {
			cout << "Case "<<tt++<<", "<<cnt<<" concurrent events:\n";
			for (int i = 0; i < ans.size(); i++) {
				cout << "("<<v[ans[i].first]<<","<<v[ans[i].second] << ") ";
			}
			cout << endl;
		}
		else {
			cout << "Case "<<tt++<<", no concurrent events.\n";
		}
	}
	return 0;


}