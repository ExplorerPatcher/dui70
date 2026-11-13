#pragma once

namespace DirectUI
{
	struct ElementIndexPair
	{
		Element* pElement;
		UINT uIndex;
	};

	struct SafeElementIndexPair
	{
		CSafeElementPtr<Element> spElement;
		UINT uIndex;
	};

	struct ElementGadgetTicketPair
	{
		HGADGET hgad;
		CSafeElementPtr<Element> speTarget;
		DWORD dwTicket;
	};

	enum PVLANIMATIONSTATE
	{
		PANI_STATE_SELECTDOWN = 1,
		PANI_STATE_SELECTUP = 2,
		PANI_STATE_SELECTREVEAL = 3,
		PANI_STATE_DOWN = 4,
		PANI_STATE_UP = 5,
		PANI_STATE_IN = 6,
		PANI_STATE_OUT = 7,
		PANI_STATE_FULL = 8,
		PANI_STATE_IN_LONG = 9,
		PANI_STATE_OUT_LONG = 10,
		PANI_STATE_OUT_LEAVE_VISIBLE = 11
	};

	enum PVLANIMATIONDIRECTION
	{
		PANI_DIR_LEFT = 1,
		PANI_DIR_RIGHT = 2,
		PANI_DIR_TOP = 3,
		PANI_DIR_BOTTOM = 4
	};

	enum ANIMATIONCOMPLETECODE
	{
		ACC_SUCCESS = 1,
		ACC_ABANDON = 2,
		ACC_FAIL = 3,
	};

	enum MANUALSTORYBOARD
	{
		MSB_START = 1,
		MSB_END = 2,
		MSB_CANCEL = 3,
		MSB_ADD = 4,
	};

	enum LAUNCHERVERSION
	{
		PANI_VER_DEFAULT = 1,
		PANI_VER_QUICK = 2,
	};

	enum TAPVERSION
	{
		TV_SQUARE70X70_TILE_TILT = 0,
		TV_SQUARE150X150_TILE_TILT = 1,
		TV_WIDE310X150_TILE_TILT = 2,
		TV_SQUARE310X310_TILE_TILT = 3,
		TV_SQUARE70X70_TILE_TILT_NO_DEAD_ZONE = 4,
		TV_TILE_TILT_BEGIN_SKIP_SCALE = 4,
		TV_SQUARE150X150_TILE_TILT_NO_DEAD_ZONE = 5,
		TV_WIDE310X150_TILE_TILT_NO_DEAD_ZONE = 6,
		TV_SQUARE310X310_TILE_TILT_NO_DEAD_ZONE = 7,
		TV_TILE_TILT_MAX = 8,
	};

	enum SLIDEVERSION
	{
		PANI_VER_REPOSITION = 0,
		PANI_VER_EDGEUI = 1,
		PANI_VER_PANEL = 2,
	};

	enum TILENOTIFICATIONOPTION
	{
		TNO_NONE = 0x0,
		TNO_SHOW_LOGO = 0x1,
		TNO_HIDE_LOGO = 0x2,
		TNO_SHOW_DISPLAYNAME = 0x4,
		TNO_HIDE_DISPLAYNAME = 0x8,
	};

	enum LOGOANIMATIONOPTION
	{
		LAO_FLAG_NONE = 0x0,
		LAO_FLAG_TILT = 0x1,
		LAO_FLAG_UNTILT = 0x2,
		LAO_FLAG_WASH = 0x4,
		LAO_FLAG_INSTANT = 0x8,
	};

	enum COPYUSAGEOPTION
	{
		CUO_NONE = 0x0,
		CUO_NEW = 0x1,
		CUO_EXISTING = 0x2,
	};

	struct POINTFLOAT3D
	{
		FLOAT x;
		FLOAT y;
		FLOAT z;
	};

	enum PVLANIMATIONHINTVALUE
	{
		PANI_HINT_INT = 1,
		PANI_HINT_ELEMENT = 2
	};

	struct PANI_FromToInt
	{
		int nFrom;
		int nTo;
	};

	struct PANI_FromToElement
	{
		Element* peFrom;
		Element* peTo;
	};

	union PANI_FromTo
	{
		PANI_FromToInt nVal;
		PANI_FromToElement pElemVal;
	};

	struct PANI_FromToValue
	{
		PVLANIMATIONHINTVALUE type;
		PANI_FromTo ftv;
	};

	struct PVLAnimationTranslation
	{
		bool fInitTranslation;
		POINT ptInit;
		POINT ptDest;
		bool fUseAsOffset;
		bool fChopStart;
		bool fChopStop;
		UINT uiChopIndex;
		LONG lChopStart;
		LONG lChopStop;
	};

	struct PVLAnimationTranslation3D
	{
		bool fInitTranslation3D;
		POINTFLOAT3D ptfl3dInit;
		POINTFLOAT3D ptfl3dDest;
	};

	struct PVLAnimationScale
	{
		bool fInitScale;
		bool fOriginScale;
		POINTFLOAT ptflInit;
		POINTFLOAT ptflScale;
		POINTFLOAT ptflOrigin;
	};

	struct PVLAnimationScale3D
	{
		bool fInitScale;
		bool fOriginScale;
		POINTFLOAT3D ptfl3dInit;
		POINTFLOAT3D ptfl3dScale;
		POINTFLOAT3D ptfl3dOrigin;
	};

	struct PVLAnimationAlpha
	{
		bool fInitAlpha;
		FLOAT flInit;
		FLOAT flDest;
	};

	struct PVLAnimationSize
	{
		bool fInitSize;
		SIZE szInit;
		SIZE szDest;
	};

	struct PVLAnimationRotation
	{
		bool fInitRotation;
		bool fOriginRotation;
		FLOAT flInitRotation;
		FLOAT flRotation;
		POINTFLOAT ptflOriginRotation;
	};

	struct PVLAnimationRotation3D
	{
		bool fInitRotation3D;
		bool fOriginRotation3D;
		POINTFLOAT3D ptfl3dInitRotation;
		POINTFLOAT3D ptfl3dRotation;
		POINTFLOAT3D ptfl3dOriginRotation;
	};

	struct PVLAnimationSkew
	{
		bool fInitSkew;
		bool fOriginSkew;
		POINTFLOAT ptflInitSkew;
		POINTFLOAT ptflSkew;
		POINTFLOAT ptflOriginSkew;
	};

	struct PVLAnimationClip
	{
		bool fInitClip;
		POINTFLOAT ptflInitialTopLeft;
		POINTFLOAT ptflInitialBottomRight;
		POINTFLOAT ptflFinalTopLeft;
		POINTFLOAT ptflFinalBottomRight;
	};

	struct PVLAnimationZOrder
	{
		bool fUseCustomZOrder;
		DWORD dwZOrder;
	};

	struct ClipRectWithElement : PVLAnimationClip
	{
		CSafeElementPtr<Element> speTarget;
	};

	struct TriggeredAnimationCompleteEvent : Event
	{
		UINT nCode;
		DWORD dwCookie;
		bool fStoryboardAnimated;
	};

	struct AnimationStatusChangeEvent : Event
	{
		UINT nCode;
		Element* peAnimatingTarget;
	};

	struct PVLAnimationNotifyEvent : Event
	{
		int iAnimationId;
		bool fTrapped;
		bool fNotifyComplete;
		DWORD dwCookie;
		bool fManualSB;
		int nManualSBID;
		int nInsertionIndex;
		bool fLauncherTriggered;
	};

	struct PVLAnimationNotifyCompleteEvent : PVLAnimationNotifyEvent
	{
		int iStoryboardId;
		PVLAnimationNotifyEvent* panEvent;
		bool fForceUpdateIfDumped;
		CSafeElementPtr<Element> speNotify;
	};

	struct PVLAnimationManualStoryboard : PVLAnimationNotifyEvent
	{
		int nCode;
		int nManualStoryboardId;
		CSafeElementPtr<Element> speFinishNotify;
		bool fVerified;
	};

	struct PVLAnimationReflowStyleEvent : Event
	{
		bool fFoundReflowStyle;
		bool fSetReflowStyle;
		int nNewReflowStyle;
		int nCurrentReflowStlye;
	};

	struct PVLAnimationCustomReflowHintEvent : Event
	{
		Element* peToMove;
		POINT ptInitial;
		POINT ptDest;
		bool fRowChange;
		bool fColumnChange;
		bool fParentChange;
		bool fUseNewCoordinateSpace;
		bool fUseLinearReflow;
		bool fUseAbsoluteColumnNumbers;
		bool fClipInside;
		PANI_FromToValue ftvRowChange;
		PANI_FromToValue ftvColumnChange;
		PANI_FromToValue ftvParentChange;
		bool fUseNewScalingOrigin;
		POINTFLOAT ptflScalingOrigin;
		int nNumberOfTowersToSkip;
		int nMaxTowerHeight;
		POINT ptExtraPortalingDistance;
		int nStaggerOrder;
	};

	struct PVLAnimationCustomDragDropScalingHintEvent : Event
	{
		bool fDrag;
		POINTFLOAT ptflScaleFactor;
		POINTFLOAT ptflScaleOrigin;
	};

	struct PVLAnimationCustomTapHintEvent : Event
	{
		RECT rcTileBounds;
	};

	struct PVLAnimationDeleteEvent : PVLAnimationNotifyEvent
	{
		CSafeElementPtr<Element> speToDelete;
		CSafeElementPtrList* pspelToDelete;
		bool fCollection;
		bool fDestroy;
		bool fFilter;
	};

	struct PVLAnimationAddEvent : PVLAnimationNotifyEvent
	{
		CSafeElementPtrList* pspelParents;
		DynamicArray<DynamicArray<SafeElementIndexPair*>*>* pdaToAdd;
		int nLayoutPos;
		bool fFilter;
		bool fIgnoreDelay;
	};

	struct PVLAnimationExpandCollapseEvent : PVLAnimationNotifyEvent, PVLAnimationClip
	{
		CSafeElementPtr<Element> speToChange;
		CSafeElementPtr<Element> speAdditional;
		CSafeElementPtr<Element> speContainer;
		bool fExpand;
		int nLayoutPos;
		bool fConsiderAsClip;
		bool fInterruptCollapse;
	};

	struct PVLAnimationRepositionEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToMove;
		bool fReverse;
		int nOrderNumber;
		UINT uiVersion;
		UINT uiState;
		int nReflowStyle;
		CSafeElementPtr<Element> speAttached;
		bool fProcessed;
		ElementGadgetTicketPair* pegtpValidation;
	};

	struct PVLAnimationParentChangeEvent : PVLAnimationNotifyEvent
	{
		CSafeElementPtr<Element> speReparentTarget;
		CSafeElementPtr<Element> speOldParent;
		CSafeElementPtr<Element> speNewParent;
	};

	struct PVLAnimationMoveEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToMove;
		CSafeElementPtr<Element> speParent;
		CSafeElementPtr<Element> speCurrentParent;
		int nIndex;
		bool fTopMost;
	};

	struct PVLAnimationSlideEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToSlide;
		CSafeElementPtr<Element> speParent;
		UINT uiState;
		UINT uiDir;
		UINT uiVersion;
		bool fLayoutAlreadySet;
		bool fAffected;
		bool fPositionAlreadySet;
	};

	struct PVLAnimationFadeEvent : PVLAnimationNotifyEvent, PVLAnimationAlpha
	{
		CSafeElementPtr<Element> speToFade;
		CSafeElementPtrList* pspelToFade;
		bool fCollection;
		bool fLeaveElementsVisible;
		int nOrderNumber;
	};

	struct PVLAnimationTapEvent : PVLAnimationNotifyEvent, PVLAnimationScale, PVLAnimationRotation3D
	{
		CSafeElementPtr<Element> speToTap;
		UINT uiState;
		UINT uiVersion;
		POINT ptContact;
		bool fSkipScaleTransform;
	};

	struct PVLAnimationLaunchEvent : PVLAnimationNotifyEvent, PVLAnimationScale
	{
		CSafeElementPtr<Element> speToLaunch;
		CSafeElementPtrList* pspelRemaining;
	};

	struct PVLAnimationDragEvent : PVLAnimationNotifyEvent, PVLAnimationScale, PVLAnimationClip
	{
		CSafeElementPtr<Element> speToDrag;
		CSafeElementPtrList* pspelRemaining;
		CSafeElementPtr<Element> speContent;
		CSafeElementPtr<Element> speAdornment;
		DynamicArray<ClipRectWithElement*>* pTowerClippingRects;
		POINT ptContact;
		bool fUseCustomScale;
		bool fAnimatingTowerClip;

		PVLAnimationDragEvent()
			: pspelRemaining(nullptr)
			, fAnimatingTowerClip(false)
		{
		}

		~PVLAnimationDragEvent()
		{
			if (pspelRemaining)
			{
				pspelRemaining->DestroyDeep();
				pspelRemaining = nullptr;
			}
			if (pTowerClippingRects)
			{
				pTowerClippingRects->Destroy();
				pTowerClippingRects = nullptr;
			}
		}
	};

	struct PVLAnimationDropEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation, PVLAnimationScale, PVLAnimationClip
	{
		CSafeElementPtr<Element> speToDrop;
		CSafeElementPtrList* pspelRemaining;
		CSafeElementPtr<Element> speContent;
		CSafeElementPtr<Element> speAdornment;
		DynamicArray<ClipRectWithElement*>* pTowerClippingRects;
		CSafeElementPtr<Element> speParent;
		int nIndex;
		int nLayoutPos;
		bool fUseCustomScale;
		bool fAnimatingTowerClip;
	};

	struct PVLAnimationRevealHideEvent : PVLAnimationNotifyEvent, PVLAnimationClip
	{
		CSafeElementPtr<Element> speTapped;
		CSafeElementPtr<Element> speOutline;
		CSafeElementPtr<Element> speBackground;
		CSafeElementPtr<Element> speContent;
		RECT rcContentClip;
		bool fReveal;
	};

	struct PVLAnimationReflowEvent : PVLAnimationNotifyEvent, PVLAnimationSize
	{
		CSafeElementPtr<Element> speContainer;
		bool fUseNewSize;
	};

	struct PVLAnimationResizeEvent : PVLAnimationNotifyEvent, PVLAnimationSize
	{
		CSafeElementPtr<Element> speToResize;
		bool fReverse;
	};

	struct PVLAnimationContentTransitionEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtrList* pspelSources;
		CSafeElementPtrList* pspelDests;
		CSafeElementPtr<Element> speParent;
		POINT ptOffset;
		int nLayoutPos;
	};

	struct PVLAnimationScaleEvent : PVLAnimationNotifyEvent, PVLAnimationScale
	{
		CSafeElementPtr<Element> speToScale;
		int nOrderNumber;
		int nCustomDuration;
	};

	struct PVLAnimationLauncherEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation, PVLAnimationScale, PVLAnimationZOrder
	{
		bool fLaunch;
		UINT uiVersion;
		CSafeElementPtr<Element> speLauncher;
		CSafeElementPtr<Element> speLauncherContent;
		CSafeElementPtrList* pspelTowers;
		CSafeElementPtrList* pspelGroupHeaders;
		CSafeElementPtr<Element> speStartText;
		CSafeElementPtr<Element> speUserTile;
		CSafeElementPtr<Element> speSortDropdown;
		CSafeElementPtr<Element> speSearchBox;
		POINT ptOffsetLauncher;
		POINT ptOffsetTower;

		PVLAnimationLauncherEvent()
			: pspelTowers(nullptr)
			, pspelGroupHeaders(nullptr)
		{
		}

		~PVLAnimationLauncherEvent()
		{
			if (pspelTowers)
			{
				pspelTowers->DestroyDeep();
				pspelTowers = nullptr;
			}
			if (pspelGroupHeaders)
			{
				pspelGroupHeaders->DestroyDeep();
				pspelGroupHeaders = nullptr;
			}
		}
	};

	struct PVLAnimationBadgeUpdateEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speOldBadge;
		CSafeElementPtr<Element> speNewBadge;
		POINT ptOffset;
	};

	struct PVLAnimationPopEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToPop;
		CSafeElementPtr<Element> speParent;
		POINT ptOffset;
		bool fLayoutAlreadySet;
		bool fUseCurrentOpacity;
	};

	struct PVLAnimationSessionEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation, PVLAnimationScale, PVLAnimationZOrder
	{
		bool fLauncher;
		UINT uiVersion;
		bool fLogin;
		CSafeElementPtr<Element> speLauncher;
		CSafeElementPtr<Element> speLauncherContent;
		CSafeElementPtrList* pspelTowers;
		CSafeElementPtrList* pspelGroupHeaders;
		CSafeElementPtr<Element> speStartText;
		CSafeElementPtr<Element> speUserTileIcon;
		CSafeElementPtr<Element> speUserTileText;
		POINT ptOffsetLauncher;
		POINT ptOffsetTower;
		POINT ptOffsetStartText;
		POINT ptOffsetUserTileIcon;
		POINT ptOffsetUserTileText;
		POINT ptGroupHeaderOffset;
		CSafeElementPtr<Element> speLoginUserTile;
		CSafeElementPtr<Element> speLoginUserText;
		POINT ptOffsetLogonUI;
	};

	struct PVLAnimationEntranceEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtrList* pspelToEnter;
		DynamicArray<POINT>* pdaOffsets;
	};

	struct PVLAnimationCrossfadeEvent : PVLAnimationNotifyEvent
	{
		CSafeElementPtr<Element> speToFadeOut;
		CSafeElementPtr<Element> speToFadeIn;
		CSafeElementPtrList* pspelToFadeOut;
		CSafeElementPtrList* pspelToFadeIn;
		bool fCloneTransforms;
		bool fLayoutAlreadySet;
		bool fDestroy;
		bool fInplace;
		bool fCollection;
	};

	struct PVLAnimationNudgeEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtrList* pspelToNudge;
		DynamicArray<POINT>* pdaOffsets;
	};

	struct PVLAnimationSwipeEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToSwipe;
		POINT ptOffset;
		CSafeElementPtr<Element> speCheckmark;
	};

	struct PVLAnimationTileNotificationEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		bool fPeek;
		CSafeElementPtr<Element> speOutgoing;
		CSafeElementPtr<Element> speIncoming;
		CSafeElementPtr<Element> speLogo;
		CSafeElementPtr<Element> speDisplayName;
		POINT ptOutgoingDest;
		POINT ptIncomingDest;
		UINT uTileNotificationOption;
	};

	struct PVLAnimationActionSpaceEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation, PVLAnimationRotation3D
	{
		int nAnimationOptions;
		CSafeElementPtr<Element> speNotify;
		CSafeElementPtr<Element> speLauncherCharm;
		CSafeElementPtr<Element> speLogoBackground;
		CSafeElementPtr<Element> speWash;
		CSafeElementPtr<Element> speLogoPane;
		CSafeElementPtr<Element> speLogoPaneVCrossbar;
		DEVICE_SCALE_FACTOR scaleFactor;
	};

	class PVLAnimation
	{
	public:
		UILIB_API static UID WINAPI NotifyStart();
		UILIB_API static UID WINAPI NotifyComplete();
		UILIB_API static UID WINAPI NotifyImplicit();
		UILIB_API static UID WINAPI NotifyStoryboardComplete();
		UILIB_API static UID WINAPI ManualStoryboardVerify();
		UILIB_API static UID WINAPI ReflowStyle();
		UILIB_API static UID WINAPI CustomReflowHint();
		UILIB_API static UID WINAPI CustomDragDropScalingHint();
		UILIB_API static UID WINAPI CustomTapHint();
		UILIB_API static UID WINAPI TriggeredAnimationComplete();
		UILIB_API static UID WINAPI AnimationStatusChange();
	};
}
