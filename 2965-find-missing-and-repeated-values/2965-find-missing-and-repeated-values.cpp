class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int total = n*n;
        int ans[2];

        unordered_set<int> seen;
        int repeated = -1;
        int Exp_sum = (total*(total+1))/2;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int val = grid[i][j];
                if(seen.count(val)){
                    repeated = val;
                    ans[0] = repeated;
                }else{
                    seen.insert(val);
                }
            }
        }
        int actual_sum=0;
        for(int x : seen){
             actual_sum += x;
        }
        int b = Exp_sum - actual_sum;
        ans[1] = b;
        return{repeated,b};
    }
};