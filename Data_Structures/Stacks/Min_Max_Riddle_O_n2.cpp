#include <bits/stdc++.h>
/*
 * Difficulty Medium
 * Max Score 60
 * https://www.hackerrank.com/challenges/min-max-riddle/
 * help this:
 * https://www.hackerrank.com/challenges/min-max-riddle/forum/comments/486316
 * https://www.hackerrank.com/challenges/min-max-riddle/forum/comments/495852
 * https://www.geeksforgeeks.org/the-stock-span-problem/
 */

using namespace std;

vector <string> split_string(string);

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    vector<long> result;
    for (size_t win_sz = 1; win_sz <= arr.size(); win_sz++) {

        deque<int> dq(win_sz);
        long max_win = 0;

        size_t i;
        for (i = 0; i < win_sz; i++) {

            while ((!dq.empty()) && arr[i] < arr[dq.back()])
                dq.pop_back(); // Remove from rear
            // Add new element at rear of queue
            dq.push_back(i);
        }

        for (; i < arr.size(); ++i) {


            max_win = max(max_win, arr[dq.front()]);


            // Remove the elements which are out of this window
            while ((!dq.empty()) && dq.front() <= i - win_sz)
                dq.pop_front(); // Remove from front of queue

            while ((!dq.empty()) && arr[i] < arr[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }


        max_win = max(max_win, arr[dq.front()]);

        result.push_back(max_win);

    }

    return result;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector <string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
