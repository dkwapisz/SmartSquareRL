# SmartSquareRL
> The project is created for an Engineering Thesis.

## Table of contents
- [General](#General)
- [Gameplay](#Gameplay)
- [Technologies/libraries used](#Technologies/libraries-used)
- [How to run](#How-to-run)

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

## How to run

1. Install SFML library: `sudo apt-get install libsfml-dev`. If you use server without GPU for training, you can use [SFML-pi](https://github.com/mickelson/sfml-pi) version, which doesn't required X11 display  
2. Install gRPC for C++, follow [THIS](https://grpc.io/docs/languages/cpp/quickstart/) steps.  
3. Provide correct path to gRPC in [cMake file](include_directories("/home/dkwapisz/.local/include")).  
4. Compile C++ project.  
5. Run servers and clients by following scripts (it is necessary to fix paths):
  - [Servers](https://github.com/dkwapisz/SmartSquareRL/blob/main/start_servers.sh) <- provide WORKER_IDs and ports you want to you
  - [Clients](https://github.com/dkwapisz/SmartSquareRL/blob/main/start_workers.sh) <- provide ports you want to use
  - To easily kill server processes, use [killServers.sh](https://github.com/dkwapisz/SmartSquareRL/blob/main/kill_servers.sh).  
6. To test created models, use [TestNeuralNetwork](https://github.com/dkwapisz/SmartSquareRL/blob/main/RL/AI/TestNeuralNetwork.py).

To configure Neural Network or hyperparameters, modify [DDQN](https://github.com/dkwapisz/SmartSquareRL/blob/main/RL/AI/DDQN.py) file or provide parameters into [learning_parameters](https://github.com/dkwapisz/SmartSquareRL/blob/main/RL/LearningData/learning_params.json).  

To calculate: usage of ReplayBuffers or epsilon parameter decay use [Calculations](https://github.com/dkwapisz/SmartSquareRL/blob/main/RL/LearningData/Calculations.py) file.

To generate random maps, use scripts created in [Maps](https://github.com/dkwapisz/SmartSquareRL/tree/main/Game/GameFiles/Maps) directory. Remember to fix MAP_SIZE variables in [Game](https://github.com/dkwapisz/SmartSquareRL/blob/ca81ff270848b2655b7189561335b594754fd299/Game/GameFiles/Game.cpp#L4) and [GameDataHandling](https://github.com/dkwapisz/SmartSquareRL/blob/ca81ff270848b2655b7189561335b594754fd299/RL/AI/GameDataHandling.py#L15) if needed. Also fix map limit in [Game](https://github.com/dkwapisz/SmartSquareRL/blob/ca81ff270848b2655b7189561335b594754fd299/Game/GameFiles/Game.cpp#L214) file. Provide correct path if you change map size and fix loop parameters for number of maps you want to use in [Level](https://github.com/dkwapisz/SmartSquareRL/blob/ca81ff270848b2655b7189561335b594754fd299/Game/GameFiles/Level.cpp#L61) file.

All trained models will be saved inside [LearningData](https://github.com/dkwapisz/SmartSquareRL/tree/main/RL/LearningData) in NeuralNetworks directory which is created when the network is saved. All logs collected during trainings will also be saved in [LearningData](https://github.com/dkwapisz/SmartSquareRL/tree/main/RL/LearningData).

If you switch between MLP and CNN models, switch everything which is needed in following files:  [DDQN](https://github.com/dkwapisz/SmartSquareRL/blob/faedb7cf720a97479e76718df1be027037d6c122/RL/AI/DDQN.py#L36), [GameDataHandling](https://github.com/dkwapisz/SmartSquareRL/blob/faedb7cf720a97479e76718df1be027037d6c122/RL/AI/GameDataHandling.py#L68), [TestNeuralNetwork](https://github.com/dkwapisz/SmartSquareRL/blob/faedb7cf720a97479e76718df1be027037d6c122/RL/AI/TestNeuralNetwork.py#L45).

