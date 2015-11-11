// Thoughts: Greedy Algorithm
// 1. if the total gas is less than the total cost, there'll be no circular route
// 2. if we cannot reach station i + 1 from station i, meaning that we will have to
// 3. start i + 1 all over again, because all stations before i will not be able to reach i + 1
// 4. We are greey about the gas accumulated from each station, totalGas += gas[i] - cost[i]
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (sum(gas) < sum(cost)) return -1;
        int totalGas = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i] - cost[i];
            if (totalGas < 0) {
                start = i + 1;
                totalGas = 0;
            }
        }
        return start;
        
    }
    int sum(vector<int>& vec) {
        int res = 0;
        for (auto &elem : vec) {
            res += elem;
        }
        return res;
    }
};
