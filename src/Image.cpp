#include "Image.hpp"

Image::Image(string path, int x, int y, bool useMask) {
   this->x = x;
   this->y = y;
   this->useMask = useMask;
   img = loadBMP(path.c_str());
   width = imagewidth(img);
   height = imageheight(img);
   if (useMask)
      mask = createmask(img);
  tag = "Image";
}

Image::~Image() {
   freeimage(img);
   if (useMask)
      freeimage(mask);
}

IMAGE *Image::createmask(IMAGE *p) {
   IMAGE *m=createimage(width,height);
   int c=imagegetpixel(p,0,0);
   for (int x=0; x<width; ++x)
      for (int y=0; y<height; ++y)
      {  int d=imagegetpixel(p,x,y);
         if (c==d)
         {  imageputpixel(m,x,y,WHITE);
            imageputpixel(p,x,y,BLACK);
         }
         else
            imageputpixel(m,x,y,BLACK);
      }
   return m;
}

void Image::draw(int rootWidth, int rootHeight) {
   putimage(absolutX,absolutY,mask,AND_PUT);
   putimage(absolutX,absolutY,img,OR_PUT);
}