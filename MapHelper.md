## Map Configuration

There is a Python script in the [Maps](Game/Maps) folder that converts a map in png format, to a map in txt format based on pixel colors. Each color used in the map is assigned a value. Then, these values are used in the [Game.cpp](Game/Game.cpp) file when creating the map.

### Actual sizes: 

- Screen -> 600 x 600 px.

- Board -> 20 x 20 squares.  


- Square -> 30 x 30 px.  
- Player -> 20 x 20 px.  
- Bullet -> 5 x 5 px.  

### Bitmap color - value mapping:

| Object | Color value     | ID  |
|--------|-----------------|-----|
| Floor  | (255, 255, 255) | 0   |
| Wall   | (0, 0, 0)       | 1   |
| Player | (0, 255, 0)     | 9   |
| Box    | (50, 0, 0)      | 2   |



