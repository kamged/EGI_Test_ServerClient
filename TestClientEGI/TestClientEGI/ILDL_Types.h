#ifndef ILDL_TYPES_H
#define ILDL_TYPES_H

#pragma once
#include "UInt16_PreType.h"
#include "Int8_PreType.h"

struct ILDL_TYPES
{
	/// <summary>
	/// Ground speed [km/h]
	/// </summary>
	UInt16_PreType RPrsntGndSpd;

	/// <summary>
	/// Vertical speed [m/s]
	/// </summary>
	UInt16_PreType VerticalSpd;

	/// <summary>
	/// Heading [0° - 360°]
	/// </summary>
	UInt16_PreType Heading;
	/// <summary>
	/// True Airspeed [km/h]
	/// </summary>
	UInt16_PreType TAS;

	/// <summary>
	/// Indicated Airspeed [km/h]
	/// </summary>
	UInt16_PreType IAS;

	/// <summary>
	/// Raw attitude [+- 90°]
	/// </summary>
	Int8_PreType R_Att;

	/// <summary>
	/// Pitch attitude [+- 90°]
	/// </summary>
	Int8_PreType P_Att;

	/// <summary>
	/// Yaw attitude [+- 90°]
	/// </summary>
	Int8_PreType Y_Att;
};

#endif // ! ILDL_TYPES_H