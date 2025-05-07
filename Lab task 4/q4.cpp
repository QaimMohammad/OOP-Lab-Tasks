#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    double price;
    string publisher;
    int stock;

public:
    Book(string auth, string tit, double pr, string pub, int stk)
        : author(auth), title(tit), price(pr), publisher(pub), stock(stk) {}

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    void displayBook() {
        cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << ", Publisher: " << publisher << ", Stock: " << stock << endl;
    }

    bool isAvailable(int requiredCopies) {
        return stock >= requiredCopies;
    }

    void reduceStock(int requiredCopies) {
        stock -= requiredCopies;
    }

    double getTotalCost(int copies) {
        return copies * price;
    }
};

class BookShop {
private:
    Book books[5] = {
        Book("J.K. Rowling", "Harry Potter", 20.0, "Bloomsbury", 5),
        Book("J.R.R. Tolkien", "The Hobbit", 15.0, "HarperCollins", 3),
        Book("George Orwell", "1984", 10.0, "Secker & Warburg", 2),
        Book("J.D. Salinger", "The Catcher in the Rye", 12.0, "Little, Brown and Company", 6),
        Book("Harper Lee", "To Kill a Mockingbird", 14.0, "J.B. Lippincott & Co.", 4)
    };

public:
    void searchBook(string title, string author, int requiredCopies) {
        for (int i = 0; i < 5; ++i) {
            if (books[i].getTitle() == title && books[i].getAuthor() == author) {
                books[i].displayBook();
                if (books[i].isAvailable(requiredCopies)) {
                    books[i].reduceStock(requiredCopies);
                    cout << "Total cost for " << requiredCopies << " copies: $" << books[i].getTotalCost(requiredCopies) << endl;
                } else {
                    cout << "Required copies not in stock." << endl;
                }
                return;
            }
        }
        cout << "Book not available." << endl;
    }
};

int main() {
    BookShop shop;
    string title, author;
    int requiredCopies;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter required copies: ";
    cin >> requiredCopies;

    shop.searchBook(title, author, requiredCopies);

    return 0;
}

