#include "Event.hpp"

KeyboardEvent::KeyboardEvent(int keyCode, int preKeyCode){
   this->keyCode = keyCode; 
   this->preKeyCode = preKeyCode;
}

int KeyboardEvent::getKeyCode() const{
   return keyCode;
}

int KeyboardEvent::getPreKeyCode() const{
   return preKeyCode;
}

MouseEvent::MouseEvent(int x, int y, Type type, int preX, int preY) {
    this->x = x;
    this->y = y;
    this->type = type;
    this->preX = preX;
    this->preY = preY;
}

int MouseEvent::getX() const{
   return x;
}

int MouseEvent::getY() const{
   return y;
}

int MouseEvent::getPreX() const{
   return preX;
}

int MouseEvent::getPreY() const{
   return preY;
}

MouseEvent::Type MouseEvent::getType() const{
   return type;
}

