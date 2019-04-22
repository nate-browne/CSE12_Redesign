#include <vector>

#include "../src/pa1.hpp"
#include "../src/util.hpp"

int run_tests(std::vector<bool> & results) {

  int count = 0, num_correct = 0;
  bool result;

  result = test_utils::test(grade_assignment(100), PERFECT);
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(grade_assignment(76), C_SCORE);
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(grade_assignment(88), B_SCORE);
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(grade_assignment(30), FAIL);
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(replace_letter("HELLO THERE", 'E', 'X'), std::string("HXLLO THXRX"));
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(replace_letter("GENERAL KENOBI", 'G', 'H'), std::string("HENERAL KENOBI"));
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(replace_letter("THE SENATE WILL DECIDE YOUR FATE", 'E',  '*'),
    std::string("TH* S*NAT* WILL D*CID* YOUR FAT*"));
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  result = test_utils::test(replace_letter("I AM THE SENATE", 'S', 'B'), std::string("I AM THE BENATE"));
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  double scores1[] = {10, 3, 8, 4, 9};
  result = test_utils::test(average_score(scores1, 5), 6.8);
  if(result) {
    results[count] = true;
    num_correct++;
  }
  count++;

  double scores2[] = {10, 13, 18, 14, 9, 20, 15, 17, 16, 16};
  result = test_utils::test(average_score(scores2, 10), 14.8);
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

  std::cout << "Number correct: " << num_correct << " out of 10" << std::endl;
  double grade = num_correct / 10;
  std::cout << "Grade: " << (grade * 100) << "%" << std::endl;
  if(num_correct != 10) {
    for(int i = 0; i < results.size(); ++i) {
      auto val = results[i];
      if(!val) {
        std::cout << "Re-run test #" << i << "." << std::endl;
      }
    }
  }
}