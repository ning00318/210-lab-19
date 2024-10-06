// COMSC-210 | Lab 19: Abstract & Automate Lab 18 | Nina Tsao

#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    float rating;
    string comments;
    Node *next;
};

class Movie {
private:
    string title;
    Node *head;

public:
    string getTitle() const {return title;}
    void setTitle(string t) {title = t;}

    void outputReviews() {
        cout << "Outputting all reviews:" << endl;
        Node *current = head;
        int i = 0;

        while (current != nullptr) {    // while current is not empty, same as while(!current)
            cout << "\t> Review #" << ++i << ": ";
            cout << current->rating << ": " << current->comments << endl;

            current = current->next;    // set the next node to current and review the data
        }
    }

    void addNodesToHead(float rating, string comments) {
        Node *newNode = new Node;       // add new node
        newNode->rating = rating;       // add rating in new node
        newNode->comments = comments;   // add comments in new node
        newNode->next = head;           // add new node in head
        head = newNode;
    }
};

int main() {
    const int SIZE = 2;

    vector<Movie> movie(SIZE);
    ifstream fin;
    fin.open("comments.txt");

    if (fin.good()) {
        cout << "Works well!" << endl;
        
        for (int i = 0; i < SIZE ; i++) {

        }

        fin.close();
    }
    else {
        cout << "File not found." << endl;
        return 1;
    }

    Node *head = nullptr;   // initialize
    outputReviews(head);     // output the data after entered all the informations

    return 0;
}