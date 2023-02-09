#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct tag {
    string name;

    vector <string> attr_names;
    vector <string> attr_values;
    
    tag* root = NULL;
    vector <tag*> nested;  // indicates whether the tag is nested
};

int main () {
    int n, q, p1, p2, v, i, j;
    string line;
    tag *t = NULL;
    vector <tag*> hrml;

    cin >> n >> q;
    cin.ignore();

    for (i=0; i<n; i++) {
        getline (cin, line);

        if (line[1] == '/') {
            t = t->root;
            continue;
        }

        if (t) {
            t->nested.push_back(new tag);
            t->nested.back()->root = t;

            t = t->nested.back();
        } else {
            t = new tag;

            hrml.push_back(t);            
        }

        p2 = line.find(' ');

        if (p2 == string::npos)
            t->name = line.substr(1, line.size() - 2);
        else
            t->name = line.substr(1, p2 - 1);

        while (p2 != string::npos) {
            p1 = p2 + 1;
            p2 = line.find(' ', p1 + 1);
            
            t->attr_names.push_back(line.substr(p1, p2 - p1));
            
            p1 = p2 + 4;
            p2 = line.find(' ', p1 + 1);
            
            if (p2 == string::npos)
                t->attr_values.push_back(line.substr(p1, line.size() - p1 - 2));
            else
                t->attr_values.push_back(line.substr(p1, p2 - p1 - 1));
        }       
    }

    for (i=0; i<q; i++) {
        getline (cin, line);

        t = NULL;
        v = 1;

        p1 = 0;
        p2 = line.find('.');

        if (p2 == string::npos)
            p2 = line.find('~');

        for (j=0; j<hrml.size() && t == NULL; j++) {
            if (hrml[j]->name.compare(line.substr(p1, p2)) == 0)
                t = hrml[j];
        }

        if (t == NULL) v = 0;

        if (v) {
            p1 = p2 + 1;
            p2 = line.find('.', p1);

            if (p2 == string::npos)
                p2 = line.find('~', p1);

            while (p2 != string::npos && v == 1) {
                v = 0;
                for (int j=0; j<t->nested.size() && v==0; j++) {
                    if (t->nested[j]->name.compare(line.substr(p1, p2 - p1)) == 0) {
                        v = 1;
                        t = t->nested[j];
                    }
                }

                p1 = p2 + 1;
                p2 = line.find('.', p1);

                if (p2 == string::npos)
                    p2 = line.find('~', p1);
            }                
        }

        if (v) {
            v = 0;                
            for (j=0; j<t->attr_names.size() && v == 0; j++) {
                if (t->attr_names[j].compare(line.substr(p1, line.size() - p1)) == 0)
                    v = 1;
            }
        }

        if (v)
            cout << t->attr_values[j-1] << endl;
        else
            cout << "Not Found!" << endl;
    }

    return 0;
}