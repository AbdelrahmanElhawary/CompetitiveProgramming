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
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
bool arr[201];
int ar[201];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int t; cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		memset(arr, 0, sizeof(arr));
		int cnt = 0;
		for (int i = 0;i<k; i++)
			cin >> ar[i];
		int ans = 0;
		for (int i = 0;; i++)
		{
			if (cnt == n) { ans = i; break; }
			for (int j = 0; j < k; j++)
			{
				if (ar[j] + i <= n)
				{
					if (!arr[ar[j] + i])cnt++;
					arr[ar[j] + i]=1;
				}
				if ((ar[j] - i) > 0)
				{
					if (!arr[ar[j] - i])cnt++;
					arr[ar[j] - i] = 1;
				}
				
			}
		}
		cout << ans << endl;

	}
	
	
	
	//system("pause");
		return 0;
}