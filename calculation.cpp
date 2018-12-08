#include "calculation.h"
#include <iostream>


int field[Figure::M][Figure::N] {0};


int Figure::F_collection [7][4]
{   
        1,0,2,4,
        1,3,2,4,
        0,1,3,5,
        1,3,5,7,
        0,2,3,5,
        0,1,2,3,
        1,3,2,5,
};

int Figure::dx= 0;
int Figure::colorNum = 1;
float Figure:: delay = 0.3;
int Figure::dy = 3;


Figure::Figure(int a){
    ptr = new point[4];

    for(int i = 0; i < 4; i++){
        ptr[i].x = (F_collection[a][i] %2) * 16;
        ptr[i].y = (F_collection[a][i] /2) * 16;
    }
}

Figure::Figure(const Figure &source)
{
    ptr = new point[4];
    for(int i  = 0 ; i < 4; i++){
            ptr[i].x = source.ptr[i].x;
            ptr[i].y = source.ptr[i].y;
            
        }
    std::cout<<" COPPY CONSTRUCYOT CALLED ! "<<std::endl;
    
    
}

Figure& Figure::operator=(const Figure &source)
{
    for(int i = 0 ; i < 4; i++){
            ptr[i].x = source.ptr[i].x;
            ptr[i].y = source.ptr[i].y;
        
        }
    return *this;
}


Figure::Figure(){
    
    ptr = new point[4];
    
    for(int i = 0; i < 4; i++){
        ptr[i].x= (F_collection[0][i] %2) * 16;
        ptr[i].y = (F_collection[0][i] /2) * 16;
    }
}


Figure::~Figure(){
    delete[] ptr;
    
}



int Figure::get_pointX(int a) const {
    
    return ptr[a].x;
    
}


int Figure::get_pointY(int a) const {
    
    return ptr[a].y;
    
}


void Figure::leftMovement(){
    Figure::dx = -2;
    for(int i = 0; i < 4; i++){
            ptr[i].x += Figure::dx;
        } 
    
}


void Figure::rightMovement(){
    Figure::dx = 2;
    for(int i = 0; i < 4; i++){
        ptr[i].x += Figure::dx;
    } 
    
}


void Figure::rotate(){
    int temp = 0;
    int tempX = ptr[1].x;
    int tempY = ptr[1].y;
    for(int i = 0; i < 4 ; i++){
        temp = ptr[i].x - tempX;
        ptr[i].x = (ptr[i].x - tempX);
        ptr[i].y = (ptr[i].y - tempY);
        ptr[i].x = ptr[i].y;
        ptr[i].y =  -temp;
        ptr[i].x += tempX;
        ptr[i].y += tempY;
    
    }
    
}


void Figure::downMovement()
{       
    Figure::dy = 3;
    
    for(int i = 0; i < 4; i++){
        ptr[i].y += Figure::dy;
    } 
}


bool Figure::check(const Figure &source)
{
    for (int i = 0; i < 4; i++ ){
            if(source.get_pointX(i) < 0 || source.get_pointX(i) >= Figure::N || source.get_pointY(i) >= Figure::M ) return false;
            else if(field[source.get_pointX(i)][source.get_pointY(i)])return false;
            
        }
    return true ;
}

void Figure::restartTile()
{
    int random = rand()%7;
    for(int i = 0; i < 4; i++){
            ptr[i].x = ( F_collection[random][i] % 2 ) * 16;
            ptr[i].y = ( F_collection[random][i] / 2 ) *16;
            
    }
}


