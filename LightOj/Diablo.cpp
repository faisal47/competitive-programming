#include <bits/stdc++.h>

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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define fop   freopen("output.txt","w",stdout);
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
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
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}




#define mt 150010

int seg[4*mt][2],arr[mt];

void build(int node,int l,int r)
{
    if(l==r)
    {
        seg[node][1]=arr[l];
        if(arr[l])
        seg[node][0]=1;

        return;
    }
    int mid=(l+r)>>1;
    build(node<<1,l,mid);
    build((node<<1)|1,mid+1,r);
    seg[node][0]=seg[node<<1][0]+seg[(node<<1)|1][0];
}
int ans,num;

void query(int node,int l,int r,int pos)
{
    if(pos < 1 || pos > seg[node][0])
        return;

    if(l==r && seg[node][0]==1)
    {
        ans=seg[node][1];
        seg[node][0]=0;
        return;
    }

    int ac=seg[node<<1][0];

    int mid=(l+r)>>1;
    query(node<<1,l,mid,pos);
    query((node<<1)|1,mid+1,r,pos-ac);

    seg[node][0]=seg[node<<1][0]+seg[(node<<1)|1][0];

    return;
}

int m;
void update(int node,int l,int r)
{
    if(m < l || m > r)
        return;

    if(l==r)
    {
        seg[node][0]=1;
        seg[node][1]=num;
        return;
    }

    int mid=(l+r)>>1;
    update(node<<1,l,mid);
    update((node<<1)|1,mid+1,r);
    seg[node][0]=seg[node<<1][0]+seg[(node<<1)|1][0];
}

int main ()
{
//    fop;
//    cffi;
    int i,j,test,t=1,n,q,pos;
    char ch;
    sci1(test);
//    cin>>test;
    while(test--)
    {
        sci2(n,q);
//        cin>>n>>q;

        ms(seg,0);
        ms(arr,0);

        for(i=1;i<=n;i++)
            sci1(arr[i]);

        build(1,1,n+q);
        m=n;
        n+=q;
//        cout<<"Case "<<t++<<":"<<endl;
        printf("Case %d:\n",t++);
        while(q--)
        {
            scch(ch);
            if(ch=='c')
            {
                ans=0;
                sci1(pos);
                query(1,1,n,pos);

                if(ans)
                    printf("%d\n",ans);
                else
                    printf("none\n");
            }
            else
            {
                sci1(num);
                m++;
                update(1,1,n);
            }
        }
    }

    return 0;
}


