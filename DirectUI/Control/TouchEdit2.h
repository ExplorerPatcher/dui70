#pragma once

#include <Richedit.h>
#include <TOM.h>
#include <TextServ.h>

namespace DirectUI
{
	struct PasteEvent : Event
	{
		LPCWSTR pszPasteText;
	};

	enum TouchEditTextMode
	{
		TETM_PlainText = 0,
		TETM_RichTextFormat = 1
	};

	enum TouchEditPasswordRevealMode
	{
		TEPRM_Normal = 0,
		TEPRM_Disabled = 1
	};

	enum TouchEditFilteredKeyComboFlags
	{
		TEFKCF_None = 0x0,
		TEFKCF_Ctrl_C = 0x1,
		TEFKCF_Ctrl_V = 0x2,
		TEFKCF_Ctrl_X = 0x4,
		TEFKCF_Shift_Ins = 0x8,
		TEFKCF_Ctrl_Ins = 0x10,
		TEFKCF_Ctrl_Del = 0x20,
		TEFKCF_Copy = TEFKCF_Ctrl_C | TEFKCF_Ctrl_Ins,
		TEFKCF_Cut = TEFKCF_Ctrl_X | TEFKCF_Ctrl_Del,
		TEFKCF_Paste = TEFKCF_Ctrl_V | TEFKCF_Shift_Ins
	};

	enum TouchEditKeyboardNavigationCapture
	{
		TEKNC_Default = 0,
		TEKNC_None = 1
	};

	class TouchEditBase : public Element
	{
	public:
		UILIB_API static UID WINAPI Enter();
		UILIB_API static UID WINAPI Paste();
		UILIB_API static UID WINAPI Cut();
		UILIB_API static UID WINAPI CaretMoved();
		UILIB_API static UID WINAPI UserTextChanged();
		UILIB_API static UID WINAPI UserTextUpdateNoChange();

		UILIB_API static const PropertyInfo* WINAPI PasswordCharacterProp();
		UILIB_API int GetPasswordCharacter();
		UILIB_API HRESULT SetPasswordCharacter(int v);

		UILIB_API static const PropertyInfo* WINAPI MaxLengthProp();
		UILIB_API int GetMaxLength();
		UILIB_API HRESULT SetMaxLength(int v);

		UILIB_API static const PropertyInfo* WINAPI MultilineProp();
		UILIB_API bool GetMultiline();
		UILIB_API HRESULT SetMultiline(bool v);

		UILIB_API static const PropertyInfo* WINAPI ReadOnlyProp();
		UILIB_API bool GetReadOnly();
		UILIB_API HRESULT SetReadOnly(bool v);

		UILIB_API static const PropertyInfo* WINAPI TextModeProp();
		UILIB_API TouchEditTextMode GetTextMode();
		UILIB_API HRESULT SetTextMode(TouchEditTextMode v);

		UILIB_API static const PropertyInfo* WINAPI SelectionForegroundColorProp();
		UILIB_API Value* GetSelectionForegroundColor();
		UILIB_API HRESULT SetSelectionForegroundColor(Value* v);

		UILIB_API static const PropertyInfo* WINAPI SelectionBackgroundColorProp();
		UILIB_API Value* GetSelectionBackgroundColor();
		UILIB_API HRESULT SetSelectionBackgroundColor(Value* v);

		UILIB_API static const PropertyInfo* WINAPI IgnoredKeyCombosProp();
		UILIB_API TouchEditFilteredKeyComboFlags GetIgnoredKeyCombos();
		UILIB_API HRESULT SetIgnoredKeyCombos(TouchEditFilteredKeyComboFlags v, TouchEditFilteredKeyComboFlags vmask);

		UILIB_API static const PropertyInfo* WINAPI KeyboardNavigationCaptureProp();
		UILIB_API TouchEditKeyboardNavigationCapture GetKeyboardNavigationCapture();
		UILIB_API HRESULT SetKeyboardNavigationCapture(TouchEditKeyboardNavigationCapture v);

		UILIB_API static const PropertyInfo* WINAPI IMEComposingProp();
		UILIB_API bool GetIMEComposing();
		UILIB_API HRESULT SetIMEComposing(bool v);

		UILIB_API static const PropertyInfo* WINAPI SyncContentWhileIMEComposingProp();
		UILIB_API bool GetSyncContentWhileIMEComposing();
		UILIB_API HRESULT SetSyncContentWhileIMEComposing(bool v);

		UILIB_API static const PropertyInfo* WINAPI ElementMovesOnIHMNotifyProp();
		UILIB_API bool GetElementMovesOnIHMNotify();
		UILIB_API HRESULT SetElementMovesOnIHMNotify(bool v);

		UILIB_API static const PropertyInfo* WINAPI FilterOnPasteProp();
		UILIB_API bool GetFilterOnPaste();
		UILIB_API HRESULT SetFilterOnPaste(bool v);

		UILIB_API static const PropertyInfo* WINAPI MoveCaretToEndOnSyncContentProp();
		UILIB_API bool GetMoveCaretToEndOnSyncContent();
		UILIB_API HRESULT SetMoveCaretToEndOnSyncContent(bool v);

		UILIB_API static const PropertyInfo* WINAPI IntegrateIMECandidateListProp();
		UILIB_API bool GetIntegrateIMECandidateList();
		UILIB_API HRESULT SetIntegrateIMECandidateList(bool v);

		UILIB_API static const PropertyInfo* WINAPI ForceEditTextToLTRProp();
		UILIB_API bool GetForceEditTextToLTR();
		UILIB_API HRESULT SetForceEditTextToLTR(bool v);

		UILIB_API static const PropertyInfo* WINAPI PreventFormatChangeUpdatingModifiedStateProp();
		UILIB_API bool GetPreventFormatChangeUpdatingModifiedState();
		UILIB_API HRESULT SetPreventFormatChangeUpdatingModifiedState(bool v);

		UILIB_API static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		UILIB_API IClassInfo* GetClassInfoW() override;

		UILIB_API static HRESULT WINAPI Register();
		UILIB_API static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		UILIB_API bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		UILIB_API void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		UILIB_API bool IsContentProtected() override;

		UILIB_API const WCHAR* GetContentStringAsDisplayed(Value** ppv) override;

		UILIB_API HRESULT Insert(Element** ppe, UINT cCount, UINT iInsertIdx) override;
		UILIB_API void SetKeyFocus() override;

		UILIB_API virtual HRESULT GetTextDocument(ITextDocument** pptd);
		UILIB_API virtual HRESULT GetTextServices(ITextServices** ppts);
		UILIB_API virtual HRESULT RefreshContent();

		UILIB_API virtual HRESULT FinalizeCurrentIMEComposition();
		UILIB_API virtual HRESULT GetControllerFor(IUnknown**);

		TouchEditBase();
		TouchEditBase(const TouchEditBase&) = default;
		TouchEditBase(TouchEditBase&&) = default;

		enum PasswordReveal
		{
			PR_Show = 0,
			PR_Hide = 1
		};

	protected:
		void _SecureDelete(WCHAR* psz, UINT cch);
		void _SetPasswordReveal(PasswordReveal reveal);
		HRESULT _SaveModified();
		HRESULT _RestoreModified();

		// @Note Added in RS1
		HRESULT _GetEncodedContentString(Value* pv, WCHAR** ppszContent, UINT* pcchBuf);
		HRESULT _GetEncodedContentString(WCHAR** ppszConent, UINT* pcchBuf);

	private:
		PasswordReveal _reveal;
		bool _fSavedModified;
	};

	class TouchEdit2 : public TouchEditBase, IElementListener
	{
	public:
		UILIB_API static UID WINAPI ClearButtonClicked();
		UILIB_API static UID WINAPI ContextMenuRequested();

		UILIB_API static const PropertyInfo* WINAPI PromptTextProp();
		UILIB_API const WCHAR* GetPromptText(Value** ppv);
		UILIB_API HRESULT SetPromptText(const WCHAR* psz);

		UILIB_API static const PropertyInfo* WINAPI PromptWithCaretProp();
		UILIB_API bool GetPromptWithCaret();
		UILIB_API HRESULT SetPromptWithCaret(bool v);

		UILIB_API static const PropertyInfo* WINAPI SuppressClearButtonProp();
		UILIB_API bool GetSuppressClearButton();
		UILIB_API HRESULT SetSuppressClearButton(bool v);

		UILIB_API static const PropertyInfo* WINAPI ShowClearButtonMinWidthProp();
		UILIB_API int GetShowClearButtonMinWidth();
		UILIB_API HRESULT SetShowClearButtonMinWidth(int v);

		UILIB_API static const PropertyInfo* WINAPI PasswordRevealModeProp();
		UILIB_API TouchEditPasswordRevealMode GetPasswordRevealMode();
		UILIB_API HRESULT SetPasswordRevealMode(TouchEditPasswordRevealMode v);

		UILIB_API static const PropertyInfo* WINAPI InnerBorderThicknessProp();
		UILIB_API const RECT* GetInnerBorderThickness(Value** ppv);
		UILIB_API HRESULT SetInnerBorderThickness(int l, int t, int r, int b);

		UILIB_API static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		UILIB_API IClassInfo* GetClassInfoW() override;
		UILIB_API static HRESULT WINAPI Register();
		UILIB_API static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		// ReSharper disable once CppHiddenFunction
		UILIB_API HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

		UILIB_API TouchEdit2();
		TouchEdit2(const TouchEdit2&) = default;
		TouchEdit2(TouchEdit2&&) noexcept = default;

		UILIB_API void OnHosted(Element* peNewHost) override;
		UILIB_API void OnInput(InputEvent* pie) override;
		UILIB_API bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		UILIB_API void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		UILIB_API void OnEvent(Event* pEvent) override;

		UILIB_API void Paint(HDC hdc, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) override;
		UILIB_API HRESULT Add(Element** ppe, UINT cCount) override;

		UILIB_API HRESULT GetAccessibleImpl(IAccessible** ppAccessible) override;
		UILIB_API Element* GetUiaFocusDelegate() override;

		UILIB_API HRESULT GetTextDocument(ITextDocument** pptd) override;
		UILIB_API HRESULT GetTextServices(ITextServices** ppts) override;
		UILIB_API HRESULT RefreshContent() override;
		UILIB_API HRESULT FinalizeCurrentIMEComposition() override;
		UILIB_API HRESULT GetTextHost(ITextHost** ppth);

		UILIB_API HRESULT GetTextSelection(ITextSelection** pptsel);
		UILIB_API HRESULT PasteText(const WCHAR* pszText);

		UILIB_API HRESULT GetSelection(long* piStart, long* pcchSel);
		UILIB_API HRESULT SetSelection(long iStart, long cch);

		UILIB_API HRESULT SetCaretPosition(long iPos);

		UILIB_API InputScope GetInputScope(); // __MIDL___MIDL_itf_inputscope_0000_0000_0001
		UILIB_API HRESULT SetInputScope(InputScope inputscope); // __MIDL___MIDL_itf_inputscope_0000_0000_0001

		UILIB_API bool HasSelection();
		UILIB_API HRESULT SelectAll();
		UILIB_API HRESULT SelectNone();
		UILIB_API void DisableSelectionHandlesOnEmptyContent();

	private:
		void OnListenerAttach(Element* peFrom) override {}
		UILIB_API void OnListenerDetach(Element* peFrom) override;

		bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override { return true; }
		UILIB_API void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		void OnListenedInput(Element* peFrom, InputEvent* pInput) override {}
		void OnListenedEvent(Element* peFrom, Event* pEvent) override {}

		HRESULT _CreateDirectChildren();
		HRESULT _CreateTextElements();
		void _UpdatePrompt();
		void _UpdateButton();
		void _RevealPassword(PasswordReveal);
		bool _IsRevealButtonActive();

		TouchEditInner* _peTouchEditInner;
		PromptText* _pePrompt;
		Element* _peTextContainer;
		TouchButton* _peButton;
		Element* _peExtra;
	};
}
