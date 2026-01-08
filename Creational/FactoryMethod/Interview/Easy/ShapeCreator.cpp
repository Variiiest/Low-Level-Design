
// Design a program that can create different shapes like Circle, Rectangle, Square.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Shape {
    public:
      virtual void draw() = 0;
      virtual ~Shape() = default;
};

class Rectangle : public Shape {
    public:
    void draw() override {
        cout << "Rectangle draw" << endl;
    }
};

class Circle : public Shape {
    public:
    void draw() override {
        cout << "Circle draw" << endl;
    }
};

class ShapeFactory {
    public:
        static unique_ptr<Shape> createShape(const string& name) {
            if (name == "Rectangle") {
                return make_unique<Rectangle>();
            }
            if (name == "Circle") {
                return make_unique<Circle>();
            }
            return nullptr;
        }
};

int main() {
    ShapeFactory::createShape("Circle")->draw();
}

//Improved version to go with GOF