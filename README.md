# How to Run

from this repo, run:

```sh
mkdir build devel logs
catkin build
source devel/setup.bash
roslaunch turtles.launch
```
Open another terminal, then
```sh
rostopic echo rosout/msg
```
