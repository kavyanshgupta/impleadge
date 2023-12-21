#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool static compare(string &a, string &b)
{
    return a.size() < b.size();
}
bool wordBreak(string s, unordered_map<string, int> &dict)
{
    vector<bool> dp(s.length() + 1, 0);
    dp[0] = true;
    for (int i = 1; i <= dp.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            string check = s.substr(j, i - j);
            if (dp[j] && dict.find(check) != dict.end() && check != s)
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[dp.size()];
}
vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    unordered_map<string, int> m;
    for (int i = 0; i < words.size(); i++)
        m[words[i]] = 1;
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        if (wordBreak(words[i], m))
            ans.push_back(words[i]);
    }
    return ans;
}
int main()
{
    auto started = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input_01.txt", "r", stdin);/*change input_01 to input_02 for second desired output*/
    freopen("output_01.txt", "w", stdout);
#endif
    vector<string> query;
    while (!cin.eof())
    {
        string s;
        cin >> s;
        query.push_back(s);
    }
    vector<string> ans = findAllConcatenatedWordsInADict(query);
    sort(ans.begin(), ans.end(), compare);
    int len = ans.size();
    cout << ans[len - 1];
    cout << "\n";
    cout << ans[len - 2];
    cout << "\n";
    auto ended = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::microseconds>(ended - started).count();
    time_taken *= 1e-3;
    cout << fixed << time_taken << setprecision(6) << " milli seconds";
    return 0;
}
