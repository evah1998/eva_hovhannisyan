#include <iostream>
#include <cmath>

using namespace std;

class RoundPeg {
    protected:
        int _radius;
    public:
        RoundPeg(int radius) {
            _radius = radius;
        }
        virtual int getRadius() const {
            return _radius;
        }
};

class RoundHole {
    private:
        int _radius;
    public:
        RoundHole(int radius) {
            _radius = radius;
        }
        int getRadius() {
            return _radius;
        }
        bool fits(RoundPeg* peg) {
            return this->getRadius() >= peg->getRadius();
        }

};

class SquarePeg {
    private:
        int _width;
    public:
        SquarePeg(int width) {
            _width = width;
        }
        int getWidth() {
            return _width;
        }
};

class SquarePegAdapter : public RoundPeg {
    private:
        SquarePeg* _peg;
    public:
        SquarePegAdapter(SquarePeg* peg)
            :RoundPeg(_radius) {
            _peg = peg;
        }
        int getRadius() const override {
            return _peg->getWidth() * sqrt(2) / 2;
        }

};

int main() {
    RoundHole* hole = new RoundHole(5);
    RoundPeg* rpeg = new RoundPeg(5);
    cout << hole->fits(rpeg) << endl;

    SquarePeg* small_sqpeg = new SquarePeg(5);
    SquarePeg* large_sqpeg = new SquarePeg(10);

    SquarePegAdapter* small_sqpeg_adapter = new SquarePegAdapter(small_sqpeg);
    SquarePegAdapter* large_sqpeg_adapter = new SquarePegAdapter(large_sqpeg);
    cout << hole->fits(small_sqpeg_adapter) << endl;
    cout << hole->fits(large_sqpeg_adapter) << endl;

    return 0;
}