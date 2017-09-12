#include <stdio.h>

typedef struct _rat
{
    int numer;
    int denom;
} rat;

rat add_rat(rat x, rat y)
{
    x.numer = x.numer * y.denom + y.numer * x.denom;
    x.denom = x.denom * y.denom;
    return x;
}

void print_rat(rat x)
{
    printf("\n%d/%d", x.numer, x.denom);
}

int main(void)
{
    const rat a = {1, 2};
    print_rat(a);
    const rat b = {1, 3};
    print_rat(b);
    print_rat(add_rat(a, b));
    return 0;
}
