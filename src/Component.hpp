#include<vector>
#include"Listener.hpp"
#include"graphics.h"

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

using namespace std;

class Component {
public:
   virtual ~Component(); //Деструктор
   void addListener(Listener *listener); //Добавляет слушателя
   void notify(Event *event); //Сообщить слушателям компонента о событии
   void render(int rootX, int rootY, int rootWidth, int rootHeight);//Визуализация и обновление абсолютной позиции
   virtual void draw(int rootWidth, int rootHeight) {} //Метод отрисовки компонента
   //Возвращает…
   bool isVisible() const; // true если компонент видимый
   int getWidth() const; // ширину компонента
   int getHeight() const; // высоту компонента
   int getX() const; // позицию x компонента в родительском контейнере
   int getY() const; // позицию y компонента в родительском контейнере
   int getAbsolutX() const; // абсолютную позицию x
   int getAbsolutY() const; // абсолютную позицию y
   string getTag() const; // тег элемента
   //Устанавливает
   void setVisible(bool visible); // Видимость элемента
   void setWidth(int width); // Ширину элемента
   void setHeight(int height); // Высоту элемента
   void setX(int x); // Позицию x компонента в родительском контейнере
   void setY(int y); // Позицию y компонента в родительском контейнере
   void setPosition(int x, int y);// Позицию x и y компонента в родительском контейнере
   void setBgColor(int color);// Цвет фона компонента
   void setColor(int color); // Основной цвет отрисовки компонента
   void setTag(string tag); // Тег элемента
protected:
   string tag = "untag"; // Тег элемента
   bool visible = true; //Видимость объекта
   int width = 0, height = 0, x = 0, y = 0,absolutX = 0, absolutY = 0;// ширина, высота, позиция компонента относительно родительского контейнера, абсолютная позиция компонента
   int bgColor = LIGHTGRAY; //Цвет фона, по умолчанию светло-серый
   int color = BLACK; //Основной цвет рисования, по умолчанию чёрный
private:
   vector<Listeners *> listeners; //Динамический массив слушателей
};

#endif