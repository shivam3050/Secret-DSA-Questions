#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For better alignment

using namespace std;

// --- YOUR SOLUTION FUNCTION ---
string solution(int v, int w) {
    // Validation: Odd wheels check
    if (w % 2 != 0) {
        return "-1";
    }

    // Logic: 2x + 4y = w  =>  y = (w - 2v) / 2
    int y = (w - 2 * v) / 2; 
    int x = v - y;

    // Validation: Out of bounds check
    if (x < 0 || y < 0) return "-1";

    return to_string(x) + " " + to_string(y); 
}

// --- AUTOMATED JUDGE SYSTEM (STYLIZED UI) ---
struct Test {
    int v, w;
    string expected;
    string desc;
};

// ANSI Color Codes for Terminal
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    vector<Test> testSuite = {
        {200, 540, "130 70", "Standard Mixed Case"},
        {10, 20, "10 0", "All Two-Wheelers"},
        {10, 40, "0 10", "All Four-Wheelers"},
        {10, 25, "-1", "Invalid: Odd Wheels"},
        {5, 40, "-1", "Invalid: Too many wheels"},
        {1, 2, "1 0", "Single TW"},
        {150, 400, "100 50", "Large Mixed Case"},
        {10, 10, "-1", "Edge: Too few wheels"}
    };

    cout << "\n" << BOLD << CYAN << "================================================================" << RESET << endl;
    cout << BOLD << CYAN << "                AUTOMATED JUDGE: VEHICLE COUNTER                " << RESET << endl;
    cout << BOLD << CYAN << "================================================================" << RESET << endl;
    
    // Table Header
    printf("%-3s | %-5s | %-5s | %-12s | %-12s | %-10s\n", "ID", "V", "W", "Expected", "Actual", "Result");
    cout << "----------------------------------------------------------------" << endl;

    int passed = 0;
    for (int i = 0; i < testSuite.size(); i++) {
        const auto& t = testSuite[i];
        string actual = solution(t.v, t.w);
        bool isCorrect = (actual == t.expected);
        
        if (isCorrect) passed++;

        // Row Print
        printf("%-3d | %-5d | %-5d | %-12s | %-12s | ", i + 1, t.v, t.w, t.expected.c_str(), actual.c_str());
        
        if (isCorrect)
            cout << GREEN << "PASS ✅" << RESET << endl;
        else
            cout << RED << "FAIL ❌" << RESET << endl;
    }

    cout << "----------------------------------------------------------------" << endl;
    
    // Final Summary
    float score = (float)passed / testSuite.size() * 100;
    cout << BOLD << "TOTAL SCORE: ";
    if (score == 100) cout << GREEN; else cout << RED;
    cout << passed << "/" << testSuite.size() << " (" << score << "%)" << RESET << endl;
    cout << BOLD << CYAN << "================================================================\n" << RESET << endl;

    return 0;
}
