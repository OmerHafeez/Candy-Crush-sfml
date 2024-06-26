# Candy-Crush-sfml

Menagerie is a fun C++ match-3 game inspired by classic puzzle games or candy crush game. Help the animals find their friends in this adorable game!

Requirements:
Ubuntu System (any recent version should work)
SFML 2.5 or later:
SFML is a simple and fast multimedia library for games. You can install it using the following command in your terminal:
sudo apt install libsfml-dev
C++ compiler that supports C++11:
Ubuntu comes with a C++ compiler by default (usually g++). This compiler should support C++11.

How to Play:
Download the source code for Menagerie. (This will depend on where you find the game files)
Compile the code: Open a terminal and navigate to the directory containing the downloaded source code (usually Menagerie.cpp and other files). Use the following command to compile the game:
g++ -o Menagerie Menagerie.cpp -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
This command tells the g++ compiler to create an executable named "Menagerie" by compiling the source code in "Menagerie.cpp" and linking the necessary SFML libraries.
Run the game: Once compiled, you can run the game by typing the following command in your terminal:
./Menagerie

Gameplay:
The gameplay follows the classic match-3 mechanics:
A grid of animal tiles appears.
Click a tile to select it.
Click on an adjacent tile to swap them.
Create lines of three or more matching animals (horizontally or vertically) to make them disappear and score points.
New tiles will fall from the top to fill the empty spaces.
The game has two levels (Level 1 and Level 2) accessible from the main menu using the number keys (1 for Level 1, 2 for Level 2).
Level 2 introduces a timer element where you lose if the time runs out before clearing all tiles.

Menu System:
The game starts with a title screen. Press Enter to proceed to the main menu.
The main menu offers options for:
Level selection (Number keys 1 and 2)
Help (Number key 3) - Briefly explains the gameplay.
High Scores (Number key 4) - Not yet implemented.
Exit (Escape key)

Additional Notes:
This is a work in progress, so some features might not be fully functional.
The code includes comments to help understand the logic.
For reference, the game likely uses the following resources included in the source code folder (check the specific folder names):
Font: Calibri.ttf
Music: InGameSong.wav
Animal Images: animals.png
Background Images: Background.png (used in both levels) and YouWin.png/YouLoseLVL2.png (for win/lose screens)
Feel free to modify the code to add your own features or customize the game!
