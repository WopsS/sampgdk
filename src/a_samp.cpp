// Copyright (c) 2011 Zeex
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	 http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <sampgdk/config.h>
#include <sampgdk/export.h>
#include <sampgdk/amx/amx.h>

#include "fakeamx.h"
#include "natives.h"

SAMPGDK_EXPORT bool SAMPGDK_CALL SendClientMessage(int playerid, int color, const char *message) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SendClientMessage");
	FakeAmxHeapObject message_(message);
	cell params[] = {
		3 * 4,
		playerid,
		color,
		message_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SendClientMessageToAll(int color, const char *message) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SendClientMessageToAll");
	FakeAmxHeapObject message_(message);
	cell params[] = {
		2 * 4,
		color,
		message_.address()
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL SendPlayerMessageToPlayer(int playerid, int senderid, const char *message) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SendPlayerMessageToPlayer");
	FakeAmxHeapObject message_(message);
	cell params[] = {
		3 * 4,
		playerid,
		senderid,
		message_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL SendPlayerMessageToAll(int senderid, const char *message) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SendPlayerMessageToAll");
	FakeAmxHeapObject message_(message);
	cell params[] = {
		2 * 4,
		senderid,
		message_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL SendDeathMessage(int killer, int killee, int weapon) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SendDeathMessage");
	cell params[] = {
		3 * 4,
		killer,
		killee,
		weapon
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GameTextForAll(const char *text, int time, int style) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GameTextForAll");
	FakeAmxHeapObject text_(text);
	cell params[] = {
		3 * 4,
		text_.address(),
		time,
		style
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GameTextForPlayer(int playerid, const char *text, int time, int style) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GameTextForPlayer");
	FakeAmxHeapObject text_(text);
	cell params[] = {
		4 * 4,
		playerid,
		text_.address(),
		time,
		style
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL GetServerTickCount() {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetTickCount");
	return FakeAmx::GetInstance().CallNative(native, 0);
}

SAMPGDK_EXPORT int SAMPGDK_CALL GetMaxPlayers() {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetMaxPlayers");
	return FakeAmx::GetInstance().CallNative(native, 0);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SetGameModeText(const char *text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SetGameModeText");
	FakeAmxHeapObject text_(text);
	cell params[] = {
		1 * 4,
		text_.address()
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SetTeamCount(int count) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SetTeamCount");
	cell params[] = {
		1 * 4,
		count
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL AddPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z,
	float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo)
{
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("AddPlayerClass");
	cell params[] = {
		11 * 4,
		modelid,
		amx_ftoc(spawn_x),
		amx_ftoc(spawn_y),
		amx_ftoc(spawn_z),
		amx_ftoc(z_angle),
		weapon1,
		weapon1_ammo,
		weapon2,
		weapon2_ammo,
		weapon3,
		weapon3_ammo
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL AddPlayerClassEx(int teamid, int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle,
	int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo)
{
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("AddPlayerClassEx");
	cell params[] = {
		12 * 4,
		teamid,
		modelid,
		amx_ftoc(spawn_x),
		amx_ftoc(spawn_y),
		amx_ftoc(spawn_z),
		amx_ftoc(z_angle),
		weapon1,
		weapon1_ammo,
		weapon2,
		weapon2_ammo,
		weapon3,
		weapon3_ammo
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL AddStaticVehicle(int modelid, float spawn_x, float spawn_y, float spawn_z,
	float z_angle, int color1, int color2)
{
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("AddStaticVehicle");
	cell params[] = {
		7 * 4,
		modelid,
		amx_ftoc(spawn_x),
		amx_ftoc(spawn_y),
		amx_ftoc(spawn_z),
		amx_ftoc(z_angle),
		color1,
		color2
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL AddStaticVehicleEx(int modelid, float spawn_x, float spawn_y, float spawn_z,
	float z_angle, int color1, int color2, int respawn_delay)
{
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("AddStaticVehicleEx");
	cell params[] = {
		8 * 4,
		modelid,
		amx_ftoc(spawn_x),
		amx_ftoc(spawn_y),
		amx_ftoc(spawn_z),
		amx_ftoc(z_angle),
		color1,
		color2,
		respawn_delay
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL AddStaticPickup(int model, int type, float x, float y, float z, int virtualworld) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("AddStaticPickup");
	cell params[] = {
		6 * 4,
		model,
		type,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z),
		virtualworld
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL CreatePickup(int model, int type, float x, float y, float z, int virtualworld) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("CreatePickup");
	cell params[] = {
		6 * 4,
		model,
		type,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z),
		virtualworld
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL DestroyPickup(int pickup) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("DestroyPickup");
	cell params[] = {
		1 * 4,
		pickup
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL ShowNameTags(bool show) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("ShowNameTags");
	cell params[] = {
		1 * 4,
		show
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL ShowPlayerMarkers(bool show) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("ShowPlayerMarkers");
	cell params[] = {
		1 * 4,
		show
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL GameModeExit() {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GameModeExit");
	FakeAmx::GetInstance().CallNative(native, 0);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL SetWorldTime(short hour) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SetWorldTime");
	cell params[] = {
		1 * 4,
		hour
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GetWeaponName(int weaponid, char *name, size_t size) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetWeaponName");
	FakeAmxHeapObject name_(size);
	cell params[] = {
		3 * 4,
		weaponid,
		name_.address(),
		size
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	name_.GetAsString(name, size);
	return ret;
}

SAMPGDK_EXPORT void SAMPGDK_CALL EnableTirePopping(bool enable) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("EnableTirePopping");
	cell params[] = {
		1 * 4,
		enable
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL AllowInteriorWeapons(bool allow) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("AllowInteriorWeapons");
	cell params[] = {
		1 * 4,
		allow
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SetWeather(int weatherid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SetWeather");
	cell params[] = {
		1 * 4,
		weatherid
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SetGravity(float gravity) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SetGravity");
	cell params[] = {
		1 * 4,
		amx_ftoc(gravity)
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL AllowAdminTeleport(bool allow) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("AllowAdminTeleport");
	cell params[] = {
		1 * 4,
		allow
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SetDeathDropAmount(int amount) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SetDeathDropAmount");
	cell params[] = {
		1 * 4,
		amount
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL CreateExplosion(float x, float y, float z, short type, float radius) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("CreateExplosion");
	cell params[] = {
		5 * 4,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z),
		type,
		amx_ftoc(radius)
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL EnableZoneNames(bool enable) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("EnableZoneNames");
	cell params[] = {
		1 * 4,
		enable
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL UsePlayerPedAnims() {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("UsePlayerPedAnims");
	FakeAmx::GetInstance().CallNative(native, 0);
}

SAMPGDK_EXPORT void SAMPGDK_CALL DisableInteriorEnterExits() {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("DisableInteriorEnterExits");
	FakeAmx::GetInstance().CallNative(native, 0);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SetNameTagDrawDistance(float distance) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SetNameTagDrawDistance");
	cell params[] = {
		1 * 4,
		amx_ftoc(distance)
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL DisableNameTagLOS() {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("DisableNameTagLOS");
	FakeAmx::GetInstance().CallNative(native, 0);
}

SAMPGDK_EXPORT void SAMPGDK_CALL LimitGlobalChatRadius(float chat_radius) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("LimitGlobalChatRadius");
	cell params[] = {
		1 * 4,
		amx_ftoc(chat_radius)
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL LimitPlayerMarkerRadius(float marker_radius) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("LimitPlayerMarkerRadius");
	cell params[] = {
		1 * 4,
		amx_ftoc(marker_radius)
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL ConnectNPC(const char *name, const char *script) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("ConnectNPC");
	FakeAmxHeapObject name_(name);
	FakeAmxHeapObject script_(script);
	cell params[] = {
		2 * 4,
		name_.address(),
		script_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL IsPlayerNPC(int playerid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("IsPlayerNPC");
	cell params[] = {
		1 * 4,
		playerid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL IsPlayerAdmin(int playerid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("IsPlayerAdmin");
	cell params[] = {
		1 * 4,
		playerid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL Kick(int playerid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("Kick");
	cell params[] = {
		1 * 4,
		playerid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL Ban(int playerid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("Ban");
	cell params[] = {
		1 * 4,
		playerid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL BanEx(int playerid, const char *reason) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("BanEx");
	FakeAmxHeapObject reason_(reason);
	cell params[] = {
		2 * 4,
		playerid,
		reason_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SendRconCommand(const char *command) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SendRconCommand");
	FakeAmxHeapObject command_(command);
	cell params[] = {
		1 * 4,
		command_.address(),
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GetServerVarAsString(const char *varname, char *value, size_t size) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetServerVarAsString");
	FakeAmxHeapObject varname_(varname);
	FakeAmxHeapObject value_(size);
	cell params[] = {
		3 * 4,
		varname_.address(),
		value_.address(),
		size
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	value_.GetAsString(value, size);
	return ret;
}

SAMPGDK_EXPORT int SAMPGDK_CALL GetServerVarAsInt(const char *varname) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetServerVarAsInt");
	FakeAmxHeapObject varname_(varname);
	cell params[] = {
		1 * 4,
		varname_.address(),
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GetServerVarAsBool(const char *varname) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetServerVarAsBool");
	FakeAmxHeapObject varname_(varname);
	cell params[] = {
		1 * 4,
		varname_.address(),
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GetPlayerNetworkStats(int playerid, char *retstr, size_t size) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetPlayerNetworkStats");
	FakeAmxHeapObject retstr_(size);
	cell params[] = {
		3 * 4,
		playerid,
		retstr_.address(),
		size
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	retstr_.GetAsString(retstr, size);
	return ret;
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GetNetworkStats(char *retstr, size_t size) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetNetworkStats");
	FakeAmxHeapObject retstr_(size);
	cell params[] = {
		2 * 4,
		retstr_.address(),
		size
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	retstr_.GetAsString(retstr, size);
	return ret;
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GetPlayerVersion(int playerid, char *version, size_t len) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetPlayerVersion");
	FakeAmxHeapObject version_(len + 1);
	cell params[] = {
		3 * 4,
		playerid,
		version_.address(),
		len
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	version_.GetAsString(version, len + 1);
	return ret;
}

SAMPGDK_EXPORT int SAMPGDK_CALL MenuCreate(const char *title, int columns, float x, float y, float col1width, float col2width) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("CreateMenu");
	FakeAmxHeapObject title_(title);
	cell params[] = {
		6 * 4,
		title_.address(),
		columns,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(col1width),
		amx_ftoc(col2width)
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL MenuDestroy(int menuid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("DestroyMenu");
	cell params[] = {
		1 * 4,
		menuid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL MenuAddItem(int menuid, int column, const char *menutext) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("AddMenuItem");
	FakeAmxHeapObject menutext_(menutext);
	cell params[] = {
		3 * 4,
		menuid,
		column,
		menutext_.address()
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL MenuSetColumnHeader(int menuid, int column, const char *columnheader) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SetMenuColumnHeader");
	FakeAmxHeapObject columnheader_(columnheader);
	cell params[] = {
		3 * 4,
		menuid,
		column,
		columnheader_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL MenuShowForPlayer(int menuid, int playerid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("ShowMenuForPlayer");
	cell params[] = {
		2 * 4,
		menuid,
		playerid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL MenuHideForPlayer(int menuid, int playerid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("HideMenuForPlayer");
	cell params[] = {
		2 * 4,
		menuid,
		playerid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL IsValidMenu(int menuid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("IsValidMenu");
	cell params[] = {
		1 * 4,
		menuid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL MenuDisable(int menuid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("DisableMenu");
	cell params[] = {
		1 * 4,
		menuid
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL MenuDisableRow(int menuid, int row) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("DisableMenuRow");
	cell params[] = {
		2 * 4,
		menuid,
		row
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL GetPlayerMenu(int playerid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GetPlayerMenu");
	cell params[] = {
		1 * 4,
		playerid
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL TextDrawCreate(float x, float y, const char *text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawCreate");
	FakeAmxHeapObject text_(text);
	cell params[] = {
		3 * 4,
		amx_ftoc(x),
		amx_ftoc(y),
		text_.address()
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawDestroy(int text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawDestroy");
	cell params[] = {
		1 * 4,
		text
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawLetterSize(int text, float x, float y) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawLetterSize");
	cell params[] = {
		3 * 4,
		text,
		amx_ftoc(x),
		amx_ftoc(y)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawTextSize(int text, float x, float y) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawTextSize");
	cell params[] = {
		3 * 4,
		text,
		amx_ftoc(x),
		amx_ftoc(y)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawAlignment(int text, int alignment) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawAlignment");
	cell params[] = {
		2 * 4,
		text,
		alignment
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawColor(int text, int color) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawColor");
	cell params[] = {
		2 * 4,
		text,
		color
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawUseBox(int text, bool use) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawUseBox");
	cell params[] = {
		2 * 4,
		text,
		use
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawBoxColor(int text, int color) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawBoxColor");
	cell params[] = {
		2 * 4,
		text,
		color
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawSetShadow(int text, int size) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawSetShadow");
	cell params[] = {
		2 * 4,
		text,
		size
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawSetOutline(int text, int size) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawSetOutline");
	cell params[] = {
		2 * 4,
		text,
		size
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawBackgroundColor(int text, int color) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawBackgroundColor");
	cell params[] = {
		2 * 4,
		text,
		color
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawFont(int text, int font) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawFont");
	cell params[] = {
		2 * 4,
		text,
		font
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawSetProportional(int text, bool set) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawSetProportional");
	cell params[] = {
		2 * 4,
		text,
		set
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawSetSelectable(int text, bool set) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawSetSelectable");
	cell params[] = {
		2 * 4,
		text,
		set
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawShowForPlayer(int playerid, int text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawShowForPlayer");
	cell params[] = {
		2 * 4,
		playerid,
		text
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawHideForPlayer(int playerid, int text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawHideForPlayer");
	cell params[] = {
		2 * 4,
		playerid,
		text
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawShowForAll(int text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawShowForAll");
	cell params[] = {
		1 * 4,
		text
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawHideForAll(int text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawHideForAll");
	cell params[] = {
		1 * 4,
		text
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL TextDrawSetString(int text, const char *string) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("TextDrawSetString");
	FakeAmxHeapObject string_(string);
	cell params[] = {
		2 * 4,
		text,
		string_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL SelectTextDraw(int playerid, int hovercolor) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("SelectTextDraw");
	cell params[] = {
		2 * 4,
		playerid,
		hovercolor
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT void SAMPGDK_CALL CancelSelectTextDraw(int playerid) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("CancelSelectTextDraw");
	cell params[] = {
		1 * 4,
		playerid
	};
	FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL GangZoneCreate(float minx, float miny, float maxx, float maxy) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneCreate");
	cell params[] = {
		4 * 4,
		amx_ftoc(minx),
		amx_ftoc(miny),
		amx_ftoc(maxx),
		amx_ftoc(maxy)
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneDestroy(int zone) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneDestroy");
	cell params[] = {
		1 * 4,
		zone
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneShowForPlayer(int playerid, int zone, int color) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneShowForPlayer");
	cell params[] = {
		3 * 4,
		playerid,
		zone,
		color
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneShowForAll(int zone, int color) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneShowForAll");
	cell params[] = {
		2 * 4,
		zone,
		color
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneHideForPlayer(int playerid, int zone) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneHideForPlayer");
	cell params[] = {
		2 * 4,
		playerid,
		zone
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneHideForAll(int zone) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneHideForAll");
	cell params[] = {
		1 * 4,
		zone
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneFlashForPlayer(int playerid, int zone, int flashcolor) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneFlashForPlayer");
	cell params[] = {
		3 * 4,
		playerid,
		zone,
		flashcolor
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneFlashForAll(int zone, int flashcolor) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneFlashForAll");
	cell params[] = {
		2 * 4,
		zone,
		flashcolor
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneStopFlashForPlayer(int playerid, int zone) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneStopFlashForPlayer");
	cell params[] = {
		2 * 4,
		playerid,
		zone
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL GangZoneStopFlashForAll(int zone) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("GangZoneStopFlashForAll");
	cell params[] = {
		1 * 4,
		zone
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL Create3DTextLabel(const char *text, int color, float x, float y, float z, float DrawDistance, int virtualworld, bool testLOS) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("Create3DTextLabel");
	FakeAmxHeapObject text_(text);
	cell params[] = {
		8 * 4,
		text_.address(),
		color,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z),
		amx_ftoc(DrawDistance),
		virtualworld,
		testLOS
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL Delete3DTextLabel(int id) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("Delete3DTextLabel");
	cell params[] = {
		1 * 4,
		id
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL Attach3DTextLabelToPlayer(int id, int playerid, float OffsetX, float OffsetY, float OffsetZ) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("Attach3DTextLabelToPlayer");
	cell params[] = {
		5 * 4,
		id,
		playerid,
		amx_ftoc(OffsetX),
		amx_ftoc(OffsetY),
		amx_ftoc(OffsetZ)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL Attach3DTextLabelToVehicle(int id, int vehicleid, float OffsetX, float OffsetY, float OffsetZ) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("Attach3DTextLabelToVehicle");
	cell params[] = {
		5 * 4,
		id,
		vehicleid,
		amx_ftoc(OffsetX),
		amx_ftoc(OffsetY),
		amx_ftoc(OffsetZ)
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL Update3DTextLabelText(int id, int color, const char *text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("Update3DTextLabelText");
	FakeAmxHeapObject text_(text);
	cell params[] = {
		3 * 4,
		id,
		color,
		text_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT int SAMPGDK_CALL CreatePlayer3DTextLabel(int playerid, const char *text, int color, float x, float y, float z, float DrawDistance, int attachedplayer, int attachedvehicle, bool testLOS) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("CreatePlayer3DTextLabel");
	FakeAmxHeapObject text_(text);
	cell params[] = {
		10 * 4,
		playerid,
		text_.address(),
		color,
		amx_ftoc(x),
		amx_ftoc(y),
		amx_ftoc(z),
		amx_ftoc(DrawDistance),
		attachedplayer,
		attachedvehicle,
		testLOS
	};
	return FakeAmx::GetInstance().CallNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL DeletePlayer3DTextLabel(int playerid, int id) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("DeletePlayer3DTextLabel");
	cell params[] = {
		2 * 4,
		playerid,
		id
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL UpdatePlayer3DTextLabelText(int playerid, int id, int color, const char *text) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("UpdatePlayer3DTextLabelText");
	FakeAmxHeapObject text_(text);
	cell params[] = {
		4 * 4,
		playerid,
		id,
		color,
		text_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL ShowPlayerDialog(int playerid, int dialogid, int style, const char *caption,
	const char *info, const char *button1, const char *button2)
{
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("ShowPlayerDialog");
	FakeAmxHeapObject caption_(caption);
	FakeAmxHeapObject info_(info);
	FakeAmxHeapObject button1_(button1);
	FakeAmxHeapObject button2_(button2);
	cell params[] = {
		7 * 4,
		playerid,
		dialogid,
		style,
		caption_.address(),
		info_.address(),
		button1_.address(),
		button2_.address()
	};
	return FakeAmx::GetInstance().CallBooleanNative(native, params);
}

SAMPGDK_EXPORT bool SAMPGDK_CALL gpci(int playerid, char *buffer, size_t size) {
	static AMX_NATIVE native = NativeManager::GetInstance().GetNative("gpci");
	FakeAmxHeapObject buffer_(size);
	cell params[] = {
		3 * 4,
		playerid,
		buffer_.address(),
		size
	};
	bool ret = FakeAmx::GetInstance().CallBooleanNative(native, params);
	buffer_.GetAsString(buffer, size);
	return ret;
}