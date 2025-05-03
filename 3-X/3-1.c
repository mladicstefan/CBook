
int binsearch(int x, int v[], int n)
{
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x == v[mid])
            return mid;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main(void){
    int x = 2;
    int v[] = {1,2,3,4,5,6,7,8,};
    int n = 8;
    binsearch(x,v,n);
}

