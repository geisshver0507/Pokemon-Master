//OOP Assignment 3: Pokemon Game
//Name: GEISSHVER REEDYY SANTHIRA SEKARAN
//Student ID: 2024149042

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Skill {
	string name;//skill name
	string type;//skill type
	int damage;//skill's damage
	int maxTry;//skill's maximum number of attempt
	int balTry;//skill's balance number of attempts

	
	
	// Default constructor
    	Skill() : name(""), type(""), damage(0), maxTry(0), balTry(0) {}
	
	//Constructor to initialize all the attributes.
	// balTry is set to the maximum number of attempt when initializing a skill
	Skill(string skillName, string skillType, int skillDamage, int skillmaxTry):
	name(skillName), type(skillType), damage(skillDamage), maxTry(skillmaxTry), balTry(skillmaxTry){}
	
};

class Pokemon {
	public:
		string name;
		string type;
		int maxHP;
		int currHP;
		Skill skills[4];
		string latestSkill = "-";
		string effectText = "";
		
		//default constructor
		Pokemon() : name(""), type(""), maxHP(0), currHP(0) {}
		
		Pokemon(string pokeName, string pokeType, int pokemaxHP, Skill pokeskill[4])
		: name(pokeName), type(pokeType), maxHP(pokemaxHP), currHP(pokemaxHP) {
		for (int i = 0; i < 4; i++)
		{
			skills[i] = pokeskill[i];
		}
		}
		
		void HealthUpdater(int damage){
			if (currHP > 0):{
				currHP -= damage;}
			if (currHP < 0 ):
			{
				currHP = 0;
			}
			
		}
		void SkillCount (int skillIndex){
			if (skills[skillIndex].balTry > 0)
			{
				skills[skillIndex].balTry--;
				latestSkill = skills[skillIndex].name;
			}
		}
		int getbalTry(int skillIndex)
		{
			return skills[skillIndex].balTry;
		}
};

void SkillInitializer(Skill palkiaSkills[], Skill charmanderSkills[], Skill eeveeSkills[], Skill dratiniSkills[], Skill pikachuSkills[]);

int DamageEffect( string attackType, string defenderPoke);

Pokemon pokemondetector(int playerchoice, Skill palkiaSkills[], Skill charmanderSkills[], Skill eeveeSkills[], Skill dratiniSkills[], Skill pikachuSkills[]);

string effectMessage(int effect);
void battle(Pokemon& attacker, Pokemon& defender, int skillIndex);

//battle page printing functions
void x_separator();
void header();
void DisplayPoke(const Pokemon& Poke1, const Pokemon& Poke2, int turn);
void recentSkill(const Pokemon& Poke1, const Pokemon& Poke2);
void skillInfo (const Pokemon& Poke1, const Pokemon& Poke2);
void displayBattlePage(const Pokemon& Poke1, const Pokemon& Poke2, int turn);

int main() {

	Skill pikachuSkills[4];
	Skill charmanderSkills[4];
	Skill eeveeSkills[4];
	Skill dratiniSkills[4];
	Skill palkiaSkills[4];
	
	SkillInitializer(palkiaSkills, charmanderSkills, eeveeSkills, dratiniSkills, pikachuSkills);
	
	int Player1, Player2;
	// turn = 1 -> Pokemon1 Attack
	// turn = 2 -> Pokemon2 Attack
	int turn = 1;//
	int skillno;
	
	
	//Pokemon choosing
	cout<<"Choose a Pokemon(0~4): ";
	cin>>Player1;
	cout<<"Choose a Pokemon(0~4): ";
	cin>>Player2;
	
	if (Player1 == Player2)
	{
		cout<<"You have to choose Pokemons different from each other."<<endl;
		exit(0);
	}
	Pokemon Poke1 = pokemondetector(Player1, palkiaSkills, charmanderSkills, eeveeSkills, dratiniSkills, pikachuSkills);
	Pokemon Poke2 = pokemondetector(Player2, palkiaSkills, charmanderSkills, eeveeSkills, dratiniSkills, pikachuSkills);
	//print initial battle page
	//
	while(Poke1.currHP > 0 and Poke2.currHP > 0)
	{	
		cout<<"Choose a skill (0~3): ";
		cin>>skillno;
		
		if (turn == 1)//poke1 attack and poke2 defends
		{
			turn = 2;
			if (Poke1.getbalTry(skillno) > 0)
			{
			
				battle(Poke1, Poke2, skillno);
				if (Poke1.currHP > 0 and Poke2.currHP > 0)
				{
				
					//print battle page
				}
				else
				{
					break;
				}
			}
			else
			{
				cout << Poke1.name << " failed to perform " << Poke1.skills[skillno].name<<"."<<endl;
			}
		}
		else if(turn == 2)//poke2 attack and poke1 defends
		{
			turn = 1;
			if (Poke2.getbalTry(skillno) > 0)
			{
				battle(Poke2, Poke1, skillno);
				if (Poke1.currHP > 0 and Poke2.currHP > 0)
				{
				
					//print battle page
				}
				else
				{
					break;
				}
			}
			}
			else
			{
				cout << Poke2.name << " failed to perform " << Poke2.skills[skillno].name<<"."<< endl;
			}
		}
		
		
		
		cout<<""<<endl;
		cout<<"==============================================================="<<endl;
		if (turn == 1)
		{
			cout<<"Match Result: "<< Poke1.name << " defeats " << Poke2.name<<endl;
		}
		else
		{
			cout<<"Match Result: "<< Poke2.name << " defeats " << Poke1.name<<endl;
		}
	
	
	return 0;
}

void SkillInitializer(Skill palkiaSkills[], Skill charmanderSkills[], Skill eeveeSkills[], Skill dratiniSkills[], Skill pikachuSkills[])
{
	//Initializing Pikachu's skills
	pikachuSkills[0] = Skill("Tackle","Normal",4,5);
	pikachuSkills[1] = Skill("Grass Knot","Grass",8,5);
	pikachuSkills[2] = Skill("Thunderbolt","Electric",10,5);
	pikachuSkills[3] = Skill("Megabolt","Electric",15,3);
	
	//Initializing Dratini's skills
	
	dratiniSkills[0] = Skill("Wrap", "Normal", 4, 10);
    	dratiniSkills[1] = Skill("Aqua Tail", "Water", 3, 5);
    	dratiniSkills[2] = Skill("Water Pulse", "Water", 13, 2);
    	dratiniSkills[3] = Skill("Hyper Beam", "Normal", 20, 1);

	//Initializing Eevee's skills
	
	eeveeSkills[0] = pikachuSkills[0];//struct allows shallow copying
    	eeveeSkills[1] = Skill("Sand Attack", "Ground", 8, 3);
    	eeveeSkills[2] = Skill("Bite", "Normal", 12, 3);
    	eeveeSkills[3] = Skill("Rain Dance", "Water", 15, 1);
    	
	//Initializing Charmander's Skills
	charmanderSkills[0] = pikachuSkills[0];//struct allows shallow copying
	charmanderSkills[1] = Skill("Flamethrower", "Fire", 11, 5);
    	charmanderSkills[2] = Skill("Dig", "Ground", 7, 5);
    	charmanderSkills[3] = Skill("Heat Wave", "Fire", 14, 5);
    	
    	//Initializing Palkia's Skills
    	
    	palkiaSkills[0] = Skill("Hydro Pump", "Water", 12, 10);
    	palkiaSkills[1] = Skill("Earth Power", "Ground", 15, 10);
    	palkiaSkills[2] = Skill("Surf", "Water", 13, 10);
    	palkiaSkills[3] = Skill("Spatial Rend", "Normal", 30, 10);

}
	
	
int DamageEffect( string attackType, string defenderPoke)
{
	//0 = effective, 1 = super effective, -1 = not very effective
	//ROW = Attack Skill Type
	// Column = Defender Pokemon Type
	//			N , Gr, E , W , Gs , F
	static const int dmgEffect[6][6] = {{0 , 0 , 0 , 0 , 0  , 0},//Normal
			       {0 , 0 , 1 , 0 ,-1  , 1},//Ground
			       {0 ,-1 ,-1 , 1 ,-1  , 0},//Electric
			       {0 , 1 , 0 ,-1 ,-1  , 1},//Water
			       {0 ,-1 , 0 , 1 ,-1  ,-1},//Grass
			       {0 , 0 , 0 ,-1 , 1  ,-1}};//Fire 
			       
	int attackval, defenderval, effect;
	//map skill type to dmgEffect's row number
	if (attackType == "Normal")
	{
		attackval = 0;
	}
	else if (attackType == "Ground")
	{
		attackval = 1;
	}
	else if (attackType == "Electric")
	{
		attackval = 2;
	}
	else if (attackType == "Water")
	{
		attackval = 3;
	}
	else if (attackType == "Grass")
	{
		attackval = 4;
	}
	else if (attackType == "Fire")
	{
		attackval = 5;
	}
	
	//map defender pokemon type to dmgEffect's column number
	if (defenderPoke == "Normal")
	{
		defenderval = 0;
	}
	else if (defenderPoke == "Ground")
	{
		defenderval = 1;
	}
	else if (defenderPoke == "Electric")
	{
		defenderval = 2;
	}
	else if (defenderPoke == "Water")
	{
		defenderval = 3;
	}
	else if (defenderPoke == "Grass")
	{
		defenderval = 4;
	}
	else if (defenderPoke == "Fire")
	{
		defenderval = 5;
	}
	
	return dmgEffect[attackval][defenderval];
	
}

Pokemon pokemondetector(int playerchoice, Skill palkiaSkills[], Skill charmanderSkills[], Skill eeveeSkills[], Skill dratiniSkills[], Skill pikachuSkills[])
{
	switch(playerchoice) {
		//Player = Pikachu
		case 0:{
			return Pokemon("Pikachu", "Electric", 35, pikachuSkills);}
		//Player = Dratini
		case 1:{
			return Pokemon("Dratini", "Water", 41, dratiniSkills);}
		//Player == Eevee
		case 2:{
			return Pokemon("Eevee", "Normal", 55, eeveeSkills);}
		//Player == Charmander
		case 3:{
			return Pokemon("Charmander", "Fire", 39, charmanderSkills);}
		//Player == Palkia
		case 4:{
			return Pokemon("Palkia", "Water", 90, palkiaSkills);}
		default:{
			return Pokemon();}
		}
		
}
string effectMessage(int effect)
{
	switch (effect){
		case -1:
			return "It was not very effective.";
		case 0:
			return "It was effective.";
		case 1:
			return "It was super effective.";
		default:
			return "It was effective.";
		}
}

void battle(Pokemon& attacker, Pokemon& defender, int skillIndex)
{
	int damage = attacker.skills[skillIndex].damage;
	int damage_power = DamageEffect(attacker.skills[skillIndex].type, defender.type);
	
	if (damage_power == -1 )//attack not effective
	{
		damage-=3;
	}
	else if(damage_power == 1)//attack very effective
	{
		damage+=5;
	}
	attacker.SkillCount(skillIndex);
	defender.HealthUpdater(damage);
	cout<<attacker.name<< " used " << attacker.skills[skillIndex].name;
	attacker.effectText = effectMessage(damage_power);
	cout<<attacker.effectText<<endl;
	
}
void x_separator()
{
	cout<<"+";
	cout<< string(61, "-");
	cout<<"+"<< endl;
}

//length of row line is 63 characters
void header()
{
	x_separator();
	cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
	x_separator();
}
void DisplayPoke(const Pokemon& Poke1, const Pokemon& Poke2, int turn)
{
	//printing Pokemon name
	if (turn == 1)
	{
		cout << "| " << Poke1.name << " (*)";
		cout << string(25-Poke1.name.size(), " ") << "| ";
		cout << Poke2.name << string(29-Poke1.name.size(), " ") << "|"<<endl;
	}
	else
	{
		cout << "| " << Poke1.name;
		cout << string(29-Poke1.name.size(), " ") << "| ";
		cout << Poke2.name << string(25-Poke1.name.size(), " ") << "|"<<endl;
	}
	
	//printing Pokemon Type
	
	cout << "| Type: " << Poke1.type << string(23 - Poke1.type.size(), " ");
	cout << "| Type: " << Poke1.type << string(23 - Poke2.type.size(), " ") << "|" << endl;
	
	//printing Pokemon's current HP
	
	cout << "| HP: " << Poke1.currHP << string(25 - to_string(Poke1.currHP).size(), " ");
	cout << "| HP: " << Poke2.currHP << string(25 - to_string(Poke2.currHP).size(), " ") << "|" << endl;
	
	x_separator();
}

void recentSkill( const Pokemon& Poke1, const Pokemon& Poke2 )
{
	//printing latest skills
	cout << "| Latest Skill: " << Poke1.latestSkill << string(15 - Poke1.latestSkill.size(), " ");
	cout << "| Latest Skill: " << Poke2.latestSkill << string(15 - Poke2.latestSkill.size(), " ") << "|" << endl;
	
	//printing damage effect
	cout << "! " << Poke1.effectText << string(29 - Poke1.effectText, " ");
	cout << "! " << Poke2.effectText << string(29 - Poke2.effectText, " ") << "|" << endl;
	
	x_separator();
}
void skillInfo (const Pokemon& Poke1, const Pokemon& Poke2)
{
	
	for (int i = 0; i < 4; i++){
		cout << "| (" << i << ") " << Poke1.skills[i].name
             	<< string(25 - Poke1.skills[i].name.size(), ' ') << "| (" << i << ") "
             	<< Poke2.skills[i].name
             	<< string(25 - Poke2.skills[i].name.size() - to_string(i).size(), ' ') << "|" << endl;

        	cout << "|     - Type: " << Poke1.skills[i].type
             	<< string(17 - Poke1.skills[i].type.size(), ' ') << "|     - Type: " << Poke2.skills[i].type
             	<< string(17 - Poke2.skills[i].type.size(), ' ') << "|" << endl;

        	cout << "|     - Damage: " << Poke1.skills[i].damage
             	<< string(15 - to_string(Poke1.skills[i].damage).size(), ' ') << "|     - Damage: " << Poke2.skills[i].damage
             	<< string(15 - to_string(Poke2.skills[i].damage).size(), ' ') << "|" << endl;

        	cout << "|     - Count: " << Poke1.skills[i].balTry << "(" << Poke1.skills[i].maxTry << ")"
             	<< string(12, ' ')
             	<< "|     - Count: " << Poke2.skills[i].balTry << "(" << Poke2.skills[i].maxTry << ")"
             	<< string(12, ' ')
             	<< "|" << endl;
    }
    x_separator();


		
	
	
	
