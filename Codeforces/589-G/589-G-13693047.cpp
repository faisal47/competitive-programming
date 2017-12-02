#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 1001
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL blocks, cum[MAX][MAX], n, m, rest[MAX*MAX], work[MAX*MAX], arr[MAX*MAX];
vector <int> sorted[MAX];

LL lower(vector <int> &v, int mn)
{
    int low = 1, high = SZ(v)-1, ret = -1, mid;
    while(low <= high)
    {
        mid = (low+high) /2;
        if(v[mid] <= mn)
            low = mid+1;
        else
        {
            ret = mid;
            high = mid-1;
        }
    }
    return ret;
}

LL query(int indx)
{
    LL baki = work[indx], mn = rest[indx];
    int i = 0;
    while(i < blocks)
    {
//        cout << "cur i" << i << endl;
        int f = lower(sorted[i], mn);
        if(f == -1)
        {
            i++;
            continue;
        }
        LL baad = cum[i][1000] - cum[i][f-1];
//        cout << "baad " << baad << endl;
        LL taken = SZ(sorted[i]) - f;
        taken *= mn;
        baad -= taken;
//        cout << "taken " << baad << endl;
        if(baki - baad > 0)
        {
            baki -= baad;
            i++;
            continue;
        }
        int orgIndx = i*1000;
        int res = orgIndx;
        while(baki > 0)
        {
            if(arr[orgIndx] > mn)
                baki -= arr[orgIndx] - mn;
            orgIndx++;
        }
        return orgIndx;
    }
    return 0;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j = 0, k;
    multiset <int> ss;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> arr[i];
        sorted[j].pb(arr[i]);
        if(SZ(sorted[j])==1000)
        {
            sorted[j].pb(-1);
            sort(all(sorted[j]));
            k = 1;

            for(k = 1; k < SZ(sorted[j]); k++)
                cum[j][k] = sorted[j][k];
            for(k = 1; k <= 1000; k++)
                cum[j][k] += cum[j][k-1];
            j++;
        }
    }
    if(!sorted[j].empty())
    {
        sorted[j].pb(-1);
        sort(all(sorted[j]));
        k = 1;
        for(k = 1; k < SZ(sorted[j]); k++)
            cum[j][k] = sorted[j][k];
        for(k = 1; k <= 1000; k++)
            cum[j][k] += cum[j][k-1];
        j++;
    }
    blocks = j;
    for(i = 0; i < n; i++)
    {
        cin >> rest[i] >> work[i];
        cout << query(i) << ' ';
    }
    return 0;
}