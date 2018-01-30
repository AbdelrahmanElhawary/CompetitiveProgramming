#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
using namespace std;
int arr[100001];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int mn = arr[0], mx = arr[n - 1];
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > mn&&arr[i] < mx)ans++;
	cout << ans << endl;
	//system("pause");
	return 0;
}