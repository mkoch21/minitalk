_**21 School/Ecole 42** Project_

# Minitalk

Problem statement: [en.subject.pdf](https://github.com/mkoch21/minitalk/blob/main/en.subject.pdf)

To code a small data exchange program using UNIX signals.

## Installation and execution
Mandatory part:
```
make
//in first terminal window:
./server
//server returns: Server process id = 50465
//in second terminal window:
./client 50465 "Some text"
./client 50465 "Some more text"
```

Bonus part
```
make bonus
//in first terminal window:
./server_bonus
//server returns: Server process id = 52760
//in second terminal window:
./client_bonus 52760 "Some text"
./client_bonus 52760 "Some more text"
```
