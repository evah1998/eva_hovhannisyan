#include <iostream>
#include <string.h>

using namespace std;

class Transport {
    public:
        virtual ~Transport() {}
        virtual string deliver() const = 0;
};

class Truck : public Transport {
    public:
        string deliver() const override {
            return "{Truck}";
        }
};
class Ship : public Transport {
    public:
        string deliver() const override {
            return "{Ship}";
        }
};

class Logistics {
    public:
        virtual ~Logistics(){};
        virtual Transport* createTransport() const = 0;

        string planDelivery() const {
            Transport* Transport = this->createTransport();
            string result = "Logistics: The same Logistic's code has just worked with " + Transport->deliver();
            delete Transport;
            return result;
        }
};

class RoadLogistics : public Logistics{
    public:
        Transport* createTransport() const override {
            return new Truck();
        }
};

class SeaLogistics : public Logistics {
    public:
        Transport* createTransport() const override {
            return new Ship();
        }
};

void ClientCode(const Logistics& logistic) {
    cout << logistic.planDelivery() << std::endl;
}

int main() {
    cout << "App: Launched with the RoadLogistics.\n";
    Logistics* logistic = new RoadLogistics();
    ClientCode(*logistic);
    cout << std::endl;
    cout << "App: Launched with the SeaLogistics.\n";
    Logistics* logistic2 = new SeaLogistics();
    ClientCode(*logistic2);

    delete logistic;
    delete logistic2;

    return 0;
}