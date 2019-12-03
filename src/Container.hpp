#include "Component.hpp"

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

using namespace std;

class Container : public Component {
public:
   Container(); //Конструктор
   virtual ~Container(); //Деструктор
   void addComponent(Component *component); //Добавить компонент в контейнер
   void notifyAll(Event *event); //Вызывает свой notify, notify компонентов в контейнере и notifyAll контейнеров в контейнере
   void setVisible(bool visible);//Устанавливает видимость контейнера и дочерних элементов
   void renderAll(int rootX, int rootY, int rootWidth, int rootHeight); //Вызывает свой render, render компонентов в контейнере и renderAll контейнеров в контейнере
   vector<Component*> *getComponents() const; //Возращает динамический массив компонентов
protected:
   void draw(int rootWidth, int rootHeight) {} //Метод отрисовки контейнера
private:
   vector<Component*> *components; //Динамический массив компонентов контейнера
};

#endif

