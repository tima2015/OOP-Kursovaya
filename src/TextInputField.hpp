#include "Container.hpp"
#include <string>

#ifndef TEXTINPUTFIELD_HPP
#define TEXTINPUTFIELD_HPP

/*
*Поле ввода текста
*/
class TextInputField : public Component {
public:
   TextInputField(string text = " ", int x = 0, int y = 0);//Конструктор
   virtual ~TextInputField() {}; //Деструктор
   void setText(string text);//Устанавливает текст поля
   string getText() const;//Возвращает текст поля
protected:
   void draw(int rootWidth, int rootHeight);
private:
   string text;//текст поля
   class InputOnKeyListener : public OnKeyUpListener {
   public:
      InputOnKeyListener(TextInputField *field);
   private:
      TextInputField *field;
      void onKeyUp(KeyboardEvent *event);
   };
};

#endif