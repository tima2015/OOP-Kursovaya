#include<vector>
#include"Listener.hpp"
#include"graphics.h"

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

using namespace std;

class Component {
public:
   virtual ~Component(); //����������
   void addListener(Listener *listener); //��������� ���������
   void notify(Event *event); //�������� ���������� ���������� � �������
   void render(int rootX, int rootY, int rootWidth, int rootHeight);//������������ � ���������� ���������� �������
   virtual void draw(int rootWidth, int rootHeight) {} //����� ��������� ����������
   //����������
   bool isVisible() const; // true ���� ��������� �������
   int getWidth() const; // ������ ����������
   int getHeight() const; // ������ ����������
   int getX() const; // ������� x ���������� � ������������ ����������
   int getY() const; // ������� y ���������� � ������������ ����������
   int getAbsolutX() const; // ���������� ������� x
   int getAbsolutY() const; // ���������� ������� y
   string getTag() const; // ��� ��������
   //�������������
   void setVisible(bool visible); // ��������� ��������
   void setWidth(int width); // ������ ��������
   void setHeight(int height); // ������ ��������
   void setX(int x); // ������� x ���������� � ������������ ����������
   void setY(int y); // ������� y ���������� � ������������ ����������
   void setPosition(int x, int y);// ������� x � y ���������� � ������������ ����������
   void setBgColor(int color);// ���� ���� ����������
   void setColor(int color); // �������� ���� ��������� ����������
   void setTag(string tag); // ��� ��������
protected:
   string tag = "untag"; // ��� ��������
   bool visible = true; //��������� �������
   int width = 0, height = 0, x = 0, y = 0,absolutX = 0, absolutY = 0;// ������, ������, ������� ���������� ������������ ������������� ����������, ���������� ������� ����������
   int bgColor = LIGHTGRAY; //���� ����, �� ��������� ������-�����
   int color = BLACK; //�������� ���� ���������, �� ��������� ������
private:
   vector<Listeners *> listeners; //������������ ������ ����������
};

#endif