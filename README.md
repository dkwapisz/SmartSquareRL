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
- C++ 20
- SFML Library
- Python 3.10
- Pillow Library
- gRPC
- Protobuf


## Reinforcement Learning algorithms:

1. Deep Q-Learning

### Rewards:
#### Map 1
- Touching the wall: -10
- Touching the box: -10
- Touching enemy: -100
- Collecting the coin: +10
- Reaching the finish: +100
- Else: 0