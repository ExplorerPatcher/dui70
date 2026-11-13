#pragma once

DECLARE_INTERFACE_IID_(ITouchTooltipEventSink, IUnknown, "2D97ED04-C05F-4302-9462-8A9EC79F1464")
{
	STDMETHOD(OnTooltipTimerFired)(DirectUI::TOUCHTOOLTIP_INPUT touchTooltipInput, DirectUI::TOUCHTOOLTIP_TYPE touchTooltipType, DirectUI::TOUCHTOOLTIP_DELAY touchTooltipDelay) PURE;
	STDMETHOD(OnTooltipHidden)() PURE;
};

MIDL_INTERFACE("13450B2E-1819-49A5-B997-800D02CC0980")
ITouchTooltip : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE SetText(const WCHAR* pszText) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetTextWithMaxLines(const WCHAR* pszText, UINT cLinesMax) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetRichTooltip(DirectUI::Element* pe) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetOptions(DirectUI::TOUCHTOOLTIP_OPTION_FLAGS* ptouchTooltipOptionFlags) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOptions(DirectUI::TOUCHTOOLTIP_OPTION_FLAGS touchTooltipOptionFlags) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetDirection(DirectUI::TOUCHTOOLTIP_LAYOUT_DIRECTION touchTooltipLayoutDirection) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetProgrammaticOffset(int cRPOffset) = 0;
	virtual HRESULT STDMETHODCALLTYPE StartShowTimer(DirectUI::TOUCHTOOLTIP_INPUT touchTooltipInput, DirectUI::TOUCHTOOLTIP_TYPE touchTooltipType) = 0;
	virtual HRESULT STDMETHODCALLTYPE Show(DirectUI::TOUCHTOOLTIP_INPUT touchTooltipInput, const RECT* prcTool, DirectUI::TOUCHTOOLTIP_PLACEMENT touchTooltipPlacementPreferred) = 0;
	virtual HRESULT STDMETHODCALLTYPE ShowNearTouchPoint(const POINT* pptTouch, DirectUI::TOUCHTOOLTIP_PLACEMENT touchTooltipPlacementPreferred) = 0;
	virtual HRESULT STDMETHODCALLTYPE ShowNearMousePoint(const POINT* pptMouse, DirectUI::TOUCHTOOLTIP_PLACEMENT touchTooltipPlacementPreferred) = 0;
	virtual HRESULT STDMETHODCALLTYPE Hide() = 0;
	virtual HRESULT STDMETHODCALLTYPE IsVisible() = 0;
	virtual HRESULT STDMETHODCALLTYPE Advise(ITouchTooltipEventSink* pEventSink) = 0;
	virtual HRESULT STDMETHODCALLTYPE Unadvise() = 0;
};

namespace DirectUI
{
	class TouchTooltip
	{
	};
}
