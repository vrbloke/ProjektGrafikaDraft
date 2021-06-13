#include "Configurer.h"

#include <fstream>

void Configurer::loadPrism(const char* filename) {
  double x1, y1, z1, x2, y2, z2;
  int r, g, b;

  std::ifstream in(filename);
  if (in.is_open())
  {
    m_prismData.clear();
    while (!in.eof())
    {
      in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b;
      m_prismData.push_back(Segment(Point(x1, y1, z1), Point(x2, y2, z2), Color(r, g, b)));
    }
    in.close();
  }
}
