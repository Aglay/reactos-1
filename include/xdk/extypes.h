/******************************************************************************
 *                            Executive Types                                 *
 ******************************************************************************/

$if (_WDMDDK_)
#define EX_RUNDOWN_ACTIVE                 0x1
#define EX_RUNDOWN_COUNT_SHIFT            0x1
#define EX_RUNDOWN_COUNT_INC              (1 << EX_RUNDOWN_COUNT_SHIFT)

#ifdef _WIN64
#define PORT_MAXIMUM_MESSAGE_LENGTH 512
#else
#define PORT_MAXIMUM_MESSAGE_LENGTH 256
#endif

typedef struct _FAST_MUTEX {
  volatile LONG Count;
  PKTHREAD Owner;
  ULONG Contention;
  KEVENT Event;
  ULONG OldIrql;
} FAST_MUTEX, *PFAST_MUTEX;

typedef enum _SUITE_TYPE {
  SmallBusiness,
  Enterprise,
  BackOffice,
  CommunicationServer,
  TerminalServer,
  SmallBusinessRestricted,
  EmbeddedNT,
  DataCenter,
  SingleUserTS,
  Personal,
  Blade,
  EmbeddedRestricted,
  SecurityAppliance,
  StorageServer,
  ComputeServer,
  WHServer,
  MaxSuiteType
} SUITE_TYPE;

typedef enum _EX_POOL_PRIORITY {
  LowPoolPriority,
  LowPoolPrioritySpecialPoolOverrun = 8,
  LowPoolPrioritySpecialPoolUnderrun = 9,
  NormalPoolPriority = 16,
  NormalPoolPrioritySpecialPoolOverrun = 24,
  NormalPoolPrioritySpecialPoolUnderrun = 25,
  HighPoolPriority = 32,
  HighPoolPrioritySpecialPoolOverrun = 40,
  HighPoolPrioritySpecialPoolUnderrun = 41
} EX_POOL_PRIORITY;

#if !defined(_WIN64) && (defined(_NTDDK_) || defined(_NTIFS_) || defined(_NDIS_))
#define LOOKASIDE_ALIGN
#else
#define LOOKASIDE_ALIGN /* FIXME: DECLSPEC_CACHEALIGN */
#endif

typedef struct _LOOKASIDE_LIST_EX *PLOOKASIDE_LIST_EX;

typedef PVOID
(DDKAPI *PALLOCATE_FUNCTION)(
  IN POOL_TYPE PoolType,
  IN SIZE_T NumberOfBytes,
  IN ULONG Tag);

typedef PVOID
(DDKAPI *PALLOCATE_FUNCTION_EX)(
  IN POOL_TYPE PoolType,
  IN SIZE_T NumberOfBytes,
  IN ULONG Tag,
  IN OUT PLOOKASIDE_LIST_EX Lookaside);

typedef VOID
(DDKAPI *PFREE_FUNCTION)(
  IN PVOID Buffer);

typedef VOID
(DDKAPI *PFREE_FUNCTION_EX)(
  IN PVOID Buffer,
  IN OUT PLOOKASIDE_LIST_EX Lookaside);

typedef VOID
(DDKAPI *PCALLBACK_FUNCTION)(
  IN PVOID CallbackContext,
  IN PVOID Argument1,
  IN PVOID Argument2);

#define GENERAL_LOOKASIDE_LAYOUT                \
    union {                                     \
        SLIST_HEADER ListHead;                  \
        SINGLE_LIST_ENTRY SingleListHead;       \
    } DUMMYUNIONNAME;                           \
    USHORT Depth;                               \
    USHORT MaximumDepth;                        \
    ULONG TotalAllocates;                       \
    union {                                     \
        ULONG AllocateMisses;                   \
        ULONG AllocateHits;                     \
    } DUMMYUNIONNAME2;                          \
                                                \
    ULONG TotalFrees;                           \
    union {                                     \
        ULONG FreeMisses;                       \
        ULONG FreeHits;                         \
    } DUMMYUNIONNAME3;                          \
                                                \
    POOL_TYPE Type;                             \
    ULONG Tag;                                  \
    ULONG Size;                                 \
    union {                                     \
        PALLOCATE_FUNCTION_EX AllocateEx;       \
        PALLOCATE_FUNCTION Allocate;            \
    } DUMMYUNIONNAME4;                          \
                                                \
    union {                                     \
        PFREE_FUNCTION_EX FreeEx;               \
        PFREE_FUNCTION Free;                    \
    } DUMMYUNIONNAME5;                          \
                                                \
    LIST_ENTRY ListEntry;                       \
    ULONG LastTotalAllocates;                   \
    union {                                     \
        ULONG LastAllocateMisses;               \
        ULONG LastAllocateHits;                 \
    } DUMMYUNIONNAME6;                          \
    ULONG Future[2];

typedef struct LOOKASIDE_ALIGN _GENERAL_LOOKASIDE {
  GENERAL_LOOKASIDE_LAYOUT
} GENERAL_LOOKASIDE, *PGENERAL_LOOKASIDE;

typedef struct _GENERAL_LOOKASIDE_POOL {
  GENERAL_LOOKASIDE_LAYOUT
} GENERAL_LOOKASIDE_POOL, *PGENERAL_LOOKASIDE_POOL;

typedef struct _PAGED_LOOKASIDE_LIST {
  GENERAL_LOOKASIDE L;
#if !defined(_AMD64_) && !defined(_IA64_)
  FAST_MUTEX Lock__ObsoleteButDoNotDelete;
#endif
} PAGED_LOOKASIDE_LIST, *PPAGED_LOOKASIDE_LIST;

typedef struct LOOKASIDE_ALIGN _NPAGED_LOOKASIDE_LIST {
  GENERAL_LOOKASIDE L;
#if !defined(_AMD64_) && !defined(_IA64_)
  KSPIN_LOCK Lock__ObsoleteButDoNotDelete;
#endif
} NPAGED_LOOKASIDE_LIST, *PNPAGED_LOOKASIDE_LIST;

typedef struct _LOOKASIDE_LIST_EX {
  GENERAL_LOOKASIDE_POOL L;
} LOOKASIDE_LIST_EX;

typedef struct _EX_RUNDOWN_REF {
  __GNU_EXTENSION union {
    volatile ULONG_PTR Count;
    volatile PVOID Ptr;
  };
} EX_RUNDOWN_REF, *PEX_RUNDOWN_REF;

typedef struct _EX_RUNDOWN_REF_CACHE_AWARE *PEX_RUNDOWN_REF_CACHE_AWARE;

typedef VOID
(DDKAPI *PWORKER_THREAD_ROUTINE)(
  IN PVOID Parameter);

typedef struct _WORK_QUEUE_ITEM {
  LIST_ENTRY List;
  PWORKER_THREAD_ROUTINE WorkerRoutine;
  volatile PVOID Parameter;
} WORK_QUEUE_ITEM, *PWORK_QUEUE_ITEM;

$endif


