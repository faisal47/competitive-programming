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
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct info
{
    int start, en, sum;
};

info max_sum(int *data, int n);

int main()
{
    int arr[50], i = 0;
    info res;
    while(scanf("%d", &arr[i]) == 1 && arr[i])
        i++;
    res = max_sum(arr, i);
    cout << res.start << ' ' << res.en << ' ' << res.sum << endl;
    return 0;
}

info max_sum(int *data, int n)
{
    int start = 0, en = 0, tem = 0, i, sum = 0;
    info ret;
    ret.start = ret.en = ret.sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += data[i];
        if(sum < 0)
        {
            tem = i + 1;
            sum = 0;
        }
        else if(sum > ret.sum)
        {
            ret.sum = sum;
            ret.start = tem;
            ret.en = i;
        }
    }
    return ret;
}
