//https://vjudge.net/problem/HackerRank-find-the-running-median
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<double> runningMedian(vector<int> a) {
    int n = a.size();
    priority_queue<double, vector<double>, greater<double>> right;
    priority_queue<double> left;
    vector<double> ans;
   
    double cur = 0;
    for(int i = 0; i < n; i++){
        double x = a[i];
        if(left.size() > right.size()){
            if(x < cur){
                right.push(left.top());
                left.pop();
                left.push(x);
            }else{
                right.push(x);
            }
            cur = (left.top() + right.top()) / 2.0;
        }else if(left.size() == right.size()){
            if(x < cur){
                left.push(x);
                cur = left.top();
            }else{
                right.push(x);
                cur = right.top();
            }
        }else{
            if(x > cur){
                left.push(right.top());
                right.pop();
                right.push(x);
            }else{
                left.push(x);
            }
            cur = (left.top() + right.top()) / 2.0;
        }
        ans.push_back(cur);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
