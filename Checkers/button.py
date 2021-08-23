from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from piece import Piece
from enum import Enum


class Button(QPushButton):
    def __init__(self, pieceType, centerX, centerY, parent=None):
        super(Button, self).__init__(parent)
        self.piece = pieceType
        self.centerX = centerX
        self.centerY = centerY


    def set_piece(self, pieceType):
        self.piece = pieceType

    # def paintEvent(self, e):
    #     qp = QPainter()
    #     qp.begin(self)
    #     self.drawBrushes(qp)
    #     qp.end()
    #
    # def drawBrushes(self, qp):
    #     if self.piece == Piece.WHITE:
    #         qp.setBrush(QBrush(Qt.white, Qt.SolidPattern))
    #     elif self.piece == Piece.BLACK:
    #         qp.setBrush(QBrush(Qt.black, Qt.SolidPattern))
    #
    #     if self.piece != Piece.NONE:
    #         qp.setBrush(QBrush(Qt.red, Qt.SolidPattern))
    #         qp.drawEllipse(self.centerX, self.centerY, 15, 15)