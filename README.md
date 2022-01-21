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
    <img src="https://img.shields.io/github/last-commit/LucasDatilioCarderelli/so_long?color=blue">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/LucasDatilioCarderelli/so_long?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/LucasDatilioCarderelli/so_long?color=blue" />
</p>

<div align="center">
	<a alt="get next line" href="https://github.com/LucasDatilioCarderelli/so_long">
		<img src="https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/so_long.png">
	</a>
</div>

---

![so_long gif](https://github.com/LucasDatilioCarderelli/42Cursus/blob/master/img/so_long.gif)

---

## Description
So long is a small 2D game project, help the little hero to collect all coins and scape safely while avoids the slimes!!

### Goal
This is a graphical desing project, it will help to improve skills in the following
areas: ``window management``, ``event handling``, ``colors``, ``textures``, and so ``forth``.

You can see the MinilibX's Documentation **[here](https://harm-smits.github.io/42docs/libs/minilibx.html)**. 

#### Objectives:
* ``Unix logic``
* ``Applicative``

#### Skills:
* ``Rigor``
* ``Algorithms & AI``
* ``Imperative programming``
* ``Graphics``

---

## How to play

### Execute the game

To play you can execute the executable ``so_long`` passing the map you want to play as parameter, as an example:
```bash
./so_long assets/maps/map_bonus.ber
```

### Controls
Use ``WASD`` or the ``Arrows Keys`` to move. 

You move one tile at a time. Enemies move after you do, and you die when you move into their tile. After picking up all Coins, the exits open and you may leave to see how many moves you’ve used.

You can close the game with ``esc`` or `Q` button.

### Maps
The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

|	Character	|	Object 		|
| - | ------------------------- |
| 1 | Wall.						|
| 0 | Empty space.			 	|
| C | Collectable.				|
| E | Exit.						|
| P | Player starting position  |
| V | Enemy starting position.  |

* The map must be a rectangle surrounded by walls ``1``.
* It must have at least one exit ``E`` and one collectable ``C``. And only one player ``P``.

See some examples in the ``./assests/maps`` folder of this project.