#pragma once

namespace DirectUI
{

inline void* HAlloc(SIZE_T s)
{
	return HeapAlloc(GetProcessHeap(), 0, s);
}

inline void* HAllocArray(UINT cItems, UINT cbItem)
{
	void* pv = NULL;

	UINT cbToAlloc;
	if (SUCCEEDED(UIntMult(cbItem, cItems, &cbToAlloc)))
	{
		pv = HAlloc(cbToAlloc);
	}

	return pv;
}

inline void* HAllocAndZero(SIZE_T s)
{
	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, s);
}

inline void* HReAlloc(void* p, SIZE_T s)
{
	return HeapReAlloc(GetProcessHeap(), 0, p, s);
}

inline void* HReAllocAndZero(void* p, SIZE_T s)
{
	return HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, p, s);
}

inline void HFree(void* p)
{
	HeapFree(GetProcessHeap(), 0, p);
}

template <typename T>
T* HNew()
{
	T* p = (T*)HAllocAndZero(sizeof(T));
	if (p)
		new(p) T();

	return p;
}

template <typename T>
T* HNewAndZero()
{
	T* p = (T*)HAllocAndZero(sizeof(T));
	if (p)
		new (p) T();

	return p;
}

template <typename T>
void HDelete(T* p)
{
	p->~T();
	HFree(p);
}

inline void* AccHAlloc(SIZE_T s) // Assumed
{
	return HeapAlloc(GetProcessHeap(), 0, s);
}

inline void* AccHAllocAndZero(SIZE_T s)
{
	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, s);
}

template <typename T>
T* AccHNew()
{
	T* p = (T*)AccHAllocAndZero(sizeof(T));
	if (p)
	{
		new(p) T();
	}

	return p;
}

template <typename T, typename T1>
T* AccHNew(const T1& p1)
{
	T* p = (T*)AccHAllocAndZero(sizeof(T));
	if (p)
	{
		new(p) T(p1);
	}

	return p;
}

inline void AccHFree(void* p)
{
	HeapFree(GetProcessHeap(), 0, p);
}

template <typename T>
void AccHDelete(T* p)
{
	p->~T();
	AccHFree(p);
}

}
