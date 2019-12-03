#include "TextInputField.hpp"

TextInputField::TextInputField(string text, int x, int y){
   this->text = text;
   this->x = x;
   this->y = y;
   width = 150;
   height = 25;
   bgColor = WHITE;
   InputOnKeyListener *iokl = new InputOnKeyListener(this);
   addListener(iokl);
   tag = "TextInputField";
}

void TextInputField::setText(string text){
   this->text = text;
}

string TextInputField::getText() const{
   return text;
}

void TextInputField::draw(int rootWidth, int rootHeight){
   setcolor(color);
   setfillstyle(SOLID_FILL,bgColor);
   setbkcolor(bgColor);
   
   bar(absolutX,absolutY,absolutX + width, absolutY + height);
   rectangle(absolutX,absolutY,absolutX + width, absolutY + height);
   outtextxy(absolutX+2,absolutY+height/2 - textheight(text.c_str())/2,text.c_str());
}

TextInputField::InputOnKeyListener::InputOnKeyListener(TextInputField *field){
   this->field = field;
}

void TextInputField::InputOnKeyListener::onKeyUp(KeyboardEvent *event){
   if (event->getKeyCode() == BACKSPACE){
      field->text.erase(field->text.end()-1);
   }
   if (event->getKeyCode() > MIN_CHAR && event->getKeyCode() < MAX_CHAR){
      field->text+= event->getKeyCode();
	  if(textwidth((field->text).c_str()) > field->getWidth())
		  field->text.erase(field->text.end()-1);
   }
}