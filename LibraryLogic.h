#pragma once
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isAvailable = true;
};

static vector<Book> library;

inline void addBook(int id, string title, string author) {
    Book newBook = { id, title, author, true };
    library.push_back(newBook);
}

inline string getBooks() {
    if (library.empty()) {
        return "Library is empty!\n";
    }

    string result = "Books in Library:\n";
    for (const auto& book : library) {
        result += "ID: " + to_string(book.id) + ", Title: " + book.title + ", Author: " + book.author
            + ", Available: " + (book.isAvailable ? "Yes" : "No") + "\n";
    }
    return result;
}
