#include"Component.hpp"

#ifndef IMAGE_HPP
#define IMAGE_HPP

class Image : public Component {
public:
   Image(string path, int x = 0, int y = 0, bool useMask = false);//Конструктор
   virtual ~Image();//Деструктор
   void draw(int rootWidth, int rootHeight);//Отрисовка изображения
private:
   bool useMask;//флаг использования маски (альтернатива альфа канала)
   IMAGE *img, *mask;//изображение и маска
   IMAGE *createmask(IMAGE *p);//создание маски
};

#endif