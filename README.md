<div align="center">
	<a href="https://www.42sp.org.br/">
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/42-saopaulo.png" height=200>
	</a>
</div>

<h1 align="center"> So_long </h1>

<h2 align="center">
	Project develop for <a href="https://github.com/LucasDatilioCarderelli/42Cursus"> 42Cursus </a>
</h2>

<p align="center">
  	<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    	<img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
  	</a>
	<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
    	<img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
	</a>
	<br>
    <img src="https://img.shields.io/github/last-commit/LucasDatilioCarderelli/so_long?color=blue">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/LucasDatilioCarderelli/so_long?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/LucasDatilioCarderelli/so_long?color=blue" />
</p>

<div align="center">
	<a href="https://github.com/LucasDatilioCarderelli/01-So_long">
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/so_long.png">
	</a>
    <br><br>
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/so_long.gif">
</div>

---

## Description
So long is a small 2D game project, help the little hero collect all coins and escape safety while avoiding the slimes!!

### Goal
This is a graphic design project that will help you to improve skills in the following
areas: ``window management``, ``event handling``, ``colours ``, ``textures``, and so ``forth``.

You can see MinilibX's Documentation **[here](https://harm-smits.github.io/42docs/libs/minilibx.html)**. 

#### Objectives:
* ``Unix logic``
* ``Applicative``

#### Skills:
* ``Rigor``
* ``Algorithms & AI``
* ``Imperative programming``
* ``Graphics``

---

## How to Play

### Execute the game

To play the game, you can execute the executable ``so_long`` passing the map you want to play as a parameter, as an example:
```bash
./so_long assets/maps/map_bonus.ber
```

### Controls
Use ``WASD`` or the ``Arrows Keys`` to move. 

You move one tile at a time. Enemies move after you do, and you die when you move into their tile. After picking up all Coins, the exits open and you may leave to see how many moves you’ve used.

You can close the game with the ``ESC`` or `Q` button.

### Maps
The game can play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

|   Character   |   Object      |
| - | ------------------------- |
| 1 | Wall.                     |
| 0 | Empty space.              |
| C | Collectable.              |
| E | Exit.                     |
| P | Player starting position  |
| V | Enemy starting position.  |

* The map must be a rectangle surrounded by walls ``1``.
* It must have at least one exit ``E`` and one collectable ``C``. And only one player ``P``.

See some examples in the ``./assests/maps`` folder of this project.

## How it Works

### Header
In ``so_long.h`` and ``so_long_bonus.h`` is where we do the includes, defines and create some structs,the ``t_game *game`` argument is the main struct that contains other struct, to facilitate the code, like:
* ``t_vars``: Used for init mlx;
* ``s_map``: Contains variables of map;
* ``s_img`` and ``s_position``: The img and its position.

### Main
In the ``main(int argc, **char argv)`` of the ``so_long.c`` file, first of all, we need to check the user input with the function ``verify_argc(int argc)``, then, we can read the map file passed as an argument after initializing some variables.
The game works because of ``mlx_hook()`` is triggered by an event looping by the ``mlx_loop(void *mlx_ptr)``.

### Reading and verifications
In this file, ``read_map.c``, we read the map with the function ``read_map(char *argv, t_game *game)`` and with [``get_next_line(int fd)``](https://github.com/LucasDatilioCarderelli/01-Get_next_line). About that, it needs to check if the game is playable, those functions are in the ``verify_error.c`` verifying if the game is surrounded by walls, if the map is not a square, if the chars are the expected and their quantities. If something fails or are wrong, the program ends by ``exit_error(char *s)`` in ``exit_free.c`` file.

### Rendering
After the map was correctly read we init the game, initing the mlx library, a window, and our images.
To render the game, ``render_game(t_game *game)`` we loop the map for each character, we put the image to window passing its position. For the bonus part, the exit is open after there is no collectible, and the enemy looks at the player and bounces after two moves, and the player follows according to the pressed key.

---

>> Feel free to clone this project. If something keeps confusing, contact me, I'll be happy to help, good luck!!.

<a href="https://github.com/LucasDatilioCarderelli" alt="login intra">
    <img src="https://img.shields.io/badge/-ldatilio-gray?style=flat&logo=42&logoColor=white" />
</a>
<a href="https://www.linkedin.com/in/lucasdatiliocarderelli/">
    <img alt="Linkedin" src="https://img.shields.io/badge/Lucas Datilio Carderelli-blue?style=flat&logo=Linkedin&logoColor=white" />
</a>
