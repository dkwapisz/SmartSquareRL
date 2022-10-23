ps aux | grep WORKER_ID | awk '{print $2}' | xargs kill -9 $2
