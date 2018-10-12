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
int main() {
	fast_in_out();
//	cout << fixed << setprecision(2);
	int n, m, v;
	cin >> n >> m >> v;
	vector<int>num(n + 1);
	for (int i = 1; i <= n; i++)
		num[i] = i;
	swap(num[2], num[v]);
	vector<pair<int, int>>ans;
	for (int i = 1; i < n&&m; i++)
	{
		ans.push_back({ num[i],num[i + 1] });
		m--;
	}
	for (int i = 4; i <= n&&m; i++)
	{
		ans.push_back({ v,num[i] });
		m--;
	}
	for (int i = 3; i <= n&&m; i++)
	{
		for (int j = i + 2; j <= n&&m; j++)
			ans.push_back({ num[i],num[j] }),m--;
	}
	if (m||ans.size()<n-1)cout << -1 << endl;
	else {
		for (auto &x : ans)
			cout << x.first << " " << x.second << endl;
	}
	pause();
	return 0;
}