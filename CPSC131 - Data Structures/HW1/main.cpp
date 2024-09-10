#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "GroceryItem.hpp"

int main() {
  std::cout << std::showpoint << std::fixed << std::setprecision(2)
      << "Welcome to Kroger. Place grocery items into your shopping cart by entering each item's information.\n"
      << "   enclose string entries in quotes, separate fields with commas.\n"
      << "   for example: \"00016000306707\", \"Betty Crocker\", \"Betty Crocker Double Chocolate Chunk Cookie Mix\", 17.19\n"
      << "   Enter CTL-Z (Windows) or CTL-D (Linux) to quit\n\n";

  std::vector<std::unique_ptr<GroceryItem>> shoppingCart;

  GroceryItem item;

  while (std::cout << "Enter UPC, Product Brand, Product Name, and Price\n", std::cin >> item) 
  {
    shoppingCart.emplace_back(std::make_unique<GroceryItem>(std::move(item)));
    std::cout << "Item added to shopping cart: " << *shoppingCart.back()
              << "\n\n";
  }

  while( !shoppingCart.empty() )
  {
    std::cout << *shoppingCart.back() << "\n";
    shoppingCart.pop_back();
  }

  return 0;
}
