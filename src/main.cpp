//OOP Assignment 3: Pokemon Game
//Name: GEISSHVER REEDYY SANTHIRA SEKARAN
//Student ID: 2024149042

#include <iostream>
#include <string>
using namespace std;

struct Skill {
	const string name;//skill name
	const string type;//skill type
	const int damage;//skill's damage
	const int maxTry;//skill's maximum number of attempt
	int balTry;//skill's balance number of attempts, modifiable throughout program
	
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
};

void SkillInitializer(Skill palkiaSkills[4], Skill charmanderSkills[4], Skill eeveeSkills[4], Skill dratiniSkills[4], Skill pikachuSkills[4]);

int main() {

	Skill thun("Thunderbolt","Electric",10,5);
	cout<<"Skill :"<< thun.name<<endl;
	cout<<"Type :"<< thun.type<<endl;
	cout<<"Damage : "<< thun.damage<<endl;
	cout<<"Max try: "<<thun.maxTry<<endl;
	cout<<"balance try: "<<thun.balTry<<endl;
	return 0;
}

void SkillInitializer(Skill palkiaSkills[4], Skill charmanderSkills[4], Skill eeveeSkills[4], Skill dratiniSkills[4], Skill pikachuSkills[4])
{
	//Initializing Pikachu's skills
	pikachuSkills[0] = Skill("Tackle","Normal",4,5);
	pikachuSkills[1] = Skill("Grass Knot","Grass",8,5);
	pikachuSkills[2] = Skill("Thunderbolt","Electric",10,5)
	pikachuSkills[3] = Skill("Megabolt","Electric",15,3)
	
	//Initializing Dratini's skills
	
	dratiniSkills[0] = Skill("Wrap", "Normal", 4, 10);
    	dratiniSkills[1] = Skill("Aqua Tail", "Water", 3, 5);
    	dratiniSkills[2] = Skill("Water Pulse", "Water", 13, 2);
    	dratiniSkills[3] = Skill("Hyper Beam", "Normal", 20, 1);

	//Initializing Eevee's skills
	
	eeveeSkills[0] = pikachuSkills[0] //Structure allows shallow copying
    	eeveeSkills[1] = Skill("Sand Attack", "Ground", 8, 3);
    	eeveeSkills[2] = Skill("Bite", "Normal", 12, 3);
    	eeveeSkills[3] = Skill("Rain Dance", "Water", 15, 1);
    	
	//Initializing Charmander's Skills
	charmanderSkills[0] = pikachuSkills[0] //Structure allows shallow copying
	charmanderSkills[1] = Skill("Flamethrower", "Fire", 11, 5);
    	charmanderSkills[2] = Skill("Dig", "Ground", 7, 5);
    	charmanderSkills[3] = Skill("Heat Wave", "Fire", 14, 5);
    	
    	//Initializing Palkia's Skills
    	
    	palkiaSkills[0] = Skill("Hydro Pump", "Water", 12, 10);
    	palkiaSkills[1] = Skill("Earth Power", "Ground", 15, 10);
    	palkiaSkills[2] = Skill("Surf", "Water", 13, 10);
    	palkiaSkills[3] = Skill("Spatial Rend", "Normal", 30, 10);

}
	
	


