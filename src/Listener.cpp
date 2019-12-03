#include "Listener.hpp"

void OnClickListener::onEvent(Event *event) {
   if (MouseEvent *me = dynamic_cast<MouseEvent *>(event))
      if (me->getType() == MouseEvent::LEFT_KEY_UP)
         onClick(me);
}

void OnDragListener::onEvent(Event *event) {
   if (MouseEvent *me = dynamic_cast<MouseEvent *>(event))
      if (me->getType() == MouseEvent::DRAG)
         onDrag(me);
}

void OnKeyUpListener::onEvent(Event *event){
   if(KeyboardEvent* ke = dynamic_cast<KeyboardEvent*>(event)){
      onKeyUp(ke);
   }
}

void OnMoveListener::onEvent(Event *event) {
   if (MouseEvent *me = dynamic_cast<MouseEvent *>(event))
      if (me->getType() == MouseEvent::MOVE)
         onMove(me);
}

void OnPressListener::onEvent(Event *event) {
   if (MouseEvent *me = dynamic_cast<MouseEvent *>(event))
      if (me->getType() == MouseEvent::LEFT_KEY_DOWN)
         onPress(me);
}