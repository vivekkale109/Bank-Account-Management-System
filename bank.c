#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    struct Account a;
    FILE *fp = fopen("bank.txt", "a");

    printf("Enter Account Number: ");
    scanf("%d", &a.accNo);

    printf("Enter Name: ");
    scanf("%s", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

void deposit() {
    struct Account a;
    int accNo, found = 0;
    float amount;

    FILE *fp = fopen("bank.txt", "r+");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&a, sizeof(a), 1, fp)) {
        if (a.accNo == accNo) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);

            a.balance += amount;

            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);

            printf("Deposit Successful! Updated Balance: %.2f\n", a.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account Not Found!\n");

    fclose(fp);
}

void withdraw() {
    struct Account a;
    int accNo, found = 0;
    float amount;

    FILE *fp = fopen("bank.txt", "r+");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&a, sizeof(a), 1, fp)) {
        if (a.accNo == accNo) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (amount > a.balance) {
                printf("Insufficient Balance!\n");
            } else {
                a.balance -= amount;

                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);

                printf("Withdrawal Successful! Updated Balance: %.2f\n", a.balance);
            }

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account Not Found!\n");

    fclose(fp);
}

void checkBalance() {
    struct Account a;
    int accNo, found = 0;

    FILE *fp = fopen("bank.txt", "r");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&a, sizeof(a), 1, fp)) {
        if (a.accNo == accNo) {
            printf("Account Holder: %s\n", a.name);
            printf("Current Balance: %.2f\n", a.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account Not Found!\n");

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: printf("Thank You!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}