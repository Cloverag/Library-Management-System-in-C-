#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <typeinfo>
#include <ctime>

using namespace std;

int current_no_users = 0;
int current_no_books = 0;
int current_no_issued_books = 0;

class Issued_books
{
    string issue_id;
    string book_name;
    string id;
    string issue_date;
    string return_date;

    string generate_issued_id(string name, string idd)
    {
        time_t timestamp;
        cout << "timestamp =" << timestamp << endl;
        time(&timestamp);
        cout << "timestamp =" << timestamp << endl;
        string pass = to_string(timestamp) + name[0] + to_string(idd[0]);
        cout << "Generated issued id = " << pass << "|" << endl;
        // pass[pass.size() - 1] = '\0';
        return pass;
    }

public:
    Issued_books(string name, string idd)
    {
        time_t timestamp;
        time(&timestamp);
        string temp = ctime(&timestamp);
        if (temp[temp.length() - 1] == '\n')
        {
            cout << "If called" << endl;
            temp[temp.length() - 1] = NULL;
        }
        this->issue_id = this->generate_issued_id(name, idd);
        this->book_name = name;
        this->id = idd;
        this->issue_date = temp;
        this->return_date = "-";
        cout << "this->issue_date + this->return_date = " << this->issue_date + this->return_date << endl;
    }
    Issued_books(string arr[])
    {
        this->issue_id = arr[0];
        this->book_name = arr[1];
        this->id = arr[2];
        this->issue_date = arr[3];
        this->return_date = arr[4];
    }
    string get_issued_book_data()
    {
        string s = "";
        s = this->issue_id + "," + this->book_name + "," + this->id + "," + this->issue_date + "," + this->return_date;
        return s;
    }
    string get_issued_id()
    {
        return this->issue_id;
    }
};
class Users
{
private:
    string name;
    string phone;
    string email;
    int current_books_no;
    int all_books_no;
    vector<string> current_books_issue_id;
    vector<string> all_books_issue_id;

public:
    string id;
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
    }
    Users(string name, string id, string email, string phone, int current_books_no, int all_books_no, int current_books_issue_id, int all_books_issue_id)
    {
        this->name = name;
        this->phone = phone;
        this->id = id;
        this->email = email;
        this->current_books_no = current_books_no;
        this->all_books_no = all_books_no;
        // this->current_books_names = current_books_names;
        // this->all_books_names = all_books_names;
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
        this->add_current_issued_books(arr[6]);
        this->add_all_issued_books(arr[7]);
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
        // this->current_books_issue_id = 0;
        // this->all_books_issue_id = 0;
    }

    void add_current_issued_books(string arr)
    {
        if (arr == "NULL")
        {
            return;
        }
        cout << "add_current_issued_books called" << endl;
        cout << "arr = " << arr << endl;
        stringstream s(arr);
        char del = '|';
        string word;
        while (!s.eof())
        {
            getline(s, word, del);
            cout << "word = " << word << endl;
            this->current_books_issue_id.push_back(word);
        }
    }
    void add_all_issued_books(string arr)
    {
        if (arr == "NULL")
        {
            return;
        }
        cout << "add_all_issued_books called" << endl;
        cout << "arr = " << arr << endl;
        stringstream s(arr);
        char del = '|';
        string word;
        while (!s.eof())
        {
            getline(s, word, del);
            cout << "word = " << word << endl;
            this->all_books_issue_id.push_back(word);
        }
    }
    string get_current_issued_book_ids_in_string()
    {
        string s = "";
        int j = current_books_issue_id.size(), i = 0;
        while (i < j)
        {
            s = s + current_books_issue_id[i];
            i++;
            if (i < j)
            {
                s = s + "|";
            }
        }
        return s;
    }
    string get_all_issued_book_ids_in_string()
    {
        string s = "";
        int j = all_books_issue_id.size(), i = 0;
        while (i < j)
        {
            s = s + all_books_issue_id[i];
            i++;
            if (i < j)
            {
                s = s + "|";
            }
        }
        return s;
    }
    void display_user_data()
    {
        cout << endl;
        //  << "display_user_data called" << endl;
        cout << "Name = " << this->name << endl
             << "Id = " << this->id << endl
             << "Phone = " << this->phone << endl
             << "Email = " << this->email << endl
             << "Current_books_no = " << this->current_books_no << endl
             << "All_books_no = " << this->all_books_no << endl
             << "Current_books_issue_id = " << this->get_current_issued_book_ids_in_string() << endl
             << "All_books_issue_id = " << this->get_all_issued_book_ids_in_string() << endl
             << endl;
    }
    string get_data_in_string()
    {
        // cout << "get_data_in_string called" << endl;
        string s = "";
        s = this->name + "," + this->id + "," + this->phone + "," + this->email + "," + to_string(this->current_books_no) + "," + to_string(this->all_books_no) + "," + this->get_current_issued_book_ids_in_string() + "," + this->get_all_issued_book_ids_in_string();
        return s;
    }
    void add_new_issued_books(string book_name)
    {
        add_current_issued_books(book_name);
        add_all_issued_books(book_name);
    }
    void show_all_issued_books_id()
    {
        cout << endl
             << "show_all_issued_books_id called" << endl
             << endl;
        int i = 0;
        while (i < this->all_books_issue_id.size())
        {
            cout << "->  " << this->all_books_issue_id[i] << endl;
            i++;
        }
        cout << endl
             << endl;
    }
    void show_current_issued_books_id()
    {
        cout << endl
             << "show_current_issued_books_id called" << endl
             << endl;
        int i = 0;
        while (i < this->current_books_issue_id.size())
        {

            cout << i << " ->  " << this->current_books_issue_id[i] << endl;
            i++;
        }
        cout << endl
             << endl;
    }
};
class Books
{
private:
    string author;
    string genre;
    string subject;
    int overall_allocate_users;
    int ongoing_allocate_users;

public:
    string name;
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
        cout << endl;
        //  << "display_user_data called" << endl;
        cout << "Name = " << this->name << endl
             << "Author = " << this->author << endl
             << "Genre = " << this->genre << endl
             << "Subject = " << this->subject << endl
             << "Overall_allocate_users = " << this->overall_allocate_users << endl
             << "Ongoing_allocate_users = " << this->ongoing_allocate_users << endl;
        cout << endl;
    }
    string get_data_in_string()
    {
        string s = "";
        s = name + "," + author + "," + genre + "," + subject + "," + to_string(overall_allocate_users) + "," + to_string(ongoing_allocate_users);
        return s;
    }
    void add_ongoing_allocate_users()
    {
        this->ongoing_allocate_users++;
        this->overall_allocate_users++;
    }
    void remove_ongoing_allocate_users()
    {
        this->ongoing_allocate_users++;
    }
};

class Horror_book : public Books
{
    string horror_book_name;

public:
    static int no_of_horror_books;
    Horror_book(string name, string author, string genre, string subject, int overall_allocate_users, int ongoing_allocate_users) : Books(name, author, genre, subject, overall_allocate_users, ongoing_allocate_users)
    {
        this->horror_book_name = name;
        if (Horror_book ::no_of_horror_books == 0 || Horror_book ::no_of_horror_books == NULL)
        {
            Horror_book ::no_of_horror_books == 1;
        }
        else
        {
            Horror_book ::no_of_horror_books++;
        }
    }
};
class Mystery_book : public Books
{
    string mystery_book_name;
    static int no_of_mystery_books;

public:
    Mystery_book(string name, string author, string genre, string subject, int overall_allocate_users, int ongoing_allocate_users) : Books(name, author, genre, subject, overall_allocate_users, ongoing_allocate_users)
    {
        this->mystery_book_name = name;
        if (Mystery_book ::no_of_mystery_books == 0 || Mystery_book ::no_of_mystery_books == NULL)
        {
            Mystery_book ::no_of_mystery_books == 1;
        }
        else
        {
            Mystery_book ::no_of_mystery_books++;
        }
    }
};
class Science_Fiction_book : public Books
{
    string science_book_name;
    static int no_of_science_books;

public:
    Science_Fiction_book(string name, string author, string genre, string subject, int overall_allocate_users, int ongoing_allocate_users) : Books(name, author, genre, subject, overall_allocate_users, ongoing_allocate_users)
    {
        this->science_book_name = name;
        if (Science_Fiction_book ::no_of_science_books == 0 || Science_Fiction_book ::no_of_science_books == NULL)
        {
            Science_Fiction_book ::no_of_science_books == 1;
        }
        else
        {
            Science_Fiction_book ::no_of_science_books++;
        }
    }
};
class Romance_book : public Books
{
    string romance_book_name;
    static int no_of_romance_books;

public:
    Romance_book(string name, string author, string genre, string subject, int overall_allocate_users, int ongoing_allocate_users) : Books(name, author, genre, subject, overall_allocate_users, ongoing_allocate_users)
    {
        this->romance_book_name = name;
        if (Romance_book ::no_of_romance_books == 0 || Romance_book ::no_of_romance_books == NULL)
        {
            Romance_book ::no_of_romance_books == 1;
        }
        else
        {
            Romance_book ::no_of_romance_books++;
        }
    }
};
class Adventure_book : public Books
{
    string adventure_book_name;
    static int no_of_adventure_books;

public:
    Adventure_book(string name, string author, string genre, string subject, int overall_allocate_users, int ongoing_allocate_users) : Books(name, author, genre, subject, overall_allocate_users, ongoing_allocate_users)
    {
        this->adventure_book_name = name;
        if (Adventure_book ::no_of_adventure_books == 0 || Adventure_book ::no_of_adventure_books == NULL)
        {
            Adventure_book ::no_of_adventure_books == 1;
        }
        else
        {
            Adventure_book ::no_of_adventure_books++;
        }
    }
};
class Historic_book : public Books
{
    string historic_book_name;
    static int no_of_historic_books;

public:
    Historic_book(string name, string author, string genre, string subject, int overall_allocate_users, int ongoing_allocate_users) : Books(name, author, genre, subject, overall_allocate_users, ongoing_allocate_users)
    {
        this->historic_book_name = name;
        if (Historic_book ::no_of_historic_books == 0 || Historic_book ::no_of_historic_books == NULL)
        {
            Historic_book ::no_of_historic_books == 1;
        }
        else
        {
            Historic_book ::no_of_historic_books++;
        }
    }
};

vector<Users> users;
vector<Books> books;
vector<Horror_book> horror_book;
vector<Mystery_book> mystery_book;
vector<Science_Fiction_book> science_fiction_book;
vector<Romance_book> romance_book;
vector<Adventure_book> adventure_book;
vector<Historic_book> historic_book;
vector<Issued_books> issued_books;

void Add_Book(vector<Books> &books);
vector<Books> Remove_Book(vector<Books> &books);
vector<Users> Add_User(vector<Users> &users);
vector<Users> Remove_User(vector<Users> &users);
vector<Issued_books> Allocate_Book_to_User(vector<Users> &users, vector<Books> &books, vector<Issued_books> &issued_books);
void Deallocate_Book_to_User();
void History_of_User(vector<Users> &users, string id);
int get_no_of_lines(ifstream &User_data);
void Update_users(vector<Users> &users);
void Update_Books(vector<Books> &books);
void Update_Issued_Books(vector<Issued_books> &issued_books);
int does_the_user_exists(string id);
int does_the_book_exists(string name);
void show_all_users(vector<Users> &users);
void show_all_books(vector<Books> &books);
void show_all_issued_books(vector<Issued_books> &issued_books);
void Remove_user_from_csv(vector<Users> &users, string id);
void Remove_book_from_csv(vector<Books> &books, string name);
void Update_csv_from_users(vector<Users> &users);
void Update_csv_from_books(vector<Books> &books);
void add_issued_book_data(string data);
int get_index_of_issued_book(string id);
void find_issued_book_by_id_function(string id);
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
        // books[current_no_books].display_book_data();
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
        // users[current_no_users].display_user_data();
        current_no_users++;
    }
    User_data.close();
}

void Update_Issued_Books(vector<Issued_books> &issued_books)
{
    cout << "Update_Books called" << endl;
    ifstream Issued_book("Issued_books.csv");
    string s = "";
    char del = ',';
    int i = 0;
    getline(Issued_book, s);
    s = "";
    string arr[5];
    while (!Issued_book.eof())
    {
        getline(Issued_book, s);
        cout << "s = " << s << endl;
        if (s == "")
        {
            cout << "if statemenet s == called" << endl;
            return;
        }
        stringstream ss(s);
        int j = 0;
        while (!ss.eof())
        {
            getline(ss, arr[j], del);
            j++;
        }
        Issued_books temp(arr);
        issued_books.push_back(temp);
        i++;
    }
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

void Add_Book(vector<Books> &books)
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
vector<Books> Remove_Book(vector<Books> &books)
{
    cout << "Remove_Book called" << endl;
    string name;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Entered name = " << name;

    int i = 0;
    while (i < books.size())
    {
        string lower_b_n = books[i].name, lname = name;
        transform(lower_b_n.begin(), lower_b_n.end(), lower_b_n.begin(), ::tolower);
        transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
        if (lower_b_n == lname)
        {
            books.erase(books.begin() + i);
            current_no_books--;
            Remove_book_from_csv(books, name);
            show_all_books(books);
            break;
        }
        i++;
        if (i == books.size())
        {
            cout << "User not found!!!!" << endl;
        }
    }
    return books;
}
vector<Users> Add_User(vector<Users> &users)
{
    cout << "Add_User called" << endl;
    ofstream User_data_edit("User_data.csv", ios::app);
    string s = "", name, id, phone, email;
    cout << "Name : ";
    cin.ignore();
    getline(cin, name);
    cout << "ID : ";
    getline(cin, id);
    transform(id.begin(), id.end(), id.begin(), ::tolower);
    cout << "Phone : ";
    getline(cin, phone);
    cout << "Email : ";
    getline(cin, email);
    int index = does_the_user_exists(id);
    if (index != -1)
    {
        cout << "A user with same id already exits" << endl;
        return users;
    }
    else
    {
        Users temp(name, id, phone, email);
        users.push_back(temp);
        users[current_no_users].display_user_data();
        current_no_users++;
        s = name + "," + id + "," + phone + "," + email + ",0,0,NULL,NULL\n";
        User_data_edit << s;
        User_data_edit.close();
    }
    return users;
}
vector<Users> Remove_User(vector<Users> &users)
{
    cout << "Remove_User called" << endl;
    string Id;
    cout << "Id: ";
    cin >> Id;
    transform(Id.begin(), Id.end(), Id.begin(), ::tolower);

    int i = 0;
    while (i < users.size())
    {
        string lower_u_i = users[i].id, lid = Id;
        transform(lower_u_i.begin(), lower_u_i.end(), lower_u_i.begin(), ::tolower);
        transform(lid.begin(), lid.end(), lid.begin(), ::tolower);
        if (users[i].id == Id)
        {
            cout << "If statement called" << endl;
            users.erase(users.begin() + i);
            current_no_users--;
            show_all_users(users);
            Remove_user_from_csv(users, Id);
            break;
        }
        i++;
        if (i == users.size())
        {
            cout << "User not found!!!!" << endl;
        }
    }
    return users;
}
vector<Issued_books> Allocate_Book_to_User(vector<Users> &users, vector<Books> &books, vector<Issued_books> &issued_books)
{
    string user_id, book_name;
    cout << "Allocate_Book_to_User called" << endl;
    cout << "Enter user id: ";
    cin.ignore();
    getline(cin, user_id);
    cout << "Enter book name: ";
    getline(cin, book_name);
    int user_index = does_the_user_exists(user_id);
    // cout<<"1. Users.size = "<<users.size()<<endl;
    if (user_index == -1)
    {
        cout << "User doesn't exists" << endl;
        return issued_books;
    }
    int book_index = does_the_book_exists(book_name);
    if (book_index == -1)
    {
        cout << "Book doesn't exists" << endl;
        return issued_books;
    }
    // cout<<"2. Users.size = "<<users.size()<<endl;
    cout << "USER DATA = " << users[user_index].get_data_in_string() << endl;
    cout << "BOOK DATA = " << books[book_index].get_data_in_string() << endl;

    Issued_books temp(book_name, user_id);
    issued_books.push_back(temp);
    cout << "Issued book data = " << temp.get_issued_book_data();
    add_issued_book_data(temp.get_issued_book_data());
    current_no_issued_books++;
    // cout << "3. Users.size = " << users.size() << endl;
    users[user_index].add_new_issued_books(temp.get_issued_id());
    // cout<<"4. Users.size = "<<users.size()<<endl;
    users[user_index].show_current_issued_books_id();
    // cout<<"5. Users.size = "<<users.size()<<endl;
    users[user_index].show_all_issued_books_id();
    // cout<<"6. Users.size = "<<users.size()<<endl;
    Update_csv_from_users(users);
    books[book_index].add_ongoing_allocate_users();
    Update_csv_from_books(books);

    // cout<<"7. Users.size = "<<users.size()<<endl;
    return issued_books;
}
void Deallocate_Book_to_User()
{
    cout << "Deallocate_Book_to_User called" << endl;
}
void History_of_User(vector<Users> &users, string id)
{
    int index = does_the_user_exists(id);
    if (index != -1)
    {
        users[index].display_user_data();
    }
    else
    {
        cout << "User not found" << endl;
    }
}
void History_of_Book(vector<Books> &books, string name)
{
    int index = does_the_book_exists(name);
    if (index != -1)
    {
        books[index].display_book_data();
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

int does_the_user_exists(string id)
{
    cout << "does_the_user_exists called" << endl;
    int i = 0;
    string upper_id = id, lower_id = id;
    transform(upper_id.begin(), upper_id.end(), upper_id.begin(), ::toupper);
    transform(lower_id.begin(), lower_id.end(), lower_id.begin(), ::tolower);
    cout << "upper_id = " << upper_id << endl;
    cout << "lower_id = " << lower_id << endl;
    cout << "current_no_users= " << current_no_users << endl;
    while (i < current_no_users)
    {

        cout << "users[i].id = " << users[i].id << endl;
        if (users[i].id == upper_id || users[i].id == lower_id)
        {
            cout << "If statement called with i = " << i << endl;
            return i;
        }
        i++;
    }
    return -1;
}
int does_the_book_exists(string name)
{
    cout << "does_the_book_exists called name = " << name << endl;
    cout << "current_no_books = " << current_no_books << endl;
    int i = 0;
    string upper_name = name, lower_name = name, s1 = "", s2 = "";
    transform(upper_name.begin(), upper_name.end(), upper_name.begin(), ::toupper);
    transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
    cout << "upper_name = " << upper_name << endl;
    cout << "lower_name = " << lower_name << endl;
    while (i < current_no_books)
    {
        cout << "i = " << i << endl;
        cout << "books[i].name = " << books[i].name << endl;
        s1 = books[i].name, s2 = books[i].name;
        transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
        transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
        if (s1 == upper_name || s2 == lower_name)
        {
            cout << "returning = " << i << endl;
            return i;
        }

        i++;
    }
    return -1;
}

void show_all_users(vector<Users> &users)
{
    int i = 0;
    cout << "users.size() = " << users.size() << endl;
    while (i < users.size())
    {
        cout << "i = " << i << " - ";
        users[i].display_user_data();
        i++;
    }
}
void show_all_books(vector<Books> &books)
{
    int i = 0;
    cout << "books.size() = " << books.size() << endl;
    while (i < books.size())
    {
        cout << "i = " << i << " - ";
        books[i].display_book_data();
        i++;
    }
}

void show_all_issued_books(vector<Issued_books> &issued_books)
{
    cout << "show_all_issued_books called" << endl;
    int i = 0;
    while (i < issued_books.size())
    {
        cout << "i = " << i << endl;
        cout << "Data = " << issued_books[i].get_issued_book_data() << endl;
        i++;
    }
}

void Remove_user_from_csv(vector<Users> &users, string id)
{

    cout << "Remove_user_from_csv called" << endl;
    vector<string> lines;
    string s = "", header;
    ifstream User_data("User_data.csv");
    string arr[8], lower_id = id, lower_arr2;
    getline(User_data, header);
    s = "";
    while (getline(User_data, s))
    {
        cout << s << endl;
        stringstream ss(s);
        string word;
        char del = ',';
        int i = 0;
        while (getline(ss, word, del))
        {
            cout << word << " - ";
            arr[i] = word;
            i++;
        }
        cout << "while loop completed" << endl;
        lower_arr2 = arr[1];
        cout << "lower_arr2 = " << lower_arr2 << endl;
        transform(lower_id.begin(), lower_id.end(), lower_id.begin(), ::tolower);
        transform(lower_arr2.begin(), lower_arr2.end(), lower_arr2.begin(), ::tolower);
        cout << "lower_arr2 = " << lower_arr2 << endl;
        cout << "lower_id = " << lower_id << endl;
        if (lower_arr2 == lower_id)
        {
            cout << "if statement called" << endl;
            continue;
        }
        else
        {
            lines.push_back(s);
        }
    }
    User_data.close();
    ofstream User_data_edit("User_data.csv");
    int i = 0;
    User_data_edit << header << endl;
    cout << "lines ::" << endl
         << endl;
    while (i < lines.size())
    {
        User_data_edit << lines[i] << endl;
        cout << lines[i] << endl;
        i++;
    }
    User_data_edit.close();
}
void Remove_book_from_csv(vector<Books> &books, string name)
{
    cout << "Remove_book_from_csv called" << endl;
    vector<string> lines;
    string s = "", header;
    ifstream Book_data("Book_data.csv");
    string arr[8], lower_name = name, lower_arr0;
    getline(Book_data, header);
    s = "";
    while (getline(Book_data, s))
    {
        cout << s << endl;
        stringstream ss(s);
        string word;
        char del = ',';
        int i = 0;
        while (getline(ss, word, del))
        {
            cout << word << " - ";
            arr[i] = word;
            i++;
        }
        cout << "while loop completed" << endl;
        lower_arr0 = arr[0];
        cout << "lower_arr0 = " << lower_arr0 << endl;
        transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
        transform(lower_arr0.begin(), lower_arr0.end(), lower_arr0.begin(), ::tolower);
        cout << "lower_arr0 = " << lower_arr0 << endl;
        cout << "lower_id = " << lower_name << endl;
        if (lower_arr0 == lower_name)
        {
            cout << "if statement called" << endl;
            continue;
        }
        else
        {
            lines.push_back(s);
        }
    }
    Book_data.close();
    ofstream Book_data_edit("Book_data.csv");
    int i = 0;
    Book_data_edit << header << endl;
    cout << "lines ::" << endl
         << endl;
    while (i < lines.size())
    {
        Book_data_edit << lines[i] << endl;
        cout << lines[i] << endl;
        i++;
    }
    Book_data_edit.close();
}

void Update_csv_from_users(vector<Users> &users)
{
    ofstream User_data_edit("User_data.csv");
    User_data_edit << "NAME,ID_NO,PHONE_NO,EMAIL_ID,CURRENT_BOOKS_NO,ALL_BOOKS_NO,CURRENT_BOOKS_NAMES,ALL_BOOKS_NAMES" << endl;
    string s = "";
    int i = 0;
    cout << "users.size() = " << users.size() << endl;
    while (i < users.size())
    {
        s = users[i].get_data_in_string();
        User_data_edit << s << endl;
        i++;
    }
    User_data_edit.close();
}
void Update_csv_from_books(vector<Books> &books)
{
    ofstream Book_data_edit("Book_data.csv");
    Book_data_edit << "BOOK_NAME,AUTHOR,GENRE,SUBJECT,OV_ALLOCATED_USER_NO,ONGOING_ALLOCATED_USER_NO" << endl;
    string s = "";
    int i = 0;
    while (i < books.size())
    {
        s = books[i].get_data_in_string();
        Book_data_edit << s << endl;
        i++;
    }
    Book_data_edit.close();
}

void add_issued_book_data(string data)
{
    cout << "add_issued_book_data called" << endl;
    ofstream Issue_book("Issued_books.csv", ios::app);
    Issue_book << data << endl;
    Issue_book.close();
}

int get_index_of_issued_book(string id)
{
    cout << "get_index_of_issued_book called" << endl;
    int i = 0;
    cout << "Id = " << id << "|" << endl;
    cout << "issued_books.size() = " << issued_books.size() << endl;
    while (i < issued_books.size())
    {
        string temp = issued_books[i].get_issued_id();
        temp[temp.size() - 1] = '\0';
        // id[id.size()] = '\0';
        cout << "temp = |" << temp << "|" << endl;
        cout << "id = |" << id << "|" << endl;
        // if (temp == id)
        // {
        //     return i;
        // }
        if (id == temp)
        {
            cout << "If statement called" << endl;
            return i;
        }
        cout << "If not called" << endl;
        i++;
    }
    return -1;
}

void find_issued_book_by_id_function(string id)
{
    cout << "find_issued_book_by_id_function called" << endl;
    string lower_id = id, higher_id = id;
    transform(lower_id.begin(), lower_id.end(), lower_id.begin(), ::tolower);
    transform(higher_id.begin(), higher_id.end(), higher_id.begin(), ::toupper);
    cout << "lower_id = " << lower_id << endl;
    cout << "higher_id = " << higher_id << endl;
    int index = get_index_of_issued_book(higher_id);
    if (index == -1)
    {
        cout << "Issued_Book not found" << endl;
    }
    else
    {
        cout << "Book found" << endl;
        cout << "i = " << index << endl;
        cout << "issued_books[index].get_issued_book_data() = " << issued_books[index].get_issued_book_data() << endl;
    }
}

int main()
{

    string id, name;
    // cout << "Horror_book::no_of_horror_books: " << Horror_book::no_of_horror_books << endl;
    Update_users(users);
    Update_Books(books);
    Update_Issued_Books(issued_books);
    int n;
    while (n != 0)
    {
        cout << " *************************************************** " << endl
             << endl;
        cout << "> Enter 0 to exit" << endl;                    // DONE
        cout << "> Enter 1 to Add Book" << endl;                // DONE
        cout << "> Enter 2 to Remove Book" << endl;             // DONE
        cout << "> Enter 3 to Add User" << endl;                // DONE
        cout << "> Enter 4 to Remove User" << endl;             // DONE
        cout << "> Enter 5 to Allocate Book to User" << endl;   // DONE
        cout << "> Enter 6 to Deallocate Book to User" << endl; // WORKING
        cout << "> Enter 7 to History of User" << endl;         // DONE
        cout << "> Enter 8 to History of Book" << endl;         // DONE
        cout << "> Enter 9 to Show all Users" << endl;          // DONE
        cout << "> Enter 10 to Show all Books" << endl;         // DONE
        cout << "> Enter 11 to Show all Issued Books" << endl;  // DONE
        cout << "> Enter 12 to Update csv from users" << endl;  // DONE
        cout << "> Enter 13 to Update csv from books" << endl;  // DONE
        cout << "> Enter 14 to Update csv from books" << endl;  // DONE
        cout << "> Enter 15 to Show no of users" << endl;       // DONE
        cout << "> Enter 16 to Show no of books" << endl;       // DONE
        cout << "> Enter 17 to Show no of issued_books" << endl // DONE
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
            books = Remove_Book(books);
            break;
        case 3:
            users = Add_User(users);
            break;
        case 4:
            users = Remove_User(users);
            break;
        case 5:
            issued_books = Allocate_Book_to_User(users, books,issued_books);
            break;
        case 6:
            Deallocate_Book_to_User();
            break;
        case 7:
            cin.ignore();
            cout << "Id of User to find: ";
            getline(cin, id);
            History_of_User(users, id);
            break;
        case 8:
            cin.ignore();
            cout << "Name of book to find: ";
            getline(cin, name);
            History_of_Book(books, name);
            break;
        case 9:
            show_all_users(users);
            break;
        case 10:
            show_all_books(books);
            break;
        case 11:
            show_all_issued_books(issued_books);
            break;
        case 12:
            Update_csv_from_users(users);
            break;
        case 13:
            Update_csv_from_books(books);
            break;
        case 14:
            // string temp = "";
            cout << "Issued_Bookk ID = ";
            cin.ignore();
            getline(cin, id);
            find_issued_book_by_id_function(id);
            break;
        case 15:
            // string temp = "";
            cout << "users.size() = " << users.size() << endl;
            break;
        case 16:
            // string temp = "";
            cout << "books.size() = " << books.size() << endl;
            break;
        case 17:
            // string temp = "";
            cout << "issued_books.size() = " << issued_books.size() << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}