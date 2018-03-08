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
short arr[2000001];
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		for (int i = 0; i < n-1; i++)
			cout << arr[i] << " "; cout << arr[n - 1] << endl;
	}
	//system("pause");
	return 0;
}
