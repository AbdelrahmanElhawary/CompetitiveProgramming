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
ll arr[32768],ansy[32768];
int main() {

	int n;
	while (cin >> n)
	{
		for (int i = 0; i < (1<<n); i++)
			cin >> arr[i];
		for (int i = 0; i < (1 << n); i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x = i ^ (1 << j);
				ansy[i] += arr[x];
			}
		}
		ll ans = 0;
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
			{
				int x = i ^ (1 << j);
				//cout << "x= " << x << endl;
				ans = max(ans, (ll)(ansy[i] + ansy[x]));
			}
		cout <<ans << endl;
		memset(arr, 0, sizeof arr);
		memset(ansy, 0, sizeof ansy);
	}
	//system("pause");
	return 0;
}
