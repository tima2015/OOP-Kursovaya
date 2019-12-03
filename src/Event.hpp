#define ESC 27
#define BACKSPACE 8
#define SPACE 32
#define ENTER 13
#define SHIFT 16
#define MIN_CHAR 32
#define MAX_CHAR 255
#ifndef EVENT_HPP
#define EVENT_HPP

//Интерфейс метка для стуктур данных событий

class Event {
   public:
      virtual ~Event(){};
};

class MouseEvent : public Event {
public:
    enum Type {
        MOVE, DRAG, LEFT_KEY_DOWN, LEFT_KEY_UP
    };

    MouseEvent(int, int, Type, int = 0, int = 0);
    int getX() const;
    int getY() const;
    int getPreX() const;
    int getPreY() const;
    Type getType() const;
private:
    int x, y, preX, preY;
    Type type;
};

class KeyboardEvent : public Event {
public:
    KeyboardEvent(int f, int fs = 0);
    int getKeyCode() const;
    int getPreKeyCode() const;
private:
    int keyCode, preKeyCode;
};

#endif

