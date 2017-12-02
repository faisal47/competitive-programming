#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long int arr[1000005],pos[1000005],col[105],dif[1000005];
int main ()
{
    long int e,f,g,c,test,n,m,k,i,a,b,c1,start,j,flag1,temp,c2=1,flag;
    cin>>test;
    while(test--)
    {
        memset(col,0,sizeof(col));
        c=b=c1=start=flag1=flag=0;
        scanf("%ld %ld %ld",&n,&m,&k);
        for(i=1; i<=n; i++)
        {
            if(i<4)
            {
                if(i==1)
                {
                    a=e=1;
                }
                else if(i==2)
                {
                    a=f=2;
                }
                else
                {
                    a=g=3;
                }
            }
            else
            {
                a=(((e+f+g)%m)+1);
                e=f;
                f=g;
                g=a;
            }
            if(a>=1&&a<=k)
            {
                if(col[a]==0&&b<k)
                {
                    col[a]=1;
                    b+=1;
                }
                pos[c]=i;
                arr[c]=a;
                ++c;
                if(b==k)
                {
                    while(1)
                    {
                        flag1=0;
                        for(j=start+1; j<c; j++)
                        {
                            if(arr[start]==arr[j])
                            {
                                flag=1;
                                flag1=1;
                                start+=1;
                                break;
                            }
                        }
                        if(flag1==0)
                        {
                            if(flag==1)
                            {
                                dif[c1++]=(pos[c-1]-pos[start]+1);
                            }
                            break;
                        }
                    }
                }
            }
        }
        if(b!=k)
        {
            cout<<"Case "<<c2++<<": sequence nai"<<endl;
            continue;
        }
        sort(dif,dif+c1);
        cout<<"Case "<<c2++<<": "<<dif[0]<<endl;
    }
    return 0;
}
