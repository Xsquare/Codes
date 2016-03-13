// calculates if the number is prime or not i.e if ( miller(n,2) ) is true or not
lli mulmod(lli a, lli b, lli c)
{
	lli x = 0, y = a%c;
	while(b>0)
	{
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b = b>>1;
	}
	return x;
}

lli modulo(lli a, lli b, lli c)
{
	lli x = 1, y = a%c;
	while(b>0)
	{
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b = b>>1;
	}
	return x;
}

bool miller(lli p, int iter)
{
    	if(p<2) return false;
    	if(p==2) return true;
    	if(!(p&1)) return false;
    	lli s = p-1, a, temp, mod;
        while(!(s&1)) s = s>>1;
    	for(int i=0; i<iter; i++)
    	{
      		a = rand()%(p-1)+1;
      		temp = s;
      		mod = modulo(a, temp, p);
    		  while(temp!=p-1 && mod!=1 && mod!=p-1)
    		  {
    			  mod = mulmod(mod, mod, p);
    			  temp = temp<<1;
   		   }
           if(mod!=p-1 && !(temp&1)) return false;
    	}
    	return true;
}
