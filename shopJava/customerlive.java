package ShopVideoVersion;

import java.util.Scanner;

class customerlive {
  public static void main(String[] args) {
    Scanner myObj = new Scanner(System.in);

    System.out.println("Customer Name, Product Name and quantity:");

    // String input
    String Customer_Name = myObj.nextLine();
    String Product_Name = myObj.nextLine();

    // Numerical input
    int quantity = myObj.nextInt();
    //double salary = myObj.nextDouble();

    // Output input by user
    System.out.println("Customer Name: " + Customer_Name);
    System.out.println("Product Name: " + Product_Name);
    System.out.println("Quantity: " + quantity);
  }
}
