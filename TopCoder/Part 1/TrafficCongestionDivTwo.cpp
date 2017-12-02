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

using namespace std;


class TrafficCongestionDivTwo {
public:
	long long theMinCars(int treeHeight) {

		unsigned long long i,j,ans=2,ans1;
		vector<long long int>v;
		v.push_back(1);
		v.push_back(1);
		if(treeHeight==0 || treeHeight==1)
	    {
	        ans=1;
	        return ans;
	    }
		for(i=2;i<=treeHeight;i++)
		{
		    ans1=0;
		    for(j=0;j<v.size();j++)
		    ans1+=v[j];
		    if(!(i&1))
		    ans1++;
		    v.push_back(ans1);
		    //ans+=ans1;
		}
		ans=v[v.size()-1];
		return ans;
	}
};
