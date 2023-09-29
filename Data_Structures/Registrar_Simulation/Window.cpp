/*
Name: Ruby Link
Student ID: 2392068
Email: rlink@chapman.edu
Class: CPSC_350-03
Assignment: The Waiting Game
*/

#include "Window.h"
//constructor
Window::Window(){
  m_idle = 0;
  m_windowCustomer = NULL;
}
//destructor
Window::~Window(){
}
//returns is a window is open
bool Window::isOpen(){
  return m_windowCustomer == NULL;
}
//gets the idle time
int Window::getIdle(){
  return m_idle;
}
//increases the idle time
void Window::increaseIdle(){
  ++m_idle;
}

