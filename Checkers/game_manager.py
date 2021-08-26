# from PyQt5.QtWidgets import *
# from PyQt5 import QtCore, QtGui
# from PyQt5.QtGui import *
# from PyQt5.QtCore import *
from enum import Enum
from ui_manager import *
import sys
from piece import Piece

class Agent(Enum):
    HUMAN = 0
    BOT = 1

class GameManager():
    def __init__(self, agent0="human", agent1="human"):
        super().__init__()

        # identify agent types
        if agent0 == "human":
            self.agent0 = Agent.HUMAN
        elif agent0 == "bot":
            self.agent0 = Agent.BOT
        if agent1 == "human":
            self.agent1 = Agent.HUMAN
        elif agent1 == "bot":
            self.agent1 = Agent.BOT

        self.agents = []
        if agent0 == Agent.HUMAN:
            self.agents.append()

        # create initial state
        self.state = [[Piece.NONE, Piece.WHITE, Piece.NONE, Piece.WHITE, Piece.NONE, Piece.WHITE, Piece.NONE, Piece.WHITE],
                      [Piece.WHITE, Piece.NONE, Piece.WHITE, Piece.NONE, Piece.WHITE, Piece.NONE, Piece.WHITE, Piece.NONE],
                      [Piece.NONE, Piece.WHITE, Piece.NONE, Piece.WHITE, Piece.NONE, Piece.WHITE, Piece.NONE, Piece.WHITE],
                      [Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE],
                      [Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE, Piece.NONE],
                      [Piece.BLACK, Piece.NONE, Piece.BLACK, Piece.NONE, Piece.BLACK, Piece.NONE, Piece.BLACK, Piece.NONE],
                      [Piece.NONE, Piece.BLACK, Piece.NONE, Piece.BLACK, Piece.NONE, Piece.BLACK, Piece.NONE, Piece.BLACK],
                      [Piece.BLACK, Piece.NONE, Piece.BLACK, Piece.NONE, Piece.BLACK, Piece.NONE, Piece.BLACK, Piece.NONE]]

        # Create UI
        self.ui = CheckersUI(self.state)

        # Start the game
        self.startGame()

    def startGame(self):
        # White: 0; Black: 1
        turn = 0
        isActive = True

        while isActive:
            self.getAction(turn)

    def getAction(self, turn):
        if turn == 0:
            if self.agent0 == Agent.BOT:


