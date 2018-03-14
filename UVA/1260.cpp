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
#define ull unsigned ll 
#define dong long
#define endl '\n'
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int arr[1001];
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		int n; ll ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				if (arr[j] <= arr[i])ans++;
		}
		cout << ans << endl;
	}


	//system("pause");
	return 0;
}