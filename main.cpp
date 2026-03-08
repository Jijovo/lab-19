//Ezzat Mohamadein | ComSc 210 | Lab 18
using namespace std;
#include <iostream>
#include <vector>

//define review node
struct Review {
    double rating;
    string comment;
    //constructor and next pointer
    public:
    Review(int r, string c);
    Review* next;
};

//define movie class
class Movie {
    string title;

    public:
    Movie(string t);
    Review* head;
};

//output function prototype
void output(Review* head);
//delete linked list function prototype
void deleteList(Review* head);

int main() {
    

    return 0;
}

//define Review constructor
Review::Review(int r, string c) {
    rating = r;
    comment = c;
    next = nullptr;
}

//define Movie constructor
Movie::Movie(string t) {
    title = t;
    head = nullptr;
}

//define output function
void output(Review* head) {
    //print linked list
    Review* current = head;
    int count = 1;
    double sum = 0;
    cout << endl;
    while (current != nullptr) {
        cout << "Review " << count << ":" << endl;
        cout << "Rating: " << current->rating << endl;
        cout << "Comment: " << current->comment << endl;
        sum += current->rating;
        current = current->next;
        count++;
    }
    //print average rating
    cout << endl << "Average rating: " << sum / (count - 1) << endl;
    current = nullptr;
}

//define delete linked list function
void deleteList(Review* head) {
    //delete linked list
    while (head != nullptr) {
        Review* prev = head;
        head = head->next;
        delete prev;
    }
}