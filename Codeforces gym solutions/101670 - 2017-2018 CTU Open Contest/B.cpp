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
#define ll long long
#define ld  double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
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
//int dx[] = { -1,0,1,0,-1,1,-1,1 };
//int dy[] = { 0,-1,0,1,1,1,-1,-1 };
ll arr[100005];
ll n; ll m;
bool check1(ld md)
{
	ld left_over = 0,take=md*m;
	for (int i = n-1;i>-1;i--)
	{
		
		left_over -= take;
		left_over += arr[i];
		if (left_over <= 0.0)return 1;
	}
	return 0;
}
ld bs1()
{
	ld s = 0, e = 1e9,ret=1e9;
	int cnt = 300;
	while (s <= e&&cnt--)
	{
		ld mid = (s + e) / 2.0;
		if (check1(mid))
		{
			e = mid - (1e-7);
			ret = mid;
		}
		else s = mid + (1e-7);
	}
	return ret;
}
bool check2(ld md)
{
	ld left_over = 0, take = md * m;
	for (int i = 0; i < n; i++)
	{

		if (arr[i] > take + left_over)
			return 0;
		left_over = (take + left_over) - arr[i];
	}
	return 1;
}
ld bs2()
{
	ld s = 0, e = 1e9, ret = 1e9;
	int cnt = 300;
	while (s <= e&&cnt--)
	{
		ld mid = (s + e) / 2.0;
		if (check2(mid))
		{
			e = mid - (1e-7);
			ret = mid;
		}
		else s = mid + (1e-7);
	}
	return ret;
	
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << bs1() << " " << bs2() << endl;
	}
	pause();
	return 0;
}