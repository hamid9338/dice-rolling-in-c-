#include <iostream>
using namespace std;

// Dice patterns
string dice_patterns[7][5] = {
    {}, // unused
    {
        "┌────────┐",
        "|        |",
        "|    ●   |",
        "|        |",
        "└────────┘"
    },
    {
        "┌────────┐",
        "|  ●     |",
        "|        |",
        "|     ●  |",
        "└────────┘"
    },
    {
        "┌────────┐",
        "| ●      |",
        "|   ●    |",
        "|     ●  |",
        "└────────┘"
    },
    {
        "┌────────┐",
        "|  ●   ● |",
        "|        |",
        "|  ●   ● |",
        "└────────┘"
    },
    {
        "┌────────┐",
        "|  ●   ● |",
        "|    ●   |",
        "|  ●   ● |",
        "└────────┘"
    },
    {
        "┌────────┐",
        "|  ●   ● |",
        "|  ●   ● |",
        "|  ●   ● |",
        "└────────┘"
    }
};

// Basic pseudo-random generator (LCG)
int fake_rand(int& seed) {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return seed % 6 + 1;
}

void roll_dice(int rolls[], int num_dice, int& seed) {
    for (int i = 0; i < num_dice; ++i) {
        rolls[i] = fake_rand(seed);
    }
}

void print_dice_faces(int rolls[], int num_dice) {
    for (int line = 0; line < 5; ++line) {
        for (int i = 0; i < num_dice; ++i) {
            cout << dice_patterns[rolls[i]][line] << "  ";
        }
        cout << endl;
    }
}

int main() {
    const int MAX_DICE = 10;
    int rolls[MAX_DICE];
    int roll_count = 0;
    int seed = 123456; // static seed to simulate randomness

    while (true) {
        int num_dice;
        cout << "\nHow many dice would you like to roll (1-" << MAX_DICE << ")? ";
        cin >> num_dice;

        if (cin.fail() || num_dice <= 0 || num_dice > MAX_DICE) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        roll_dice(rolls, num_dice, seed);
        roll_count++;
        cout << "\nYou rolled:\n";
        print_dice_faces(rolls, num_dice);
        cout << "\nTotal Rolls This Session: " << roll_count << endl;

        char again;
        cout << "\nDo you want to roll again? (y/n): ";
        cin >> again;

        if (tolower(again) != 'y') {
            cout << "Thanks for playing!" << endl;
            break;
        }
    }

    return 0;
}
