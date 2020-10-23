# dcss-trainer

Various hacks for Dungeon Crawl Stone Soup version 0.25.0.

## Download
Download this project by cloning the repository:

```bash
git clone https://github.com/cbliou/dcss-trainer.git
```

The trainer is the executable located in the Release folder. Source code for the trainer is within this project.

On my computer, Windows Defender mistakenly believes there's a trojan in the executable. You can also build the trainer from scratch if you don't trust the executable (which I totally understand):
+ Download Microsoft Visual Studio 2019
+ Open the `.sln` file in this repository and all other files
+ Click `Build -> Build Solution` and you should have a new `.exe` file ready to go

## Use
This trainer only supports the `tiles` version of crawl. It only supports version 0.25.0; the trainer will most likely not work on other versions of crawl.
Use: First run `crawl-tiles.exe` then run the trainer. If everything goes well, the trainer should detect that the tiles version of crawl is currently running.

## Features
+ Godmode: Sets all incoming damage to your player to 0. Includes magic/poison damage. Press `F1` to activate.
+ more features soon...
