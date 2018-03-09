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
ll arr[50002],n;
void upper(int x)
{
	int s = 0, e = n - 1,ret = -1;
	while (s <= e)
	{
		int mid = (s + e)/2;
		if (arr[mid] > x)
		{
			ret = mid;
			e = mid - 1;
		}
		else if(arr[mid]<=x)  s = mid + 1;
	}
	if (ret != -1) { cout << arr[ret]; return; }
	cout << 'X';
	return;
}
void lower(int x)
{
	int s = 0, e = n - 1, ret = -1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (arr[mid] < x)
		{
			ret = mid;
			s = mid +1;
		}
		else if (arr[mid]>=x)  e = mid - 1;
	}
	if (ret != -1) { cout << arr[ret]; return; }
	cout << 'X';
	return;
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	 cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int q; cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x; cin >> x;
		lower(x);
		cout << " ";
		upper(x);
		cout << endl;
	}
	//system("pause");
	return 0;
}
