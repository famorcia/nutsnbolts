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
 *  Systems in Motion AS, Bygd�y all� 5, N-0257 Oslo, NORWAY. (www.sim.no)
 *
\**************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif // HAVE_CONFIG_H

#include <assert.h>

#include <Inventor/SoDB.h>

#include <NutsnBolts/NutsnBolts.h>
#include <NutsnBolts/nodes/NbViewerNavigationMode.h>
#include <NutsnBolts/navigation/NbNavigationSystem.h>
#include <NutsnBolts/navigation/NbNavigationMode.h>

// *************************************************************************

/*!
  \mainpage Nuts'n'Bolts v0.1

  The SIM Nuts'n'Bolts library is a library of useful utilities for
  viewer/applications developers.  The collection of classes is viewer-
  centric - you will not find nodes more suitable for any specific
  engineering-domains in this library.

  This library might not be upward compatible between major release
  versions.  Users of this library are therefore encouraged to use the
  NB_VERSION_# defines heavily to write code that can be built against
  multiple major versions of SIM Nuts'n'Bolts the APIs change.
*/

/*!
  \defgroup nodes
  \brief Scene graph nodes.

  The scene graph nodes you will find in SIM Nuts'n'Bolts.
*/

/*!
  \defgroup navigation
  \brief Camera navigation system.

  The classes related to user-interactive camera navigation.
*/

/*!
  \defgroup misc
  \brief Miscellaneous.

  The classes and files that don't belong to any particular group.
*/

/*!
  \defgroup internal
  \brief Internal code.

  The classes and files that are not part of the public API.
*/

/*!
  \class NutsnBolts NutsnBolts/NutsnBolts.h
  \brief Static namespace class for global funtions related to the
  SIM Nuts'n'Bolts library on the whole.

  This class contains just static functions that relate to library
  initialization and cleanup, and library versioning.

  \ingroup misc
*/

/*!
  This function initializes the SIM Nuts'n'Bolts library - all the
  classes and components.

  \sa NutsnBolts::clean
*/

void
NutsnBolts::init(void)
{
  NbViewerNavigationMode::initClass();
  NbNavigationMode::initClass();
  NbNavigationSystem::initClass();
#if 0
  coin_atexit(NutsnBolts::Clean);
#endif
}

/*!
  This function cleans up after all the Nuts'n'Bolts components.

  \sa NutsnBolts::init
*/

void
NutsnBolts::clean(void)
{
  NbNavigationSystem::cleanClass();
}

/*!
  This function returns the major version number (!.*.*) of the library.

  \sa NutsnBolts::getMinorVersion, NutsnBolts::getMicroVersion, NutsnBolts::getVersion
*/

int
NutsnBolts::getMajorVersion(void)
{
  return NB_MAJOR_VERSION;
}

/*!
  This function returns the minor version number (*.!.*) of the library.

  \sa NutsnBolts::getMajorVersion, NutsnBolts::getMicroVersion, NutsnBolts::getVersion
*/

int
NutsnBolts::getMinorVersion(void)
{
  return NB_MINOR_VERSION;
}

/*!
  This function returns the micro version number (*.*.!) of the library.

  \sa NutsnBolts::getMajorVersion, NutsnBolts::getMinorVersion, NutsnBolts::getVersion
*/

int
NutsnBolts::getMicroVersion(void)
{
  return NB_MICRO_VERSION;
}

/*!
  This function returns the version string for the library version.

  \sa NutsnBolts::getMajorVersion, NutsnBolts::getMinorVersion, NutsnBolts::getMicroVersion
*/

const char *
NutsnBolts::getVersion(void)
{
  static const char version[] = NB_VERSION;
  return version;
}

// *************************************************************************
