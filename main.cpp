//Ezzat Mohamadein | ComSc 210 | Lab 18
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>

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
    string getTitle() {return title;}
};

//output function prototype
void output(Review* head);
//delete linked list function prototype
void deleteList(Review* head);

int main() {
    //create movie vector
    vector<Movie> movies;
    //add movies to vector
    movies.push_back(Movie("Movie 1"));
    movies.push_back(Movie("Movie 2"));
    movies.push_back(Movie("Movie 3"));
    movies.push_back(Movie("Movie 4"));
    //add reviews to movies using comments from comments.txt and randomized ratings
    ifstream fin("comments.txt");
    int c = 3;
    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < c; j++) {
            string comment;
            getline(fin, comment);
            double rating = rand() % 5 + 1;
            Review* newReview = new Review(rating, comment);
            if (movies[i].head == nullptr) {
                movies[i].head = newReview;
            } else {
                Review* current = movies[i].head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newReview;
            }
        }
    }
    fin.close();
    //output reviews for each movie
    for (int i = 0; i < movies.size(); i++) {
        cout << "Reviews for " << movies[i].getTitle() << ":" << endl;
        output(movies[i].head);
    }
    //delete linked lists
    for (int i = 0; i < movies.size(); i++) {
        deleteList(movies[i].head);
    }

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
    cout << endl << "Average rating: " << sum / (count - 1) << endl << endl;
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