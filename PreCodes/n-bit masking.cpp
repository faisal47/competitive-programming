#include "stdio.h"

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

int eight[12];

void init(){
    int i;
    eight[0] = 1;
    REP1(i, 1, 10)
        eight[i] = 8 * eight[i-1];
}

int get_bit(int mask, int pos){
    return (mask / eight[pos]) % 8;
}

int set_bit(int mask, int pos, int bit){
    int tmp =(mask / eight[pos]) % 8;
    mask -= tmp * eight[pos];
    mask += bit * eight[pos];
    return mask;
}

int main(){
    init();

    return 0;
}
