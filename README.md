# Slide Puzzle
This is a playable slide puzzle. The goal is to get the tiles in chronological number order. There is an option to 
play with a 3x3, 4x4, and 5x5 board and in easy or hard mode. Hard mode is when the empty tile has to be in the bottom 
right corner to win. Easy mode is when the tiles have to be in order but the empty tile doesn't have to be in the bottom
right corner.
![image](https://user-images.githubusercontent.com/73136277/117036605-34da6a80-accb-11eb-902e-ba395d90ff1b.png)

## Dependencies
* Visual Studio 2015
* CMake
* Cinder
* Clion

To run this project, install it locally by cloning it into CLion


## Controls
| Key  | Action |
| ------------- | ------------- |
| mouse click | Selects Tile |
| left arrow  | Moves Tile Left  |
| right arrow  | Moves Tile Right |
| up arrow  | Moves Tile Up  |
| down arrow  | Moves Tile Down |
| h  | 3x3 Hard mode  |
| e  | 3x3 Easy Mode  |
| d  | 4x4 Hard Mode |
| p  | 4x4 Easy Mode  |
| g  | 5x5 Hard Mode  |
| y  | 5x5 Easy Mode  |
| t  | Hard Mode with an easily solvable board to show end screen  |
| r  | Easy Mode with an easily solvable board to show end screen  |
| s  | Start Game  |
| q | Replay/Takes you back to the menu  |

In the menu, select a mode by clicking the respective key. If no mode is selected, the default mode is a 3x3 board in 
easy mode. After selecting mode, click s to start the game. Once in the game, select a tile by clicking it, then use the
arrow keys to slide it. A tile can only be slid into a spot with the emtpy tile. A tile cannot be slid into another tile
or the wall. Solve the puzzle by getting all the numbers in order. Once the puzzle is solved a "You Win" screen will pop
up and the option to play again will be presented by pressing q.

The menu
![image](https://user-images.githubusercontent.com/73136277/117036419-09578000-accb-11eb-8dbe-917e697bb51e.png)

A 4x4 board
![image](https://user-images.githubusercontent.com/73136277/117036695-550a2980-accb-11eb-9d01-dc66680b68f7.png)

A board mid game. The current tile that was clicked is outlined in pink. If in easy mode, if 5 were slid up, the user
would win. If in hard mode, the user would have to slide 5 up and 8 to the left to win. 
![image](https://user-images.githubusercontent.com/73136277/117036906-884cb880-accb-11eb-9635-3e87c29e6892.png)
