#define SET(x, n) (x[n>>6]|=(1<<((n>>1)&31)))
#define CHK(x, n) (x[n>>6]&(1<<((n>>1)&31)))
#define sqr(x) ((x)*(x))
#define MAX 46656
#define RAN 100032
#define LMT 216
#define LEN 4830

/// first call sieve for once,
/// then you can call segment sieve as a function
unsigned base[MAX/64], seg[RAN/64], primes[LEN];

void sieve()
{
	unsigned i, j, k;
	for(i=3;i<LMT;i+=2)
		if(!CHK(base, i))
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				SET(base, j);
	for(i=3,j=0;i<MAX;i+=2)
		if(!CHK(base, i))
			primes[j++]=i;
	return;
}

int seg_sieve(int a, int b)
{
	unsigned i, j, k, cnt=0;
	if(a<=2 && b>=2) cnt++;
	if(b<2) return 0;
	if(b<=2) return 1;
	if(a<3) a=3;
	if(!(a&1)) a++;
	memset(seg, 0, sizeof seg);
	for(i=0;sqr(primes[i])<=b;i++)
	{
		j = primes[i] * ((a+primes[i]-1)/primes[i]);
		if(!(j&1)) j+=primes[i];
		for(k=(primes[i]<<1);j<=b;j+=k)
			if(j!=primes[i])
				SET(seg, (j-a));
	}
	for(i=0;i<=(b-a);i+=2)
	{
		if(!(CHK(seg, i)))
			cnt++;
	}
	return cnt;
}
