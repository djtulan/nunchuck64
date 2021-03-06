//=============================================================================
// *** Nunchuk64 ***
// Copyright (c) Robert Grasböck, All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//=============================================================================
/// @file   controller.h
/// @author Robert Grasböck (robert.grasboeck@gmail.com)
/// @date   December, 2017
/// @brief  i2c controller
//=============================================================================
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <stdint.h>

/// \brief 6 bytes of controller data
typedef struct {
  uint8_t byte[6];  ///< 6 data bytes
} ContollerData;

/// \brief enumeration of different controller IDs
typedef enum {
  ID_Unknown,                           ///< 0 unknown
  ID_Nunchuck,                          ///< 1 Nunchuck
  ID_Wii_Classic,                       ///< 2 Wii Classic
  ID_Wii_Classic_Pro,                   ///< 3 Wii Classic Pro
  ID_NES_Classic_Mini_Clone_Encrypted,  ///< 4 NES Classic Mini Clone encrypted
  ID_8Bitdo_SF30,                       ///< 5 8Bitdo SF30
  // room for new IDs
  MAX_IDs           ///< number of different supported ids
} ControllerID;

/**
* @brief send init sequence to controller
*
*/
extern void controller_init(void);

/**
* @brief read current controller data
*
* @param [out] cd a struct of 6 bytes to store data of the controller
* @return TRUE ... if read was ok / FALSE ... if read error
*/
extern uint8_t controller_read(ContollerData *cd);

/**
* @brief get controller id
*
* @return enum ControllerID / MAX_IDs ... if id not found
*/
extern ControllerID get_id(void);

#endif
