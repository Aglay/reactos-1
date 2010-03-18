/******************************************************************************
 *                         I/O Manager Functions                              *
 ******************************************************************************/

#if !defined(_M_AMD64)
NTHALAPI
VOID
NTAPI
READ_PORT_BUFFER_UCHAR(
  IN PUCHAR Port,
  IN PUCHAR Buffer,
  IN ULONG Count);

NTHALAPI
VOID
NTAPI
READ_PORT_BUFFER_ULONG(
  IN PULONG Port,
  IN PULONG Buffer,
  IN ULONG Count);

NTHALAPI
VOID
NTAPI
READ_PORT_BUFFER_USHORT(
  IN PUSHORT Port,
  IN PUSHORT Buffer,
  IN ULONG Count);

NTHALAPI
UCHAR
NTAPI
READ_PORT_UCHAR(
  IN PUCHAR Port);

NTHALAPI
ULONG
NTAPI
READ_PORT_ULONG(
  IN PULONG Port);

NTHALAPI
USHORT
NTAPI
READ_PORT_USHORT(
  IN PUSHORT Port);

NTKERNELAPI
VOID
NTAPI
READ_REGISTER_BUFFER_UCHAR(
  IN PUCHAR Register,
  IN PUCHAR Buffer,
  IN ULONG Count);

NTKERNELAPI
VOID
NTAPI
READ_REGISTER_BUFFER_ULONG(
  IN PULONG Register,
  IN PULONG Buffer,
  IN ULONG Count);

NTKERNELAPI
VOID
NTAPI
READ_REGISTER_BUFFER_USHORT(
  IN PUSHORT Register,
  IN PUSHORT Buffer,
  IN ULONG Count);

NTKERNELAPI
UCHAR
NTAPI
READ_REGISTER_UCHAR(
  IN PUCHAR Register);

NTKERNELAPI
ULONG
NTAPI
READ_REGISTER_ULONG(
  IN PULONG Register);

NTKERNELAPI
USHORT
NTAPI
READ_REGISTER_USHORT(
  IN PUSHORT Register);

NTHALAPI
VOID
NTAPI
WRITE_PORT_BUFFER_UCHAR(
  IN PUCHAR Port,
  IN PUCHAR Buffer,
  IN ULONG Count);

NTHALAPI
VOID
NTAPI
WRITE_PORT_BUFFER_ULONG(
  IN PULONG Port,
  IN PULONG Buffer,
  IN ULONG Count);

NTHALAPI
VOID
NTAPI
WRITE_PORT_BUFFER_USHORT(
  IN PUSHORT Port,
  IN PUSHORT Buffer,
  IN ULONG Count);

NTHALAPI
VOID
NTAPI
WRITE_PORT_UCHAR(
  IN PUCHAR Port,
  IN UCHAR Value);

NTHALAPI
VOID
NTAPI
WRITE_PORT_ULONG(
  IN PULONG Port,
  IN ULONG Value);

NTHALAPI
VOID
NTAPI
WRITE_PORT_USHORT(
  IN PUSHORT Port,
  IN USHORT Value);

NTKERNELAPI
VOID
NTAPI
WRITE_REGISTER_BUFFER_UCHAR(
  IN PUCHAR Register,
  IN PUCHAR Buffer,
  IN ULONG Count);

NTKERNELAPI
VOID
NTAPI
WRITE_REGISTER_BUFFER_ULONG(
  IN PULONG Register,
  IN PULONG Buffer,
  IN ULONG Count);

NTKERNELAPI
VOID
NTAPI
WRITE_REGISTER_BUFFER_USHORT(
  IN PUSHORT Register,
  IN PUSHORT Buffer,
  IN ULONG Count);

NTKERNELAPI
VOID
NTAPI
WRITE_REGISTER_UCHAR(
  IN PUCHAR Register,
  IN UCHAR Value);

NTKERNELAPI
VOID
NTAPI
WRITE_REGISTER_ULONG(
  IN PULONG Register,
  IN ULONG Value);

NTKERNELAPI
VOID
NTAPI
WRITE_REGISTER_USHORT(
  IN PUSHORT Register,
  IN USHORT Value);

#else

FORCEINLINE
VOID
READ_PORT_BUFFER_UCHAR(
  IN PUCHAR Port,
  IN PUCHAR Buffer,
  IN ULONG Count)
{
  __inbytestring((USHORT)(ULONG_PTR)Port, Buffer, Count);
}

FORCEINLINE
VOID
READ_PORT_BUFFER_ULONG(
  IN PULONG Port,
  IN PULONG Buffer,
  IN ULONG Count)
{
  __indwordstring((USHORT)(ULONG_PTR)Port, Buffer, Count);
}

FORCEINLINE
VOID
READ_PORT_BUFFER_USHORT(
  IN PUSHORT Port,
  IN PUSHORT Buffer,
  IN ULONG Count)
{
  __inwordstring((USHORT)(ULONG_PTR)Port, Buffer, Count);
}

FORCEINLINE
UCHAR
READ_PORT_UCHAR(
  IN PUCHAR Port)
{
  return __inbyte((USHORT)(ULONG_PTR)Port);
}

FORCEINLINE
ULONG
READ_PORT_ULONG(
  IN PULONG Port)
{
  return __indword((USHORT)(ULONG_PTR)Port);
}

FORCEINLINE
USHORT
READ_PORT_USHORT(
  IN PUSHORT Port)
{
  return __inword((USHORT)(ULONG_PTR)Port);
}

FORCEINLINE
VOID
READ_REGISTER_BUFFER_UCHAR(
  IN PUCHAR Register,
  IN PUCHAR Buffer,
  IN ULONG Count)
{
  __movsb(Register, Buffer, Count);
}

FORCEINLINE
VOID
READ_REGISTER_BUFFER_ULONG(
  IN PULONG Register,
  IN PULONG Buffer,
  IN ULONG Count)
{
  __movsd(Register, Buffer, Count);
}

FORCEINLINE
VOID
READ_REGISTER_BUFFER_USHORT(
  IN PUSHORT Register,
  IN PUSHORT Buffer,
  IN ULONG Count)
{
  __movsw(Register, Buffer, Count);
}

FORCEINLINE
UCHAR
READ_REGISTER_UCHAR(
  IN volatile UCHAR *Register)
{
  return *Register;
}

FORCEINLINE
ULONG
READ_REGISTER_ULONG(
  IN volatile ULONG *Register)
{
  return *Register;
}

FORCEINLINE
USHORT
READ_REGISTER_USHORT(
  IN volatile USHORT *Register)
{
  return *Register;
}

FORCEINLINE
VOID
WRITE_PORT_BUFFER_UCHAR(
  IN PUCHAR Port,
  IN PUCHAR Buffer,
  IN ULONG Count)
{
  __outbytestring((USHORT)(ULONG_PTR)Port, Buffer, Count);
}

FORCEINLINE
VOID
WRITE_PORT_BUFFER_ULONG(
  IN PULONG Port,
  IN PULONG Buffer,
  IN ULONG Count)
{
  __outdwordstring((USHORT)(ULONG_PTR)Port, Buffer, Count);
}

FORCEINLINE
VOID
WRITE_PORT_BUFFER_USHORT(
  IN PUSHORT Port,
  IN PUSHORT Buffer,
  IN ULONG Count)
{
  __outwordstring((USHORT)(ULONG_PTR)Port, Buffer, Count);
}

FORCEINLINE
VOID
WRITE_PORT_UCHAR(
  IN PUCHAR Port,
  IN UCHAR Value)
{
  __outbyte((USHORT)(ULONG_PTR)Port, Value);
}

FORCEINLINE
VOID
WRITE_PORT_ULONG(
  IN PULONG Port,
  IN ULONG Value)
{
  __outdword((USHORT)(ULONG_PTR)Port, Value);
}

FORCEINLINE
VOID
WRITE_PORT_USHORT(
  IN PUSHORT Port,
  IN USHORT Value)
{
  __outword((USHORT)(ULONG_PTR)Port, Value);
}

FORCEINLINE
VOID
WRITE_REGISTER_BUFFER_UCHAR(
  IN PUCHAR Register,
  IN PUCHAR Buffer,
  IN ULONG Count)
{
  LONG Synch;
  __movsb(Register, Buffer, Count);
  InterlockedOr(&Synch, 1);
}

FORCEINLINE
VOID
WRITE_REGISTER_BUFFER_ULONG(
  IN PULONG Register,
  IN PULONG Buffer,
  IN ULONG Count)
{
  LONG Synch;
  __movsd(Register, Buffer, Count);
  InterlockedOr(&Synch, 1);
}

FORCEINLINE
VOID
WRITE_REGISTER_BUFFER_USHORT(
  IN PUSHORT Register,
  IN PUSHORT Buffer,
  IN ULONG Count)
{
  LONG Synch;
  __movsw(Register, Buffer, Count);
  InterlockedOr(&Synch, 1);
}

FORCEINLINE
VOID
WRITE_REGISTER_UCHAR(
  IN volatile UCHAR *Register,
  IN UCHAR Value)
{
  LONG Synch;
  *Register = Value;
  InterlockedOr(&Synch, 1);
}

FORCEINLINE
VOID
WRITE_REGISTER_ULONG(
  IN volatile ULONG *Register,
  IN ULONG Value)
{
  LONG Synch;
  *Register = Value;
  InterlockedOr(&Synch, 1);
}

FORCEINLINE
VOID
WRITE_REGISTER_USHORT(
  IN volatile USHORT *Register,
  IN USHORT Value)
{
  LONG Sync;
  *Register = Value;
  InterlockedOr(&Sync, 1);
}
#endif

#if defined(USE_DMA_MACROS) && !defined(_NTHAL_) && \
   (defined(_NTDDK_) || defined(_NTDRIVER_)) || defined(_WDM_INCLUDED_)

#define DMA_MACROS_DEFINED

FORCEINLINE
NTSTATUS
IoAllocateAdapterChannel(
  IN PDMA_ADAPTER DmaAdapter,
  IN PDEVICE_OBJECT DeviceObject,
  IN ULONG NumberOfMapRegisters,
  IN PDRIVER_CONTROL ExecutionRoutine,
  IN PVOID Context)
{
  PALLOCATE_ADAPTER_CHANNEL AllocateAdapterChannel;
  AllocateAdapterChannel =
      *(DmaAdapter)->DmaOperations->AllocateAdapterChannel;
  ASSERT(AllocateAdapterChannel);
  return AllocateAdapterChannel(DmaAdapter,
                                DeviceObject,
                                NumberOfMapRegisters,
                                ExecutionRoutine,
                                Context );
}

FORCEINLINE
BOOLEAN
NTAPI
IoFlushAdapterBuffers(
  IN PDMA_ADAPTER DmaAdapter,
  IN PMDL Mdl,
  IN PVOID MapRegisterBase,
  IN PVOID CurrentVa,
  IN ULONG Length,
  IN BOOLEAN WriteToDevice)
{
  PFLUSH_ADAPTER_BUFFERS FlushAdapterBuffers;
  FlushAdapterBuffers = *(DmaAdapter)->DmaOperations->FlushAdapterBuffers;
  ASSERT(FlushAdapterBuffers);
  return FlushAdapterBuffers(DmaAdapter,
                             Mdl,
                             MapRegisterBase,
                             CurrentVa,
                             Length,
                             WriteToDevice);
}

FORCEINLINE
VOID
NTAPI
IoFreeAdapterChannel(
  IN PDMA_ADAPTER DmaAdapter)
{
  PFREE_ADAPTER_CHANNEL FreeAdapterChannel;
  FreeAdapterChannel = *(DmaAdapter)->DmaOperations->FreeAdapterChannel;
  ASSERT(FreeAdapterChannel);
  FreeAdapterChannel(DmaAdapter);
}

FORCEINLINE
VOID
NTAPI
IoFreeMapRegisters(
  IN PDMA_ADAPTER DmaAdapter,
  IN PVOID MapRegisterBase,
  IN ULONG NumberOfMapRegisters)
{
  PFREE_MAP_REGISTERS FreeMapRegisters;
  FreeMapRegisters = *(DmaAdapter)->DmaOperations->FreeMapRegisters;
  ASSERT(FreeMapRegisters);
  FreeMapRegisters(DmaAdapter, MapRegisterBase, NumberOfMapRegisters);
}

FORCEINLINE
PHYSICAL_ADDRESS
NTAPI
IoMapTransfer(
  IN PDMA_ADAPTER DmaAdapter,
  IN PMDL Mdl,
  IN PVOID MapRegisterBase,
  IN PVOID CurrentVa,
  IN OUT PULONG Length,
  IN BOOLEAN WriteToDevice)
{
  PMAP_TRANSFER MapTransfer;

  MapTransfer = *(DmaAdapter)->DmaOperations->MapTransfer;
  ASSERT(MapTransfer);
  return MapTransfer(DmaAdapter,
                     Mdl,
                     MapRegisterBase,
                     CurrentVa,
                     Length,
                     WriteToDevice);
}
#endif

#if (NTDDI_VERSION >= NTDDI_WIN2K)

NTKERNELAPI
VOID
NTAPI
IoAcquireCancelSpinLock(
  OUT PKIRQL Irql);

NTKERNELAPI
NTSTATUS
NTAPI
IoAcquireRemoveLockEx(
  IN PIO_REMOVE_LOCK RemoveLock,
  IN PVOID Tag OPTIONAL,
  IN PCSTR File,
  IN ULONG Line,
  IN ULONG RemlockSize);

#endif

/*
 * NTSTATUS
 * IoAcquireRemoveLock(
 *   IN PIO_REMOVE_LOCK  RemoveLock,
 *   IN OPTIONAL PVOID  Tag)
 */
#if DBG
#define IoAcquireRemoveLock(RemoveLock, Tag) \
  IoAcquireRemoveLockEx(RemoveLock, Tag, __FILE__, __LINE__, sizeof (IO_REMOVE_LOCK))
#else
#define IoAcquireRemoveLock(RemoveLock, Tag) \
  IoAcquireRemoveLockEx(RemoveLock, Tag, "", 1, sizeof (IO_REMOVE_LOCK))
#endif

/*
 * VOID
 * IoAdjustPagingPathCount(
 *   IN PLONG  Count,
 *   IN BOOLEAN  Increment)
 */
#define IoAdjustPagingPathCount(_Count, \
                                _Increment) \
{ \
  if (_Increment) \
    { \
      InterlockedIncrement(_Count); \
    } \
  else \
    { \
      InterlockedDecrement(_Count); \
    } \
}

#if (NTDDI_VERSION >= NTDDI_WIN2K)

NTKERNELAPI
NTSTATUS
NTAPI
IoAllocateDriverObjectExtension(
  IN PDRIVER_OBJECT DriverObject,
  IN PVOID ClientIdentificationAddress,
  IN ULONG DriverObjectExtensionSize,
  OUT PVOID *DriverObjectExtension);

NTKERNELAPI
PVOID
NTAPI
IoAllocateErrorLogEntry(
  IN PVOID IoObject,
  IN UCHAR EntrySize);

NTKERNELAPI
PIRP
NTAPI
IoAllocateIrp(
  IN CCHAR StackSize,
  IN BOOLEAN ChargeQuota);

NTKERNELAPI
PMDL
NTAPI
IoAllocateMdl(
  IN PVOID VirtualAddress OPTIONAL,
  IN ULONG Length,
  IN BOOLEAN SecondaryBuffer,
  IN BOOLEAN ChargeQuota,
  IN OUT PIRP Irp OPTIONAL);

NTKERNELAPI
PIO_WORKITEM
NTAPI
IoAllocateWorkItem(
  IN PDEVICE_OBJECT DeviceObject);

NTKERNELAPI
NTSTATUS
NTAPI
IoAttachDevice(
  IN PDEVICE_OBJECT SourceDevice,
  IN PUNICODE_STRING TargetDevice,
  OUT PDEVICE_OBJECT *AttachedDevice);

NTKERNELAPI
PDEVICE_OBJECT
NTAPI
IoAttachDeviceToDeviceStack(
  IN PDEVICE_OBJECT SourceDevice,
  IN PDEVICE_OBJECT TargetDevice);

NTKERNELAPI
PIRP
NTAPI
IoBuildAsynchronousFsdRequest(
  IN ULONG MajorFunction,
  IN PDEVICE_OBJECT DeviceObject,
  IN OUT PVOID Buffer OPTIONAL,
  IN ULONG Length OPTIONAL,
  IN PLARGE_INTEGER StartingOffset OPTIONAL,
  IN PIO_STATUS_BLOCK IoStatusBlock OPTIONAL);

NTKERNELAPI
PIRP
NTAPI
IoBuildDeviceIoControlRequest(
  IN ULONG IoControlCode,
  IN PDEVICE_OBJECT DeviceObject,
  IN PVOID InputBuffer OPTIONAL,
  IN ULONG InputBufferLength,
  OUT PVOID OutputBuffer OPTIONAL,
  IN ULONG OutputBufferLength,
  IN BOOLEAN InternalDeviceIoControl,
  IN PKEVENT Event,
  OUT PIO_STATUS_BLOCK IoStatusBlock);

NTKERNELAPI
VOID
NTAPI
IoBuildPartialMdl(
  IN PMDL SourceMdl,
  IN OUT PMDL TargetMdl,
  IN PVOID VirtualAddress,
  IN ULONG Length);

NTKERNELAPI
PIRP
NTAPI
IoBuildSynchronousFsdRequest(
  IN ULONG MajorFunction,
  IN PDEVICE_OBJECT DeviceObject,
  IN OUT PVOID Buffer OPTIONAL,
  IN ULONG Length OPTIONAL,
  IN PLARGE_INTEGER StartingOffset OPTIONAL,
  IN PKEVENT Event,
  OUT PIO_STATUS_BLOCK IoStatusBlock);

NTKERNELAPI
NTSTATUS
FASTCALL
IofCallDriver(
  IN PDEVICE_OBJECT DeviceObject,
  IN OUT PIRP Irp);
#define IoCallDriver IofCallDriver

NTKERNELAPI
VOID
FASTCALL
IofCompleteRequest(
  IN PIRP Irp,
  IN CCHAR PriorityBoost);
#define IoCompleteRequest IofCompleteRequest

NTKERNELAPI
BOOLEAN
NTAPI
IoCancelIrp(
  IN PIRP Irp);

NTKERNELAPI
NTSTATUS
NTAPI
IoCheckShareAccess(
  IN ACCESS_MASK DesiredAccess,
  IN ULONG DesiredShareAccess,
  IN OUT PFILE_OBJECT FileObject,
  IN OUT PSHARE_ACCESS ShareAccess,
  IN BOOLEAN Update);

NTKERNELAPI
VOID
FASTCALL
IofCompleteRequest(
  IN PIRP Irp,
  IN CCHAR PriorityBoost);

NTKERNELAPI
NTSTATUS
NTAPI
IoConnectInterrupt(
  OUT PKINTERRUPT *InterruptObject,
  IN PKSERVICE_ROUTINE ServiceRoutine,
  IN PVOID ServiceContext OPTIONAL,
  IN PKSPIN_LOCK SpinLock OPTIONAL,
  IN ULONG Vector,
  IN KIRQL Irql,
  IN KIRQL SynchronizeIrql,
  IN KINTERRUPT_MODE InterruptMode,
  IN BOOLEAN ShareVector,
  IN KAFFINITY ProcessorEnableMask,
  IN BOOLEAN FloatingSave);

NTKERNELAPI
NTSTATUS
NTAPI
IoCreateDevice(
  IN PDRIVER_OBJECT DriverObject,
  IN ULONG DeviceExtensionSize,
  IN PUNICODE_STRING DeviceName OPTIONAL,
  IN DEVICE_TYPE DeviceType,
  IN ULONG DeviceCharacteristics,
  IN BOOLEAN Exclusive,
  OUT PDEVICE_OBJECT *DeviceObject);

NTKERNELAPI
NTSTATUS
NTAPI
IoCreateFile(
  OUT PHANDLE FileHandle,
  IN ACCESS_MASK DesiredAccess,
  IN POBJECT_ATTRIBUTES ObjectAttributes,
  OUT PIO_STATUS_BLOCK IoStatusBlock,
  IN PLARGE_INTEGER AllocationSize OPTIONAL,
  IN ULONG FileAttributes,
  IN ULONG ShareAccess,
  IN ULONG Disposition,
  IN ULONG CreateOptions,
  IN PVOID EaBuffer OPTIONAL,
  IN ULONG EaLength,
  IN CREATE_FILE_TYPE CreateFileType,
  IN PVOID InternalParameters OPTIONAL,
  IN ULONG Options);

NTKERNELAPI
PKEVENT
NTAPI
IoCreateNotificationEvent(
  IN PUNICODE_STRING EventName,
  OUT PHANDLE EventHandle);

NTKERNELAPI
NTSTATUS
NTAPI
IoCreateSymbolicLink(
  IN PUNICODE_STRING SymbolicLinkName,
  IN PUNICODE_STRING DeviceName);

NTKERNELAPI
PKEVENT
NTAPI
IoCreateSynchronizationEvent(
  IN PUNICODE_STRING EventName,
  OUT PHANDLE EventHandle);

NTKERNELAPI
NTSTATUS
NTAPI
IoCreateUnprotectedSymbolicLink(
  IN PUNICODE_STRING SymbolicLinkName,
  IN PUNICODE_STRING DeviceName);

NTKERNELAPI
VOID
NTAPI
IoDeleteDevice(
  IN PDEVICE_OBJECT DeviceObject);

NTKERNELAPI
NTSTATUS
NTAPI
IoDeleteSymbolicLink(
  IN PUNICODE_STRING SymbolicLinkName);

NTKERNELAPI
VOID
NTAPI
IoDetachDevice(
  IN OUT PDEVICE_OBJECT TargetDevice);

NTKERNELAPI
VOID
NTAPI
IoDisconnectInterrupt(
  IN PKINTERRUPT InterruptObject);

NTKERNELAPI
VOID
NTAPI
IoFreeIrp(
  IN PIRP Irp);

NTKERNELAPI
VOID
NTAPI
IoFreeMdl(
  IN PMDL Mdl);

NTKERNELAPI
VOID
NTAPI
IoFreeWorkItem(
  IN PIO_WORKITEM IoWorkItem);

NTKERNELAPI
PDEVICE_OBJECT
NTAPI
IoGetAttachedDevice(
  IN PDEVICE_OBJECT DeviceObject);

NTKERNELAPI
PDEVICE_OBJECT
NTAPI
IoGetAttachedDeviceReference(
  IN PDEVICE_OBJECT DeviceObject);

NTKERNELAPI
NTSTATUS
NTAPI
IoGetBootDiskInformation(
  IN OUT PBOOTDISK_INFORMATION BootDiskInformation,
  IN ULONG Size);

NTKERNELAPI
NTSTATUS
NTAPI
IoGetDeviceInterfaceAlias(
  IN PUNICODE_STRING SymbolicLinkName,
  IN CONST GUID *AliasInterfaceClassGuid,
  OUT PUNICODE_STRING AliasSymbolicLinkName);

NTKERNELAPI
PEPROCESS
NTAPI
IoGetCurrentProcess(VOID);

NTKERNELAPI
NTSTATUS
NTAPI
IoGetDeviceInterfaces(
  IN CONST GUID *InterfaceClassGuid,
  IN PDEVICE_OBJECT PhysicalDeviceObject OPTIONAL,
  IN ULONG Flags,
  OUT PWSTR *SymbolicLinkList);

NTKERNELAPI
NTSTATUS
NTAPI
IoGetDeviceObjectPointer(
  IN PUNICODE_STRING ObjectName,
  IN ACCESS_MASK DesiredAccess,
  OUT PFILE_OBJECT *FileObject,
  OUT PDEVICE_OBJECT *DeviceObject);

NTKERNELAPI
NTSTATUS
NTAPI
IoGetDeviceProperty(
  IN PDEVICE_OBJECT DeviceObject,
  IN DEVICE_REGISTRY_PROPERTY DeviceProperty,
  IN ULONG BufferLength,
  OUT PVOID PropertyBuffer,
  OUT PULONG ResultLength);

NTKERNELAPI
PDMA_ADAPTER
NTAPI
IoGetDmaAdapter(
  IN PDEVICE_OBJECT PhysicalDeviceObject OPTIONAL,
  IN PDEVICE_DESCRIPTION DeviceDescription,
  IN OUT PULONG NumberOfMapRegisters);

NTKERNELAPI
PVOID
NTAPI
IoGetDriverObjectExtension(
  IN PDRIVER_OBJECT DriverObject,
  IN PVOID ClientIdentificationAddress);

NTKERNELAPI
PVOID
NTAPI
IoGetInitialStack(VOID);

NTKERNELAPI
PDEVICE_OBJECT
NTAPI
IoGetRelatedDeviceObject(
  IN PFILE_OBJECT FileObject);

NTKERNELAPI
VOID
NTAPI
IoQueueWorkItem(
  IN PIO_WORKITEM IoWorkItem,
  IN PIO_WORKITEM_ROUTINE WorkerRoutine,
  IN WORK_QUEUE_TYPE QueueType,
  IN PVOID Context OPTIONAL);

NTKERNELAPI
VOID
NTAPI
IoInitializeIrp(
  IN OUT PIRP Irp,
  IN USHORT PacketSize,
  IN CCHAR StackSize);

NTKERNELAPI
VOID
NTAPI
IoInitializeRemoveLockEx(
  IN PIO_REMOVE_LOCK Lock,
  IN ULONG AllocateTag,
  IN ULONG MaxLockedMinutes,
  IN ULONG HighWatermark,
  IN ULONG RemlockSize);

NTKERNELAPI
NTSTATUS
NTAPI
IoInitializeTimer(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIO_TIMER_ROUTINE TimerRoutine,
  IN PVOID Context OPTIONAL);

NTKERNELAPI
VOID
NTAPI
IoInvalidateDeviceRelations(
  IN PDEVICE_OBJECT DeviceObject,
  IN DEVICE_RELATION_TYPE Type);

NTKERNELAPI
VOID
NTAPI
IoInvalidateDeviceState(
  IN PDEVICE_OBJECT PhysicalDeviceObject);

NTKERNELAPI
BOOLEAN
NTAPI
IoIsWdmVersionAvailable(
  IN UCHAR MajorVersion,
  IN UCHAR MinorVersion);

NTKERNELAPI
NTSTATUS
NTAPI
IoOpenDeviceInterfaceRegistryKey(
  IN PUNICODE_STRING SymbolicLinkName,
  IN ACCESS_MASK DesiredAccess,
  OUT PHANDLE DeviceInterfaceKey);

NTKERNELAPI
NTSTATUS
NTAPI
IoOpenDeviceRegistryKey(
  IN PDEVICE_OBJECT DeviceObject,
  IN ULONG DevInstKeyType,
  IN ACCESS_MASK DesiredAccess,
  OUT PHANDLE DevInstRegKey);

NTKERNELAPI
NTSTATUS
NTAPI
IoRegisterDeviceInterface(
  IN PDEVICE_OBJECT PhysicalDeviceObject,
  IN CONST GUID *InterfaceClassGuid,
  IN PUNICODE_STRING ReferenceString OPTIONAL,
  OUT PUNICODE_STRING SymbolicLinkName);

NTKERNELAPI
NTSTATUS
NTAPI
IoRegisterPlugPlayNotification(
  IN IO_NOTIFICATION_EVENT_CATEGORY EventCategory,
  IN ULONG EventCategoryFlags,
  IN PVOID EventCategoryData OPTIONAL,
  IN PDRIVER_OBJECT DriverObject,
  IN PDRIVER_NOTIFICATION_CALLBACK_ROUTINE CallbackRoutine,
  IN OUT PVOID Context OPTIONAL,
  OUT PVOID *NotificationEntry);

NTKERNELAPI
NTSTATUS
NTAPI
IoRegisterShutdownNotification(
  IN PDEVICE_OBJECT DeviceObject);

NTKERNELAPI
VOID
NTAPI
IoReleaseCancelSpinLock(
  IN KIRQL Irql);

NTKERNELAPI
VOID
NTAPI
IoReleaseRemoveLockAndWaitEx(
  IN PIO_REMOVE_LOCK RemoveLock,
  IN PVOID Tag OPTIONAL,
  IN ULONG RemlockSize);

NTKERNELAPI
VOID
NTAPI
IoReleaseRemoveLockEx(
  IN PIO_REMOVE_LOCK RemoveLock,
  IN PVOID Tag OPTIONAL,
  IN ULONG RemlockSize);

NTKERNELAPI
VOID
NTAPI
IoRemoveShareAccess(
  IN PFILE_OBJECT FileObject,
  IN OUT PSHARE_ACCESS ShareAccess);

NTKERNELAPI
NTSTATUS
NTAPI
IoReportTargetDeviceChange(
  IN PDEVICE_OBJECT PhysicalDeviceObject,
  IN PVOID NotificationStructure);

NTKERNELAPI
NTSTATUS
NTAPI
IoReportTargetDeviceChangeAsynchronous(
  IN PDEVICE_OBJECT PhysicalDeviceObject,
  IN PVOID NotificationStructure,
  IN PDEVICE_CHANGE_COMPLETE_CALLBACK Callback OPTIONAL,
  IN PVOID Context OPTIONAL);

NTKERNELAPI
VOID
NTAPI
IoRequestDeviceEject(
  IN PDEVICE_OBJECT PhysicalDeviceObject);

NTKERNELAPI
VOID
NTAPI
IoReuseIrp(
  IN OUT PIRP Irp,
  IN NTSTATUS Status);

NTKERNELAPI
NTSTATUS
NTAPI
IoSetDeviceInterfaceState(
  IN PUNICODE_STRING SymbolicLinkName,
  IN BOOLEAN Enable);

NTKERNELAPI
VOID
NTAPI
IoSetShareAccess(
  IN ACCESS_MASK DesiredAccess,
  IN ULONG DesiredShareAccess,
  IN OUT PFILE_OBJECT FileObject,
  OUT PSHARE_ACCESS ShareAccess);

NTKERNELAPI
VOID
NTAPI
IoStartNextPacket(
  IN PDEVICE_OBJECT DeviceObject,
  IN BOOLEAN Cancelable);

NTKERNELAPI
VOID
NTAPI
IoStartNextPacketByKey(
  IN PDEVICE_OBJECT DeviceObject,
  IN BOOLEAN Cancelable,
  IN ULONG Key);

NTKERNELAPI
VOID
NTAPI
IoStartPacket(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIRP Irp,
  IN PULONG Key OPTIONAL,
  IN PDRIVER_CANCEL CancelFunction OPTIONAL);

NTKERNELAPI
VOID
NTAPI
IoStartTimer(
  IN PDEVICE_OBJECT DeviceObject);

NTKERNELAPI
VOID
NTAPI
IoStopTimer(
  IN PDEVICE_OBJECT DeviceObject);

NTKERNELAPI
NTSTATUS
NTAPI
IoUnregisterPlugPlayNotification(
  IN PVOID NotificationEntry);

NTKERNELAPI
VOID
NTAPI
IoUnregisterShutdownNotification(
  IN PDEVICE_OBJECT DeviceObject);

NTKERNELAPI
VOID
NTAPI
IoUpdateShareAccess(
  IN PFILE_OBJECT FileObject,
  IN OUT PSHARE_ACCESS ShareAccess);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIAllocateInstanceIds(
  IN GUID *Guid,
  IN ULONG InstanceCount,
  OUT ULONG *FirstInstanceId);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIQuerySingleInstanceMultiple(
  IN PVOID *DataBlockObjectList,
  IN PUNICODE_STRING InstanceNames,
  IN ULONG ObjectCount,
  IN OUT ULONG *InOutBufferSize,
  OUT PVOID OutBuffer);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIRegistrationControl(
  IN PDEVICE_OBJECT DeviceObject,
  IN ULONG Action);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMISuggestInstanceName(
  IN PDEVICE_OBJECT PhysicalDeviceObject OPTIONAL,
  IN PUNICODE_STRING SymbolicLinkName OPTIONAL,
  IN BOOLEAN CombineNames,
  OUT PUNICODE_STRING SuggestedInstanceName);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIWriteEvent(
  IN PVOID WnodeEventItem);

NTKERNELAPI
VOID
NTAPI
IoWriteErrorLogEntry(
  IN PVOID ElEntry);

#endif /* (NTDDI_VERSION >= NTDDI_WIN2K) */

#if (NTDDI_VERSION >= NTDDI_WINXP)

NTKERNELAPI
NTSTATUS
NTAPI
IoCsqInitialize(
  IN PIO_CSQ Csq,
  IN PIO_CSQ_INSERT_IRP CsqInsertIrp,
  IN PIO_CSQ_REMOVE_IRP CsqRemoveIrp,
  IN PIO_CSQ_PEEK_NEXT_IRP CsqPeekNextIrp,
  IN PIO_CSQ_ACQUIRE_LOCK CsqAcquireLock,
  IN PIO_CSQ_RELEASE_LOCK CsqReleaseLock,
  IN PIO_CSQ_COMPLETE_CANCELED_IRP CsqCompleteCanceledIrp);

NTKERNELAPI
VOID
NTAPI
IoCsqInsertIrp(
  IN PIO_CSQ Csq,
  IN PIRP Irp,
  IN PIO_CSQ_IRP_CONTEXT Context OPTIONAL);

NTKERNELAPI
PIRP
NTAPI
IoCsqRemoveIrp(
  IN PIO_CSQ Csq,
  IN PIO_CSQ_IRP_CONTEXT Context);

NTKERNELAPI
PIRP
NTAPI
IoCsqRemoveNextIrp(
  IN PIO_CSQ Csq,
  IN PVOID PeekContext);

NTKERNELAPI
BOOLEAN
NTAPI
IoForwardIrpSynchronously(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIRP Irp);

#define IoForwardAndCatchIrp IoForwardIrpSynchronously

NTKERNELAPI
VOID
NTAPI
IoFreeErrorLogEntry(
  PVOID ElEntry);

NTKERNELAPI
NTSTATUS
NTAPI
IoSetCompletionRoutineEx(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIRP Irp,
  IN PIO_COMPLETION_ROUTINE CompletionRoutine,
  IN PVOID Context,
  IN BOOLEAN InvokeOnSuccess,
  IN BOOLEAN InvokeOnError,
  IN BOOLEAN InvokeOnCancel);

VOID
NTAPI
IoSetStartIoAttributes(
  IN PDEVICE_OBJECT DeviceObject,
  IN BOOLEAN DeferredStartIo,
  IN BOOLEAN NonCancelable);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIDeviceObjectToInstanceName(
  IN PVOID DataBlockObject,
  IN PDEVICE_OBJECT DeviceObject,
  OUT PUNICODE_STRING InstanceName);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIExecuteMethod(
  IN PVOID DataBlockObject,
  IN PUNICODE_STRING InstanceName,
  IN ULONG MethodId,
  IN ULONG InBufferSize,
  IN OUT PULONG OutBufferSize,
  IN OUT  PUCHAR InOutBuffer);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIHandleToInstanceName(
  IN PVOID DataBlockObject,
  IN HANDLE FileHandle,
  OUT PUNICODE_STRING InstanceName);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIOpenBlock(
  IN GUID *DataBlockGuid,
  IN ULONG DesiredAccess,
  OUT PVOID *DataBlockObject);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIQueryAllData(
  IN PVOID DataBlockObject,
  IN OUT ULONG *InOutBufferSize,
  OUT PVOID OutBuffer);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIQueryAllDataMultiple(
  IN PVOID *DataBlockObjectList,
  IN ULONG ObjectCount,
  IN OUT ULONG *InOutBufferSize,
  OUT PVOID OutBuffer);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMIQuerySingleInstance(
  IN PVOID DataBlockObject,
  IN PUNICODE_STRING InstanceName,
  IN OUT ULONG *InOutBufferSize,
  OUT PVOID OutBuffer);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMISetNotificationCallback(
  IN OUT PVOID Object,
  IN WMI_NOTIFICATION_CALLBACK Callback,
  IN PVOID Context OPTIONAL);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMISetSingleInstance(
  IN PVOID DataBlockObject,
  IN PUNICODE_STRING InstanceName,
  IN ULONG Version,
  IN ULONG ValueBufferSize,
  IN PVOID ValueBuffer);

NTKERNELAPI
NTSTATUS
NTAPI
IoWMISetSingleItem(
  IN PVOID DataBlockObject,
  IN PUNICODE_STRING InstanceName,
  IN ULONG DataItemId,
  IN ULONG Version,
  IN ULONG ValueBufferSize,
  IN PVOID ValueBuffer);

#endif /* (NTDDI_VERSION >= NTDDI_WINXP) */

#if defined(_WIN64)
NTKERNELAPI
ULONG
NTAPI
IoWMIDeviceObjectToProviderId(
  IN PDEVICE_OBJECT DeviceObject);
#else
#define IoWMIDeviceObjectToProviderId(DeviceObject) ((ULONG)(DeviceObject))
#endif

/*
 * USHORT
 * IoSizeOfIrp(
 *   IN CCHAR  StackSize)
 */
#define IoSizeOfIrp(_StackSize) \
  ((USHORT) (sizeof(IRP) + ((_StackSize) * (sizeof(IO_STACK_LOCATION)))))

FORCEINLINE
VOID
IoSkipCurrentIrpStackLocation(
  IN OUT PIRP Irp)
{
  ASSERT(Irp->CurrentLocation <= Irp->StackCount);
  Irp->CurrentLocation++;
  Irp->Tail.Overlay.CurrentStackLocation++;
}

FORCEINLINE
VOID
IoSetNextIrpStackLocation(
  IN OUT PIRP Irp)
{
  ASSERT(Irp->CurrentLocation > 0);
  Irp->CurrentLocation--;
  Irp->Tail.Overlay.CurrentStackLocation--;
}

FORCEINLINE
PIO_STACK_LOCATION
IoGetNextIrpStackLocation(
  IN PIRP Irp)
{
  ASSERT(Irp->CurrentLocation > 0);
  return ((Irp)->Tail.Overlay.CurrentStackLocation - 1 );
}

FORCEINLINE
VOID
IoSetCompletionRoutine(
  IN PIRP Irp,
  IN PIO_COMPLETION_ROUTINE CompletionRoutine OPTIONAL,
  IN PVOID Context OPTIONAL,
  IN BOOLEAN InvokeOnSuccess,
  IN BOOLEAN InvokeOnError,
  IN BOOLEAN InvokeOnCancel)
{
  PIO_STACK_LOCATION irpSp;
  ASSERT( (InvokeOnSuccess || InvokeOnError || InvokeOnCancel) ? (CompletionRoutine != NULL) : TRUE );
  irpSp = IoGetNextIrpStackLocation(Irp);
  irpSp->CompletionRoutine = CompletionRoutine;
  irpSp->Context = Context;
  irpSp->Control = 0;

  if (InvokeOnSuccess) {
    irpSp->Control = SL_INVOKE_ON_SUCCESS;
  }

  if (InvokeOnError) {
    irpSp->Control |= SL_INVOKE_ON_ERROR;
  }

  if (InvokeOnCancel) {
    irpSp->Control |= SL_INVOKE_ON_CANCEL;
  }
}

/*
 * PDRIVER_CANCEL
 * IoSetCancelRoutine(
 *   IN PIRP  Irp,
 *   IN PDRIVER_CANCEL  CancelRoutine)
 */
#define IoSetCancelRoutine(_Irp, \
                           _CancelRoutine) \
  ((PDRIVER_CANCEL) (ULONG_PTR) InterlockedExchangePointer( \
    (PVOID *) &(_Irp)->CancelRoutine, (PVOID) (ULONG_PTR) (_CancelRoutine)))

/*
 * VOID
 * IoRequestDpc(
 *   IN PDEVICE_OBJECT  DeviceObject,
 *   IN PIRP  Irp,
 *   IN PVOID  Context);
 */
#define IoRequestDpc(DeviceObject, Irp, Context)( \
  KeInsertQueueDpc(&(DeviceObject)->Dpc, (Irp), (Context)))

/*
 * VOID
 * IoReleaseRemoveLock(
 *   IN PIO_REMOVE_LOCK  RemoveLock,
 *   IN PVOID  Tag)
 */
#define IoReleaseRemoveLock(_RemoveLock, \
                            _Tag) \
  IoReleaseRemoveLockEx(_RemoveLock, _Tag, sizeof(IO_REMOVE_LOCK))

/*
 * VOID
 * IoReleaseRemoveLockAndWait(
 *   IN PIO_REMOVE_LOCK  RemoveLock,
 *   IN PVOID  Tag)
 */
#define IoReleaseRemoveLockAndWait(_RemoveLock, \
                                   _Tag) \
  IoReleaseRemoveLockAndWaitEx(_RemoveLock, _Tag, sizeof(IO_REMOVE_LOCK))

#if defined(_WIN64)
NTKERNELAPI
BOOLEAN
IoIs32bitProcess(
  IN PIRP Irp OPTIONAL);
#endif

#define PLUGPLAY_REGKEY_DEVICE                            1
#define PLUGPLAY_REGKEY_DRIVER                            2
#define PLUGPLAY_REGKEY_CURRENT_HWPROFILE                 4

FORCEINLINE
PIO_STACK_LOCATION
IoGetCurrentIrpStackLocation(
  IN PIRP Irp)
{
  ASSERT(Irp->CurrentLocation <= Irp->StackCount + 1);
  return Irp->Tail.Overlay.CurrentStackLocation;
}

FORCEINLINE
VOID
IoMarkIrpPending(
  IN OUT PIRP Irp)
{
  IoGetCurrentIrpStackLocation( (Irp) )->Control |= SL_PENDING_RETURNED;
}

/*
 * BOOLEAN
 * IoIsErrorUserInduced(
 *   IN NTSTATUS  Status);
 */
#define IoIsErrorUserInduced(Status) \
   ((BOOLEAN)(((Status) == STATUS_DEVICE_NOT_READY) || \
   ((Status) == STATUS_IO_TIMEOUT) || \
   ((Status) == STATUS_MEDIA_WRITE_PROTECTED) || \
   ((Status) == STATUS_NO_MEDIA_IN_DEVICE) || \
   ((Status) == STATUS_VERIFY_REQUIRED) || \
   ((Status) == STATUS_UNRECOGNIZED_MEDIA) || \
   ((Status) == STATUS_WRONG_VOLUME)))

/* VOID
 * IoInitializeRemoveLock(
 *   IN PIO_REMOVE_LOCK  Lock,
 *   IN ULONG  AllocateTag,
 *   IN ULONG  MaxLockedMinutes,
 *   IN ULONG  HighWatermark)
 */
#define IoInitializeRemoveLock( \
  Lock, AllocateTag, MaxLockedMinutes, HighWatermark) \
  IoInitializeRemoveLockEx(Lock, AllocateTag, MaxLockedMinutes, \
    HighWatermark, sizeof(IO_REMOVE_LOCK))

VOID
FORCEINLINE
IoInitializeDpcRequest(
  IN PDEVICE_OBJECT DeviceObject,
  IN PIO_DPC_ROUTINE DpcRoutine)
{
  KeInitializeDpc( &DeviceObject->Dpc,
                   (PKDEFERRED_ROUTINE) DpcRoutine,
                   DeviceObject );
}

#define DEVICE_INTERFACE_INCLUDE_NONACTIVE 0x00000001

/*
 * ULONG
 * IoGetFunctionCodeFromCtlCode(
 *   IN ULONG  ControlCode)
 */
#define IoGetFunctionCodeFromCtlCode(_ControlCode) \
  (((_ControlCode) >> 2) & 0x00000FFF)

FORCEINLINE
VOID
IoCopyCurrentIrpStackLocationToNext(
  IN PIRP Irp)
{
  PIO_STACK_LOCATION irpSp;
  PIO_STACK_LOCATION nextIrpSp;
  irpSp = IoGetCurrentIrpStackLocation(Irp);
  nextIrpSp = IoGetNextIrpStackLocation(Irp);
  RtlCopyMemory( nextIrpSp, irpSp, FIELD_OFFSET(IO_STACK_LOCATION, CompletionRoutine));
  nextIrpSp->Control = 0;
}

NTKERNELAPI
VOID
NTAPI
IoGetStackLimits(
  OUT PULONG_PTR LowLimit,
  OUT PULONG_PTR HighLimit);

FORCEINLINE
ULONG_PTR
IoGetRemainingStackSize(VOID)
{
  ULONG_PTR End, Begin;
  ULONG_PTR Result;

  IoGetStackLimits(&Begin, &End);
  Result = (ULONG_PTR)(&End) - Begin;
  return Result;
}

