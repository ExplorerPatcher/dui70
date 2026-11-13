#pragma once

namespace DuiBehaviorFilters
{

enum Flags
{
	None = 0x0,
	Hosted = 0x1,
	UnHosted = 0x2,
	PropertyChanging = 0x4,
	PropertyChanged = 0x8,
	Input = 0x10,
	KeyFocusMoved = 0x20,
	Events = 0x40,
	Layout = 0x80,
	Paint = 0x100,
	GetAdjacent = 0x200,
	DisplayNodeCallback = 0x400,
};

}

DEFINE_ENUM_FLAG_OPERATORS(DuiBehaviorFilters::Flags);

DECLARE_INTERFACE_IID_(IDuiBehavior, IUnknown, "70650A6D-8987-4D93-9B1D-ACEB9D92F485")
{
	STDMETHOD(Init)(DirectUI::Value* pvArgs) PURE;
	STDMETHOD(GetCallbackFilters)(DuiBehaviorFilters::Flags* pFilters) PURE;
	STDMETHOD(OnAttach)(DirectUI::Element* pe) PURE;
	STDMETHOD(OnDetach)(DirectUI::Element* pe) PURE;
	STDMETHOD(OnHosted)(DirectUI::Element* peFrom, DirectUI::Element* pe) PURE;
	STDMETHOD(OnUnHosted)(DirectUI::Element* peFrom, DirectUI::Element* peOldHost) PURE;
	STDMETHOD(OnPropertyChanging)(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew, BOOL* pfAllowProcess) PURE;
	STDMETHOD(OnPropertyChanged)(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) PURE;
	STDMETHOD(OnInput)(DirectUI::Element* peFrom, DirectUI::InputEvent* pInput) PURE;
	STDMETHOD(OnKeyFocusMoved)(DirectUI::Element* peFrom, DirectUI::Element* peOld, DirectUI::Element* peNew) PURE;
	STDMETHOD(OnEvent)(DirectUI::Element* peFrom, DirectUI::Event* pEvent) PURE;
	STDMETHOD(OnDoLayout)(DirectUI::Element* peFrom, int dWidth, int dHeight) PURE;
	STDMETHOD(OnUpdateDesiredSize)(DirectUI::Element* peFrom, int dConstW, int dConstH, DirectUI::Surface* psrf, SIZE* pszDesired) PURE;
	STDMETHOD(OnPaint)(DirectUI::Element* peFrom, HDC hdc, const RECT* prcGadgetPxl, const RECT* prcInvalidPxl) PURE;
	STDMETHOD(OnGetAdjacent)(DirectUI::Element* peFrom, int iNavDir, const DirectUI::NavReference* pnr, DWORD dwFlags, DirectUI::Element** ppeTo) PURE;
	STDMETHOD(OnDisplayNodeCallback)(DirectUI::Element* peFrom, EventMsg* pGMsg) PURE;
};
