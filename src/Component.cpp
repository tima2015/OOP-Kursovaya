#include "Component.hpp"
#include <iostream>

using namespace std;

Component::~Component() {
   cout << "delete " << tag << "...\n";
   for (Listener *listener : listeners) {
      delete listener;
   }
}

void Component::addListener(Listener *listener) {
   listeners.push_back(listener);
}


void Component::notify(Event *event) {
   for (Listener *listener : listeners) {
      listener->onEvent(event);
   }
}

bool Component::isVisible() const {
   return visible;
}

void Component::render(int rootX, int rootY, int rootWidth, int rootHeight) {
   absolutX = rootX + x;
   absolutY = rootY + y;
   if (visible == false)
      return;
   draw(rootWidth, rootHeight);
}

int Component::getWidth() const {
   return width;
}

int Component::getHeight() const {
   return height;
}

int Component::getX() const {
   return x;
}

int Component::getY() const {
   return y;
}

int Component::getAbsolutX() const {
   return absolutX;
}

int Component::getAbsolutY() const {
   return absolutY;
}

string Component::getTag() const {
   return tag;
}

void Component::setVisible(bool visible) {
   this->visible = visible;
}

void Component::setWidth(int width) {
   this->width = width;
}
void Component::setHeight(int height) {
   this->height = height;
}

void Component::setX(int x) {
   this->x = x;
}

void Component::setY(int y) {
   this->y = y;
}

void Component::setPosition(int x, int y) {
   this->x = x;
   this->y = y;
}

void Component::setBgColor(int color) {
   bgColor = color;
}

void Component::setColor(int color) {
   this->color = color;
}

void Component::setTag(string tag) {
   this->tag = tag;
}