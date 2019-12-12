#include <cstdlib>
#include "Screen.hpp"


using namespace std;

//Простой тест, создание окна с меткой, "Привет мир!" и заголовком "Окно теста 1"
void test1(Screen *screen);
//Тест в виде программы калькулятора
void test2(Screen *screen);

/*
 *
 */
int main() {
   initwindow(1280,720);
   Screen *screen = new Screen();
   test1(screen);
   test2(screen);
   screen->start();
   delete screen;
   return 0;
}

void test1(Screen *screen) {
   Window *window = new Window("Окно теста 1",150,150);
   window->setTag("Test 1 Window");
   window->setPosition(screen->getWidth()/2 - window->getWidth()/2, screen->getHeight()/2 - window->getHeight()/2);
   Label *label = new Label("Привет мир!");
   label->setTag("Hello World Label  ");
   label->setPosition(150/2 - label->getWidth()/2, 150/2 - label->getHeight()/2);
   window->addComponent(label);
   screen->addComponent(window);
}

class TestTextButtonListener : public OnClickListener {
public:
   TestTextButtonListener(Label *l, TextInputField *i, Window *w) {
      this->l = l;
      this->i = i;
      this->w = w;
   }
   Label *l;
   TextInputField *i;
   Window *w;
   void onClick(MouseEvent *event) {
      l->setText(i->getText());
      l->setPosition(w->getWidth()/2 - l->getWidth()/2, w->getHeight()/2 + l->getHeight()*2);
   }
};

void test2(Screen *screen) {
   Window *window = new Window("Окно теста 2");
   window->setPosition(screen->getWidth()/2 - window->getWidth()/2, screen->getHeight()/2 - window->getHeight()/2);
   Label *label1 = new Label("Введённый текст:");
   label1->setPosition(window->getWidth()/2 - label1->getWidth()/2, window->getHeight()/2 - label1->getHeight()/2);
   Label *label2 = new Label();
   label2->setPosition(window->getWidth()/2 - label2->getWidth()/2, window->getHeight()/2 + label2->getHeight()*2);
   TextInputField *in = new TextInputField();
   in->setWidth(100);
   in->setPosition(window->getWidth()/2 - in->getWidth()/2,8);
   TextButton *button = new TextButton("Принять текст");
   button->setPosition(window->getWidth()/2 - button->getWidth()/2,window->getHeight() - button->getHeight() - 8);

   button->addListener(new TestTextButtonListener(label2,in,window));
   window->addComponent(in);
   window->addComponent(label1);
   window->addComponent(label2);
   window->addComponent(button);
   screen->addComponent(window);
}