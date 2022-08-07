// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_ITERABLE_HPP_
#define APP_SRC_MAIN_CPP_COMMON_ITERABLE_HPP_

class Iterable {
public:
  virtual void beforeLoop() = 0;
  virtual void beforeIteration() = 0;
  virtual void afterIteration() = 0;
  virtual void afterLoop() = 0;
  virtual void update(double) = 0;
  virtual void draw() = 0;
  virtual bool isRunning() = 0;
};

#endif // APP_SRC_MAIN_CPP_COMMON_ITERABLE_HPP_
