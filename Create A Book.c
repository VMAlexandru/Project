#include <iostream>
#include <string>

using namespace std;

// Structura unui nod
struct Node {
    string title;
    string author;
    string language;
    string type;
    int year;
    int pages;
    string publisher;
    string link;
    Node* next;
    Node* prev;

    Node(string t, string a, string l, string ty, int y, int p, string pub, string lk)
        : title(t), author(a), language(l), type(ty), year(y), pages(p), publisher(pub), link(lk), next(nullptr), prev(nullptr) {}
};

// Clasa pentru Deque
class Deque {
private:
    Node* front;
    Node* back;
    int count;

public:
    Deque() : front(nullptr), back(nullptr), count(0) {}

    // Adaugă un nod la început
    void pushFront(string t, string a, string l, string ty, int y, int p, string pub, string lk) {
        Node* newNode = new Node(t, a, l, ty, y, p, pub, lk);
        if (!front) {
            front = back = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        count++;
    }

    // Adaugă un nod la sfârșit
    void pushBack(string t, string a, string l, string ty, int y, int p, string pub, string lk) {
        Node* newNode = new Node(t, a, l, ty, y, p, pub, lk);
        if (!back) {
            front = back = newNode;
        } else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        count++;
    }

    // Șterge un nod de la început
    void popFront() {
        if (!front) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            back = nullptr;
        }
        delete temp;
        count--;
    }

    // Șterge un nod de la sfârșit
    void popBack() {
        if (!back) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = back;
        back = back->prev;
        if (back) {
            back->next = nullptr;
        } else {
            front = nullptr;
        }
        delete temp;
        count--;
    }

    // Afișează conținutul deque-ului
    void display() {
        if (!front) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* current = front;
        while (current) {
            cout << "Title: " << current->title << ", Author: " << current->author
                 << ", Language: " << current->language << ", Type: " << current->type
                 << ", Year: " << current->year << ", Pages: " << current->pages
                 << ", Publisher: " << current->publisher << ", Link: " << current->link << endl;
            current = current->next;
        }
    }

    // Afișează numărul de noduri
    int size() {
        return count;
    }
};

// Funcția principală
int main() {
    Deque deque;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add node to front\n";
        cout << "2. Add node to back\n";
        cout << "3. Remove node from front\n";
        cout << "4. Remove node from back\n";
        cout << "5. Display deque\n";
        cout << "6. Display number of nodes\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string t, a, l, ty, pub, lk;
                int y, p;
                cout << "Enter title: "; cin.ignore(); getline(cin, t);
                cout << "Enter author: "; getline(cin, a);
                cout << "Enter language: "; getline(cin, l);
                cout << "Enter type: "; getline(cin, ty);
                cout << "Enter year: "; cin >> y;
                cout << "Enter pages: "; cin >> p;
                cin.ignore();
                cout << "Enter publisher: "; getline(cin, pub);
                cout << "Enter link: "; getline(cin, lk);
                deque.pushFront(t, a, l, ty, y, p, pub, lk);
                break;
            }
            case 2: {
                string t, a, l, ty, pub, lk;
                int y, p;
                cout << "Enter title: "; cin.ignore(); getline(cin, t);
                cout << "Enter author: "; getline(cin, a);
                cout << "Enter language: "; getline(cin, l);
                cout << "Enter type: "; getline(cin, ty);
                cout << "Enter year: "; cin >> y;
                cout << "Enter pages: "; cin >> p;
                cin.ignore();
                cout << "Enter publisher: "; getline(cin, pub);
                cout << "Enter link: "; getline(cin, lk);
                deque.pushBack(t, a, l, ty, y, p, pub, lk);
                break;
            }
            case 3:
                deque.popFront();
                break;
            case 4:
                deque.popBack();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Number of nodes: " << deque.size() << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
