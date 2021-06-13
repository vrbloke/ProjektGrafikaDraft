#include "Renderer.h"

void Renderer::Render(wxDC* parentDC, int width, int height) {
  wxBufferedDC dc(parentDC);

  // Technical constants

  int sizeX = m_cfg->getSizeX();
  int sizeY = m_cfg->getSizeY();
  int posX = m_cfg->getPosX();
  int posY = m_cfg->getPosY();

  // Model constants

  // DC SETUP

  dc.Clear();
  dc.DestroyClippingRegion();
  dc.SetClippingRegion(posX, posY, sizeX, sizeY);
  dc.SetDeviceOrigin(posX + sizeX / 2, posY + sizeY / 2);

  // Drawing test

  std::vector<Segment> segs = m_cfg->getData();

  switch (c) {
  case 0:
    dc.DrawText(_("0"), wxPoint(20, 20));
    break;
  case 1:
    dc.DrawText(_("1"), wxPoint(20, 40));
    break;
  case 2:
    dc.DrawText(_("2"), wxPoint(20, 60));
    break;
  }

  c = ++c % 3;
}
