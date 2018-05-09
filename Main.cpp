#include <iostream>
#include "Container.h"
#include "Shapes.h"
#include "ShapeFactory.h"

int main()
{
    Container<Shape *> shapes;
    for (int i = 0; i < 500; ++i)
    {
        shapes.addFirst(ShapeFactory::makeRandomShape());
    }

    std::cout << "ShapesCount: " << Shape::getCount() << std::endl;

    std::cout << "Shapes:" << std::endl;
    shapes.forEach(
            [] (Shape * const & shape)
            {
                std::cout << shape->print() << std::endl;
            }
    );

    shapes.forEach(
            [] (Shape * const & shape)
            {
                delete shape;
            }
    );

    std::cout << "ShapesCount: " << Shape::getCount() << std::endl;

    shapes.clean();

    return 0;

}