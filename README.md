# Pokemon Master Kiung

##Overview
This is a console-based Pokemon battle simulation game developed as part of an Object-Oriented Programming assignment 
at Yonsei University. The game allows players to choose from five distinct Pokemon and engage in turn-based battles
with unique skills and type-based damage mechanics.

### The Pokémon Roster
#### Choose Your Pokemon:
1. **Pikachu** (Type: Electric, Max HP: 35)
   - Tackle, Grass Knot, Thunderbolt, Megabolt
2. **Dratini** (Type: Water, Max HP: 41)
   - Wrap, Aqua Tail, Water Pulse, Hyper Beam
3. **Eevee** (Type: Normal, Max HP: 55)
   - Tackle, Sand Attack, Bite, Rain Dance
4. **Charmander** (Type: Fire, Max HP: 39)
   - Tackle, Flamethrower, Dig, Heat Wave
5. **Palkia** (Type: Water, Max HP: 90)
   - Hydro Pump, Earth Power, Surf, Spatial Rend


### Type Effectiveness System
	 Each skill type has different effectiveness against Pokemon types
	Damage adjustment:
		1. Super Effective: +5 damage
		2. Not Very Effective: -3 damage
		3. Neutral: Standard damage



### How It Works
#### Gameplay Overview:
1. **Select Pokémon:**
   - Players pick two unique Pokémon to face off in battle.
   - Duplicate selections trigger an error and terminate the game.

2. **Prepare for Combat:**
   - Display a detailed battle page with each Pokémon’s stats.
   - Skill effectiveness is calculated dynamically.

3. **Turn-Based Action:**
   - Pokemons take turns to attack.
   - Skills have varying effectiveness based on type matchups (e.g., super effective, not very effective).

4. **Skill Management:**
   - Each skill has a limited number of uses.
   - Attempts to use an exhausted skill will fail and skip the turn.

5. **Winning the Battle:**
   - The battle concludes when one Pokémon’s HP reaches zero.
   - A detailed result announces the victor.

### Compilation
 Use the provided `run.sh` script to compile and run the program:
   ```bash
   ./run.sh
   ```

### How to play the Game:
1. Follow the prompt and select 2 different Pokemons
2. Select skills (0-3) to attack.
3. Battle continues until one Pokemon's HP reaches 0

ENJOY THE GAME!!!!


# Pokemon-Master
## Geisshver Reedyy Santhira Sekaran Student ID: 2024149042
