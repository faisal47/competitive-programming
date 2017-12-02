#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
    int len,i;
    char arr[1500];
    while(gets(arr))
    {
        len=strlen(arr);
        for(i=0;i<len;i++)
        {
            if(arr[i]=='4')
            cout<<'q';
            else if(arr[i]=='5')
            cout<<'j';
            else if(arr[i]=='6')
            cout<<'l';
            else if(arr[i]=='7')
            cout<<'m';
            else if(arr[i]=='8')
            cout<<'f';
            else if(arr[i]=='9')
            cout<<'p';
            else if(arr[i]=='0')
            cout<<'/';
            else if(arr[i]=='-')
            cout<<'[';
            else if(arr[i]=='=')
            cout<<']';
            else if(arr[i]=='q')
            cout<<'4';
            else if(arr[i]=='w')
            cout<<'5';
            else if(arr[i]=='e')
            cout<<'6';
            else if(arr[i]=='r')
            cout<<'.';
            else if(arr[i]=='t')
            cout<<'o';
            else if(arr[i]=='y')
            cout<<'r';
            else if(arr[i]=='u')
            cout<<'s';
            else if(arr[i]=='i')
            cout<<'u';
            else if(arr[i]=='o')
            cout<<'y';
            else if(arr[i]=='p')
            cout<<'b';
            else if(arr[i]=='[')
            cout<<';';
            else if(arr[i]==']')
            cout<<'=';
            else if(arr[i]=='a')
            cout<<'7';
            else if(arr[i]=='s')
            cout<<'8';
            else if(arr[i]=='d')
            cout<<'9';
            else if(arr[i]=='f')
            cout<<'a';
            else if(arr[i]=='g')
            cout<<'e';
            else if(arr[i]=='j')
            cout<<'t';
            else if(arr[i]=='k')
            cout<<'d';
            else if(arr[i]=='l')
            cout<<'c';
            else if(arr[i]==';')
            cout<<'k';
            else if(arr[i]==39)
            cout<<'-';
            else if(arr[i]=='z')
            cout<<'0';
            else if(arr[i]=='x')
            cout<<'z';
            else if(arr[i]=='c')
            cout<<'x';
            else if(arr[i]=='v')
            cout<<',';
            else if(arr[i]=='b')
            cout<<'i';
            else if(arr[i]=='m')
            cout<<'w';
            else if(arr[i]==',')
            cout<<'v';
            else if(arr[i]=='.')
            cout<<'g';
            else if(arr[i]=='/')
            cout<<(char)39;
            else if(arr[i]=='$')
            cout<<'Q';
            else if(arr[i]=='%')
            cout<<'J';
            else if(arr[i]=='^')
            cout<<'L';
            else if(arr[i]=='&')
            cout<<'M';
            else if(arr[i]=='*')
            cout<<'F';
            else if(arr[i]=='(')
            cout<<'P';
            else if(arr[i]==')')
            cout<<'?';
            else if(arr[i]=='_')
            cout<<'{';
            else if(arr[i]=='+')
            cout<<'}';
            else if(arr[i]=='Q')
            cout<<'$';
            else if(arr[i]=='W')
            cout<<'%';
            else if(arr[i]=='E')
            cout<<'^';
            else if(arr[i]=='R')
            cout<<'>';
            else if(arr[i]=='T')
            cout<<'O';
            else if(arr[i]=='Y')
            cout<<'R';
            else if(arr[i]=='U')
            cout<<'S';
            else if(arr[i]=='I')
            cout<<'U';
            else if(arr[i]=='O')
            cout<<'Y';
            else if(arr[i]=='P')
            cout<<'B';
            else if(arr[i]=='{')
            cout<<':';
            else if(arr[i]=='}')
            cout<<'+';
            else if(arr[i]=='A')
            cout<<'&';
            else if(arr[i]=='S')
            cout<<'*';
            else if(arr[i]=='D')
            cout<<'(';
            else if(arr[i]=='F')
            cout<<'A';
            else if(arr[i]=='G')
            cout<<'E';
            else if(arr[i]=='J')
            cout<<'T';
            else if(arr[i]=='K')
            cout<<'D';
            else if(arr[i]=='L')
            cout<<'C';
            else if(arr[i]==':')
            cout<<'K';
            else if(arr[i]=='"')
            cout<<'_';
            else if(arr[i]=='Z')
            cout<<')';
            else if(arr[i]=='X')
            cout<<'Z';
            else if(arr[i]=='C')
            cout<<'X';
            else if(arr[i]=='V')
            cout<<'<';
            else if(arr[i]=='B')
            cout<<'|';
            else if(arr[i]=='M')
            cout<<'W';
            else if(arr[i]=='<')
            cout<<'V';
            else if(arr[i]=='>')
            cout<<'G';
            else if(arr[i]=='?')
            cout<<'"';
            else
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
