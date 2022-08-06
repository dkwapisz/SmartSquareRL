## TODO LIST:
- [x] Set new reward system for coins: 
  - **if coin is IN FoV** and:
    - player getting closer to closer coin -> +10
    - player move away from closer coin -> -10
  - getting coin with no change -> +50
- [x] Change direction states -> if something is for example UP and RIGHT (diagonal), it should be [1, 1, 0, 0] in state vector, not only closest direction
- [ ] Direction to the closest coin -> should be exposed for DQN if coin is not in FoV?
- [ ] "coinInFoV" should be as separate boolean state?
- [x] Shorten state vector for "isClosestObstacleBox" and "coinsNeeded" from [0, 1], [1, 0] to [0], [1]
- [ ] Closest wall/danger should be separate to different state -> if player is very close to wall/danger, expose this information to direction state
- [ ] Think what about finish -> use finish in FoV mechanic same as coins?


### New Reward System:

- Touching wall: -10
- Touching box: -10
- Collecting coin: +50
- Touching enemy: -100
- Getting closer to coin **IF** coin is in FoV: +10
- Moving away from coin **IF** coin is in FoV: -10
- Reaching finish if all coins were collected: +100
- Out of time (20s): -100 -> time is reset after collecting coin
- Getting closer to finish **AFTER** collecting every coin **IF** finish is in FoV: +10
- Moving away from finish **AFTER** collecting every coin **IF** finish is in FoV: -10
- Else: 0

### New State:

- closestObstacleBox Nx1 - boolean
- coinsNeeded Nx1 - boolean
- closestObstacle Nx4
- closestCoin Nx4
- closestEnemy Nx4
- finishDirection Nx4
- coinInFoV Nx1 (?)