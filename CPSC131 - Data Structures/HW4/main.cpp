#include <exception>
#include <iomanip>                                                        // setprecision()
#include <iostream>                                                       // cout, fixed(), showpoint()

#include "GroceryStore.hpp"






int main()
{
  try
  {
    std::cout << std::fixed << std::setprecision( 2 ) << std::showpoint;


    ///////////////////////// TO-DO (1) //////////////////////////////
      /// Create a grocery store
      ///
    GroceryStore raleys; // Created the best chain of grocery store in the world, Raley's

    /////////////////////// END-TO-DO (1) ////////////////////////////


    ///////////////////////// TO-DO (2) //////////////////////////////
      /// Now, let's pretend your grocery store is busy with several shoppers, each pushing a shopping cart filled with a bunch of
      /// groceries by using your store's makeShoppingCarts function to create a collection of shopping carts.
      ///
    GroceryStore::ShoppingCarts raleys_shopping_carts = raleys.makeShoppingCarts(); // Filled the store to the brim with shoppers

    /////////////////////// END-TO-DO (2) ////////////////////////////


    ///////////////////////// TO-DO (3) //////////////////////////////
      /// There are several shoppers standing in line waiting to purchase the groceries in their shopping cart.  Process them all by
      /// passing the collection of shopping carts to your store's ringUpCustomers function.  This function will, for each shopper,
      /// scan all the groceries in their shopping cart, print a receipt with an amount due, deduct the items bought from the
      /// store's inventory, and returns a collection of groceries sold.
      ///
    GroceryStore::GroceryItemsSold raleys_sold = raleys.ringUpCustomers( raleys_shopping_carts ); // Rung up all the customers in record time!

    /////////////////////// END-TO-DO (3) ////////////////////////////


    ///////////////////////// TO-DO (4) //////////////////////////////
      /// Get a reference to your store's inventory by using your store's inventory function.  The store doesn't carry everything,
      /// especially all at once.  The inventory tells you how many of each item are currently on hand (i.e., in stock).
      ///
      /// The store's managers have decided to stop selling Frozen Spanish Omelets (UPC = 00041331092609), so remove this from the
      /// store's inventory.
      ///
    GroceryStore::Inventory_DB & raleys_inventory = raleys.inventory(); // Pulled up the ole' inventory book from the Raley's vault
    raleys_inventory.erase( "00041331092609" ); // Bon voyage, Frozen Spanish Omelets!

    /////////////////////// END-TO-DO (4) ////////////////////////////


    ///////////////////////// TO-DO (5) //////////////////////////////
      /// All the shoppers have now checkout out and it's late in the day.  Close your store, take inventory, and if you sold enough
      /// items to fall below your re-order threshold, order more by using your store's reorderItems function passing the
      /// collection of items sold.
    raleys.reorderItems( raleys_sold ); // One click on Amazon and the store is restocked!

    /////////////////////// END-TO-DO (5) ////////////////////////////
  }

  catch( const std::exception & ex )
  {
    std::cout << "FAILED - Unhandled exception:\n"  << ex.what() << '\n';
  }

  return 0;
}
