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

public:
    Movie(string t) {title = t;}

    void outputReviews(Node *head) {
        cout << "Outputting all reviews:" << endl;
        Node *current = head;
        int i = 0;
        float total = 0.0;

        while (current != nullptr) {    // while current is not empty, same as while(!current)
            cout << "\t> Review #" << ++i << ": ";
            cout << current->rating << ": " << current->comments << endl;

            total += current->rating;   // calculate the total rating
            current = current->next;    // set the next node to current and review the data
        }
        
        float average = total / i;
        cout << "\t> Average: " << average << endl;
    }

    Node *addNodesToHead(Node *head, float rating, string comments) {
        Node *newNode = new Node;       // add new node
        newNode->rating = rating;       // add rating in new node
        newNode->comments = comments;   // add comments in new node
        newNode->next = head;           // add new node in head

        return newNode;     // return new head to the new node
    }
};

int main() {
    Movie movie;

    ifstream fin;
    fin.open("comments.txt");
    
    Node *head = nullptr;   // initialize
    movie.outputReviews(head);     // output the data after entered all the informations

    return 0;
}