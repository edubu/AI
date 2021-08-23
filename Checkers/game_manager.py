# from PyQt5.QtWidgets import *
# from PyQt5 import QtCore, QtGui
# from PyQt5.QtGui import *
# from PyQt5.QtCore import *
from enum import Enum
from ui_manager import *
import sys

class Agent(Enum):
    HUMAN = 0
    BOT = 1

class GameManager():
    def __init__(self, agent1="human", agent2="human"):
        super().__init__()

        # identify agent types
        if agent1 == "human":
            self.agent1 = Agent.HUMAN
        elif agent1 == "bot":
            self.agent1 = Agent.BOT
        if agent2 == "human":
            self.agent2 = Agent.HUMAN
        elif agent2 == "bot":
            self.agent2 = Agent.BOT

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
        #self.ui.set_state(self.state)

        # Start the game
        # self.start_game()