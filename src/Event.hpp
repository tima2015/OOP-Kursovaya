//���� ������ ����������
#define ESC 27
#define BACKSPACE 8
#define SPACE 32
#define ENTER 13
#define SHIFT 16
//��� ������������/������������� ���������� ��� ����������� �������
#define MIN_CHAR 32
#define MAX_CHAR 255
#ifndef EVENT_HPP
#define EVENT_HPP

//��������� ����� ��� ������� ������ �������
class Event {
public:
   virtual ~Event() {};
};

//������� ����
class MouseEvent : public Event {
public:
   enum Type {
      MOVE, DRAG, LEFT_KEY_DOWN, LEFT_KEY_UP
   };

   MouseEvent(int, int, Type, int = 0, int = 0);//�����������
   int getX() const;//��������� ������� x ������� ����
   int getY() const;// ��������� ������� y ������� ����
   int getPreX() const;// ��������� ���������� ������� x ������� ����
   int getPreY() const;// ��������� ���������� ������� y ������� ����
   Type getType() const;// ��������� ��� ������� ����
private:
   int x, y, preX, preY;//������� x,y, ���������� x,y
   Type type;//��� ������� ����
};

class KeyboardEvent : public Event {
public:
   KeyboardEvent(int, int = 0);//�����������
   int getKeyCode() const;//��������� ��� ������� ������� �������
   int getPreKeyCode() const;//��������� ���������� ������� �������
private:
   int keyCode, preKeyCode;//��� �������, ��� ���������� ������� �������
};
#endif

