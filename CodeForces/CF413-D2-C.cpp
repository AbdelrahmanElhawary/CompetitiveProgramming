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
int arr1[102];
vector<ll>v;
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr1[i];
		sum += arr1[i];
	}
	for (int i = 1; i <= m; i++)
	{
		int x; cin >> x;
		sum -= arr1[x];
		v.push_back(arr1[x]);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		sum += max(sum, v[i]);
	cout << sum << endl;
	
	//system("pause");
	return 0;
}