#include "Container.hpp"
#include <string>

#ifndef LABEL_HPP
#define LABEL_HPP

/*
*����� (�����)
*/
class Label : public Component{
   public:
      Label(string text = " ", int x = 0, int y = 0);//�����������
      virtual ~Label(){};//����������
      void useParentBgColor(bool use);//������������ ���� ���� ������������� ��������
      void setText(string text);//������������� ����� �����
      string getText() const;//���������� ����� �����
   protected:
      void draw(int rootWidth, int rootHeight);//������������ �����
   private:
      string text;//����� �����
      bool useParentBgColorFlag = true;//���� ������������� ����� ���� ������������� ��������, ������ ������
};

#endif