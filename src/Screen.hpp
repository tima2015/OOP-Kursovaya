#include"Container.hpp"
#include "Button.hpp"
#include "Window.hpp"
#include "TextInputField.hpp"
#include "Image.hpp"

#define WIDTH 1024
#define HEIGHT 768
#ifndef SCREEN_HPP
#define SCREEN_HPP

class Screen : public Container {
public:
   Screen();//Конструктор
   ~Screen() {}; //Деструктор
   void start(bool rootCreated = false);//Инициализация графического интерфейса
private:
   void draw(int rootWidth, int rootHeight);//Метод отрисовки
   bool run;//Флаг, при false приложение завершает свою работу
   void checkMouse();//Проверка событий мыши, уведомляет о них слушателей
   void checkKeyboard();//Проверка событий клавиатуры, уведомляет о них слушателей
   class ScreenOnKeyUpListener : public OnKeyUpListener {
   public:
      ScreenOnKeyUpListener(Screen *screen);//Конструктор
   private:
      Screen *screen;//Родительский экран
      void onKeyUp(KeyboardEvent *event);//Реализация завершения работы Screen  при нажатии клавиши ESC
   };
   class ScreenOnSelectListner : public OnClickListener {
   public:
      ScreenOnSelectListner(Screen *screen);//Конструктор
   private:
      Screen *screen;//Родительский экран
      void replaceSelectables(int pos);//Перемещение окна в верх массива
      void onClick(MouseEvent *event);//Выбор текущего активного окна
   };
   class AboutButton : public Button {
   public:
      AboutButton(Screen *screen);//Конструктор
      virtual ~AboutButton() {}; //Деструктор
   private:
      class AboutButtonOnClickListener : public OnClickListener {
      public:
         AboutButtonOnClickListener(AboutButton *button,Screen *screen);//Конструктор
      private:
			Screen *screen; //Кореной элемент
         AboutButton *button;//Родительская кнопка
         void onClick(MouseEvent *event);
      };
   };
};

#endif