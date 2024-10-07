// COMSC-210 | Lab 19: Abstract & Automate Lab 18 | Nina Tsao
// Reference: https://cplusplus.com/forum/beginner/269971/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>  // rand(), srand()
#include <iomanip>  // set precision
using namespace std;

struct Node {
    double rating;
    string comments;
    Node *next;
};

class Movie {
private:
    string title;
    Node *head = nullptr;

public:
    string getTitle() const {return title;}
    void setTitle(string t) {title = t;}

    void outputReviews() {
        cout << "Reviews of the movie -- " << title << endl;
        Node *current = head;
        int i = 0;

        while (current != nullptr) {    // while current is not empty, same as while(!current)
            cout << "\t> Review #" << ++i << ": ";
            cout << fixed << setprecision(1) << current->rating << ": " << current->comments << endl;

            current = current->next;    // set the next node to current and review the data
        }
    }

    void addNodesToHead(double rating, string comments) {
        Node *newNode = new Node;       // add new node
        newNode->rating = rating;       // add rating in new node
        newNode->comments = comments;   // add comments in new node
        newNode->next = head;           // add new node in head
        head = newNode;
    }
};

int main() {
    const int SIZE = 2;
    srand(time(0));

    vector<Movie> movie(SIZE);  // 2 Movie objects
    ifstream fin;
    fin.open("comments.txt");

    if (fin.good()) {
        string title, comments;
        double rating;
        
        for (int i = 0; i < SIZE ; i++) {
            getline(fin, title);
            movie[i].setTitle(title);

            for (int j = 0; j < 2 ; j++) {
                getline(fin, comments);
                rating = (rand() / (double)RAND_MAX) * (5.0 - 1.0) + 1.0;
                movie[i].addNodesToHead(rating, comments);
            }
        }

        fin.close();
    }
    else {
        cout << "File not found." << endl;
        return 1;
    }

    for (auto i: movie)
        i.outputReviews();     // output the data after entered all the informations

    return 0;
}