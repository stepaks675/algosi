#include <SFML/Graphics.hpp>
#include <random>
using namespace sf;
#define PUZIREK
int size = 1000;
int temp = 0;
int lastindex = 0;
int main()
{
    srand(time(NULL));
    int array[1000] = { 0 };
    for (int i = 0; i < 1000; i++) {
        array[i] = rand() % 1000;
    }
    
    RenderWindow window(VideoMode(1280, 1100), "sort?");
    window.setFramerateLimit(100);
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        VertexArray col(sf::Lines, 2);
        for (int i = 0; i < 1000; i++) {
            col[0].position = Vector2f(i+50, 1100);
            col[1].position = Vector2f(i+50, 1100-array[i]);
            window.draw(col);
        }
#ifdef PUZIREK
        for (int i = 0; i < size-1; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                lastindex = i+1;
            }
        }
        size = lastindex;
#endif
        window.display();
    }

    return 0;
}