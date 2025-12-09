#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

const int n = 5;
const int price = 100;

struct Room {           // We need some structure for rooms in project, so it will include:
    int id;             // Number of room 
    int capacity;       // is room for 1 person or 2 person   
    double basePrice;   // 100 euros for 1 night and 1 person or 150 for one night and 2 persons
    bool occupied;      // is room occupied true or false 
    int discount;       // discount for final price 10%, 20% or 30%
    
    double finalPrice () const {                        // Method for returning discount price if we need it 
        return basePrice * (1.0 - discount / 100.0);
    }
    
};

void saveRoomsToFile(const vector<Room>& rooms);   // Save rooms to file
bool loadRoomsFromFile(vector<Room>& rooms);      // Load rooms from file
void roomGenerator(vector<Room>& rooms);          // Generate random rooms
void numberOfRooms(const vector<Room>& rooms);    // Show all rooms
void numberOfFreeRooms(const vector<Room>& rooms);// Show only free rooms
void reservation(vector<Room>& rooms);            // Book a room
void deleteReservation(vector<Room>& rooms);      // Delete a reservation


// Save all rooms to file
void saveRoomsToFile(const vector<Room>& rooms) {
    ofstream file("rooms.txt");                    // open file to write
    if (!file.is_open()) {                         // check if file opened
        cout << "Error: can't save rooms\n";
        return;
    }

    for (const Room &r : rooms) {                 // write each room to file
        file << r.id << " "
             << r.capacity << " "
             << r.basePrice << " "
             << r.occupied << " "
             << r.discount << "\n";
    }

    file.close();                                  // close file after writing
}

// Load rooms from file
bool loadRoomsFromFile(vector<Room>& rooms) {
    ifstream file("rooms.txt");                    // open file to read
    if (!file.is_open()) {                         // check if file exists
        return false;   // file doesn't exist
    }

    Room temp;
    while (file >> temp.id >> temp.capacity >> temp.basePrice 
                >> temp.occupied >> temp.discount)  // read each room
    {
        rooms.push_back(temp);                     // add room to vector
    }

    file.close();                                  // close file after reading
    return true;                                   // return true if loaded
}

// Generate rooms randomly
void roomGenerator(vector<Room>& rooms) {
    srand(time(nullptr));                           // seed random generator

    int roomsCount = (rand() % 131 + 20) * 2;       // random even number between 40-300

    int discounts[] = {0, 10, 20, 30};             // possible discounts

    rooms.clear();                                  // clear vector if already has data

    for (int i = 0; i < roomsCount; i++) {        // generate each room
        Room r;
        r.id = i + 1;
        if (i < roomsCount / 2) {                 // first half 1 person rooms
            r.capacity = 1;
            r.basePrice = 100;
        } else {                                  // second half 2 person rooms
            r.capacity = 2;
            r.basePrice = 150;
        }
        r.occupied = false;
        r.discount = discounts[rand() % 4];       // random discount
        rooms.push_back(r);                        // add room to vector
    }
}

// Show all rooms
void numberOfRooms(const vector<Room>& rooms) {
    for (int i = 0; i != rooms.size(); i++){
        Room r = rooms[i];
        cout << " Room " << r.id
             << " | Capacity: "<< r.capacity
             << " | Price: " << r.basePrice
             << " | Discount: " << r.discount
             << " | Is free: " << (r.occupied ? "occupied" : "free")  
             <<endl;
    }
}

// Show only free rooms
void numberOfFreeRooms(const vector<Room>& rooms) {
    for (int i = 0; i != rooms.size(); i++){
        Room r = rooms[i];
        if (!r.occupied){
            cout << " Room " << r.id
                 << " | Capacity: "<< r.capacity
                 << " | Price: " << r.basePrice
                 << " | Discount: " << r.discount
                 << endl;
        }
    }
}

// Book a room
void reservation(vector<Room>& rooms){
    int id;
    cout << "Enter room number: ";
    cin >> id;

    int nights;
    cout << "Enter how many nights: ";
    cin >> nights;

    if (id < 1 || id > rooms.size()) {            // check valid room number
        cout << "Error! we haven't this room\n";
        return;
    }

    Room &r = rooms[id-1];                         // get reference to room

    if(r.occupied) {
        cout <<"The room is occupied already\n"; 
    } else {
        r.occupied = true;                         // mark as occupied

        double finalPrice = r.finalPrice() * nights;  // calculate total price with discount

        cout << "Reservation successful for " 
             << nights << " nights. Final price: "
             << finalPrice << " EUR\n";
    }
}

// Delete reservation
void deleteReservation(vector<Room>& rooms){
    int id;
    cout << "Enter room number: ";
    cin >> id;

    if (id < 1 || id > rooms.size()) {            // check valid room number
        cout << "Error! we haven't this room\n";
        return;
    }

    Room &r = rooms[id-1];                         // get reference to room

    if (!r.occupied) {                             // check if room is not occupied
        cout << "This room is not occupied\n";
    } else {
        r.occupied = false;                        // mark room as free
        cout << "Reservation was deleted successfully\n";
    }
}

// Main program,
int main(){ 
    vector<Room> rooms;

    // Try to load rooms from file
    if (!loadRoomsFromFile(rooms)) {
        roomGenerator(rooms);                      // If file doesn't exist -> generate rooms
        saveRoomsToFile(rooms);                    // Save generated rooms to file
    }

    int choice;
    while (true) {
        cout << "--Hotel reserve menu--\n";
        cout << "1. Show all rooms\n";
        cout << "2. Show free rooms\n";
        cout << "3. Reserve some room\n";
        cout << "4. Delete reservation\n";
        cout << "5. Exit menu\n";
        cin >> choice;

        if (choice == 1){
            numberOfRooms(rooms);                  // Show all rooms
        }
        if (choice == 2){
            numberOfFreeRooms(rooms);              // Show free rooms
        }
        if (choice == 3){
            reservation(rooms);                    // Book room
        }
        if (choice == 4){
            deleteReservation(rooms);             // Delete reservation
        }
        if (choice == 5){
            break;                                 // Exit program
        }

        saveRoomsToFile(rooms);                    // Save current state to file after any action
    }

    return 0;
}
