#include <cctype>
#include <cassert>

#include "AVL.hpp"

#define PROMPT "Enter a command ((c)ontains, i(s)_empty, (e)mpty, (i)nsert, (r)emove,\
 (p)rint, (f)ind_min, find_(m)ax): "

static inline void clrbuf(void) {
  char c;
  do {
    c = fgetc(stdin);
  } while(c != '\n');
}

static void die(const char *reason) {
  fprintf(stderr, "%s\n", reason);
  exit(1);
}

int main(void) {

  char opt;
  std::cout << "Starting automated tests..." << std::endl;

  cse12_ds::BST<int> *t1 = nullptr, *t2 = nullptr;

  t1 = new cse12_ds::BST<int>();
  assert(t1); // make sure the constructor worked
  assert(t1->is_empty());

  t1->insert(1);
  t1->insert(2);
  t1->insert(3);
  t1->insert(4);
  t1->insert(5);
  t1->insert(6);
  t1->insert(7);

  assert(!t1->is_empty()); // tree shouldn't be empty now
  t1->print();
  std::cout << std::endl;

  t1->empty();
  assert(t1->is_empty()); // tree should now be empty

  t1->insert(2);
  t1->insert(1);
  t1->insert(3);

  t2 = new cse12_ds::AVL<int>(*t1); // try using the copy constructor

  assert(t2); // shouldn't be null still
  t2->insert(4);
  t2->insert(5);
  t2->insert(6);
  t2->insert(7);
  t2->print();
  std::cout << std::endl;

  t2->remove(4); // remove the root
  t2->print();
  std::cout << std::endl;

  delete t1;
  t1 = nullptr;
  t2->empty();
  assert(t2->is_empty()); // tree should be empty now

  delete t2;
  t2 = nullptr;

  std::cout << std::endl << "Automated tests complete!" << std::endl;
  std::cout << "The driver will now go into interactive mode." << std::endl;
  std::cout << "The datatype will be std::string." << std::endl;

  cse12_ds::BST<std::string> *tree = nullptr;

  std::cout << std::endl << "(A)VL or (B)ST?: ";
  std::cin >> opt;
  clrbuf();

  opt = toupper(opt);

  switch(opt) {
    case 'A':
      tree = new cse12_ds::AVL<std::string>();
      break;
    case 'B':
      tree = new cse12_ds::BST<std::string>();
      break;
    default:
      die("Invalid Tree option given.");
  }

  std::string val, m_val;
  char buf[BUFSIZ];

  while(true) {

    opt = '\0';
    std::cout << std::endl << PROMPT;

    if((opt = fgetc(stdin)) == EOF) break;

    clrbuf();

    switch(opt) {
      case 'c':
        std::cout << "Enter a string to search for: ";
        std::cin >> buf;
        clrbuf();

        val = std::string(buf);

        std::cout << "String \"" << val << "\" in tree: " <<
          ((tree->contains(val)) ? "true" : "false") << std::endl;
        break;
      case 's':
        std::cout << "Tree is empty: " << ((tree->is_empty()) ? "true" : "false")
          << std::endl;
        break;
      case 'e':
        tree->empty();
        std::cout << "Tree is empty." << std::endl;
        break;
      case 'i':
        std::cout << "Enter a string to insert: ";
        std::cin >> buf;
        clrbuf();

        val = std::string(buf);
        tree->insert(val);
        std::cout << "String \"" << val << "\" inserted." << std::endl;
        break;
      case 'r':
        std::cout << "Enter a string to remove: ";
        std::cin >> buf;
        clrbuf();

        val = std::string(buf);

        if(!tree->contains(val)) {
          std::cout << "String \"" << val << "\" not in the tree." << std::endl;
        } else {
          tree->remove(val);
          std::cout << "String \"" << val << "\" removed." << std::endl;
        }
        break;
      case 'p':
        tree->print();
        break;
      case 'f':
        try {
          m_val = tree->find_min();
          std::cout << "Min value is \"" << m_val << "\"" << std::endl;
        } catch(std::out_of_range & ex) {
          std::cout << ex.what() << std::endl;
        }
        break;
      case 'm':
        try {
          m_val = tree->find_max();
          std::cout << "Max value is \"" << m_val << "\"" << std::endl;
        } catch(std::out_of_range & ex) {
          std::cout << ex.what() << std::endl;
        }
        break;
      default:
        std::cout << "Command '" << opt << "' is invalid." << std::endl;
        break;
    }
  }

  delete tree;
  return EXIT_SUCCESS;
}

