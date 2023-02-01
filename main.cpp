// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT1L
// Names: Wesley Wong Min Guan | Tang Yu Xuan | Koh JIa Jie
// IDs: 1211101998 | 1211103236 | 1211102879
// Emails: MEMBER_EMAIL_1 | MEMBER_EMAIL_2 | MEMBER_EMAIL_3
// Phones: 0125881773 | 01139214061 | 0163091595
// *********************************************************

#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <climits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

class Character
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

    public:
        void setZombie(int zombieID) { zombieNo.push_back(zombieID); } // Set a new zombie.
        int getZombie(int index) { return zombieNo.at(index); }        // Return the zombie ID.
        int sizeZombie() { return zombieNo.size(); };                  // Return the number of the zombies.

        void setLife(int life) { zombieLife.push_back(life); }                                                    // Set another life using pushback.
        int getLife(int index) { return zombieLife.at(index); }                                                   // Get life at the specified index.
        void insertLife(int newLife, int position) { zombieLife.insert(zombieLife.begin() + position, newLife); } // Set new life for selected zombie.
        void eraseLife(int position) { zombieLife.erase(zombieLife.begin() + position); }                         // Clear life for selected zombie.
        int sizeLife() { return zombieLife.size(); };                                                             // Return the size of the vector.
        int accumulateZombieLife() { return accumulate(zombieLife.begin(), zombieLife.end(), 0); }                // return the accumulation of the attacks in the alien attack.

        void setAttack(int attack) { zombieAttack.push_back(attack); } // Set another life using pushback.
        int getAttack(int index) { return zombieAttack.at(index); }    // Get life at the specified index.
        int sizeAttack() { return zombieAttack.size(); }               // Return the size of the vector.

        void setRange(int range) { zombieRange.push_back(range); } // Set another life using pushback.
        int getRange(int index) { return zombieRange.at(index); }  // Get life at the specified index.
        int sizeRange() { return zombieRange.size(); }             // Return the size of the vector.
    };
};

void save(Character::Alien &aliens, Character::Zombie &zombies, int &column, int &row, string **arr, string saveFileName)
{
    // Alien.
    ofstream file;
    file.open(saveFileName);
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
    file << "Row: ";
    file << row << endl;
    file << "Column: ";
    file << column << endl;
    file << "2D Array: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            file << arr[i][j] << " ";
        }
        file << endl;
    }
    file << endl;
    file.close();
}

int getSavedAlienLife(string loadFileName)
{
    int savedAlienLife;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Alien Life: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(12);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedAlienLife = n;
            }
        }
    }
    return savedAlienLife;
}

int getSavedAlienAttack(string loadFileName)
{
    int savedAlienAttack;
    ifstream file; // Create a file object.
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Alien Attack: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(14);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedAlienAttack = n;
            }
        }
    }
    return savedAlienAttack;
}

vector<int> getSavedZombieNo(string loadFileName)
{
    vector<int> savedZombieNo;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Zombies No: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(12);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedZombieNo.push_back(n);
            }
        }
    }
    return savedZombieNo;
}

vector<int> getSavedZombieLife(string loadFileName)
{
    vector<int> savedZombieLife;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Zombies Life: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(14);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedZombieLife.push_back(n);
            }
        }
    }
    return savedZombieLife;
}

vector<int> getSavedZombieAttack(string loadFileName)
{
    vector<int> savedZombieAttack;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Zombies Attack: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(16);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedZombieAttack.push_back(n);
            }
        }
    }
    return savedZombieAttack;
}

vector<int> getSavedZombieRange(string loadFileName)
{
    vector<int> savedZombieRange;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Zombies Range: ") != string::npos) // Finds for Alien Life.
        {
            line = line.substr(15);  // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedZombieRange.push_back(n);
            }
        }
    }
    return savedZombieRange;
}

int getSavedRow(string loadFileName)
{
    int savedRow;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Row: ") != string::npos) // finds for Alien Life:
        {
            line = line.substr(5);   // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedRow = n;
            }
        }
    }
    return savedRow;
}

int getSavedColumn(string loadFileName)
{
    int savedColumn;
    ifstream file;
    file.open(loadFileName);
    string line;
    while (getline(file, line))
    {
        if (line.find("Column: ") != string::npos) // finds for Alien Life:
        {
            line = line.substr(8);   // Remove the first 12 char and save to line
            istringstream iss(line); // It creates an object of the "istringstream" class, which is used to extract integers from the "line" string, one at a time. The ">>" operator is used to extract each integer and store it in the "n" variable.
            int n;
            while (iss >> n)
            {
                savedColumn = n;
            }
        }
    }
    return savedColumn;
}

void getSavedArray(string **arr, int row, int column, string loadFileName)
{

    ifstream file(loadFileName);
    int savedRow, savedColumn;
    file >> savedRow >> savedColumn;
    // if (savedRow != row || savedColumn != column)
    // {
    //     cout << "The size of the array in the file does not match the current size" << endl;
    //     return;
    // }
    // The values of savedRow and savedColumn are stored in the text file where the 2D array was saved.
    // The code file >> savedRow >> savedColumn; reads those values from the file and stores them in the variables savedRow and savedColumn in memory.
    // In this case, the text file is assumed to have the values for savedRow and savedColumn saved in the first line, separated by a space. So, this line of code is used to retrieve those values and store them in memory for further use.
    string line;
    for (int i = 0; i < row; i++)
    {
        getline(file, line);
        stringstream ss(line);

        for (int j = 0; j < column; j++)
        {
            ss >> arr[i][j];
        }
    }
    file.close();
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

void displayCharacter(Character::Alien &aliens, Character::Zombie &zombies, int &zombie) // Display the life, attack and range of alien and zombie.
{
    int zombiesNo;
    cout << "Alien    : Life ";
    displayAlienLife(aliens);
    cout << ", Attack ";
    displayAlienAttack(aliens);
    cout << endl;
    for (zombiesNo = 0; zombiesNo < zombie; ++zombiesNo)
    {
        cout << "Zombie " << zombiesNo + 1 << " : Life ";
        displayZombieLife(zombies, zombiesNo);
        cout << ", Attack ";
        displayZombieAttack(zombies, zombiesNo);
        cout << ", Range ";
        displayZombieRange(zombies, zombiesNo);
        cout << endl;
    }
    cout << endl;
}

void displayBoard(string **arr, int &row, int &column, int &zombie, int &rowStart, Character::Alien &aliens, Character::Zombie &zombies) // Display the game board.
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
    displayCharacter(aliens, zombies, zombie);
}

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

int **ZombiePosition(int &zombie)
{
    int **PositionZombie = new int *[zombie];
    for (int i = 0; i < zombie; i++)
    {
        PositionZombie[i] = new int[2];
    }
    return PositionZombie;
}

string randomObject() // Randomize object.
{
    string finalObject;
    string object[8] = {"^", "v", "<", ">", "h", "p", "r", " "};
    finalObject = object[rand() % 8];
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

void generateRandomTrail(string **arr, int &row, int &column, int &zombie, int &rowStart, Character::Alien aliens, Character::Zombie zombies) // Assign random objects to the trails after alien's turn.
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

string **generate2DArr(int &row, int &column) // Initialize 2D array.
{
    string **arr = new string *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new string[column];
    }
    return arr;
}

int randomLife() // Randomize zombie life.
{
    int finalLife;
    int life[4] = {100, 150, 200, 250};
    finalLife = life[rand() % 4];
    return finalLife;
}

int randomAttack() // Randomize zombie attack.
{
    int finalAttack;
    int attack[5] = {10, 15, 20, 25, 30};
    finalAttack = attack[rand() % 5];
    return finalAttack;
}

int randomRange(int &row, int &column)
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

void generateZombie(Character::Zombie &zombies, int &zombie, int &row, int &column, string **arr, int **PositionZombie) // Generate zombies with random life, attack and range.
{
    for (int i = 0; i < zombie; ++i)
    {
        zombies.setZombie(i);
        int zombieLife = randomLife();
        zombies.setLife(zombieLife);
        int zombieAttack = randomAttack();
        zombies.setAttack(zombieAttack);
        int zombieRange = randomRange(row, column);
        zombies.setRange(zombieRange);
    }
    assignZombie(row, column, zombie, arr, PositionZombie);
}

void help() // Show command list.
{
    cout << "1. up\t\t- Move Up" << endl;
    cout << "2. down\t\t- Move Down" << endl;
    cout << "3. left\t\t- Move Left " << endl;
    cout << "4. right\t- Move Right" << endl;
    cout << "5. arrow\t- Change the direction of an arrow using row and column" << endl;
    cout << "6. help\t\t- Display the user commands" << endl;
    cout << "7. save\t\t- Save the game " << endl;
    cout << "8. load\t\t- Load previous saved game" << endl;
    cout << "9. quit\t\t- exit the game" << endl;
    return;
}

void alienAttackZero(Character::Alien &aliens)
{
    aliens.clearAttack();
    aliens.setAttack(0);
}

string moveUp(int &x, int &y, string **arr, string &hit, Character::Zombie zombies) // Action for alien to move up.
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
    if (x - 1 >= 0 && move == true)
    {
        arr[x][y] = ".";
        x = x - 1;
        hit = arr[x][y];
        arr[x][y] = "A";
        return hit;
    }
    else
    {
        return hit;
    }
}

string moveDown(int &x, int &y, string **arr, string &hit, int &row, Character::Zombie zombies) // Action for alien to move down.
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
    if (x + 1 <= row - 1 && move == true)
    {
        arr[x][y] = ".";
        x = x + 1;
        hit = arr[x][y];
        arr[x][y] = "A";
        return hit;
    }
    else
    {
        return hit;
    }
}

string moveLeft(int &x, int &y, string **arr, string &hit, Character::Zombie zombies) // Action for alien to move up.
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
    if (y - 1 >= 0 && move == true)
    {
        arr[x][y] = ".";
        y = y - 1;
        hit = arr[x][y];
        arr[x][y] = "A";
        return hit;
    }
    else
    {
        return hit;
    }
}

string moveRight(int &x, int &y, string **arr, string &hit, int &column, Character::Zombie zombies) // Action for alien to move up.
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
    if (y + 1 <= column - 1 && move == true)
    {
        arr[x][y] = ".";
        y = y + 1;
        hit = arr[x][y];
        arr[x][y] = "A";
        return hit;
    }
    else
    {
        return hit;
    }
}

string continuousMove(string &hit, string &lastMove, int &x, int &y, string **arr, int &row, int &column, Character::Zombie zombies) // Identify what is the next hit.
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

string findClosestZombie(int &row, int &column, string **arr, int **PositionZombie, int zombie, Character::Zombie &zombies) // A calculater for finding the shortest distance between the alien and a zombie.
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
    if (zombies.accumulateZombieLife() == 0)
    {
    }
    vector<string> sameDistanceZombies;
    for (int i = 0; i < (row); ++i)
    {
        for (int j = 0; j < (column); ++j)
        {
            if (arr[i][j] != "A" && arr[i][j] != "^" && arr[i][j] != "v" && arr[i][j] != "<" && arr[i][j] != ">" && arr[i][j] != "h" && arr[i][j] != "p" && arr[i][j] != "r" && arr[i][j] != " " && arr[i][j] != ".")
            {
                int rowX = i;
                int colX = j;
                int manhattanDistance = abs(rowA - rowX) + abs(colA - colX);
                if (manhattanDistance < shortestDistance)
                {
                    shortestDistance = manhattanDistance;
                    shortestPoint = arr[i][j];
                    sameDistanceZombies.clear();
                    sameDistanceZombies.push_back(arr[i][j]);
                }
                else if (manhattanDistance == shortestDistance)
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

void alienAttackIncrease(Character::Alien &aliens)
{
    int sum;
    aliens.setAttack(20);
    sum = aliens.accumulateAttack();
    aliens.clearAttack();
    aliens.setAttack(sum);
}

void alienAttack(Character::Zombie &zombies, Character::Alien &aliens, string &hitZombie, int **PositionZombie, string **arr, int &x, int &y, string &lastMove, int &row, int &column, string &hit, int &zombie)
{
    int zombieNo = stoi(hitZombie);
    int attack = aliens.getAttack(0);
    cout << "Zombie " << zombieNo << " recieved " << attack << "." << endl;
    if (attack >= zombies.getLife(zombieNo - 1))
    {
        zombies.eraseLife(zombieNo - 1);
        zombies.insertLife(0, zombieNo - 1);
        arr[PositionZombie[zombieNo - 1][0]][PositionZombie[zombieNo - 1][1]] = " "; // Replace the zombie's position with alien
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

void hitObject(string &hit, Character::Alien &aliens, Character::Zombie &zombies, string &lastMove, int &row, int &column, string **arr, int &x, int &y, int **PositionZombie, int &zombie) // Display different outputs based on what it hits.
{
    string hitZombie;
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
    }
    else if (hit == "v")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = "v";
    }
    else if (hit == "<")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = "<";
    }
    else if (hit == ">")
    {
        cout << "Alien finds a arrow." << endl;
        cout << "Alien's attack is increased by 20." << endl;
        alienAttackIncrease(aliens);
        cout << endl;
        lastMove = ">";
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
    }
    else if (hit == "p")
    {
        cout << "Alien found a pod!" << endl;
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
            cout << endl;
        }
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
        else if (lastMove == "v")
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
    }
    else if (hit == " ")
    {
        cout << "Alien finds an empty space." << endl;
        cout << endl;
    }
    else if (hit == ".")
    {
        cout << "Alien finds an empty space." << endl;
        cout << endl;
    }
    else if (hit == hitZombie)
    {
        cout << endl;
        alienAttack(zombies, aliens, hitZombie, PositionZombie, arr, x, y, lastMove, row, column, hit, zombie);
    }
}

void zombieAttack(Character::Zombie &zombies, Character::Alien &aliens, int **PositionZombie, int i, string **arr, int &row, int &column) // Zombie detect and attack alien if nearby.
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
    cout << endl;
}

void zombieMove(Character::Zombie &zombies, Character::Alien &aliens, int &row, int &column, string **arr, int **PositionZombie, int &rowStart, int &zombie) // Action for zombie to move.
{
    alienAttackZero(aliens);
    rowStart = 0;
    system("cls");
    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
    for (int i = 0; i < zombie; i++)
    {
        if (zombies.getLife(i) == 0)
        {
            arr[PositionZombie[i][0]][PositionZombie[i][1]] = " ";
            continue;
        }
        string direction[4] = {"left", "right", "up", "down"};
        string move = direction[rand() % 4];
        bool hitZombie = false;
        rowStart = 0;
        cout << "Zombie " << i + 1 << "'s turn." << endl;
        if (move == "up")
        { // Movement depend on direcction move.
            cout << "Zombie " << i + 1 << " moves up." << endl;
            if (PositionZombie[i][0] > 0 && arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] != "A" && arr[PositionZombie[i][0] - 1][PositionZombie[i][1]] != "r") // Prevent hit the border, the alien and the rock.
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
            if (PositionZombie[i][0] < row - 1 && arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] != "A" && arr[PositionZombie[i][0] + 1][PositionZombie[i][1]] != "r")
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
            if (PositionZombie[i][1] > 0 && arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] != "A" && arr[PositionZombie[i][0]][PositionZombie[i][1] - 1] != "r")
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
            if (PositionZombie[i][1] < column - 1 && arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] != "A" && arr[PositionZombie[i][0]][PositionZombie[i][1] + 1] != "r")
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
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
        zombieAttack(zombies, aliens, PositionZombie, i, arr, row, column);
        system("PAUSE");
        system("CLS");
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
    }
}

string commandUser(string &command) // Allow user to input command.
{
    cout << "command > ";
    cin >> command;
    cout << endl;
    return command;
}

void changeArrow(string **arr, int row, int column) // Allow user to change the direction of selected arrow.
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

int main()
{
    Character::Alien aliens;
    Character::Zombie zombies;
    srand(time(NULL));
    int row = 5;    // Default setting for row.
    int column = 9; // Default setting for column.
    int zombie = 1; // Default setting for zombie.
    int rowStart;
    bool exit = false;
    bool generate = true;
    setting(row, column, zombie);
    int **PositionZombie = ZombiePosition(zombie); // Initialize an array to store the position of zombie.
    string **arr = generate2DArr(row, column);     // Initialize an array for the board.
    int x = (row - 1) / 2;                         // Find the center in the row.
    int y = (column - 1) / 2;                      // Find the center in the column.
    while (generate != false)
    {
        generateRandom(arr, row, column);
        string alien = "A";
        arr[x][y] = alien;
        generate = false;
    }
    generateZombie(zombies, zombie, row, column, arr, PositionZombie);
    string command;
    while (exit != true)
    {
        system("CLS");
        displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
        commandUser(command);
        string lastMove;
        string hit;
        if (command == "quit")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            exit = true;
            break;
        }
        else if (command == "up" || command == "down" || command == "left" || command == "right")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool alienHitRock = false;
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
            hitObject(hit, aliens, zombies, lastMove, row, column, arr, x, y, PositionZombie, zombie);
            if (hit == "r")
            {
                alienHitRock = true;
            }
            system("PAUSE");
            while (alienHitRock != true)
            {
                if ((x == 0 && lastMove == "^") || (x == (row - 1) && lastMove == "v") || (y == 0 && lastMove == "<") || (y == (column - 1) && lastMove == ">") || (lastMove <= to_string(zombies.sizeZombie())) || (zombies.accumulateZombieLife() == 0))
                {
                    break;
                }
                else
                {
                    system("CLS");
                    displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);
                    hit = continuousMove(hit, lastMove, x, y, arr, row, column, zombies);
                    hitObject(hit, aliens, zombies, lastMove, row, column, arr, x, y, PositionZombie, zombie);
                    if (hit == "r")
                    {
                        alienHitRock = true;
                    }
                    system("PAUSE");
                }
            }
            system("CLS");
            displayBoard(arr, row, column, zombie, rowStart, aliens, zombies);

            if (zombies.accumulateZombieLife() == 0 || aliens.getLife(0) == 0)
            {
                while (true)
                {
                    cout << "Do you want to restart the game ?(y/n) :";
                    string restart;
                    cin >> restart;
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
            else
            {
                generateRandomTrail(arr, row, column, zombie, rowStart, aliens, zombies);
                system("PAUSE");
                zombieMove(zombies, aliens, row, column, arr, PositionZombie, rowStart, zombie);
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
        else if (command == "save")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string saveFileName;
            cout << "Enter the file name to save the current game (.txt): ";
            cin >> saveFileName;
            save(aliens, zombies, column, row, arr, saveFileName);
            cout << "Game saved!" << endl;
            system("PAUSE");
        }
        else if (command == "load")
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            system("PAUSE");
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