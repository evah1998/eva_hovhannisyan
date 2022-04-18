#include <iostream>
#include "human.h"

using namespace std;

Human::Human(Gender gender, EyeColour eye_colour, HairColour hair_colour, Human* father, Human* mother, int health_level, int mental_health, int height, int weight) {
		_gender = gender;
		_eye_colour = eye_colour;
      	_hair_colour = hair_colour;
      	_father = father;
      	_mother = mother;
      	_health_level = health_level;
      	_mental_health = mental_health;
     	_height = height;
      	_weight = weight;
}

void walk() {
	int step = 0;
	step++;
}
