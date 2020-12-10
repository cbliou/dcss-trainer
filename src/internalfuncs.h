#include "addresses.h"

struct coord_def {
	int x;
	int y;
};

typedef bool(__stdcall* _Magic_mapping)(int map_radius, int proportion, bool suppress_msg,
	bool force, bool deterministic, coord_def origin);
_Magic_mapping magic_mapping = (_Magic_mapping)magicMappingAddy;