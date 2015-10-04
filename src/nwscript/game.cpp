/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Game-specific NWScript information.
 */

#include "src/common/util.h"

#include "src/nwscript/game.h"
#include "src/nwscript/game_nwn.h"
#include "src/nwscript/game_nwn2.h"
#include "src/nwscript/game_kotor.h"
#include "src/nwscript/game_kotor2.h"
#include "src/nwscript/game_jade.h"
#include "src/nwscript/game_witcher.h"
#include "src/nwscript/game_dragonage.h"
#include "src/nwscript/game_dragonage2.h"

namespace NWScript {

static const GameInfo kGameInfo[Aurora::kGameIDMAX] = {
	{
		ARRAYSIZE(NWN::kEngineTypeNames),
		NWN::kEngineTypeNames,
		ARRAYSIZE(NWN::kFunctionNames),
		NWN::kFunctionNames
	},
	{
		ARRAYSIZE(NWN2::kEngineTypeNames),
		NWN2::kEngineTypeNames,
		ARRAYSIZE(NWN2::kFunctionNames),
		NWN2::kFunctionNames
	},
	{
		ARRAYSIZE(KotOR::kEngineTypeNames),
		KotOR::kEngineTypeNames,
		ARRAYSIZE(KotOR::kFunctionNames),
		KotOR::kFunctionNames
	},
	{
		ARRAYSIZE(KotOR2::kEngineTypeNames),
		KotOR2::kEngineTypeNames,
		ARRAYSIZE(KotOR2::kFunctionNames),
		KotOR2::kFunctionNames
	},
	{
		ARRAYSIZE(Jade::kEngineTypeNames),
		Jade::kEngineTypeNames,
		ARRAYSIZE(Jade::kFunctionNames),
		Jade::kFunctionNames
	},
	{
		ARRAYSIZE(Witcher::kEngineTypeNames),
		Witcher::kEngineTypeNames,
		ARRAYSIZE(Witcher::kFunctionNames),
		Witcher::kFunctionNames
	},
	{
		0,
		0,
		0,
		0
	},
	{
		ARRAYSIZE(DragonAge::kEngineTypeNames),
		DragonAge::kEngineTypeNames,
		ARRAYSIZE(DragonAge::kFunctionNames),
		DragonAge::kFunctionNames
	},
	{
		ARRAYSIZE(DragonAge2::kEngineTypeNames),
		DragonAge2::kEngineTypeNames,
		ARRAYSIZE(DragonAge2::kFunctionNames),
		DragonAge2::kFunctionNames
	}
};

const GameInfo *getGameInfo(Aurora::GameID game) {
	if ((size_t)game >= ARRAYSIZE(kGameInfo) || (game == Aurora::kGameIDSonic))
		return 0;

	return &kGameInfo[(size_t)game];
}

size_t getEngineTypeCount(Aurora::GameID game) {
	const GameInfo *info = getGameInfo(game);
	if (!info)
		return 0;

	return info->engineTypeCount;
}

Common::UString getGenericEngineTypeName(size_t n) {
	return Common::UString::format("E%u", (uint)n);
}

Common::UString getEngineTypeName(Aurora::GameID game, size_t n) {
	const GameInfo *info = getGameInfo(game);
	if (!info || (n >= info->engineTypeCount))
		return "";

	return info->engineTypeNames[n];
}

size_t getFunctionCount(Aurora::GameID game) {
	const GameInfo *info = getGameInfo(game);
	if (!info)
		return 0;

	return info->functionCount;
}

Common::UString getFunctionName(Aurora::GameID game, size_t n) {
	const GameInfo *info = getGameInfo(game);
	if (!info || (n >= info->functionCount))
		return "";

	return info->functionNames[n];
}

} // End of namespace NWScript
