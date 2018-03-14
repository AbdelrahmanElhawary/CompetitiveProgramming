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
pair<int,int> arr[10001];
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int n, l;
	while (cin>>l>>n)
	{
		if (!n && !l)break;
		int s = 0, e = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y; cin >> x >> y;
			arr[i].first = max(0, x - y);
			arr[i].second = min(x + y, l);
		}
		sort(arr, arr + n);
		int p1 = 0,ans=0, cur = 0, pos = 0;
		bool f = 1;
		while (pos<l)
		{
			for (; p1 < n;p1++)
			{
				if (arr[p1].first <= pos)
					cur = max(cur, arr[p1].second);
				else break;
			}
			if (pos == cur) { f = 0; break; }
			pos = cur;
			ans++;
		}
		if (f)cout << n - ans << endl;
		else cout << "-1\n";
	}
	//system("pause");
	return 0;
}