#include <iostream>
#include <vector>

class Seat {
public:
    int id;
    bool booked;

    Seat(int id) : id(id), booked(false) {}
};

class Cinema {
private:
    std::vector<Seat> seats;
    int rows;
    int cols;

public:
    Cinema(int rows, int cols) : rows(rows), cols(cols) {
        for (int i = 1; i <= rows * cols; ++i) {
            seats.push_back(Seat(i));
        }
    }

    void displaySeats() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int index = i * cols + j;
                std::cout << (seats[index].booked ? "[X]" : "[ ]") << " ";
            }
            std::cout << std::endl;
        }
    }

    bool bookSeat(int seatId) {
        if (seatId < 1 || seatId > rows * cols) {
            std::cout << "Invalid seat number." << std::endl;
            return false;
        }
        if (seats[seatId - 1].booked) {
            std::cout << "Seat already booked." << std::endl;
            return false;
        }
        seats[seatId - 1].booked = true;
        std::cout << "Seat " << seatId << " booked successfully." << std::endl;
        return true;
    }
};

int main() {
    int rows = 5;
    int cols = 5;
    Cinema cinema(rows, cols);

    int choice;
    do {
        std::cout << "\nSeat Booking Management System" << std::endl;
        std::cout << "1. Display Seats" << std::endl;
        std::cout << "2. Book a Seat" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                cinema.displaySeats();
                break;
            case 2:
                int seatId;
                std::cout << "Enter seat number to book: ";
                std::cin >> seatId;
                cinema.bookSeat(seatId);
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
