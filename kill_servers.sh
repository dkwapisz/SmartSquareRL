# Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
# License:      GPLv3

ps aux | grep WORKER_ID | awk '{print $2}' | xargs kill -9 $2
