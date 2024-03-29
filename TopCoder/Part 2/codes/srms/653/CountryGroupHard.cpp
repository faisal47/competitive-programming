#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define pi acos(-1)
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz(a) (int)a.size()
#define ll long long
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
//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

#define mt 110
#define mod
int dp[mt][mt][mt],n;
vec_<int>arr;

int solve1(int pos,int pre,int cycle)
{
    if(pos == n && cycle==0)
        return 1;
    if(pos == n)
        return 0;
    int &ret=dp[pos][pre][cycle],i;
    if(ret != -1)
        return ret;
    ret=0;
    if(cycle==0)
    {
        if(arr[pos] == 0)
        {
            for(i=1; i<=n; i++)
            {
                ret+=solve1(pos+1,i,i-1);
                if(ret > 1)
                    return ret;
            }
        }
        else
        {
            ret+=solve1(pos+1,arr[pos],arr[pos]-1);
            if(ret > 1)
                return ret;
        }
    }
    else
    {
        if(arr[pos] == 0)
        {
            ret+=solve1(pos+1,pre,cycle-1);
            if(ret > 1)
                return ret;
        }
        else
        {
            if(pre != arr[pos])
                return ret=0;
            ret+=solve1(pos+1,arr[pos],cycle-1);
            if(ret > 1)
                return ret;
        }
    }
    return ret;
}

class CountryGroupHard
{
public:
    string solve(vector <int> a)
    {
        arr=a;
        n=sz(arr);
        ms(dp,-1);
        if(solve1(0,0,0) > 1)
            return "Insufficient";
        return "Sufficient";
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1)
{
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    CountryGroupHard *obj;
    string answer;
    obj = new CountryGroupHard();
    clock_t startTime = clock();
    answer = obj->solve(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p1 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
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

    vector <int> p0;
    string p1;

    {
        // ----- test 0 -----
        int t0[] = {0,2,3,0,0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Sufficient";
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {0,2,0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Insufficient";
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {0,3,0,0,3,0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Sufficient";
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {0,0,3,3,0,0};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Insufficient";
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {2,2,0,2,2};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "Sufficient";
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
// PROBLEM STATEMENT
//
// Some people are sitting in a row.
// Each person came here from some country.
// People from the same country are all sitting together.
//
//
//
// A reporter has already approached some of the people and asked each of them the same question:
// "How many people from your country (including you) are here?"
// All the people who were asked the question gave her correct answers.
//
//
//
// You are given a vector <int> a.
// The elements of a correspond to the people in the row, in order.
// For each i, element i of a is either 0 if the corresponding person was not asked the question, or a positive integer: the answer given by that person.
//
//
//
// The reporter just realized that she might be able to reconstruct all the missing answers from the answers she already knows.
// Return "Sufficient" if she can do that, or "Insufficient" if she cannot.
//
//
// DEFINITION
// Class:CountryGroupHard
// Method:solve
// Parameters:vector <int>
// Returns:string
// Method signature:string solve(vector <int> a)
//
//
// CONSTRAINTS
// -The number of elements in a will be between 1 and 100, inclusive.
// -All numbers of a will be between 0 and 100, inclusive.
// -There exist valid country assignment of people for input.
//
//
// EXAMPLES
//
// 0)
// {0,2,3,0,0}
//
// Returns: "Sufficient"
//
// The first two people must be from the same country. The last three people must also be from the same country. Thus, the only possible sequence of answers is {2,2,3,3,3}.
//
// 1)
// {0,2,0}
//
// Returns: "Insufficient"
//
// There are still two different sequences of answers that are consistent with the reporter's information: the answers can be either {1,2,2} or {2,2,1}.
//
// 2)
// {0,3,0,0,3,0}
//
// Returns: "Sufficient"
//
//
//
// 3)
// {0,0,3,3,0,0}
//
// Returns: "Insufficient"
//
//
//
// 4)
// {2,2,0,2,2}
//
// Returns: "Sufficient"
//
//
//
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
