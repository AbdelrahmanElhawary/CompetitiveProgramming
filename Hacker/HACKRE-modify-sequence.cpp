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

void fast_in_out() 
{
	
std::ios_base::sync_with_stdio(NULL);

	cin.tie(NULL); cout.tie(NULL);

}

vector<int>v;

int main() {

		fast_in_out();

	//	cout << fixed << setprecision(4);

		int n; cin >> n;

		for (int i = 0; i < n; i++)

		{

			int x; cin >> x;

			v.push_back(x);

		}

		bool f = 1;

		for (int i = 0; i < n-1; i++)

		{

			int x = min(v[i], v[i + 1]);

			v[i] -= x; v[i + 1] -= x;

			if (v[i] != 0) { f = 0; break; }

		}

		if (v[n-1] != 0) { f = 0; }

		if (f)cout << "YES\n"; else cout << "NO\n";

		//system("pause");

	return 0;

}
