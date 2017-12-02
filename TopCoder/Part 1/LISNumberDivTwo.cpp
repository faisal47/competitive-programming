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


class LISNumberDivTwo {
public:
	int calculate(vector <int> seq) {
	    int i,ans=1;
	    for(i=1;i<seq.size();i++)
	    {
	        if(seq[i]<=seq[i-1])
	        ans++;
	    }
	    return ans;

	}
};
