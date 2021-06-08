#pragma once
#include "GUI.h"

#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <memory>

class Configurer;

class UIFrame : public MyFrame1 {
public:
	UIFrame(wxWindow* parent) : MyFrame1(parent) {}

	virtual void VelocityXOnText(wxCommandEvent& event) override { };
	virtual void VelocityYOnText(wxCommandEvent& event) override { };
	virtual void VelocityZOnText(wxCommandEvent& event) override { };
	virtual void PlaneXOnText(wxCommandEvent& event) override {};
	virtual void PlaneYOnText(wxCommandEvent& event) override {};
	virtual void PlaneZOnText(wxCommandEvent& event) override {};
	virtual void PrismDataClick(wxCommandEvent& event) override {};
	virtual void SaveAnimationClick(wxCommandEvent& event) override {};
	virtual void PlaneLocationOnScrollChanged(wxScrollEvent& event) override {} ;

	void Redraw(); 
private:
	std::shared_ptr<Configurer> cfg;

};