using namespace std;
#ifndef HUMAN
#define HUMAN

#include "enums.h"
#include "date.h"

class Human {
private:
      Gender _gender;
      EyeColour _eye_colour;
      HairColour _hair_colour;
      Human* _father;
      Human* _mother;
      int _health_level;
      int _mental_health;
      int _height;
      int _weight;
      void Think();
      void Digest();
public:
      void GetUp();
      char* Speak();
      void Walk();
      void Breath();
      void GetFat();
      void LoseWeight();
      void Sleep();
      virtual void Joy();      
      bool Eat(Food _food);
      void Drink(Drink _drink);
	Human(Gender gender, EyeColour eye_colour, HairColour hair_colour, Human* father, Human* mother, int health_level, int mental_health, int height, int weight); 
	Human(const Human&) = default;
};
 
#endif
