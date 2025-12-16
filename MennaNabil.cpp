#include <iostream>
#include <string>

using namespace std;

struct Note {
    int noteId;
    string description;
};

const int MAX_NOTES = 100; 
Note notes[MAX_NOTES];
int noteCount = 0;
int nextId = 1;

void displayMenu() {
    cout << "\n===== Notes Organizer =====\n";
    cout << "1. Create Note\n";
    cout << "2. Show All Notes\n";
    cout << "3. Remove Note\n";
    cout << "4. Quit\n";
    cout << "Select an option: ";
}

void createNote() {
    if (noteCount >= MAX_NOTES) {
        cout << "Cannot add more notes. Maximum reached.\n";
        return;
    }

    Note n;
    n.noteId = nextId++;
    cin.ignore();
    cout << "Type note description: ";
    getline(cin, n.description);

    notes[noteCount++] = n;
    cout << "Note saved successfully!\n";
}

void showNotes() {
    if (noteCount == 0) {
        cout << "No notes found.\n";
        return;
    }

    cout << "\n--- Notes List ---\n";
    for (int i = 0; i < noteCount; ++i) {
        cout << "Note ID: " << notes[i].noteId << " | Description: " << notes[i].description << endl;
    }
}

void removeNote() {
    int id;
    cout << "Enter Note ID to remove: ";
    cin >> id;

    for (int i = 0; i < noteCount; ++i) {
        if (notes[i].noteId == id) {
            
            for (int j = i; j < noteCount - 1; ++j) {
                notes[j] = notes[j + 1];
            }
            noteCount--;
            cout << "Note removed successfully!\n";
            return;
        }
    }

    cout << "Note not found.\n";
}

int main() {
    int option;

    while (true) {
        displayMenu();
        cin >> option;

        switch (option) {
        case 1:
            createNote();
            break;
        case 2:
            showNotes();
            break;
        case 3:
            removeNote();
            break;
        case 4:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid selection.\n";
        }
    }
}
