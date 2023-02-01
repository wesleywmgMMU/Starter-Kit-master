# Part 1

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtu.be/N-zW7AZEOGs).

## Minimum Requirements

### Completed

List all the features completed.

1. Overview of Alien vs. Zombie
2. Game Board
3. Game Characters
4. Attributes
5. Movement and Attack
6. Multiple Zombies
7. Game Objects
8. Game Controls
9. Game Flow

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Load Feature


## Additional Features

Describe the additional features that has been implemented.

## Contributions

List down the contribution of each group members.

For example:

### Wesley Wong Min Guan

1. Row, column, and zombie count customization
2. Default setting page
3. Display game board and status of alien and zombies
4. Alien Movement
5. Alien action based on what it hit
6. Generate random object on trail after the end of alien's turn
7. Assign alien's and zombies' position in game board
8. Assign random object in game board
9. User command


### Tang Yu Xuan

1. Zombies and aliens classes (private and public) and implementation
2. Save feature
3. Minor bug/changes on Alien behaviour
4. Alien's attack become zero after when it ends it turns
5. Alien movement and attack zombies
6. End of the game (Alien life bocome 0 or all zombies are defeated)
7. Range of zombies will not exceed size of game board
8. Generate ramdom object after alien hits the rock
9. User can change the arrow's direction

### Koh Jia Jie

1. Alien movement and attack zombies
2. Zombie movement and attack behaviour
3. Minor bug/changes on Alien and zombies behaviour
4. End of the game (Alien life become 0 or all zombies are defeated)
5. Range of zombies will not exceed size of game board
6. Store the zombies' position
8. Alien and zombies will stop if they hit another zombie, meanwhile alien will attack zombie
9. Zombie will be removed from the game board once its life bocome 0 and skip its turn

## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.
1. Cannot update the alienLife after attacked by zombie.
  Solution: We declare an object in the main function instead of other fucntions.

2. Even though the dimension of board is very high, still possible to get Zombie attack range of 1. 
  Solution: With the row and column, we save the lower value and the range of zombies will in between (lower value + 1 / 2) and (lower value / 3).

3. We don't know how to generate an 2d array with custom row and column .
Solution: we use a dynamic allocation of memory using the new operator. The 2D array is represented as an array of pointers to arrays, where each element of the first array points to a separate 1D array, effectively creating a 2D array. The function returns a pointer to the 2D array.
