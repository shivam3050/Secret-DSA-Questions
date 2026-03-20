#include <bits/stdc++.h>
using namespace std;

int solution (vector<int> &A, vector<vector<int>> &queries) {
    int n = A.size();
    int q = queries.size();
    
    for(int i=0;i<q;i++){
        
        int l,r,x,y;
        l = queries[i][0];
        r = queries[i][1];
        x = queries[i][2];
        y = queries[i][3];
        
        for(int j=0;j<=(r-l);j++){
            A[l+j] = x + j * y;
        }
        
    }
    int sum = 0;
    for(auto x:A) sum+=x;
    
    
    
    return sum % (int)(1e9 + 7);
}

int main() {
    
	vector<int> A = {5,5,0,3,0};
	
	vector<vector<int>> queries = {{0,2,1,1}, {0,1,6,5}, {2,3,8,0}, {2,4,9,6},{3,4,8,9}};
	int sum = solution(A,queries);
	
	cout << sum << endl;
}
