#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

// 1,1,2,3,4,9,8,27,16,81,32,243,64,729,128,2187...

/**
 * @brief Finds the n-th term of the mixed series.
 * Odd positions (1, 3, 5...): Power of 2 (2^0, 2^1, 2^2...)
 * Even positions (2, 4, 6...): Power of 3 (3^0, 3^1, 3^2...)
 * * @param n The position in the series (1-indexed)
 * @return long long The n-th term
 */
long long findNthTerm(int n) {
    // TODO: Implement your logic
    if(n<=0) return -1;
    if(n%2==1){
        n= (n+1)/2;
        return (long long) std::pow(2, n-1);
    } else {
        return (long long) std::pow(3, (n/2)-1);
    }
     
}

struct TestCase {
    int id;
    int input;
    long long expected;
};

void runTestSuite() {
    std::vector<TestCase> tests = {
        {1, 1, 1},          // 1st term: 2^0
        {2, 2, 1},          // 2nd term: 3^0
        {3, 3, 2},          // 3rd term: 2^1
        {4, 4, 3},          // 4th term: 3^1
        {5, 5, 4},          // 5th term: 2^2
        {6, 6, 9},          // 6th term: 3^2
        {7, 0, -1},         // Edge Case: Invalid input
        {8, -5, -1},        // Edge Case: Negative input
        {9, 15, 128},       // Large: 8th odd term (2^7)
        {10, 20, 19683}     // Large: 10th even term (3^9)
    };

    printf("%-4s | %-12s | %-12s | %-12s | %-10s\n", "ID", "Input Data", "Expected", "Actual", "Status");
    printf("---------------------------------------------------------------------------\n");

    for (const auto& test : tests) {
        long long actual = findNthTerm(test.input);
        bool passed = (actual == test.expected);

        printf("%-4d | %-12d | %-12lld | %-12lld | %s\n", 
               test.id, 
               test.input, 
               test.expected, 
               actual, 
               passed ? GREEN "PASS ✅" RESET : RED "FAIL ❌" RESET);
    }
}

int main() {
    runTestSuite();
    return 0;
}
