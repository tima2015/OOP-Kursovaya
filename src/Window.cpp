#include "Window.hpp"
#include "graphics.h"

Window::Window(string title, int width, int height) {
   this->title = title;
   this->width = width;
   this->height = height;
   WindowOnDragListener *wodl = new WindowOnDragListener(this);
   WindowOnClickListener *wocl = new WindowOnClickListener(this);
   addListener(wodl);
   addListener(wocl);
   tag = "Window";
}

bool Window::isSelected() const {
   return selected;
}

void Window::setSelected(bool selected) {
   this->selected = selected;
}

string Window::getTitle() const {
   return title;
}

void Window::draw(int rootWidth, int rootHeight) {
   setcolor(color);
   if (selected) {
      setfillstyle(SOLID_FILL, WHITE);
      setbkcolor(WHITE);
   } else {
      setfillstyle(SOLID_FILL, DARKGRAY);
      setbkcolor(DARKGRAY);
   }

   int w = rootWidth > width ? width : rootWidth, h = rootHeight > height ? height : rootHeight;


   bar(absolutX, absolutY - textheight(title.c_str()), absolutX + w, absolutY);
   outtextxy(absolutX + 2, absolutY - textheight(title.c_str()), title.c_str());
   rectangle(absolutX, absolutY - textheight(title.c_str()), absolutX + w, absolutY);

   setfillstyle(SOLID_FILL, bgColor);
   bar(absolutX, absolutY,absolutX + w,
       absolutY + h);
   rectangle(absolutX, absolutY,absolutX + w,
             absolutY + h);

}

Window::WindowOnDragListener::WindowOnDragListener(Window *window) {
   this->window = window;
}

void Window::WindowOnDragListener::onDrag(MouseEvent *event) {
   if (!window->selected)
      return;
   if (window->x < event->getX() && event->getX() < window->x + window->width &&
         window->y+2 > event->getY() && event->getY() > window->y - textheight(window->title.c_str()))
      window->dragedNow = true;
   if (window->dragedNow)
      window->setPosition(event->getX() - window->width/2, event->getY());
}

Window::WindowOnClickListener::WindowOnClickListener(Window *window) {
   this->window = window;
}

void Window::WindowOnClickListener::onClick(MouseEvent *event) {
   window->dragedNow = false;
}