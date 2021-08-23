from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from game_manager import GameManager
import sys

if __name__ == "__main__":
    App = QApplication(sys.argv)

    if len(sys.argv) == 3:
        game = GameManager(sys.argv[1], sys.argv[2])
    else:
        game = GameManager()

    sys.exit(App.exec())


