#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "KDT.hpp"

using namespace std;

// Helper method implemented below
Point populate(string &);

int main(int argc, char *argv[]) {

  unsigned int size = 0;
  unsigned int height = 0;

  // Check for Arguments
  if(argc != 2) {
    cerr << "Invalid number of arguments." << endl
      << "Usage: ./main <input filename>." << endl;
    return -1;
  }

  // Open file
  ifstream in;
  in.open(argv[1], ios::binary);

  // Check if input file was actually opened
  if(!in.is_open()) {
    cerr << "Invalid input file. No file was opened. Please try again." << endl;
    return -1;
  }

  // Check for empty file
  in.seekg(0, ios_base::end);
  unsigned int len = in.tellg();
  if(!len) {
    cout << "The file is empty. " << endl;
    return -1;
  }

  // Resets the stream to beginning of file
  in.seekg(0, ios_base::beg);

  // Instantiate a tree
  KDT kdt = KDT();
  string line;
  vector<Point> to_insert;

  // Parse file and populate the vector
  for(string line; getline(in, line); ) {
    Point pt = populate(line);
    to_insert.push_back(pt);
  }

  // Populate the k-d tree
  size = kdt.build(to_insert);
  height = kdt.height();

  cout << "Size of tree: " << size << endl;
  cout << "Height of tree: " << height << endl;
  string query;
  char response = 'y';

  do {

    cout << "Enter coordinate (x y): " << endl;
    getline(cin, query);
    Point to_find = populate(query);
    KDT::iterator it = kdt.findNearestNeighbor(to_find);

    cout << "Nearest point in tree: " << *it << endl;

    cout << "Search again? (y/n): " << endl;
    cin >> response;
    cin.ignore();

    if(response != 'n' && response != 'y') {
      cout << "Invalid response" << endl;
      return EXIT_FAILURE;
    }
  } while(response == 'y');

  if(in.is_open()) {
    in.close();
  }

  return EXIT_SUCCESS;
}

/**
 * Helper method to create a point from a parsed string
 */
Point populate(string & str) {

  // Create C-style string for use with tokenizing
  char * temp = new char[str.length() + 1];
  double x, y;
  bool x_point = false;

  // Parse on whitespace
  strncpy(temp, str.c_str(), str.length());
  char * ptr = strtok(temp, " ");

  // Grab x and y coordinates
  while(ptr) {
    char *endptr;
    if(!x_point) {
      x = strtod(ptr, &endptr);
      x_point = true;
    } else {
      y = strtod(ptr, &endptr);
    }
    ptr = strtok(NULL, " ");
  }

  // Create a point
  Point pt = Point(x, y);
  delete[] temp;
  return pt;
}
