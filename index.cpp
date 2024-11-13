#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <typeinfo>
#include <ctime>
#include <memory>
#include <stdexcept>

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
            temp[temp.length() - 1] = '\0';
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
    vector<string> get_all_data_in_vector()
    {
        vector<string> temp;
        temp.push_back(this->issue_id);
        temp.push_back(this->book_name);
        temp.push_back(this->id);
        temp.push_back(this->issue_date);
        temp.push_back(this->return_date);
        return temp;
    }
    void book_submitted()
    {
        time_t timestamp;
        time(&timestamp);
        string temp = ctime(&timestamp);
        if (temp[temp.length() - 1] == '\n')
        {
            temp[temp.length() - 1] = '\0';
        }
        this->return_date = temp;
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
        if (arr == "NULL" || arr == "")
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
        if (arr == "NULL" || arr == "")
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
        int i = 0;
        while (i < current_books_issue_id.size())
        {
            s = s + current_books_issue_id[i];
            i++;
            if (i < current_books_issue_id.size())
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
    void deallocate_book_id(string book_id)
    {
        cout << "deallocate_book_id called" << endl;
        int i = 0;
        while (i < this->current_books_issue_id.size())
        {
            if (current_books_issue_id[i] == book_id)
            {
                cout << "Issue_id found with i = " << i << endl;
                this->current_books_issue_id.erase(this->current_books_issue_id.begin() + i);
            }
            i++;
        }
    }
};

class Books
{
protected:
    string author;
    string genre;
    string subject;
    int total_no_books;
    int available_no_books;
    int overall_allocate_users;
    int ongoing_allocate_users;

public:
    string name;
    virtual ~Books() = default; // Virtual destructor
    virtual void display_book_info() const = 0;

    Books()
    {
        cout << "Books default constructor called" << endl;
    }

    // Parameterized constructor
    Books(string name, string author, string genre, string subject, int overall_allocate_users, int ongoing_allocate_users)
        : name(name), author(author), genre(genre), subject(subject),
          overall_allocate_users(overall_allocate_users), ongoing_allocate_users(ongoing_allocate_users) {}

    // Another parameterized constructor
    Books(string name, string author, string genre, string subject, int no)
        : name(name), author(author), genre(genre), subject(subject),
          total_no_books(no), available_no_books(no), overall_allocate_users(0), ongoing_allocate_users(0) {}

    // Constructor with exception handling
    Books(string arr[])
    {
        try
        {
            this->name = arr[0];
            this->author = arr[1];
            this->genre = arr[2];
            this->subject = arr[3];
            this->available_no_books = stoi(arr[4]);
            this->total_no_books = stoi(arr[5]);
            this->overall_allocate_users = stoi(arr[6]);
            this->ongoing_allocate_users = stoi(arr[7]);
        }
        catch (const exception &e)
        {
            throw runtime_error("Error in Books constructor: " + string(e.what()));
        }
    }

    // Encapsulation: Public method to modify private members
    void add_ongoing_allocate_users()
    {
        try
        {
            if (available_no_books <= 0)
                throw runtime_error("No available books to allocate.");
            this->ongoing_allocate_users++;
            this->overall_allocate_users++;
            this->available_no_books--;
        }
        catch (const exception &e)
        {
            throw runtime_error("Error in add_ongoing_allocate_users: " + string(e.what()));
        }
    }

    // Exception handling example
    void remove_ongoing_allocate_users()
    {
        try
        {
            if (ongoing_allocate_users <= 0)
                throw runtime_error("No ongoing allocations to remove.");
            this->available_no_books++;
            this->ongoing_allocate_users--;
        }
        catch (const exception &e)
        {
            throw runtime_error("Error in remove_ongoing_allocate_users: " + string(e.what()));
        }
    }

    // Polymorphism: Overridable function display_book_info
    virtual void display_book_data() const
    {
        cout << "Name = " << this->name << endl
             << "Author = " << this->author << endl
             << "Genre = " << this->genre << endl
             << "Subject = " << this->subject << endl
             << "Available_no_books = " << this->available_no_books << endl
             << "Total_no_books = " << this->total_no_books << endl
             << "Overall_allocate_users = " << this->overall_allocate_users << endl
             << "Ongoing_allocate_users = " << this->ongoing_allocate_users << endl
             << endl;
    }

    // Getter functions for protected members
    string getGenre() const { return genre; }
    int getTotalNoBooks() const { return total_no_books; }
    string get_data_in_string() const
    {
        return name + "," + author + "," + genre + "," + subject + "," +
               to_string(available_no_books) + "," + to_string(total_no_books) + "," +
               to_string(overall_allocate_users) + "," + to_string(ongoing_allocate_users);
    }
    int get_available_no_books() const { return available_no_books; }
};

// Derived class from Books - Inheritance
class Educational_book : public Books
{
    string book_name;

public:
    static int no_of_educational_books;

    Educational_book(string name, string author, string subject, int total_no_books)
        : Books(name, author, "Educational book", subject, total_no_books), book_name(name)
    {
        no_of_educational_books++;
    }

    void display_book_info() const override
    {
        cout << "Educational Book Info:" << endl;
        display_book_data();
    }
};
// int Educational_book::no_of_educational_books = 0;

class Horror_book : public Books
{
    string horror_book_name;

public:
    static int no_of_horror_books;

    Horror_book(string name, string author, string subject, int total_no_books)
        : Books(name, author, "Horror book", subject, total_no_books), horror_book_name(name)
    {
        no_of_horror_books++;
    }

    void display_book_info() const override
    {
        cout << "Horror Book Info:" << endl;
        display_book_data();
    }
};
// int Horror_book::no_of_horror_books = 0;

class Adventure_book : public Books
{
    string adventure_book_name;

public:
    static int no_of_adventure_books;

    Adventure_book(string name, string author, string subject, int total_no_books)
        : Books(name, author, "Adventure book", subject, total_no_books), adventure_book_name(name)
    {
        no_of_adventure_books++;
    }

    void display_book_info() const override
    {
        cout << "Adventure Book Info:" << endl;
        display_book_data();
    }

    void display_book_info(string additional_info) const
    {
        cout << additional_info << endl;
        display_book_info();
    }
};
// int Adventure_book::no_of_adventure_books = 0;

class Fantasy_book : public Books
{
    string book_name;

public:
    static int no_of_fantasy_books;

    Fantasy_book(string name, string author, string subject, int total_no_books)
        : Books(name, author, "Fantasy book", subject, total_no_books), book_name(name)
    {
        no_of_fantasy_books++;
    }

    void display_book_info() const override
    {
        cout << "Fantasy Book Info:" << endl;
        display_book_data();
    }
};
// int Fantasy_book::no_of_fantasy_books = 0;

class Science_Fiction_book : public Books
{
    string book_name;

public:
    static int no_of_sci_fiction_books;

    Science_Fiction_book(string name, string author, string subject, int total_no_books)
        : Books(name, author, "Science Fiction book", subject, total_no_books), book_name(name)
    {
        no_of_sci_fiction_books++;
    }

    void display_book_info() const override
    {
        cout << "Science Fiction Book Info:" << endl;
        display_book_data();
    }
};
// int Science_Fiction_book::no_of_sci_fiction_books = 0;

class Mystery_book : public Books
{
    string book_name;

public:
    static int no_of_mystery_books;

    Mystery_book(string name, string author, string subject, int total_no_books)
        : Books(name, author, "Mystery book", subject, total_no_books), book_name(name)
    {
        no_of_mystery_books++;
    }

    void display_book_info() const override
    {
        cout << "Mystery Book Info:" << endl;
        display_book_data();
    }
};
// int Mystery_book::no_of_mystery_books = 0;

class Thriller_Suspense_book : public Books
{
    string book_name;

public:
    static int no_of_thriller_books;

    Thriller_Suspense_book(string name, string author, string subject, int total_no_books)
        : Books(name, author, "Thriller & Suspense book", subject, total_no_books), book_name(name)
    {
        no_of_thriller_books++;
    }

    void display_book_info() const override
    {
        cout << "Thriller & Suspense Book Info:" << endl;
        display_book_data();
    }
};
class Other_book : public Books
{
    string book_name;

public:
    static int no_of_other_books;

    Other_book(string name, string author, string genre, string subject, int total_no_books)
        : Books(name, author, genre, subject, total_no_books), book_name(name)
    {
        no_of_other_books++;
    }

    void display_book_info() const override
    {
        cout << "Other Book Info:" << endl;
        display_book_data();
    }
};
// int Thriller_Suspense_book::no_of_thriller_books = 0;

// Template function to compare total number of books based on genre
template <typename GenreType>
bool compareTotalBooks(const Books &book, GenreType genre)
{
    // Check if the book's genre matches the provided genre type
    if (book.getGenre() == genre)
    {
        cout << "Total number of books in genre '" << genre << "' is: " << book.getTotalNoBooks() << endl;
        return true;
    }
    else
    {
        cout << "The book's genre does not match the given genre type '" << genre << "'." << endl;
        return false;
    }
}

int Educational_book::no_of_educational_books = 0;
int Horror_book::no_of_horror_books = 0;
int Adventure_book::no_of_adventure_books = 0;
int Fantasy_book::no_of_fantasy_books = 0;
int Science_Fiction_book::no_of_sci_fiction_books = 0;
int Mystery_book::no_of_mystery_books = 0;
int Thriller_Suspense_book::no_of_thriller_books = 0;
int Other_book::no_of_other_books = 0;

// Vector declarations using pointers
vector<Users> users;
vector<Books *> books;
vector<Issued_books> issued_books;
vector<Educational_book *> educational_books;
vector<Horror_book *> horror_books;
vector<Adventure_book *> adventure_books;
vector<Fantasy_book *> fantasy_books;
vector<Science_Fiction_book *> science_fiction_books;
vector<Mystery_book *> mystery_books;
vector<Thriller_Suspense_book *> thriller_suspense_books;
vector<Other_book *> other_books;
// vector<Historical_Fiction_book*> historical_fiction_books;
// vector<Romance_Book*> romance_books;
// vector<Graphic_Novel*> graphic_novels;
string input_check(string input);
void Add_Book(vector<Books *> &books);
void Remove_Book(vector<Books *> &books);
void Add_User(vector<Users> &users);
void Remove_User(vector<Users> &users);
void Allocate_Book_to_User(vector<Users> &users, vector<Books *> &books, vector<Issued_books> &issued_books);
void Deallocate_Book_from_User(vector<Users> &users, vector<Books *> &books, vector<Issued_books> &issued_books);
void History_of_User(vector<Users> &users, string id);
int get_no_of_lines(ifstream &User_data);
void Update_users(vector<Users> &users);
void Update_Books(vector<Books *> &books);
void Update_Issued_Books(vector<Issued_books> &issued_books);
int does_the_user_exists(string id);
int does_the_book_exists(string name);
void show_all_users(vector<Users> &users);
void show_all_books(vector<Books *> &books);
void show_all_issued_books(vector<Issued_books> &issued_books);
void Remove_user_from_csv(vector<Users> &users, string id);
void Remove_book_from_csv(vector<Books *> &books, string name);
void Update_csv_from_users(vector<Users> &users);
void Update_csv_from_books(vector<Books *> &books);
void add_issued_book_data(string data);
void Update_csv_from_issued_books(vector<Issued_books> &issued_books);
int get_index_of_issued_book(string id);
int does_the_issued_book_exists(string id);
int current_no = 0;

void Update_Books(vector<Books *> &books)
{
    cout << "Update_Books called" << endl;
    ifstream Books_data("Book_data.csv");
    string s = "";
    string arr[8];
    getline(Books_data, s); // Skip header
    s = "";
    while (getline(Books_data, s))
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

        // Create appropriate derived class based on genre
        Books *temp = nullptr;
        string genre = arr[2];

        if (genre == "Educational book")
        {
            temp = new Educational_book(arr[0], arr[1], arr[3], stoi(arr[4]));
        }
        else if (genre == "Horror book")
        {
            temp = new Horror_book(arr[0], arr[1], arr[3], stoi(arr[4]));
        }
        else if (genre == "Adventure book")
        {
            temp = new Adventure_book(arr[0], arr[1], arr[3], stoi(arr[4]));
        }
        else if (genre == "Fantasy book")
        {
            temp = new Fantasy_book(arr[0], arr[1], arr[3], stoi(arr[4]));
        }
        else if (genre == "Science Fiction book")
        {
            temp = new Science_Fiction_book(arr[0], arr[1], arr[3], stoi(arr[4]));
        }
        else if (genre == "Mystery book")
        {
            temp = new Mystery_book(arr[0], arr[1], arr[3], stoi(arr[4]));
        }
        else if (genre == "Thriller & Suspense book")
        {
            temp = new Thriller_Suspense_book(arr[0], arr[1], arr[3], stoi(arr[4]));
        }

        if (temp != nullptr)
        {
            books.push_back(temp);
            current_no_books++;
        }
        else
        {
            cout << "Warning: Unknown book genre '" << genre << "'" << endl;
        }
    }
    Books_data.close();
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

void Add_Book(vector<Books *> &books)
{
    Books *book;
    // ifstream Book_data("Book_data.csv");
    int no, k;
    string s = "", Name, Author = "", Subject = "", Genre = "", temp;
    cout << "Book Name : ";
    cin.ignore();
    getline(cin, Name);
    Name = input_check(Name);
    cout << "Author : ";
    getline(cin, Author);
    Author = input_check(Author);
    cout << "GENRE :" << endl;
    while (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8 && k != 9 && k != 10 || k != 11)
    {
        cout << ">>>    1. Educational Book" << endl;
        cout << ">>>    2. Action & Adventure Book" << endl;
        cout << ">>>    3. Fantasy Book" << endl;
        cout << ">>>    4. Science Fiction Book" << endl;
        cout << ">>>    5. Mystery Book" << endl;
        cout << ">>>    6. Horror Book" << endl;
        cout << ">>>    7. Thriller & Suspense Book" << endl;
        cout << ">>>    8. Other" << endl
             << endl;
        cout << " --->>> Please enter your choice : ";
        cin >> temp;
        if (temp == "1" || temp == "2" || temp == "3" || temp == "4" || temp == "5" || temp == "6" || temp == "7" || temp == "8")
        {
            // cout << "You have entered a valid number." << endl;
            k = stoi(temp);
            break;
        }
        else
        {
            cout << "You have not entered a valid number" << endl;
            continue;
        }
    }
    if (k == 8)
    {
        cout << ">-- Genre = ";
        cin.ignore();
        getline(cin, Genre);
        Genre = input_check(Genre);
    }
    cout << "SUBJECT : ";
    cin.ignore();
    getline(cin, Subject);
    Subject = input_check(Subject);
    cout << "No of books: ";
    cin >> no;
    int i = does_the_book_exists(Name);
    if (i != -1)
    {
        cout << "A book with same name already exists" << endl;
        return;
    }

    switch (k)
    {
    case 1:
        book = new Educational_book(Name, Author, Subject, no);

        if (book != nullptr)
        {
            cout << "Book data = " << book->get_data_in_string() << endl;
            books.push_back(book);
            Educational_book *tempp;
            // Converting the base class pointer to derived class pointer
            // to store in the specific vector
            tempp = (Educational_book *)book;
            educational_books.push_back(tempp);
            cout << "Edu Book data = " << tempp->get_data_in_string() << endl;
        }
        break;
    case 2:
        book = new Adventure_book(Name, Author, Subject, no);
        if (book != nullptr)
        {
            cout << "Book data = " << book->get_data_in_string() << endl;
            books.push_back(book);
            Adventure_book *tempp;
            // Converting the base class pointer to derived class pointer
            // to store in the specific vector
            tempp = (Adventure_book *)book;
            adventure_books.push_back(tempp);
            cout << "Adventure Book data = " << tempp->get_data_in_string() << endl;
        }
        break;
    case 3:
        book = new Fantasy_book(Name, Author, Subject, no);
        if (book != nullptr)
        {
            cout << "Book data = " << book->get_data_in_string() << endl;
            books.push_back(book);
            Fantasy_book *tempp;
            // Converting the base class pointer to derived class pointer
            // to store in the specific vector
            tempp = (Fantasy_book *)book;
            fantasy_books.push_back(tempp);
            cout << "Fantasy Book data = " << tempp->get_data_in_string() << endl;
        }
        break;
    case 4:
        book = new Science_Fiction_book(Name, Author, Subject, no);
        if (book != nullptr)
        {
            cout << "Book data = " << book->get_data_in_string() << endl;
            books.push_back(book);
            Science_Fiction_book *tempp;
            // Converting the base class pointer to derived class pointer
            // to store in the specific vector
            tempp = (Science_Fiction_book *)book;
            science_fiction_books.push_back(tempp);
            cout << "Sci-Fi Book data = " << tempp->get_data_in_string() << endl;
        }
        break;
    case 5:
        book = new Mystery_book(Name, Author, Subject, no);
        if (book != nullptr)
        {
            cout << "Book data = " << book->get_data_in_string() << endl;
            books.push_back(book);
            Mystery_book *tempp;
            // Converting the base class pointer to derived class pointer
            // to store in the specific vector
            tempp = (Mystery_book *)book;
            mystery_books.push_back(tempp);
            cout << "Mystery Book data = " << tempp->get_data_in_string() << endl;
        }
        break;
    case 6:
        book = new Horror_book(Name, Author, Subject, no);
        if (book != nullptr)
        {
            cout << "Book data = " << book->get_data_in_string() << endl;
            books.push_back(book);
            Horror_book *tempp;
            // Converting the base class pointer to derived class pointer
            // to store in the specific vector
            tempp = (Horror_book *)book;
            horror_books.push_back(tempp);
            cout << "Horror Book data = " << tempp->get_data_in_string() << endl;
        }
        break;
    case 7:
        book = new Thriller_Suspense_book(Name, Author, Subject, no);
        if (book != nullptr)
        {
            cout << "Book data = " << book->get_data_in_string() << endl;
            books.push_back(book);
            Thriller_Suspense_book *tempp;
            // Converting the base class pointer to derived class pointer
            // to store in the specific vector
            tempp = (Thriller_Suspense_book *)book;
            thriller_suspense_books.push_back(tempp);
            cout << "Thriller & Suspense Book data = " << tempp->get_data_in_string() << endl;
        }
        break;
    case 8:
        book = new Other_book(Name, Author, Genre, Subject, no);
        if (book != nullptr)
        {
            cout << "Book data = " << book->get_data_in_string() << endl;
            books.push_back(book);
            Other_book *tempp;
            // Converting the base class pointer to derived class pointer
            // to store in the specific vector
            tempp = (Other_book *)book;
            other_books.push_back(tempp);
            cout << "Other Book data = " << tempp->get_data_in_string() << endl;
        }
        break;
    default:
        cout << "Please enter a valid number" << endl;
        break;
    }

    ofstream Book_data_edit("Book_data.csv", ios::app);
    Book_data_edit << books[current_no_books]->get_data_in_string() << endl;
    current_no_books++;
    Book_data_edit.close();
}
void Remove_Book(vector<Books *> &books)
{
    cout << "Remove_Book called" << endl;
    string name;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    name = input_check(name);
    cout << "Entered name = " << name;

    int i = 0;
    while (i < books.size())
    {
        string lower_b_n = books[i]->name, lname = name;
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
    return;
}
void Add_User(vector<Users> &users)
{
    cout << "Add_User called" << endl;
    ofstream User_data_edit("User_data.csv", ios::app);
    string s = "", name, id, phone, email;
    cout << "Name : ";
    cin.ignore();
    getline(cin, name);
    name = input_check(name);
    cout << "ID : ";
    getline(cin, id);
    id = input_check(id);
    transform(id.begin(), id.end(), id.begin(), ::tolower);
    cout << "Phone : ";
    getline(cin, phone);
    phone = input_check(phone);
    cout << "Email : ";
    getline(cin, email);
    email = input_check(email);
    int index = does_the_user_exists(id);
    if (index != -1)
    {
        cout << "A user with same id already exits" << endl;
        return;
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
    return;
}
void Remove_User(vector<Users> &users)
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
    return;
}
void Allocate_Book_to_User(vector<Users> &users, vector<Books *> &books, vector<Issued_books> &issued_books)
{
    string user_id, book_name;
    cout << "Allocate_Book_to_User called" << endl;
    cout << "Enter user id: ";
    cin.ignore();
    getline(cin, user_id);
    user_id = input_check(user_id);
    cout << "Enter book name: ";
    getline(cin, book_name);
    book_name = input_check(book_name);
    int user_index = does_the_user_exists(user_id);
    // cout<<"1. Users.size = "<<users.size()<<endl;
    if (user_index == -1)
    {
        cout << "User doesn't exists" << endl;
        return;
    }
    int book_index = does_the_book_exists(book_name);
    int no_of_books = books[book_index]->get_available_no_books();
    if (book_index == -1)
    {
        cout << "Book doesn't exists" << endl;
        return;
    }
    if (no_of_books <= 0)
    {
        cout << "No avaialable books" << endl;
        return;
    }
    // cout<<"2. Users.size = "<<users.size()<<endl;
    cout << "USER DATA = " << users[user_index].get_data_in_string() << endl;
    cout << "BOOK DATA = " << books[book_index]->get_data_in_string() << endl;

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
    books[book_index]->add_ongoing_allocate_users();
    Update_csv_from_books(books);

    // cout<<"7. Users.size = "<<users.size()<<endl;
    return;
}
void Deallocate_Book_from_User(vector<Users> &users, vector<Books *> &books, vector<Issued_books> &issued_books)
{
    cout << "Deallocate_Book_from_User called" << endl;
    string issued_book_id;
    cout << "Enter Book_issue_ID = ";
    cin.ignore();
    getline(cin, issued_book_id);
    issued_book_id = input_check(issued_book_id);
    int issued_book_index = does_the_issued_book_exists(issued_book_id);
    if (issued_book_index == -1)
    {
        cout << "Issue_book_id doesn't exists" << endl;
        return;
    }
    vector<string> temp;
    temp = issued_books[issued_book_index].get_all_data_in_vector();
    string book_name = temp[1];
    string user_id = temp[2];
    int user_index = does_the_user_exists(user_id);
    int book_index = does_the_book_exists(book_name);
    if (user_index == -1)
    {
        cout << "User doesn't exist" << endl;
        return;
    }
    if (book_index == -1)
    {
        cout << "Book doesn't exist" << endl;
        return;
    }
    cout << "USER DATA = " << users[user_index].get_data_in_string() << endl;
    cout << "BOOK DATA = " << books[book_index]->get_data_in_string() << endl;
    users[user_index].deallocate_book_id(issued_book_id);
    books[book_index]->remove_ongoing_allocate_users();
    issued_books[issued_book_index].book_submitted();
    Update_csv_from_users(users);
    Update_csv_from_books(books);
    Update_csv_from_issued_books(issued_books);

    // if (book_index == -1)
    // {
    //     cout << "Book doesn't exists" << endl;
    //     return;
    // }
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
void History_of_Book(vector<Books *> &books, string name)
{
    int index = does_the_book_exists(name);
    if (index != -1)
    {
        books[index]->display_book_data();
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
        cout << "books[i]->name = " << books[i]->name << endl;
        s1 = books[i]->name, s2 = books[i]->name;
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
void show_all_books(vector<Books *> &books)
{
    int i = 0;
    cout << "books.size() = " << books.size() << endl;
    while (i < books.size())
    {
        cout << "i = " << i << " - ";
        books[i]->display_book_data();
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
void Remove_book_from_csv(vector<Books *> &books, string name)
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
void Update_csv_from_books(vector<Books *> &books)
{
    ofstream Book_data_edit("Book_data.csv");
    Book_data_edit << "BOOK_NAME,AUTHOR,GENRE,SUBJECT,OV_ALLOCATED_USER_NO,ONGOING_ALLOCATED_USER_NO" << endl;
    string s = "";
    int i = 0;
    while (i < books.size())
    {
        s = books[i]->get_data_in_string();
        Book_data_edit << s << endl;
        i++;
    }
    Book_data_edit.close();
}

void Update_csv_from_issued_books(vector<Issued_books> &issued_books)
{
    cout << "Update_csv_from_issued_books called" << endl;
    ofstream Issued_book_data_edit("Issued_books.csv");
    Issued_book_data_edit << "BOOK_ISSUE_ID,BOOK_NAME,USER_ID,DATE_OF_ISSUE,DATE_OF_RETURN" << endl;
    string s = "";
    int i = 0;
    while (i < issued_books.size())
    {
        s = issued_books[i].get_issued_book_data();
        Issued_book_data_edit << s << endl;
        i++;
    }
    Issued_book_data_edit.close();
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

int does_the_issued_book_exists(string id)
{
    cout << "does_the_issued_book_exists called" << endl;
    int i = 0;
    string upper_id = id, lower_id = id;
    transform(upper_id.begin(), upper_id.end(), upper_id.begin(), ::toupper);
    transform(lower_id.begin(), lower_id.end(), lower_id.begin(), ::tolower);
    cout << "upper_id = " << upper_id << endl;
    cout << "lower_id = " << lower_id << endl;
    cout << "current_no_issued_books= " << issued_books.size() << endl;
    while (i < issued_books.size())
    {

        cout << "issued_books[i].id = " << issued_books[i].get_issued_id() << endl;
        if (issued_books[i].get_issued_id() == upper_id || issued_books[i].get_issued_id() == lower_id)
        {
            cout << "If statement called with i = " << i << endl;
            return i;
        }
        i++;
    }
    return -1;
}

void Update_users_from_csv(vector<Users> &users)
{
    if (users.size() != 0)
    {
        int i = 0;
        while (i < users.size())
        {
            users.erase(users.begin() + i);
            i++;
        }
    }
    Update_users(users);
}

string replace(string s, char c1, char c2)
{
    int l = s.length();

    // loop to traverse in the string
    for (int i = 0; i < l; i++)
    {
        // check for c1 and replace
        if (s[i] == c1)
            s[i] = c2;

        // check for c2 and replace
        else if (s[i] == c2)
            s[i] = c1;
    }
    return s;
}
string input_check(string input)
{
    char del = ',';
    int c = count(input.begin(), input.end(), del);
    if (c > 0)
    {
        input = replace(input, ',', '~');
    }
    return input;
}
int main()
{

    string id, name, temp = "";
    int index;
    // cout << "Horror_book::no_of_horror_books: " << Horror_book::no_of_horror_books << endl;
    Update_users(users);
    Update_Books(books);
    Update_Issued_Books(issued_books);
    int n;
    while (n != 0)
    {
        cout << " ****************************************************************************************** " << endl
             << endl;
        cout << "---->                              Enter 0 to exit" << endl;                          // DONE
        cout << "---->                              Enter 1 to Add Book" << endl;                      // DONE
        cout << "---->                              Enter 2 to Remove Book" << endl;                   // DONE
        cout << "---->                              Enter 3 to Add User" << endl;                      // DONE
        cout << "---->                              Enter 4 to Remove User" << endl;                   // DONE
        cout << "---->                              Enter 5 to Allocate Book to User" << endl;         // DONE
        cout << "---->                              Enter 6 to Deallocate Book to User" << endl;       // DONE
        cout << "---->                              Enter 7 to History of User" << endl;               // DONE
        cout << "---->                              Enter 8 to History of Book" << endl;               // DONE
        cout << "---->                              Enter 9 to Show all Users" << endl;                // DONE
        cout << "---->                              Enter 10 to Show all Books" << endl;               // DONE
        cout << "---->                              Enter 11 to Show all Issued Books" << endl;        // DONE
        cout << "---->                              Enter 12 to Update csv from users" << endl;        // DONE
        cout << "---->                              Enter 13 to Update csv from books" << endl;        // DONE
        cout << "---->                              Enter 14 to Update csv from issued_books" << endl; // DONE
        cout << "---->                              Enter 15 to Show no of users" << endl;             // DONE
        cout << "---->                              Enter 16 to Show no of books" << endl;             // DONE
        cout << "---->                              Enter 17 to Show no of issued_books" << endl;      // DONE
        cout << "---->                              Enter 18 to Get data of issued book id" << endl;   // DONE
        cout << "---->                              Enter 19 to Update users from csv" << endl;        // DONE
        cout << "---->                              Enter 20 to Update books from csv" << endl;        // DONE
        cout << "---->                              Enter 21 to Update issued_books from csv" << endl  // DONE
             << endl;
        cout << " ****************************************************************************************** " << endl;
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
            Remove_Book(books);
            break;
        case 3:
            Add_User(users);
            break;
        case 4:
            Remove_User(users);
            break;
        case 5:
            Allocate_Book_to_User(users, books, issued_books);
            break;
        case 6:
            Deallocate_Book_from_User(users, books, issued_books);
            break;
        case 7:
            cin.ignore();
            cout << "Id of User to find: ";
            getline(cin, id);
            id = input_check(id);
            History_of_User(users, id);
            break;
        case 8:
            cin.ignore();
            cout << "Name of book to find: ";
            getline(cin, name);
            name = input_check(name);
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
            Update_csv_from_issued_books(issued_books);
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
        case 18:
            //     // string temp = "";
            cout << "Issued_Book ID = ";
            cin.ignore();
            getline(cin, id);
            id = input_check(id);
            index = does_the_issued_book_exists(id);
            if (index == -1)
            {
                cout << "Issued Book doesn't exist" << endl;
            }
            cout << "DATA = " << issued_books[index].get_issued_book_data() << endl;
            break;
        case 19:
            // string temp = "";
            Update_users_from_csv(users);
            cout << "Users updated from csv";
            break;
        case 20:
            // string temp = "";
            Update_Books(books);
            cout << "Books updated from csv";
            break;
        case 21:
            // string temp = "";
            Update_Issued_Books(issued_books);
            cout << "Issued Books updated from csv";
            break;
        case 22:
            cin.ignore();
            getline(cin, temp);
            cout << input_check(temp) << endl;
            break;
        default:
            cout
                << "Invalid Input"
                << endl;
            break;
        }
    }
}