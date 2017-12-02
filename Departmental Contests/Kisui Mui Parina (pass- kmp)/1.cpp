#include<iostream>
#include<cmath>
using namespace std;
int main()
{
long long n,x,y,z,ans;
    cin>>n;
    while(n--)
    {

        cin>>x;
        for(int i=10; i>=0; i--)
        {
            y=1;
            for(int j=0;j<i;j++)y*=10;
            if(x/y>=1)
            {
                z=x%y;
                ans=x-z;
                if(z>4) ans+=y;
                break;
            }
        }
        cout<<">> "<<ans<<endl;
    }
}
