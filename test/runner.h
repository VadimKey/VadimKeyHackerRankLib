#pragma once

// if TESTHEADER defined it will be included
#ifdef TESTHEADER
#include TESTHEADER
#endif

#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace HackerRank {
namespace Test {

// For simple unit tests it will be enough to put TEST_MAIN in the source file
#define TEST_MAIN() int main() { return HackerRank::Test::Runner::run(); }
  
// Define and register test function
// E.g.:
// TEST(foo) {
//   reason = "N/A";
//   return false;
// }
// Will create function:
// bool test_foo(string&);
// and register it with Test::Runner
#define TEST(name) bool test_ ## name (std::string& reason); \
  HackerRank::Test::Runner::add hlp_add_ ## name(test_ ## name);	    \
  bool test_ ## name (std::string& reason)
  
// Test function should return bool and accept string reference as parameter
typedef std::function<bool(std::string&)> TestFunction;

// Tests runner
// First you need to register tests (you can do it just in the global scope):
// Runner::add(footest);
// Runner::add(bartest);
//
// Then you can run tests:
// return Runner::run();
class Runner {
public:
  // Register test function to be runned
  struct add {
    add(const TestFunction& test) { Runner::tests.push_back(test); }
  };

  // Run registered tests in order of adding
  // will return 0 if ok
  // otherwise will return 1 and fail reason will be logged to standard error output
  static int run() {
    std::string reason;
    for (auto& test : tests) {
      if (not test(reason)) {
	std::cerr << "TEST " TESTHEADER " FAILED: " << reason << std::endl;
	return 1;
      }
    }
    return 0;
  }

private:
  static std::vector<TestFunction> tests;
};

std::vector<TestFunction> Runner::tests;

} // namespace test
} // namespace HackerRank
