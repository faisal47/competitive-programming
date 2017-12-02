#include <bits/stdc++.h>
using namespace std;

#define MAX 110

string arr[MAX];
bool arr2[MAX][MAX];

int main ()
{
    int test,n,m;
    cin>>test;
    while(test--){
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    arr2[i][j]= arr[i][j]=='G' ? true:false;
        
        int ans1,ans2;
        ans1=ans2=0;
        for(int i=0;i<n;i++){
            bool col=i&1;
            for(int j=0;j<m;j++){
                if(arr2[i][j]!=col)
                        ans1+= arr2[i][j] ? 3 : 5;
                col^=1;
            }
        }
        
        for(int i=0;i<n;i++){
            bool col=!(i&1);
            for(int j=0;j<m;j++){     
                if(arr2[i][j]!=col)
                    ans2+= arr2[i][j] ? 3 : 5;
                
                col^=1;
            }
        }
        
        cout<<min(ans1,ans2)<<endl;
    }
    
    return 0;
}

