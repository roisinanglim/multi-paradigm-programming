#include <stdlib.h>
#include <stdio.h>
#define Bin_Bags 5.99
#define Milk 3.99
#define Tea_Bags 4.99
#define Spagetii 5.99
 
int main()
{
 
    int choice = 0;
    double totalPrice = 0;

    printf("May I take your order? \n\n");
 
    do {
        printf("Products: \n\n");
        printf("1. Bin_Bags      $%.2lf \n", Bin_Bags);
        printf("2. Milk        $%.2lf \n", Milk);
        printf("3. Tea_Bags    $%.2lf \n", Tea_Bags);
        printf("4. Spagetii $%.2lf \n", Spagetii);
        printf("5. Exit\n\n");
        printf("Enter an item: ");
        scanf("%i", &choice); 
        }
        return 0;
}
