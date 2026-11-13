#pragma once

#include "IDuiBehavior.h"

class IDuiBehaviorImpl : public IDuiBehavior
{
	STDMETHODIMP Init(DirectUI::Value* pvArgs) override;
	STDMETHODIMP OnAttach(DirectUI::Element* pe) override;
	STDMETHODIMP OnDetach(DirectUI::Element* pe) override;
	STDMETHODIMP OnHosted(DirectUI::Element* peFrom, DirectUI::Element* pe) override;
	STDMETHODIMP OnUnHosted(DirectUI::Element* peFrom, DirectUI::Element* peOldHost) override;
	STDMETHODIMP OnPropertyChanging(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew, BOOL* pfAllowProcess) override;
	STDMETHODIMP OnPropertyChanged(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) override;
	STDMETHODIMP OnInput(DirectUI::Element* peFrom, DirectUI::InputEvent* pInput) override;
	STDMETHODIMP OnKeyFocusMoved(DirectUI::Element* peFrom, DirectUI::Element* peOld, DirectUI::Element* peNew) override;
	STDMETHODIMP OnEvent(DirectUI::Element* peFrom, DirectUI::Event* pEvent) override;
	STDMETHODIMP OnDoLayout(DirectUI::Element* peFrom, int dWidth, int dHeight) override;
	STDMETHODIMP OnUpdateDesiredSize(DirectUI::Element* peFrom, int dConstW, int dConstH, DirectUI::Surface* psrf, SIZE* pszDesired) override;
	STDMETHODIMP OnPaint(DirectUI::Element* peFrom, HDC hdc, const RECT* prcGadgetPxl, const RECT* prcInvalidPxl) override;
	STDMETHODIMP OnGetAdjacent(DirectUI::Element* peFrom, int iNavDir, const DirectUI::NavReference* pnr, DWORD dwFlags, DirectUI::Element** ppeTo) override;
	STDMETHODIMP OnDisplayNodeCallback(DirectUI::Element* peFrom, EventMsg* pGMsg) override;
};
