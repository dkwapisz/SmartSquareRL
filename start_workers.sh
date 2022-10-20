cd /home/dawidml/SmartSquareRL/cmake-build-release

Xvfb -ac :99 -screen 0 1280x1024x24 > /dev/null 2>&1 &
/home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50051 &
/home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50052 &
/home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50053 &
/home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50054 &
/home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50055 &
/home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50056 &
/home/dawidml/SmartSquareRL/cmake-build-release/SmartSquareRL 50057