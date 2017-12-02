bool sieve[mt];
ll prime[664579];
int p;
void SOE()
{
	int i, j, k=0, r;
	prime[k++] = 2LL;
	for(i=3; i<=mt-1; i+=2)
	{
		if(sieve[i]==false)
		{
			prime[k++] = (ll)(i);
			if(i<(mt-1)/i)
			{
				r = (i<<1);
				for(j=(i*i); j<(mt-1); j+=r)
				{
					sieve[j] = true;
				}
			}
		}
	}
	p = k;
	return ;
}

