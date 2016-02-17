// http://comeoncodeon.wordpress.com/2011/10/09/modular-multiplicative-inverse/

/* Fermats Little Theorem - m is prime and coprime to b*/
// To find (b^(-1))%m for (a/b)%m
// (a/b)%m=( (a%m)*((b^(-1))%m) )%m
int pow(int a, int b, int MOD) {
int x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
 
int modInverse(int b, int m) {
    return pow(b,m-2,m);
}
