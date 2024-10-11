from tkinter import *
from PIL import ImageTk,Image

root=Tk()
root.title('abcd')
root.iconbitmap("google icon.png")


button_quit = Button(root, text='Exit Program', command=root.quit)

button_quit.pack()






root.mainloop()