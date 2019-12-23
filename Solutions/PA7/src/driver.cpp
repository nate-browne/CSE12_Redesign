#include <cassert>

#include "dict.hpp"

static void die(const char *reason) {
  fprintf(stderr, "%s\n", reason);
  exit(1);
}

int main(int argc, char *argv[]) {

  if(argc < 3) die("Not enough command line args passed.");

  PhoneBook *pb = nullptr;
  SocialNetwork *sn = nullptr;

  try {
    std::string phone_file(argv[1]);
    pb = new PhoneBook(phone_file);

    std::string net_file(argv[2]);
    sn = new SocialNetwork(net_file);
  } catch(std::invalid_argument & ex) {
    die("Problems with file I/O.");
  }

  delete pb;
  return EXIT_SUCCESS;
}
