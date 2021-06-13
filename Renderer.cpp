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
  //dc.SetDeviceOrigin(posX + sizeX / 2, posY + sizeY / 2);

  // Drawing test

  std::vector<Segment> segs = m_cfg->getData();

  dc.DrawText(std::to_string(m_cfg->getVx()), wxPoint(20, 20));
  dc.DrawText(std::to_string(m_cfg->getVy()), wxPoint(70, 20));
  dc.DrawText(std::to_string(m_cfg->getVz()), wxPoint(120, 20));

  dc.DrawText(std::to_string(m_cfg->getPx()), wxPoint(20, 40));
  dc.DrawText(std::to_string(m_cfg->getPy()), wxPoint(70, 40));
  dc.DrawText(std::to_string(m_cfg->getPz()), wxPoint(120, 40));

  dc.DrawText(std::to_string(m_cfg->getPos()), wxPoint(20, 60));
  dc.DrawText(std::to_string(m_cfg->getPosX()), wxPoint(20, 80));
  dc.DrawText(std::to_string(m_cfg->getPosY()), wxPoint(40, 80));
  dc.DrawText(std::to_string(m_cfg->getSizeX()), wxPoint(20, 100));
  dc.DrawText(std::to_string(m_cfg->getSizeY()), wxPoint(40, 100));

  switch (c) {
  case 0:
    dc.DrawText(_("0"), wxPoint(30, 120));
    break;
  case 1:
    dc.DrawText(_("1"), wxPoint(30, 140));
    break;
  case 2:
    dc.DrawText(_("2"), wxPoint(30, 160));
    break;
  }

  c = ++c % 3;
}
