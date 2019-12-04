#include "Container.hpp"

#ifndef WINDOW_HPP
#define WINDOW_HPP
/**
*����, �������� ����������� ��� ������ �����������.
*����� ����� ���������.
*/
class Window : public Container {
public:
   Window(string title = " ", int width = 250, int height = 200);//�����������
   virtual ~Window(){};//����������
   bool isSelected() const;//���������� true, ���� ���� �������� ��������
   void setSelected(bool selected);//������������� ������ ���������� ����
   string getTitle() const;//���������� ����� ��������� ����
protected:
   void draw(int rootWidth, int rootHeight);//������������ ����, ������������ Container
private:
   bool selected = false;//������ ���������� ����
   bool dragedNow = false;//���� ����������� ����
   string title;//����� ��������� ����
   class WindowOnDragListener : public OnDragListener { //�������� �����, ����������� ��������� �������������� �����
   public:
      WindowOnDragListener(Window *window);//�����������
   private:
      Window *window;//���� ���������
      void onDrag(MouseEvent *event);//����������� ����
   };
   class WindowOnClickListener : public OnClickListener { //�������� �����, ����������� ��������� ������ ����� ������ ����
   public:
      WindowOnClickListener(Window *window);//�����������
   private:
      Window *window;//���� ���������
      void onClick(MouseEvent *event);//������ ����� �����������
   };
};

#endif