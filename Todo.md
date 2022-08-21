## TODO LIST
#### New states:
* Distances to walls around player (120 rays -> 1 in 6 will be sent as state -> 20 distances)
* DistanceX, DistanceY (unit vectors) to destination (coin/finish depends on that if player collect all coins or not)
* 6 maps, each rotated (0, 90, 180, 270) -> 24 maps, selected randomly after gameOver
* 
#### Bugs: 
[ ] - repair iteration counter
[ ] - add score to create graph of learning

## TODO LIST 2 [DEPRECATED]:
- [x] Set new reward system for coins: 
  - **if coin is IN FoV** and:
    - player getting closer to closer coin -> +10
    - player move away from closer coin -> -10
  - getting coin with no change -> +50
- [x] Change direction states -> if something is for example UP and RIGHT (diagonal), it should be [1, 1, 0, 0] in state vector, not only closest direction
- [x] Direction to the closest coin -> should be exposed for DQN if coin is not in FoV?
- [x] "coinInFoV" should be as separate boolean state? -> yes
- [x] Shorten state vector for "isClosestObstacleBox" and "coinsNeeded" from [0, 1], [1, 0] to [0], [1]
- [x] Think what about finish -> use finish in FoV mechanic same as coins?
- [x] **IMPORTANT - FIX REWARDS (CHECK GIVING REWARDS PLAYING AT GAME AS NORMAL PLAYER) - broken reward: after collecting coin (GameStateHandling 167), collecting all coins (finish), check lastDistanceWall reward.**
- [ ] bug with finish area and rays

### New Reward System:

- Touching wall: -10
- Touching box: -10
- Collecting coin: +50
- Touching enemy: -100
- Getting closer to coin **IF** coin is in FoV: +3
- Moving away from coin **IF** coin is in FoV: -5
- Reaching finish if all coins were collected: +100
- Out of time (20s): -100 -> time is reset after collecting coin
- Getting coin in FoV **IF** already collected 1 coin: +30
- Losing coin from FoV (not apply to coin that have just been collected): -50
- Getting closer to finish **AFTER** collecting every coin **IF** finish is in FoV: +5
- Moving away from finish **AFTER** collecting every coin **IF** finish is in FoV: -5
- Getting closer to lastDiscoveredWall **IF** coin not in FoV: +3
- Moving away from lastDiscoveredWall **IF** coin not in FoV: -5
- Else: 0

### New State:

- coinsNeeded 1x1 - boolean
- closestObstacle 1x4
- closestCoin 1x4
- finishDirection 1x4
- coinInFoV 1x1 - boolean
- lastDiscoveredWall 1x4

- closestObstacleBox Nx1 - boolean [not used]
- closestEnemy Nx4 [not used]