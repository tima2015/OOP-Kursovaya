#include "Event.hpp"
#ifndef Listener_HPP
#define Listener_HPP

class Listener {//Слушатель 
public:
    virtual ~Listener(){}//Деструктор
    virtual void onEvent(Event *event){}//Действие при событии
};

class OnClickListener : public Listener {//Слушатель клика мыши
protected:
    virtual void onClick(MouseEvent *event){};//Действие при клике мышкой
private:
    void onEvent(Event *event);//Проверка было ли событие кликом мыши
};

class OnPressListener : public Listener {//Слуушатель зжатия кнопки мыши
protected:
    virtual void onPress(MouseEvent *event){};//Действие при зажатии кнопки мыши
private:
    void onEvent(Event *event);//Проверка было ли событие зажатием кнопки мыши
};

class OnDragListener : public Listener {//Слуушатель перетаскивания зажатой мыши
protected:
    virtual void onDrag(MouseEvent *event){};//Действие при перетаскивании зажатой мыши
private:
    void onEvent(Event *event);//Проверка было ли событие перетаскиванием зажатой мыши
};

class OnMoveListener : public Listener {//Слуушатель передвижения мыши
protected:
    virtual void onMove(MouseEvent *event){};//Действие при передвижении мыши
private:
    void onEvent(Event *event);//Проверка было ли событие передвижением мыши
};

class OnKeyUpListener : public Listener {//Слуушатель событий клавиатуры
protected:
    virtual void onKeyUp(KeyboardEvent *event){};// Действие при событии клавиатуры
private:
    void onEvent(Event *event);//Проверка является ли событие событием клавиатуры
};

#endif

