#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookName;
    string ISBN;
    string author;
    string publisher;

public:
    // Constructor
    Book(string name, string isbn, string auth, string pub)
        : bookName(name), ISBN(isbn), author(auth), publisher(pub) {}

    // Query methods
    string getBookName() { return bookName; }
    string getISBN() { return ISBN; }
    string getAuthor() { return author; }
    string getPublisher() { return publisher; }

    // Method to get book description
    string getBookInfo() {
        return "Book Name: " + bookName + "\nISBN: " + ISBN + "\nAuthor: " + author + "\nPublisher: " + publisher;
    }
};

int main() {
    // Creating an array of Book objects
    Book books[5] = {
        Book("The Great Gatsby", "9780743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("1984", "9780451524935", "George Orwell", "Secker & Warburg"),
        Book("To Kill a Mockingbird", "9780061120084", "Harper Lee", "J.B. Lippincott & Co."),
        Book("Moby-Dick", "9780142437247", "Herman Melville", "Harper & Brothers"),
        Book("The Catcher in the Rye", "9780316769488", "J.D. Salinger", "Little, Brown and Company")
    };

    // Displaying book information
    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << i + 1 << " Info:\n";
        cout << books[i].getBookInfo() << endl;
    }

    return 0;
}


