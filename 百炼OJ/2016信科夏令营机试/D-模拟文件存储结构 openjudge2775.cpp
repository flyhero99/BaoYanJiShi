#include <bits/stdc++.h>
using namespace std;

struct Dir {
    string name;
    vector<string> files;
    vector<Dir> dirs;
};

Dir input(string name) {
    Dir dir;

    string str;
    cin >> str;

    if(str == "#") return dir;

    dir.name = name;

    while(str != "*" && str != "]") {
        if(str[0] == 'f') dir.files.push_back(str);
        else dir.dirs.push_back(input(str));

        cin >> str;
    }
    
    return dir;
}

void iprintf(int level, string str) {
    int i;
    for(i = 0; i < level; ++i) {
        cout << "|     ";
    }
    cout << str << endl;
    return;
}

void output(Dir dir, int level) {
    iprintf(level,dir.name);

    int v_i;
    for(v_i = 0; v_i != dir.dirs.size(); ++v_i) output(dir.dirs[v_i],level + 1);

    sort(dir.files.begin(),dir.files.end());
    for(v_i = 0; v_i != dir.files.size(); ++v_i) iprintf(level,dir.files[v_i]);

    return;
}

int main() {
    int count = 1;

    Dir dir = input("ROOT");
    while(dir.name == "ROOT") {

        cout << "DATA SET " << count++ << ":" << endl;
        output(dir,0);
        cout << endl;

        dir = input("ROOT");
    }

    return 0;
}