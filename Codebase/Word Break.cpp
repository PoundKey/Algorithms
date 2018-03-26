// just realized that word break is very different from combination. 
// the key is to pick a pivot position, start, and for all possible lengths i -> [1, x]
// set the prefix [start, start + i - 1], and recursively call on the rest f(start + i)
// CORE: once we know the start position and the length of the prefix, we could figure out
// the start position of the suffix, which is: start + i

void WordBreak(string str)
{
    if (str.empty()) return;
    for (int i = 1; i <= str.size(); i++)
    {
        cout << str.substr(0, i) << " ";
        WordBreak(str.substr(i));
    }
}

void PrintSubArray(const vector<int>& v, int start, int len)
{
    if (start + len > v.size()) return;
    string res;
    for (int i = start; i < start + len; i++)
    {
        res += to_string(v[i]);
    }
    cout << res << " ";
}

void WordBreak(const vector<int>& v, int startWith = 0)
{
    if (startWith >= v.size()) return;
    for (int i = 1; i <= v.size() - startWith; i++) // length
    {
        PrintSubArray(v, startWith, i);
        WordBreak(v, startWith + i);
    }
}

void PrintSequence(int start, int len)
{
    string res;
    while (len > 0)
    {
        res += to_string(start);
        --len;
        ++start;
    }
    cout << res << " ";
}

void WordBreak(int n, int startWith = 1)
{
    if (startWith > n) return;
    for (int i = 1; i <= (n - startWith + 1); i++)
    {
        PrintSequence(startWith, i);
        WordBreak(n, startWith + i);
    }
}

// Test cases
void main()
{
    cout << "<<<============== Word Break String =============>>>" << endl;
    WordBreak("123");
    cout << endl;
    WordBreak("1234");
    cout << endl;
    WordBreak("12345");
    cout << endl;

    cout << "<<<============== Word Break Vector =============>>>" << endl;
    vector<int> wbv1 = { 1, 2, 3 };
    vector<int> wbv2 = { 1, 2, 3, 4 };
    vector<int> wbv3 = { 1, 2, 3, 4, 5 };
    WordBreak(wbv1);
    cout << endl;
    WordBreak(wbv2);
    cout << endl;
    WordBreak(wbv3);
    cout << endl;

    cout << "<<<============== Word Break Natural Number =============>>>" << endl;
    WordBreak(3);
    cout << endl;
    WordBreak(4);
    cout << endl;
    WordBreak(5);
    cout << endl;

/**
All there test above outputs:
<<<============== Word Break String =============>>>
1 2 3 23 12 3 123
1 2 3 4 34 23 4 234 12 3 4 34 123 4 1234
1 2 3 4 5 45 34 5 345 23 4 5 45 234 5 2345 12 3 4 5 45 34 5 345 123 4 5 45 1234 5 12345

<<<============== Word Break Vector =============>>>
1 2 3 23 12 3 123
1 2 3 4 34 23 4 234 12 3 4 34 123 4 1234
1 2 3 4 5 45 34 5 345 23 4 5 45 234 5 2345 12 3 4 5 45 34 5 345 123 4 5 45 1234 5 12345

<<<============== Word Break Natural Number =============>>>
1 2 3 23 12 3 123
1 2 3 4 34 23 4 234 12 3 4 34 123 4 1234
1 2 3 4 5 45 34 5 345 23 4 5 45 234 5 2345 12 3 4 5 45 34 5 345 123 4 5 45 1234 5 12345
*/

}
