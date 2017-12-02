/// "All the praises be to Allâh, the Lord of the 'Alamîn (worlds i.e. mankind, jinns and all that exists)"///

#include<bits/stdc++.h>

/// "All the praises be to Allâh, the Lord of the 'Alamîn (worlds i.e. mankind, jinns and all that exists)"///

using namespace std;

int main ()
{
    int i,test,t=1,n,a,c1,mot;
    scanf("%d",&test);
    while(test--)
    {
        mot=c1=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(a<0)
                c1++;
            mot+=abs(a);
        }

        printf("Case %d: ",t++);

        if(n == c1)
        {
            puts("inf");
        }
        else
        {
            n-=c1;
            printf("%d/%d\n",mot/__gcd(mot,n),n/__gcd(mot,n));
        }
    }

    return 0;
}
