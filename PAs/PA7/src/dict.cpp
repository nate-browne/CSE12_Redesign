#include <string.h> // for memset

#include "dict.hpp"

typedef std::tuple<std::string, std::string> StringTuple;

// utility functions
static std::vector<StringTuple> *parse_file(const std::string & filename) {
  std::ifstream in;
  auto *retval = new std::vector<std::tuple<std::string, std::string>>();
  std::string line;

  in.open(filename);

  if(!in.is_open()) {
    delete retval;
    throw std::invalid_argument("Couldn't open file.");
  }

  in.seekg(0, std::ios_base::end);
  size_t len = in.tellg();

  if(!len) {
    in.close();
    delete retval;
    throw std::invalid_argument("File is empty.");
  }

  in.seekg(0, std::ios_base::beg);

  while(std::getline(in, line)) {
    std::istringstream ss(line);
    std::vector<std::string> record;

    while(ss) {
      std::string next;
      if(!std::getline(ss, next, '\t')) break;
      record.push_back(next);
      if(record.size() != 2) continue;
      retval->push_back(std::make_tuple(record[0], record[1]));
    }
  }

  in.close();
  return retval;
}

static std::vector<std::string> *parse_network(const std::string & filename) {
  std::ifstream in;
  auto *retval = new std::vector<std::string>();
  std::string line;

  in.open(filename);

  if(!in.is_open()) {
    delete retval;
    throw std::invalid_argument("Couldn't open file.");
  }

  in.seekg(0, std::ios_base::end);
  size_t len = in.tellg();
  if(!len) {
    in.close();
    delete retval;
    throw std::invalid_argument("File is empty.");
  }

  in.seekg(0, std::ios_base::beg);

  while(std::getline(in, line)) {
    retval->push_back(line);
  }

  in.close();
  return retval;
}

PhoneBook::PhoneBook(const std::string & filename) {
  listings = new std::unordered_map<std::string, std::string>();
  listings->max_load_factor(0.75); // default is 1.0 (bad)
  this->build_listings(filename);
}

PhoneBook::~PhoneBook(void) {
  delete this->listings;
}

void PhoneBook::build_listings(const std::string & filename) {
  auto parsed = parse_file(filename);

  for(auto it : *parsed) {
    if(this->listings->count(std::get<0>(it))) continue; 
    (*this->listings)[std::get<0>(it)] = std::get<1>(it);
  }

  delete parsed;
}

bool PhoneBook::is_entry(const std::string & name) const {

}

const std::string PhoneBook::get_entry(const std::string & name) const {

}

SocialNetworkNode::SocialNetworkNode(const std::string & name) {
  this->name = name;
  this->friends = new std::unordered_set<std::string>();
  this->friends->max_load_factor(0.75);
}

SocialNetworkNode::~SocialNetworkNode(void) {
  delete this->friends;
}

void SocialNetworkNode::add_friend(const std::string & friend_n) {

}

std::string SocialNetworkNode::get_name(void) const {

}

const std::unordered_set<std::string> * SocialNetworkNode::get_friends_list(void) const {

}

void SocialNetwork::fill_entry(const std::string & nm, const std::vector<std::string> * entries) {
  std::default_random_engine generator;
  std::uniform_real_distribution<double> dist;
  for(std::string ent : *entries) {
    double drop_prob = dist(generator);
    if(ent != nm) {
      if(dist(generator) > drop_prob)
        this->friend_map->at(nm)->add_friend(ent);
    }
  }
}

void SocialNetwork::build_network(const std::string & filename) {
  auto parsed = parse_network(filename);

  for(auto it : *parsed) {
    (*this->friend_map)[it] = new SocialNetworkNode(it);
    fill_entry(it, parsed);
  }
  delete parsed;
}

SocialNetwork::SocialNetwork(const std::string & filename) {
  this->friend_map = new std::unordered_map<std::string, SocialNetworkNode *>();
  this->friend_map->max_load_factor(0.75);
  this->build_network(filename);
}

SocialNetwork::~SocialNetwork(void) {

}

bool SocialNetwork::are_connected(const std::string & name_1, const std::string & name_2) const {
  return false;
}

void SocialNetwork::print_friends_for(const std::string & name) {

}

bool SocialNetwork::is_entry(const std::string & name) {
  return this->friend_map->count(name);
}
