# Command Line Secret Santa Program

## Information
Command line program that randomly picks Secret Santa Partners

Written by Toshi Tabata (18/12/2019)

## Purpose
Made as a fun event between friends to see what solution we would all
come up with for a secret santa program.

## Program summary
  1. Gets a list of participant's names from stdin
  2. Creates a copy of this list
  3. Shuffles the copy of the list until each item has a new index
  4. Pairs based on matching indices (i.e. list1[i] paired with list2[i])

## Example Usage
```
Please give me a list of names separated by a \n!
Give an EOF (control + d) when you're done
p1
p2
p3
p4
p5
p1 is p2's secret santa!
p2 is p3's secret santa!
p3 is p4's secret santa!
p4 is p5's secret santa!
p5 is p1's secret santa!
```
