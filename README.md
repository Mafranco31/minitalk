# Minitalk

This exercice is a client / server discussion.

## Description

Here the objective is to create a program ./server that gives a key to interact with it, using signals.

Then a program ./client that enter the key of the server and talk with it.

## Installation

```bash
git clone https://github.com/Mafranco31/minitalk.git minitalk && cd minitalk && make
```

## Use minitalk

Start the server by running ./server, it will give you the PID to communicate with it.

Then in a new window, run the ./client with as argument the PID and the message you want the server to print.
