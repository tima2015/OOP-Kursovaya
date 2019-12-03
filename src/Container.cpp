#include "Container.hpp"
#include "Window.hpp"
#include <iostream>
using namespace std;

Container::Container(){
components = new vector<Component*>();   
}

Container::~Container(){
   for (int i = 0; i < components->size(); i++) {
      delete components->at(i);
   }
   delete components;
}

void Container::notifyAll(Event *event) {
   notify(event);
   if (Window *container = dynamic_cast<Window*>(this))
      if(!container->isSelected())
         return;
   for (int i = 0; i < components->size(); i++) {
      Component* component = components->at(i);
      if (Container *container = dynamic_cast<Container *>(component))
         container->notifyAll(event);
      else
         component->notify(event);
   }
}

void Container::setVisible(bool visible){
   this->visible = visible;
   for (int i = 0; i < components->size(); i++) {
      components->at(i)->setVisible(visible);
   }
}

void Container::renderAll(int rootX, int rootY, int rootWidth, int rootHeight) {
   render(rootX,rootY,rootWidth,rootHeight);
   for (int i = 0; i < components->size(); i++) {
      Component* component = components->at(i);
      if (Container *container = dynamic_cast<Container*>(component)){
         container->renderAll(absolutX, absolutY, width, height);
      }else
         component->render(absolutX, absolutY, width, height);
   }
}

void Container::addComponent(Component* component){
   if(!visible)
      component->setVisible(false);
   components->push_back(component);
}

vector<Component*> *Container::getComponents() const{
   return components;
}