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
		
		//default constructor
		Pokemon() : name(""), type(""), maxHP(0), currHP(0) {}
		
		Pokemon(string pokeName, string pokeType, int pokemaxHP, Skill pokeskill[4])
		: name(pokeName), type(pokeType), maxHP(pokemaxHP), currHP(pokemaxHP) {
		for (int i = 0; i < 4; i++)
		{
			skills[i] = pokeskill[i];
		}
		}
};

void SkillInitializer(Skill palkiaSkills[], Skill charmanderSkills[], Skill eeveeSkills[], Skill dratiniSkills[], Skill pikachuSkills[]);

int DamageEffect( string attackType, string defenderPoke);

Pokemon pokemondetector(int playerchoice, Skill palkiaSkills[], Skill charmanderSkills[], Skill eeveeSkills[], Skill dratiniSkills[], Skill pikachuSkills[]);

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
	
	cout<<"Poke 1: "<<Poke1.name<<endl;
	cout<<"Poke 2: "<<Poke2.name<<endl;
	
	
	
	
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
		}
}
		
	
