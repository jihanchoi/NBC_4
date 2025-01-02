#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author));
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    struct Find
    {
        string search;
        bool operator()(Book book) {
            return ((book.author == search) && (book.title == search));
        }
    };

    void bookSearch(string search) {
        Find find;
        find.search = search;
        vector<Book>::iterator bookSearch;
        bookSearch = find_if(books.begin(), books.end(), find);
        if (bookSearch == books.end()) {
            cout << "ã�� ���Ͽ����ϴ� \n";
            return ;
        }
        cout << bookSearch->title << " / " << bookSearch->author << endl;
    }
};

int main() {
    BookManager manager;

    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;
        cout << "2. ��� å ���" << endl;
        cout << "3. �˻��ϱ�" << endl;
        cout << "4. ����" << endl;
        cout << "����: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "å ����: ";
            cin.ignore();
            getline(cin, title);
            cout << "å ����: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2) {
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            string search;
            cout << "å �̸� or �۰��� �Է��ϼ���" << endl;
            cin.ignore();
            cin >> search;
            manager.bookSearch(search);
        }
        else if (choice == 4) {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0;
}