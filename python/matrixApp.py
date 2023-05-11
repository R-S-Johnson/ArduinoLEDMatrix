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
                button = tk.Button(self.master, command=lambda i=i, j=j: self.on_button_click(i, j), width=5, bg="white")
                button.grid(row=i, column=j)
                row.append(button)
            self.buttons.append(row)
            saveButton = tk.Button(self.master, command=self.saveButtonPress, text="save")
            saveButton.grid(row=self.rows, column=self.cols-1)

    def on_button_click(self, i, j):
        _, color = colorchooser.askcolor()
        if color:
            self.buttons[i][j].config(bg=color)

    def saveButtonPress(self):
        f = open("color.txt", 'w')
        for row in self.buttons:
            for button in row:
                f.write(str(button.cget('bg')) + "\n")
        f.close()
        self.master.destroy()


def main():
    root = tk.Tk()
    ui = MatrixUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()
