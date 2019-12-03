#include"Component.hpp"

#ifndef IMAGE_HPP
#define IMAGE_HPP

class Image : public Component{
   public:
      Image(string path, int x = 0, int y = 0, bool useMask = false);
      virtual ~Image();
	  void draw(int rootWidth, int rootHeight);
	private:
		bool useMask;
		IMAGE *img, *mask;
		IMAGE *createmask(IMAGE *p);
};

#endif