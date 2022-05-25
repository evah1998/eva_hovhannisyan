#include <iostream>

using namespace std;

int size = 10;

class Graphic {
    public:
        virtual ~Graphic() {}
        virtual void move(int x, int y);
        virtual void draw() const = 0;
};

class Dot :public Graphic {
    protected:
        int _x;
        int _y;
    public:
        Dot(int x, int y) {
            _x = x;
            _y = y;
        }

        void move(int x, int y) override {
            _x += x;
            _y += y;
        }

        void draw() const override {
            // Нарисовать точку в координате X, Y.
        }
};

class Circle : public Dot {
    private:
        int _radius;
    public:
        Circle(int x, int y, int radius) 
            : Dot(x, y) {
            _radius = radius;
        }
        void draw() const override {
        // Нарисовать окружность в координате X, Y и радиусом R.
        }
};

class CompoundGraphic : public Graphic {
    private:
        Graphic* children[10];
    public:
        CompoundGraphic() {}
        void add(Graphic* child) {
            // Добавить компонент в список дочерних.
        }
        void remove(Graphic* child) {
            // Убрать компонент из списка дочерних.
        }
        void move(int x, int y) override {
            for (int i = 0; i < size; ++i) {
                children[i]->move(x, y);
            }
        }
        void draw() const override {
           for (int i = 0; i < size; ++i) {
                children[i]->draw();
            }
        }
};

int main() {
        CompoundGraphic* all = new CompoundGraphic();
        Graphic* dot = new Dot(1, 2);
        all->add(dot);
        Graphic* circle = new Circle(5, 3, 10);
        all->add(circle);
        
        return 0;
};
