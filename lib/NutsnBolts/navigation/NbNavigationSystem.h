#ifndef NB_NAVIGATIONSYSTEM_H
#define NB_NAVIGATIONSYSTEM_H

/**************************************************************************\
 *
 *  This file is part of the SIM Nuts'n'Bolts extension library for Coin.
 *  Copyright (C) 1998-2005 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License ("GPL") version 2
 *  as published by the Free Software Foundation.  See the file COPYING
 *  at the root directory of this source distribution for additional
 *  information about the GNU GPL.
 *
 *  For using SIM Nuts'n'Bolts with software that can not be combined with
 *  the GNU GPL, and for taking advantage of the additional benefits of
 *  our support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion AS, Bygd��y all�� 5, N-0257 Oslo, NORWAY. (www.sim.no)
 *
\**************************************************************************/

#include <Inventor/SbName.h>

#include <NutsnBolts/Basic.h>

class SbViewportRegion;
class SoNode;
class SoCamera;
class SoEvent;

class NbNavigationMode;
class NbNavigationSystem;

#define NB_EXAMINER_SYSTEM              "examiner"
#define NB_EXAMINER_IDLE_MODE           "examiner:idle"
#define NB_EXAMINER_ROTATE_MODE         "examiner:rotate"
#define NB_EXAMINER_WAITFORZOOM_MODE    "examiner:wait_for_zoom"
#define NB_EXAMINER_ZOOM_MODE           "examiner:zoom"
#define NB_EXAMINER_WAITFORPAN_MODE     "examiner:wait_for_pan"
#define NB_EXAMINER_PAN_MODE            "examiner:pan"

// some simple button1-modes
#define NB_PANNER_SYSTEM                "panner"
#define NB_PANNER_IDLE_MODE             "panner:idle"
#define NB_PANNER_PAN_MODE              "panner:pan"

#define NB_ZOOMER_SYSTEM                "zoomer"
#define NB_ZOOMER_IDLE_MODE             "zoomer:idle"
#define NB_ZOOMER_ZOOM_MODE             "zoomer:zoom"

#define NB_ROTATER_SYSTEM               "rotater"
#define NB_ROTATER_IDLE_MODE            "rotater:idle"
#define NB_ROTATER_ROTATE_MODE          "rotater:rotate"

#define NB_DEFAULT_SYSTEM               NB_EXAMINER_SYSTEM

typedef
  void NbNavigationModeChangeCB(void * closure, NbNavigationSystem * system);

class NbNavigationSystemP;

class NB_DLL_API NbNavigationSystem {
public:
  static void initClass(void);
  static void cleanClass(void);

  static SbBool registerSystem(NbNavigationSystem * system);
  static SbBool unregisterSystem(NbNavigationSystem * system);
  static NbNavigationSystem * getByName(SbName name);

public:
  NbNavigationSystem(SbName name);
  ~NbNavigationSystem(void);

  void addModeChangeCallback(NbNavigationModeChangeCB * cb, void * closure);
  void removeModeChangeCallback(NbNavigationModeChangeCB * cb, void * closure);

  void setCamera(SoCamera * camera);
  void setViewport(const SbViewportRegion & viewport);

  SbBool processEvent(const SoEvent * event);

  SbName getName(void) const;

  SbName getCurrentModeName(void) const;
  const NbNavigationMode * getCurrentMode(void) const;
  
  enum TransitionType {
    INITIAL,
    STACK,
    SWITCH,
    FINISH,
    ABORT
  };

  void addMode(NbNavigationMode * mode);
  void addModeTransition(NbNavigationMode * mode,
			 TransitionType type,
			 const SoEvent * trigger = NULL,
			 const SoEvent * condition = NULL);
  void addModeTransition(NbNavigationMode * mode1,
			 NbNavigationMode * mode2,
			 TransitionType type,
			 const SoEvent * trigger,
			 const SoEvent * condition = NULL);

protected:
  void invokeModeChangeCallbacks(void);

private:
  NbNavigationSystemP * pimpl;

}; // NbNavigationSystem

#endif // !NB_NAVIGATIONSYSTEM_H
