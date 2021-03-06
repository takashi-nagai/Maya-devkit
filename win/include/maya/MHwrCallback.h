#ifndef _MHwrCallback
#define _MHwrCallback
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related
// material (collectively the "Data") in these files contain unpublished
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its
// licensors,  which is protected by U.S. and Canadian federal copyright law
// and by international treaties.
//
// The Data may not be disclosed or distributed to third parties or be
// copied or duplicated, in whole or in part, without the prior written
// consent of Autodesk.
//
// The copyright notices in the Software and this entire statement,
// including the above license grant, this restriction and the following
// disclaimer, must be included in all copies of the Software, in whole
// or in part, and all derivative works of the Software, unless such copies
// or derivative works are solely in the form of machine-executable object
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE,
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES.
// ==========================================================================
//+
//
// CLASS:    MHwrCallback
//
// ****************************************************************************

#if defined __cplusplus


#include <maya/MTypes.h>

//! \ingroup OpenMayaRender
//! \brief Rendering Callbacks
/*!
This class is used to register callbacks to gain access to Maya's
Hardware Rendering device status. You can be notified of device creation, lost
reset and deletion.

To register callbacks, inherit from this class and override
deviceNew, deviceLost, deviceReset, deviceDeleted. Any
number of these methods can be overridden by the callback. Then
register the callbacks by calling the addCallback() method.

If multiple callbacks need to be registered, the order of invocation
can be set by adding each callback with a priority number, 0 being the
highest priority.
*/
class OPENMAYARENDER_EXPORT MHwrCallback {
public:
                    MHwrCallback();
	virtual			~MHwrCallback();

    // Methods to override, return true on success
    virtual void    deviceNew();
    virtual void	deviceLost();
    virtual void    deviceReset();
	virtual void	deviceDeleted();

    static void     addCallback(MHwrCallback*, int priority = 0);
    static void     removeCallback(MHwrCallback*);

private:
    const void*     internalData;
};

#endif /* __cplusplus */
#endif /* _MHwrCallback */

