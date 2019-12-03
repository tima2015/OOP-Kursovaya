#include "Event.hpp"
#ifndef Listener_HPP
#define Listener_HPP

class Listener {
public:
    virtual ~Listener(){}//Деструктор
    virtual void onEvent(Event *event){}//Действие при событии
};

class OnClickListener : public Listener {
protected:
    virtual void onClick(MouseEvent *event){};//Действие при клике мышкой
private:
    void onEvent(Event *event);//Проверка было ли событие кликом мышки
};

class OnPressListener : public Listener {
protected:
    virtual void onPress(MouseEvent *event){};// Действие при зажатии кнопки мыши
private:
    void onEvent(Event *event);// Проверка было ли событие зажатием кнопки мыши
};

class OnDragListener : public Listener {
protected:
    virtual void onDrag(MouseEvent *event){};// Действие при перетаскивании зажатой мыши
private:
    void onEvent(Event *event);// Проверка было ли событие перетаскиванием зажатой мыши
};

class OnMoveListener : public Listener {
protected:
    virtual void onMove(MouseEvent *event){};// Действие при передвижении мыши
private:
    void onEvent(Event *event);// Проверка было ли событие передвижением мыши
};

class OnKeyUpListener : public Listener {
protected:
    virtual void onKeyUp(KeyboardEvent *event){};// Действие при событии клавиатуры
private:
    void onEvent(Event *event);//Проверка является ли событие событием клавиатуры
};

#endif

