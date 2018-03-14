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
int arr[1000002];
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int t, tt = 1;
	cin >> t;
	arr[1] = 1; arr[2] = 2; arr[3] = 3;
	while (t--)
	{
		int vis[102]{ 0 };
		int n, m,k; cin >> n >> m>>k;
		//cout << arr[1] << " " << arr[2] <<" "<< arr[3]<<" ";
		for (int i = 4; i <= n; i++)
		{
			arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % m + 1;
		//	cout << arr[i] << " ";
		}
		//cout << endl;
		int l = 1, e = 1e9, p1 = 1, p2 = 1, cnt = 0; bool f = 0;
		for (int i = 1; i <= n; i++)
		{
			p1 = i;
			for (; p2 <= n; p2++)
			{
				if (cnt == k)break;
				if (arr[p2] > k)continue;
				if (!vis[arr[p2]])cnt++;
				vis[arr[p2]]++;
			}
		//	cout << p1 << " " << p2 << " " << cnt << endl;
			if (cnt == k && ((e - l) > (p2 - p1))) {f = 1; e = p2; l = p1; }
			if (arr[p1] <= k) {
				vis[arr[p1]]--;
				if (!vis[arr[p1]])cnt--;
			}
		}
		if(!f)cout << "Case " << tt++ << ": sequence nai\n";
		else cout << "Case " << tt++ << ": " << e - l << endl;
	}
	//system("pause");
	return 0;
}