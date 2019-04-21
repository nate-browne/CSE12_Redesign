/*-----------------------------------------------------------------------------

                                                        Author: Nate Browne
                                                        Date: 20 Aug 2018
                        AVL Tree Implementation

File Name:       driver.cpp
Description:     This program acts like a test driver for the AVL tree
                 implementation to verify that everything is working correctly
                 and as expected with all of the member methods.
-----------------------------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <getopt.h>
#include "driver.h"
#include "avl_tree.h"

int main(int argc, char *argv[]) {

  char buffer[BUFSIZ], command, option;
  std::string str;
  int num;

  Tree<UCSDStudent>::set_debug(false);

  // Parse command line args
  while((option = getopt(argc, argv, "x")) != EOF) {
    switch(option) {
      case 'x':
        Tree<UCSDStudent>::set_debug(true);
        break;
    }
  }

  Tree<UCSDStudent> *tree = new Tree<UCSDStudent>();
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
        std::cout << "Please enter UCSD student name to insert: ";
        std::cin >> buffer;

        std::cout << "Please enter UCSD student number: ";
        std::cin >> num;

        // Create and insert student
        str = std::string(buffer);
        UCSDStudent stu(str, num);
        tree->insert(stu);

        break;
      }

      // lookup
      case 'l': {

        bool found;

        // grab input
        std::cout << "Please enter UCSD student name to lookup: ";
        std::cin >> buffer;

        // Create string and student, look them up
        str = std::string(buffer);
        UCSDStudent stu(str);
        found = tree->lookup(stu);

        // report results
        if(found) {
          std::cout << "Student found!!!" << std::endl << stu << std::endl;
        } else {
          std::cout << "student " << str << " not there!" << std::endl;
        }
        break;
      }

      // remove
      case 'r': {

        bool removed;

        // grab input
        std::cout << "Please enter UCSD student name to remove: ";
        std::cin >> buffer;

        // Create string and student, look them up
        str = std::string(buffer);
        UCSDStudent stu(str);
        removed = tree->remove(stu);

        // report results
        if(removed) {
          std::cout << "Student removed!!!" << std::endl << stu << std::endl;
        } else {
          std::cout << "student " << str << " not there!" << std::endl;
        }
        break;
      }

      // write
      case 'w': {

        tree->Write(std::cout << "The tree contains:" << std::endl);;
        break;
      }
    }
  }

  tree->Write(std::cout << "Final Tree:" << std::endl);
  delete tree;
  return EXIT_SUCCESS;
}
