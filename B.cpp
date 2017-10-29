#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    size_t n;
    while (cin >> n) {
        map<char, vector<string>> writers_to_books;
        for (size_t i = 0; i < n; ++i) {
            string code;
            string writers;
            cin >> code >> writers;
            for_each(writers.begin(), writers.end(), [&](char name) {
                writers_to_books[name].push_back(code);
            });
        }
        auto the_writer = max_element(writers_to_books.begin(), writers_to_books.end(),
                                      [](pair<char, vector<string>> writer1, pair<char, vector<string>> writer2) {
                                          return writer1.second.size() < writer2.second.size();
                                      });
        cout << the_writer->first << endl;
        cout << the_writer->second.size() << endl;
        for (auto &&item : the_writer->second) {
            cout << item << endl;
        }
    }
    return 0;
}