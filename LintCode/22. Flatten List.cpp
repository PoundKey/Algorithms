class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> res;
        if (nestedList.empty()) return res;
        DFS(res, nestedList);
        return res;
    }
    
    void DFS(vector<int>& res, const vector<NestedInteger>& list) {
        if (list.empty()) return;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].isInteger()) {
                res.push_back(list[i].getInteger());
            } else {
                DFS(res, list[i].getList());
            }
        }
    }
};
