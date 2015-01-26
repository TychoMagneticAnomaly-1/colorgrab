#ifndef MAINFRAME_H
#define MAINFRAME_H
#include "IColorModel.h"
#include "wxcrafter.h"

#include <wx/config.h>
#include <vector>

class MainFrame : public MainFrameBaseClass
{
private:
    wxConfig config;
    bool dragPicker;
    bool capturing;
    wxString format;
	std::vector<IColorModel*> colorModels;
    IColorModel* colorModel;
public:
    MainFrame(wxWindow* parent);
    virtual ~MainFrame();

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    
    void SetColorModel(IColorModel* colorModel);
    void UpdateColorModel();
	 
    wxColour GetColor() const;
	 void SetColor(const wxColor& color, bool updateInputs = true);
	 void SetColorFromMouse();
	 void SetColorFromPixel(wxCoord x, wxCoord y);
	 void UpdateZoomArea();
protected:
    virtual void OnGrabClick(wxCommandEvent& event);
    virtual void OnZoomPanelDown(wxMouseEvent& event);
    virtual void OnZoomPanelMove(wxMouseEvent& event);
    virtual void OnZoomPanelUp(wxMouseEvent& event);
    virtual void OnZoomPanelZoom(wxMouseEvent& event);
    virtual void OnCaptureZoom(wxMouseEvent& event);
    virtual void OnFormatChoose(wxMenuEvent& event);
    virtual void OnFormatClick(wxCommandEvent& event);
    virtual void OnSettingDrag(wxCommandEvent& event);
    virtual void OnSystemColorPicker(wxCommandEvent& event);
    virtual void OnCaptureMove(wxMouseEvent& event);
    virtual void OnCaptureEnd(wxMouseEvent& event);
    virtual void OnCaptureStart(wxMouseEvent& event);
    virtual void OnColorPick(wxColourPickerEvent& event);
    virtual void OnColorChange(wxCommandEvent& event);
    virtual void OnZoomSelect(wxCommandEvent& event);
    virtual void OnSelectColorModel(wxCommandEvent& event);
};
#endif // MAINFRAME_H
