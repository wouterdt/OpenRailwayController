///////////////////////////////////////////////////////////////////////////// C++ code generated with wxFormBuilder (version Sep 12 2010)// http://www.wxformbuilder.org///// PLEASE DO "NOT" EDIT THIS FILE!///////////////////////////////////////////////////////////////////////////#ifndef __weatherdlggen__#define __weatherdlggen__#include <wx/string.h>#include <wx/listbox.h>#include <wx/gdicmn.h>#include <wx/font.h>#include <wx/colour.h>#include <wx/settings.h>#include <wx/stattext.h>#include <wx/textctrl.h>#include <wx/sizer.h>#include <wx/button.h>#include <wx/panel.h>#include <wx/bitmap.h>#include <wx/image.h>#include <wx/icon.h>#include <wx/spinctrl.h>#include <wx/checkbox.h>#include <wx/statbox.h>#include <wx/combobox.h>#include <wx/notebook.h>#include <wx/dialog.h>///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Class WeatherDlgGen///////////////////////////////////////////////////////////////////////////////class WeatherDlgGen : public wxDialog {	private:		protected:		wxNotebook* m_WeatherBook;		wxPanel* m_IndexPanel;		wxListBox* m_IndexList;		wxStaticText* m_labID;		wxTextCtrl* m_ID;		wxButton* m_AddWeather;		wxButton* m_DeleteWeather;		wxButton* m_ActivateWeather;		wxPanel* m_DayPanel;		wxStaticText* m_labOutputs;		wxTextCtrl* m_Outputs;		wxStaticText* m_labMaxBri;		wxSpinCtrl* m_MaxBri;		wxStaticText* m_labMinBri;		wxSpinCtrl* m_MinBri;		wxStaticText* m_labColorSliding;		wxSpinCtrl* m_ColorSliding;		wxStaticText* m_labNightSliding;		wxSpinCtrl* m_NightSliding;		wxCheckBox* m_SlidingDaylight;		wxCheckBox* m_RelativeTime;		wxStaticBoxSizer* m_SunriseBox;		wxStaticText* m_labSunriseTime;		wxSpinCtrl* m_SunriseHour;		wxStaticText* m_staticText5;		wxSpinCtrl* m_SunriseMin;		wxStaticText* m_labRGBSunrise;		wxSpinCtrl* m_SunriseRed;		wxSpinCtrl* m_SunriseGreen;		wxSpinCtrl* m_SunriseBlue;		wxStaticBoxSizer* m_NoonBox;		wxStaticText* m_labNoonTime;		wxSpinCtrl* m_NoonHour;		wxStaticText* m_staticText52;		wxSpinCtrl* m_NoonMin;		wxStaticText* m_labRGBNoon;		wxSpinCtrl* m_NoonRed;		wxSpinCtrl* m_NoonGreen;		wxSpinCtrl* m_NoonBlue;		wxStaticBoxSizer* m_SunsetBox;		wxStaticText* m_labSunsetTime;		wxSpinCtrl* m_SunsetHour;		wxStaticText* m_staticText51;		wxSpinCtrl* m_SunsetMin;		wxStaticText* m_labRGBSunset;		wxSpinCtrl* m_SunsetRed;		wxSpinCtrl* m_SunsetGreen;		wxSpinCtrl* m_SunsetBlue;		wxPanel* m_NightPanel;		wxStaticText* m_labOutputsNight;		wxTextCtrl* m_OutputsNight;		wxStaticText* m_labBrightnessNight;		wxSpinCtrl* m_BrightnessNight;		wxStaticText* m_labRGBNight;		wxSpinCtrl* m_RedNight;		wxSpinCtrl* m_GreenNight;		wxSpinCtrl* m_BlueNight;		wxPanel* m_ThemePanel;		wxListBox* m_ThemeList;		wxButton* m_ThemeAdd;		wxButton* m_ThemeModify;		wxButton* m_ThemeDelete;		wxStaticText* m_labThemeID;		wxTextCtrl* m_ThemeID;		wxStaticText* m_labThemeOutputs;		wxTextCtrl* m_ThemeOutputs;		wxStaticText* m_labThemeSound;		wxTextCtrl* m_ThemeSound;		wxSpinCtrl* m_ThemeSoundRandomRate;		wxComboBox* m_SoundOutput;		wxStaticText* m_labThemeDim;		wxSpinCtrl* m_ThemeDim;		wxStaticText* m_labThemeDimPercent;		wxStaticText* m_labThemeTime;		wxSpinCtrl* m_ThemeHour;		wxStaticText* m_labThemeTimeSep;		wxSpinCtrl* m_ThemeMinute;		wxStaticText* m_labThemeDuration;		wxSpinCtrl* m_ThemeDuration;		wxStaticText* m_labThemeDurationMinutes;		wxStaticText* m_labThemeRandom;		wxCheckBox* m_ThemeRandom;		wxStdDialogButtonSizer* m_StdButtons;		wxButton* m_StdButtonsOK;		wxButton* m_StdButtonsApply;		wxButton* m_StdButtonsCancel;		wxButton* m_StdButtonsHelp;				// Virtual event handlers, overide them in your derived class		virtual void onIndexList( wxCommandEvent& event ) { event.Skip(); }		virtual void onAddWeather( wxCommandEvent& event ) { event.Skip(); }		virtual void onDeleteWeather( wxCommandEvent& event ) { event.Skip(); }		virtual void onActivateWeather( wxCommandEvent& event ) { event.Skip(); }		virtual void onThemeSelected( wxCommandEvent& event ) { event.Skip(); }		virtual void onThemeAdd( wxCommandEvent& event ) { event.Skip(); }		virtual void onThemeModify( wxCommandEvent& event ) { event.Skip(); }		virtual void onThemeDelete( wxCommandEvent& event ) { event.Skip(); }		virtual void onApply( wxCommandEvent& event ) { event.Skip(); }		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }				public:				WeatherDlgGen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Weather"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );		~WeatherDlgGen();	};#endif //__weatherdlggen__