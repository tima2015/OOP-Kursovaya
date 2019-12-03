#include "Button.hpp"
#include <iostream>

using namespace std;

Button::Button(int x, int y, int width, int height) {
   this->x = x;
   this->y= y;
   this->width = width;
   this->height = height;
   onMoveInButtonListener *omibl = new onMoveInButtonListener(this);
   onPressedButtonListener *opbl = new onPressedButtonListener(this);
   ButtonOnClickListener *bocl = new ButtonOnClickListener(this);
   addListener(omibl);
   addListener(opbl);
   addListener(bocl);
   tag = "Button";
}

void Button::setCheckColor(int color) {
   checkColor = color;
}

void Button::setPressedColor(int color) {
   this->pressedColor = color;
}

void Button::draw(int rootWidth, int rootHeight) {
   int c;

   switch (stage) {
   case UP:
      c = bgColor;
      break;
   case CHECK:
      c = checkColor;
      break;
   case DOWN:
      c = pressedColor;
      break;
   }

   setcolor(color);
   setfillstyle(SOLID_FILL, c);
   bar(absolutX,absolutY,absolutX + width, absolutY + height);
   rectangle(absolutX,absolutY,absolutX + width, absolutY + height);
}

Button::onMoveInButtonListener::onMoveInButtonListener(Button *button) {
   this->button = button;
}

void Button::onMoveInButtonListener::onMove(MouseEvent *event) {
   if (button->stage == DOWN)
      return;
   if (button->absolutX < event->getX() && event->getX() < button->absolutX + button->width &&
         button->absolutY < event->getY() && event->getY() < button->absolutY + button->height)
      button->stage = CHECK;
   else
      button->stage = UP;
}

Button::onPressedButtonListener::onPressedButtonListener(Button *button) {
   this->button = button;
}

void Button::onPressedButtonListener::onPress(MouseEvent *event) {
   if (button->absolutX < event->getX() && event->getX() < button->absolutX + button->width &&
         button->absolutY < event->getY() && event->getY() < button->absolutY + button->height)
      button->stage = DOWN;
}

Button::ButtonOnClickListener::ButtonOnClickListener(Button *button) {
   this->button = button;
}

void Button::ButtonOnClickListener::onClick(MouseEvent *event) {
      button->stage = UP;
}

TextButton::TextButton(string text, int x, int y, int width, int height) : Button(x,y,width,height) {
   buttonLabel = new Label();
   setText(text);
   addComponent(buttonLabel);
   tag = "TextButton";
}

string TextButton::getText() const {
   return buttonLabel->getText();
}

void TextButton::setText(string text) {
   buttonLabel->setText(text);
   buttonLabel->setPosition(width/2 - buttonLabel->getWidth()/2, height/2 - buttonLabel->getHeight()/2);
}