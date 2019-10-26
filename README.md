# fillit

This is the story of a piece of Tetris, one little square and a dev walk into a bar...

# Description

This is a project about developing an algorithm that will fit tetriminoes provided as an input to the smallest possible square in shortest amount of time. Tetriminoes are the object pieces from well-know game "Tetris".

![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/50/All_5_free_tetrominoes.svg/200px-All_5_free_tetrominoes.svg.png)

In this project, a student will learn how to solve recurring problems (finding an optimal solution among many other possibilites). It is also great opportnunity to practice data structure implementation in practice.

# Installation

Clone the repository to a directory.

```
git clone https://github.com/ytanne/fillit.git fillit
```

Run make to get fillit executable.

```
cd fillit && make && make clean
```

# Usage
After installing, you can test the code by storing custom valid tetriminoes in file, and providing it as an input. Firstly, lets create a test case by storing the following tetriminoes in a file `test.fillit`:

```
....
.##.
##..
....

....
.###
...#
....

...#
...#
...#
...#

.#..
###.
....
....
```

Then pass this file as a standard input to the obtained executable:

```
./fillit test.fillit
```

That will give us following output:

<img src="https://github.com/ytanne/fillit/blob/master/example.png" width="400" height="200"/>

# Authors and acknowledgment
I would not be able to finish this project without [Misha](https://github.com/lisov1y). Big thanks for the collaboration!

# Comments

I really enjoy Mr. Robot TV show !

<img src="https://i.imgur.com/e5MGWSa.jpg" width="300" height="300"/>
