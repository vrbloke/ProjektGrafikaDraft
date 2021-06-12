#pragma once

#define DEFAULT_BLUE

#include <vector>

class UIFrame;

struct Point {
  float x, y, z;
  Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
  Point() : x(0), y(0), z(0) {}
};

struct Color {
  int r, g, b;
  Color(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {}
#ifdef DEFAULT_BLUE
  Color() : r(0), g(0), b(255) {}
#endif //default blue
#ifndef DEFAULT_BLUE
  Color() : r(0), g(0), b(0) {}
#endif
};

typedef Color Colour;

struct Segment {
  Point begin, end;
  Color color;
  Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
  Segment(Point _begin, Point _end) : begin(_begin), end(_end), color(Color(0,0,255)) {}
  Segment() : begin(Point()), end(Point()), color(Color(0, 0, 255)) {}
};

class Configurer {
private:
  // WskaŸnik do g³ównego okna programu.
  UIFrame* m_mainFrame;
  std::vector<Segment> m_prismData;
  // Wspó³rzêdne wektora prêdkoœci.
  float m_vx, m_vy, m_vz;
  // Wspó³rzêdne wektora normalnego p³aszczyzny.
  float m_px, m_py, m_pz;
  // Po³o¿enie p³aszczyzny wzd³u¿ kierunku wektora normalnego (do animacji).
  float m_pos;
public:
  Configurer(UIFrame* parent) :
    m_vx(0), m_vy(0), m_vz(0),
    m_px(0), m_py(0), m_pz(0),
    m_pos(0),
    m_mainFrame(parent)
  {}

  void setVx(float _vx) { m_vx = _vx; }
  float getVx() const { return m_vx; }
  void setVy(float _vy) { m_vy = _vy; }
  float getVy() const  { return m_vy; }
  void setVz(float _vz) { m_vz = _vz; }
  float getVz() const { return m_vz; }
  void setPx(float _px) { m_px = _px; }
  float getPx() const { return m_px; }
  void setPy(float _py) { m_py = _py; }
  float getPy() const { return m_py; }
  void setPz(float _pz) { m_pz = m_pz; }
  float getPz() const { return m_pz; }
  void setPos(float _pos) { m_pos = _pos; }
  float getPos() const { return m_pos; }
  std::vector<Segment>& getData() { return m_prismData; }
  void setData(std::vector<Segment>& _data) { m_prismData = _data; }

  void startAnimation();

  void loadPrism(const char* filename) const;
  void saveAnimation(const char* filename) const;
};