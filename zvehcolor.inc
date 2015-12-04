/*

	About: vehicle color & paintjob system
	Author:	ziggi

	Usage:
		GetVehicleColor(vehicleid, &color1, &color2)
		GetVehiclePaintjob(vehicleid)

*/

#if !defined _samp_included
	#error "Please include a_samp or a_npc before zvehcolor"
#endif

#if defined _zvehcolor_included
	#endinput
#endif

#define _zvehcolor_included
#pragma library zvehcolor

/*

	Define const

*/


/*

	Define functions

*/


/*

	Enums

*/


/*

	Vars

*/

static
	gColor1[MAX_VEHICLES char],
	gColor2[MAX_VEHICLES char],
	gPaintjob[MAX_VEHICLES char];

/*

	Public color functions

*/

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	gColor1{vehicleid} = color1;
	gColor2{vehicleid} = color2;

	#if defined zvc_OnVehicleRespray
		return zvc_OnVehicleRespray(playerid, vehicleid, color1, color2);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnVehicleRespray
	#undef OnVehicleRespray
#else
	#define _ALS_OnVehicleRespray
#endif
 
#define OnVehicleRespray zvc_OnVehicleRespray
#if defined zvc_OnVehicleRespray
	forward zvc_OnVehicleRespray(playerid, vehicleid, color1, color2);
#endif


stock zvc_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:angle, color1, color2)
{
	if (color1 == -1) {
		color1 = random(255);
	}

	if (color2 == -1) {
		color2 = random(255);
	}

	new id = AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, angle, color1, color2);

	gColor1{id} = color1;
	gColor2{id} = color2;

	return id;
}
#if defined _ALS_AddStaticVehicle
	#undef AddStaticVehicle
#else
	#define _ALS_AddStaticVehicle
#endif
 
#define AddStaticVehicle zvc_AddStaticVehicle


stock zvc_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:angle, color1, color2, respawn_delay, addsiren=0)
{
	if (color1 == -1) {
		color1 = random(255);
	}

	if (color2 == -1) {
		color2 = random(255);
	}

	new id = AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, angle, color1, color2, respawn_delay, addsiren);

	gColor1{id} = color1;
	gColor2{id} = color2;

	return id;
}
#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx
#else
	#define _ALS_AddStaticVehicleEx
#endif
 
#define AddStaticVehicleEx zvc_AddStaticVehicleEx


stock zvc_CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay, addsiren=0)
{
	if (color1 == -1) {
		color1 = random(255);
	}

	if (color2 == -1) {
		color2 = random(255);
	}

	new id = CreateVehicle(modelid, x, y, z, angle, color1, color2, respawn_delay, addsiren);

	gColor1{id} = color1;
	gColor2{id} = color2;

	return id;
}
#if defined _ALS_CreateVehicle
	#undef CreateVehicle
#else
	#define _ALS_CreateVehicle
#endif
 
#define CreateVehicle zvc_CreateVehicle


stock zvc_ChangeVehicleColor(vehicleid, color1, color2)
{
	if (color1 == -1) {
		color1 = random(255);
	}

	if (color2 == -1) {
		color2 = random(255);
	}

	new success = ChangeVehicleColor(vehicleid, color1, color2);

	if (success) {
		gColor1{vehicleid} = color1;
		gColor2{vehicleid} = color2;	
	}

	return success;
}
#if defined _ALS_ChangeVehicleColor
	#undef ChangeVehicleColor
#else
	#define _ALS_ChangeVehicleColor
#endif
 
#define ChangeVehicleColor zvc_ChangeVehicleColor


stock GetVehicleColor(vehicleid, &color1, &color2)
{
	color1 = gColor1{vehicleid};
	color2 = gColor2{vehicleid};
}

/*

	Public paintjob functions

*/

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	gPaintjob{vehicleid} = paintjobid;

	#if defined zvc_OnVehiclePaintjob
		return zvc_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnVehiclePaintjob
	#undef OnVehiclePaintjob
#else
	#define _ALS_OnVehiclePaintjob
#endif
 
#define OnVehiclePaintjob zvc_OnVehiclePaintjob
#if defined zvc_OnVehiclePaintjob
	forward zvc_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
#endif


stock zvc_ChangeVehiclePaintjob(vehicleid, paintjobid)
{
	gPaintjob{vehicleid} = paintjobid;

	return ChangeVehiclePaintjob(vehicleid, paintjobid);
}
#if defined _ALS_ChangeVehiclePaintjob
    #undef ChangeVehiclePaintjob
#else
    #define _ALS_ChangeVehiclePaintjob
#endif
 
#define ChangeVehiclePaintjob zvc_ChangeVehiclePaintjob


stock GetVehiclePaintjob(vehicleid)
{
	return gPaintjob{vehicleid};
}
