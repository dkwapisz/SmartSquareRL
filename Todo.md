## TODO LIST:
- [x] Set new reward system for coins: 
  - **if coin is IN FoV** and:
    - player getting closer to closer coin -> +10
    - player move away from closer coin -> -10
  - getting coin with no change -> +50
- [x] Change direction states -> if something is for example UP and RIGHT (diagonal), it should be [1, 1, 0, 0] in state vector, not only closest direction
- [x] Direction to the closest coin -> should be exposed for DQN if coin is not in FoV?
- [x] "coinInFoV" should be as separate boolean state? -> yes
- [x] Shorten state vector for "isClosestObstacleBox" and "coinsNeeded" from [0, 1], [1, 0] to [0], [1]
- [ ] Closest wall/danger should be separate to different state -> if player is very close to wall/danger, expose this information to direction state
- [x] Think what about finish -> use finish in FoV mechanic same as coins?
- [ ] **IMPORTANT - FIX REWARDS (CHECK GIVING REWARDS PLAYING AT GAME AS NORMAL PLAYER) - broken reward: after collecting coin (GameStateHandling 167), collecting all coins (finish), check lastDistanceWall reward.**


### New Reward System:

- Touching wall: -10
- Touching box: -10
- Collecting coin: +50
- Touching enemy: -100
- Getting closer to coin **IF** coin is in FoV: +1
- Moving away from coin **IF** coin is in FoV: -10
- Reaching finish if all coins were collected: +100
- Out of time (20s): -100 -> time is reset after collecting coin
- Getting coin in FoV **IF** already collected 1 coin: +30
- Losing coin from FoV (not apply to coin that have just been collected): -50
- Getting closer to finish **AFTER** collecting every coin **IF** finish is in FoV: +1
- Moving away from finish **AFTER** collecting every coin **IF** finish is in FoV: -10
- Getting closer to lastDiscoveredWall **IF** coin not in FoV: +1
- Moving away from lastDiscoveredWall **IF** coin not in FoV: -10
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