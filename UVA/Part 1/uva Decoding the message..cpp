#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char arr[100000],z,*word;
int main ()
{
    int len,c,test,t;
    scanf("%d",&test);
    scanf("%c",&z);
    gets(arr);
    for(t=0;t<test;t++)
    {
        if(t)
        cout<<endl;
        printf("Case #%d:\n",t+1);
        while(gets(arr))
        {
            len=strlen(arr);
            if(len==0)
            break;
            c=0;
            word=strtok(arr," ");
            while(word!=NULL)
            {
               len=strlen(word);
                //cout<<"len= "<<len<<endl;
                if((len-1)>=c)
                {
                    cout<<word[c];c++;
                }
                word=strtok(NULL," ");
            }
            cout<<endl;
        }
    }
    return 0;
}
