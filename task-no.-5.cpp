#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Movie {
    string title;
    int duration;
    int price;
};
struct Seat {
    int row;
    int column;
    bool isBooked;
};
void displayMovieListings(const vector<Movie>& movies) {
    cout << "Movie Listings:" << endl;
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << (i + 1) << ". " << movies[i].title << " (" << movies[i].duration << " minutes, Rs " << movies[i].price << ")" << endl;
    }
}
void displaySeatLayout(const vector<vector<Seat>>& seats) {
    cout << "Seat Layout:" << endl;
    for (const auto& row : seats) {
        for (const auto& seat : row) {
            if (seat.isBooked) {
                cout << "X ";
            } else {
                cout << seat.row << seat.column << " ";
            }
        }
        cout << endl;
    }
}
void bookSeat(vector<vector<Seat>>& seats, int row, int column) {
    if (seats[row][column].isBooked) {
        cout << "Seat is already booked." << endl;
    } else {
        seats[row][column].isBooked = true;
        cout << "Seat booked successfully." << endl;
    }
}
int calculateTotalCost(const vector<Movie>& movies, int movieIndex, int numSeats) {
    return movies[movieIndex].price * numSeats;
}
int main() {
    vector<Movie> movies = {
        {"Movie 1", 120, 800},
        {"Movie 2", 150, 960},
        {"Movie 3", 180, 1200}
    };
    vector<vector<Seat>> seats(5, vector<Seat>(5));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            seats[i][j].row = i + 1;
            seats[i][j].column = j + 1;
            seats[i][j].isBooked = false;
        }
    }
    while (true) {
        cout << "Movie Ticket Booking System." << endl;
        cout << "1. View Movie Listings" << endl;
        cout << "2. View Seat Layout" << endl;
        cout << "3. Book Seat" << endl;
        cout << "4. Calculate Total Cost" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                displayMovieListings(movies);
                break;
            case 2:
                displaySeatLayout(seats);
                break;
            case 3: {
                int movieIndex;
                cout << "Enter movie index (1-3): ";
                cin >> movieIndex;
                --movieIndex;
                int row, column;
                cout << "Enter seat row (1-5): ";
                cin >> row;
                cout << "Enter seat column (1-5): ";
                cin >> column;
                --row; --column;
                bookSeat(seats, row, column);
                break;
            }
            case 4: {
                int movieIndex;
                cout << "Enter movie index (1-3): ";
                cin >> movieIndex;
                --movieIndex;
                int numSeats;
                cout << "Enter number of seats: ";
                cin >> numSeats;
                int totalCost = calculateTotalCost(movies, movieIndex, numSeats);
                cout << "Total cost: Rs " << totalCost << endl;
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }
    return 0;
}

