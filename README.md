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

Use: First run `crawl-tiles.exe` then run the trainer. If everything goes well, the trainer should detect that the tiles version of crawl is currently running.

## Features

### Hacks
+ Godmode: Sets all incoming damage to your player to 0. Includes magic/poison damage. 
+ Infinite mana : Does not use mana when casting spells.

### Custom stats
+ Change strength value : Set strength to a number between 0 and 127.
+ Change intelligence value : Set intelligence to a number between 0 and 127.
+ Change dexterity value: Set dexterity to a number between 0 and 127.
