#pragma once

namespace DirectUI
{
	class DECLSPEC_UUID("751ef5ec-0791-440d-bfaf-d5dd8ae60b63")
	BehaviorEngine;
}

MIDL_INTERFACE("11322f06-9f1e-48c6-8d47-20398011a462")
IDuiBehaviorEngine : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE RegisterBehaviorFactory(const WCHAR* pwzNamespace, IDuiBehaviorFactory* pFactory) = 0;
	virtual HRESULT STDMETHODCALLTYPE UnregisterBehaviorFactory(const WCHAR* pwzNamespace, IDuiBehaviorFactory* pFactory) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateBehavior(const WCHAR* pwzNamespace, const WCHAR* pwzName, DirectUI::Value* pvArgs, IDuiBehavior** ppBehavior) = 0;
};
