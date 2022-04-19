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
      int _mental_health;
      int _height;
      void Think();
      void Digest();
protected:
      int _health_level;
      int _weight;
public:
      void GetUp();
      char* Speak();
      void Walk();
      void Breath();
      void GetFat();
      void LoseWeight();
      void Sleep();
      virtual void Joy();      
      void Eat(Food _food);
      void Drink(Drinks _drink);
	  void SetEyeColour(EyeColour eye_colour);
	  HairColour GetHairColour() const;
	  void SetHairColor(HairColour hair_colour);
	  Gender GetGender() const;
	Human* GetFather() const;
	Human* GetMother() const;
	int GetHealthLevel() const;

	Human(Gender gender, EyeColour eye_colour, HairColour hair_colour, Human* father, Human* mother, int health_level, int mental_health, int height, int weight); 
	Human(const Human&) = default;
};
 
#endif
