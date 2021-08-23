import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from enum import Enum
from piece import Piece
from button import Button

class CheckersUI(QWidget):
    def __init__(self, state):
        super().__init__()

        # dimensions
        self.state = state
        self.width = 450
        self.height = 470 + 60

        self.setObjectName("Window")
        self.resize(self.width, self.height)
        self.setStyleSheet(
            "background-color: rgb(200, 200, 200)"
        )
        self.setMinimumSize(self.width, self.height)
        self.setMaximumSize(self.width, self.height)
        self.gridLayoutWidget = QWidget(self)
        self.gridLeftMargin = 10
        self.gridTopStart = 60
        self.gridLayoutWidget.setGeometry(QRect(self.gridLeftMargin, self.gridTopStart, 430, 430))
        self.gridLayoutWidget.setObjectName("gridLayoutWidget")
        self.gridLayout = QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")

        self.label = QLabel(self)
        self.labelHeight = 30
        self.label.setGeometry(QRect(150, 10, 150, self.labelHeight))

        font = QFont()
        font.setFamily("Arial")
        font.setPointSize(20)
        font.setBold(True)
        font.setWeight(75)

        self.label.setFont(font)
        self.label.setAlignment(Qt.AlignCenter)
        self.label.setObjectName("turnLabel")
        self.line = QFrame(self)
        self.lineHeight = 20
        self.line.setGeometry(QRect(10, 40, self.width - 20, self.lineHeight))
        lineFont = QFont()
        lineFont.setPointSize(16)
        lineFont.setBold(True)
        lineFont.setWeight(75)
        self.line.setFont(lineFont)
        self.line.setFrameShape(QFrame.HLine)
        self.line.setObjectName("line")

        # Initialize buttons
        self.button_size = 50
        self.cells = []
        startWhite = True
        for x in range(8):
            temp = []
            startWhite = not startWhite
            for y in range(8):
                btn_center_x = self.gridLeftMargin + ((y - 1) * self.button_size) + (self.button_size / 2)
                btn_center_y = self.gridTopStart + ((x-1) * self.button_size) + (self.button_size / 2)
                btn = Button(state[x][y], btn_center_x, btn_center_y)
                # btn = QPushButton()
                btn.setFixedHeight(self.button_size)
                btn.setFixedWidth(self.button_size)
                if startWhite and y % 2 == 1:
                    btn.setStyleSheet(
                        "background-color: rgb(210,161,86)"
                    )
                elif startWhite and y % 2 == 0:
                    btn.setStyleSheet(
                        "background-color: rgb(124,100,68)"
                    )
                elif not startWhite and y % 2 == 0:
                    btn.setStyleSheet(
                        "background-color: rgb(210,161,86)"
                    )
                elif not startWhite and y % 2 == 1:
                    btn.setStyleSheet(
                        "background-color: rgb(124,100,68)"
                    )

                temp.append(btn)
                self.gridLayout.addWidget(btn, x, y, 1, 1)
            self.cells.append(temp)


        # Initial state
        self.label.setText("White Turn")

        # Show UI
        self.show()

    # def paintEvent(self, e):
    #     qp = QPainter()
    #     qp.begin(self)
    #     self.drawBrushes(qp)
    #     qp.end()


    # def drawBrushes(self, qp):
    #     for i, row in enumerate(self.state):
    #         for j, cell in enumerate(row):
    #             if cell == Piece.WHITE:
    #                 qp.setBrush(QBrush(Qt.white, Qt.SolidPattern))
    #             elif cell == Piece.BLACK:
    #                 qp.setBrush(QBrush(Qt.black, Qt.SolidPattern))
    #
    #             if cell != Piece.NONE:
    #                 qp.setBrush(QBrush(Qt.red, Qt.SolidPattern))
    #                 qp.drawEllipse((self.button_size * j) + self.gridLeftMargin,
    #                                 (self.button_size * i) + self.gridTopStart,
    #                                 15, 15)

    def set_turn_text(self, text):
        self.label.setText(text)

    def set_state(self, state):
        self.state = state

