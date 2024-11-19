### Group 9 Library Management System 

## Steps for running code
1. Open the Code file in VS Code(Trying to run in DevC++ can result in error as we are directly making changes in CSV file)

2. Compile and run the index.cpp file


### Steps on how the program runs 
1. When first timing running the code will read all the User_data.csv,Book_data.csv and Issued_books.csv for any existing data.
   -If any User data already exits then the code will Create a class of the Users and will append it in the users(users is a vector of  Users class)
   -If any Book data already exists then the code first check the genre of the Book and then accordingly Create a class of the particular genre(Ex. mystery book) and will append it in the books(books is a vector of  Books class) and genre specific vector of that genre's class
   -If any Issued books already exits then the code will Create a class of the Issued books and will append it in the issued_books(issued_books is a vector of  Issued_books class)

2. First Add a User by choosing the Add User option in terminal(This will write the user details in the User_data.csv file)
 -  The User have to provide details like phone no, email id, Name, Unique User_id. 

3. Add Books by choosing "Add Book" option in the terminal(This will write the user details in the User_data.csv file)
 -  The Book's detail will be need in order to keep track of it, details like (Unique book name , total book no, Author, Genre,Subject)

4. You can add as many Books as well as Users as you want without thinking of data being lost(All the data is being stored and can be easily retrieved)

5. A User can issue any book in the library if the book exists in the library and its available count is not ZERO by using the (Allocate book feature).

6. The issued book's details (issued time, user_id, Book_name and resubmission time) and saved in the Issued_books.csv file with a unique key for identification of issued book

7. This issued_book identification key will be stored in Users details existing in the User_data.csv file

8. A book can be unissued by simply using "Dealocate book" option in the terminal(this will first run some validation to check if the issued book exists by taking issued_book_id as input).

9. If the issued book exists then in the issued book's data the current time will be added in the "date of return" timeslot and then issued book unique id will be removed from the respective Users "Ongoing issued books id"

10. We have given options to the client to change Users, Books and Issued_books data directly in the csv file and run options like Update_Users_from_csv,Update_Books_from_csv and Update_Issued_books_from_csv

11. If the data somehow got deleted while the code is still running then you can run command's like Update_csv_from_users,Update_csv_from_books and Update_csv_from_issued_books.

12. Client can see specific book, users or issued book data by using History_of_book, Histor_of_user and History_of_Issued_books features

13. If the client wants to get all users, books or Issued_books data while running the code then features like Show_all_users, Show_all_books and Show_all_issued_books can be used

