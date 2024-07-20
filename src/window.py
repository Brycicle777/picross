from tkinter import *

class Window:
    def __init__(self, width, height, num_rows=10, num_cols=10, title="Picross"):
        self.__root = Tk()
        self.__root.title(title)
        self.__root.protocol("WM_DELETE_WINDOW", self.close)
        self.frame = Frame(self.__root)
        self.__root.rowconfigure(0, weight=1)
        self.__root.columnconfigure(0, weight=1)
        self.frame.grid(row=0, column=0, sticky="news")
        self.grid = Frame(self.frame)
        self.grid.grid(stick="news", column=0, row=7, columnspan=1)
        self.frame.rowconfigure(7, weight=1)
        self.frame.columnconfigure(0, weight=1)
        #Alright probably need to split this out into something separate
        #But at least tested that it worked
        #Need separate areas for displaying numbers and stuff next
        #Also to have buttons be "empty"
        #Also to actually understand this code (copied from phone, no wifi rn)
        #Could have timer in top-left too
        
        for x in range(num_cols):
            for y in range(num_rows):
                btn = Button(self.frame)
                btn.grid(column=x, row=y, sticky="news")

        self.frame.columnconfigure(tuple(range(num_cols)), weight=1)
        self.frame.rowconfigure(tuple(range(num_rows)), weight=1)
        self.running = False

    def redraw(self):
        self.__root.update_idletasks()
        self.__root.update()

    def wait_for_close(self):
        self.running = True
        while self.running:
            self.redraw()

    def close(self):
        self.running = False

