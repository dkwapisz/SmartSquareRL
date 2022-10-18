# SmartSquareRL
> The project is created for an Engineering Thesis.

## Table of contents
- [General](#General)
- [Gameplay](#Gameplay)
- [Technologies/libraries used](#Technologies/libraries-used)

## General
The repository will contain the game and a Reinforcement Learning algorithm that will learn to play the game. Currently, the game is finished. The base version of the game can be found [here](https://github.com/dkwapisz/SmartSquareGame).

The game was written in C++ to be as optimized as possible. The RL algorithm will be written in Python. The gRPC library and Protobuffer will probably be used to communicate between the game and the AI.

## Gameplay
[Here you can check how game looks like.](https://youtube.com/shorts/BdZh8jy2RsA?feature=share)

## Technologies/libraries used:
- C++ 17
- SFML Library 2.5.1
- Python 3.10
- Pillow Library
- gRPC 1.46.3
- Protobuf 3.19.4.0


## Reinforcement Learning algorithm:
### Double Deep Q-Network

### Rewards:
**Positive:**
- Collecting coin: +75
- Discovering new floor part: +1
- Winning level: +500

**Negative:**
- Collision with wall: -20
- Moving away from coin (counting in 8 directions -> UP, UP-RIGHT, RIGHT, RIGHT-DOWN etc): -5
- Losing level when all coins have not been collected: `-300 + (coinsLeft * (-125))`
- Losing level when all coins have been collected: -500

**Rewards/punishments TBD:**
- Collision with box: -20
- Collision with enemy: -100
