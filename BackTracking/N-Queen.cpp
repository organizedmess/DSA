#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string capitalizeName(string name) {
    int n = name.length();
    string temp_name = name;
    for (int i = 0; i < n; i++) {
        temp_name[i] = toupper(name[i]);
    }
    return temp_name;
}

string abbreviateName(string name) {
    string temp_name = name;
    vector<string> parts;
    int n = name.length();
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (name[i] == ' ') {
            parts.push_back(name.substr(s, i - s));
            s = i + 1;
        }
    }

    parts[1][0] = toupper(parts[1][0]);
    parts[1] = parts[1].substr(0, 1);

    if(parts.size() == 3)    
        temp_name = parts[0] + " " + parts[1] + "." + " " + parts[2];
    if(parts.size() == 2)    
        temp_name = parts[0] + " " + parts[1] + ".";
    
    for(char c: temp_name){
        cout<<c;
    }
    return temp_name;
}

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cin.ignore();  // Ignore the newline character
    
    string uppercase_name = capitalizeName(name);
    string abb_name = abbreviateName(name);
    cout << "Your abbreviated name is: " << abb_name << endl;
    // cout << "Your name in uppercase is: " << uppercase_name << endl;
    
    return 0;
}

