#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

struct node
{
	int ind, dis;
};

bool operator < (node a, node b)
{
	if (a.dis != b.dis) return a.dis < b.dis;
	return a.ind < b.ind;
}

int n, m, e, d;
vector<int> arr[101];
vector<int> cst[101];
int ans[101];
set<node> S;
node cur, temp;

void dijkstra()
{
	S.clear();
	cur.ind = e;
	cur.dis = 0;
	S.insert(cur);
	while (S.size())
	{
		cur = *S.begin();
		S.erase(S.begin());

		if (cur.dis > d) return;
		if (ans[cur.ind] != -1) continue;
		ans[cur.ind] = cur.dis;

		for (int i = 0; i<arr[cur.ind].size(); i++)
		{
			temp.ind = arr[cur.ind][i];
			temp.dis = cur.dis + cst[cur.ind][i];
			S.insert(temp);
		}
	}
	return;
}


int main() {
	int x, y, c;
	int t; cin >> t;
	while (t--) {
		for (auto &v : arr)
			v.clear();
		for (auto&v : cst)
			v.clear();
		cin >> n >> e >> d >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> c;
			arr[y].push_back(x); //reversed route
			cst[y].push_back(c);
		}
		memset(ans, -1, sizeof ans);
		dijkstra();

		int ret = 0;
		for (int i = 1; i <= n; i++)
			if (ans[i] <= d && ans[i] != -1)
				ret++;

		cout << ret << endl;
		if (t)cout << endl;
	}
	//system("pause");
	return 0;
}