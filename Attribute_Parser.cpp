// Problem: Attribute Parser
// Platform: HackerRank

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>        
#include <sstream>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();

    map<string, string> mp;
    vector<string> tags;

    for(int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        if(line[1] == '/') {
            tags.pop_back();
        } else {
            line.erase(remove(line.begin(), line.end(), '<'), line.end());
            line.erase(remove(line.begin(), line.end(), '>'), line.end());

            stringstream ss(line);
            string tag;
            ss >> tag;

            tags.push_back(tag);

            string path = "";
            for(int i = 0; i < tags.size(); i++) {
                if(i > 0) path += ".";
                path += tags[i];
            }

            string attr, eq, val;
            while(ss >> attr >> eq >> val) {
                val = val.substr(1, val.size() - 2);
                mp[path + "~" + attr] = val;
            }
        }
    }

    for(int i = 0; i < q; i++) {
        string query;
        getline(cin, query);

        if(mp.find(query) != mp.end())
            cout << mp[query] << endl;
        else
            cout << "Not Found!" << endl;
    }
    return 0;
}
