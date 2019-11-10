#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
int n,k;
int arr[100001];
int main()
{
     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     //freopen("", "r", stdin);
	 //freopen("", "w", stdout);

	 scanf("%d%d", &n, &k);
	 int ans = 0;
	 for(int i=0;i<n;i++)
     {
         scanf("%d", &arr[i]);
         ans += arr[i];
     }
     if(ans % k == 0)
     {
         vector<int> vec;
         int x = ans / k;
         int sum = 0, y = 0;
         for(int i=0;i<n;i++)
         {
             sum += arr[i];
             y++;
             if(sum == x)
             {
                 vec.push_back(y);
                 y = 0;
                 sum = 0;
             }
             else if(sum > x)
             {
                 printf("No");
                 return 0;
             }
         }
         y = vec.size();
         if(sum != 0 || y != k)
         {
             printf("No");
             return 0;
         }
         printf("Yes\n");
         for(int i=0;i<k;i++)
            printf("%d ", vec[i]);
     }
     else
     {
         printf("No");
     }

    return 0;
}