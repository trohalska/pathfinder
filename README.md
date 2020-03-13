# pathfinder
 ### description:
 ```
 Ucode project: develop an algorithm that finds the shortest paths between the points.
 ---
 Designed using the Dijksta algorithm, works on simple graphs.
 Finds the shortest path, and if there are another shortest paths of the same length, find only one more as well.
 Gets input data from file.
 ```
 ### usage:
 ```
 1. git clone
 2. make
 3. ./pathfinder [filename]
 ```
 **input example:**
 ```
 4
 Greenland-Bananal,8
 Fraser-Greenland,10
 Bananal-Fraser,3
 Java-Fraser,5
 ```
 **output example:**
 ```
 ./pathfinder path | cat -e
 ========================================$
 Path: Greenland -> Bananal$
 Route: Greenland -> Bananal$
 Distance: 8$
 ========================================$
 ========================================$
 Path: Greenland -> Fraser$
 Route: Greenland -> Fraser$
 Distance: 10$
 ========================================$
 ========================================$
 Path: Greenland -> Java$
 Route: Greenland -> Fraser -> Java$
 Distance: 10 + 5 = 15$
 ========================================$
 ========================================$
 Path: Bananal -> Fraser$
 Route: Bananal -> Fraser$
 Distance: 3$
 ========================================$
 ========================================$
 Path: Bananal -> Java$
 Route: Bananal -> Fraser -> Java$
 Distance: 3 + 5 = 8$
 ========================================$
 ========================================$
 Path: Fraser -> Java$
 Route: Fraser -> Java$
 Distance: 5$
 ========================================$
```
