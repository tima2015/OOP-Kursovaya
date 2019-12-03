#include "Label.hpp"

Label::Label(string text, int x, int y){
   setText(text);
   this->x = x;
   this->y = y;
   tag = "Label";
}

void Label::useParentBgColor(bool use){
   useParentBgColorFlag = use;
}

void Label::setText(string text){
   this->text = text;
   height = textheight(text.c_str());
   width = textwidth(text.c_str());
}

string Label::getText() const{
   return text;
}

void Label::draw(int rootWidth, int rootHeight){
   setbkcolor(useParentBgColorFlag ? getpixel(absolutX + width/2,absolutY + height/2) : bgColor);
   setcolor(color);
   outtextxy(absolutX, absolutY, text.c_str());
}