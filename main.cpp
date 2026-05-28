#include <iostream>
#include <string>
#include <limits> // Important library to clear the input buffer and prevent errors

using namespace std;

int main() {
    // Maximum capacity of the shelter
    const int MAX_CATS = 10;
    
    // Initial number of cats in the shelter
    int currentCatCount = 4;

    // 1D Arrays for names and breeds
    string catNames[MAX_CATS] = {"Mishmish", "Lucy", "Zatar", "Fluffy"};
    string catBreeds[MAX_CATS] = {"Shirazi", "Siamese", "Himalayan", "Domestic Shorthair"};

    // 2D Nested Array for stats: Column 0 = Age (months), Column 1 = Weight (kg)
    double catStats[MAX_CATS][2] = {
        {12, 4.5},  // Mishmish
        {5,  2.1},  // Lucy
        {24, 5.0},  // Zatar
        {8,  3.2}   // Fluffy
    };

    int choice;
    
    // Main program loop
    while (true) {
        cout << "\n====================================\n";
        cout << "   🐾 Smart Cat Shelter System 🐾\n";
        cout << "by Zainab Emad & Hind Abdulrahmen.\n"; // Fixed syntax error here
        cout << "====================================\n";
        cout << "1. View all available cats\n";
        cout << "2. Search for a specific cat\n";
        cout << "3. Calculate average age of cats\n";
        cout << "4. Add a new cat (e.g., Tuxedo)\n"; 
        cout << "5. Exit program\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice (1-5): ";
        
        cin >> choice;

        // Check if the input is a valid number
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "❌ Invalid input! Please enter a number between 1 and 5.\n";
            continue;
        }

        if (choice == 1) {
            // Option 1: View all cats
            cout << "\n--- Available Cats & Their Details ---\n";
            for (int i = 0; i < currentCatCount; i++) {
                cout << i + 1 << ". Name: " << catNames[i] 
                     << " | Breed: " << catBreeds[i] 
                     << " | Age: " << catStats[i][0] << " months" 
                     << " | Weight: " << catStats[i][1] << " kg\n";
            }
        } 
        else if (choice == 2) {
            // Option 2: Search for a cat
            string searchName;
            cout << "Enter cat name to search: ";
            cin >> searchName;
            
            bool found = false;
            for (int i = 0; i < currentCatCount; i++) {
                if (catNames[i] == searchName) {
                    cout << "\n✅ Cat Found!\n";
                    cout << "Breed: " << catBreeds[i] << "\n";
                    cout << "Age: " << catStats[i][0] << " months\n";
                    cout << "Weight: " << catStats[i][1] << " kg\n";
                    found = true;
                    break; 
                }
            }
            if (!found) {
                cout << "❌ Sorry, this cat is not in our shelter.\n";
            }
        } 
        else if (choice == 3) {
            // Option 3: Calculate average age
            double totalAge = 0;
            for (int i = 0; i < currentCatCount; i++) {
                totalAge += catStats[i][0]; 
            }
            double averageAge = totalAge / currentCatCount;
            cout << "\n📊 The average age of cats in the shelter is: " << averageAge << " months.\n";
        } 
        else if (choice == 4) {
            // Option 4: Add a new cat
            if (currentCatCount < MAX_CATS) {
                cout << "\n--- Add New Cat Details ---\n";
                
                // Clear the input buffer before reading strings to prevent skipping steps
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "Enter Cat Name: ";
                cin >> catNames[currentCatCount]; 
                
                cout << "Enter Cat Breed (e.g., Tuxedo): ";
                cin >> catBreeds[currentCatCount]; 
                
                cout << "Enter Cat Age (months): ";
                cin >> catStats[currentCatCount][0]; 
                
                cout << "Enter Cat Weight (kg): ";
                cin >> catStats[currentCatCount][1]; 
                
                currentCatCount++; // Move to the next empty slot
                cout << "\n🎉 New cat added successfully!\n";
            } else {
                cout << "\n❌ Shelter is full! Cannot add more cats.\n";
            }
        } 
        else if (choice == 5) {
            // Option 5: Exit
            cout << "\nThank you for using our system!ba-byee! :)👋🐾\n";
            break; 
        } 
        else {
            cout << "❌ Invalid choice! Please select a number from 1 to 5.\n";
        }
    }

    return 0;
}
