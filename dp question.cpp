#include <bits/stdc++.h>

using namespace std;


int N;
vector<long long> A, B;
map<long long,long long>mp;

long long solve(int i, int x, int y, int z) {
   
    if (i == N) {
        return 0;
    }
    
    long long key = ((long long)i << 21) | ((long long)x << 14) | ((long long)y << 7) | (long long)z;

    if (mp.contains(key)) return mp[key];

 
    long long answer1 = solve(i + 1, x, y, z) - B[i];

   
    long long answer2 = 0;
    if (x > 0 && y > 0) {
        long long current_val = A[i] * (long long)(x - 1) * (y - 1) * z;
        answer2 = current_val + solve(i + 1, x - 1, y - 1, z);
    }

    
    long long answer3 = 0;
    if (y > 0 && z > 0) {
        long long current_val = A[i] * (long long)x * (y - 1) * (z - 1);
        answer3 = current_val + solve(i + 1, x, y - 1, z - 1);
    }

    
    return mp[key] = max({answer1, answer2, answer3});
}

int main() {
    int x, y, z;
    cin >> N >> x >> y >> z;
    A.resize(N); B.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    long long max_sum = solve(0, x, y, z);
    
    // Apply modulo at the very end
    long long MOD = 1e9 + 7;
    cout << (max_sum % MOD + MOD) % MOD << endl;

    return 0;
}
