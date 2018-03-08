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
int main() {
	fast_in_out();
	//	cout << fixed << setprecision();
	int n;
	while (cin >> n)
	{
		queue<int>q;
		stack<int>stk;
		priority_queue<int>pq;
		bool f1 = 1, f2 = 1, f3 = 1;
		for (int i = 0; i < n; i++)
		{
			int x, y; cin >> x >> y;
			if (x == 1)
			{
				q.push(y);
				stk.push(y);
				pq.push(y);
			}
			if (x == 2)
			{
				if (q.size() == 0) { f1 = f2 = f3 = 0; continue; }
				if (q.front() != y)f1 = 0;
				if (stk.top() != y)f2 = 0;
				if (pq.top() != y)f3 = 0;
				q.pop(); stk.pop(); pq.pop();
			}
		}
		int c = f1 + f2 + f3;
		if (f1 && !f2 && !f3)cout << "queue\n";
		else if (!f1 && f2 && !f3)cout << "stack\n";
		else if (!f1 && !f2 && f3)cout << "priority queue\n";
		else if (c >= 2)cout << "not sure\n";
		else if (!c)cout << "impossible\n";

	}
	
	//system("pause");
	return 0;
}
