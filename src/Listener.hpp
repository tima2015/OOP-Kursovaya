#include "Event.hpp"
#ifndef Listener_HPP
#define Listener_HPP

class Listener {
public:
    virtual ~Listener(){}
    virtual void onEvent(Event *event){}
};

class OnClickListener : public Listener {
protected:
    virtual void onClick(MouseEvent *event){}
private:
    void onEvent(Event *event);
};

class OnPressListener : public Listener {
protected:
    virtual void onPress(MouseEvent *event){};
private:
    void onEvent(Event *event);
};

class OnDragListener : public Listener {
protected:
    virtual void onDrag(MouseEvent *event){};
private:
    void onEvent(Event *event);
};

class OnMoveListener : public Listener {
protected:
    virtual void onMove(MouseEvent *event){};
private:
    void onEvent(Event *event);
};

class OnKeyUpListener : public Listener {
protected:
    virtual void onKeyUp(KeyboardEvent *event){};
private:
    void onEvent(Event *event);
};

#endif

