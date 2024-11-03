#include <iostream>
#include "Inventory.h"

namespace InventorySystem {
    // Implementing the operator!=
    bool BookInfo::operator!=(const BookInfo& other) const {
        return (bookISBN != other.bookISBN); // checking with ISBN *UNIQUE IDENTIFIER*
    }

    // Function to add a book to the inventory
    void addBook(vector<BookInfo>& books, vector<BookLocation>& locations, const BookInfo& book, const BookLocation& location) {
        // Check for duplicates
        for (const auto& existingBook : books) {
            if (existingBook.bookISBN == book.bookISBN) {
                cout << "Duplicate book found: " << book.bookTitle << endl;
                return;
            }
        }
        books += book; //Using the overload operator +=
        locations += location;
        cout << "Added book: " << book.bookTitle << endl;
    }

    // Function to find a book
    BookInfo* findBook(const vector<BookInfo>& books, const vector<BookLocation>& locations, const BookInfo& userInfo, BookLocation& location) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (!(userInfo != books[i])) { // Using the overloaded operator !=
                location = locations[i];
                return const_cast<BookInfo*>(&books[i]); // Found the book
            }
        }
        return nullptr; // Not found
    }

    // Overloaded operator+= for adding a book to the vector
    vector<BookInfo>& operator+=(vector<BookInfo>& books, const BookInfo& book) {
        books.push_back(book);
        return books;
    }

    // Overloaded operator+= for adding a location to the vector
    vector<BookLocation>& operator+=(vector<BookLocation>& locations, const BookLocation& location) {
        locations.push_back(location);
        return locations;
    }
}

