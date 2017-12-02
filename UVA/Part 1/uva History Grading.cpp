#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int d,pos[30],l[30],s[30],fs[30],n,i,c,lis,j,fpos[30];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>c;
        pos[c]=i;
    }
    for(i=1;i<=n;i++)
    fpos[pos[i]]=i;
    c=0;
    while(cin>>d)
    {
        c++;
        s[d]=c;
        l[c]=1;
        if(c==n)
        {
            lis=1;
            for(i=1;i<=n;i++)
            fs[i]=fpos[s[i]];
            //s1[i]=pos[s[i]];
//            cout<<s[i]<<" ";
//            cout<<endl;
//            for(i=1;i<=n;i++)
//            cout<<l[i]<<" ";
//            cout<<endl;
            for(i=1;i<=n;i++)
            {
                for(j=i+1;j<=n;j++)
                {
                    if(fs[j]>fs[i])
                    {
                        if(l[j]<(l[i]+1))
                        l[j]=l[i]+1;
                        lis=max(l[j],lis);
                    }
                }
            }
            c=0;
            cout<<lis<<endl;
        }
    }
    return 0;
}
