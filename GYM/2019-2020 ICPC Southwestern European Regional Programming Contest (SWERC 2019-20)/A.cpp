const LL MOD = 1LL<<40;
const LL S0 = 0x600DCAFE;
LL f(LL prv){
	return (prv + (prv>>20) + 12345) % MOD;
}

int main(){ FAST
	LL tortoise = f(S0);
	LL hare = f(f(S0));
	while(tortoise != hare){
		tortoise = f(tortoise);
		hare = f(f(hare));
	}

	int start = 0;
	tortoise = S0;
	while(tortoise != hare){
		tortoise = f(tortoise);
		hare = f(hare);
		++start;
	}

	cout << start << ln;
