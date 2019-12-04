#include "Container.hpp"

#ifndef TEXTINPUTFIELD_HPP
#define TEXTINPUTFIELD_HPP

/*
*���� ����� ������
*/
class TextInputField : public Component {
public:
   TextInputField(string text = " ", int x = 0, int y = 0);//�����������
   virtual ~TextInputField() {}; //����������
   void setText(string text);//������������� ����� ����
   string getText() const;//���������� ����� ����
protected:
   void draw(int rootWidth, int rootHeight);//���������
private:
   string text;//����� ����
   class InputOnKeyListener : public OnKeyUpListener {
   public:
      InputOnKeyListener(TextInputField *field);//�����������
   private:
      TextInputField *field;//������������ ���� �����
      void onKeyUp(KeyboardEvent *event);//��������� ������� �����
   };
};

#endif