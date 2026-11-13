#pragma once

interface IDuiBehavior;

MIDL_INTERFACE("230aa8d1-9b2e-4074-8880-6a7f6125dccb")
IDuiBehaviorFactory : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE CreateBehavior(const WCHAR*, IDuiBehavior**) = 0;
};
