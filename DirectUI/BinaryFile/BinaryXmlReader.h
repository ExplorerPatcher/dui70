#pragma once

namespace DirectUI
{

MIDL_INTERFACE("B97EE329-6B9C-471F-A52A-3F99D814F17A")
IDuiParserCache : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE Find(ULONG key, DirectUI::IClassInfo** ppClassInfo) = 0;
	virtual HRESULT STDMETHODCALLTYPE Find(ULONG key, DirectUI::Value** ppValue) = 0;
	virtual HRESULT STDMETHODCALLTYPE Store(ULONG key, DirectUI::IClassInfo* pClassInfo) = 0;
	virtual HRESULT STDMETHODCALLTYPE Store(ULONG key, DirectUI::Value* pValue) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateLayout(ULONG key, DirectUI::Value** ppValue) = 0;
	virtual HRESULT STDMETHODCALLTYPE AddLayout(ULONG key, HRESULT (*)(int, int*, DirectUI::Value**), int cargs, int* pargs) = 0; // TODO: Figure out the typedef of this function
	virtual HRESULT STDMETHODCALLTYPE ClearStoredClasses() = 0;
};

DECLARE_INTERFACE_IID_(IDuiBinaryReader, IUnknown, "C1F02EF9-E2EB-47B2-BF2C-EEF7449FC1F6")
{
	virtual HRESULT STDMETHODCALLTYPE GetResource(UINT index, LPCWSTR* ppszResid) = 0;
	virtual HRESULT STDMETHODCALLTYPE SeekToResource(LPCWSTR pszResid) = 0;
	virtual HRESULT STDMETHODCALLTYPE PushState() = 0;
	virtual HRESULT STDMETHODCALLTYPE PopState() = 0;
};

}