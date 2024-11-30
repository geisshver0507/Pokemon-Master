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
}

int main() {

	
}
