#include <stdio.h>
#include <iostream>
#include  <string>
using namespace std;
int main ()
{
    int n,row,colam,i,j,k,mid;
    string a;
    while(cin>>n>>a)
    {
        if(n==0&&a.size()==1&&a[0]=='0')
            break;
        row=(2*n)+3;
        colam=2+n;
        mid=row/2;
        mid+=1;
        for(i=1; i<=row; i++)
        {
            for(j=0; j<a.size(); j++)
            {
                if(j!=0)
                    cout<<" ";
                if(i==1)
                {
                    if(a[j]=='1'||a[j]=='4')
                    {
                        for(k=0; k<colam; k++)
                            cout<<" ";
                    }
                    else if(a[j]=='2'||a[j]=='3'||a[j]=='5'||a[j]=='6'||a[j]=='7'||a[j]=='8'||a[j]=='9'||a[j]=='0')
                    {
                        cout<<" ";
                        for(k=0; k<n; k++)
                            cout<<"-";
                        cout<<" ";
                    }
                }
                else if(i==mid)
                {
                    if(a[j]=='1'||a[j]=='7'||a[j]=='0')
                    {
                        for(k=0; k<colam; k++)
                            cout<<" ";
                    }
                    else if(a[j]=='2'||a[j]=='3'||a[j]=='4'||a[j]=='5'||a[j]=='6'||a[j]=='8'||a[j]=='9')
                    {
                        cout<<" ";
                        for(k=0; k<n; k++)
                            cout<<"-";
                        cout<<" ";
                    }
                }
                else if(i==row)
                {
                    if(a[j]=='1'||a[j]=='7'||a[j]=='4')
                    {
                        for(k=0; k<colam; k++)
                            cout<<" ";
                    }
                    else if(a[j]=='2'||a[j]=='3'||a[j]=='5'||a[j]=='6'||a[j]=='8'||a[j]=='9'||a[j]=='0')
                    {
                        cout<<" ";
                        for(k=0; k<n; k++)
                            cout<<"-";
                        cout<<" ";
                    }
                }
                else
                {
                    if(a[j]=='1'||a[j]=='3'||a[j]=='7')
                    {
                        cout<<" ";
                        for(k=0; k<n; k++)
                            cout<<" ";
                        cout<<"|";
                    }
                    else if(a[j]=='2')
                    {
                        if(i<mid)
                        {
                            cout<<" ";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<"|";
                        }
                        else
                        {
                            cout<<"|";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<" ";
                        }
                    }
                    else if(a[j]=='4')
                    {
                        if(i<mid)
                        {
                            cout<<"|";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<"|";
                        }
                        else
                        {
                            cout<<" ";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<"|";
                        }
                    }
                    else if(a[j]=='5')
                    {
                        if(i>mid)
                        {
                            cout<<" ";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<"|";
                        }
                        else
                        {
                            cout<<"|";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<" ";
                        }
                    }
                    else if(a[j]=='6')
                    {
                        if(i<mid)
                        {
                            cout<<"|";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<" ";
                        }
                        else
                        {
                            cout<<"|";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<"|";
                        }
                    }
                    else if(a[j]=='8'||a[j]=='0')
                    {
                        cout<<"|";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<"|";
                    }
                    else if(a[j]=='9')
                    {
                        if(i<mid)
                        {
                            cout<<"|";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<"|";
                        }
                        else
                        {
                           cout<<" ";
                            for(k=0; k<n; k++)
                                cout<<" ";
                            cout<<"|";
                        }
                    }
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
