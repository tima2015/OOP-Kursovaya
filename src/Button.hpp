#include "Container.hpp"

#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button : public Container {
public:
   Button(int x = 0, int y = 0, int width = 100, int height = 25);// �����������
   virtual ~Button() {}; // ����������
   void setCheckColor(int color); // ��������� ����� ���������������� ��� ��������� ���� �� ������
   void setPressedColor(int color); // ��������� ����� ���������������� ��� ������� ����� ������ ���� �� ������
   protected:
   void draw(int rootWidth, int rootHeight); // ���������
private:
   int checkColor = RGB(220,220,220); //���� ��������������� ��� ��������� ���� �� ������, �� ��������� �����������
   int pressedColor = DARKGRAY; //���� ��������������� ���� ������� ������
   enum Stage {
      UP, CHECK, DOWN
   };

   Stage stage = UP;//������ ������, �� ��������� UP
   class onMoveInButtonListener : public OnMoveListener {
   public:
      onMoveInButtonListener(Button *button); //�����������
   private:
      Button *button;//������������ ������
      void onMove(MouseEvent *event); //��������� ������ �� CHECK ��� �������� �� ������
   };
   class onPressedButtonListener : public OnPressListener {
   public:
      onPressedButtonListener(Button *button);//�����������
   private:
      Button *button;//������������ ������
      void onPress(MouseEvent *event);//��������� ������ ������ �� DOWN ����� ������ ������
   };
   class ButtonOnClickListener : public OnClickListener {
   public:
      ButtonOnClickListener(Button *button);//�����������
   private:
      Button *button;//������������ ������
      void onClick(MouseEvent *event); //��������� ������ �� CHECK ��� ����� �� ������
   };
};


class TextButton : public Button{
public:
   TextButton(string text = " " ,int x = 0, int y = 0, int width =100, int height = 25);//�����������
   virtual ~TextButton(){};//����������
   string getText() const;//���������� ����� ������
   void setText(string text);//��������� ������ ������
private:
   Label *buttonLabel;//����� ��������� ������
};

#endif