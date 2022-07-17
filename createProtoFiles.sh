/usr/local/bin/protoc -I=./Game/ProtoClient/ProtoFiles --cpp_out=./Game/ProtoClient/ProtoFiles ./Game/ProtoClient/ProtoFiles/game.proto
/usr/local/bin/protoc -I=./Game/ProtoClient/ProtoFiles --grpc_out=./Game/ProtoClient/ProtoFiles --plugin=protoc-gen-grpc=/home/dkwapisz/grpc/cmake/build/grpc_cpp_plugin ./Game/ProtoClient/ProtoFiles/game.proto
python -m grpc_tools.protoc -I./RL/ProtoServer/ProtoFiles --python_out=./RL/ProtoServer/ProtoFiles  --grpc_python_out=./RL/ProtoServer/ProtoFiles  ./RL/ProtoServer/ProtoFiles/game.proto
