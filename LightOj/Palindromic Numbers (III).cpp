#include <bits/stdc++.h>
#define sz(a) len
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sci1(a) scanf(" %d",&a)
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

#define mt 100010
#define mod

char arr[mt];

int main ()
{
//    cffi;
    int i,j,test,t=1,l,r,p;
    bool flag;
    int len;
    sci1(test);

    while(test--)
    {
        scanf(" %s",arr);
        printf("Case %d: ",t++);
        len=strlen(arr);
        if(len==1 && arr[0]!='9')
        {
            arr[0]++;
            puts(arr);
            continue;
        }

        for(i=0; i<len; i++)
        {
            if(arr[i]!='9')
                break;
        }

        if(i==len)
        {
            printf("1");
            len--;
            for(i=0; i<len; i++)
                printf("0");
            printf("1\n");
            continue;
        }

        flag=0;
        l=len/2;
        l--;
        r=l+1;
        if(len & 1)
            r++;
        p=-1;
        while(l>=0)
        {
            if(arr[l]>arr[r])
            {
                arr[r]=arr[l];
                flag=1;
            }
            else if(arr[l]<arr[r])
            {
                if(flag)
                    arr[r]=arr[l];
                else
                    arr[l]=arr[r];
                flag=1;

                if(p==-1)
                    p=l;
            }
            else if(!flag && arr[l]!='9')
            {
                arr[l]++;arr[r]++;
                flag=1;
                if(p==-1)
                    p=l;
            }

            l--;
            r++;
        }
//        deb("hola");
        if(!flag)
        {
            l=len/2;
            l--;
            r=l+1;
            if(len&1)
            {
                if(arr[len/2]!='9')
                {
                    arr[len/2]++;
                    flag=1;
                }
                r++;
            }
            if(!flag)
            {
                while(l>=0)
                {
                    if(arr[l]!='9')
                    {
                        arr[l]++;
                        arr[r]++;
                        p=l;
                        break;
                    }
                    l--;
                    r++;
                }
            }
        }

        if(p!= -1)
        {
            l=p+1;
            r=len-l-1;

            while(l<=r)
            {
                arr[l]=arr[r]='0';
                l++;
                r--;
            }

        }
        puts(arr);
    }

    return 0;
}


