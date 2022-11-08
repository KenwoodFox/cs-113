/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <stdio.h>
#include <stdint.h>

class BankAccount
{
public:
    double amount = 1000.0;

    void withdraw(double req)
    {
        if (req <= amount)
        {
            amount -= req;
        }
        else
        {
            printf("Err: amount to withdraw overbalance.\n");
        }
        printf("Balance remaining: %0.2lf\n", amount);
    }

    void deposit(double req)
    {
        amount += req;
        printf("Balance after deposit: %0.2lf\n", amount);
    }
};

int selectFrom(BankAccount &acc1, BankAccount &acc2)
{
    int sel = 0;
    printf("Please make a selection,\n\t[0] Checking (%0.2lf)\n\t[1] Savings (%0.2lf)\n", acc1.amount, acc2.amount);
    scanf("%d", &sel);
    return sel == 1 || sel == 0 ? sel : 0;
}

enum Selection
{
    withdrawl,
    deposit,
    transfer,
    display,
    exit
};

int main()
{
    static BankAccount checking;
    static BankAccount savings;

    int sel, _sel;
    double amt = 0;

    do
    {
        printf("\nPlease make a selection,\n\t[%d] Withdrawl\n\t[%d] Deposit\n\t[%d] Transfer\n\t[%d] Display\n\t[%d] Exit\n", withdrawl, deposit, transfer, display, exit);
        scanf("%d", &sel);

        switch (sel)
        {
        case withdrawl:
            printf("Please enter an amount to withdraw: ");
            scanf("%lf", &amt);
            selectFrom(checking, savings) == 0 ? checking.withdraw(amt) : savings.withdraw(amt);
            break;

        case deposit:
            printf("Please enter an amount to deposit: ");
            scanf("%lf", &amt);
            selectFrom(checking, savings) == 0 ? checking.deposit(amt) : savings.deposit(amt);
            break;

        case transfer:
            printf("Please enter an amount to transfer: ");
            scanf("%lf", &amt);
            _sel = selectFrom(checking, savings);
            if (_sel)
            {
                checking.withdraw(amt);
                savings.deposit(amt);
            }
            else
            {
                checking.deposit(amt);
                savings.withdraw(amt);
            }
            printf("Checking:\t%0.2lf\nSavings:\t%0.2lf.\n", checking.amount, savings.amount);

        case display:
            printf("Balance remaining:\n\tChecking:\t%0.2lf\n\tSavings:\t%0.2lf\n", checking.amount, savings.amount);

        case exit:
            break;

        default:
            printf("Err: Unknown selection.\n");
            break;
        }
    } while (sel != exit);

    printf(MOTD); // Print build info
    return 0;
}
