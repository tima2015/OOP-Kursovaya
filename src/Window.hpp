#include "Container.hpp"

#ifndef WINDOW_HPP
#define WINDOW_HPP
/**
*ќкно, €вл€етс€ контейнером дл€ других компонентов.
*ћожет иметь заголовок.
*/
class Window : public Container {
public:
   Window(string title = " ", int width = 250, int height = 200);// онструктор
   virtual ~Window(){};//ƒеструктор
   bool isSelected() const;//¬озвращает true, если окно €вл€етс€ активным
   void setSelected(bool selected);//”станавливает статус активности окна
   string getTitle() const;//возвращает текст заголовка окна
protected:
   void draw(int rootWidth, int rootHeight);//отрисовывает окно, унаследовано Container
private:
   bool selected = false;//статус активности окна
   bool dragedNow = false;//флаг перемещени€ окна
   string title;//текст заголовка окна
   class WindowOnDragListener : public OnDragListener { //вложеный класс, реализующий слушатель перетаскивани€ мышью
   public:
      WindowOnDragListener(Window *window);// онструктор
   private:
      Window *window;//окно слушател€
      void onDrag(MouseEvent *event);//перемещение окна
   };
   class WindowOnClickListener : public OnClickListener { //вложеный класс, реализующий слушатель шелчка левой кнопки мыши
   public:
      WindowOnClickListener(Window *window);// онструктор
   private:
      Window *window;//окно слушател€
      void onClick(MouseEvent *event);//сн€тие флага перемещени€
   };
};

#endif