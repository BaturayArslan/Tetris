#ifndef CALCULATION_H
#define CALCULATION_H
#include <SFML/Graphics.hpp>



struct point
{
    int x,y;
};



class Figure
{
public:
    static int F_collection [7][4];
    static int dx;
    static int dy;
    static int colorNum;
    static float delay;
    static  const int M = 200;
    static const int N = 100;
    
    
    int get_pointX(int a) const;
    int get_pointY(int a) const ;
    void leftMovement();
    void rightMovement();
    void downMovement();
    void restartTile();
    static bool check(const Figure &source);
    Figure& operator=(const Figure &source);
    void rotate();
    
    Figure(const Figure &source); //copy constructor
    Figure(int a);
    Figure();
    ~Figure();
private:
    point* ptr {nullptr};
    
    
};



extern int field [Figure::M][Figure::N];





#endif // CALCULATION_H
