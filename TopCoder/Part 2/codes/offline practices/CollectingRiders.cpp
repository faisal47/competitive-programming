/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
int X[]= {1,1,2,2,-1,-1,-2,-2}; //knight move//
int Y[]= {2,-2,1,-1,2,-2,1,-1}; //knight move//

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 12
#define mod

bool col[mt][mt];

int len1,len2,mot;

vector<string>arr;

int dist[mt][mt];
int dist2[mt][mt];

int check(int a,int b)
{
    return a>=0 && a<len1 && b>=0 && b<len2 && !col[a][b];
}


bool bfs(int s,int e)
{
    queue<int>q;
    ms(col,0);
    q.push(s);
    q.push(e);
    col[s][e]=1;
    int i,s1,e1,mot_temp=0;
    if(arr[s][e]!='.')
        mot_temp++;

    ms(dist,0);
    ms(dist2,0);

    while(!q.empty())
    {
        if(mot_temp>=mot)
            return 1;
        s=q.front();
        q.pop();
        e=q.front();
        q.pop();
        for(i=0; i<8; i++)
        {
            s1=s+X[i];
            e1=e+Y[i];
            if(check(s1,e1))
            {
//                deb("from ",s,e,"to",s1,e1);
                q.push(s1);
                q.push(e1);
                col[s1][e1]=1;
                dist2[s1][e1]=1+dist2[s][e];
                if(arr[s1][e1]!='.')
                {
                    if(dist2[s][e]+1 <=arr[s1][e1]-'0')
                        dist[s1][e1]=1;
                    else if(dist2[s][e]+1 >arr[s1][e1]-'0')
                    {
                        dist[s1][e1]=(dist2[s][e]+1)/(arr[s1][e1]-'0');
                        if((dist2[s][e]+1)%(arr[s1][e1]-'0'))
                            dist[s1][e1]++;
                    }
                }
                if(arr[s1][e1]!='.')
                    mot_temp++;
            }
        }
    }
    return 0;
}


int find_ans()
{
    int i,j;
    int temp=0;
    for(i=0; i<len1; i++)
        for(j=0; j<len2; j++)
            if(arr[i][j]!='.')
                temp+=dist[i][j];
    return temp;
}

class CollectingRiders
{
public:
    int minimalMoves(vector <string> board)
    {
        arr=board;
        len1=sz(board);
        len2=sz(board[0]);
        int i,j,ans;
        ans=inf;
        mot=0;
        for(i=0; i<len1; i++)
            for(j=0; j<len2; j++)
                if(board[i][j]!='.')
                    mot++;

        //deb("mot == ",mot);

        for(i=0; i<len1; i++)
        {
            for(j=0; j<len2; j++)
            {
//                cout<<arr[i][j];
                if(bfs(i,j))
                    ans=min(find_ans(),ans);
            }
//            cout<<endl;
        }

        if(ans>=inf)
            return -1;

        return ans;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1)
{
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    CollectingRiders *obj;
    int answer;
    obj = new CollectingRiders();
    clock_t startTime = clock();
    answer = obj->minimalMoves(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p1;
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    vector <string> p0;
    int p1;

    {
        // ----- test 0 -----
        string t0[] = {"...1","....","2..."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"........",".1......","........","....3...","........","........",".7......","........"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"..","2.",".."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {".1....1."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = -1;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        string t0[] = {"9133632343","5286698232","8329333369","5425579782","4465864375","8192124686","3191624314","5198496853","1638163997","6457337215"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 121;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
