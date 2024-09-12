#include <iostream>
#include <string>

using namespace std;

enum MessageType
{
    Basic = 7,
    Warning = 14,
    Error = 12,
    Succes = 10,
    Info = 11,
    Debug = 13
};

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Message
{
private:
    string text;
    MessageType type;

    void reset_color()
    {
        SetConsoleTextAttribute(hConsole, MessageType::Basic);
    }
public:
    Message() {
        text = "";
        type = MessageType::Basic;
    }
    Message(string text, MessageType type) {
        this->text = text;
        this->type = type;
    }
    void setText(string text) {
        this->text = text;
    }
    void setType(MessageType type) {
        this->type = type;
    }
    string getText() {
        return text;
    }
    MessageType getType() {
        return type;
    }

    void show()
    {
        SetConsoleTextAttribute(hConsole, type);
        cout << text;
        reset_color();
    }
    void show_line()
    {
        SetConsoleTextAttribute(hConsole, type);
        cout << text << endl;
        reset_color();
    }
    ~Message() {
        SetConsoleTextAttribute(hConsole, MessageType::Debug);
        cout << "Destructor called" << endl;
        reset_color();
    }
};

int main() {
    //Message message; //object (instance) of class Message
    Message* message = new Message("Hello World!", MessageType::Succes); //pointer to object (instance) of class Message
    message->show_line();
    message->setType(MessageType::Warning);
    message->show_line();
    message->setType(MessageType::Debug);
    message->show_line();
    delete message;
    return 0;
}