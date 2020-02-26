#include "RST.hpp"

#define PROMPT "Enter a command ((c)ontains, i(s)_empty, (e)mpty, (i)nsert, (r)emove,\
 (p)rint, (f)ind_min, find_(m)ax): "

using std::string;
using std::cout;
using std::endl;
using std::cin;

static inline void clrbuf(void) {
  char c;
  do {
    c = fgetc(stdin);
  } while(c != '\n');
}

int main(void) {

  char opt;

  string val, m_val;
  char buf[BUFSIZ];

  RST<string> *tree = new RST<string>();

  while(true) {

    opt = '\0';
    cout << endl << PROMPT;

    if((opt = fgetc(stdin)) == EOF) break;

    clrbuf();

    switch(opt) {
      case 'c':
        cout << "Enter a string to search for: ";
        cin >> buf;
        clrbuf();

        val = string(buf);

        cout << "String \"" << val << "\" in tree: " <<
          ((tree->contains(val)) ? "true" : "false") << endl;
        break;
      case 's':
        cout << "Tree is empty: " << ((tree->is_empty()) ? "true" : "false")
          << endl;
        break;
      case 'e':
        tree->empty();
        cout << "Tree is empty." << endl;
        break;
      case 'i':
        cout << "Enter a string to insert: ";
        cin >> buf;
        clrbuf();

        val = string(buf);
        tree->insert(val);
        cout << "String \"" << val << "\" inserted." << endl;
        break;
      case 'r':
        cout << "Enter a string to remove: ";
        cin >> buf;
        clrbuf();

        val = string(buf);

        if(!tree->contains(val)) {
          cout << "String \"" << val << "\" not in the tree." << endl;
        } else {
          tree->remove(val);
          cout << "String \"" << val << "\" removed." << endl;
        }
        break;
      case 'p':
        tree->print();
        break;
      case 'f':
        try {
          m_val = tree->find_min();
          cout << "Min value is \"" << m_val << "\"" << endl;
        } catch(std::out_of_range & ex) {
          cout << ex.what() << endl;
        }
        break;
      case 'm':
        try {
          m_val = tree->find_max();
          cout << "Max value is \"" << m_val << "\"" << endl;
        } catch(std::out_of_range & ex) {
          cout << ex.what() << endl;
        }
        break;
      default:
        cout << "Command '" << opt << "' is invalid." << endl;
        break;
    }
  }

  delete tree;
  return EXIT_SUCCESS;
}
