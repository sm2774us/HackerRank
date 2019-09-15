#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 30
 * https://www.hackerrank.com/challenges/kindergarten-adventures/
 */

using namespace std;

vector <string> split_string(string);

/*
 * Complete the solve function below.
 */
int solve(vector<int> t) {
    /*
     * Return the ID
     */

    const int n = t.size();

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        if (t[i] < 1 || t[i] > n) {
            continue;
        }
        const int start = ((i + 1) - t[i] + n) % n;
        const int end = (i + 1) % n;

        arr[start]--;
        arr[end]++;


    }
    int max_cnt = INT_MIN;
    int id = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > max_cnt) {
            max_cnt = sum;
            id = i + 1;
        }
    }
    return id;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int t_count;
    cin >> t_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string t_temp_temp;
    getline(cin, t_temp_temp);

    vector <string> t_temp = split_string(t_temp_temp);

    vector<int> t(t_count);

    for (int t_itr = 0; t_itr < t_count; t_itr++) {
        int t_item = stoi(t_temp[t_itr]);

        t[t_itr] = t_item;
    }

    int id = solve(t);

    fout << id << "\n";

    fout.close();

    return 0;
}

vector <string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector <string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
