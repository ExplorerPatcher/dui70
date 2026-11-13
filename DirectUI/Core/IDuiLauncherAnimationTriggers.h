#pragma once

#include "PVLAnimation.h"

namespace DirectUI
{

struct ElementOffsetPair
{
	Element* peTarget;
	POINT ptOffset;
};

// MIDL_INTERFACE("390E8C35-5643-4FFA-A0CC-BEE64802A534")
MIDL_INTERFACE("A658A77F-0729-4714-BA5F-4CC1BCD5D727")
IDuiLauncherAnimationTriggers : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE TriggerTap(Element* peToTap, UINT uiState, POINT ptContact, UINT uiVersion, DWORD* pdwCookie) = 0;
	virtual HRESULT STDMETHODCALLTYPE TriggerLaunch(Element* peToLaunch, ElementList* pelUnk, DWORD* pdwCookie) = 0;
	virtual HRESULT STDMETHODCALLTYPE TriggerDrag(Element* peToDrag, ElementList* pelRemaining, Element* peContent, Element* peAdornment, DynamicArray<ClipRectWithElement*>* pTowerClippingRects, UINT uiState, POINT ptContact, DWORD* pdwCookie) = 0;
	virtual HRESULT STDMETHODCALLTYPE TriggerDrop(Element* peToDrop, ElementList* pelRemaining, Element* peContent, Element* peAdornment, DynamicArray<ClipRectWithElement*>* pTowerClippingRects, Element* peParent, int nIndex, int nLayoutPos, POINT ptDest, DWORD* pdwCookie) = 0;
	// virtual HRESULT STDMETHODCALLTYPE TriggerSession(UINT uiVersion, UINT uiState, ElementOffsetPair* peopLauncher, ElementList* pelTowers, ElementList* pelGroupHeaders, ElementOffsetPair* peopStartText, ElementOffsetPair* peopUserTileIcon, ElementOffsetPair* peopUserTileText, Element* peLauncherContent, POINT ptTowerOffset, POINT ptGroupHeaderOffset, DWORD* pdwCookie) = 0;
	// virtual HRESULT STDMETHODCALLTYPE TriggerLogin(UINT uiVersion, Element* peLoginUserTile, Element* peLoginUserText, POINT ptOffset, DWORD* pdwCookie) = 0;
	virtual HRESULT STDMETHODCALLTYPE TriggerLogonEntrance(ElementList* pelToEnter, DynamicArray<POINT>* pdaOffsets, DWORD* pdwCookie) = 0;
	virtual HRESULT STDMETHODCALLTYPE TriggerCrossfade(ElementList* pelToFadeOut, ElementList* pelToFadeIn, bool fCloneTransforms, bool fLayoutAlreadySet, bool fDestroy, bool fInplace, DWORD* pdwCookie) = 0;
	virtual HRESULT STDMETHODCALLTYPE AddScale(int nStoryboardId, Element* peToScale, POINTFLOAT ptflOrigin, POINTFLOAT ptflScale, int nOrderNumber, int nCustomDuration) = 0;
};

}