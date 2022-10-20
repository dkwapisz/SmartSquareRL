conda activate RL

cd /home/dawidml/SmartSquareRL/RL/AI

nohup /home/dawidml/miniconda3/envs/RL/bin/python /home/dawidml/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 0 --PORT 50051 &
nohup /home/dawidml/miniconda3/envs/RL/bin/python /home/dawidml/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 1 --PORT 50052 &
nohup /home/dawidml/miniconda3/envs/RL/bin/python /home/dawidml/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 2 --PORT 50053 &
nohup /home/dawidml/miniconda3/envs/RL/bin/python /home/dawidml/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 3 --PORT 50054 &
nohup /home/dawidml/miniconda3/envs/RL/bin/python /home/dawidml/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 4 --PORT 50055 &
nohup /home/dawidml/miniconda3/envs/RL/bin/python /home/dawidml/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 5 --PORT 50056 &
nohup /home/dawidml/miniconda3/envs/RL/bin/python /home/dawidml/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 6 --PORT 50057 &

sleep 5

cd /home/dawidml/SmartSquareRL/cmake-build-release

nohup /home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50051 &
nohup /home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50052 &
nohup /home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50053 &
nohup /home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50054 &
nohup /home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50055 &
nohup /home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50056 &
nohup /home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50057