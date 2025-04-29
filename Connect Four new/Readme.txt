Connect 4 Game
Overview
This project is a desktop implementation of the classic Connect 4 game. It features interactive gameplay, music, and bot functionality, built using C++ and supporting dynamic UI elements. The game can be played between two players or against a bot, with smooth rendering and customizable settings.

Features
Interactive Gameplay: Classic Connect 4 rules applied.
Bot Support: Play against an AI bot.
Dynamic UI: Buttons, animations, and user-friendly interface.
Customizable Assets: Fonts, background, and music can be easily changed.
Debug and Release Modes: Optimized builds for both development and production.
Folder Structure

Copy code
Connect4/
├── bin/                            # Compiled binaries and runtime files
│   ├── debug/                      # Debug builds
│   └── release/                    # Release builds
├── files/                          # Game assets (fonts, images, audio)
├── obj/                            # Object files for builds
├── src/                            # Source code
├── connect4.cbp                    # Code::Blocks project file
├── connect4.depend                 # Dependency file
└── README.md                       # Project overview and instructions
Installation
Clone the Repository

bash
Copy code
git clone <repository-url>
cd Connect4
Set Up Development Environment

Install Code::Blocks or your preferred C++ IDE.
Ensure a C++ compiler (e.g., GCC) is installed.
Build the Project

Open connect4.cbp in Code::Blocks.
Build and run the project in Debug or Release mode.
Gameplay
Objective: Connect four discs of your color (red or yellow) in a line (horizontal, vertical, or diagonal) before your opponent.
Controls:
Use the arrow keys to navigate:
Left/Right Arrows: Move the piece horizontally across the columns.
Down Arrow: Drop the piece into the column below.
Alternatively, you can use the mouse to hover over a column and drop a piece by pressing Enter or clicking the mouse button.
Pause/Resume: Click the pause button in the top-left corner during gameplay.
Asset Details
Fonts:
arial.ttf and KnightWarrior.otf are used for text rendering.
Audio:
music.ogg: Background music.
naruto.ogg: Optional alternate background track.
Icons and Images:
logo.ico: Application icon.
background.png and button.png: Visual assets for the UI.
