/*++ BUILD Version: 0001    Increment this if a change has global effects

Copyright (c) 1985-1996, Microsoft Corporation

Module Name:


    windows.h

Abstract:

    Master include file for Windows applications.

--*/

#ifndef _WINDOWS_
#define _WINDOWS_
#pragma option push -b

#ifndef WINVER
#define WINVER 0x0400
#endif

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

/*  If defined, the following flags inhibit definition
 *     of the indicated items.
 *
 *  NOGDICAPMASKS     - CC_*, LC_*, PC_*, CP_*, TC_*, RC_
 *  NOVIRTUALKEYCODES - VK_*
 *  NOWINMESSAGES     - WM_*, EM_*, LB_*, CB_*
 *  NOWINSTYLES       - WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
 *  NOSYSMETRICS      - SM_*
 *  NOMENUS           - MF_*
 *  NOICONS           - IDI_*
 *  NOKEYSTATES       - MK_*
 *  NOSYSCOMMANDS     - SC_*
 *  NORASTEROPS       - Binary and Tertiary raster ops
 *  NOSHOWWINDOW      - SW_*
 *  OEMRESOURCE       - OEM Resource values
 *  NOATOM            - Atom Manager routines
 *  NOCLIPBOARD       - Clipboard routines
 *  NOCOLOR           - Screen colors
 *  NOCTLMGR          - Control and Dialog routines
 *  NODRAWTEXT        - DrawText() and DT_*
 *  NOGDI             - All GDI defines and routines
 *  NOKERNEL          - All KERNEL defines and routines
 *  NOUSER            - All USER defines and routines
 *  NONLS             - All NLS defines and routines
 *  NOMB              - MB_* and MessageBox()
 *  NOMEMMGR          - GMEM_*, LMEM_*, GHND, LHND, associated routines
 *  NOMETAFILE        - typedef METAFILEPICT
 *  NOMINMAX          - Macros min(a,b) and max(a,b)
 *  NOMSG             - typedef MSG and associated routines
 *  NOOPENFILE        - OpenFile(), OemToAnsi, AnsiToOem, and OF_*
 *  NOSCROLL          - SB_* and scrolling routines
 *  NOSERVICE         - All Service Controller routines, SERVICE_ equates, etc.
 *  NOSOUND           - Sound driver routines
 *  NOTEXTMETRIC      - typedef TEXTMETRIC and associated routines
 *  NOWH              - SetWindowsHook and WH_*
 *  NOWINOFFSETS      - GWL_*, GCL_*, associated routines
 *  NOCOMM            - COMM driver routines
 *  NOKANJI           - Kanji support stuff.
 *  NOHELP            - Help engine interface.
 *  NOPROFILER        - Profiler interface.
 *  NODEFERWINDOWPOS  - DeferWindowPos routines
 *  NOMCX             - Modem Configuration Extensions
 */

#if defined(RC_INVOKED) && !defined(NOWINRES)

#include <winresrc.h>

#else

#if defined(RC_INVOKED)
/* Turn off a bunch of stuff to ensure that RC files compile OK. */
#define NOATOM
#define NOGDI
#define NOGDICAPMASKS
#define NOMETAFILE
#define NOMINMAX
#define NOMSG
#define NOOPENFILE
#define NORASTEROPS
#define NOSCROLL
#define NOSOUND
#define NOSYSMETRICS
#define NOTEXTMETRIC
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOCRYPT
#define NOMCX
#endif

#if defined(__cplusplus) && defined(__BORLANDC__)
#include <mem.h> // Get correct namespace compliant protos for memcpy, etc.
                 // since WINDOWS.H and its associated files use them.
#endif

#if defined(__BORLANDC__)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400 /* If not set, assume NT 4.00  */
#endif
#if !defined(__MFC_COMPAT__)
#undef _ANONYMOUS_STRUCT /* The correct term */
#else
#define _ANONYMOUS_STRUCT /* on for __MFC_COMPAT__ support */
#endif
#if defined(__cplusplus)
#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
#endif
#define __inline inline
#else
#undef _ANONYMOUS_UNION /* The correct term */
#define NONAMELESSUNION /* Incorrect term, but MS keeps using it! */
#define __inline
#endif
#if defined(_UNICODE)
#define UNICODE
#endif
#if defined(__cplusplus)
// The following RTL functions are referred to in various macros defined
// in the Windows headers.  Since C++ now requires that most RTL functions
// appear in the std namespace, we must yank a copy of these into the
// global namespace so that the Windows Headers' non std:: scoped
// references to these RTL memxxx functions compile properly.
using std::memcmp;
using std::memcpy;
using std::memmove;
using std::memset;
#endif
#endif

#if !defined(_PPC_) && !defined(_ALPHA_) && !defined(_MIPS_) \
        && !defined(_X86_) && defined(_M_IX86)
#define _X86_
#endif

#if !defined(_PPC_) && !defined(_ALPHA_) && !defined(_X86_) \
        && !defined(_MIPS_) && defined(_M_MRX000)
#define _MIPS_
#endif

#if !defined(_PPC_) && !defined(_ALPHA_) && !defined(_X86_) \
        && !defined(_MIPS_) && defined(_M_ALPHA)
#define _ALPHA_
#endif

#if !defined(_PPC_) && !defined(_ALPHA_) && !defined(_X86_) \
        && !defined(_MIPS_) && defined(_M_PPC)
#define _PPC_
#endif

#ifndef RC_INVOKED
#if (_MSC_VER >= 800)
#pragma warning(disable : 4001)
#endif

#include <excpt.h>

#include <stdarg.h>

#endif /* RC_INVOKED */

#include <windef.h>

#include <winbase.h>

#include <wingdi.h>

#include <winuser.h>

#include <winnls.h>

#include <wincon.h>

#include <winver.h>

#include <winreg.h>

#include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN

#include <cderr.h>

#include <dde.h>

#include <ddeml.h>

#include <dlgs.h>

#include <lzexpand.h>

#include <mmsystem.h>

#include <nb30.h>

#include <rpc.h>

#include <shellapi.h>

#include <winperf.h>

#if (_WIN32_WINNT >= 0x0400)

#include <winsock2.h>

#include <mswsock.h>

#else

#include <winsock.h>

#endif /* _WIN32_WINNT >=  0x0400 */

#if (_WIN32_WINNT >= 0x0400)
#ifndef NOCRYPT

#include <wincrypt.h>

#endif
#endif /* _WIN32_WINNT >=  0x0400 */

#ifndef NOGDI

#include <commdlg.h>

#include <winspool.h>

#ifdef INC_OLE1

#include <ole.h>

#else

#include <ole2.h>

#endif /* !INC_OLE1 */
#endif /* !NOGDI */
#endif /* WIN32_LEAN_AND_MEAN */

#ifdef INC_OLE2

#include <ole2.h>

#endif /* INC_OLE2 */

#ifndef NOSERVICE

#include <winsvc.h>

#endif

#if (WINVER >= 0x0400)
#ifndef NOMCX

#include <mcx.h>

#endif /* NOMCX */

#ifndef NOIME

#include <imm.h>

#endif
#endif /* WINVER >= 0x0400 */

#ifndef RC_INVOKED
#if (_MSC_VER >= 800)
#pragma warning(default : 4001)
#endif
#endif /* RC_INVOKED */

#endif /* RC_INVOKED */

#endif /* _INC_WINDOWS */

#pragma option pop
#endif /* _WINDOWS_ */
