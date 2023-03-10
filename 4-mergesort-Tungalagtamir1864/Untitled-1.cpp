#include<SFML/Graphics.hpp>
#include"Header.h" 

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Balls");
    
    window.setFramerateLimit(60);  


      //  sf::CircleShape circle;
        sf::Vector2f position(600, 350); 
      //  circle.setPosition(position);

      //  circle.setRadius(4.f);
    

   // float xVelocity = 7;
   // float yVelocity = 7;

    sf::RectangleShape line(sf::Vector2f(300, 10));
    line.rotate(90);

      line.setPosition(position);

 //  circle.setRadius(4.f);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }      

         //if (position.x < 0 || position.x>1180) xVelocity *= -1; 
        // if(position.y< 0 || position.y >620 ) yVelocity *= -1;

         //position.x += xVelocity;
         //position.y += yVelocity;
        // circle.setPosition(position);



        window.clear();
       
        window.draw(line);
        
        window.display();
    }

    return 0;
}