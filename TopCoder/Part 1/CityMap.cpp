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


class CityMap
{
public:
    string getLegend(vector <string> cityMap, vector <int> POIs)
    {
        int i,j,arr[300];
        string ans;
        memset(arr,0,sizeof(arr));
        for(i=0; i<cityMap.size(); i++)
        for(j=0;j<cityMap[i].size();j++)
            arr[cityMap[i][j]]++;
        for(i=0; i<POIs.size(); i++)
            for(j=0; j<300; j++)
            {
                if(arr[j]==POIs[i] && (char)j!='.')
                {
                    ans+=(char)j;
                    break;
                }
            }
        return ans;
    }
};
