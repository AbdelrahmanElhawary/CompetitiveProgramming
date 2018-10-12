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
#include<unordered_map>
#define ll long long
#define ld long double
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
pair<pair<ll, ll>, ll>arr[100005];
ll cost[100005]; int n, k;
ll bs(ll en)
{
	int s = 0, e = n - 1, ret =-1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (arr[mid].first.first <= en)
		{
			s = mid + 1;
			ret = mid;
		}
		else e = mid - 1;
	}
	return ret;
}
ll bs2(ll st)
{
	int s = 0, e = n - 1, ret = -1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (arr[mid].first.second >= st)
		{
			e = mid - 1;
			ret = mid;
		}
		else s = mid + 1;
	}
	return ret;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
		}
		sort(arr, arr + n);
		for (int i = 0; i < n; i++)
		{
			cost[i] = arr[i].second*(arr[i].first.second - arr[i].first.first + 1);
			if (i)cost[i] += cost[i - 1];
		}
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			ll s = arr[i].first.first, e = min((ll)1e9, s + k - 1);
			ll ind = bs(e);
			ll ansy;
			if (arr[ind].first.second <= e)
			{
				ansy = cost[ind];
				if (i)ansy -= cost[i - 1];
			}
			else {
				ansy = cost[ind-1];
				if (i)ansy -= cost[i - 1];
				ansy += (e - arr[ind].first.first + 1)*arr[ind].second;
			}
			ans = max(ansy, ans);
			s = max(0LL, arr[i].first.second - k + 1), e = arr[i].first.second;
			ind = bs2(s);
			ansy;
			if (arr[ind].first.first >= s)
			{
				ansy = cost[i];
				if (ind)ansy -= cost[ind - 1];
			}
			else {
				ansy = cost[i];
				ansy -= cost[ind];
				ansy += (arr[ind].first.second- s + 1)*arr[ind].second;
			}
			ans = max(ansy, ans);
		}
		cout << ans << endl;

	}
	pause();
	return 0;
}