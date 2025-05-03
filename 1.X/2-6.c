unsigned setbits(unsigned x,int p,int n, unsigned y)
{
    unsigned mask = ~(~0 << n);
    return (x & ~(mask << (p+1-n))) | ((y & mask) << (p+1-n));
}