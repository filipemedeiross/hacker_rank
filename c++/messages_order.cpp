#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Message {
    int id;
    string text_;

    static int order;

    public: 
        Message (const string& text) : text_(text), id(order++) {}

        const string& get_text () {
            return text_;
        }

        int get_id () {
            return id;
        } 
};

bool operator< (Message& m1, Message& m2) {
    return (bool) (m1.get_id() < m2.get_id());
}

int Message::order = 0;

class MessageFactory {
    public:
        MessageFactory () {}

        Message create_message(const string& text) {
            return Message(text);
        }
};

class Recipient {
    vector<Message> messages_;

    public:
        Recipient () {}

        void receive (const Message& msg) {
            messages_.push_back(msg);
        }

        void print_messages () {
            fix_order();

            for (auto& msg : messages_)
                cout << msg.get_text() << endl;

            messages_.clear();
        }

    private:
        void fix_order () {
            sort(messages_.begin(), messages_.end());
        }
};

class Network {
    public:
        // Simulates the unpredictable network, where sent messages might arrive in unspecified order
        static void send_messages (vector<Message> messages, Recipient& recipient) {
            random_shuffle(messages.begin(), messages.end());  

            for (auto msg : messages)
                recipient.receive(msg);

        }
};

int main () {
    string text;
    vector<Message> messages;
    MessageFactory message_factory;
    Recipient recipient;
    
    while (getline(cin, text))
        messages.push_back(message_factory.create_message(text));

    Network::send_messages(messages, recipient);

    recipient.print_messages();
}