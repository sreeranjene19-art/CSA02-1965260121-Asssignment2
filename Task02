
#include <stdio.h>

int calls = 0;
int audit_entries = 0;

/* Slow server verification function */
int slow_verify(int disability_card)
{
    calls++;
    audit_entries++;

    /* Simulates verification against the server */
    return disability_card;
}

int main(void)
{
    int senior, eligible, disability_card;
    int result;
    int i;

    /* Experiment 1: Short-circuit evaluation */
    calls = 0;

    result = 0 && slow_verify(1);
    printf("0 && slow_verify(1) = %d\n", result);
    printf("Function calls = %d\n", calls);

    calls = 0;

    result = 1 || slow_verify(1);
    printf("\n1 || slow_verify(1) = %d\n", result);
    printf("Function calls = %d\n", calls);

    /* Experiment 2: Difference between & and && */
    calls = 0;

    result = 0 && slow_verify(1);
    printf("\n0 && slow_verify(1) = %d\n", result);
    printf("Function calls = %d\n", calls);

    calls = 0;

    result = 0 & slow_verify(1);
    printf("\n0 & slow_verify(1) = %d\n", result);
    printf("Function calls = %d\n", calls);

    /* Experiment 3: 1000 passengers */
    calls = 0;
    audit_entries = 0;

    for (i = 0; i < 1000; i++)
    {
        senior = (i % 4 == 0);
        eligible = 1;
        disability_card = (i % 10 == 0);

        /* Cheap condition first */
        result = (senior && eligible)
                 || slow_verify(disability_card);
    }

    printf("\nExperiment 3: Cheap condition first\n");
    printf("Total passengers = 1000\n");
    printf("Slow verification calls = %d\n", calls);
    printf("Audit entries = %d\n", audit_entries);

    /* Experiment 4: Slow condition first */
    calls = 0;
    audit_entries = 0;

    for (i = 0; i < 1000; i++)
    {
        senior = (i % 4 == 0);
        eligible = 1;
        disability_card = (i % 10 == 0);

        result = slow_verify(disability_card)
                 || (senior && eligible);
    }

    printf("\nExperiment 4: Slow condition first\n");
    printf("Total passengers = 1000\n");
    printf("Slow verification calls = %d\n", calls);
    printf("Audit entries = %d\n", audit_entries);

    return 0;
}
