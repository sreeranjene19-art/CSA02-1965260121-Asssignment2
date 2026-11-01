
#include <stdio.h>
#include <math.h>

#define MAX_MONTHS 360

double to_cents(double amount)
{
    return round(amount * 100.0) / 100.0;
}

/* Returns 1 if repaid, 0 if not repaid within the limit */
int loan_schedule(double principal, double rate,
                  double payment, int print_schedule,
                  int *months, double *total_interest)
{
    double balance = to_cents(principal);
    *months = 0;
    *total_interest = 0.0;

    if (principal <= 0 || rate < 0 || payment <= 0)
        return 0;

    if (print_schedule)
        printf("\nMonth   Interest   Payment   Balance\n");

    while (balance > 0.0)
    {
        if (*months >= MAX_MONTHS)
        {
            if (print_schedule)
                printf("Safety limit reached: loan not fully repaid.\n");
            return 0;
        }

        double interest = to_cents(balance * rate);
        double amount_due = to_cents(balance + interest);

        /* Payment must exceed interest to reduce the balance */
        if (payment <= interest)
        {
            if (print_schedule)
                printf("Repayment is insufficient to reduce the loan.\n");
            return 0;
        }

        double actual_payment = payment;

        /* Do not collect more than the amount owed */
        if (actual_payment > amount_due)
            actual_payment = amount_due;

        balance = to_cents(amount_due - actual_payment);
        *total_interest = to_cents(*total_interest + interest);
        (*months)++;

        if (print_schedule)
        {
            printf("%5d   %8.2f   %7.2f   %8.2f\n",
                   *months, interest, actual_payment, balance);
        }
    }

    if (print_schedule)
    {
        printf("Months taken: %d\n", *months);
        printf("Total interest: Rs %.2f\n", *total_interest);
    }

    return 1;
}

int main(void)
{
    int months;
    double total_interest;

    printf("LOAN REPAYMENT SCHEDULE\n");

    loan_schedule(10000.0, 0.02, 2000.0,
                  1, &months, &total_interest);

    printf("\nGROWTH INVESTIGATION\n");
    printf("Payment    Months   Result\n");

    double payments[] = {500, 300, 250, 201, 200, 199};
    int count = sizeof(payments) / sizeof(payments[0]);

    for (int i = 0; i < count; i++)
    {
        int repaid = loan_schedule(10000.0, 0.02,
                                   payments[i], 0,
                                   &months, &total_interest);

        if (repaid)
            printf("%7.2f    %3d      Repaid\n",
                   payments[i], months);
        else
            printf("%7.2f    %3d      Not repaid\n",
                   payments[i], months);
    }

    return 0;
}
