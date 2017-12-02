#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;


class TheSwapsDivTwo
{
public:
    int find(vector <int> sequence)
    {
        int i,j,c=0,k=0;
        map<int,int>m;
        for(i=0; i<sequence.size(); i++)
            for(j=i+1; j<sequence.size(); j++)
            {
                if(sequence[i]!=sequence[j])
                    c++;
                else if(!k)
                {
                    k=1;
                    c++;
//                    m[sequence[i]]=1;
                }
            }
        return c;
    }
};
