#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Users
{

    string name;
    string id;
    string phone;
    string email;

public:
    void add_users(string name, string id, string phone, string email)
    {
        cout << "add_users called" << endl;
        this->name = name;
        this->id = id;
        this->phone = phone;
        this->email = email;
        cout << "add_users ends" << endl;
    }
    void display()
    {
        cout << "this->name = " << this->name << endl;
        cout << "this->id = " << this->id << endl;
        cout << "this->phone = " << this->phone << endl;
        cout << "this->email = " << this->email << endl;
    }
};

int main()
{
    vector<Users> users;
    Users s;
    s.add_users("Dhruv", "bt23cse135", "8459187658", "Dhruv@123");
    users.push_back(s);
    users[0].display();
    users[1].display();
    return 0;
}
