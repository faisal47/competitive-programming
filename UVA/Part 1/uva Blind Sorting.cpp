#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
   unsigned int n;
   while (cin >> n)
   {
      --n;
      cout << n+(unsigned int)log2(n) << endl;
   }
   return 0;
}
