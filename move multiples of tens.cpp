#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// --- Abstract Solution ---
vector<int> rearrangeInventory(vector<int> nums) {
    vector<int> answer;
    vector<int>tens;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%10==0){
            tens.push_back(nums[i]);
        } else {
            answer.push_back(nums[i]);
        }
    }
    int i=0;
    for(;i<answer.size();i++){
        nums[i] = answer[i];
    }
    int t = tens.size();

    for(auto x:tens){
        nums[i] = x;
        i++;
    }
    
    
    
    return nums; 
}

// --- Helper Functions for UI ---
string vectorToString(const vector<int>& v) {
    string res = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        res += to_string(v[i]) + (i == v.size() - 1 ? "" : ",");
    }
    res += "]";
    return res;
}

void runTests() {
    struct TestCase {
        int id;
        vector<int> input;
        vector<int> expected;
    };

    vector<TestCase> tests = {
        {1, {10, 2, 30, 4, 5}, {2, 4, 5, 10, 30}},
        {2, {1, 2, 3, 4}, {1, 2, 3, 4}},
        {3, {10, 20, 30}, {10, 20, 30}},
        {4, {0, 15, 20, 7}, {15, 7, 0, 20}},
        {5, {}, {}},
        {6, {100, -10, 5, -20, 11}, {5, 11, 100, -10, -20}},
        {7, {10, 10, 10, 1, 2}, {1, 2, 10, 10, 10}},
        {8, {5555, 100000, 44, 20}, {5555, 44, 100000, 20}}
    };

    printf("%-3s | %-20s | %-20s | %-20s | %-10s\n", "ID", "Input Data", "Expected", "Actual", "Status");
    printf("-------------------------------------------------------------------------------------------\n");

    for (const auto& t : tests) {
        vector<int> actual = rearrangeInventory(t.input);
        bool pass = (actual == t.expected);
        
        string inputStr = vectorToString(t.input);
        string expectedStr = vectorToString(t.expected);
        string actualStr = vectorToString(actual);

        printf("%-3d | %-20s | %-20s | %-20s | ", t.id, inputStr.c_str(), expectedStr.c_str(), actualStr.c_str());
        
        if (pass) {
            printf("\033[32mPASS ✅\033[0m\n");
        } else {
            printf("\033[31mFAIL ❌\033[0m\n");
        }
    }
}

int main() {
    runTests();
    return 0;
}
