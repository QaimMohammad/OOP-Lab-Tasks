#include <iostream>
#include <vector>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(string t, string pDate, string uID, string pub)
        : title(t), publicationDate(pDate), uniqueID(uID), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << "Title: " << title << " | Publication Date: " << publicationDate
             << " | Publisher: " << publisher << " | Status: " 
             << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut() {
        if (isCheckedOut) {
            cout << title << " is already checked out." << endl;
        } else {
            isCheckedOut = true;
            cout << title << " has been checked out successfully." << endl;
        }
    }

    void returnItem() {
        if (!isCheckedOut) {
            cout << title << " is already available." << endl;
        } else {
            isCheckedOut = false;
            cout << title << " has been returned successfully." << endl;
        }
    }

    string getTitle() {
        return title;
    }

    string getPublisher() {
        return publisher;
    }
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pDate, string uID, string pub, string a, string isbn, int pages)
        : Media(t, pDate, uID, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        cout << "Book | " << title << " | Author: " << author << " | ISBN: " << ISBN
             << " | Pages: " << numberOfPages << " | Status: "
             << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    string getAuthor() {
        return author;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    double rating;

public:
    DVD(string t, string pDate, string uID, string pub, string dir, int dur, double rate)
        : Media(t, pDate, uID, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        cout << "DVD | " << title << " | Director: " << director << " | Duration: "
             << duration << " mins | Rating: " << rating << " | Status: "
             << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pDate, string uID, string pub, string art, string gen, int tracks)
        : Media(t, pDate, uID, pub), artist(art), genre(gen), numberOfTracks(tracks) {}

    void displayInfo() override {
        cout << "CD | " << title << " | Artist: " << artist << " | Genre: " << genre
             << " | Tracks: " << numberOfTracks << " | Status: "
             << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};

class Library {
private:
    vector<Media*> collection;

public:
    void addMedia(Media* media) {
        collection.push_back(media);
    }

    void searchMedia(string title) {
        bool found = false;
        for (auto media : collection) {
            if (media->getTitle() == title) {
                media->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "No media found with title: " << title << endl;
    }

    void searchMedia(string author, bool isBook) {
        if (!isBook) return;
        bool found = false;
        for (auto media : collection) {
            Book* book = dynamic_cast<Book*>(media);
            if (book && book->getAuthor() == author) {
                book->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "No books found by author: " << author << endl;
    }

    void displayAll() {
        if (collection.empty()) {
            cout << "No media available in the library." << endl;
            return;
        }
        for (auto media : collection)
            media->displayInfo();
    }
};

int main() {
    Library lib;

    Book* b1 = new Book("C++ Programming", "2020", "B101", "TechPress", "John Doe", "123456789", 450);
    DVD* d1 = new DVD("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD* c1 = new CD("Thriller", "1982", "C303", "Epic Records", "Michael Jackson", "Pop", 9);

    lib.addMedia(b1);
    lib.addMedia(d1);
    lib.addMedia(c1);

    lib.displayAll();

    b1->checkOut();
    b1->returnItem();

    lib.searchMedia("Inception");
    lib.searchMedia("John Doe", true);

    delete b1;
    delete d1;
    delete c1;

    return 0;
}

