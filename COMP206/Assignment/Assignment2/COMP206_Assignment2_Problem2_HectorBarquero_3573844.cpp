//: COMP206_Assignment2_Problem2_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment2_Problem2_HectorBarquero_STUDENT_ID.cpp
 Description: Store and display private book attributes using public accessors.
 Date: Jun 28, 2026
 Author: Hector Barquero
 Version: 1.6
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Defines a book class where title, ISBN, author, edition, publisher and publication year are private. 
    Public get and set methods provide controlled access to every attrib. main() creates and displays several books.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment2_Problem2_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment2_Problem2_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment2_Problem2_HectorBarquero_STUDENT_ID.exe

 Classes:
    Book - stores book attribs and provides public accessors

 Variables:
    title - string - book title
    isbn - string - ISBN id
    author - string - author name
    edition - string - edition description
    publisher - string - publisher name
    publicationYear - int - year of publication
*/

/*
 TEST PLAN

 Normal case 1, parameterized construction:
    Construct a book with all six values and verify that display prints each value as specified.

 Normal case 2, setter methods:
    Construct an empty book, set six values, then verify each getter and the displayed output.

 Normal case 3, several obj:
    Create and display three book objects. Verify that each retains independent attrib values.

 Bad edge case 1, publication year zero:
    setPublicationYear(0) is accepted bc the assignment doesnt specify a valid year range. The getter returns 0 without changing it.

 Discussion:
    The attributes cannot be accessed directly outside Book. Returning strings by const reference avoids bad copies
    while keeping read only use of the program.
*/

#include <iostream>
#include <string>  

using namespace std;

// setup
class Book {
// private bc get set methods access, but the attribs are private
private:
    string title;
    string isbn;
    string author;
    string edition;
    string publisher;
    int publicationYear;

public:
    Book()
        : publicationYear(0) {
    }

    Book(const string& newTitle,
         const string& newIsbn,
         const string& newAuthor,
         const string& newEdition,
         const string& newPublisher,
         int newPublicationYear)
        : title(newTitle),
          isbn(newIsbn),
          author(newAuthor),
          edition(newEdition),
          publisher(newPublisher),
          publicationYear(newPublicationYear) {
    }

    const string& getTitle() const {
        return title;
    }

    void setTitle(const string& newTitle) {
        title = newTitle;
    }

    const string& getIsbn() const {
        return isbn;
    }

    void setIsbn(const string& newIsbn) {
        isbn = newIsbn;
    }

    const string& getAuthor() const {
        return author;
    }

    void setAuthor(const string& newAuthor) {
        author = newAuthor;
    }

    const string& getEdition() const {
        return edition;
    }

    void setEdition(const string& newEdition) {
        edition = newEdition;
    }

    const string& getPublisher() const {
        return publisher;
    }

    void setPublisher(const string& newPublisher) {
        publisher = newPublisher;
    }

    int getPublicationYear() const {
        return publicationYear;
    }

    void setPublicationYear(int newPublicationYear) {
        publicationYear = newPublicationYear;
    }

    void display() const {
        cout << "Title: " << getTitle() << '\n'
             << "ISBN: " << getIsbn() << '\n'
             << "Author: " << getAuthor() << '\n'
             << "Edition: " << getEdition() << '\n'
             << "Publisher: " << getPublisher() << '\n'
             << "Year: " << getPublicationYear() << "\n\n";
    }
};

// barquerohr: use primer data from my 4th edition reference book 
int main() {
    Book book1(
        "The C++ Programming Language",
        "978-0321563842",
        "Bjarne Stroustrup",
        "4th",
        "Addison-Wesley Professional",
        2013);

    Book book2;
    book2.setTitle("C++ Primer");
    book2.setIsbn("978-0321714114");
    book2.setAuthor("Stanley B. Lippman, Josée Lajoie and Barbara E. Moo");
    book2.setEdition("5th");
    book2.setPublisher("Addison-Wesley Professional");
    book2.setPublicationYear(2012);

    Book book3(
        "Programming: Principles and Practice Using C++",
        "978-0321992789",
        "Bjarne Stroustrup",
        "2nd",
        "Addison-Wesley Professional",
        2014);

    book1.display();
    book2.display();
    book3.display();

    return 0;
} ///:~