#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int main ()
{
    priority_queue<int,vector<int>,greater<int> >q;
  long long int n,m,sum,motsum;
    while(cin>>n)
    {
        if(n==0)
        break;
        motsum=0;
        while(n--)
        {
            cin>>m;
            q.push(m);
        }

        while(q.size()!=1)
        {
            sum=0;
            sum+=q.top();q.pop();
            sum+=q.top();q.pop();
            q.push(sum);
            motsum+=sum;
        }
        q.pop();
        cout<<motsum<<endl;
    }
    return 0;
}
