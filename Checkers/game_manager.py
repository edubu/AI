from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from enum import Enum
import sys

class Agent(Enum):
    HUMAN = 0
    BOT = 1

class Piece(Enum):
    NONE = 0
    WHITE = 1
    BLACK = 2
    WHITE_KING = 3
    BLACK_KING = 4

class GameManager(QMainWindow):
    def __init__(self, agent1, agent2):
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
        self.setup_ui()

        # Start the game
        #self.start_game()


    def setup_ui(self):
        self.setWindowTitle("Checkers")
        self.setGeometry(100, 100, 500, 700)

        #show components
        self.show()


