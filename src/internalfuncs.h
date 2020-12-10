#include "addresses.h"

struct coord_def {
	int x;
	int y;
};

typedef bool(__stdcall* _Magic_mapping)(int map_radius, int proportion, bool suppress_msg,
	bool force, bool deterministic, coord_def origin);
_Magic_mapping magic_mapping = (_Magic_mapping)magicMappingAddy;


// calling this function, even with the acquirement scroll in the right slot, does not do anything :(
//00000DCC * 4 + crawl-tiles.exe + EE3898
typedef bool(__stdcall* _Acquirement_screen)(int unknown);
_Acquirement_screen acquirement_screen = (_Acquirement_screen)acqScreenAddy;


typedef bool(__cdecl* _Acquirement)(void);
_Acquirement acquirement = (_Acquirement)acquirementAddy;