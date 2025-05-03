unsigned rightrot(unsigned x, int n)
{
    int wordsize = sizeof(x) * 8;
    return (x >> n) | (x << (wordsize - n));
}
