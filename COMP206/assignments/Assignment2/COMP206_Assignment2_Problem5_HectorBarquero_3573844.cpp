//: COMP206_Assignment2_Problem5_HectorBarquero_STUDENT_ID.cpp

/*
 Title: COMP206_Assignment2_Problem5_HectorBarquero_STUDENT_ID.cpp
 Description: Model points and a polymorphic hierarchy of geometric shapes.
 Date: Jun 28, 2026
 Author: Hector Barquero
 Version: 2.0
 Copyright: 2026 Hector Barquero
*/

/*
 DOCUMENTATION

 Program Purpose:
    Define point operations and a shape hierarchy containing Circle, Rectangle and Triangle. 
    Each derived class calcs area, circumference/perimeter and an axis-aligned bounding box. 
    Constructors validate their geometric inputs.

 Compile on macOS with Homebrew GCC:
    g++-16 -std=c++17 -Wall -Wextra -pedantic COMP206_Assignment2_Problem5_HectorBarquero_STUDENT_ID.cpp -o COMP206_Assignment2_Problem5_HectorBarquero_STUDENT_ID

 Execution on macOS:
    ./COMP206_Assignment2_Problem5_HectorBarquero_STUDENT_ID.exe

 Classes:
    Point - stores x and y coordinates and supports show, add and subtract
    Shape - base class providing default geometric methods and display
    Circle - defined by a centre point and radius
    Rectangle - defined by four perimeter-ordered Point vertices
    Triangle - defined by three non-collinear Point vertices

 Math xref:
    Circle area = pi * radius^2
    Circle circumference = 2 * pi * radius
    Rectangle area = adjacent side length product
    Rectangle circumference = sum of four side lengths
    Triangle area = absolute shoelace determinant / 2
    Triangle circumference = sum of three side lengths

 Variables:
    x, y - double - Point coordinates
    valid - bool - whether constructor arguments form the requested shape
    vertices - Point collections defining Rectangle and Triangle objects
*/

/*
 TEST PLAN

 Point normal case:
    Add (2, 3) and (4, -1), expect (6, 2). Subtract the second point from the first, expect (-2, 4).

 Circle normal case:
    Circle centre (2, 2), radius 3. Expect ~28.274 and circumference approx 18.850. Bounding box is (-1, -1) to (5, 5).

 Circle bad data case:
    Radius -2 prints a warning and marks the citrcle invalid.

 Rectangle normal case:
    Vertices (0,0), (4,0), (4,2), (0,2) produce area 8 and perimeter 12.

 Rectangle square case:
    Vertices (0,0), (3,0), (3,3), (0,3) print the sq message.

 Bad case, rectangle:
    A non rectangle quadrilateral prints a warning and is marked invalid.

 Triangle normal case:
    Vertices (0,0), (4,0), (0,3) produce area 6 and perimeter 12.

 Bad case, triangle:
    Three collinear points print a warning and mark the Triangle invalid.

 Discussion:
    Rectangle vertices must be supplied in perimeter order. Floating-point comparisons use a tolerance
    rather than exact equality. Bounding boxes are axis-aligned and represented by minimum and maximum coordinate points.
*/

#include <algorithm> // max, min
#include <array>   
#include <cmath>     // to use abs for absolute and hypot for hypotenuse
#include <iomanip>   // set decimal precision https://cplusplus.com/reference/iomanip/setprecision/
#include <iostream> 
#include <limits>    // lets me query diff properties of arithmetic types: https://en.cppreference.com/cpp/types/numeric_limits
#include <string> 
#include <utility>   // implements binary tuples (pair) https://cppreference.com/cpp/utility
#include <vector> 

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point()
        : x(0.0), y(0.0) {
    }

    Point(double xCoordinate, double yCoordinate)
        : x(xCoordinate), y(yCoordinate) {
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void show() const {
        cout << '(' << x << ", " << y << ')';
    }

    Point add(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point subtract(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
};

static double distanceBetween(const Point& first, const Point& second) {
    return hypot(second.getX() - first.getX(), second.getY() - first.getY());
}

static double dotProduct(const Point& first, const Point& second) {
    return first.getX() * second.getX() + first.getY() * second.getY();
}

static double crossProduct(const Point& first, const Point& second) {
    return first.getX() * second.getY() - first.getY() * second.getX();
}

static bool nearlyEqual(double first, double second, double tolerance = 1.0e-9) {
    const double scale = max({1.0, abs(first), abs(second)});
    return abs(first - second) <= tolerance * scale;
}

class Shape {
public:
    virtual ~Shape() = default;

    virtual string className() const {
        return "Shape";
    }

    virtual bool isValid() const {
        return false;
    }

    virtual double area() const {
        cout << "Shape area is not defined.\n";
        return 0.0;
    }

    virtual double circumference() const {
        cout << "Shape circumference is not defined.\n";
        return 0.0;
    }

    virtual pair<Point, Point> boundingBox() const {
        cout << "Shape bounding box is not defined.\n";
        return {Point(), Point()};
    }

    virtual void showStoredInformation() const {
        cout << "No specific shape information is stored.\n";
    }

    virtual void display() const {
        cout << className() << '\n';
        showStoredInformation();
        cout << "Valid: " << (isValid() ? "yes" : "no") << '\n';

        if (isValid()) {
            cout << "Area: " << area() << '\n';
            cout << "Circumference: " << circumference() << '\n';

            const pair<Point, Point> box = boundingBox();
            cout << "Bounding box: ";
            box.first.show();
            cout << " to ";
            box.second.show();
            cout << '\n';
        } else {
            cout << "Area, circumference and bounding box are unavailable.\n";
        }

        cout << '\n';
    }
};

class Circle final : public Shape {
private:
    Point centre;
    double radius;
    bool valid;

public:
    Circle()
        : centre(0.0, 0.0), radius(1.0), valid(true) {
    }

    Circle(const Point& newCentre, double newRadius)
        : centre(newCentre), radius(newRadius), valid(newRadius > 0.0) {
        if (!valid) {
            cout << "Warning: Circle radius must be greater than zero.\n";
        }
    }

    string className() const override {
        return "Circle";
    }

    bool isValid() const override {
        return valid;
    }

    double area() const override {
        const double pi = acos(-1.0);
        return valid ? pi * radius * radius : 0.0;
    }

    double circumference() const override {
        const double pi = acos(-1.0);
        return valid ? 2.0 * pi * radius : 0.0;
    }

    pair<Point, Point> boundingBox() const override {
        return {
            Point(centre.getX() - radius, centre.getY() - radius),
            Point(centre.getX() + radius, centre.getY() + radius)
        };
    }

    void showStoredInformation() const override {
        cout << "Centre: ";
        centre.show();
        cout << "\nRadius: " << radius << '\n';
    }
};

class Rectangle final : public Shape {
private:
    array<Point, 4> vertices;
    bool valid;
    bool square;

    void validate() {
        const Point edge1 = vertices[1].subtract(vertices[0]);
        const Point edge2 = vertices[2].subtract(vertices[1]);
        const Point edge3 = vertices[3].subtract(vertices[2]);
        const Point edge4 = vertices[0].subtract(vertices[3]);

        const double length1 = distanceBetween(vertices[0], vertices[1]);
        const double length2 = distanceBetween(vertices[1], vertices[2]);
        const double length3 = distanceBetween(vertices[2], vertices[3]);
        const double length4 = distanceBetween(vertices[3], vertices[0]);

        const bool nonZeroSides =
            length1 > 0.0 && length2 > 0.0 && length3 > 0.0 && length4 > 0.0;

        const bool rightAngles =
            nearlyEqual(dotProduct(edge1, edge2), 0.0) &&
            nearlyEqual(dotProduct(edge2, edge3), 0.0) &&
            nearlyEqual(dotProduct(edge3, edge4), 0.0) &&
            nearlyEqual(dotProduct(edge4, edge1), 0.0);

        const bool oppositeSidesEqual =
            nearlyEqual(length1, length3) && nearlyEqual(length2, length4);

        const bool oppositeSidesParallel =
            nearlyEqual(crossProduct(edge1, edge3), 0.0) &&
            nearlyEqual(crossProduct(edge2, edge4), 0.0);

        valid = nonZeroSides && rightAngles && oppositeSidesEqual && oppositeSidesParallel;
        square = valid && nearlyEqual(length1, length2);

        if (!valid) {
            cout << "Warning: supplied points do not form a rectangle in perimeter order.\n";
        } else if (square) {
            cout << "Special case: this rectangle is a square.\n";
        }
    }

public:
    Rectangle()
        : vertices{Point(0.0, 0.0), Point(1.0, 0.0),
                   Point(1.0, 1.0), Point(0.0, 1.0)},
          valid(false), square(false) {
        validate();
    }

    Rectangle(const Point& first,
              const Point& second,
              const Point& third,
              const Point& fourth)
        : vertices{first, second, third, fourth}, valid(false), square(false) {
        validate();
    }

    string className() const override {
        return "Rectangle";
    }

    bool isValid() const override {
        return valid;
    }

    bool isSquare() const {
        return square;
    }

    double area() const override {
        if (!valid) {
            return 0.0;
        }

        return distanceBetween(vertices[0], vertices[1]) *
               distanceBetween(vertices[1], vertices[2]);
    }

    double circumference() const override {
        if (!valid) {
            return 0.0;
        }

        double perimeter = 0.0;
        for (size_t index = 0; index < vertices.size(); ++index) {
            perimeter += distanceBetween(vertices[index],
                                         vertices[(index + 1) % vertices.size()]);
        }
        return perimeter;
    }

    pair<Point, Point> boundingBox() const override {
        double minimumX = numeric_limits<double>::max();
        double minimumY = numeric_limits<double>::max();
        double maximumX = numeric_limits<double>::lowest();
        double maximumY = numeric_limits<double>::lowest();

        for (const Point& vertex : vertices) {
            minimumX = min(minimumX, vertex.getX());
            minimumY = min(minimumY, vertex.getY());
            maximumX = max(maximumX, vertex.getX());
            maximumY = max(maximumY, vertex.getY());
        }

        return {Point(minimumX, minimumY), Point(maximumX, maximumY)};
    }

    void showStoredInformation() const override {
        cout << "Vertices: ";
        for (size_t index = 0; index < vertices.size(); ++index) {
            vertices[index].show();
            if (index + 1 < vertices.size()) {
                cout << ", ";
            }
        }
        cout << "\nSquare: " << (square ? "yes" : "no") << '\n';
    }
};

class Triangle final : public Shape {
private:
    array<Point, 3> vertices;
    bool valid;

    void validate() {
        const Point firstEdge = vertices[1].subtract(vertices[0]);
        const Point secondEdge = vertices[2].subtract(vertices[0]);
        valid = !nearlyEqual(crossProduct(firstEdge, secondEdge), 0.0);

        if (!valid) {
            cout << "Warning: supplied points are collinear and do not form a triangle.\n";
        }
    }

public:
    Triangle()
        : vertices{Point(0.0, 0.0), Point(1.0, 0.0), Point(0.0, 1.0)},
          valid(false) {
        validate();
    }

    Triangle(const Point& first, const Point& second, const Point& third)
        : vertices{first, second, third}, valid(false) {
        validate();
    }

    string className() const override {
        return "Triangle";
    }

    bool isValid() const override {
        return valid;
    }

    double area() const override {
        if (!valid) {
            return 0.0;
        }

        const double determinant =
            vertices[0].getX() * (vertices[1].getY() - vertices[2].getY()) +
            vertices[1].getX() * (vertices[2].getY() - vertices[0].getY()) +
            vertices[2].getX() * (vertices[0].getY() - vertices[1].getY());

        return abs(determinant) / 2.0;
    }

    double circumference() const override {
        if (!valid) {
            return 0.0;
        }

        return distanceBetween(vertices[0], vertices[1]) +
               distanceBetween(vertices[1], vertices[2]) +
               distanceBetween(vertices[2], vertices[0]);
    }

    pair<Point, Point> boundingBox() const override {
        const double minimumX = min({vertices[0].getX(), vertices[1].getX(), vertices[2].getX()});
        const double minimumY = min({vertices[0].getY(), vertices[1].getY(), vertices[2].getY()});
        const double maximumX = max({vertices[0].getX(), vertices[1].getX(), vertices[2].getX()});
        const double maximumY = max({vertices[0].getY(), vertices[1].getY(), vertices[2].getY()});

        return {Point(minimumX, minimumY), Point(maximumX, maximumY)};
    }

    void showStoredInformation() const override {
        cout << "Vertices: ";
        for (size_t index = 0; index < vertices.size(); ++index) {
            vertices[index].show();
            if (index + 1 < vertices.size()) {
                cout << ", ";
            }
        }
        cout << '\n';
    }
};

int main() {
    cout << fixed << setprecision(3);

    cout << "Point operations\n";
    const Point firstPoint(2.0, 3.0);
    const Point secondPoint(4.0, -1.0);

    cout << "First point: ";
    firstPoint.show();
    cout << "\nSecond point: ";
    secondPoint.show();
    cout << "\nAdded: ";
    firstPoint.add(secondPoint).show();
    cout << "\nSubtracted: ";
    firstPoint.subtract(secondPoint).show();
    cout << "\n\n";

    const Circle defaultCircle;
    const Circle circle(Point(2.0, 2.0), 3.0);
    const Circle invalidCircle(Point(0.0, 0.0), -2.0);

    const Rectangle defaultRectangle;
    const Rectangle rectangle(
        Point(0.0, 0.0), Point(4.0, 0.0),
        Point(4.0, 2.0), Point(0.0, 2.0));
    const Rectangle square(
        Point(0.0, 0.0), Point(3.0, 0.0),
        Point(3.0, 3.0), Point(0.0, 3.0));
    const Rectangle nonRectangle(
        Point(0.0, 0.0), Point(4.0, 0.0),
        Point(3.0, 2.0), Point(0.0, 2.0));

    const Triangle defaultTriangle;
    const Triangle triangle(
        Point(0.0, 0.0), Point(4.0, 0.0), Point(0.0, 3.0));
    const Triangle invalidTriangle(
        Point(0.0, 0.0), Point(1.0, 1.0), Point(2.0, 2.0));

    const vector<const Shape*> shapes = {
        &defaultCircle,
        &circle,
        &invalidCircle,
        &defaultRectangle,
        &rectangle,
        &square,
        &nonRectangle,
        &defaultTriangle,
        &triangle,
        &invalidTriangle
    };

    for (const Shape* shape : shapes) {
        shape->display();
    }

    return 0;
} ///:~