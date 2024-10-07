# Warzone

## Project Overview
This project involves the development of a  version of the popular Risk board game using C++, focusing on advanced program design with C++. The game is based on the "Warzone" variant of Risk, and the project is divided into multiple parts

## Game Objective
The goal of the game is for players to conquer all territories on the map. Players compete by placing armies, attacking neighboring territories, and using special cards to gain strategic advantages.

## Game Map
The map consists of a connected graph where:
- Nodes represent territories.
- Edges represent adjacency between territories.
- The map is divided into continents, each providing bonuses if controlled entirely by a player.

## Phases of the Game
1. **Startup Phase**: Players are assigned territories randomly.
2. **Main Play Phase**: A turn-based system where players issue orders, such as deploying or advancing armies, or using special orders from cards.

## Orders and Actions
- **Deploy**: Place armies on a controlled territory.
- **Advance**: Move armies to an adjacent territory (can result in an attack if the target belongs to another player).
- **Special Orders**:
  - Bomb: Halve the armies on an opponent’s territory.
  - Blockade: Triple the number of armies on a controlled territory and convert it into a neutral territory.
  - Airlift: Move armies between any two territories.
  - Negotiate: Prevents attacks between two players for a turn.

## Battle Simulation
- **Attack**: The attacking and defending armies have respective probabilities to eliminate each other. If the defender loses all armies, the attacker takes control of the territory.
- **Card System**: Players earn cards when they conquer territories. Cards can be used to execute special actions, like bombing a territory or moving armies.

## Winning Condition
A player wins by conquering all territories on the map. If a player loses all their territories, they are removed from the game.

## Dependencies
- C++ standard libraries.
- Graph data structures to represent the map.

## How to Build and Run
1. Clone the repository: `git clone <repo-link>`
2. Navigate to the project directory: `cd RiskGame`
3. Compile the project: `make`
4. Run the game: `./risk_game`

## Contributions
This project was developed in teams, with each assignment building on the previous one. The structure was modular, making it easier to implement and test individual components.


## References
- Warzone: https://www.warzone.com/
- Domination Game Maps: http://domination.sourceforge.net/getmaps.shtml
