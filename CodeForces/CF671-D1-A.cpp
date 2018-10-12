#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#include <assert.h>
#include<complex>
#define point complex<double>
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define length(a) (hypot((a).imag(),(a).real()))
#define norm(a) (a)/length(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
ld dis(ll x1, ll y1, ll x2, ll y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	pair<ll, ll>a, b, t;
	cin >> a.first >> a.second >> b.first >> b.second >> t.first >> t.second;
	int n; cin >> n;
	ld ans = 0;
	vector<pair<ll, ll>>vv(n);
	for (int i = 0; i < n; i++)
		cin >> vv[i].first >> vv[i].second, ans += dis(vv[i].first, vv[i].second, t.first, t.second);
	ans *= 2;
	ld ansy = 1e18;
	vector<pair<ld,int>>ans1(n);
	for (int i = 0; i < n; i++)
	{
		ll x = vv[i].first, y = vv[i].second;
		ld d1 =dis(x, y, a.first, a.second), d2 = dis(x, y, t.first, t.second);
		ansy = min(ansy, ans + d1 - d2);
		d1 = dis(x, y, b.first, b.second);
		ans1[i] = { d1 - d2 ,i };
		ansy = min(ansy, ans + d1 - d2);

	}
	sort(ans1.begin(), ans1.end());
	for (int i = 0; i < n; i++)
	{
		ll x = vv[i].first, y = vv[i].second;
		ld d1 = dis(x, y, a.first, a.second), d2 = dis(x, y, t.first, t.second);
		if (ans1[0].second == i)
			ansy = min(ansy, ans + d1 - d2+ ans1[1].first);
		else ansy = min(ansy, ans + d1 - d2 + ans1[0].first);
	}
	cout << ansy << endl;
	pause();
	return 0;
}