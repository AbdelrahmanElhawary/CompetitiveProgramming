#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
#include <utility>
#include<set>
#include<string.h>
#include <deque>
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main() {
		fast_in_out();
		//cout << fixed << setprecision(0);
		int t; cin >> t;
		while (t--) {
			int n, k; cin >> n >> k;
			int c1 = 0, c2 = n - 1;
			deque<int>q;
			for (int i = 0; i < n; i++)
			{
				if (i % 2)q.push_back(c1++);
				else q.push_back(c2--);
			}
			for (int i = 0; i < n; i++)
				if (q[i] == k)cout << i << endl;
		}
	//	system("pause");
	return 0;
}