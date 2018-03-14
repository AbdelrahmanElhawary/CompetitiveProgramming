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
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
#define endl '\n'

using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
ll arr[100001];
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	ll n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int p1 = 0, p2 = 0, s = 0, e = 1e9;
		ll sum = 0; bool f = 0;
		for (int i = 0; i < n; i++)
		{
			p1 = i;
			for (; p2 < n; p2++)
			{
			//	cout << sum << " the sum:" << endl;
				if (sum >= m)break;
				sum += arr[p2];
			}
			//cout << sum << endl;
			if (sum >= m && (e - s) > (p2 - p1)) { f = 1; e = p2; s = p1; }
			sum -= arr[p1];
		}
		if (!f)cout << 0 << endl;
		else cout << e-s << endl;
	}
	
	
//	system("pause");
	return 0;
}