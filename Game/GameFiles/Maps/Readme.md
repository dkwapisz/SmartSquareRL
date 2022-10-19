## Map Configuration

There is a [Python script](TrainingMaps/ConvertMap.py) here that converts a map in png format, to a map in txt format based on pixel
colors. Each color used in the map is assigned a value. Then, these values are used in the [Level.cpp](../Level.cpp)
file when creating the map.

### Actual sizes:

- Screen -> 600 x 600 px.

- Board -> 20 x 20 squares.


- Square -> 30 x 30 px.
- Player -> 20 x 20 px.
- Bullet -> 5 x 5 px.

### Bitmap color - value mapping:

| Object        | Color value     | ID  |
|---------------|-----------------|-----|
| Floor         | (255, 255, 255) | 0   |
| Wall          | (0, 0, 0)       | 1   |
| Box           | (50, 0, 0)      | 2   |
| StaticDanger  | (170, 0, 150)   | 3   |
| Coin          | (255, 255, 0)   | 4   |
| MovingDangerH | (255, 0, 0)     | 5   |
| MovingDangerV | (120, 0, 0)     | 6   |
| Finish        | (80, 120, 0)    | 7   |
| Player        | (0, 255, 0)     | 8   |



