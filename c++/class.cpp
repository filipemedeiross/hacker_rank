#include <iostream>
#include <sstream>

using namespace std;

class Student {
    private:
        int age;
        int standard;
        string first_name;
        string last_name;
    
    public:
        void set_age (int age) {
            this->age = age;
        }

        void set_standard (int standard) {
            this->standard = standard;
        }

        void set_first_name (string first_name) {
            this->first_name = first_name;
        }

        void set_last_name (string last_name) {
            this->last_name = last_name;
        }

        int get_age () {
            return age;
        }

        int get_standard () {
            return standard;
        }

        string get_first_name () {
            return first_name;
        }

        string get_last_name () {
            return last_name;
        }

        string to_string () {
            stringstream description;

            description << age << ",";
            description << first_name << ",";
            description << last_name << ",";
            description << standard;

            return description.str(); 
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    Student st;
    
    cin >> age >> first_name >> last_name >> standard;
    
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << endl;
    cout << st.get_last_name() << ", " << st.get_first_name() << endl;
    cout << st.get_standard() << endl;
    cout << endl;
    
    cout << st.to_string();
    
    return 0;
}