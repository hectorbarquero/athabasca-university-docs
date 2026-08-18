//: COMP206_Assignment3_Problem5_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment3_Problem5_HectorBarquero_STUDENT_ID.cpp
 Description: Store, display and sort 12 book objects in a vector.
 Date: July 16, 2026
 Author: Hector Barquero
 Version: 1.4
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Define a Book class with private bibliographic attr and public get/set methods. Create 12 books in a Bookshelf class,
    display them in insertion order, sort by title and publication year, and display them again.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment3_Problem5_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment3_Problem5_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment3_Problem5_HectorBarquero_STUDENT_ID.exe

 Notes:
    The assignment using a Java term `ArrayList` which is represented by std::vector<Book>.
    BookComparator::compareTo() returns bool, as required by std::sort. "Book name" is interpreted as the book title.

 Classes:
    Book - stores one book's private bibliographic attributes
    BookComparator - compares titles first and publication years second
    Bookshelf - creates, displays and sorts the collection of twelve books

 Functions:
    Book constructors - create empty or fully initialized books
    get/set methods - provide controlled access to each private attribute
    display() - displays every attribute of one book
    BookComparator::compareTo() - defines ascending title/year ordering
    BookComparator::operator()() - lets std::sort use compareTo()
    Bookshelf::displayBooks() - displays each book in a vector
    Bookshelf::run() - creates, displays, sorts and redisplays the bookshelf
    main() - runs the Bookshelf demonstration

 Variables:
    title, isbn, author, edition, publisher - string - book text attributes
    publicationYear - int - year in which the book was published
    books - vector<Book> - twelve Book objects in insertion or sorted order
*/

/*
 TEST PLAN

 Normal case 1, insertion order:
    Verify the first list contains twelve books in the same order used in run().

 Normal case 2, title sorting:
    Verify titles appear alphabetically in the second list.

 Normal case 3, equal titles:
    Two books are titled "C++ Primer" and have publication years 2012 and 2013.
    Expected result: the 2012 edition appears before the 2013 edition.

 Normal case 4, attribute access:
    Create a Book, set each field with its setter and verify each getter returns
    the assigned value.

 Structural test:
    Verify both displayed lists contain exactly twelve books.

 Discussion:
    Displaying n books takes O(n) time. std::sort performs O(n log n) comparisons on avg and in the worst case 
    for this implementation. Each comparison checks titles and may then check years, both treated as constant sized fields. 
    The vector stores O(n) books, and std::sort uses O(log n) auxiliary stack space.
*/

#include <algorithm> // sort func
#include <iostream> 
#include <string>  
#include <utility>   // move func
#include <vector>   

using namespace std;

class Book {
private:
    string title;
    string isbn;
    string author;
    string edition;
    string publisher;
    int publicationYear = 0;

public:
    Book() = default;

    Book(string newTitle,
         string newIsbn,
         string newAuthor,
         string newEdition,
         string newPublisher,
         int newPublicationYear)
        : title(move(newTitle)),
          isbn(move(newIsbn)),
          author(move(newAuthor)),
          edition(move(newEdition)),
          publisher(move(newPublisher)),
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
        cout << "Title: " << title << '\n'
             << "ISBN: " << isbn << '\n'
             << "Author: " << author << '\n'
             << "Edition: " << edition << '\n'
             << "Publisher: " << publisher << '\n'
             << "Publication year: " << publicationYear << "\n\n";
    }
};

class BookComparator {
public:
    bool compareTo(const Book& first, const Book& second) const {
        if (first.getTitle() != second.getTitle()) {
            return first.getTitle() < second.getTitle();
        }

        return first.getPublicationYear() < second.getPublicationYear();
    }

    bool operator()(const Book& first, const Book& second) const {
        return compareTo(first, second);
    }
};

class Bookshelf {
private:
    static void displayBooks(const vector<Book>& books) {
        for (size_t index = 0; index < books.size(); ++index) {
            cout << "Book " << index + 1 << '\n';
            cout << "------\n";
            books[index].display();
        }
    }

public:
    static int run() {
        vector<Book> books{
            {"The C++ Programming Language", "9780321563842", "Bjarne Stroustrup", "4th", "Addison-Wesley", 2013},
            {"Clean Code", "9780132350884", "Robert C. Martin", "1st", "Prentice Hall", 2008},
            {"C++ Primer", "9780321714114", "Stanley Lippman", "5th", "Addison-Wesley", 2012},
            {"Design Patterns", "9780201633610", "Erich Gamma et al.", "1st", "Addison-Wesley", 1994},
            {"Effective Modern C++", "9781491903995", "Scott Meyers", "1st", "O'Reilly Media", 2014},
            {"Programming: Principles and Practice Using C++", "9780321992789", "Bjarne Stroustrup", "2nd", "Addison-Wesley", 2014},
            {"C++ Primer", "9780321741133", "Stanley Lippman", "Special", "Addison-Wesley", 2013},
            {"The Pragmatic Programmer", "9780135957059", "David Thomas and Andrew Hunt", "20th Anniversary", "Addison-Wesley", 2019},
            {"Algorithms", "9780321573513", "Robert Sedgewick and Kevin Wayne", "4th", "Addison-Wesley", 2011},
            {"Code Complete", "9780735619678", "Steve McConnell", "2nd", "Microsoft Press", 2004},
            {"A Tour of C++", "9780136816485", "Bjarne Stroustrup", "3rd", "Addison-Wesley", 2022},
            {"Effective C++", "9780321334879", "Scott Meyers", "3rd", "Addison-Wesley", 2005}
        };

        cout << "Books in insertion order\n";
        cout << "========================\n\n";
        displayBooks(books);

        sort(books.begin(), books.end(), BookComparator{});

        cout << "Books sorted by title, then publication year\n";
        cout << "============================================\n\n";
        displayBooks(books);

        return 0;
    }
};

int main() {
    return Bookshelf::run();
} ///:~
