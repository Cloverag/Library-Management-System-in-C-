#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <typeinfo>
using namespace std;

int current_no_users = 0;
int current_no_books = 0;

class Users
{
private:
    string name;
    string id;
    string phone;
    string email;
    int current_books_no;
    int all_books_no;
    int current_books_names;
    int all_books_names;

public:
    Users()
    {
        cout << "Users default constructor called" << endl;
    }
    Users(string name, string id, string email, string phone)
    {
        this->name = name;
        this->phone = phone;
        this->id = id;
        this->email = email;
        this->current_books_no = 0;
        this->all_books_no = 0;
        this->current_books_names = 0;
        this->all_books_names = 0;
    }
    Users(string name, string id, string email, string phone, int current_books_no, int all_books_no, int current_books_names, int all_books_names)
    {
        this->name = name;
        this->phone = phone;
        this->id = id;
        this->email = email;
        this->current_books_no = current_books_no;
        this->all_books_no = all_books_no;
        this->current_books_names = current_books_names;
        this->all_books_names = all_books_names;
    }
    Users(string arr[])
    {
        cout << "Users array contructor called" << endl;
        this->name = arr[0];
        this->id = arr[1];
        this->phone = arr[2];
        this->email = arr[3];
        this->current_books_no = stoi(arr[4]);
        this->all_books_no = stoi(arr[5]);
        this->current_books_names = stoi(arr[6]);
        this->all_books_names = stoi(arr[7]);
    }
    void add_new_users(string name, string id, string phone, string email)
    {
        cout << endl
             << "add_new_users called" << endl;
        this->name = name;
        this->id = id;
        this->phone = phone;
        this->email = email;
        this->current_books_no = 0;
        this->all_books_no = 0;
        this->current_books_names = 0;
        this->all_books_names = 0;
    }
    void display_user_data()
    {
        cout << endl
             << "display_user_data called" << endl;
        cout << "name = " << this->name << endl;
        cout << "id = " << this->id << endl;
        cout << "phone = " << this->phone << endl;
        cout << "email = " << this->email << endl;
        cout << "current_books_no = " << this->current_books_no << endl;
        cout << "all_books_no = " << this->all_books_no << endl;
        cout << "current_books_names = " << this->current_books_names << endl;
        cout << "all_books_names = " << this->all_books_names << endl
             << endl;
    }
};
class Books
{
private:
    string name;
    string author;
    string genre;
    string subject;
    int overall_allocate_users;
    int ongoing_allocate_users;

public:
    Books()
    {
        cout << "Books default constructor called" << endl;
    }
    Books(string name, string author, string genre, string subject, int overall_allocate_users, int ongoing_allocate_users)
    {
        this->name = name;
        this->author = author;
        this->genre = genre;
        this->subject = subject;
        this->overall_allocate_users = overall_allocate_users;
        this->ongoing_allocate_users = ongoing_allocate_users;
    }
    Books(string name, string author, string genre, string subject)
    {
        this->name = name;
        this->author = author;
        this->genre = genre;
        this->subject = subject;
        this->overall_allocate_users = 0;
        this->ongoing_allocate_users = 0;
    }
    Books(string arr[])
    {
        cout << "Users array contructor called" << endl;
        this->name = arr[0];
        this->author = arr[1];
        this->genre = arr[2];
        this->subject = arr[3];
        this->overall_allocate_users = stoi(arr[4]);
        this->ongoing_allocate_users = stoi(arr[5]);
    }
    void display_book_data()
    {
        cout << endl
             << "display_user_data called" << endl;
        cout << "name = " << this->name << endl;
        cout << "author = " << this->author << endl;
        cout << "genre = " << this->genre << endl;
        cout << "subject = " << this->subject << endl;
        cout << "overall_allocate_users = " << this->overall_allocate_users << endl;
        cout << "ongoing_allocate_users = " << this->ongoing_allocate_users << endl
             << endl;
    }
};

void Add_Book(vector<Books> books);
void Remove_Book();
void Add_User(vector<Users> users);
void Remove_User();
void Allocate_Book_to_User();
void Deallocate_Book_to_User();
void History_of_User();
int get_no_of_lines(ifstream &User_data);
void Update_users(vector<Users> &users);
void Update_Books(vector<Books> &books);

int current_no = 0;

void Update_Books(vector<Books> &books)
{
    cout << "Update_Books called" << endl;
    ifstream User_data("Book_data.csv");
    string s = "";
    string arr[6];
    getline(User_data, s);
    s = "";
    while (getline(User_data, s))
    {
        int i = 0;
        cout << "i = " << i << endl;
        char del = ',';
        stringstream ss(s);
        string word;
        while (!ss.eof())
        {
            getline(ss, word, del);
            cout << word << " - ";
            arr[i] = word;
            i++;
        }
        // int index = stoi(arr[0]);
        // cout << "index = " << index << endl;
        Books temp(arr);
        // temp.display_user_data();
        books.push_back(temp);
        books[current_no_books].display_book_data();
        current_no_books++;
    }
    User_data.close();
}
void Update_users(vector<Users> &users)
{
    cout << "Update_users called" << endl;
    ifstream User_data("User_data.csv");
    string s = "";
    string arr[7];
    getline(User_data, s);
    s = "";
    while (getline(User_data, s))
    {
        int i = 0;
        cout << "i = " << i << endl;
        char del = ',';
        stringstream ss(s);
        string word;
        while (!ss.eof())
        {
            getline(ss, word, del);
            cout << word << " - ";
            arr[i] = word;
            i++;
        }
        // int index = stoi(arr[0]);
        // cout << "index = " << index << endl;
        Users temp(arr);
        // temp.display_user_data();
        users.push_back(temp);
        users[current_no_users].display_user_data();
        current_no_users++;
    }
    User_data.close();
}
int get_no_of_lines(ifstream &file_name)
{
    cout << "get_no_of_lines called" << endl;
    int no_of_lines = 0;
    string s = "";
    while (getline(file_name, s))
    {
        no_of_lines++;
    }
    return no_of_lines;
}

void Add_Book(vector<Books> books)
{
    ifstream Book_data("Book_data.csv");
    string s = "", Name, Author = "", Subject = "", Genre = "";
    cout << "Book Name : ";
    cin.ignore();
    getline(cin, Name);
    cout << "Author : ";
    getline(cin, Author);
    cout << "GENRE : ";
    getline(cin, Genre);
    cout << "SUBJECT : ";
    getline(cin, Subject);
    cout << "before s = " << s << endl;
    s = Name + "," + Author + "," + Genre + "," + Subject + ",0,0\n";
    Book_data.close();
    Books temp(Name, Author, Genre, Subject);
    books.push_back(temp);
    books[current_no_books].display_book_data();
    current_no_books++;
    ofstream Book_data_edit("Book_data.csv", ios::app);
    Book_data_edit << s;
    Book_data_edit.close();
}
void Remove_Book()
{
    cout << "Remove_Book called" << endl;
}
void Add_User(vector<Users> users)
{
    cout << "Add_User called" << endl;
    ofstream User_data_edit("User_data.csv", ios::app);
    string s = "", name, id, phone, email;
    cout << "Name : ";
    cin >> name;
    cout << "ID : ";
    cin >> id;
    cout << "Phone : ";
    cin >> phone;
    cout << "Email : ";
    cin >> email;
    Users temp(name, id, phone, email);
    users.push_back(temp);
    users[current_no_users].display_user_data();
    current_no_users++;
    s = name + "," + id + "," + phone + "," + email + ",0,0,0,0\n";
    User_data_edit << s;
    User_data_edit.close();
}
void Remove_User()
{
    cout << "Remove_User called" << endl;
}
void Allocate_Book_to_User()
{
    cout << "Allocate_Book_to_User called" << endl;
}
void Deallocate_Book_to_User()
{
    cout << "Deallocate_Book_to_User called" << endl;
}
void History_of_User()
{
    cout << "Histrory_of_User called" << endl;
}

int main()
{
    vector<Users> users;
    vector<Books> books;
    Update_users(users);
    Update_Books(books);
    int n;
    while (n != 0)
    {
        cout << " *************************************************** " << endl
             << endl;
        cout << "> Enter 0 to exit" << endl;
        cout << "> Enter 1 to Add Book" << endl;
        cout << "> Enter 2 to Remove Book" << endl;
        cout << "> Enter 3 to Add User" << endl;
        cout << "> Enter 4 to Remove User" << endl;
        cout << "> Enter 5 to Allocate Book to User" << endl;
        cout << "> Enter 6 to Deallocate Book to User" << endl;
        cout << "> Enter 7 to History of User" << endl
             << endl;
        cout << " *************************************************** " << endl;
        cout << " Enter your choice :: ";
        cin >> n;
        switch (n)
        {
        case 0:
            return 0;
            break;
        case 1:
            Add_Book(books);
            break;
        case 2:
            Remove_Book();
            break;
        case 3:
            Add_User(users);
            break;
        case 4:
            Remove_User();
            break;
        case 5:
            Allocate_Book_to_User();
            break;
        case 6:
            Deallocate_Book_to_User();
            break;
        case 7:
            History_of_User();
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}