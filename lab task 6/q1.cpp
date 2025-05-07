#include <iostream>
#include <string>
using namespace std;

class Books {
protected:
    string genre;
public:
    void setGenre(const string& g) {
        genre = g;
    }

    void displayGenre() {
        cout << "Genre: " << genre << endl;
    }
};

class Novel : public Books {
private:
    string title;
    string author;
public:
    void setDetails(const string& t, const string& a) {
        title = t;
        author = a;
    }

    void displayDetails() {
        displayGenre();
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;
public:
    void setDetails(const string& t, const string& a) {
        title = t;
        author = a;
    }

    void displayDetails() {
        displayGenre();
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    Novel novel;
    Mystery mystery;

    novel.setGenre("Novel");
    novel.setDetails("Pride and Prejudice", "Jane Austen");
    
    mystery.setGenre("Mystery");
    mystery.setDetails("Sherlock Holmes", "Arthur Conan Doyle");

    cout << "\nNovel Details:\n";
    novel.displayDetails();

    cout << "\nMystery Details:\n";
    mystery.displayDetails();

    return 0;
}


