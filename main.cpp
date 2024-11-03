#include <iostream>
#include "Inventory.h"


using namespace std;

#include <iostream>
#include "Inventory.h"

using namespace std;
using namespace InventorySystem;

int main() {
    vector<BookInfo> books;
    vector<BookLocation> locations;

    // Create and add a book
    BookInfo book1 = {
        "The Great Gatsby",       // bookTitle
        "1925",                   // publishDate
        "Fiction",                // bookGenre
        "9780743273565",          // bookISBN
        "Scribner",               // bookPublisher
        "Hardcover",              // bookFormat
        "English",                // bookLanguage
        "F. Scott Fitzgerald"     // bookAuthor
    };
    BookLocation location1 = { 1, "top", 2, "Fiction" };
    addBook(books, locations, book1, location1);

    // Create a book to find (only ISBN is necessary for search)
    BookInfo searchBook = { "", "", "", "9780743273565", "", "", "", "" };
    BookLocation foundLocation;

    // Search for the book
    BookInfo* foundBook = findBook(books, locations, searchBook, foundLocation);
    if (foundBook) {
        cout << "Book found: " << foundBook->bookTitle << " by " << foundBook->bookAuthor << endl;
        cout << "Location: Aisle " << foundLocation.aisleNumber << ", " << foundLocation.shelfPosition
            << " shelf, Row " << foundLocation.rowNumber << ", Section " << foundLocation.sectionName << endl;
    }
    else {
        cout << "Book not found." << endl;
    }

    return 0;
}