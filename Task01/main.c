#include <stdio.h>

int main(void)
{
    double price, qty, senior;
    double total, net;
    double gross, discount, tax, correct_total, correct_net;
    int count = 0;

    /* Three test cases */
    double prices[] = {100.0, 500.0, 1000.0};
    double quantities[] = {2.0, 3.0, 2.0};
    int seniors[] = {1, 0, 1};

    for (int i = 0; i < 3; i++)
    {
        price = prices[i];
        qty = quantities[i];
        senior = seniors[i];

        /* Original buggy calculation */
        total = price * qty
              - price * qty * 15 / 100 * senior
              + price * qty * 5 / 100;

        net = total > 1000 ? total - 50 : total;

        printf("\nTest Case %d\n", i + 1);
        printf("Price = %.2f, Quantity = %.0f, Senior = %d\n",
               price, qty, seniors[i]);
        printf("Buggy Total = %.2f\n", total);
        printf("Buggy Net = %.2f\n", net);

        /* Correct calculation using intermediate variables */
        gross = price * qty;
        discount = senior ? gross * 0.15 : 0.0;
        tax = (gross - discount) * 0.05;
        correct_total = gross - discount + tax;
        correct_net = correct_total > 1000
                    ? correct_total - 50
                    : correct_total;

        printf("Correct Gross = %.2f\n", gross);
        printf("Correct Discount = %.2f\n", discount);
        printf("Correct Tax = %.2f\n", tax);
        printf("Correct Total = %.2f\n", correct_total);
        printf("Correct Net = %.2f\n", correct_net);
    }

    /* Demonstration of the problematic statement */
    printf("\nCount demonstration:\n");
    count = count++ + 1;  /* Undefined behaviour in C */
    printf("Count = %d\n", count);

    return 0;
}
