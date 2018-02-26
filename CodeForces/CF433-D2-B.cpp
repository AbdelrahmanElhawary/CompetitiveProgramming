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
ll arr1[100002], arr2[100002];
int main() {
	fast_in_out();
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr1[i]; arr2[i] = arr1[i];
	}
	sort(arr2, arr2 + n+1);
	for (int i = 1; i <= n; i++)
	{
		arr1[i] += arr1[i - 1];
		arr2[i] += arr2[i - 1];
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int f,l, r;
		cin >> f >> l >> r;
		if(f==1) cout << arr1[r] - arr1[l - 1]<<endl;
		else cout << arr2[r] - arr2[l - 1] << endl;
	}

	//system("pause");
	return 0;
}