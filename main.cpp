//Ezzat Mohamadein | ComSc 210 | Lab 18
using namespace std;
#include <iostream>

//define review node
struct Review {
    double rating;
    string comment;
    //constructor and next pointer
    public:
    Review(int r, string c);
    Review* next;
};

int main() {
    //create linked list
    Review* head;
    //ask user for mode
    int mode;
    cout << "Select mode: Add nodes at head (1) or Add nodes at tail (2): ";
    cin >> mode;
    cout << endl;
    //ask user for review
    double r;
    string c;
    cout<< "Review 1:" << endl << "Enter rating (1-5): ";
    cin >> r;
    cout <<"Enter comment: ";
    cin.ignore();
    getline(cin, c);
    //create new review node
    head = new Review(r, c);
    //ask for second review
    cout<< endl << "Review 2:" << endl << "Enter rating (1-5): ";
    cin >> r;
    cout << "Enter comment: ";
    cin.ignore();
    getline(cin, c);
    //create new review node
    Review* r2 = new Review(r, c);
    //add second review to linked list
    if (mode == 1) {
        r2->next = head;
        head = r2;
    } else if (mode == 2) {
        head->next = r2;
    } else {
        cout << "Invalid mode selected. Exiting program." << endl;
        return 1;
    }

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

    //delete linked list
    current = nullptr;
    while (head != nullptr) {
        Review* prev = head;
        head = head->next;
        delete prev;
    }
    return 0;
}

//define constructor
Review::Review(int r, string c) {
    rating = r;
    comment = c;
    next = nullptr;
}