#ifndef Inventory_h
#define Inventory_h

using namespace std;

#include <string>
#include <vector>

namespace InventorySystem {

    // BookInfo structure
    struct BookInfo {
        string bookTitle;
        string publishDate;
        string bookGenre;
        string bookISBN;
        string bookPublisher;
        string bookFormat; // e.g., hardcover, paperback, eBook
        string bookLanguage;
        string bookAuthor;

        // Overloaded operator!= for comparison
        bool operator!=(const BookInfo& other) const;
    };

    // BookLocation structure
    struct BookLocation {
        int aisleNumber;
        string shelfPosition; // e.g., top, middle, bottom
        int rowNumber;
        string sectionName; // e.g., Fiction, Non-Fiction
    };

    void addBook(vector<BookInfo>& books, vector<BookLocation>& locations, const BookInfo& book, const BookLocation& location);
    BookInfo* findBook(const vector<BookInfo>& books, const vector<BookLocation>& locations, const BookInfo& userInfo, BookLocation& location);

    // Operator overloading for adding a book
    vector<BookInfo>& operator+=(vector<BookInfo>& books, const BookInfo& book);
    vector<BookLocation>& operator+=(vector<BookLocation>& locations, const BookLocation& location);
}
#endif
