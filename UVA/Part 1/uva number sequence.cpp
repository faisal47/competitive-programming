#include <iostream>
#include <stdio.h>
using namespace std;
int arr[70000],arr1[150000003],arr2[150000003],arr3[150000003],arr4[100000003],arr5[150000003],arr6[150000003],arr7[150000003],arr8[150000003],arr9[150000003],arr10[150000003],arr11[150000003];
int main ()
{
   unsigned long long n,c=0,a=10,i=1,d=1,test;
    for(i=1;i<10;i++)
    arr[c++]=i;
    while(1)
    {
        i=a;
        if(i>=10&&i<100)
        {
            arr[c+1]=i%10;
            arr[c]=i/10;
            c+=2;
        }
        else if(i>=100&&i<1000)
        {
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=3;
        }
        else if(i>=1000&&i<10000)
        {
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=4;
        }
        else if(i>=10000&&i<100000)
        {
            arr[c+4]=i%10;i/=10;
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=5;
        }
        else if(i>=100000&&i<1000000)
        {
            arr[c+5]=i%10;i/=10;
            arr[c+4]=i%10;i/=10;
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=6;
        }
        else if(i>=1000000&&i<10000000)
        {
            arr[c+6]=i%10;i/=10;
            arr[c+5]=i%10;i/=10;
            arr[c+4]=i%10;i/=10;
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=7;
        }
        else if(i>=10000000&&i<100000000)
        {
            arr[c+7]=i%10;i/=10;
            arr[c+6]=i%10;i/=10;
            arr[c+5]=i%10;i/=10;
            arr[c+4]=i%10;i/=10;
            arr[c+3]=i%10;i/=10;
            arr[c+2]=i%10;i/=10;
            arr[c+1]=i%10;i/=10;
            arr[c]=i%10;
            c+=8;
        }
        ++a;
        if(c>=69000)
        break;
    }
    a=1;c=0;
    while(1)
    {
        i=a;
        if(i>0&&i<=200000000)
        {
            arr1[i]=arr[c++];
        }
        else if(i>200000000&&i<=400000000)
        {
            i-=200000000;
            arr2[i]=arr[c++];
        }
        else if(i>400000000&&i<=600000000)
        {
            i-=400000000;
            arr3[i]=arr[c++];
        }
        else if(i>600000000&&i<=800000000)
        {
            i-=600000000;
            arr4[i]=arr[c++];
        }
        else if(i>800000000&&i<=1000000000)
        {
            i-=800000000;
            arr5[i]=arr[c++];
        }
        else if(i>1000000000&&i<=1200000000)
        {
            i-=1000000000;
            arr6[i]=arr[c++];
        }
        else if(i>1200000000&&i<=1400000000)
        {
            i-=1200000000;
            arr7[i]=arr[c++];
        }
        else if(i>1400000000&&i<=1600000000)
        {
            i-=1400000000;
            arr8[i]=arr[c++];
        }
        else if(i>1600000000&&i<=1800000000)
        {
            i-=1600000000;
            arr9[i]=arr[c++];
        }
        else if(i>1800000000&&i<=2000000000)
        {
            i-=1800000000;
            arr10[i]=arr[c++];
        }
        else if(i>2000000000&&i<=2200000000)
        {
            i-=2000000000;
            arr11[i]=arr[c++];
        }
        if(a>=2147483647)
        break;
        if(c==d)
        {
            ++d;
            c=0;
        }
        ++a;
    }
    cin>>test;
    while(test--)
    {
        cin>>a;
        i=a;
        if(i>0&&i<=200000000)
        {
           cout<<arr1[i]<<endl;
        }
        else if(i>200000000&&i<=400000000)
        {
            i-=200000000;
           cout<<arr2[i]<<endl;
        }
        else if(i>400000000&&i<=600000000)
        {
            i-=400000000;
            cout<<arr3[i]<<endl;
        }
        else if(i>600000000&&i<=800000000)
        {
            i-=600000000;
            cout<<arr4[i]<<endl;
        }
        else if(i>800000000&&i<=1000000000)
        {
            i-=800000000;
            cout<<arr5[i]<<endl;
        }
        else if(i>1000000000&&i<=1200000000)
        {
            i-=1000000000;
            cout<<arr6[i]<<endl;
        }
        else if(i>1200000000&&i<=1400000000)
        {
            i-=1200000000;
            cout<<arr7[i]<<endl;
        }
        else if(i>1400000000&&i<=1600000000)
        {
            i-=1400000000;
            cout<<arr8[i]<<endl;
        }
        else if(i>1600000000&&i<=1800000000)
        {
            i-=1600000000;
            cout<<arr9[i]<<endl;
        }
        else if(i>1800000000&&i<=2000000000)
        {
            i-=1800000000;
            cout<<arr10[i]<<endl;
        }
        else if(i>2000000000&&i<=2200000000)
        {
            i-=2000000000;
            cout<<arr11[i]<<endl;
        }
    }
    return 0;
}

