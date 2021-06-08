#pragma once
#include "UIFrame.h"

class Configurer {
private:
  // WskaŸnik do g³ównego okna programu.
  UIFrame* MainFrame;
  // Wspó³rzêdne wektora prêdkoœci.
  float vx, vy, vz;
  // Wspó³rzêdne wektora normalnego p³aszczyzny.
  float px, py, pz;
  // Po³o¿enie p³aszczyzny wzd³u¿ kierunku wektora normalnego (do animacji).
  float pos;
public:
  Configurer(UIFrame* parent);

  void setVx(float _vx) { vx = _vx; }
  float getVx() { return vx; }
  void setVy(float _vy) { vy = _vy; }
  float getVy() { return vy; }
  void setVz(float _vz) { vz = _vz; }
  float getVz() { return vz; }
  void setPx(float _px) { px = _px; }
  float getPx() { return px; }
  void setPy(float _py) { py = _py; }
  float getPy() { return py; }
  void setPz(float _pz) { pz = pz; }
  float getPz() { return pz; }

  void startAnimation();

  void loadPrism(const char* filename) const;
  void saveAnimation(const char* filename) const;
};