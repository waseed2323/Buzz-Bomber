# Buzz-Bomber

This project is a C++ SFML-based game where the player takes on the role of a defender, protecting their garden from swarming bees and dangerous red bees while managing limited spray cans. The goal is to eliminate bees, collect honeycombs, and avoid running out of ammo or getting blocked by flowers. The game progresses through multiple levels, and a high-score leaderboard tracks top players.

Features Implemented
Phase 1: Core Gameplay
Bees & Honeycombs:

Bees move horizontally and drop honeycombs when shot.
Regular bees are worth 100 points, and red bees give more points based on their tier.
Hummingbird Assistance:

The hummingbird helps collect honeycombs (regular and red).
A scoring system rewards the player based on the tier at which the honeycomb is eaten.
Beehives:

When a bee gets stuck, it builds a beehive at the stuck location.
Beehives are worth points when the level ends but can be destroyed by spraying.
Flowers as Obstacles:

Flowers grow randomly at the bottom of the screen when bees reach the ground.
If flowers block the spray can, it gets automatically pushed left or right to the nearest free space.
Spray Cans:

The player has three spray cans, each with 56 bullets.
Used spray cans are displayed at the bottom-left corner, and the bullet count is dynamically updated.

Level Transitions:

The game has three levels, with progressively increasing difficulty.
After completing a level (all bees killed and honeycombs collected), a transition screen displays "Moving to the Next Level."
Backgrounds & Visual Elements:

Background images are added to the main menu and levels, scaled manually for the entire screen.
Visual adjustments include reducing the size of spray can sprites and showing their positions and bullet counts.
Audio Effects:

Added background music to levels and menu.
Specific sound effects play during interactions, such as bees being shot or transitions between levels.
Key Constraints
SFML-Allowed Data Types and Commands:

Limited to using sf::RenderWindow, sf::VideoMode, sf::Sprite, sf::Text, sf::Event, and other core SFML elements.
Restricted from using advanced libraries like cstring, cmath, or functions like getSize or getPosition.
Dynamic Memory Usage:

Implemented dynamic memory using pointers for storing player names instead of the string library.
Data structures like arrays are used for managing bees, honeycombs, and flowers.
Gameplay Logic:

All logic, including collisions, scoring, and level completion, was implemented within existing functions.
Avoided creating unnecessary structs or complex classes.
How to Play
Controls:

Use the spacebar to fire bullets.
The spray can moves automatically if blocked by flowers.
Objective:

Eliminate all bees and collect honeycombs to progress through levels.
Avoid getting blocked by flowers or running out of spray cans.
Winning the Game
