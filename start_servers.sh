# Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
# License:      GPLv3

cd /home/dkwapisz/SmartSquareRL/RL/AI

/home/dkwapisz/anaconda3/envs/RL/bin/python /home/dkwapisz/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 4 --PORT 50051 &
/home/dkwapisz/anaconda3/envs/RL/bin/python /home/dkwapisz/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 5 --PORT 50052 &
/home/dkwapisz/anaconda3/envs/RL/bin/python /home/dkwapisz/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 6 --PORT 50053 &
/home/dkwapisz/anaconda3/envs/RL/bin/python /home/dkwapisz/SmartSquareRL/RL/AI/ProtoServer.py --WORKER_ID 7 --PORT 50054
