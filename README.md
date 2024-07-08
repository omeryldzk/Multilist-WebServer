# Web Browser History - Sorted Multilevel Linked List

## Overview

This project implements a sorted multilevel linked list to manage a web browser's history. The data structure is a 2D structure where the first dimension keeps the date (`DateNode`), and the second dimension keeps the time and site name (`TSiteNode`).

## Data Structure

The linked list is designed with two main types of nodes:
- **DateNode**: Represents a node with a specific date.
- **TSiteNode**: Represents a node with the time and site name.

## Functionalities

### Add Node

Adds a record to the sorted multilevel linked list by date and time.

### Remove Node

Removes a record from the list by date and time.

### Print List

Prints the entire list sorted by date and time.

## Classes

### DateNode

Represents a date node with pointers to next, previous, and up nodes.

### TSiteNode

Represents a time and site node with a pointer to the up node.

### MultiList

Manages the multilevel linked list with functionalities to add, remove, and print nodes.

