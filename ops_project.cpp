#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool isIssued;

public:
    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        isIssued = false;
    }

    int getID() { return bookID; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool getStatus() { return isIssued; }

    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << "Book \"" << title << "\" issued successfully!\n";
        } else {
            cout << "Book already issued.\n";
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            cout << "Book \"" << title << "\" returned successfully!\n";
        } else {
            cout << "Book was not issued.\n";
        }
    }

    void displayBook() {
        cout << "ID: " << bookID
             << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (isIssued ? "Issued" : "Available") 
             << endl;
    }
};
class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book \"" << title << "\" added successfully!\n";
    }

    void showAllBooks() {
        if (books.empty()) {
            cout << "No books in library.\n";
            return;
        }
        for (auto &b : books) {
            b.displayBook();
        }
    }

    void searchBook(int id) {
        for (auto &b : books) {
            if (b.getID() == id) {
                cout << "Book Found:\n";
                b.displayBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void issueBook(int id) {
        for (auto &b : books) {
            if (b.getID() == id) {
                b.issueBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void returnBook(int id) {
        for (auto &b : books) {
            if (b.getID() == id) {
                b.returnBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

int main() {
    Library lib;
    int choice, id;
    string title, author;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Book Title: "; getline(cin, title);
                cout << "Enter Author Name: "; getline(cin, author);
                lib.addBook(id, title, author);
                break;
            case 2:
                lib.showAllBooks();
                break;
            case 3:
                cout << "Enter Book ID to search: "; cin >> id;
                lib.searchBook(id);
                break;
            case 4:
                cout << "Enter Book ID to issue: "; cin >> id;
                lib.issueBook(id);
                break;
            case 5:
                cout << "Enter Book ID to return: "; cin >> id;
                lib.returnBook(id);
                break;
            case 0:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
