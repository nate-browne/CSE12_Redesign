#include "RST.hpp"

#define PROMPT "Enter a command ((c)ontains, i(s)_empty, (e)mpty, (i)nsert, (r)emove,\
 (p)rint, (f)ind_min, find_(m)ax): "

static inline void clrbuf(void) {
  char c = '\0';
  while(c != '\n') c = fgetc(stdin);
}

int main(void) {

  char opt;

  std::string val, m_val;
  char buf[BUFSIZ];

  RST<std::string> *tree = new RST<std::string>();

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
