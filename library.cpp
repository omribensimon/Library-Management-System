#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class temp
{
    string id, name, author, search;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
};

void temp::addBook()
{
    cout << "\nEnter Book ID: ";
    cin.ignore();
    getline(cin, id);
    cout << "Enter Book Name: ";
    getline(cin, name);
    cout << "Enter Book's Author Name: ";
    getline(cin, author);

    file.open("bookData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << id << "*" << name << "*" << author << endl;
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }

    cout << "Book Added Successfully" << endl;
    cout << endl;
}

void temp::showAll()
{
    file.open("bookData.txt", ios::in);
    if (file.is_open()) {
        cout << "\n\n";
        cout << "Book id\t\tBook Name\t\tAuthor's Name" << endl;

        while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
            cout << id << "\t\t" << name << "\t\t" << author << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
    cout << endl;

}

void temp::extractBook()
{
    cout << "Enter Book ID: ";
    cin.ignore();
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (file.is_open()) {
        cout << "\n\n";
        cout << "Book id\t\tBook Name\t\tAuthor's Name" << endl;
        bool found = false;

        while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author, '\n')) {
            if (search == id) {
                cout << id << "\t\t" << name << "\t\t" << author << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }

        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
    cout << endl;

}

int main()
{
    temp obj;
    char choice;

    cout << "Library Management System\n";
    cout << "---------------------------\n";
    cout << "1 - Show All Books\n";
    cout << "2 - Extract Book\n";
    cout << "3 - Add Books (Admin)\n";
    cout << "4 - Exit\n";
    cout << "---------------------------\n";
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice) {
    case '1':
        obj.showAll();
        break;
    case '2':
        obj.extractBook();
        break;
    case '3':
        obj.addBook();
        break;
    case '4':
        return 0;
    default:
        cout << "Invalid Choice" << endl;
    }

    cin.ignore();
    return main();
}
