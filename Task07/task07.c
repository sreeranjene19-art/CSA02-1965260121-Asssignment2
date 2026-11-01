
#include <stdio.h>

unsigned long long original_checks = 0;
unsigned long long redesigned_checks = 0;

/* Original Algorithm */
int original_is_prime(unsigned long long n)
{
    original_checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long long i = 2; i < n; i++) {
        original_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* Redesigned Algorithm */
int redesigned_is_prime(unsigned long long n)
{
    redesigned_checks = 0;

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    redesigned_checks++;
    if (n % 2 == 0)
        return 0;

    for (unsigned long long i = 3; i <= n / i; i += 2) {
        redesigned_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    unsigned long long numbers[] = {97, 100, 7919, 1000003};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Q7: PRIME NUMBER ALGORITHM COMPARISON\n");
    printf("---------------------------------------------------------------\n");
    printf("Number\tOriginal\tRedesigned\tOld Checks\tNew Checks\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        unsigned long long n = numbers[i];

        int old_result = original_is_prime(n);
        unsigned long long old_count = original_checks;

        int new_result = redesigned_is_prime(n);
        unsigned long long new_count = redesigned_checks;

        double reduction = 0.0;

        if (old_count > 0) {
            reduction = ((double)(old_count - new_count)
                         / old_count) * 100.0;
        }

        printf("%llu\t%s\t\t%s\t\t%llu\t\t%llu\n",
               n,
               old_result ? "Prime" : "Composite",
               new_result ? "Prime" : "Composite",
               old_count,
               new_count);

        printf("Operation reduction: %.2f%%\n\n", reduction);

        if (old_result == new_result)
            printf("Validation: PASS\n\n");
        else
            printf("Validation: FAIL\n\n");
    }

    printf("CONCLUSION\n");
    printf("The redesigned algorithm checks only odd divisors\n");
    printf("up to the square root of the number.\n");
    printf("It reduces unnecessary divisibility checks while\n");
    printf("preserving the prime/composite result.\n");

    return 0;
}
