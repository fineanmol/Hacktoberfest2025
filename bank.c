#include <stdio.h>

int main()
{
    int i = 1, amt, bal = 0;

    if (i < 4 && i > 0)
    {
        do
        {
            printf("1. Deposit \n2. Withdraw \n3. Check Balance \n4. Exit\n");
            printf("Enter Choice: ");

            scanf("%d", &i);

            switch (i)
            {
            case 1:
                printf("Enter Amount to deposit :");
                scanf("%d", &amt);
                printf("Deposit Successful\n");
                bal = bal + amt;
                break;
            case 2:
                printf("Enter Amount to Withdraw :");
                scanf("%d", &amt);
                if (amt <= bal)
                {
                    printf("Withdrawal Successful\n");
                    bal = bal - amt;
                }

                else
                    printf("Please Enter Amount less than balance\n");
                break;
            case 3:
                printf("Balance=%d\n", bal);
                break;
            case 4:
                printf("Exiting...");
                break;
            }
        } while (i <= 4);
    }
    else
        printf("Enter Valid Choice");
}
