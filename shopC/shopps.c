// This package defines three variable types ,macros and several functions for performing inputs & outputs
#include <stdio.h>

// This defines one variable size_t,one macro and various functions for manipulating arrays
#include <string.h>

// This defines four variable types, several macros, and various functions for performing general functions 
#include <stdlib.h>


// A product structure is created with product name and price
struct Product {

    // Char* returns the memory adress of the variable containing letters
    char* name;
    // double assigns the datatype of a variable with two decimal places
    double price; 
};


// Productstock is an entity containing variables associacted with the product and availability of that product
struct Productstock {

    // Product contains deatils about the product name & price
    struct Product product;
    // Quantity contains the details of the volume of each available product
    int quantity;
};

// Shop is an entity cotaining variables realted to the shops cash available and the productstock available
struct Shop {

    // Cash is assigned as a datatype with two decimal places
    double cash;

    // Procductstock cotains stock array of 20 items maximum
    struct Productstock stock[20];

    // Index increase and decreasing the product stock
    int index;
};

// A customer structure is created with the product name and price
struct Customer {
    //Pointer is added for the customers name so that there is no defined lenght
    char *Customername;
    double Budget;
        // Products in the shopping list can only contain a maximum of ten items
    struct Productstock shoppinglist[10];
        // Keeps track of the increase and decrease the product stock
    int index;
};


// Method to print the  product name as string & product price as double. Void does not return the results to the caller it prints to the screen
void printProduct(struct Product p)
{
    // COMMENT REQUIRED
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
    printf("------\n");

}


//Read in shops stock and cash float from a CSV file
struct Shop createAndStockShop()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    // Open file & read in detail
    fp = fopen("stock.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    //This gets the first line of the file
    getline(&line, &len, fp);

    // Assigns the first line as cash in the shop and converts the string to a floating point number
    double cashInShop = atof(line);

    // This assignes variable shop to cashInShop
    struct Shop shop = {cashInShop};

    // Read in every line until the end of the file
    while ((read = getline(&line, &len, fp)) != -1) 
    {
        // Gets the address on the product names
        char *n = strtok(line, ",");

        // Gets the address on the product prices
        char *p = strtok(NULL, ",");

        // Gets the quantity on the products
        char *q = strtok(NULL, ",");

        // Convert quantity to data type integer 
        int quantity = atoi(q);

        // Converts prices to data type with two decimal places
        double price = atof(p);

        // Malloc manually allocates a piece of memory to store a variable
        char *name = malloc(sizeof(char)* 50);

        // This copys the string 
        strcpy(name,n);

        // This assignes the product within the product stuct the name and price variables read  filein from the
        struct Product product = {name,price};

        // This assignes the stockitem within the productstock the product and quantity read in from the file
        struct Productstock stockItem = {product , quantity};

        // This takes the cash in the shop the stock and assigns this as stockitem
        shop.stock[shop.index++] = stockItem;   
    }
    printProduct(shop.stock[0].product);
    return shop;
}

//Read in customers deatils and customers orders from a csv file
struct Customer sellshopsstock()
{   
    //struct Customer customer = {};
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;
    int i = 0;

    // Open file & read in detail
    fp = fopen("customerorder.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    //This gets the first line of the file
    getline(&line, &len, fp);

    // Gets the address on the product names
        char *cn = strtok(line, ",");

        // Gets the address on the product prices
        char *b = strtok(NULL, ",");

        // Malloc manually allocates a piece of memory to store a variable
        char *Customername = malloc(sizeof(char)* 50);
        
        // This copys the string 
        strcpy(Customername,cn);

        // Converts prices to data type with two decimal places
        double Budget = atof(b);

        // This assignes the product within the product stuct the name and price variables read  filein from the
       struct Customer cus = {Customername,Budget};

       // Print out customer name and budget
       printf("Customer name: %s Budget: %.2f\n",cus.Customername,cus.Budget);


    // Read in every line until the end of the file
    while ((read = getline(&line, &len, fp)) != -1) 
    {
       // printf("%s IS A LINE",line);}


        char *n = strtok(NULL, ",");
        
        // Gets the quantity on the products
        char *q = strtok(NULL, ",");

        // Convert quantity to data type integer 
        int quantity = atoi(q);

        // Malloc manually allocates a piece of memory to store a variable
        char *name = malloc(sizeof(char)* 50);  

         // This copys the string 
        strcpy(name,n);



        // This assignes the stockitem within the productstock the product and quantity read in from the file
       struct Productstock saleitem = {name , quantity};
           


        // Read in the customers shopping list from the CSV file and put it into the productstruct as shoppinglist 
        struct Productstock shoppingitems = {name , quantity};



       cus.shoppinglist[cus.index++] = shoppingitems; 
    }  

   return cus;
}

void printshop(struct Shop s)
{

    // // COMMENT REQUIRED
    printf("Shop has %.2f in cash\n", s.cash);

    // // COMMENT REQUIRED
    for (int i = 0; i < s.index; i++)
    {
        // // COMMENT REQUIRED
        printProduct(s.stock[i].product);
        printf("The SHOP HAS %d of the above\n",s.stock[i].quantity);
    }
}

void printCustomer(struct Customer cus)
{
    // COMMENT REQUIRED
    printf("Customer NAME: %s \n Budget: %.2f\n", cus.Customername, cus.Budget);
    printf("------\n");
    //Record productstock available
    for (int i = 0; i < cus.index; i++)
    {
        printProduct(cus.shoppinglist[i].product);
        //from customers name in customers shopping list get the prodcut name and the productstock (chaining of access)
        printf("%s ORDERS %2.f OF ABOVE PRODUCT\n",cus.Customername,cus.shoppinglist[i].quantity);
    }

}



//Enter method information here for function to call
int main(void)
{
   
   // COMMENT REQUIRED
    struct Shop shop = createAndStockShop();
     // COMMENT REQUIRED
    printshop(shop);
    
    struct Customer cus  = sellshopsstock();

    printCustomer(cus);

}