#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "calculation.h"
using namespace sf;
    



int main()
{   
    RenderWindow window(VideoMode(400,600),"ALIVE",Style::Default);
    Event event;
    Texture texture;
    texture.loadFromFile("tetris/blue.png");
    Sprite draw(texture);
    
    Figure tile(5);
    Figure temp;
    
    Clock clock;
    float timer = 0;
    
    
    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer +=time;
        
        
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
            
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Up){
                    temp = tile;
                    tile.rotate();
                    if(!Figure::check(tile)) tile = temp;
                } 
                else if(event.key.code == Keyboard::Left)
                {   
                    temp = tile;
                    tile.leftMovement();
                    if(!Figure::check(tile)) tile = temp;
                    
                    
                }
                else if (event.key.code == Keyboard::Right)
                {
                    temp = tile;
                    tile.rightMovement();
                    if(!Figure::check(tile)) tile = temp;
                    
                }
            }
        }
       // --------FLOW-------
       if(timer > Figure::delay)
        {
            temp = tile;
            tile.downMovement();
            if(!Figure::check(tile)){
                tile = temp;
                for(int i = 0; i < 4; i++){
                    field[temp.get_pointX(i)][temp.get_pointY(i)] = Figure::colorNum;
                }
                Figure::colorNum = 1 + rand()%7;
                tile.restartTile();
            }
            timer = 0;
        }
        
        
       
    
        
        
        
        
        window.clear(Color::Black);
        for(int i = 0 ; i < 4; i++){
            draw.setPosition(tile.get_pointX(i),tile.get_pointY(i));
            window.draw(draw);
        
        }
        window.display();
        
    }

        
    
}