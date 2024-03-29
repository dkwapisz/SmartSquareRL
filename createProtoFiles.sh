# Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
# License:      GPLv3

/home/dkwapisz/grpc/cmake/build/third_party/protobuf/protoc -I=./Game/ProtoClient/ProtoFiles --cpp_out=./Game/ProtoClient/ProtoFiles ./Game/ProtoClient/ProtoFiles/game.proto
/home/dkwapisz/grpc/cmake/build/third_party/protobuf/protoc -I=./Game/ProtoClient/ProtoFiles --grpc_out=./Game/ProtoClient/ProtoFiles --plugin=protoc-gen-grpc=/home/dkwapisz/grpc/cmake/build/grpc_cpp_plugin ./Game/ProtoClient/ProtoFiles/game.proto
python3 -m grpc_tools.protoc -I./RL/AI/ProtoFiles --python_out=./RL/AI/ProtoFiles  --grpc_python_out=./RL/AI/ProtoFiles  ./RL/AI/ProtoFiles/game.proto
