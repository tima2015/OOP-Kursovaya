#include "Component.hpp"

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

using namespace std;

class Container : public Component {
public:
   Container(); //�����������
   virtual ~Container(); //����������
   void addComponent(Component *component); //�������� ��������� � ���������
   void notifyAll(Event *event); //�������� ���� notify, notify ����������� � ���������� � notifyAll ����������� � ����������
   void setVisible(bool visible);//������������� ��������� ���������� � �������� ���������
   void renderAll(int rootX, int rootY, int rootWidth, int rootHeight); //�������� ���� render, render ����������� � ���������� � renderAll ����������� � ����������
   vector<Component*> *getComponents() const; //��������� ������������ ������ �����������
protected:
   void draw(int rootWidth, int rootHeight) {} //����� ��������� ����������
private:
   vector<Component*> *components; //������������ ������ ����������� ����������
};

#endif

