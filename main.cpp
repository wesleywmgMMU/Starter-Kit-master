// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT1L
// Names: Wesley Wong Min Guan | Tang Yu Xuan | Koh JIa Jie
// IDs: 1211101998 | 1211103236 | 1211102879
// Emails: 1211101998@student.mmu.edu.my | 1211103236@student.mmu.edu.my | 1211102879@student.mmu.edu.my
// Phones: 0125881773 | 01139214061 | 0163091595
// *********************************************************

#include <iostream>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <limits>
#include <numeric>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

class Character // Attributes for alien and zombies.
{
public:
    class Alien
    {
    private:
        vector<int> alienLife{100}; // Original life of the alien.
        vector<int> alienAttack{0}; // Original attack of the alien.

    public:
        void setLife(int life) { alienLife.push_back(life); }  // Set another life using pushback.
        void clearLife() { alienLife.clear(); }                // Clear every life in the alienLife.
        int getLife(int index) { return alienLife.at(index); } // Get life at the specified index.
        int sizeLife() { return alienLife.size(); }            // Return the size of the vector.

        void setAttack(int attack) { alienAttack.push_back(attack); }                            // Set another life using pushback.
        int getAttack(int index) { return alienAttack.at(index); }                               // Get life at the specified index.
        int sizeAttack() { return alienAttack.size(); }                                          // Return the size of the vector.
        int accumulateAttack() { return accumulate(alienAttack.begin(), alienAttack.end(), 0); } // Return the accumulation of the attacks in the alien attack.
        void clearAttack() { alienAttack.clear(); }                                              // Clear every attack in the alienLife.
    };

    class Zombie
    {
    private:
        vector<int> zombieNo{};     // The number of the zombies.
        vector<int> zombieLife{};   // The life of the zombies.
        vector<int> zombieAttack{}; // The attack of the zombies.
        vector<int> zombieRange{};  // The range of the zombies.
        vector<int> bossLife{};     // The life of the boss.
        vector<int> bossAttack{};   // The attack of the boss.
        vector<int> bossCD{};       // The cd of the boss.

    public:
        void setZombie(int zombieID) { zombieNo.push_back(zombieID); } // Set a new zombie.
        int getZombie(int index) { return zombieNo.at(index); }        // Return the zombie ID.
        int sizeZombie() { return zombieNo.size(); }                   // Return the number of the zombies.
        void replacedSavedZombie(vector<int> newVector) { zombieNo = newVector; }

        void setLife(int life) { zombieLife.push_back(life); }                                                    // Set another life using pushback.
        int getLife(int index) { return zombieLife.at(index); }                                                   // Get life at the specified index.
        void insertLife(int newLife, int position) { zombieLife.insert(zombieLife.begin() + position, newLife); } // Set new life for selected zombie.
        void eraseLife(int position) { zombieLife.erase(zombieLife.begin() + position); }                         // Clear life for selected zombie.
        int sizeLife() { return zombieLife.size(); };                                                             // Return the size of the vector.
        int accumulateZombieLife() { return accumulate(zombieLife.begin(), zombieLife.end(), 0); }                // return the accumulation of the attacks in the alien attack.
        void replacedSavedLife(vector<int> newVector) { zombieLife = newVector; }

        void setAttack(int attack) { zombieAttack.push_back(attack); } // Set another life using pushback.
        int getAttack(int index) { return zombieAttack.at(index); }    // Get life at the specified index.
        int sizeAttack() { return zombieAttack.size(); }               // Return the size of the vector.
        void replacedSavedAttack(vector<int> newVector) { zombieAttack = newVector; }

        void setRange(int range) { zombieRange.push_back(range); } // Set another life using pushback.
        int getRange(int index) { return zombieRange.at(index); }  // Get life at the specified index.
        int sizeRange() { return zombieRange.size(); }             // Return the size of the vector.
        void replacedSavedRange(vector<int> newVector) { zombieRange = newVector; }

        void setBossLife(int life) { bossLife.push_back(life); }                         // Set boss life.
        int getBossLife(int index) { return bossLife.at(index); }                        // Get boss life.
        void insertBossLife(int newLife) { bossLife.insert(bossLife.begin(), newLife); } // Set new boss life.
        void eraseBossLife() { bossLife.erase(bossLife.begin()); }                       // Erase previous life.
        void replacedSavedBossLife(vector<int> newVector) { bossLife = newVector; }

        void setBossAttack(int attack) { bossAttack.push_back(attack); } // Set boss attack.
        int getBossAttack(int index) { return bossAttack.at(index); }    // Get boss attack.
        void replacedSavedBossAttack(vector<int> newVector) { bossAttack = newVector; }

        void setBossCD(int cd) { bossCD.push_back(cd); }                       // Set boss cd.
        int getBossCD(int index) { return bossCD.at(index); }                  // Get boss cd.
        void insertBossCD(int newCD) { bossCD.insert(bossCD.begin(), newCD); } // Set new boss cd.
        void eraseBossCD() { bossCD.erase(bossCD.begin()); }                   // Erase previous cd.
        void replacedSavedBossCD(vector<int> newVector) { bossCD = newVector; }
    };
};

//save and load

void save(Character::Alien &aliens, Character::Zombie &zombies, string &mode, int &column, int &row, string **arr, int **PositionZombie, int x, int y, bool &bossSpawn, string saveFileName)
{
    // Alien.
    ofstream file;
    file.open(saveFileName);
    file << "Mode: ";
    file << mode << " ";
    file << endl;
    file << "Alien Life: ";
    file << aliens.getLife(0) << " ";
    file << endl;
    file << "Alien Attack: ";
    file << aliens.getAttack(0) << " ";
    file << endl;
    // Zombies.
    file << "Zombies No: ";
    for (int i = 0; i < zombies.sizeZombie(); i++)
    {
        file << zombies.getZombie(i) << " ";
    }
    file << endl;
    file << "Zombies Life: ";
    for (int i = 0; i < zombies.sizeLife(); i++)
    {
        file << zombies.getLife(i) << " ";
    }
    file << endl;
    file << "Zombies Attack: ";
    for (int i = 0; i < zombies.sizeAttack(); i++)
    {
        file << zombies.getAttack(i) << " ";
    }
    file << endl;
    file << "Zombies Range: ";
    for (int i = 0; i < zombies.sizeRange(); i++)
    {
        file << zombies.getRange(i) << " ";
    }
    file << endl;
    file << "Boss life: ";
    file << zombies.getBossLife(0) << " ";
    file << endl;
    file << "Boss attack: ";
    file << zombies.getBossAttack(0) << " ";
    file << endl;
    file << "Boss CD: ";
    file << zombies.getBossCD(0) << " ";
    file << endl;
    file << "Boss spawn: ";
    file << bossSpawn << " ";
    file << endl;
    file << "Row: ";
    file << row << endl;
    file << "Column: ";
    file << column << endl;
    file << "Alien position x: ";
    file << x << endl;
    file << "Alien position y: ";
    file << y << endl;
    file << "Zombie Position: " << endl;
    for (int i = 0; i < zombies.sizeZombie(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            file << PositionZombie[i][j];
        }
        file << endl;
    }
    file << endl;
    file << "2D Array: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            file << arr[i][j];
        }
        file << endl;
    }
    file << endl;
    file.close();
}

string getSavedMode(string loadFileName)
{
    string savedMode;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Mode: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(6);   // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedMode = n;
            }
        }
    }
    return savedMode;
}

int getSavedAlienLife(string loadFileName) // Get alien life from loaded file.
{
    int savedAlienLife;
    ifstream file; //creates a file object
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Alien Life: ") != string::npos) // Execute if Alien LIfe: is found
        {
            line = line.substr(12);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n) // while all integers are extracted, savedAlienLife = n;
            {
                savedAlienLife = n;
            }
        }
    }
    return savedAlienLife;
}

int getSavedAlienAttack(string loadFileName) // Get alien attack from loaded file.
{
    int savedAlienAttack;
    ifstream file; 
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Alien Attack: ") != string::npos) 
        {
            line = line.substr(14);  
            istringstream iss(line); 
            int n;
            while (iss >> n)
            {
                savedAlienAttack = n;
            }
        }
    }
    return savedAlienAttack;
}

int getSavedAlienPositionX(string loadFileName) // Get alien position X from loaded file.
{
    int savedAlienPositionX;
    ifstream file; 
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Alien position x: ") != string::npos) 
        {
            line = line.substr(18);  
            istringstream iss(line);
            int n;
            while (iss >> n)
            {
                savedAlienPositionX = n;
            }
        }
    }
    return savedAlienPositionX;
}

int getSavedAlienPositionY(string loadFileName) // Get alien position Y from loaded file.
{
    int savedAlienPositionY;
    ifstream file; 
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Alien position y: ") != string::npos) 
        {
            line = line.substr(18);  
            istringstream iss(line); 
            int n;
            while (iss >> n)
            {
                savedAlienPositionY = n;
            }
        }
    }
    return savedAlienPositionY;
    ;
}

vector<int> getSavedZombieNo(string loadFileName) // Get zombie count from loaded file.
{
    vector<int> savedZombieNo;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Zombies No: ") != string::npos)
        {
            line = line.substr(12);  
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedZombieNo.push_back(n); // each n integer is pushed back into the savedZombieNo
            }
        }
    }
    return savedZombieNo;
}

vector<int> getSavedZombieLife(string loadFileName) // Get zombie life from loaded file.
{
    vector<int> savedZombieLife;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Zombies Life: ") != string::npos) 
        {
            line = line.substr(14);  
            istringstream iss(line); 
            int n;
            while (iss >> n)
            {
                savedZombieLife.push_back(n);
            }
        }
    }
    return savedZombieLife;
}

vector<int> getSavedZombieAttack(string loadFileName) // Get zombie attack from loaded file.
{
    vector<int> savedZombieAttack;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Zombies Attack: ") != string::npos) 
        {
            line = line.substr(16);  
            istringstream iss(line); 
            int n;
            while (iss >> n)
            {
                savedZombieAttack.push_back(n);
            }
        }
    }
    return savedZombieAttack;
}

vector<int> getSavedZombieRange(string loadFileName) // Get zombie range from loaded file.
{
    vector<int> savedZombieRange;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Zombies Range: ") != string::npos) 
        {
            line = line.substr(15);  
            istringstream iss(line); 
            int n;
            while (iss >> n)
            {
                savedZombieRange.push_back(n);
            }
        }
    }
    return savedZombieRange;
}

bool getSavedBossSpawn(string loadFileName)
{
    int savedBossSpawn;
    ifstream file; // Create a file object.
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Boss spawn: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(12);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedBossSpawn = n;
            }
        }
    }
    return savedBossSpawn;
}

vector<int> getSavedBossLife(string loadFileName)
{
    vector<int> savedBossLife;
    ifstream file; // Create a file object.
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Boss life: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(11);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedBossLife.push_back(n);
            }
        }
    }
    return savedBossLife;
}

vector<int> getSavedBossAttack(string loadFileName)
{
    vector<int> savedBossAttack;
    ifstream file; // Create a file object.
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Boss attack: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(13);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedBossAttack.push_back(n);
            }
        }
    }
    return savedBossAttack;
}

vector<int> getSavedBossCD(string loadFileName)
{
    vector<int> savedBossCD;
    ifstream file; // Create a file object.
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Boss CD: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(9);   // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedBossCD.push_back(n);
            }
        }
    }
    return savedBossCD;
}

int getSavedRow(string loadFileName) // Get row from loaded file.
{
    int savedRow;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Row: ") != string::npos) 
        {
            line = line.substr(5);   
            istringstream iss(line); 
            int n;
            while (iss >> n)
            {
                savedRow = n;
            }
        }
    }
    return savedRow;
}

int getSavedColumn(string loadFileName) // Get column from loaded file.

{
    int savedColumn;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Column: ") != string::npos) 
        {
            line = line.substr(8);  
            istringstream iss(line); 
            int n;
            while (iss >> n)
            {
                savedColumn = n;
            }
        }
    }
    return savedColumn;
}

string **getSavedArray(string filename) // Get array from loaded file.
{
    int row, col;
    string line;
    string **newArray;
    ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.find("Row:") != string::npos)
            {
                row = stoi(line.substr(line.find(":") + 1));
            }
            else if (line.find("Column:") != string::npos)
            {
                col = stoi(line.substr(line.find(":") + 1));
            }
            else if (line.find("2D Array:") != string::npos)
            {
                newArray = new string *[row];
                for (int i = 0; i < row; i++)
                {
                    getline(file, line);
                    newArray[i] = new string[col];
                    for (int j = 0; j < col; j++)
                    {
                        newArray[i][j] = line[j];
                    }
                }
            }
        }
        file.close();
    }
    return newArray;
}

int **getSavedPositionZombie(string filename) // Get zombie postion from loaded file.
{
    int row, col;
    string line;
    int **newArray;
    ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.find("Zombie Position:") != string::npos)
            {
                vector<vector<int>> zombiePositions;
                while (getline(file, line) && line != "")
                {
                    int x = line[0] - '0';
                    int y = line[1] - '0';
                    zombiePositions.push_back({x, y});
                }

                int zombiePositionsSize = zombiePositions.size();
                newArray = new int *[zombiePositionsSize]; //creates a newArray dynamically with the size of zombiePosition
                for (int i = 0; i < zombiePositionsSize; i++)
                {
                    newArray[i] = new int[2];
                    newArray[i][0] = zombiePositions[i][0];
                    newArray[i][1] = zombiePositions[i][1];
                }
            }
        }
        file.close();
    }
    return newArray;
}

//customisations and initialisations

string difficulty() // Menu for user to choose difficulty.
{
    string mode;
    bool error = false;
    do
    {
        cout << "                   Difficulty                  " << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        // cout << "Easy      -- Alien revive 30 health when the Boss is spawned," << endl
        //      << "             Boss has lower attack and normal health" << endl << endl;
        // cout << "Medium    -- Alien's life deducted into 30 when the Boss is spawned," << endl
        //      << "             Boss has normal attack and health." << endl << endl;
        // cout << "Hard      -- Alien's life deducted into 1 when the Boss is spawned," << endl
        //      << "             Zombies have higher attack and life." << endl
        //      << "             Boss has very high attack and higher life." << endl << endl;
        // cout << "Nightmare -- Alien's life deducted into 1 when the Boss is spawned," << endl
        //      << "             Zombies have very high attack and life." << endl
        //      << "             Boss has very high life and kills alien in ONE HIT." << endl << endl << endl;

        cout << "  Easy      -- We'll take it easy on you." << endl
             << endl;
        cout << "  Medium    -- Just your average difficulty." << endl
             << endl;
        cout << "  Hard      -- We'll hit you with all we got." << endl
             << endl;
        cout << "  Nightmare -- Survive the unsurvivable." << endl
             << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << endl;
        cout << "Please select the difficulty => ";
        cin >> mode;
        transform(mode.begin(), mode.end(), mode.begin(), ::tolower);
        if ((mode != "easy" && mode != "medium" && mode != "hard" && mode != "nightmare") || cin.fail())
        {
            cout << "Please enter the correct difficulty !" << endl
                 << endl;
            system("pause");
            error = true;
        }
        else
        {
            error = false;
        }
        system("cls");
    } while (error == true);
    return mode;
}
int customize(int &row, int &column, int &zombie) // Customization for row, column and zombie amount.
{
    // Row setting.
    cout << "Board Settings" << endl;
    cout << "--------------" << endl;
    int error;
    do
    {
        error = false;
        cout << "Enter rows => ";
        cin >> row;
        if (cin.fail()) // Check invalid input.
        {
            cout << "Please enter a valid odd integer (4 < row < 100)." << endl;
            error = true;
            cin.clear();  // The clear() function can be used to clear these error flags and restore the cin object to a good state, allowing further input operations to be performed.
            cin.ignore(); // The cin.clear() can be used together with cin.ignore() to clear the error state of the stream and ignore any unread characters that may be in the input buffer.
        }
        else if (row < 5) // Check number < 5.
        {
            cout << "Please enter a valid odd integer (4 < row < 100)." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (row > 99) // Check number > 99.
        {
            cout << "Please enter a valid odd integer (4 < row < 100)." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (row % 2 == 0) // Check even number.
        {
            cout << "Please enter a valid odd integer (4 < row < 100)." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
    } while (error == 1);

    // Column setting.
    do
    {
        error = 0;
        cout << "Enter columns => ";
        cin >> column;
        if (cin.fail()) // Check invalid input.
        {
            cout << "Please enter a valid odd integer (4 < column < 100)." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (column < 5) // Check number < 5
        {
            cout << "Please enter a valid odd integer (4 < column < 100)." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (column > 99) // Check number > 99
        {
            cout << "Please enter a valid odd integer (4 < column < 100)." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (column % 2 == 0) // Check even number.
        {
            cout << "Please enter a valid odd integer (4 < column < 100)." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
    } while (error == 1);

    // Zombie setting.
    cout << endl;
    cout << "Zombie Settings" << endl;
    cout << "---------------" << endl;
    do
    {
        error = 0;
        cout << "Enter number of zombies => ";
        cin >> zombie;
        if (cin.fail())
        {
            cout << "Please enter a valid positive integer < 10." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (zombie < 1)
        {
            cout << "Please enter a valid positive integer < 10." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        else if (zombie > 9)
        {
            cout << "Please enter a valid positive integer < 10." << endl;
            error = 1;
            cin.clear();
            cin.ignore();
        }
        cout << endl;
    } while (error == 1);
    cout << "Settings Updated." << endl;
    return row, column, zombie;
}

void setting(int &row, int &column, int &zombie) // Default page and ask user for customization.
{
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    cout << "Board Rows\t: " << row << endl;
    cout << "Board Columns\t: " << column << endl;
    cout << "Zombie Count\t: " << zombie << endl;
    bool next = false;
    while (next != true)
    {
        string change;
        cout << endl;
        cout << "Do you wish to change the game settings (y/n)? => ";
        cin >> change;
        if (change == "y" || change == "Y")
        {
            system("CLS");
            customize(row, column, zombie);
            next = true;
            system("PAUSE");
            return;
        }
        else if (change == "n" || change == "N")
        {
            return;
        }
        else
        {
            cout << "Please enter y/n." << endl;
        }
    }
}

string **generate2DArr(int &row, int &column) // Initialize 2D array.
{
    string **arr = new string *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new string[column];
    }
    return arr;
}

//display functions

void displayTitle(int &column, int &row) // Display ".: Alien vs Zombie :.".
{
    if (row > 9)
    {
        cout << "    ";
    }
    else
    {
        cout << "   ";
    }
    int x = column + 1;
    while (x > 11)
    {
        cout << " ";
        --x;
    }
    cout << ".: Alien vs Zombie :." << endl;
}

void displayBorder(int &column, int &row) // Display one horizontal line of border.
{
    int x = 1;
    if (row > 9)
    {
        cout << "    +";
    }
    else
    {
        cout << "   +";
    }
    while (x <= column)
    {
        cout << "-+";
        ++x;
    }
    cout << endl;
}

int displayRow(int &rowStart, int &row) // Display row count on the left side of board.
{
    cout << " ";
    int rowCount = rowStart + 1;
    if (row > 9)
    {
        cout.width(2);
    }
    cout.setf(ios::fixed);
    cout << rowCount << " ";
    ++rowStart;
    return rowCount;
}

void displayColumn(int &column, int &row) // Display column count on the bottom side of board.
{
    int columnStart = 0;
    int x = 0;
    if (column > 9)
    {
        if (row > 9)
        {
            cout << "    ";
        }
        else
        {
            cout << "   ";
        }
        for (int i = 1; i <= column; ++i)
        {
            if (i < 10)
            {
                cout << "  ";
            }
            else if (i % 10 == 0)
            {
                x = x + 1;
                cout << " " << x;
            }
            else
            {
                cout << " " << x;
            }
        }
        cout << endl;
    }
    if (row > 9)
    {
        cout << "    ";
    }
    else
    {
        cout << "   ";
    }
    for (int i = 1; i <= column; ++i)
    {
        if (columnStart == 9)
        {
            columnStart = 0;
        }
        else
        {
            columnStart = columnStart + 1;
        }
        cout << " " << columnStart;
    }
    cout << endl;
    cout << endl;
}

void displayAlienLife(Character::Alien &aliens) // Display the life of alien.
{
    cout.width(3);
    cout << aliens.getLife(0);
}

void displayAlienAttack(Character::Alien &aliens) // Display the attack of alien.
{
    cout.width(3);
    cout << aliens.getAttack(0);
}

int displayZombieNo(Character::Zombie &zombies, int &zombiesNo) // Display the life of zombies.
{
    cout << zombies.getZombie(zombiesNo);
    return zombiesNo;
}

void displayZombieLife(Character::Zombie &zombies, int &zombiesNo) // Display the life of zombies.
{
    cout.width(3);
    cout << zombies.getLife(zombiesNo);
}

void displayZombieAttack(Character::Zombie &zombies, int &zombiesNo) // Display the attack of zombies.
{
    cout.width(3);
    cout << zombies.getAttack(zombiesNo);
}

void displayZombieRange(Character::Zombie &zombies, int &zombiesNo) // Display the range of zombies.
{
    cout.width(2);
    cout << zombies.getRange(zombiesNo);
}

void help() // Show command list.
{
    cout << " 1. up\t\t- Move Up" << endl;
    cout << " 2. down\t- Move Down" << endl;
    cout << " 3. left\t- Move Left " << endl;
    cout << " 4. right\t- Move Right" << endl;
    cout << " 5. arrow\t- Change the direction of an arrow using row and column" << endl;
    cout << " 6. help\t- Display the command list" << endl;
    cout << " 7. object\t- Display the object list" << endl;
    cout << " 8. save\t- Save the game " << endl;
    cout << " 9. load\t- Load previous saved game" << endl;
    cout << "10. quit\t- Exit the game" << endl;
    cout << "11. restart\t- Restart the game" << endl;
    return;
}

void object() // Show object list.
{
    cout << " 1. \'^\' \'v\' \'<\' \'>\'\t- Arrow" << endl;
    cout << " 2. \'h\'\t\t\t- Health" << endl;
    cout << " 3. \'p\'\t\t\t- Pod" << endl;
    cout << " 4. \'r\'\t\t\t- Rock" << endl;
    cout << " 5. \'@\'\t\t\t- Teleport Portal" << endl;
    cout << " 6. \'~\'\t\t\t- Mighty Rod" << endl;
    cout << " 7. \' \'\t\t\t- Space" << endl;
    cout << " 8. \'.\'\t\t\t- Trail" << endl;
    cout << " 9. \'A\'\t\t\t- Alien" << endl;
    cout << "10. \'1\'-\'9\'\t\t- Zombie" << endl;
    cout << "11. \'B\'\t\t\t- Zombie Boss" << endl;
    return;
}

string commandUser(string &command) // Allow user to input command.
{
    cout << "command > ";
    cin >> command;
    cout << endl;
    return command;
}

void displayCharacter(Character::Alien &aliens, Character::Zombie &zombies, int &zombie, bool &bossSpawn, int &turn) // Display the life, attack and range of alien and zombie.
{
    int zombiesNo;
    if (turn == 0)
    {
        cout << "-> ";
    }
    else
    {
        cout << "   ";
    }
    if (bossSpawn == true)
    {
        cout << "Alien : Life ";
    }
    else
    {
        cout << "Alien    : Life ";
    }
    displayAlienLife(aliens);
    cout << ", Attack ";
    displayAlienAttack(aliens);
    cout << endl;

    for (zombiesNo = 0; zombiesNo < zombie; ++zombiesNo)
    {

        if (zombies.accumulateZombieLife() == 0 && bossSpawn == true)
        {
            if (turn >= 1)
            {
                cout << "-> ";
            }
            else
            {
                cout << "   ";
            }
            cout << "BOSS\t : Life ";
            cout.width(3);
            cout << zombies.getBossLife(0) << ", Attack ";
            cout.width(3);
            cout << zombies.getBossAttack(0) << ", CD ";
            cout.width(3);
            cout << zombies.getBossCD(0) << endl;
            break;
        }
        else
        {

            if ((turn == zombiesNo + 1) && (zombies.getLife(zombiesNo) > 0))
            {
                cout << "-> ";
            }
            else
            {
                cout << "   ";
            }
            // }
            cout << "Zombie " << zombiesNo + 1 << " : Life ";
            displayZombieLife(zombies, zombiesNo);
            cout << ", Attack ";
            displayZombieAttack(zombies, zombiesNo);
            cout << ", Range ";
            displayZombieRange(zombies, zombiesNo);
            cout << endl;
        }
    }
    cout << endl;
}

void displayBoard(string **arr, int &row, int &column, int &zombie, int &rowStart, Character::Alien &aliens, Character::Zombie &zombies, bool &bossSpawn, int &turn) // Display the game board.
{
    rowStart = 0;
    displayTitle(column, row);
    displayBorder(column, row);
    for (int i = 0; i < row; ++i)
    {
        displayRow(rowStart, row);
        for (int j = 0; j < column; ++j)
        {
            cout << "|" << arr[i][j];
        }
        cout << "|" << endl;
        displayBorder(column, row);
    }
    displayColumn(column, row);
    displayCharacter(aliens, zombies, zombie, bossSpawn, turn);
}

//Random Functions

string randomObject() // Randomize object.
{
    string finalObject;
    string object[21] = {"^", "v", "<", ">", "h", "p", "r", " ", "^", "v", "<", ">", "h", "p", " ", "^", "v", "<", ">", "h", "p"};
    finalObject = object[rand() % 21];
    // finalObject = "p";
    return finalObject;
}

string randomRock() // Randomize object.
{
    string finalRock;
    string rock[7] = {"^", "v", "<", ">", "h", "p", " "};
    finalRock = rock[rand() % 7];
    return finalRock;
}

void generateRandom(string **arr, int &row, int &column) // Assign random objects to each land.
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            arr[i][j] = randomObject();
        }
    }
}

void generateRandomTrail(string **arr, int &row, int &column, int &zombie, int &rowStart, Character::Alien &aliens, Character::Zombie &zombies) // Assign random objects to the trails after alien's turn.
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if (arr[i][j] == ".")
            {
                arr[i][j] = randomObject();
            }
        }
    }
    cout << "Alien's turn ends. The trail is reset." << endl;
    cout << endl;
}

int randomLife(string mode) // Randomize zombie life.
{
    int finalLife;
    if (mode == "easy" || mode == "medium")
    {
        int life[3] = {100, 125, 150};
        finalLife = life[rand() % 3];
    }
    else if (mode == "hard")
    {
        int life[2] = {200, 250};
        finalLife = life[rand() % 2];
    }
    else if (mode == "nightmare")
    {
        int life[2] = {350, 400};
        finalLife = life[rand() % 2];
    }
    return finalLife;
}

int randomAttack(string mode) // Randomize zombie attack.
{
    int finalAttack;
    if (mode == "easy" || mode == "medium")
    {
        int attack[3] = {5, 10, 15};
        finalAttack = attack[rand() % 3];
    }
    else if (mode == "hard")
    {
        int attack[3] = {20, 25, 30};
        finalAttack = attack[rand() % 3];
    }
    else if (mode == "nightmare")
    {
        int attack[2] = {35, 40};
        finalAttack = attack[rand() % 2];
    }
    return finalAttack;
}

int randomRange(int &row, int &column) // Randomize zombie range.
{
    int finalRange;
    int smaller;

    if (row < column)
    {
        smaller = row;
    }
    else
    {
        smaller = column;
    }
    finalRange = rand() % (smaller);
    while (finalRange > (smaller + 1) / 2 || finalRange < smaller / 3 || finalRange == 0)
    {
        finalRange = rand() % (smaller);
    }
    return finalRange;
}

//Alien  Functions

string moveUp(int &x, int &y, string **arr, string &hit, Character::Zombie &zombies) // Action for alien to move up.
{
    if (x - 1 >= 0)
    {
        bool move = true;
        for (int i = 1; i <= zombies.sizeZombie(); i++)
        {
            if (arr[x - 1][y] == to_string(i))
            {
                move = false;
                hit = to_string(i);
            }
            else
            {
                continue;
            }
        }
        if (move == true)
        {
            arr[x][y] = ".";
            x = x - 1;
            hit = arr[x][y];
            arr[x][y] = "A";
        }
    }
    return hit;
}

string moveDown(int &x, int &y, string **arr, string &hit, int &row, Character::Zombie &zombies) // Action for alien to move down.
{
    if (x + 1 < row)
    {
        bool move = true;
        for (int i = 1; i <= zombies.sizeZombie(); i++)
        {
            if (arr[x + 1][y] == to_string(i))
            {
                move = false;
                hit = to_string(i);
            }
            else
            {
                continue;
            }
        }
        if (move == true)
        {
            arr[x][y] = ".";
            x = x + 1;
            hit = arr[x][y];
            arr[x][y] = "A";
        }
    }
    return hit;
}

string moveLeft(int &x, int &y, string **arr, string &hit, Character::Zombie &zombies) // Action for alien to move up.
{
    if (y - 1 >= 0)
    {
        bool move = true;
        for (int i = 1; i <= zombies.sizeZombie(); i++)
        {
            if (arr[x][y - 1] == to_string(i))
            {
                move = false;
                hit = to_string(i);
            }
            else
            {
                continue;
            }
        }
        if (move == true)
        {
            arr[x][y] = ".";
            y = y - 1;
            hit = arr[x][y];
            arr[x][y] = "A";
        }
    }
    return hit;
}

string moveRight(int &x, int &y, string **arr, string &hit, int &column, Character::Zombie &zombies) // Action for alien to move up.
{
    if (y + 1 < column)
    {
        bool move = true;
        for (int i = 1; i <= zombies.sizeZombie(); i++)
        {
            if (arr[x][y + 1] == to_string(i))
            {
                move = false;
                hit = to_string(i);
            }
            else
            {
                continue;
            }
        }
        if (move == true)
        {
            arr[x][y] = ".";
            y = y + 1;
            hit = arr[x][y];
            arr[x][y] = "A";
        }
    }
    return hit;
}

string continuousMove(string &hit, string &lastMove, int &x, int &y, string **arr, int &row, int &column, Character::Zombie &zombies) // Identify what is the next hit.
{
    if (lastMove == "^")
    {
        hit = moveUp(x, y, arr, hit, zombies);
    }
    else if (lastMove == "v")
    {
        hit = moveDown(x, y, arr, hit, row, zombies);
    }
    else if (lastMove == "<")
    {
        hit = moveLeft(x, y, arr, hit, zombies);
    }
    else if (lastMove == ">")
    {
        hit = moveRight(x, y, arr, hit, column, zombies);
    }
    return hit;
}

string findClosestZombie(int &row, int &column, string **arr, int **PositionZombie, int &zombie, Character::Zombie &zombies) // A calculater for finding the shortest distance between the alien and a zombie.
{
    int rowA, colA;
    int shortestDistance = INT_MAX; // Initialize shortestDistance to a large number.
    string shortestPoint = "0";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] == "A")
            {
                rowA = i;
                colA = j;
            }
        }
    }
    vector<string> sameDistanceZombies;
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] != "A" && arr[i][j] != "^" && arr[i][j] != "v" && arr[i][j] != "<" && arr[i][j] != ">" && arr[i][j] != "h" && arr[i][j] != "p" && arr[i][j] != "r" && arr[i][j] != " " && arr[i][j] != "." && arr[i][j] != "@" && arr[i][j] != "~")
            {
                int rowX = i;
                int colX = j;
                int closestDistance = abs(rowA - rowX) + abs(colA - colX);
                if (closestDistance < shortestDistance)
                {
                    shortestDistance = closestDistance;
                    shortestPoint = arr[i][j];
                    sameDistanceZombies.clear();
                    sameDistanceZombies.push_back(arr[i][j]);
                }
                else if (closestDistance == shortestDistance)
                {
                    sameDistanceZombies.push_back(arr[i][j]);
                }
            }
        }
    }
    if (sameDistanceZombies.size() > 1)
    {
        // Generate a random number using rand() function.
        int randomIndex = rand() % sameDistanceZombies.size();
        // Access the random element in the vector.
        shortestPoint = sameDistanceZombies[randomIndex];
    }
    return shortestPoint;
}

void alienAttackIncrease(Character::Alien &aliens) // Allow alien attack to accumulate.
{
    int sum;
    aliens.setAttack(20);
    sum = aliens.accumulateAttack();
    aliens.clearAttack();
    aliens.setAttack(sum);
}

void alienAttackZero(Character::Alien &aliens) // Reset alien attack to zero.
{
    aliens.clearAttack();
    aliens.setAttack(0);
}

void alienAttack(Character::Zombie &zombies, Character::Alien &aliens, string &hitZombie, int **PositionZombie, string **arr, int &x, int &y, string &lastMove, int &row, int &column, string &hit, int &zombie, bool &bossSpawn) // Allow alien to attack zombie by direct hit.
{
    int attack = aliens.getAttack(0);
    int criticalPercent [8] = {1, 0, 1, 0, 0, 1, 0, 1};
    int criticalHit = criticalPercent[rand() % 8];
    if (criticalHit == 1)     // 50% of getting critical hit.
    {
        cout << "++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "     Alien deals a critical hit !     " << endl;
        cout << "++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        attack *= 1.2;
    }
    if (zombies.accumulateZombieLife() != 0)
    {
        int zombieNo = stoi(hitZombie);
        cout << "Zombie " << zombieNo << " received a damage of " << attack << "." << endl;
        if (attack >= zombies.getLife(zombieNo - 1))
        {
            zombies.eraseLife(zombieNo - 1);
            zombies.insertLife(0, zombieNo - 1);
            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = "A"; // Replace the zombie's position with alien
            cout << "Zombie " << hit << " is defeated." << endl;
            hit = continuousMove(hit, lastMove, x, y, arr, row, column, zombies);
        }
        else
        {
            int life = zombies.getLife(zombieNo - 1) - attack;
            zombies.eraseLife(zombieNo - 1);
            zombies.insertLife(life, zombieNo - 1);
            cout << "Zombie " << zombieNo << " survived the attack." << endl;
            lastMove = hitZombie;
        }
    }
    else
    {
        cout << "The BOSS received a damage of " << attack << "." << endl;
        if (attack >= zombies.getBossLife(0))
        {
            zombies.eraseBossLife();
            zombies.insertBossLife(0);
            cout << "The BOSS is defeated." << endl
                 << endl;
            cout << "================================================" << endl;
            cout << "   BOSS : NO ! That's impossible ! NO........" << endl;
            cout << "================================================" << endl;
            for (int i = 0; i < row; i++) // Replace the Boss's position with alien
            {
                for (int j = 0; j < column; j++)
                {
                    if (arr[i][j] == "B")
                    {
                        arr[i][j] == " ";
                    }
                }
            }
        }
        else
        {
            string speech[5] = {"It seems that I have over estimated you.", "Most impressive !", "You can't defeat me.", "Everything you did is worthless.", "Is that the all you got ?"};
            int life = zombies.getBossLife(0) - attack;
            zombies.eraseBossLife();
            zombies.insertBossLife(life);
            cout << "The BOSS survived the attack." << endl
                 << endl;
            cout << "=================================================" << endl;
            cout << "   BOSS : " << speech[rand() % 5] << endl;
            cout << "=================================================" << endl;
            lastMove = "B";
        }
    }
    cout << endl;
}

void hitObject(string &hit, Character::Alien &aliens, Character::Zombie &zombies, string &lastMove, int &row, int &column, string **arr, int &x, int &y, int **PositionZombie, int &zombie, bool bossSpawn, int &rowStart, int &turn) // Display different outputs based on what it hits.
{
    string hitZombie = "0";
    for (int i = 1; i <= zombies.sizeZombie(); i++)
    {
        if (hit == to_string(i))
        {
            hitZombie = to_string(i);
        }
    }
    if (hit == "^")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = "^";
        system("PAUSE");
    }
    else if (hit == "v")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = "v";
        system("PAUSE");
    }
    else if (hit == "<")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = "<";
        system("PAUSE");
    }
    else if (hit == ">")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = ">";
        system("PAUSE");
    }
    else if (hit == "h")
    {
        cout << "Alien finds a health pack." << endl;
        cout << "Alien's life is increased by 20." << endl;
        cout << endl;
        aliens.setLife(20);
        int totalLife = aliens.getLife(0) + aliens.getLife(1);
        aliens.clearLife();
        if (totalLife > 100)
        {
            totalLife = 100;
        }
        aliens.setLife(totalLife);
        system("PAUSE");
    }
    else if (hit == "@")
    {
        cout << "Alien finds a teleport portal." << endl;
        cout << "Alien teleported to other side." << endl;
        cout << endl;
        arr[x][y] = ".";
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                if (arr[i][j] == "@")
                {
                    arr[i][j] = "A";
                    x = i;
                    y = j;
                }
            }
        }
        system("PAUSE");
    }
    else if (hit == "~")
    {
        bool movedZombieBool = false;
        string moveZombie;
        cout << "Alien receives the mighty rod!" << endl;
        cout << "Position of zombie is being control." << endl;
        cout << endl;
        while (movedZombieBool == false)
        {
            cout << "Do you want to unleash this attribute (y/n)?: ";
            cin >> moveZombie;
            transform(moveZombie.begin(), moveZombie.end(), moveZombie.begin(), ::tolower);
            cout << endl;
            while (true)
            {
                if (moveZombie == "y")
                {
                    system("cls");
                    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                    int zombieNo;
                    string zombieMoveDirection;
                    bool validInput = false;
                    while (!validInput)
                    {
                        cout << "Choose your desire zombie to move its position by one (ex: 1 right): ";
                        if (cin >> zombieNo >> zombieMoveDirection)
                        {
                            validInput = true; // input is valid
                        }
                        else
                        {
                            cout << "Invalid input. Please enter an integer and a string ^^";
                            cout << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining characters in the input buffer
                        }
                    }
                    transform(zombieMoveDirection.begin(), zombieMoveDirection.end(), zombieMoveDirection.begin(), ::tolower);
                    int currentPosition[2];                               // current positon array
                    currentPosition[0] = PositionZombie[zombieNo - 1][0]; // row
                    currentPosition[1] = PositionZombie[zombieNo - 1][1]; // column
                    // cout <<"current zombie position row and column: "<< currentPosition[0] << " " << currentPosition[1] << endl; testing purpose;
                    if (zombieNo > 0 && zombieNo <= zombies.sizeZombie() && (zombieMoveDirection == "right" || zombieMoveDirection == "left" || zombieMoveDirection == "up" || zombieMoveDirection == "down"))
                    {
                        if (zombieMoveDirection == "right" && PositionZombie[zombieNo - 1][1] < column - 1 && arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1] + 1] != "A")
                        {

                            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = randomObject();
                            PositionZombie[zombieNo - 1][1] += 1;
                            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = to_string(zombieNo);
                            system("CLS");
                            displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                            cout << "======================================" << endl;
                            cout << "   Zombie " << zombieNo << " : How am I moved right?" << endl;
                            cout << "======================================" << endl;
                            cout << endl;
                            system("PAUSE");
                        }
                        else if (zombieMoveDirection == "left" && PositionZombie[zombieNo - 1][1] > 0 && arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1] - 1] != "A")
                        {

                            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = randomObject();
                            PositionZombie[zombieNo - 1][1] -= 1;
                            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = to_string(zombieNo);
                            system("CLS");
                            displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                            cout << "=====================================" << endl;
                            cout << "   Zombie " << zombieNo << " : How am I moved left?" << endl;
                            cout << "=====================================" << endl;
                            cout << endl;
                            system("PAUSE");
                        }
                        else if (zombieMoveDirection == "up" && PositionZombie[zombieNo - 1][0] > 0 && arr[PositionZombie[zombieNo - 1][0] - 1][PositionZombie[zombieNo - 1][1]] != "A")
                        {
                            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = randomObject();
                            PositionZombie[zombieNo - 1][0] -= 1;
                            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = to_string(zombieNo);
                            system("CLS");
                            displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                            cout << "===================================" << endl;
                            cout << "   Zombie " << zombieNo << " : How am I moved up?" << endl;
                            cout << "===================================" << endl;
                            cout << endl;
                            system("PAUSE");
                        }
                        else if (zombieMoveDirection == "down" && PositionZombie[zombieNo - 1][0] < row - 1 && arr[PositionZombie[zombieNo - 1][0] + 1][PositionZombie[zombieNo - 1][1]] != "A")
                        {

                            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = randomObject();
                            PositionZombie[zombieNo - 1][0] += 1;
                            arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = to_string(zombieNo);
                            system("CLS");
                            displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                            cout << "=====================================" << endl;
                            cout << "   Zombie " << zombieNo << " : How am I moved down?" << endl;
                            cout << "=====================================" << endl;
                            cout << endl;
                            system("PAUSE");
                        }
                        if (arr[currentPosition[0]][currentPosition[1]] == to_string(zombieNo))
                        {
                            system("CLS");
                            displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                            cout << "==================================" << endl;
                            cout << "   Zombie " << zombieNo << ": Did you made the right move??" << endl;
                            cout << "==================================" << endl;
                            cout << endl;
                            system("PAUSE");
                        }
                        movedZombieBool = true;
                        break;
                    }
                    else
                    {
                        cout << "Please enter a valid zombie no and direction." << endl;
                        continue;
                    }
                }
                else if (moveZombie == "n")
                {
                    system("CLS");
                    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                    cout << "===========================" << endl;
                    cout << "   Zombies : Silly you ! " << endl;
                    cout << "===========================" << endl;
                    cout << endl;
                    system("PAUSE");
                    movedZombieBool = true;
                    break;
                }
            }
        }
    }

    else if (hit == "p")
    {
        cout << "Alien found a pod!" << endl;
        if (zombies.accumulateZombieLife() != 0)
        {
            int closestZombie = std::stoi(findClosestZombie(row, column, arr, PositionZombie, zombie, zombies));
            if (closestZombie != 0)
            {
                int closestZombieLife = zombies.getLife(closestZombie - 1) - 10;
                if (closestZombieLife <= 0)
                {
                    arr[PositionZombie[closestZombie - 1][0]][PositionZombie[closestZombie - 1][1]] = " ";
                    closestZombieLife = 0;
                }
                zombies.eraseLife(closestZombie - 1);
                zombies.insertLife(closestZombieLife, (closestZombie - 1));
                cout << "Zombie " << zombies.getZombie(closestZombie - 1) + 1 << " receives a damage of 10." << endl;
                // cout << "test" << endl;
                if (zombies.getLife(closestZombie - 1) == 0)
                {
                    cout << "Zombie " << zombies.getZombie(closestZombie - 1) + 1 << " is defeated." << endl;
                    // cout << "test2" << endl;
                    // system("pause");
                }
            }
        }
        else if (zombies.accumulateZombieLife() == 0 && bossSpawn == true)
        {
            cout << "Pod is not effective to BOSS." << endl;
        }
        else
        {
            cout << "Nothing happened." << endl;
        }
        cout << endl;
        system("PAUSE");
    }
    else if (hit == "r")
    {
        string objectRock = randomRock();
        ;
        string objectBeneathRock;
        if (objectRock == "h")
        {
            objectBeneathRock = "a health pack";
            alienAttackZero(aliens);
        }
        else if (objectRock == "p")
        {
            objectBeneathRock = "a pod";
            alienAttackZero(aliens);
        }
        else if (objectRock == " ")
        {
            objectBeneathRock = "nothing";
            alienAttackZero(aliens);
        }
        else if (objectRock == "^")
        {
            objectBeneathRock = "an arrow (^)";
            alienAttackZero(aliens);
        }
        else if (objectRock == "v")
        {
            objectBeneathRock = "an arrow (v)";
            alienAttackZero(aliens);
        }
        else if (objectRock == "<")
        {
            objectBeneathRock = "an arrow (<)";
            alienAttackZero(aliens);
        }
        else if (objectRock == ">")
        {
            objectBeneathRock = "an arrow (>)";
            alienAttackZero(aliens);
        }
        cout << "Alien stumbles upon a rock." << endl;
        cout << "Alien discovers " << objectBeneathRock << " beneath the rock." << endl;
        cout << endl;
        arr[x][y] = objectRock;
        if (lastMove == "^")
        {
            x = x + 1;
            arr[x][y] = "A";
        }
        if (lastMove == "v")
        {
            x = x - 1;
            arr[x][y] = "A";
        }
        if (lastMove == "<")
        {
            y = y + 1;
            arr[x][y] = "A";
        }
        if (lastMove == ">")
        {
            y = y - 1;
            arr[x][y] = "A";
        }
        system("PAUSE");
    }
    else if (hit == " ")
    {
        cout << "Alien finds an empty space." << endl;
        cout << endl;
        system("PAUSE");
    }
    else if (hit == ".")
    {
        cout << "Alien finds an empty space." << endl;
        cout << endl;
        system("PAUSE");
    }
    else if (hit == hitZombie)
    {
        alienAttack(zombies, aliens, hitZombie, PositionZombie, arr, x, y, lastMove, row, column, hit, zombie, bossSpawn);
        system("PAUSE");
    }
    else if (hit == "B")
    {
        arr[x][y] = "B";
        if (lastMove == "^")
        {
            x = x + 1;
            arr[x][y] = "A";
        }
        if (lastMove == "v")
        {
            x = x - 1;
            arr[x][y] = "A";
        }
        if (lastMove == "<")
        {
            y = y + 1;
            arr[x][y] = "A";
        }
        if (lastMove == ">")
        {
            y = y - 1;
            arr[x][y] = "A";
        }
        alienAttack(zombies, aliens, hitZombie, PositionZombie, arr, x, y, lastMove, row, column, hit, zombie, bossSpawn);
        system("PAUSE");
    }
    else if (hit == "")
    {
        cout << "Alien is unable to move" << endl;
        cout << endl;
        system("PAUSE");
    }
}

void changeArrow(string **arr, int &row, int &column) // Allow user to change the direction of selected arrow.
{
    int x;
    int y;
    string updatedDirection;
    int error;
    do
    {
        error = 0;
        cout << "Enter row, column and direction (ex: 1 2 left): ";
        cin >> x >> y >> updatedDirection;
        transform(updatedDirection.begin(), updatedDirection.end(), updatedDirection.begin(), ::tolower);
        if (((x == cin.fail() || y == cin.fail()) || (x > row || x < 1 || y > column || y < 1) || (arr[x - 1][y - 1] != "^" && arr[x - 1][y - 1] != "v" && arr[x - 1][y - 1] != "<" && arr[x - 1][y - 1] != ">")) && (updatedDirection != "up" && updatedDirection != "down" && updatedDirection != "left" && updatedDirection != "right")) // Check invalid coordinate and direction.
        {
            cout << "Please enter a valid coordinate and direction." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (x == cin.fail() || y == cin.fail()) // Check invalid coordinate.
        {
            cout << "Please enter a valid coordinate." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (x > row || x < 1 || y > column || y < 1) // Check invalid coordinate.
        {
            cout << "Please enter a valid coordinate." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (arr[x - 1][y - 1] != "^" && arr[x - 1][y - 1] != "v" && arr[x - 1][y - 1] != "<" && arr[x - 1][y - 1] != ">") // Check invalid coordinate.
        {
            cout << "Please enter a valid coordinate." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (updatedDirection != "up" && updatedDirection != "down" && updatedDirection != "left" && updatedDirection != "right" || updatedDirection == "left" && arr[x - 1][y - 1] == "<" || updatedDirection == "right" && arr[x - 1][y - 1] == ">" || updatedDirection == "up" && arr[x - 1][y - 1] == "^" || updatedDirection == "down" && arr[x - 1][y - 1] == "v") // Check invalid direction.
        {

            cout << "Please enter a valid direction or new direction." << endl;
            error = 1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (error == 1);
    if (updatedDirection == "up")
    {
        updatedDirection = "^";
    }
    else if (updatedDirection == "down")
    {
        updatedDirection = "v";
    }
    else if (updatedDirection == "left")
    {
        updatedDirection = "<";
    }
    else if (updatedDirection == "right")
    {
        updatedDirection = ">";
    }
    string z = arr[x - 1][y - 1];
    arr[x - 1][y - 1] = updatedDirection;
    cout << "Arrow " << z << " is switched to " << updatedDirection << "." << endl;
    cout << endl;
    system("PAUSE");
}

//Zombie Functions

void assignZombie(int &row, int &column, int &zombie, string **arr, int **PositionZombie) // Generate zombies for the board.
{
    int numberAssignInt = 1;
    int randomRow, randomColumn;
    for (int i = 0; i < zombie; ++i)
    {
        do
        {
            randomRow = rand() % row;
            randomColumn = rand() % column;
        } while (arr[randomRow][randomColumn] == "A" || arr[randomRow][randomColumn] == "1" || arr[randomRow][randomColumn] == "2" || arr[randomRow][randomColumn] == "3" || arr[randomRow][randomColumn] == "4" || arr[randomRow][randomColumn] == "5" || arr[randomRow][randomColumn] == "6" || arr[randomRow][randomColumn] == "7" || arr[randomRow][randomColumn] == "8" || arr[randomRow][randomColumn] == "9");

        string numberAssignStr = to_string(numberAssignInt);
        arr[randomRow][randomColumn] = numberAssignStr;
        PositionZombie[i][0] = randomRow; // Assign the Row and Column of each zombie in the array.
        PositionZombie[i][1] = randomColumn;
        numberAssignInt = numberAssignInt + 1;
    }
}

void generateZombie(Character::Zombie &zombies, int &zombie, int &row, int &column, string **arr, int **PositionZombie, string mode) // Generate zombies with random life, attack and range.
{
    for (int i = 0; i < zombie; ++i)
    {
        zombies.setZombie(i);
        int zombieLife = randomLife(mode);
        zombies.setLife(zombieLife);
        int zombieAttack = randomAttack(mode);
        zombies.setAttack(zombieAttack);
        int zombieRange = randomRange(row, column);
        zombies.setRange(zombieRange);
    }
    assignZombie(row, column, zombie, arr, PositionZombie);
}

int **ZombiePosition(int &zombie) // Store position of every zombie.
{
    int **PositionZombie = new int *[zombie];
    for (int i = 0; i < zombie; i++)
    {
        PositionZombie[i] = new int[2];
    }
    return PositionZombie;
}

void zombieAttack(Character::Zombie &zombies, Character::Alien &aliens, int **PositionZombie, int &i, string **arr, int &row, int &column) // Zombie detect and attack alien if nearby.
{
    bool attack = false;
    for (int a = 1; a <= zombies.getRange(i); a++)
    {
        if (PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1]] == "A")
        { // To prevent oversize and detect upper position.
            attack = true;
            break;
        }
        if (PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1]] == "A")
        { // To prevent oversize and detect lower position.
            attack = true;
            break;
        }
        if (PositionZombie[i][1] + a <= column - 1 && arr[PositionZombie[i][0]][PositionZombie[i][1] + a] == "A")
        { // To prevent oversize and detect right position.
            attack = true;
            break;
        }
        if (PositionZombie[i][1] - a >= 0 && arr[PositionZombie[i][0]][PositionZombie[i][1] - a] == "A")
        { // To prevent oversize and detect left position.
            attack = true;
            break;
        }
        for (int b = 0; b <= zombies.getRange(i) - a; b++)
        {
            if (PositionZombie[i][1] + b <= column - 1 && PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1] + b] == "A")
            { // To detect upper right diagonal position.
                attack = true;
                break;
            }
            if (PositionZombie[i][1] - b >= 0 && PositionZombie[i][0] - a >= 0 && arr[PositionZombie[i][0] - a][PositionZombie[i][1] - b] == "A")
            { // To detect upper left diagonal position.
                attack = true;
                break;
            }
            if (PositionZombie[i][1] + b <= column - 1 && PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1] + b] == "A")
            { // To detect lower right diagonal position.
                attack = true;
                break;
            }
            if (PositionZombie[i][1] - b >= 0 && PositionZombie[i][0] + a <= row - 1 && arr[PositionZombie[i][0] + a][PositionZombie[i][1] - b] == "A")
            { // To detect lower left diagonal position.
                attack = true;
                break;
            }
        }
    }

    if (attack == false)
    {
        cout << "Zombie " << i + 1 << " is unable to attack alien." << endl;
        cout << "Alien is too far away." << endl;
    }
    else if (attack == true)
    {
        cout << "Zombie " << i + 1 << " attacks Alien." << endl;
        cout << "Alien receives a damage of " << zombies.getAttack(i) << "." << endl;
        aliens.setLife(zombies.getAttack(i));
        int totalLife = aliens.getLife(0) - aliens.getLife(1);
        aliens.clearLife();
        if (totalLife < 0)
        {
            totalLife = 0;
        }
        aliens.setLife(totalLife);
    }
}

void zombieMove(Character::Zombie &zombies, Character::Alien &aliens, int &row, int &column, string **arr, int **PositionZombie, int &rowStart, int &zombie, bool &bossSpawn, int &turn) // Action for zombie to move.
{
    turn = turn + 1;
    alienAttackZero(aliens);
    for (int i = 0; i < zombie; i++)
    {
        if (zombies.getLife(i) == 0)
        {
            turn = turn + 1;
            continue;
        }
        system("cls");
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
        string direction[4] = {"left", "right", "up", "down"};
        string move = direction[rand() % 4];
        bool hitZombie = false;
        rowStart = 0;
        cout << "Zombie " << i + 1 << "'s turn." << endl;
        if (move == "up")
        { // Movement depend on direcction move.
            cout << "Zombie " << i + 1 << " moves up." << endl;
            if (PositionZombie[i][0] > 0 && arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] != "A" && arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] != "r" && arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] != "~") // Prevent hit the border, the alien and the rock.
            {
                for (int j = 1; j <= zombies.sizeZombie(); j++)
                {
                    if (arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] == to_string(j))
                    {
                        hitZombie = true;
                    }
                }
                if (hitZombie == false)
                {
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = " "; // Change the original zombie's position into empty.
                    PositionZombie[i][0] = PositionZombie[i][0] - 1;
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1); // Place the zombie in the new position.
                }
            }
        }
        else if (move == "down")
        {
            cout << "Zombie " << i + 1 << " moves down." << endl;
            if (PositionZombie[i][0] < row - 1 && arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] != "A" && arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] != "r" && arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] != "~")
            {
                for (int j = 1; j <= zombies.sizeZombie(); j++)
                {
                    if (arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] == to_string(j))
                    {
                        hitZombie = true;
                    }
                }
                if (hitZombie == false)
                {
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                    PositionZombie[i][0] = PositionZombie[i][0] + 1;
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
                }
            }
        }
        else if (move == "left")
        {
            cout << "Zombie " << i + 1 << " moves left." << endl;
            if (PositionZombie[i][1] > 0 && arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] != "A" && arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] != "r" && arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] != "~")
            {
                for (int j = 1; j <= zombies.sizeZombie(); j++)
                {
                    if (arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] == to_string(j))
                    {
                        hitZombie = true;
                    }
                }
                if (hitZombie == false)
                {
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                    PositionZombie[i][1] = PositionZombie[i][1] - 1;
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
                }
            }
        }
        else
        {
            cout << "Zombie " << i + 1 << " moves right." << endl;
            if (PositionZombie[i][1] < column - 1 && arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] != "A" && arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] != "r" && arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] != "~")
            {
                for (int j = 1; j <= zombies.sizeZombie(); j++)
                {
                    if (arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] == to_string(j))
                    {
                        hitZombie = true;
                    }
                }
                if (hitZombie == false)
                {
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
                    PositionZombie[i][1] = PositionZombie[i][1] + 1;
                    arr[PositionZombie[i][0]][PositionZombie[i][1]] = to_string(i + 1);
                }
            }
        }
        cout << endl;
        system("PAUSE");
        system("CLS");
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
        zombieAttack(zombies, aliens, PositionZombie, i, arr, row, column);
        if (aliens.getLife(0) == 0)
        {
            cout << "Alien is defeated." << endl;
            system("PAUSE");
            break;
        }
        turn = turn + 1;
        cout << endl;
        system("PAUSE");
    }
}

//Additional Features

void statusBoss(Character::Zombie &zombies, string &mode) // Assign attributes for zombie boss.
{
    if (mode == "easy") // Initialize Boss status
    {
        zombies.setBossLife(500);
        zombies.setBossAttack(50);
        zombies.setBossCD(3);
    }
    else if (mode == "medium")
    {
        zombies.setBossLife(650);
        zombies.setBossAttack(70);
        zombies.setBossCD(3);
    }
    else if (mode == "hard")
    {
        zombies.setBossLife(800);
        zombies.setBossAttack(99);
        zombies.setBossCD(3);
    }
    else if (mode == "nightmare")
    {
        zombies.setBossLife(1000);
        zombies.setBossAttack(999);
        zombies.setBossCD(5);
    }
}

void Boss(Character::Alien &aliens, Character::Zombie &zombies, string **arr, int &row, int &column, bool &bossSpawn, int &zombie, int &rowStart, int &turn, string mode) // Assign boss to the game board.
{
    system("CLS");
    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] == "B")
            {
                arr[i][j] = " ";
            }
        }
    }
    int x, y;
    do
    {
        x = rand() % row;
        y = rand() % column;
    } while (arr[x][y] == "A");

    arr[x][y] = "B"; // Assign Boss position, changed every round.

    int CD0; // The boss original CD.
    if (mode == "nightmare")
    {
        CD0 = 5;
    }
    else
    {
        CD0 = 3;
    }
    int CD = zombies.getBossCD(0); // Reduce cd of Boss.
    int alienHP;
    CD -= 1;
    if (CD == 0) // Boss attack alien at CD 0.
    {
        cout << "The BOSS attack alien." << endl;
        cout << "Alien receives a damage of " << zombies.getBossAttack(0) << "." << endl;
        alienHP = aliens.getLife(0) - zombies.getBossAttack(0);
        if (alienHP <= 0)
        {
            cout << endl;
            cout << "==========================================" << endl;
            cout << "   BOSS : Is that the best you can do ?" << endl;
            cout << "==========================================" << endl;
            alienHP = 0;
        }
        else
        {
            cout << endl;
            cout << "=================================================" << endl;
            cout << "   BOSS : It is surprised that you are alive !" << endl;
            cout << "=================================================" << endl;
            Sleep(1500);
            cout << "==================================" << endl;
            cout << "   BOSS : Ha, let us continue ." << endl;
            cout << "==================================" << endl;
        }
        aliens.clearLife();
        aliens.setLife(alienHP);
        zombies.eraseBossCD();
        zombies.insertBossCD(CD0);
    }
    else if (bossSpawn == true)
    {
        system("CLS");
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
        cout << "The BOSS does not attack. " << endl;
        zombies.eraseBossCD();
        zombies.insertBossCD(CD);
    }
}

void GameOver() // Animation for game over.
{
    string letterG[5] = {"  0000 ", "0      ", "0   000", "0     0", "  0000 "};
    string letterA[5] = {"  000  ", " 0   0 ", "0000000", "0     0", "0     0"};
    string letterM[5] = {"00   00", "0 0 0 0", "0  0  0", "0     0", "0     0"};
    string letterE[5] = {"0000000", "0      ", "00000  ", "0      ", "0000000"};
    string letterO[5] = {"  000  ", "0     0", "0     0", "0     0", "  000  "};
    string letterV[5] = {"0     0", "0     0", "0     0", " 0   0 ", "  000  "};
    string letterR[5] = {"00000  ", "0    0 ", "00000  ", "0    0 ", "0     0"};

    for (int i = 0; i <= 5; i++)
    {
        system("cls");
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            for (int space = 4; space >= i; space--)
            {
                cout << "       ";
                cout << "  ";
            }
            if (i > 0)
            {
                cout << letterG[j] << "  ";
            }
            if (i > 1)
            {
                cout << letterA[j] << "  ";
            }
            if (i > 2)
            {
                cout << letterM[j] << "  ";
            }
            if (i > 3)
            {
                cout << letterE[j] << "  ";
            }
            if (i > 4)
            {
                cout << "       ";
                cout << "  ";
            }
            cout << endl;
        }
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            if (i > 4)
            {
                cout << "       ";
                cout << "  ";
            }
            if (i > 3)
            {
                cout << letterO[j] << "  ";
            }
            if (i > 2)
            {
                cout << letterV[j] << "  ";
            }
            if (i > 1)
            {
                cout << letterE[j] << "  ";
            }
            if (i > 0)
            {
                cout << letterR[j] << "  ";
            }
            cout << endl;
        }
        Sleep(250); // delay 250 milliseconds
    }
    cout << endl
         << endl;
}

void YouWin() // Animation for you win.
{
    string letterY[5] = {"0     0", " 0   0 ", "  0 0  ", "   0   ", "   0   "};
    string letterO[5] = {"  000  ", "0     0", "0     0", "0     0", "  000  "};
    string letterU[5] = {"0     0", "0     0", "0     0", "0     0", "  000  "};
    string letterW[5] = {"0     0", "0     0", "0  0  0", "0 0 0 0", "00   00"};
    string letterI[5] = {"0000000", "   0   ", "   0   ", "   0   ", "0000000"};
    string letterN[5] = {"00    0", "0 0   0", "0  0  0", "0   0 0", "0    00"};

    for (int i = 0; i <= 4; i++)
    {
        system("cls");
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            for (int space = 3; space >= i; space--)
            {
                cout << "       ";
                cout << "  ";
            }
            if (i > 0)
            {
                cout << letterY[j] << "  ";
            }
            if (i > 1)
            {
                cout << letterO[j] << "  ";
            }
            if (i > 2)
            {
                cout << letterU[j] << "  ";
            }
            if (i > 3)
            {
                cout << "       ";
                cout << "  ";
            }
            cout << endl;
        }
        cout << endl;
        for (int j = 0; j < 5; j++)
        {
            if (i > 3)
            {
                cout << "       ";
                cout << "  ";
            }
            if (i > 2)
            {
                cout << letterW[j] << "  ";
            }
            if (i > 1)
            {
                cout << letterI[j] << "  ";
            }
            if (i > 0)
            {
                cout << letterN[j] << "  ";
            }
            cout << endl;
        }
        Sleep(250);
    }
    cout << endl
         << endl;
}

void assignPortal(string **arr, int &row, int &column, bool &portal) // Randomly assign portals to the board.
{
    if (portal == false)
    {
        // int numberAssignInt = 1;
        int randomRow, randomColumn;
        for (int i = 0; i < 2; ++i)
        {
            do
            {
                randomRow = rand() % row;
                randomColumn = rand() % column;
            } while (arr[randomRow][randomColumn] == "A" || arr[randomRow][randomColumn] == "1" || arr[randomRow][randomColumn] == "2" || arr[randomRow][randomColumn] == "3" || arr[randomRow][randomColumn] == "4" || arr[randomRow][randomColumn] == "5" || arr[randomRow][randomColumn] == "6" || arr[randomRow][randomColumn] == "7" || arr[randomRow][randomColumn] == "8" || arr[randomRow][randomColumn] == "9" || arr[randomRow][randomColumn] == "@" || arr[randomRow][randomColumn] == "B" || arr[randomRow][randomColumn] == "~");

            arr[randomRow][randomColumn] = "@";
        }
        portal = true;
    }
}

void removePortal(string **arr, int &row, int &column, bool &portal) // Remove all portals on the board.
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if (arr[i][j] == "@")
            {
                arr[i][j] = " ";
            }
        }
    }
    portal = false;
}

void assignSpecialAttribute(string **arr, int &row, int &column, bool &specialAttribute) // Randomly assign portals to the board.
{
    if (specialAttribute == false)
    {
        // int numberAssignInt = 1;
        int randomRow, randomColumn;
        do
        {
            randomRow = rand() % row;
            randomColumn = rand() % column;
        } while (arr[randomRow][randomColumn] == "A" || arr[randomRow][randomColumn] == "1" || arr[randomRow][randomColumn] == "2" || arr[randomRow][randomColumn] == "3" || arr[randomRow][randomColumn] == "4" || arr[randomRow][randomColumn] == "5" || arr[randomRow][randomColumn] == "6" || arr[randomRow][randomColumn] == "7" || arr[randomRow][randomColumn] == "8" || arr[randomRow][randomColumn] == "9" || arr[randomRow][randomColumn] == "@" || arr[randomRow][randomColumn] == "B");

        arr[randomRow][randomColumn] = "~";
        specialAttribute = true;
    }
}

void removeSpecialAttribute(string **arr, int &row, int &column, bool &specialA) // Remove all portals on the board.
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if (arr[i][j] == "~")
            {
                arr[i][j] = " ";
            }
        }
    }
    specialA = false;
}

void effect(int &row, bool &bossSpawn) // effect when the boss is spawn and after it is defeated.
{
    string x08 = "                           ____________________                              ";
    string x07 = "  __-@--%_-**-_ _          ____________________          @ -$_= _-=*_ #%     ";
    string x06 = "     --__-++_-__ -%#       ____________________         *- _& - _+=-_=       ";
    string x05 = "      #-_%-_--$#_- +-      ____________________        _ -@- ++ _ *_         ";
    string x04 = "        _-_#=- $&* -       ____________________      - % - =+ _ -#*          ";
    string x03 = "            -#_--+ =_@ _   ____________________    %   @# -_+-* _            ";
    string x02 = "                _*_-+ _ &- ____________________ - _ *#-_-_+-                 ";
    string x01 = "                   =#$%&#* ____________________ #^&^@&*                      ";
    string x00 = "                       &#*&^$%#$*^&*%^#$%*&*%^$**#^                          ";

    system("cls");
    int count = 28;
    for (int i = 1; i <= count; i++)
    {
        cout << x08 << endl;
        Sleep(20);
    }
    for (int i = 1; i <= count; i++)
    {
        system("cls");
        for (int j = 28; j >= i; j--)
        {
            cout << x08 << endl;
        }
        if (i > 7)
        {
            cout << x07 << endl;
        }
        if (i > 6)
        {
            cout << x06 << endl;
        }
        if (i > 5)
        {
            cout << x05 << endl;
        }
        if (i > 4)
        {
            cout << x04 << endl;
        }
        if (i > 3)
        {
            cout << x03 << endl;
        }
        if (i > 2)
        {
            cout << x02 << endl;
        }
        if (i > 1)
        {
            cout << x01 << endl;
        }
        if (i > 0)
        {
            cout << x00 << endl;
        }
        if (i == 8)
        {
            Sleep(200);
            break;
        }
        Sleep(20);
    }
    if (bossSpawn == false)
    {
        system("cls");
        string s01 = "             ,:;=*CYI/+++\\IL=+,";
        string s02 = "         .;&AZOYJI**+<;:-,,-:+=+L;,";
        string s03 = "      ,AHRKOPJ**<---,,,...,,--:\\>+IL\\,";
        string s04 = "    ,6EHKRZFJ*</---,,,.....,,--:;\\>*IO\\,";
        string s05 = "   ,AEHRAZOVI+<<--,,,..........,,--;=*II\\";
        string s06 = "  ;AWHRKKXCI=/--,,,.............,,,->+*IL\\";
        string s07 = " .HBEEHKR&I+/--,,,...............,,-:\\;*IL\\";
        string s08 = ".;REHRKROLI*<;-,,,................,,-;>\\*IF\\";
        string s09 = ".EHEHDSZOTJ*<\\-,,,................,,-:>=+I*L:";
        string s10 = ".EEEHAGOPTI+\\:--,,,................,,-:>+I*II";
        string s11 = ":EHEEBDOPJ*=<;:+-,,....,,..........,,-;/II11I";
        string s12 = ":HEEBWADSFJI<\\<<::--,....,,,,----,,.,,:JAIIJI";
        string s13 = ":ZKREWXRKSCI*=<<;::;::,.-:/>/;;::--,.\\/\\/KFLYT;";
        string s14 = ".XACHWEKS*;:--6-\\:,.:;:,\\/\\/;.,;=,,,,..,IRFYT&'";
        string s15 = "'HDWNBC/JNMMMMMMNBC+=<<;-,-JHMMNMWRA;,.HFTYT";
        string s16 = " XANMH/JMMMMMMMMMMEHAJI*=:IMMMMMMMMMMB*YYJLT";
        string s17 = " EBWYD1HEMMMMMMMMMBHAP*,1,HNMMMMMMMMMM:.\\TLY";
        string s18 = " EWMZS\\SBWNMNMMMWBWEPI<.I.EBWNMMMMNMMN;.:IYL";
        string s19 = " CBNDNE\\CHBEBEEBR/HEPT&I;:'YI&SEBWNNWB:.:LLT";
        string s20 = " /XKAWB\\<JYNBXS/JHETMXHNL=+<-,*TWBENEP,.-LYL,";
        string s21 = " SXRCBWBO&+*ICKHWNCBMARMMA\\<=\\*.*,,,:;1.,;I'";
        string s22 = "  TEBWHI<*/;TRJJTBDMMXKMMEI-;*JZLZJI*=--;/Y'";
        string s23 = "   'THCL;,.\\<:;AENCMMAGNMHI-*F;\\IJDHSI/IJF";
        string s24 = "     :ENBWM6+*JKHEF:*TYT*I-;-\\L\\A6NHGTJIF";
        string s25 = "      =AWHWMWYDRKY1:+:YI-I-I\\,1:MMNIRXHJ";
        string s26 = "       XHPNMHAKZDCY<K:AI,I,I,1,\\WMMWIYI";
        string s27 = "       KPOMMOIGLBIHCE=WI7VT-I1;7JMMBIJ'";
        string s28 = "       XZFBNDRLIB1HLB.W1.LL,I\\I,JWH/IJ";
        string s29 = "       OTA6BHZLIY;HTF=H-JIJII\\-1JVZ:JI";
        string s30 = "       ZXSH&BEKLH0E1IIY-I/:1IJ=*J:/TIJ,";
        string s31 = "       YDRETLHTTLZIJJITJLII11:\\-,.*TIJ";
        string s32 = "        =<F&TVI6I*+/;:T:I:I-16.,:/J/-";
        string s33 = "          'VFTLIII=\\;:JL:,...7,7JJ/";
        string s34 = "             'TJCYJJIV/\\V,,,/,JV'";
        string s35 = "               'TL\\:=+L.J==/JF-";
        string s36 = "                 'TOD6X&LJF''";

        for (int i = 0; i < 3; i++)
        {
            cout << s01 << endl;
            cout << s02 << endl;
            cout << s03 << endl;
            cout << s04 << endl;
            cout << s05 << endl;
            cout << s06 << endl;
            cout << s07 << endl;
            cout << s08 << endl;
            cout << s09 << endl;
            cout << s10 << endl;
            cout << s11 << endl;
            cout << s12 << endl;
            cout << s13 << endl;
            cout << s14 << endl;
            cout << s15 << endl;
            cout << s16 << endl;
            cout << s17 << endl;
            cout << s18 << endl;
            cout << s19 << endl;
            cout << s20 << endl;
            cout << s21 << endl;
            cout << s22 << endl;
            cout << s23 << endl;
            cout << s24 << endl;
            cout << s25 << endl;
            cout << s26 << endl;
            cout << s27 << endl;
            cout << s28 << endl;
            cout << s29 << endl;
            cout << s30 << endl;
            cout << s31 << endl;
            cout << s32 << endl;
            cout << s33 << endl;
            cout << s34 << endl;
            cout << s35 << endl;
            cout << s36 << endl;
            Sleep(400);
            system("cls");
            Sleep(250);
        }
        for (int i = 0; i < 5; i++)
        {
            cout << s01 << endl;
            cout << s02 << endl;
            cout << s03 << endl;
            cout << s04 << endl;
            cout << s05 << endl;
            cout << s06 << endl;
            cout << s07 << endl;
            cout << s08 << endl;
            cout << s09 << endl;
            cout << s10 << endl;
            cout << s11 << endl;
            cout << s12 << endl;
            cout << s13 << endl;
            cout << s14 << endl;
            cout << s15 << endl;
            cout << s16 << endl;
            cout << s17 << endl;
            cout << s18 << endl;
            cout << s19 << endl;
            cout << s20 << endl;
            cout << s21 << endl;
            cout << s22 << endl;
            cout << s23 << endl;
            cout << s24 << endl;
            cout << s25 << endl;
            cout << s26 << endl;
            cout << s27 << endl;
            cout << s28 << endl;
            cout << s29 << endl;
            cout << s30 << endl;
            cout << s31 << endl;
            cout << s32 << endl;
            cout << s33 << endl;
            cout << s34 << endl;
            cout << s35 << endl;
            cout << s36 << endl;
            Sleep(100);
            system("cls");
            Sleep(20);
        }
    }
}

int main()
{
    system("CLS");
    string mode = difficulty();
    Character::Alien aliens;
    Character::Zombie zombies;
    ifstream file;
    bool updated = false;
    srand(time(NULL));
    int row, column, zombie, turn, rowStart;
    if (updated == false)
    {
        row = 5;    // Default setting for row.
        column = 9; // Default setting for column.
        zombie = 1; // Default setting for zombie.
    }
    bool portal = false;
    bool specialAttribute = false;
    bool exit = false;
    bool generate = true;
    bool bossSpawn = false;
    setting(row, column, zombie);
    int **PositionZombie = ZombiePosition(zombie); // Initialize an array to store the position of zombie.
    string **arr = generate2DArr(row, column);     // Initialize an array for the board.
    int x = (row - 1) / 2;                         // Find the center in the row.
    int y = (column - 1) / 2;                      // Find the center in the column.
    statusBoss(zombies, mode);
    while (generate != false)
    {
        generateRandom(arr, row, column);
        string alien = "A";
        arr[x][y] = alien;
        generate = false;
    }
    generateZombie(zombies, zombie, row, column, arr, PositionZombie, mode);
    string command;
    while (exit != true)
    {
        turn = 0;
        cout << arr[x][y] << endl;
        system("CLS");
        if (bossSpawn == false)
        {
            assignSpecialAttribute(arr, row, column, specialAttribute);
        }
        assignPortal(arr, row, column, portal);
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
        commandUser(command);
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        string lastMove;
        string hit;
        if (command == "quit")
        {
            GameOver();
            system("pause");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            exit = true;
            break;
        }
        else if (command == "up" || command == "down" || command == "left" || command == "right")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool alienHitRock = false;
            int currentX;
            if (command == "up")
            {
                hit = moveUp(x, y, arr, hit, zombies);
                lastMove = "^";
            }
            else if (command == "down")
            {
                hit = moveDown(x, y, arr, hit, row, zombies);
                lastMove = "v";
            }
            else if (command == "left")
            {
                hit = moveLeft(x, y, arr, hit, zombies);
                lastMove = "<";
            }
            else if (command == "right")
            {
                hit = moveRight(x, y, arr, hit, column, zombies);
                lastMove = ">";
            }
            hitObject(hit, aliens, zombies, lastMove, row, column, arr, x, y, PositionZombie, zombie, bossSpawn, rowStart, turn);
            if (hit == "r")
            {
                alienHitRock = true;
            }
            while (alienHitRock != true)
            {
                if ((x == 0 && lastMove == "^") || (x == (row - 1) && lastMove == "v") || (y == 0 && lastMove == "<") || (y == (column - 1) && lastMove == ">") || (lastMove <= to_string(zombies.sizeZombie())) || (zombies.accumulateZombieLife() == 0 && zombies.getBossLife(0) == 0) || (lastMove == "B"))
                {
                    break;
                }
                else
                {
                    system("CLS");
                    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                    hit = continuousMove(hit, lastMove, x, y, arr, row, column, zombies);
                    hitObject(hit, aliens, zombies, lastMove, row, column, arr, x, y, PositionZombie, zombie, bossSpawn, rowStart, turn);
                    if (hit == "r")
                    {
                        alienHitRock = true;
                    }
                }
            }
            if (zombies.getBossLife(0) != 0)
            {
                system("CLS");
                displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                generateRandomTrail(arr, row, column, zombie, rowStart, aliens, zombies);
                system("PAUSE");
                removeSpecialAttribute(arr, row, column, specialAttribute);
                removePortal(arr, row, column, portal);
                zombieMove(zombies, aliens, row, column, arr, PositionZombie, rowStart, zombie, bossSpawn, turn);
            }
            else
            {
                effect(row, bossSpawn);
            }

            if (zombies.accumulateZombieLife() == 0 && zombies.getBossLife(0) != 0)
            {
                Boss(aliens, zombies, arr, row, column, bossSpawn, zombie, rowStart, turn, mode);
                if (bossSpawn == false)
                {
                    system("CLS");
                    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                    cout << "Here comes the boss !" << endl
                         << endl;
                    system("PAUSE");
                    effect(row, bossSpawn);
                    bossSpawn = true;
                    system("CLS");
                    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                    if (mode == "easy")
                    {
                        cout << "===============================" << endl;
                        cout << "   BOSS : Here is the gift ." << endl;
                        cout << "===============================" << endl;
                        cout << endl;
                        cout << "Alien gifted 30 health points. " << endl;
                        int alienHP = aliens.getLife(0) + 30;
                        if (alienHP > 100)
                        {
                            alienHP = 100;
                        }
                        aliens.clearLife();
                        aliens.setLife(alienHP);
                    }
                    else if (mode == "medium")
                    {
                        cout << "=================================================" << endl;
                        cout << "   BOSS : Now you have to face the true test ." << endl;
                        cout << "=================================================" << endl;
                        cout << endl;
                        cout << "Alien's life is deducted into 30. " << endl;
                        aliens.clearLife();
                        aliens.setLife(30);
                    }
                    else if (mode == "hard")
                    {
                        cout << "========================================" << endl;
                        cout << "   BOSS : Prepare to meet your doom !" << endl;
                        cout << "========================================" << endl;
                        cout << endl;
                        cout << "Alien's life is deducted into 1. " << endl;
                        aliens.clearLife();
                        aliens.setLife(1);
                    }
                    else if (mode == "nightmare")
                    {
                        cout << "=======================================================" << endl;
                        cout << "   BOSS : You will now feel the full power of mine !" << endl;
                        cout << "=======================================================" << endl;
                        cout << endl;
                        cout << "Alien's life is deducted into 1. " << endl;
                        aliens.clearLife();
                        aliens.setLife(1);
                    }
                }
                cout << endl;
                system("pause");
            }
            if ((zombies.accumulateZombieLife() == 0 && zombies.getBossLife(0) == 0) || aliens.getLife(0) == 0)
            {
                if (aliens.getLife(0) == 0)
                {
                    GameOver();
                }
                else if (zombies.accumulateZombieLife() == 0 && zombies.getBossLife(0) == 0)
                {
                    YouWin();
                }
                while (true)
                {
                    cout << "Do you want to restart the game (y/n)?:";
                    string restart;
                    cin >> restart;
                    transform(restart.begin(), restart.end(), restart.begin(), ::tolower);
                    cout << endl;
                    if (restart == "n")
                    {
                        exit = true;
                        break;
                    }
                    else if (restart == "y")
                    {
                        system("cls");
                        main();
                        exit = true;
                        break;
                    }
                    else
                    {
                        cout << "Please enter a valid input !" << endl
                             << endl;
                    }
                }
            }
        }

        else if (command == "arrow")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            changeArrow(arr, row, column);
        }
        else if (command == "help")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            help();
            cout << endl;
            system("PAUSE");
        }
        else if (command == "object")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            object();
            cout << endl;
            system("PAUSE");
        }
        else if (command == "save")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string saveFileName;
            cout << "Enter the file name to save the current game (.txt): ";
            cin >> saveFileName;
            file.open(saveFileName);
            if (file.is_open())
            {
                cout << "Saved file is overwritten! " << endl;
                file.close();
            }
            // Need to save bossCD, bossLife, bossAttack and bossSpawn
            save(aliens, zombies,mode, column, row, arr, PositionZombie, x, y, bossSpawn, saveFileName);

            cout << "Game saved!" << endl;
            system("PAUSE");
        }
        else if (command == "load")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string saveFileName;
            string loadFileName;
            // bool saving = false;
            while (true)
            {
                string saveFile;
                system("cls");
                displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                cout << "Do you want to save the current game? (y/n): ";
                cin >> saveFile;

                if (saveFile == "y")
                {
                    cout << "Enter the file name to save the current game (.txt): ";
                    cin >> saveFileName;
                    transform(saveFileName.begin(), saveFileName.end(), saveFileName.begin(), ::tolower);
                    file.open(saveFileName);
                    if (file.is_open())
                    {
                        cout << "Saved file is overwritten! " << endl;
                        system("pause");
                        file.close();
                    }
                    save(aliens, zombies,mode, column, row, arr, PositionZombie, x, y,bossSpawn, saveFileName);
                    cout << endl;
                    break;
                }
                else if (saveFile == "n")
                {
                    break;
                }
                else
                {
                    cout << "Please enter a valid input ! " << endl;
                }
                system("pause");
            }
            while (true)
            {
                cout << "Enter load file name(.txt): ";
                cin >> loadFileName;
                transform(loadFileName.begin(), loadFileName.end(), loadFileName.begin(), ::tolower);
                file.open(loadFileName);
                if (file.is_open()) // if the desired load file is in the directory
                {
                    mode = getSavedMode(loadFileName);
                    row = getSavedRow(loadFileName);
                    column = getSavedColumn(loadFileName);
                    arr = getSavedArray(loadFileName);
                    aliens.setLife(getSavedAlienLife(loadFileName));
                    aliens.clearAttack();
                    aliens.setAttack(getSavedAlienAttack(loadFileName));
                    zombies.replacedSavedLife(getSavedZombieLife(loadFileName));
                    zombies.replacedSavedAttack(getSavedZombieAttack(loadFileName));
                    zombies.replacedSavedZombie(getSavedZombieNo(loadFileName));
                    zombies.replacedSavedRange(getSavedZombieRange(loadFileName));
                    zombie = zombies.sizeZombie();
                    PositionZombie = getSavedPositionZombie(loadFileName);
                    bossSpawn = getSavedBossSpawn(loadFileName);
                    zombies.replacedSavedBossLife(getSavedBossLife(loadFileName));
                    zombies.replacedSavedBossAttack(getSavedBossAttack(loadFileName));
                    zombies.replacedSavedBossCD(getSavedBossCD(loadFileName));
                    x = getSavedAlienPositionX(loadFileName);
                    y = getSavedAlienPositionY(loadFileName);
                    break;
                }
                else
                {
                    cout << "File not found, please enter a new file name." << endl;
                    system("pause");
                    system("cls");
                    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies, bossSpawn, turn);
                }
                file.close();
            }
            cout << endl;
            system("PAUSE");
        }
        else if (command == "restart")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("PAUSE");
            main();
            exit = true;
            break;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid command." << endl;
            cout << "You can view the command list by entering command \'help\'." << endl;
            cout << endl;
            system("PAUSE");
        }
    }
}