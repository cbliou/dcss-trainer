# dcss-trainer

Various hacks for Dungeon Crawl Stone Soup version 0.25.0. You can find the game [here](https://crawl.develz.org/download.htm) (navigate to past releases -> 0.25).

## Download
Download this project by cloning the repository:

```bash
git clone https://github.com/cbliou/dcss-trainer.git
```

## Use
This trainer only supports the `tiles` version of crawl. It only supports version 0.25.0; the trainer will most likely not work on other versions of crawl.

Use: Run the executable `dcsstrainer.exe`. It will attempt to inject the src.dll, which is the actual trainer itself. If successful, the trainer will appear and the console will close.
TODO: add dll ejecting + auto inject process

## Features

### Hacks

#### Player
+ Godmode: Sets all incoming damage to your player to 0. Includes magic/poison damage. 
+ Infinite mana: Does not use mana when casting spells.
+ No Hunger: Your hunger does not decrease.
+ Auto-identify items: Items in your inventory and environment will be automatically identified. Currently does not include shop items.

#### Monster
+ One HP: Sets all monster HP to one.
+ Monster freeze: Freeze all monsters in place; they will not attack you.
+ Disable movement: Disables monster movement. However, they will still attack. Enemies will physical attacks only will attack themselves. Enemies with ranged and magic attacks can attack you/summon monsters/etc.
+ Instakill: all attacks will instantly kill any monster. Works for ranged/magic/physical.

### Custom stats
+ Change strength, intelligence, dex values: Set them to values between 0 and 127. Missing/invalid values are set to your current values.
+ Change skill levels: Set them to skill levels between 0.0 and 27.0. Missing/invalid values are set to your current values.

### Possible incoming features
+ turn trainer on and off
+ Tile-based kill aura
+ Gold/piety/item stat modifying
+ Item spawning
+ Click to blink? (seems like a good fcn hook lesson)
+ No negative status effects
+ Remove negative mutations
+ Unlock all spells
+ uncurse/curse all items (for Ashenzari)
+ Account for race aptitudes in skill levels
+ Hook tick function to learn about function hooking
+ See if you can hook Shaft Self