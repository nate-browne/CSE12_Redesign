#include <vector>

#include "../src/pa1.hpp"
#include "../src/util.hpp"

int run_tests(std::vector<bool> & results) {

  int count = 0, num_correct = 0;
  bool result;

  result = test_utils::test(GradeAssignment(100), PERFECT);
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(GradeAssignment(30), FAIL);
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(ReplaceLetter("HELLO THERE", 'E', 'X'), std::string("HXLLO THXRX"));
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(ReplaceLetter("GENERAL KENOBI", 'G', 'H'), std::string("HENERAL KENOBI"));
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  double scores1[] = {10, 3, 8, 4, 9};
  result = test_utils::test(AverageScore(scores1, 5), 6.8);
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  return num_correct;
}

int main(void) {
  std::vector<bool> results = std::vector<bool>();

  for(int i = 0; i < 10; ++i) {
    results.push_back(false);
  }

  std::cout << "Running test suite..." << std::endl;
  int num_correct = run_tests(results);

  std::cout << "Number correct: " << num_correct << " out of 5" << std::endl;
  double grade = num_correct / 5;
  std::cout << "Grade: " << (grade * 100) << "%" << std::endl;
  if(num_correct != 5) {
    for(size_t i = 0; i < results.size(); ++i) {
      bool val = results[i];
      if(!val) {
        std::cout << "Re-run test #" << i << "." << std::endl;
      }
    }
  }
}

