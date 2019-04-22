#ifndef PA1_HPP
#define PA1_HPP

#include <string>

const std::string PERFECT = "Perfect score!";
const std::string A_SCORE = "You got an A!";
const std::string B_SCORE = "You got a B, not bad!";
const std::string C_SCORE = "You got a C, you can do better!";
const std::string D_SCORE = "Oof you got a D, try again next time";
const std::string FAIL = "Yikes that's an F bud, sorry";

// Question 1: Return a string corresponding to the grade
std::string GradeAssignment(int);

// Question 2: replace all letters in the string with the given char and return
// it
std::string ReplaceLetter(const std::string &, const char, const char);

// Question 3: Find the average of all of the entries of the array
double AverageScore(const double scores[], int);

#endif