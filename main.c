#include <stdio.h>

int main() {

    int id[10], qty[10];
    float price[10];
    char name[10][20];

    int n, choice, i, searchID;
    float totalValue, highest, lowest;
    int posHigh, posLow;

    printf("Enter number of items (max 10): ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Limit is 10 items.\n");
        return 0;
    }

    i = 0;
    while (i < n) {
        printf("\nItem %d ID: ", i + 1);
        scanf("%d", &id[i]);

        printf("Item %d Name: ", i + 1);
        scanf("%s", name[i]);

        printf("Stock: ");
        scanf("%d", &qty[i]);

        printf("Unit Price: ");
        scanf("%f", &price[i]);

        i++;
    }

    while (1) {

        printf("\n===== MENU =====\n");
        printf("1. Display Items\n");
        printf("2. Stock Analysis\n");
        printf("3. Search Item by ID\n");
        printf("4. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n--- Item List ---\n");
            for (i = 0; i < n; i++) {
                printf("ID: %d | Name: %s | Qty: %d | Price: %.2f\n",
                       id[i], name[i], qty[i], price[i]);
            }
        }

        else if (choice == 2) {
            totalValue = 0;
            highest = qty[0] * price[0];
            lowest = qty[0] * price[0];
            posHigh = 0;
            posLow = 0;

            for (i = 0; i < n; i++) {
                float value = qty[i] * price[i];
                totalValue += value;

                if (value > highest) {
                    highest = value;
                    posHigh = i;
                }
                if (value < lowest) {
                    lowest = value;
                    posLow = i;
                }
            }

            printf("\nTotal Stock Value: %.2f\n", totalValue);
            printf("Highest Value Item: %s (%.2f)\n", name[posHigh], highest);
            printf("Lowest Value Item: %s (%.2f)\n", name[posLow], lowest);
        }

        else if (choice == 3) {
            printf("Enter Item ID to search: ");
            scanf("%d", &searchID);

            int found = 0;
            for (i = 0; i < n; i++) {
                if (id[i] == searchID) {
                    found = 1;
                    printf("\nItem Found:\n");
                    printf("ID: %d\nName: %s\nStock: %d\nPrice: %.2f\n",
                           id[i], name[i], qty[i], price[i]);
                    break;
                }
            }

            if (!found) {
                printf("Item not found.\n");
            }
        }

        else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }

        else {
            printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}