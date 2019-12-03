//Коды клавиш клавиатуры
#define ESC 27
#define BACKSPACE 8
#define SPACE 32
#define ENTER 13
#define SHIFT 16
//Код минимального/максимального возможного для отображения символа
#define MIN_CHAR 32
#define MAX_CHAR 255
#ifndef EVENT_HPP
#define EVENT_HPP

//Интерфейс метка для стуктур данных событий
class Event {
public:
   virtual ~Event() {};
};

//Событие мыши
class MouseEvent : public Event {
public:
   enum Type {
      MOVE, DRAG, LEFT_KEY_DOWN, LEFT_KEY_UP
   };

   MouseEvent(int, int, Type, int = 0, int = 0);//Конструктор
   int getX() const;//Возращает позицию x нажатия мыши
   int getY() const;// Возращает позицию y нажатия мыши
   int getPreX() const;// Возращает предыдущую позицию x нажатия мыши
   int getPreY() const;// Возращает предыдущую позицию y нажатия мыши
   Type getType() const;// Возращает тип события мыши
private:
   int x, y, preX, preY;//Текущие x,y, предыдущие x,y
   Type type;//тип события мыши
};

class KeyboardEvent : public Event {
public:
   KeyboardEvent(int, int = 0);//Конструктор
   int getKeyCode() const;//Возращает код тукущей нажатой клавиши
   int getPreKeyCode() const;//Возращает предыдущей нажатой клавишу
private:
   int keyCode, preKeyCode;//Код клавиши, код предыдущей нажатой клавиши
};
#endif

