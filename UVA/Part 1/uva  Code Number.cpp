#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main ()
{
    char arr[100],z;
    int test,t,i,len;
    scanf("%d",&test);
    scanf("%c",&z);
    for(t=0;t<test-1;t++)
    {
        while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
            break;
            for(i=0;i<len;i++)
            {
                if(arr[i]=='0')
                cout<<"O";
                else if(arr[i]=='O')
                cout<<"0";
                else if(arr[i]=='1')
                cout<<"I";
                else if(arr[i]=='I')
                cout<<"1";
                else if(arr[i]=='2')
                cout<<"Z";
                else if(arr[i]=='Z')
                cout<<"2";
                else if(arr[i]=='3')
                cout<<"E";
                else if(arr[i]=='E')
                cout<<"3";
                else if(arr[i]=='4')
                cout<<"A";
                else if(arr[i]=='A')
                cout<<"4";
                else if(arr[i]=='5')
                cout<<"S";
                else if(arr[i]=='S')
                cout<<"5";
                else if(arr[i]=='6')
                cout<<"G";
                else if(arr[i]=='G')
                cout<<"6";
                else if(arr[i]=='7')
                cout<<"T";
                else if(arr[i]=='T')
                cout<<"7";
                else if(arr[i]=='8')
                cout<<"B";
                else if(arr[i]=='B')
                cout<<"8";
                else if(arr[i]=='9')
                cout<<"P";
                else if(arr[i]=='P')
                cout<<"9";
                else
                cout<<arr[i];
            }
            cout<<endl;
        }
        cout<<endl;
    }
        while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
            break;
            for(i=0;i<len;i++)
            {
                if(arr[i]=='0')
                cout<<"O";
                else if(arr[i]=='O')
                cout<<"0";
                else if(arr[i]=='1')
                cout<<"I";
                else if(arr[i]=='I')
                cout<<"1";
                else if(arr[i]=='2')
                cout<<"Z";
                else if(arr[i]=='Z')
                cout<<"2";
                else if(arr[i]=='3')
                cout<<"E";
                else if(arr[i]=='E')
                cout<<"3";
                else if(arr[i]=='4')
                cout<<"A";
                else if(arr[i]=='A')
                cout<<"4";
                else if(arr[i]=='5')
                cout<<"S";
                else if(arr[i]=='S')
                cout<<"5";
                else if(arr[i]=='6')
                cout<<"G";
                else if(arr[i]=='G')
                cout<<"6";
                else if(arr[i]=='7')
                cout<<"T";
                else if(arr[i]=='T')
                cout<<"7";
                else if(arr[i]=='8')
                cout<<"B";
                else if(arr[i]=='B')
                cout<<"8";
                else if(arr[i]=='9')
                cout<<"P";
                else if(arr[i]=='P')
                cout<<"9";
                else
                cout<<arr[i];
            }
            cout<<endl;
        }
    return 0;
}
