unsigned invert (unsigned x, int p, int n)
{
    unsigned mask = ~(~0 << n);
    return (x ^ (mask << (p+1-n)));
}