#include "Container.hpp"

#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button : public Container {
public:
   Button(int x = 0, int y = 0, int width = 100, int height = 25);// Конструктор
   virtual ~Button() {}; // Деструктор
   void setCheckColor(int color); // Установка цвета устанавливаемого при наведении мыши на кнопку
   void setPressedColor(int color); // Установка цвета устанавливаемого при зажатии левой кнопки мыши на кнопке
   protected:
   void draw(int rootWidth, int rootHeight); // Отрисовка
private:
   int checkColor = RGB(220,220,220); //Цвет устанавливаемый при наведении мыши на кнопку, по умолчанию светлосерый
   int pressedColor = DARKGRAY; //Цвет устанавливаемый прри зажатии кнопки
   enum Stage {
      UP, CHECK, DOWN
   };

   Stage stage = UP;//Стадия кнопки, по умолчанию UP
   class onMoveInButtonListener : public OnMoveListener {
   public:
      onMoveInButtonListener(Button *button); //Конструктор
   private:
      Button *button;//Родительская кнопка
      void onMove(MouseEvent *event); //Установка стадии на CHECK при движении на кнопке
   };
   class onPressedButtonListener : public OnPressListener {
   public:
      onPressedButtonListener(Button *button);//Конструктор
   private:
      Button *button;//Родительская кнопка
      void onPress(MouseEvent *event);//Изменение стадии кнопки на DOWN когда кнопка зажата
   };
   class ButtonOnClickListener : public OnClickListener {
   public:
      ButtonOnClickListener(Button *button);//Конструктор
   private:
      Button *button;//Родительская кнопка
      void onClick(MouseEvent *event); //Установка стадии на CHECK при клике на кнопке
   };
};


class TextButton : public Button{
public:
   TextButton(string text = " " ,int x = 0, int y = 0, int width =100, int height = 25);//Конструктор
   virtual ~TextButton(){};//Деструктор
   string getText() const;//Возвращает текст кнопки
   void setText(string text);//Установка текста кнопки
private:
   Label *buttonLabel;//Метка текстовой кнопки
};

#endif