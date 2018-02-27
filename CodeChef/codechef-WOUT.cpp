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
#include <iterator>
#include <functional> 
#include<iomanip>
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
ll arr[1000010];
int main()
{
	fast_in_out();
	int t; cin >> t;
	while (t--)
	{
		memset(arr, 0, sizeof arr);
		ll n,H; cin >> n>>H;
		for (int i = 0; i < n; i++)
		{
			ll l, h; cin >> l >> h;
			arr[l]++;
			arr[h + 1]--;
		}
		for (int i = 1; i < n; i++)
			arr[i] += arr[i - 1];
		ll ansy = 0;
		for (int i = 0; i < H; i++)
			ansy += arr[i];
		ll ans = ansy;
		for (int i = H; i < n; i++)
		{
			ansy=ansy- arr[i - H] + arr[i];
			ans = max(ansy, ans);
		}
		cout << (n * H) - ans << endl;
	}

	//system("pause");
	return 0;
}