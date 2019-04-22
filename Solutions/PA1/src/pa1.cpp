#include "pa1.hpp"

std::string grade_assignment(int grade) {
  if(grade == 100) {
    return PERFECT;
  } else if(grade >= 90 && grade < 100) {
    return A_SCORE;
  } else if(grade >= 80 && grade < 90) {
    return B_SCORE;
  } else if(grade >= 70 && grade < 80) {
    return C_SCORE;
  } else if(grade >= 60 && grade < 70) {
    return D_SCORE;
  } else {
    return FAIL;
  }
}

std::string replace_letter(const std::string & to_replace, const char replacee, const char replacer) {
  std::string result = "";
  for(auto c : to_replace) {
    if(c == replacee) {
      result += replacer;
    } else {
      result += c;
    }
  }
  return result;
}

double average_score(const double scores[], int num_elements) {
  double sum = 0;
  for(int i = 0; i < num_elements; ++i) {
    sum += scores[i];
  }
  return sum / num_elements;
}