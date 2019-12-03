#include "Container.hpp"
#include <string>

#ifndef LABEL_HPP
#define LABEL_HPP

/*
*Метка (текст)
*/
class Label : public Component{
   public:
      Label(string text = " ", int x = 0, int y = 0);//Конструктор
      virtual ~Label(){};//Деструктор
      void useParentBgColor(bool use);//Использовать цвет фона родительского элемента
      void setText(string text);//Устанавливает текст метки
      string getText() const;//Возвращает текст метки
   protected:
      void draw(int rootWidth, int rootHeight);//Отрисовывает метку
   private:
      string text;//текст метки
      bool useParentBgColorFlag = true;//флаг использования цвета фона родительского элемента, вместо своего
};

#endif