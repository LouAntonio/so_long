<img src="https://github.com/LouAntonio/42-resources/blob/main/resourses/so_long.png" style="width: 100%"/>

# so_long
#### My first 2D game 

so_long is a 'simple' and small 2D game, and his goal is to make the player catch all the collectables and then scape.

In the project, the cadet is going to use the school graphical library: the MiniLibX! This library was
developed internally and includes basic necessary tools to open a window, create images
and deal with keyboard and mouse events.

### SAMPLE VALID MAP
```
1111111111111
10C10000000C1
100001000C001
1P0C01E000001
1111111111111
1101101000111
1101101111011
1110001000011
1111101011111
1111101100011
1111111111111
1111111111111
```

| Char | Description |
| :--: | :--: |
| `0` | Empty space              |
| `1` | Wall                     |
| `C` | Collectible              |
| `E` | Exit                 |
| `P` | Player |

### GAME RULES
- The player [P] must catch all the collectibles [C] and the leave the game, 'entering' the exit [E]
- The player cant leave until catch all the collectibles
- The player cant walk or cross walls
- By walk into a collectible, the player catches it

### MAP VALIDATION
- The map extension must be '.ber'

- The map must be closed (surrounde by walls)

- There must be only one player and one exit

- There must have at lesat one collectible

- The map cant have invalid chars (only 1, 0, P, C and E allowed)

- The map must be rectangular, and have the same lenth in all rows

- The player must be able to catch all the collectible before leave

  - The exit cant be surrounded by walls
 
  - A collectible cant be surrounded by walls
  - So forth...
  
In case of error in any of this verifications, the game window can't be displayed, and the program must show an `error\n`, and a custom message (optional)

### HOW TO BUILD
<ul style="list-style: none">
  <li>Read the map</li>
  <li>Validate the map
    <ul>
      <li>Errors handling
        <ul>
          <li>Handle memmory leaks</li>
        </ul>
    </ul>
  </li>
  <li>Map rendering</li>
  <li>Events handling
    <ul>
      <li>Errors handling</li>
        <li>(ESC key || Q key) <b>&&</b> window cross must close the game
          <ul>
          <li>Handle memmory leaks</li>
        </ul>
        </li>
        <li>Directions key || WDSA must move the player</li>
    </ul>
  </li>
    <li>Enable game exit when the player catch all the collectibles
        <ul>
          <li>Handle memmory leaks</li>
        </ul>
    </li>
  </li>
</ul>
