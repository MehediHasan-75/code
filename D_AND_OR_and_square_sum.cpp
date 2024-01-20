#include <stdio.h>
int main()
{
    int T, i;
    long long int a, b, sum;
    double avg;
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        scanf("%lld %lld", &a, &b);
        sum = a + b;
        if (sum % 2 == 0)
            avg = sum / 2;
        else if (sum % 2 != 0)
            avg = (sum / 2) + 0.5;
        printf("%.1lf\n", avg);
    }
    return 0;
}