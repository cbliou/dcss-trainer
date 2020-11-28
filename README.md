# dcss-trainer

Various hacks for Dungeon Crawl Stone Soup version 0.25.0. You can find the game [here](https://crawl.develz.org/download.htm) (navigate to past releases -> 0.25).

## Download
Download this project by cloning the repository:

```bash
git clone https://github.com/cbliou/dcss-trainer.git
```

The trainer is the executable located in the Release folder. Source code for the trainer is within this project.

## Use
This trainer only supports the `tiles` version of crawl. It only supports version 0.25.0; the trainer will most likely not work on other versions of crawl.

Use: The trainer will automatically detect `crawl-tiles.exe` is running and attach to it.

## Features

### Hacks
+ Godmode: Sets all incoming damage to your player to 0. Includes magic/poison damage. 
+ Infinite mana: Does not use mana when casting spells.
+ No Hunger: Your hunger does not decrease.
+ Auto-identify items: Items in your inventory and environment will be automatically identified. Currently does not include shop items.

### Custom stats
+ Change strength, intelligence, dex values: Set them to values between 0 and 127. Missing/invalid values are set to your current values.
+ Change skill levels: Set them to skill levels between 0.0 and 27.0. Missing/invalid values are set to your current values.

### Incoming features
+ Tile-based kill aura
+ One-shot monsters (to learn about function hooking)
+ Item spawning
+ Gold hacks
+ No negative status effects
+ Remove negative mutations
+ Unlock all spells
+ Account for race aptitudes in skill levels
+ Hook tick function to learn about function hooking
+ See if you can hook Shaft Self