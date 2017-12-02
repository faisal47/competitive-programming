#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string a[105];
    a[1]="i";
    a[2]="ii";
    a[3]="iii";
    a[4]="iv";
    a[5]="v";
    a[6]="vi";
    a[7]="vii";
    a[8]="viii";
    a[9]="ix";
    a[10]="x";
    a[11]="xi";
    a[12]="xii";
    a[13]="xiii";
    a[14]="xiv";
    a[15]="xv";
    a[16]="xvi";
    a[17]="xvii";
    a[18]="xviii";
    a[19]="xix";
    a[20]="xx";
    a[21]="xxi";
    a[22]="xxii";
    a[23]="xxiii";
    a[24]="xxiv";
    a[25]="xxv";
    a[26]="xxvi";
    a[27]="xxvii";
    a[28]="xxviii";
    a[29]="xxix";
    a[30]="xxx";
    a[31]="xxxi";
    a[32]="xxxii";
    a[33]="xxxiii";
    a[34]="xxxiv";
    a[35]="xxxv";
    a[36]="xxxvi";
    a[37]="xxxvii";
    a[38]="xxxviii";
    a[39]="xxxix";
    a[40]="xl";
    a[41]="xli";
    a[42]="xlii";
    a[43]="xliii";
    a[44]="xliv";
    a[45]="xlv";
    a[46]="xlvi";
    a[47]="xlvii";
    a[48]="xlviii";
    a[49]="xlix";
    a[50]="l";
    a[51]="li";
    a[52]="lii";
    a[53]="liii";
    a[54]="liv";
    a[55]="lv";
    a[56]="lvi";
    a[57]="lvii";
    a[58]="lviii";
    a[59]="lix";
    a[60]="lx";
    a[61]="lxi";
    a[62]="lxii";
    a[63]="lxiii";
    a[64]="lxiv";
    a[65]="lxv";
    a[66]="lxvi";
    a[67]="lxvii";
    a[68]="lxviii";
    a[69]="lxix";
    a[70]="lxx";
    a[71]="lxxi";
    a[72]="lxxii";
    a[73]="lxxiii";
    a[74]="lxxiv";
    a[75]="lxxv";
    a[76]="lxxvi";
    a[77]="lxxvii";
    a[78]="lxxviii";
    a[79]="lxxix";
    a[80]="lxxx";
    a[81]="lxxxi";
    a[82]="lxxxii";
    a[83]="lxxxiii";
    a[84]="lxxxiv";
    a[85]="lxxxv";
    a[86]="lxxxvi";
    a[87]="lxxxvii";
    a[88]="lxxxviii";
    a[89]="lxxxix";
    a[90]="xc";
    a[91]="xci";
    a[92]="xcii";
    a[93]="xciii";
    a[94]="xciv";
    a[95]="xcv";
    a[96]="xcvi";
    a[97]="xcvii";
    a[98]="xcviii";
    a[99]="xcix";
    a[100]="c";
    int i,n,arr[10],j;
    while(cin>>n)
    {
        if(n==0)
        break;
        for(i=1;i<=5;i++)
        arr[i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<a[i].size();j++)
            {
                if (a[i][j]=='i')
                arr[1]++;
                else if (a[i][j]=='v')
                arr[2]++;
                else if (a[i][j]=='x')
                arr[3]++;
                else if (a[i][j]=='l')
                arr[4]++;
                else if (a[i][j]=='c')
                arr[5]++;
            }
        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,arr[1],arr[2],arr[3],arr[4],arr[5]);
    }
    return 0;

}
