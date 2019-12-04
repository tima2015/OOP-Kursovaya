#include "Container.hpp"

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
   void draw(int rootWidth, int rootHeight);//Отрисовка
private:
   string text;//Текст поля
   class InputOnKeyListener : public OnKeyUpListener {
   public:
      InputOnKeyListener(TextInputField *field);//Конструктор
   private:
      TextInputField *field;//Родительское поле ввода
      void onKeyUp(KeyboardEvent *event);//Обработка события ввода
   };
};

#endif