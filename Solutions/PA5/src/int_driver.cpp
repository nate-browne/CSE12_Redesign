/*-----------------------------------------------------------------------------

                                                        Author: Nate Browne
                                                        Date: 20 Aug 2018
                        AVL Tree Implementation

File Name:       int_driver.cpp
Description:     This program acts like a test driver for the AVL tree
                 implementation to verify that everything is working correctly
                 and as expected with all of the member methods.
-----------------------------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <getopt.h>
#include "avl_tree.h"

int main(int argc, char *argv[]) {

  char command, option;
  std::string str;
  int num;

  Tree<int>::set_debug(false);

  // Parse command line args
  while((option = getopt(argc, argv, "x")) != EOF) {
    switch(option) {
      case 'x':
        Tree<int>::set_debug(true);
        break;
    }
  }

  Tree<int> *tree = new Tree<int>();
  tree->Write(std::cout << "Initial tree:" << std::endl);

  while(std::cin) {
    command = '\0'; // Reset command each time through the loop

    // Get user's command choice
    std::cout << "Please enter a command (is(e)mpty, (i)nsert, (l)ookup, (r)emove"
      << ", (w)rite): ";
    std::cin >> command;
    std::cout << std::endl;

    switch(command) {

      // empty check
      case 'e': {

        if(tree->is_empty()) {
          std::cout << "Tree is empty." << std::endl;
        } else {
          std::cout << "Tree is not empty." << std::endl;
        }
        break;
      }

      // insertion
      case 'i': {

        // Grab input
        std::cout << "Please enter number to insert: ";
        std::cin >> num;

        tree->insert(num);

        break;
      }

      // lookup
      case 'l': {

        bool found;

        // grab input
        std::cout << "Please enter number to lookup: ";
        std::cin >> num;

        // Lookup number
        found = tree->lookup(num);

        // report results
        if(found) {
          std::cout << "Number found!!!" << std::endl << num << std::endl;
        } else {
          std::cout << "number" << num << " not there!" << std::endl;
        }
        break;
      }

      // remove
      case 'r': {

        bool removed;

        // grab input
        std::cout << "Please enter UCSD student name to remove: ";
        std::cin >> num;

        // remove number
        removed = tree->lookup(num);

        // report results
        if(removed) {
          std::cout << "Number removed!!!" << std::endl << num << std::endl;
        } else {
          std::cout << "student " << num << " not there!" << std::endl;
        }
        break;
      }

      // write
      case 'w': {

        tree->Write(std::cout << "The tree contains:" << std::endl);
        break;
      }
    }
  }

  tree->Write(std::cout << "Final Tree:" << std::endl);
  delete tree;
  return EXIT_SUCCESS;
}
