// 1. foreach killed process i, we push the child process to be killed to the queue, if any.
// 2. while queue is not empty, continue to do this. This is sort like BFS, I think.
// 3. time complexity O(n^2), can we do better?
class Solution {
public:
    /**
     * @param pid: the process id
     * @param ppid: the parent process id
     * @param kill: a PID you want to kill
     * @return: a list of PIDs of processes that will be killed in the end
     */
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        vector<int> res;
        if (pid.empty()) return res;
        queue<int> q;
        q.push(kill);
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            res.push_back(k); // save the killed process
            for (int i = 0; i < ppid.size(); i++)
            {
                if (ppid[i] == k)
                {
                    // we want to kill the child process
                    q.push(pid[i]);
                }
            }
        }
        return res;
    }
    
    // 1. how about take the DFS approach? record each ppid's child pid in a map<int, vector<int>>
    // 2. foreach process to be killed, recursively go into it's children process, if any
    // 3. runtime complexity: O(n), space complexity, O(n)
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        vector<int> res;
        if (pid.empty()) return res;
        map<int, vector<int>> map;
        for (int i = 0; i < ppid.size(); i++)
        {
            map[ppid[i]].push_back(pid[i]);
        }
        Traverse(map, res, kill);
        return res;
    }
    void Traverse(map<int, vector<int>>& m, vector<int>& res, int kill)
    {
        res.push_back(kill);
        vector<int> children = m[kill];
        for (int i = 0; i < children.size(); ++i)
        {
            Traverse(m, res, children[i]);
        }
    }
};

