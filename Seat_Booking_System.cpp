#include<iostream>
#include<string>
#include<vector>
using namespace std;
void displaySeatLayout(const vector<vector<int>>& seats) {
    for(int i=0;i<12;i++){
        if(i==0){
            cout<<" Orchestra / Stalls \n";
        }
        if(i==5){
            cout<<"      Balcony      \n";
        }
        if(i==9){
            cout<<"    Upper Circle    \n";
        }
        cout<<"Row "<<i+1<<": ";
        for(int j=0;j<7;j++){
            cout<<seats[i][j]<<" "; // Display the seat layout
        }
        cout<<endl;
    }
}
void bookSingleSeat(vector<vector<int>>& seats, string& name) {
    int row, col;
    cout << "Enter row (1-12) and column (1-7) to book a single seat: ";
    cin >> row >> col;
    if(row < 1 || row > 12 || col < 1 || col > 7) {
        cout << "Invalid seat selection. Please try again.\n";
        return;
    }
    if(seats[row-1][col-1] == 0) {
        seats[row-1][col-1] = 1;
        cout <<"COngratulations!! "<<name<< " Seat booked successfully at Row " << row << ", Column " << col << ".\n";
        return;
    }else {
        cout << "Sorry, this seat is already booked.\n";
        return;
    }
}
void bookMultipleSeats(vector<vector<int>>& seats, string& name) {
    cout << "See the seat layout below:\n";
    displaySeatLayout(seats);
    cout << "Only Book the Block of seats in the same row.\n"
         << "And If there is no block of seats available in the same row, then book a single seat in that Block.\n";
    
    cout<< "Enter the row (1-12) and the number of seats to book in that row : ";
    int row, numSeats;
    cin >> row >> numSeats;
    if(row < 1 || row > 12 || numSeats < 1 || numSeats > 7) {
        cout << "Invalid input. Please try again.\n";
        return;
    }
    for(int i = 0; i < numSeats; i++){
        if(seats[row-1][i] != 0) {
            cout << "Seat at Row " << row << ", Column " << (i+1) << " is already booked.\n";
            cout << "If you want to book a single seat in that same block, then Give your input as Y (for yes) / N (for No).\n";
            char choice;
            cin >> choice;
            if(choice == 'Y' || choice == 'y') {
                bookSingleSeat(seats, name);
                return;
            }
            return;
        }
    }
    for(int i = 0; i < numSeats; i++){
        seats[row-1][i] = 1; // Mark the seats as booked
    }
    cout <<"COngratulations!! "<<name<< " Successfully booked " << numSeats << " seats in Row " << row << ".\n";
    return;
}
void cancelBooking(vector<vector<int>>& seats, string& name) {
    int row, col;
    cout << "Enter row (1-12) and column (1-7) to cancel a booking: ";
    cin >> row >> col;
    if(row < 1 || row > 12 || col < 1 || col > 7) {
        cout << "Invalid seat selection. Please try again.\n";
        return;
    }
    if(seats[row-1][col-1] == 1) {
        seats[row-1][col-1] = 0;
    }
    cout <<"COngratulations!! "<<name<< " Booking cancelled successfully at Row " << row << ", Column " << col << ".\n";
    displaySeatLayout(seats);
    return;
}
void availableSeats(const vector<vector<int>>& seats) {
    cout << "Available Seats:\n";
    for(int i = 0; i < 12; i++) {
        int sum = 0;
        for(int j = 0; j < 7; j++) {
            if(seats[i][j] == 0) {
                cout << "(" << (i + 1) << ", " << (j + 1) <<")"<< " seat is available.\n";
                sum++;
            }
        }
        cout << "-----------------------------------\n";
        cout <<"Toatal "<<sum<<" Seats are available in the Row "<<i<< endl;
        cout << "-----------------------------------\n";
    }
    return;
}
int main(){
    cout<<"Welcome to the Cinema Seat Booking System!\n"
        <<"=======================================\n";
        
    cout<<"Enter your name: ";
    string name;
    getline(cin, name);
    cout<<"Hello "<<name<<",\n";
    
    cout<<"This system allows you to book, cancel, and view cinema seats.\n"
        <<"You can also view the seat layout and check available seats.\n"
        <<"Please follow the instructions to proceed with your booking.\n"
        <<"=======================================\n"
        <<"Note: The seat layout consists of 12 rows and 7 columns.\n"
        <<"Please select an option from the menu below:\n"
        <<"====== Cinema Seat Booking Menu ======\n"
        <<"1. Veiw Seat Layout\n"
        <<"2. Book a Single Seat\n"
        <<"3. Book Multiple Seats or a Block of seats\n"
        <<"4. Cancel a Booking\n"
        <<"5. Display Available Seats Only\n"
        <<"6. Exit\n";
    cout<<"=======================================\n";
    vector<vector<int>>seats(12,vector<int>(7,0)); // Initialize 100 seats, all available (0)
    cout<<"Enter your choice (1-6) to proceed the function : ";
    int n;
    cin>>n;
    switch(n){
        case 1:
            cout<<"You have selected to view the seat layout.\n";
            displaySeatLayout(seats);
        break;
        case 2:
            cout<<"You have selected to book a single seat.\n";
            bookSingleSeat(seats, name);
        break;
        case 3:
            cout<<"You have selected to book multiple seats or a block of seats.\n";
            bookMultipleSeats(seats, name);
        break;
        case 4:
            cout<<"You have selected to cancel a booking.\n";
            cancelBooking(seats, name);
        break;
        case 5:
            cout<<"You have selected to display available seats only.\n";
            availableSeats(seats);
        break;
        case 6:
            cout<<"You have selected to exit the booking system.\n";
            cout<<"Thank you for using the Cinema Seat Booking System!\n";
        break;
        default:
            cout<<"Invalid choice! Please select a number between 1 and 6.\n";
        break;
    }
    return 0;
}