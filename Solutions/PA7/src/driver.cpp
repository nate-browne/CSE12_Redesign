#include <string.h> // for memset

#include "dict.hpp"

static void die(const char *reason) {
  fprintf(stderr, "%s\n", reason);
  exit(1);
}

static void clrbuf(void) {
  char c = '\0';
  while(c != '\n') c = fgetc(stdin);
}

static void handle_phone(PhoneBook * pb) {
  char opt;
  std::string name;
  std::string res;
  char buf[BUFSIZ];
  std::cout << "(q)uery or (g)et_entry: ";

  if((opt = fgetc(stdin)) == EOF) return;

  clrbuf();

  switch(opt) {
    case 'q':
      std::cout << "Enter a name to search the phone book for: ";
      std::cin >> buf;
      clrbuf();
      name = std::string(buf);
      std::cout << "\"" << name << "\" is in the phone book: "
        << ((pb->is_entry(name)) ? "true" : "false") << std::endl;
      break;
    case 'g':
      std::cout << "Enter a name to get the phone number of: ";
      std::cin >> buf;
      clrbuf();
      name = std::string(buf);
      if((res = pb->get_entry(name)) != "") {
        std::cout << "For name \"" << name << "\", the phone number is: "
          << res << std::endl;
      } else {
        std::cout << "Name \"" << name << "\" is not present." << std::endl;
      }
      break;
    default:
      std::cerr << "\'" << opt << "\' is not a valid option." << std::endl;
      break;
  }
}

static void handle_network(SocialNetwork * sn) {
  std::string start, target;
  char opt;
  char buf[BUFSIZ];
  std::cout << "(c)onnectivity check or (p)rint friends: ";

  if((opt = fgetc(stdin)) == EOF) return;

  clrbuf();

  switch(opt) {
    case 'c':
      std::cout << "Enter a starting name (must be in the network): ";
      std::cin >> buf;
      clrbuf();
      start = std::string(buf);

      memset(buf, '\0', BUFSIZ);
      std::cout << "Enter a target name (doesn't necessarily have to be in the network): ";
      std::cin >> buf;
      clrbuf();
      target = std::string(buf);

      if(!sn->is_entry(start)) {
        fprintf(stderr, "%s\n", "Invalid starting name (not in network).");
        break;
      }

      std::cout << "Path from \"" << start << "\" to \"" << target << "\": "
        << ((sn->are_connected(start, target)) ? "true" : "false") << std::endl;
      break;
    case 'p':
      std::cout << "Enter a name to print friends of (must be in the network): ";
      std::cin >> buf;
      clrbuf();
      start = std::string(buf);

      if(!sn->is_entry(start)) {
        fprintf(stderr, "%s\n", "Invalid starting name (not in network).");
        break;
      }

      sn->print_friends_for(start);
      break;
    default:
      std::cerr << "\'" << opt << "\' is not a valid option." << std::endl;
      break;
  }
}

int main(int argc, char *argv[]) {

  if(argc < 3) die("Not enough command line args passed.");

  PhoneBook *pb = nullptr;
  SocialNetwork *sn = nullptr;

  try {
    std::string phone_file(argv[1]);
    pb = new PhoneBook(phone_file);
  } catch(std::invalid_argument & ex) {
    die("Problems with file I/O.");
  }

  try {
    std::string net_file(argv[2]);
    sn = new SocialNetwork(net_file);
  } catch(std::invalid_argument & ex) {
    delete pb;
    die("Problems with file I/O.");
  }

  while(true) {
    char c;
    std::cout << "(p)honebook or (s)ocial network: ";

    if((c = fgetc(stdin)) == EOF) break;

    clrbuf();

    switch(c) {
      case 'p':
        handle_phone(pb);
        break;
      case 's':
        handle_network(sn);
        break;
      default:
        std::cerr << "\'" << c << "\' is not a valid option." << std::endl;
        break;
    }
  }

  delete pb;
  delete sn;
  return EXIT_SUCCESS;
}
