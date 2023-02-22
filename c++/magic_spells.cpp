#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Spell { 
    string scrollName;

    public:
        Spell () : scrollName("") {}
        Spell (string name): scrollName(name) {}
        
        virtual ~Spell() {}

        string revealScrollName () {
            return scrollName;
        }
};

class Fireball : public Spell { 
    int power;
    
    public:
        Fireball (int power) : power(power) {}
        
        void revealFirepower () {
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    int power;
    
    public:
        Frostbite (int power) : power(power) {}

        void revealFrostpower () {
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    int power;

    public:
        Thunderstorm (int power) : power(power) {}
        
        void revealThunderpower () {
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    int power;
    
    public:
        Waterbolt (int power) : power(power) {}
        
        void revealWaterpower () {
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;

        static string read () {
            return journal;
        }
};
string SpellJournal::journal = "";

void counterspell (Spell *spell) {
    if (dynamic_cast<Fireball*> (spell))
        ((Fireball*) spell)->revealFirepower();
    else if (dynamic_cast<Frostbite*> (spell))
        ((Frostbite*) spell)->revealFrostpower();
    else if (dynamic_cast<Waterbolt*> (spell))
        ((Waterbolt*) spell)->revealWaterpower();
    else if (dynamic_cast<Thunderstorm*> (spell))
        ((Thunderstorm*) spell)->revealThunderpower();
    else {
        string name = spell->revealScrollName();
        string journal = SpellJournal::read();
        int m = name.length();
        int n = journal.length();

        int **L = new int*[m + 1];
        for (int i = 0; i < m + 1; i++)
            L[i] = new int[n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (name[i - 1] == journal[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }

        cout << L[m][n] << endl;
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s;
            int power;
            
            cin >> s;
            cin >> power;

            if (s == "fire")
                spell = new Fireball(power);
            else if (s == "frost")
                spell = new Frostbite(power);
            else if (s == "water")
                spell = new Waterbolt(power);
            else if (s == "thunder")
                spell = new Thunderstorm(power);
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }

            return spell;
        }
};

int main () {
    int T;
    Wizard Arawn;
    Spell *spell;

    cin >> T;
    
    while (T--) {
        spell = Arawn.cast();
        counterspell(spell);
    }

    return 0;
}
