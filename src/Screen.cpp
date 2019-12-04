#include "Screen.hpp"

Screen::Screen() {

   ScreenOnKeyUpListener *sokul = new ScreenOnKeyUpListener(this);
   ScreenOnSelectListner *sosl = new ScreenOnSelectListner(this);
   addListener(sokul);
   addListener(sosl);
   x = 0;
   y = 0;
   tag = "Screen";
}

void Screen::start() {
   width = getmaxx();
   height = getmaxy();

   AboutButton *ab = new AboutButton(this);
   addComponent(ab);
   run = true;
   int p=0;
   while (run) {
      checkMouse();
      checkKeyboard();
      p=1-p;
      setactivepage(p);
      setbkcolor(LIGHTBLUE);
      renderAll(x,y,width,height);
      setvisualpage(p);
      delay(1);
   }
}

void Screen::checkMouse() {
   static int preX, preY;
   static MouseEvent::Type preType;
   MouseEvent::Type type;

   if (mousebuttons() == 0) {
      if (preType == MouseEvent::LEFT_KEY_DOWN || preType == MouseEvent::DRAG)
         type = MouseEvent::LEFT_KEY_UP;
      else
         type = MouseEvent::MOVE;
   } else {
      if (preType == MouseEvent::MOVE)
         type = MouseEvent::LEFT_KEY_DOWN;
      else {
         type = MouseEvent::DRAG;
      }
   }

   MouseEvent *event = new MouseEvent(mousex(),mousey(),type,preX,preY);
   notifyAll(event);
   delete event;
   preX = mousex();
   preY = mousey();
   preType = type;
}

void Screen::checkKeyboard() {
   static int preKeyCode;
   if (kbhit() == 0)
      return;
   int keyCode = getch();
   KeyboardEvent *event = new KeyboardEvent(keyCode, preKeyCode);
   notifyAll(event);
   delete event;
   preKeyCode = keyCode;
}

void Screen::draw(int rootWidth, int rootHeight) {
   clearviewport();
}

Screen::ScreenOnKeyUpListener::ScreenOnKeyUpListener(Screen *screen) {
   this->screen = screen;
}

void Screen::ScreenOnKeyUpListener::onKeyUp(KeyboardEvent *event) {
   if (event->getKeyCode() == ESC) {
      for (int i = 0; i < screen->getComponents()->size(); i++)
         if (Window *w = dynamic_cast<Window *>(screen->getComponents()->at(i)))
            if (w->isSelected()) {
               screen->getComponents()->erase(screen->getComponents()->begin() + i);
               delete w;
               return;
            }
      screen->run = false;
   }
}

Screen::ScreenOnSelectListner::ScreenOnSelectListner(Screen *screen) {
   this->screen = screen;
}

void Screen::ScreenOnSelectListner::replaceSelectables(int pos) {
   for (int i = pos; i < screen->getComponents()->size() - 1; i++) {
      auto buffer = screen->getComponents()->at(i+1);
      screen->getComponents()->at(i+1) = screen->getComponents()->at(i);
      screen->getComponents()->at(i) = buffer;
   }
}

void Screen::ScreenOnSelectListner::onClick(MouseEvent *event) {
   bool selectFlag = true;
   int n = -1;
   for (int i = screen->getComponents()->size() - 1; i >= 0; i--) {
      Component *component = screen->getComponents()->at(i);
      if (Window *w = dynamic_cast<Window *>(component)) {
         w->setSelected(false);
         if (component->isVisible() && selectFlag && component->getX() < event->getX() &&
               component->getWidth() + component->getX() > event->getX() &&
               component->getY() - textheight(w->getTitle().c_str())< event->getY() &&
               component->getHeight() + component->getY() > event->getY()) {
            selectFlag = false;
            if (!w->isSelected()) {
               w->setSelected(true);
               n = i;
            }
         }
      }
   }
   if (n != -1) {
      replaceSelectables(n);
   }
}

Screen::AboutButton::AboutButton(Screen *screen) : Button() {
   Image *img = new Image("res/about.bmp",4,4,true);
   addComponent(img);
   AboutButtonOnClickListener *abocl = new AboutButtonOnClickListener(this, screen);
   addListener(abocl);

   x = screen->getWidth() - img->getWidth() - 8;
   y = screen->getHeight() - img->getHeight() - 8;
   width = screen->getWidth() - x;
   height = screen->getHeight() - y;
}

Screen::AboutButton::AboutButtonOnClickListener::AboutButtonOnClickListener(AboutButton *button, Screen *screen) {
   this->button = button;
   this->screen = screen;
}

void Screen::AboutButton::AboutButtonOnClickListener::onClick(MouseEvent *event) {
   if (button->absolutX < event->getX() && event->getX() < button->absolutX + button->width &&
         button->absolutY < event->getY() && event->getY() < button->absolutY + button->height) {

      Window *helpWindow = new Window("Информация о библиотеке", 400, 100);//Синевато(black) бледная куртка, розовая шапка, разноцветный портфель
      helpWindow->setPosition(screen->getWidth()/2 - helpWindow->getWidth()/2,
                              screen->getHeight()/2 - helpWindow->getHeight()/2);

      Label *l = new Label("Данная библиотека является курсовой работой", 8, 8);
      helpWindow->addComponent(l);
      helpWindow->addComponent(new Label("студента ЮУрГУ, ИЕТН, группы ЕТ-212", 8, l->getHeight() + 8));
      helpWindow->addComponent(new Label("Шерстобитова Тимофея Сергеевича", 8, l->getHeight()*2 + 8));
      helpWindow->addComponent(new Label("Email: woodgoldfilm@gmail.com", 8, l->getHeight()*3 + 8));
      helpWindow->addComponent(new Label("VK: https://vk.com/ozymand", 8, l->getHeight()*4 + 8));
      screen->addComponent(helpWindow);
   }
}



