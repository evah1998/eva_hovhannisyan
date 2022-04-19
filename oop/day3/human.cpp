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

void Human::Digest() {
  if (_health_level < 100) {
    ++_health_level;
  }
} 

void Human::Walk() {
  if (_health_level < 100) {
    ++_health_level;
  }

  --_weight;
}

void Human::Eat(Food food) {
  if ((food == banana || food == apple || food == yogurt || food == honey) && _health_level < 100) {
    ++_health_level;
  }

  if ((food == chips || food == pizza || food == burger) && _health_level < 100) {
    --_health_level;
  }
  
	++_weight;
}

void Human::Drink(Drinks drink) {
  if (drink == alcohol) {
    --_health_level;
  }

  if (drink == milk || drink == water || drink == tea || drink == juice) {
    _health_level = (_health_level >= 99 && _health_level <= 100) ? 100 : ++_health_level;
  }
}

void Human::SetEyeColour(EyeColour eye_colour) {
  if (eye_colour == brown || eye_colour == black || eye_colour == blue || eye_colour == green || eye_colour == red) {
    _eye_colour = eye_colour;
  } else {
    _eye_colour = black;
  }
}

HairColour Human::GetHairColour() const {
  return _hair_colour;
}

void Human::SetHairColor(HairColour hair_colour) {
  if (hair_colour == Brown || hair_colour == Black || hair_colour == Blonde || hair_colour == White ) {
    _hair_colour = hair_colour;
  } else {
    _hair_colour = White;
  }
}

Gender Human::GetGender() const {
  return _gender;
}

Human* Human::GetFather() const {
  return _father;
}

Human* Human::GetMother() const {
  return _mother;
}

void Human::SetHealthLevel() {
  _health_level = health_level;
}

