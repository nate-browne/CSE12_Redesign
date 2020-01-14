#ifndef DICT_HPP
#define DICT_HPP

#include <cstdlib>

#include <queue>
#include <tuple>
#include <vector>
#include <random>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

class PhoneBook {
  std::unordered_map<std::string, std::string> *listings;
  void build_listings(const std::string &);
 public:
  PhoneBook(const std::string &);
  ~PhoneBook(void);

  bool is_entry(const std::string &) const;
  const std::string get_entry(const std::string &) const;
};

class SocialNetworkNode {
  std::string name;
  std::unordered_set<std::string> *friends;
 public:
  SocialNetworkNode(const std::string &);
  ~SocialNetworkNode(void);
  void add_friend(const std::string &);
  const std::unordered_set<std::string> * get_friends_list(void) const;
  std::string get_name(void) const;
};

class SocialNetwork {
  std::unordered_map<std::string, SocialNetworkNode *> *friend_map;
  void build_network(const std::string &);
  void fill_entry(const std::string &, const std::vector<std::string> *);
 public:
  SocialNetwork(const std::string &);
  ~SocialNetwork(void);
  bool are_connected(const std::string &, const std::string &) const;
  void print_friends_for(const std::string &);
  bool is_entry(const std::string &);
};

#endif

