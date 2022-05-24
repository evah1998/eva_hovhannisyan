#include <iostream>
#include <string.h>

using namespace std;

class Chair {
 public:
  virtual ~Chair(){};
  virtual string hasLegs() const = 0;
  virtual string sitOn() const = 0;
};

class VictorianChair : public Chair {
 public:
  string hasLegs() const override {
    return "Victorian chair has legs.";
  }
  string sitOn() const override {
    return "Sit on victorian chair.";
  }
};

class ModernChair : public Chair {
  string hasLegs() const override {
    return "Modern chair has legs.";
  }
  string sitOn() const override {
    return "Sit on modern chair.";
  }
};

class Sofa {
 public:
  virtual ~Sofa(){};
  virtual string hasLegs() const = 0;
};

class VictorianSofa : public Sofa {
 public:
  string hasLegs() const override {
    return "Victorian sofa has legs.";
  }
};

class ModernSofa : public Sofa {
 public:
  string hasLegs() const override {
    return "Modern sofa has legs.";
  }
};

class FurnitureFactory {
 public:
  virtual Chair *createChair() const = 0;
  virtual Sofa *createSofa() const = 0;
};

class VictorianFurnitureFactory : public FurnitureFactory {
 public:
  Chair *createChair() const override {
    return new VictorianChair();
  }
  Sofa *createSofa() const override {
    return new VictorianSofa();
  }
};

class ModernFurnitureFactory : public FurnitureFactory {
 public:
  Chair *createChair() const override {
    return new ModernChair();
  }
  Sofa *createSofa() const override {
    return new ModernSofa();
  }
};

void ClientCode(const FurnitureFactory &factory) {
  const Chair *chair = factory.createChair();
  const Sofa *sofa = factory.createSofa();
  cout << sofa->hasLegs() << "\n";
  delete chair;
  delete sofa;
}

int main() {
  cout << "Client: Testing client code with the first factory type:\n";
  VictorianFurnitureFactory *f1 = new VictorianFurnitureFactory();
  ClientCode(*f1);
  delete f1;
  cout << endl;
  cout << "Client: Testing the same client code with the second factory type:\n";
  ModernFurnitureFactory *f2 = new ModernFurnitureFactory();
  ClientCode(*f2);
  delete f2;
  return 0;
}

