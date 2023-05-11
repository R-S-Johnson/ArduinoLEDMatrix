import tkinter as tk
from tkinter import colorchooser

class MatrixUI:
    def __init__(self, master, rows=15, cols=12):
        self.master = master
        self.rows = rows
        self.cols = cols
        self.buttons = []

        for i in range(self.rows):
            row = []
            for j in range(self.cols):
                button = tk.Button(self.master, command=lambda i=i, j=j: self.onButtonClick(i, j), width=5, bg="#000000")
                button.grid(row=i, column=j)
                row.append(button)
            self.buttons.append(row)
            saveButton = tk.Button(self.master, command=self.saveButtonPress, text="save")
            saveButton.grid(row=self.rows, column=self.cols-1)

    def onButtonClick(self, i, j):
        _, color = colorchooser.askcolor()
        if color:
            self.buttons[i][j].config(bg=color)

    def saveButtonPress(self):
        f = open("color.txt", 'w')
        for rowi in range(len(self.buttons)):
            for colj in range(len(self.buttons[rowi])):
                color = self.buttons[rowi][colj].cget("bg")
                if color != "#000000":
                    colorRGB = tuple(int(color.lstrip("#")[i:i+2], 16) for i in (0, 2, 4))
                    f.write(str(rowi) + " "
                            + str(colj) + " "
                            + str(colorRGB[0]) + " "
                            + str(colorRGB[1]) + " "
                            + str(colorRGB[2]) + "\n")
        f.close()
        self.master.destroy()


def main():
    root = tk.Tk()
    ui = MatrixUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()
