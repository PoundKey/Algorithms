#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Permutation of a string
void permute(string s, string res) {
   if (s.empty()) cout << res << " ";
   for(int i = 0; i < s.length(); i++ )
      permute(string(s).erase(i, 1), res + s[i]);
}

// Combination: without start parameter
void combine(string s, string res) {
    if (s.empty()) cout << res << " ";
    int len = s.size();
    for (int i = 0; i < s.size(); i++) {
        combine(s.substr(i + 1, len - i - 1), res + s[i]);
    }
}

// Combination: with start parameter == 0
void combineWith(string& s, string res, int start) {
    if (start >= s.size()) cout << res << " ";
    for (int i = start; i < s.size(); i++) {
        combineWith(s, res + s[i], i + 1);
    }
}

//Check if string t is a subsequence of s.
bool exisitSeq(string s, string t) {
    // O(n) Runtime
    if (t.empty()) return true;
    if (s.empty()) return false;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[j]) j++;
        if (j == t.size()) return true;
    }
    return false;
}

void test_exisitSeq() {
    cout << "Test Case 1: " << print(exisitSeq("", "")) << " >> Expect: Pass" << endl;
    cout << "Test Case 2: " << print(exisitSeq("def", "")) << " >> Expect: Pass" << endl;
    cout << "Test Case 3: " << print(exisitSeq("def", "ef")) << " >> Expect: Pass" << endl;
    cout << "Test Case 4: " << print(exisitSeq("def", "fv")) << " >> Expect: Fail" << endl;
    cout << "Test Case 5: " << print(exisitSeq("defaisveryclear", "face")) << " >> Expect: Pass" << endl;
}

/**
The following code is sort like backtracking, but the main purpose is to find
the word breaks in between, therefore substr function is used.
*/

//String backtracking, general version
void DFS(string s, int start) {
    if (start >= s.size()) return;
    int len = s.size() - start;
    for (int i = 1; i <= len; i++) {
        cout << s.substr(start, i) << " | ";
        DFS(s, start + i);
    }
}

//String backtracking, substr version // word break
void DFS(string s) {
    for (int i = 1; i <= s.size(); i++) {
        cout << s.substr(0, i) << " | ";
        DFS(s.substr(i, s.size() - i));
    }
}

