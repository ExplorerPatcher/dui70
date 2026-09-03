#pragma once

namespace DirectUI
{

template <typename T>
IClassInfo* WINAPI GetElementClass()
{
	__if_exists(T::Class)
	{
		return T::Class;
	}
	__if_not_exists(T::Class)
	{
		return T::GetClassInfoPtr();
	}
}

template <typename T>
void WINAPI SetElementClass(IClassInfo* pClass)
{
	__if_exists(T::Class)
	{
		T::Class = pClass;
	}
	__if_not_exists(T::Class)
	{
		T::SetClassInfoPtr(pClass);
	}
}

}

#define DEFINE_CLASSINFO() \
    static ::DirectUI::IClassInfo *Class; \
    virtual ::DirectUI::IClassInfo *GetClassInfoW() { return Class; }

#define IMPLEMENT_CLASSINFO(c) \
    ::DirectUI::IClassInfo *c::Class

namespace DirectUI
{
	class UILIB_API ClassInfoBase : public IClassInfo
	{
		class Impl
		{
		};

		Impl* _pImpl;

	public:
		ClassInfoBase();
		ClassInfoBase(const ClassInfoBase&) = default;

		virtual ~ClassInfoBase();

		HRESULT Initialize(HINSTANCE hModule, const WCHAR* pszName, bool fGlobal, const PropertyInfo* const* ppPI, UINT cPI);
		HRESULT Register();

		static bool ClassExist(IClassInfo** ppCI, const PropertyInfo* const* ppPI, UINT cPI, IClassInfo* pCIBase, HMODULE hModule, const WCHAR* pszName, bool fGlobal);

		//~ Begin DirectUI::IClassInfo Interface
		void AddRef() override;
		int Release() override;
		const PropertyInfo* EnumPropertyInfo(UINT nEnum) override;
		const PropertyInfo* GetByClassIndex(UINT iIndex) override;
		UINT GetPICount() const override;
		UINT GetGlobalIndex() const override;
		const WCHAR* GetName() const override;
		bool IsValidProperty(const PropertyInfo* ppi) const override;
		bool IsSubclassOf(IClassInfo* pci) const override;
		void Destroy() override;
		HINSTANCE GetModule() const override;
		bool IsGlobal() const override;
		void AddChild() override;
		void RemoveChild() override;
		int GetChildren() const override;
		void AssertPIZeroRef() const override;
		//~ End DirectUI::IClassInfo Interface
	};

	template <typename T>
	class StandardCreator
	{
	public:
		static HRESULT CreateInstance(Element* pElement, DWORD* pdwFlags, Element** ppElement)
		{
			return T::Create(pElement, pdwFlags, ppElement);
		}
	};

	template <typename T>
	class EmptyCreator
	{
	public:
		static HRESULT CreateInstance(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement)
		{
			DUI_ASSERT("Cannot instantiate this type via parser. Must use substitution.");
			return E_NOTIMPL;
		}
	};

	template <typename TClass, typename TBaseClass, typename TCreator = StandardCreator<TClass>>
	class ClassInfo : public ClassInfoBase
	{
		static HRESULT Create(HMODULE hModule, const WCHAR* pszName, bool fGlobal, const PropertyInfo* const* ppPI, UINT cPI, ClassInfo** ppCI)
		{
			*ppCI = nullptr;

			ClassInfo* pCI = DirectUI::HNew<ClassInfo>();
			HRESULT hr = pCI ? S_OK : E_OUTOFMEMORY;
			if (SUCCEEDED(hr))
			{
				hr = pCI->Initialize(hModule, pszName, fGlobal, ppPI, cPI);
				if (SUCCEEDED(hr))
				{
					*ppCI = pCI;
				}
				else
				{
					HDelete(pCI);
				}
			}
			return hr;
		}

		static HRESULT Register(HMODULE hModule, const WCHAR* pszName, const PropertyInfo* const* ppPI, UINT cPI, bool fGlobal)
		{
			HRESULT hr = S_OK;

			if (GetElementClass<TBaseClass>())
			{
				GetElementClass<TBaseClass>()->AddRef();
			}
			else
			{
				hr = TBaseClass::Register();
			}

			if (SUCCEEDED(hr))
			{
				CritSecLock lock(Element::GetFactoryLock());

				IClassInfo* pCI;
				if (ClassExist(&pCI, ppPI, cPI, GetElementClass<TBaseClass>(), hModule, pszName, fGlobal))
				{
					SetElementClass<TClass>(pCI);
					hr = S_OK;
				}
				else
				{
					SetElementClass<TClass>(nullptr);

					hr = Create(hModule, pszName, fGlobal, ppPI, cPI, &pCI);
					if (SUCCEEDED(hr))
					{
						hr = static_cast<ClassInfoBase*>(pCI)->Register();
						if (SUCCEEDED(hr))
						{
							SetElementClass<TClass>(pCI);
						}
						else
						{
							pCI->Destroy();
						}
					}
				}
			}

			return hr;
		}

	public:
		static HRESULT Register(const WCHAR* pszName, const PropertyInfo* const* ppPI, UINT cPI)
		{
			return Register(HINST_DUIDLL, pszName, ppPI, cPI, false);
		}

		static HRESULT RegisterGlobal(HMODULE hModule, const WCHAR* pszName, const PropertyInfo* const* ppPI, UINT cPI)
		{
			return Register(hModule, pszName, ppPI, cPI, true);
		}

		HRESULT CreateInstance(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) override
		{
			return TCreator::CreateInstance(pParent, pdwDeferCookie, ppElement);
		}

		IClassInfo* GetBaseClass() override
		{
			return GetElementClass<TBaseClass>();
		}

		void Destroy() override
		{
			HDelete(this);
			SetElementClass<TClass>(nullptr);
		}
	};

	template <typename T>
	HRESULT CreateAndInit(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement)
	{
		*ppElement = nullptr;
		T* pT = HNew<T>();
		HRESULT hr = pT ? S_OK : E_OUTOFMEMORY;
		if (SUCCEEDED(hr))
		{
			hr = pT->Initialize(pParent, pdwDeferCookie);
			if (SUCCEEDED(hr))
			{
				*ppElement = pT;
			}
			else
			{
				pT->Destroy(false);
			}
		}
		return hr;
	}

	template <typename T, typename A1T>
	HRESULT CreateAndInit(A1T arg1, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement)
	{
		*ppElement = nullptr;
		T* pT = HNew<T>();
		HRESULT hr = pT ? S_OK : E_OUTOFMEMORY;
		if (SUCCEEDED(hr))
		{
			hr = pT->Initialize(arg1, pParent, pdwDeferCookie);
			if (SUCCEEDED(hr))
			{
				*ppElement = pT;
			}
			else
			{
				pT->Destroy(false);
			}
		}
		return hr;
	}

	template <typename T, typename A1T, typename A2T>
	HRESULT CreateAndInit(A1T arg1, A2T arg2, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement)
	{
		*ppElement = nullptr;
		T* pT = HNew<T>();
		HRESULT hr = pT ? S_OK : E_OUTOFMEMORY;
		if (SUCCEEDED(hr))
		{
			hr = pT->Initialize(arg1, arg2, pParent, pdwDeferCookie);
			if (SUCCEEDED(hr))
			{
				*ppElement = pT;
			}
			else
			{
				pT->Destroy(false);
			}
		}
		return hr;
	}

	template <typename T, typename A1T, typename A2T, typename A3T>
	HRESULT CreateAndInit(A1T arg1, A2T arg2, A3T arg3, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement)
	{
		*ppElement = nullptr;
		T* pT = HNew<T>();
		HRESULT hr = pT ? S_OK : E_OUTOFMEMORY;
		if (SUCCEEDED(hr))
		{
			hr = pT->Initialize(arg1, arg2, arg3, pParent, pdwDeferCookie);
			if (SUCCEEDED(hr))
			{
				*ppElement = pT;
			}
			else
			{
				pT->Destroy(false);
			}
		}
		return hr;
	}
}

template <typename T>
BOOL IsSubclassOf(DirectUI::Element* pe)
{
	return pe->GetClassInfoW()->IsSubclassOf(DirectUI::GetElementClass<T>()); // @Note: bool -> BOOL, no != 0
}

template <typename T>
T* element_cast(DirectUI::Element* pe)
{
	T* p = nullptr;
	if (pe && IsSubclassOf<T>(pe))
	{
		p = (T*)pe;
	}
	return p;
}

template <typename T>
HRESULT ElementCast(DirectUI::Element* pe, T** ppT)
{
	*ppT = element_cast<T>(pe);
	return *ppT ? S_OK : E_FAIL;
}

template <typename T>
T* element_interface_cast(DirectUI::Element* pe)
{
	T* p = nullptr;
	return pe && SUCCEEDED(pe->QueryInterface(__uuidof(*p), (void**)&p)) ? p : nullptr;
}

template <typename T>
BOOL IsClassOf(DirectUI::Element* pe)
{
	return pe->GetClassInfoW() == DirectUI::GetElementClass<T>();
}
