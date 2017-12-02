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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int sequence[100], I[101], L[100], lislength;

int input(void);
int lis(int);
void printseq(void);

int main()
{
    int n = lis(input());
    printseq();
    printf("\n%d\n", n);
    return 0;
}

int input(void)
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &sequence[i]);
    I[0] = -infinity;
    for(i = 1; i <= n; i++)
        I[i] = infinity;
    return n;
}

int lis(int n)
{
    int i, low, high, mid;
    lislength = 0;
    for(i = 0; i < n; i++)
    {
        low = 0, high = lislength;
        while(low <= high)
        {
            mid = low + high >> 1;
            if(I[mid] < sequence[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = sequence[i];
        L[i] = low;
        if(lislength < low)
            lislength = low;
    }
    return lislength;
}

void printseq(void)
{
    int pos, i, n, j, arr[lislength], val = lislength;
    for(i = 0; i < 10; i++)
        if(L[i] == lislength)
        {
            pos = i;
            arr[val - 1] = sequence[pos];
            val--;
            break;
        }
    for(i = pos; i >= 0; i--)
    {
        if(L[i] == val && sequence[pos] > sequence[i])
        {
            arr[val - 1] = sequence[i];
            val--;
            pos = i;
        }
    }
    for(i = 0; i < lislength; i++)
        cout << arr[i] << ' ';
}
