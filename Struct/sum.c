typedef int(* int32_f)();

int sum(int32_f term, int a, int32_f next, int b)
{
    if(a > b)
        return 0;
    else
        return term(a) + sum(tern, next(a), next, b);
}

int cube(int x)
{
    return x * x * x;
}

int inc(int n)
{
    return n + 1;
}

int sum_cube(int a, int b)
{
    return sum(cube, a, inc, b);
}
