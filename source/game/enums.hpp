// This file is part of openCaesar3.
//
// openCaesar3 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// openCaesar3 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with openCaesar3.  If not, see <http://www.gnu.org/licenses/>.
//
// Copyright 2012-2013 Gregoire Athanase, gathanase@gmail.com


#ifndef _OPENCAESAR3_ENUMS_INCLUDE_H_
#define _OPENCAESAR3_ENUMS_INCLUDE_H_

#include <string>

enum DirectionType 
{ 
  D_NONE, 
  D_NORTH, 
  D_NORTH_WEST, 
  D_WEST, 
  D_SOUTH_WEST, 
  D_SOUTH, 
  D_SOUTH_EAST, 
  D_EAST, 
  D_NORTH_EAST, 
  D_MAX 
};

enum WalkerGraphicType 
{
  WG_NONE, WG_POOR, WG_BATH, WG_PRIEST, WG_ACTOR, WG_TAMER, WG_TAX, WG_CHILD, WG_MARKETLADY, 
  WG_PUSHER, WG_PUSHER2, 
  WG_ENGINEER, 
  WG_GLADIATOR, WG_GLADIATOR2, 
  WG_RIOTER, WG_BARBER, 
  WG_PREFECT, WG_PREFECT_DRAG_WATER, WG_PREFECT_FIGHTS_FIRE,
  WG_HOMELESS, 
  WG_RICH, WG_RICH2,
  WG_DOCTOR, WG_LIBRARIAN, WG_JAVELINEER, 
  WG_SOLDIER, 
  WG_HORSEMAN, WG_HORSE_CARAVAN, WG_CAMEL_CARAVAN, WG_MARKETLADY_HELPER, 
  WG_ANIMAL_SHEEP_WALK,
  WG_FISHING_BOAT, WG_FISHING_BOAT_WORK,
  WG_MAX 
};

enum WalkerType 
{ 
  WT_NONE, WT_IMMIGRANT, WT_EMIGRANT, 
  WT_SOLDIER, WT_CART_PUSHER, 
  WT_MARKETLADY, WT_MARKETLADY_HELPER,
  WT_SERVICE,                     //unknown service
  WT_TRAINEE, WT_WORKERS_HUNTER,
  WT_PREFECT, WT_TAXCOLLECTOR, WT_ENGINEER,
  WT_DOCTOR, WT_BATHLADY,
  WT_MERCHANT,
  WT_ACTOR, WT_GLADIATOR, WT_TAMER, WT_CHARIOT,
  WT_ANIMAL_SHEEP,
  WT_BARBER, WT_SURGEON,
  WT_FISHING_BOAT,
  WT_MAX, WT_ALL=WT_MAX 
};
  
enum WaterService { WTR_WELL=0, WTR_FONTAIN, WTR_RESERVOIR, WTR_COUNT };

enum ClimateType { C_CENTRAL, C_NORTHERN, C_DESERT, C_MAX };

enum ScreenType { SCREEN_NONE, SCREEN_MENU, SCREEN_GAME, SCREEN_QUIT, SCREEN_MAX };

enum TileOverlayType
{
  unknown,
  buildingAmphitheater, B_THEATER, B_HIPPODROME, B_COLLOSSEUM, B_ACTOR_COLONY, B_GLADIATOR_SCHOOL, B_LION_HOUSE, B_CHARIOT_MAKER,   // entertainment
  B_HOUSE, B_ROAD, B_PLAZA, B_GARDEN,  // road & house
  B_SENATE, B_FORUM,  // administration
  B_GOVERNOR_HOUSE, B_GOVERNOR_VILLA, B_GOVERNOR_PALACE,
  B_RESERVOIR, B_AQUEDUCT, B_FOUNTAIN, B_WELL,  // water
  B_PREFECTURE,   // security
  B_WALL, B_TOWER, B_GATEHOUSE, B_FORT_LEGIONNAIRE, B_FORT_JAVELIN, B_FORT_MOUNTED, B_MILITARY_ACADEMY, B_BARRACKS,
  B_MARKET, B_GRANARY, B_WAREHOUSE,   // commerce
  B_WHEAT_FARM, B_FRUIT_FARM, B_VEGETABLE_FARM, B_OLIVE_FARM, B_GRAPE_FARM, B_PIG_FARM,   // farms
  B_MARBLE_QUARRY, B_IRON_MINE, B_TIMBER_YARD, B_CLAY_PIT,   // raw materials
  B_WINE_WORKSHOP, B_OIL_WORKSHOP, B_WEAPONS_WORKSHOP, B_FURNITURE, B_POTTERY,  // factories
  B_ENGINEER_POST, B_STATUE1, B_STATUE2, B_STATUE3, B_LOW_BRIDGE, B_HIGH_BRIDGE,  // utility
  B_SHIPYARD, B_DOCK, B_WHARF,
  B_DOCTOR, B_HOSPITAL, B_BATHS, B_BARBER,   // health
  B_SCHOOL, B_COLLEGE, B_LIBRARY, B_MISSION_POST,  // education
  B_TEMPLE_CERES, B_TEMPLE_MARS, B_TEMPLE_NEPTUNE, B_TEMPLE_MERCURE, B_TEMPLE_VENUS, // religion: small temples
  B_BIG_TEMPLE_CERES, B_BIG_TEMPLE_MARS, B_BIG_TEMPLE_NEPTUNE, B_BIG_TEMPLE_MERCURE, B_BIG_TEMPLE_VENUS, // religion: big temples
  B_TEMPLE_ORACLE, // religion: others
  B_NATIVE_HUT, B_NATIVE_CENTER, B_NATIVE_FIELD, // building of natives
  B_TRIUMPHAL_ARCH,
  B_BURNING_RUINS, B_BURNED_RUINS, B_COLLAPSED_RUINS, B_PLAGUE_RUINS,
  B_FORUM_2, B_SENATE_2,
  wtrFishPlace,
  userType=1000,
  B_MAX
};

enum TileOverlayGroup
{
  lndcUnknown,
  BC_INDUSTRY,
  BC_RAWMATERIAL,
  BC_FOOD,
  BC_DISASTER,
  BC_RELIGION,
  BC_MILITARY,
  BC_NATIVE,
  BC_WATER,
  BC_ADMINISTRATION,
  BC_BRIDGE,
  BC_ENGINEERING,
  BC_TRADE,
  BC_TOWER,
  BC_GATE,
  BC_SECURITY,
  BC_EDUCATUION,
  BC_HEALTH,
  BC_SIGHT,
  BC_GARDEN,
  BC_ROAD,
  BC_ENTERTAINMENT,
  BC_HOUSE,
  BC_WALL,
  BC_MAX
};

enum DrawingOverlayType
{
  drwSimple,
  drwWater,
  drwRisks,
  OV_RISK_FIRE,
  OV_RISK_DAMAGE,
  OV_RISK_CRIME,
  OV_RISK_ABORIGEN,
  OV_RISK_TROUBLES,
  OV_ENTERTAINMENT,
  OV_ENTERTAINMENT_ALL,
  OV_ENTERTAINMENT_THEATRES,
  OV_ENTERTAINMENT_AMPHITHEATRES,
  OV_ENTERTAINMENT_COLLISEUM,
  OV_ENTERTAINMENT_HIPPODROME,
  OV_EDUCATION,
  OV_EDUCATION_ALL,
  OV_EDUCATION_SCHOOL,
  OV_EDUCATION_LIBRARY,
  OV_EDUCATION_ACADEMY,
  OV_HEALTH,
  OV_HEALTH_BARBER,
  OV_HEALTH_BATHS,
  OV_HEALTH_DOCTOR,
  OV_HEALTH_HOSPITAL,
  OV_COMMERCE,
  OV_COMMERCE_TAX,
  OV_COMMERCE_FOOD,
  OV_COMMERCE_PRESTIGE,
  OV_RELIGION,
  OV_COUNT
};

enum BuildMenuType 
{ 
  BM_NONE, 
  BM_WATER, 
  BM_HEALTH, 
  BM_SECURITY, 
  BM_EDUCATION, 
  BM_ENGINEERING, 
  BM_ADMINISTRATION, 
  BM_ENTERTAINMENT, 
  BM_COMMERCE, 
  BM_FARM, 
  BM_RAW_MATERIAL, 
  BM_FACTORY, 
  BM_RELIGION, 
  BM_TEMPLE, 
  BM_BIGTEMPLE, 
  BM_MAX 
};

enum AdvisorType
{
  ADV_EMPLOYERS=0,
  ADV_LEGION,
  ADV_EMPIRE,
  ADV_RATINGS,
  ADV_TRADING,
  ADV_POPULATION,
  ADV_HEALTH,
  ADV_EDUCATION,
  ADV_ENTERTAINMENT,
  ADV_RELIGION,
  ADV_FINANCE,
  ADV_MAIN,
  ADV_COUNT
};

#endif  //_OPENCAESAR3_ENUMS_INCLUDE_H_
