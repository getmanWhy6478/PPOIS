import tkinter as tk
from model import DataModel
from view import MainView
from controller import AppController

if __name__ == "__main__":
    root = tk.Tk()
    m, v = DataModel(), MainView(root)
    c = AppController(m, v)
    root.mainloop()