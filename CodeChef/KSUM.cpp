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
const int N = 1e5 + 10, M = 1e6 + 50, mod = 1e9+7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int n, m, k;
map<pair<int, int>, bool>mp;
priority_queue<pair<ll, pair<int, int>>>pq;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	//srand(time(0));
	cin >> n >> k;
	vector<int>v(n);
	ll sum = 0;
	for (auto& e : v)
		cin >> e, sum += e;
	vector<ll>ans;
	pq.push({ sum,{0,n - 1} });
	mp[{0, n - 1}] = 1;
	while (ans.size()<k) {
		ll sn = pq.top().first;
		auto e = pq.top().second;
		pq.pop();
		ans.emplace_back(sn);
		if (e.first + 1 <= e.second && mp.count({ e.first + 1,e.second }) == 0)
			pq.push({ sn - v[e.first],{e.first + 1,e.second} }), mp[{e.first + 1, e.second}] = 1;
		if (e.second - 1 >= e.first && mp.count({ e.first,e.second - 1 }) == 0)
			pq.push({ sn - v[e.second],{e.first,e.second - 1} }), mp[{e.first, e.second - 1}] = 1;
	}
	for(int i=0;i<k;i++)
	{
		if (i)cout << " ";
		cout << ans[i];
	}
	return 0;
}