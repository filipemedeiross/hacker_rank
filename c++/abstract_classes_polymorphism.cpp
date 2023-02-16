#include <string>
#include <map>
#include <iostream>

using namespace std;

struct Node {
    int key;
    int value;
    
    Node* prev;
    Node* next;
    
    Node (Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val) {};
    Node (int k, int val) : Node (NULL, NULL, k, val) {};
};

class Cache {
    protected:
        int cp;  // capacity
        
        map<int, Node*> mp;  // map the key to the node in the linked list
        
        Node* head;  // double linked list head pointer
        Node* tail;  // double linked list tail pointer

        virtual void set(int, int) = 0;  // set function
        virtual int get(int) = 0;  // get function
};

class LRUCache : public Cache {
    int size;

    public:
        LRUCache (int c) {
            size = 0;
            cp = c;

            head = NULL;
            tail = NULL;
        };

        void set(int k, int v) {
            map<int, Node*>::iterator it = mp.find(k);

            if (it == mp.end()) {
                Node* new_node = new Node(NULL, head, k, v);
                mp.insert(make_pair(k, new_node));

                if (size)
                    head->prev = new_node;
                else
                    tail = new_node;
                    
                head = new_node;

                if (size == cp)
                    update_tail();  
                else
                    size++;
            } else {
                it->second->value = v;

                if (it->second != head)
                    update_head(it->second);
            }
        };

        int get(int k) {
            map<int, Node*>::iterator it = mp.find(k);

            if (it == mp.end())
                return -1;
            
            if (it->second != head)
                update_head(it->second);

            return it->second->value;
        };

        void update_head (Node* pos_node) {
            pos_node->prev->next = pos_node->next;

            if (pos_node == tail)
                tail = pos_node->prev;
            else
                pos_node->next->prev = pos_node->prev;

            pos_node->prev = NULL;
            pos_node->next = head;

            head->prev = pos_node;
            head = pos_node;
        }

        void update_tail () {
            Node* aux = tail;

            tail = tail->prev;
            tail->next = NULL;

            mp.erase(aux->key);
        }
};

int main() {
    int n, capacity, i, key, value;
    string command;
    LRUCache *l;

    cin >> n >> capacity;
   
    l  = new LRUCache(capacity);
    for (i = 0; i < n; i++) {
        cin >> command;

        if (command == "get") {
            cin >> key;

            cout << l->get(key) << endl;
        } else if (command == "set") {
            cin >> key >> value;
            
            l->set(key, value);
        }
   }

   return 0;
}