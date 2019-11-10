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
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define holla(x) cout << #x << " is " << x << endl;
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
const int N = 1e5 + 300, M = 1000 + 5, mod = 998244353;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
const int MAX = 1e5 + 10;
int n, par[MAX], rnk[MAX];
int find(int ind)
{
	if (par[ind] == ind) return ind;
	return par[ind] = find(par[ind]);
}
void merge(int x, int y)
{
	int xRoot = find(x);
	int yRoot = find(y);
	if (rnk[xRoot] > rnk[yRoot])
		par[yRoot] = xRoot;
	if (rnk[xRoot] < rnk[yRoot])
		par[xRoot] = yRoot;
	if (rnk[xRoot] == rnk[yRoot])
	{
		par[xRoot] = yRoot;
		rnk[yRoot]++;
	}
	return;
}
struct node
{
	int x, y, id;
}ar[N];
int get() {
	string s; cin >> s;
	int cnt = 100; int sz = s.size();
	if (s.find('.') != string::npos) {
		if (s[sz - 2] == '.')cnt /= 10;
		if (s[sz - 3] == '.')cnt /= 100;
		s.erase(s.begin() + s.find('.'));
	}
	return stoi(s)*cnt;
}
ll dis(ll x1, ll y1, ll x2, ll y2) {
	ll x = x1 - x2;
	ll y = y1 - y2;
	return x * x + y * y;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	//kolo ray7 , ya 5raby
	int t, tt = 1; cin >> t;
	while (t--) {
		int n; ll d;
		cin >> n;
		d = get();
		//cout << d << endl;
		d *= d;
		for (int i = 0; i < n; i++) {
			int x, y;
			x = get(); y = get();
			ar[i] = { x,y,i };
			par[i] = i; rnk[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (find(ar[i].id) == find(ar[j].id))continue;
				if (dis(ar[i].x, ar[i].y, ar[j].x, ar[j].y) <= d) {
					merge(ar[i].id, ar[j].id);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += (find(i) == i);
		cout <<"Case "<<tt++<<": "<< cnt << endl;
	}
	return 0;
}