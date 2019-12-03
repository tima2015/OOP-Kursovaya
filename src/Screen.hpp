#include"Container.hpp"
#include "Button.hpp"
#include "Window.hpp"
#include "TextInputField.hpp"
#include "Image.hpp"

#define WIDTH 1024
#define HEIGHT 768
#ifndef SCREEN_HPP
#define SCREEN_HPP

class Screen : public Container {
public:
   Screen();//�����������
   ~Screen() {}; //����������
   void start(bool rootCreated = false);//������������� ������������ ����������
private:
   void draw(int rootWidth, int rootHeight);//����� ���������
   bool run;//����, ��� false ���������� ��������� ���� ������
   void checkMouse();//�������� ������� ����, ���������� � ��� ����������
   void checkKeyboard();//�������� ������� ����������, ���������� � ��� ����������
   class ScreenOnKeyUpListener : public OnKeyUpListener {
   public:
      ScreenOnKeyUpListener(Screen *screen);//�����������
   private:
      Screen *screen;//������������ �����
      void onKeyUp(KeyboardEvent *event);//���������� ���������� ������ Screen  ��� ������� ������� ESC
   };
   class ScreenOnSelectListner : public OnClickListener {
   public:
      ScreenOnSelectListner(Screen *screen);//�����������
   private:
      Screen *screen;//������������ �����
      void replaceSelectables(int pos);//����������� ���� � ���� �������
      void onClick(MouseEvent *event);//����� �������� ��������� ����
   };
   class AboutButton : public Button {
   public:
      AboutButton(Screen *screen);//�����������
      virtual ~AboutButton() {}; //����������
   private:
      class AboutButtonOnClickListener : public OnClickListener {
      public:
         AboutButtonOnClickListener(AboutButton *button,Screen *screen);//�����������
      private:
			Screen *screen; //������� �������
         AboutButton *button;//������������ ������
         void onClick(MouseEvent *event);
      };
   };
};

#endif