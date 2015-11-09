// Thoughts: Things to look out.
// 1. add "/" to the orginal path so path like "/home" will be pushed into dir
// 2. use "/" as the end symbol for single folder's name.
// 3. remeber to clear the name variable after each action.
// 4. corner case like "////", if dir.empty() return "/"
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        string name;
        path += "/";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (name.empty()) {
                    continue;
                } else if (name == ".") {
                    name.clear();
                } else if (name == "..") {
                    if (!dir.empty()) dir.pop_back();
                    name.clear();
                } else {
                    dir.push_back(name);
                    name.clear();
                }
            } else {
                name += path[i];
            }
        }
        string res;
        for (int i = 0; i < dir.size(); i++) {
            res += "/" + dir[i];
        }
        
        return res.empty() ? "/" : res;        

    }
};
