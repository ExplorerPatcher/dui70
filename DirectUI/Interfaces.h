#pragma once

namespace DirectUI
{
	DECLARE_INTERFACE(IElementListener)
	{
		virtual void OnListenerAttach(Element* peFrom) = 0;
		virtual void OnListenerDetach(Element* peFrom) = 0;
		virtual bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) = 0;
		virtual void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) = 0;
		virtual void OnListenedInput(Element* peFrom, InputEvent* pInput) = 0;
		virtual void OnListenedEvent(Element* peFrom, Event* pEvent) = 0;
	};

	DECLARE_INTERFACE(IClassInfo)
	{
		virtual void AddRef() = 0;
		virtual int Release() = 0;
		virtual HRESULT CreateInstance(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) = 0;
		virtual const PropertyInfo* EnumPropertyInfo(UINT nEnum) = 0;
		virtual const PropertyInfo* GetByClassIndex(UINT iIndex) = 0;
		virtual UINT GetPICount() const = 0;
		virtual UINT GetGlobalIndex() const = 0;
		virtual IClassInfo* GetBaseClass() = 0;
		virtual const WCHAR* GetName() const = 0;
		virtual bool IsValidProperty(const PropertyInfo* ppi) const = 0;
		virtual bool IsSubclassOf(IClassInfo* pci) const = 0;
		virtual void Destroy() = 0;
		virtual HMODULE GetModule() const = 0;
		virtual bool IsGlobal() const = 0;
		virtual void AddChild() = 0;
		virtual void RemoveChild() = 0;
		virtual int GetChildren() const = 0;
		virtual void AssertPIZeroRef() const = 0;
	};

	class UILIB_API IProvider
	{
	public:
		virtual PfnCreateProxy GetProxyCreator() = 0;
	};
	
	class UILIB_API IXProviderCP
	{
	public:
		virtual HRESULT CreateDUICP(class HWNDElement*, HWND, HWND, Element**, class DUIXmlParser**) = 0;
		virtual HRESULT CreateParserCP(DUIXmlParser**) = 0;
		virtual void DestroyCP() = 0;
	};

	class UILIB_API IXElementCP
	{
	public:
		virtual HWND GetNotificationSinkHWND() = 0;
		virtual UINT GetCreationFlags() = 0;
	};
}

class CSafeElementListenerCB : public DirectUI::IElementListener
{
public:
	void OnListenerAttach(DirectUI::Element* peFrom) override {}
	void OnListenerDetach(DirectUI::Element* peFrom) override {}
	bool OnListenedPropertyChanging(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) override { return true; }
	void OnListenedPropertyChanged(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) override {}
	void OnListenedInput(DirectUI::Element* peFrom, DirectUI::InputEvent* pInput) override {}
	void OnListenedEvent(DirectUI::Element* peFrom, DirectUI::Event* pEvent) override {}
};

namespace DirectUI
{
	struct UILIB_API NavReference
	{
		void Init(Element* pe, RECT* prc);

		UINT cbSize;
		Element* pe;
		RECT* prc;
	};
}