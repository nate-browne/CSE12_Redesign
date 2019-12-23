# PA7: Using Other People's Code (The STL) (XXX points)
### Due: TBD

### Overview
In this PA, you'll finally be using the C++ STL in order to solve some
non-trivial problems. You may use whatever headers you'd like, though the
ones included already are sufficient.

Your implementation should go in `dict.cpp`.

#### Compilation and Testing
To compile, use the provided Makefile. If you just want to build the program, run `make build`. If you want to build and run, use `make prog`. For debugging, run `make debug`.

Like before, you are responsible for testing your program fully. We provide a driver for you to use, but you still have to verify correctness to ensure a good grade.

#### Turnin
*Instructions coming soon!*

### The Code
You'll be filling out the missing method bodies for the classes defined in `dict.hpp`. These classes are as follows:

1. A phone book that holds names mapped to their numbers.
2. An abstraction of a social network as a graph.

Many methods are very straight forward, but for the more complicated ones, make sure you understand what it is you're doing _before_ you
try writing any code.

#### The Functions, Described
1. `bool PhoneBook::is_empty(const std::string & name) const`
   * This function just checks if our PhoneBook is empty.
   * Should be an easy one-liner.
2. `const std::string PhoneBook::get_entry(const std::string & name) const`
   * This function should grab the corresponding phone number for the given `name`.
   * If no such number exists, return the empty string.
3. `void SocialNetworkNode::add_friend(const std::string & friend_n)`
   * This function just adds a friend to the current node.
     * What field do you modify to accomplish this?
   * Should be a one line function.
4. `bool SocialNetworkNode::query(const std::string & name) const`
   * Checks if the given `name` is a friend of the current node.
   * Should be a one line function.
5. `std::string SocialNetworkNode::get_name(void) const`
   * Gets the name of the current node.
   * Should be an easy one-liner.
6. `const std::unordered_set<std::string> *SocialNetworkNode::get_friends_list(void) const`
   * Returns the list of friends for the current node.
   * Should be an easy one-liner.
7. `SocialNetwork::~SocialNetwork(void)`
   * Deallocates *all* memory for this SocialNetwork.
     * What does that also include? Look at the type of the `unordered_map`.
8. `bool SocialNetwork::are_connected(const std::string & name_1, const std::string & name_2) const`
   * Walk the structure looking to see if there is any way to reach `name_2` from `name_1`, and return
      true if one does exist.
   * See the implementation tips for more.
9. `void SocialNetwork::print_friends_for(const std::string & name) const`
   * Prints all of the friends of the node with the given `name`.
   * *__MAKE SURE TO RUN THE DRIVER TO SEE THE EXPECTED FORMAT__*
     * You have been warned.

#### Implementation Tips
1. Make heavy use of websites like <a href="http://cppreference.com/" target="_blank">cppreference</a>; these
   pages work wonders for understanding the STL.
2. Take your time and draw things out to make sure you understand all of the working parts.
3. Read through and understand all of the code we gave you; it'll simplify things later.
4. For function 8, you'll need to understand how to traverse a graph. You may want to look into
   implementing either BFS or DFS (DuckDuckGo them), but make sure you understand the code to see
   how you get from node to node.
5. This PA features command line arguments and file I/O to make testing easier, but make sure
   that the formatting is correct since the I/O code isn't very robust.

# Good luck! Start Early, Test Often, and Finish Early!
