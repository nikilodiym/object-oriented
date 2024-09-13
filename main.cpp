#include <iostream>
#include <string>

using namespace std;

enum class Color {
    RED,
    GREEN,
    BLUE,
    YELLOW
};

string getColorName(Color color) {
    switch (color) {
    case Color::RED: return "Red";
    case Color::GREEN: return "Green";
    case Color::BLUE: return "Blue";
    case Color::YELLOW: return "Yellow";
    default: return "Unknown";
    }
}

class Shape {
protected:
    Color color;
public:
    Shape(Color c) : color(c) {}

    virtual void display() const = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(Color c, double r) : Shape(c), radius(r) {}

    void display() const override {
        cout << "Circle with radius " << radius << " and color " << getColorName(color) << "\n";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(Color c, double w, double h) : Shape(c), width(w), height(h) {}

    void display() const override {
         cout << "Rectangle with width " << width << ", height " << height << " and color " << getColorName(color) << "\n";
    }
};


int main(){
    Circle circle(Color::BLUE, 5.0);
    Rectangle rectangle(Color::RED, 3.0, 6.0);

    circle.display();
    rectangle.display();

	system("pause");
	return 0;
}