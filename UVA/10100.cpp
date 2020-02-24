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
const ld eps = 1e-9;
const int N = 1e3 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
vector<string>get(string s) {
	string str="";
	stringstream ss(s);
	vector<string>v;
	while (ss >> str)v.push_back(str);
	return v;
}
int dp[N][N];
string print(int x) {
	string s;
	if (x >= 10)
		s = to_string(x);
	else s = " " + to_string(x);
	return s;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int tt = 1;
	string s1,s2;
	while (getline(cin, s1)) {
		getline(cin, s2);
		if (s1.empty() || s2.empty()) {
			cout << print(tt++) << ". Blank!\n";
			continue;
		}
		for (auto& e : s1) {
			if (!isalpha(e)&&!isdigit(e))e = ' ';
		}
		for (auto& e : s2) {
			if (!isalpha(e)&&!isdigit(e))e = ' ';
		}
		int ans = 0;
		vector<string>v1,v2;
		v1 = get(s1);
		v2 = get(s2);
		int n = v1.size(),m=v2.size();
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				if (v1[i - 1] == v2[j - 1])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		cout << print(tt++)<<". Length of longest match: "<<dp[n][m]<<"\n";
	}
	return 0;

}