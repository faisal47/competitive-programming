#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int dp[SZ][SZ];

int find_survivour(int n, int k);

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        cout << find_survivour(n, k) << endl;
    }
    return 0;
}

int find_survivour(int n, int k)
{
    if(n == 1)
        return 1;
    if(dp[n][k])
        return dp[n][k];
    return dp[n][k] = ((find_survivour(n - 1, k) + k - 1) % n) + 1;
}
