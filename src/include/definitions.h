/*
 * definitions.h
 *
 *  Created on: 7-nov-2010
 *      Author: Stefan
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#define DEBUGGING bDoDebug

#define IDEAL_FPS	60

// MAP ID
#define MAPID_UNITS  0
#define MAPID_STRUCTURES 1
#define MAPID_AIR   2
#define MAPID_WORMS  3
#define MAPID_MAX	 4 // used for clearing all

// Game modes
#define MOD_DUNE2		0
#define MOD_D2TM		1
//#define MOD_MINE		2		// own made mod

#define MAP_W_MAX        64     // max of width
#define MAP_H_MAX        64     // max of height

#define MAX_CELLS    (MAP_W_MAX * MAP_H_MAX) // use width and height to determine max

// MEMORY USAGE: (units, structures, etc , more info below)
#define MAX_UNITS        300     // max of units in the game
#define MAX_STRUCTURES   200     // max of structures in the game
#define MAX_BULLETS      600     // max of bullets in the game at once
#define MAX_PARTICLES    1200	 // max of particles at once
#define MAX_REINFORCEMENTS 50    // max of 50 reinforcements
#define MAX_SKIRMISHMAPS 100     // max of 100 skirmish maps
//#define HOUSE_SLOTS       10      // amount of House 'types'

// FOR OPTIONS:

// GAME (MENU) FLAGS: (used when GAME_MENU)
// Game menu state machine

#define HUMAN			0
// PLAYER/AI stuff
// 0 = HUMAN			== ALLIES WITH FREMEN WHEN ATREIDES
// 1 = CPU (Atreides)
// 2 = CPU (Harkonnen)
// 3 = CPU (Ordos)
// 4 = CPU (Sardaukar)	== ALLIES WITH EVERYBODY (EXCEPT PLAYER)
// 5 = CPU (Fremen)		== ALLIES WITH ATREIDES
// 6 = WORM
#define MAX_PLAYERS       7

#define AI_WORM			  6

#define THINK_PLAYER      1      // real player is thinking for this one
#define THINK_CLIENT      2      // this ID is a client; so this is updated through the network
#define THINK_SERVER      3      // this ID is the server (??)
#define THINK_NONE        4      // un-used slot
#define THINK_CPU         99     // computer thinks for this player

// HOUSES stuff
#define MAX_HOUSES        12      // 12 different type of houses

// BULLETS stuff
#define MAX_BULLET_TYPES      30    // max of 30 types of bullets

// Lists stuff
#define MAX_ICONS       30      // max of 30 icons per list
#define MAX_ITEMS		MAX_ICONS
//#define MAX_LISTS       25      // max of 25 lists

// #TIMERS
#define TIMER_GUARD         10
#define TIMER_UNIT_BULLET   5

// FACING
#define FACE_UP           0
#define FACE_UPRIGHT      1
#define FACE_RIGHT        2
#define FACE_DOWNRIGHT    3
#define FACE_DOWN         4
#define FACE_DOWNLEFT     5
#define FACE_LEFT         6
#define FACE_UPLEFT       7

// Mouse status
#define MOUSE_STATE_NORMAL  0
#define MOUSE_STATE_MOVE    1
#define MOUSE_STATE_ATTACK  2
#define MOUSE_STATE_PLACE   3

// House id's
#define GENERALHOUSE   0     // no house at all, general house (gray)
#define HARKONNEN 1
#define ATREIDES  2
#define ORDOS     3
#define SARDAUKAR 4
#define FREMEN 	  5
#define MERCENARY 6
#define CORRINO   7         // == SARDAUKAR!!!   ---- in this code we use this 'house' for sandworms
#define SANDHOUSE 9
#define GREYHOUSE	10

#define ATREIDES_TALK	20
#define HARKONNEN_TALK	21
#define ORDOS_TALK		22
// .. add another id for another house

// BRAINS:
#define BRAIN_AI        1
#define BRAIN_CLIENT    2
#define BRAIN_NONE      3
#define BRAIN_AI_WORM   4

#define MAX_UNITTYPES       50
#define MAX_STRUCTURETYPES  50

// Structure types
#define PALACE            0         // cPalace
#define WINDTRAP          1         // cWindTrap
#define HEAVYFACTORY      2         // cHeavyFactory
#define LIGHTFACTORY      3         // cLightFactory
#define CONSTYARD         4         // cConstYard
#define SILO              5         // cSpiceSilo
#define HIGHTECH          6         // cHighTech
#define IX                7         // cIX
#define REPAIR            8         // cRepairFacility
#define RADAR             9         // = OUTPOST (cOutPost)
#define REFINERY          10        // cRefinery
#define WOR               11        // cWor
#define BARRACKS          12        // cBarracks
#define STARPORT          13        // cStarPort
#define TURRET            14        // cGunTurret
#define RTURRET           15        // cRocketTurret

// SPECIAL! -> These are not actually structures. When they are done with building the
// cell properties will be changed, this is also done in CREATE_STRUCTURE()
#define SLAB1             24      // 1 single slab
#define SLAB4             25      // 4 slabs
#define WALL              26      // 1 wall


#define MUSIC_WIN           0
#define MUSIC_LOSE          1
#define MUSIC_ATTACK        2
#define MUSIC_PEACE         3
#define MUSIC_MENU          4
#define MUSIC_CONQUEST      5
#define MUSIC_BRIEFING      6

// Unit types
#define SOLDIER           0
#define TROOPER           1
#define INFANTRY          2
#define TROOPERS          3
#define TRIKE             4
#define RAIDER            5
#define QUAD              6
#define TANK              7
#define LAUNCHER          8
#define SIEGETANK         9
#define DEVASTATOR        10
#define DEVIATOR          11
#define SONICTANK         12
#define HARVESTER         13
#define MCV               14   // Start with 0
#define CARRYALL          15  // air unit
#define ORNITHOPTER       16  // air unit
#define SANDWORM		  17


// special units
#define SABOTEUR		  19  // special unit
#define UNIT_FREMEN_ONE       20  // special unit(s) for fremen support
#define UNIT_FREMEN_THREE       21  // special unit(s) for fremen support
#define MISSILE			  22  // unit abusal id for missile (death hand)

// Frigate
#define FRIGATE           29  // air unit (should be last!!)

// Bullet types
#define ROCKET_SMALL      0   // small rocket (trooper/troopers)
#define ROCKET_NORMAL     1   // normal rocket (turret/launcher/deviator)
#define ROCKET_BIG        2   // big rocket (palace, nuclear)
#define BULLET_SMALL      3   // infantry bullet
#define BULLET_TRIKE      4   // a trike bullet, looks like infantry but is stronger
#define BULLET_QUAD       5   // a quad bullet
#define BULLET_TANK       6   // a normal tank dot
#define BULLET_SIEGE      7   // a siege tank dot
#define BULLET_DEVASTATOR 8   // a devastator dot
#define BULLET_GAS        9   // a deviator shot
#define BULLET_TURRET     10  // a normal turret dot
#define BULLET_SHIMMER    11  // EXEPTION: Shimmer effect!
#define ROCKET_SMALL_ORNI 12   // small rocket ornithopter
#define ROCKET_RTURRET	  13	// rocket turrets have weaker turrets!
#define BULLET_SAB        14    // a fake bullet , to make it easier to blow up stuff
#define ROCKET_SMALL_FREMEN     15   // small rocket (trooper/troopers) - FOR FREMEN

// Special bullets (explosions) (Particle types)
#define EXPL_ONE          21  // 2 types of explosion
#define EXPL_TWO          22  // for structures
#define EXPL_TRIKE        23  // explosion for trike/quad
#define EXPL_TANK         24  // explosion for a tank/siege/devastator
#define EXPL_TANK_TWO     25  // another explosion of a tank etc

// Particle types
#define PARTYPE_SMOKE		1
#define PARTYPE_REPAIRBLINK 2

// smudge
#define SMUDGE_ROCK 0
#define SMUDGE_SAND 1
#define SMUDGE_WALL 2


#endif /* DEFINITIONS_H_ */
