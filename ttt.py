from tkinter import *
from PIL import ImageTk,Image

root=Tk()
root.title("tic_tac_toe")



# for the letter chosen in first interface by Player 1
order=[]
def chosen_x():
    global cho_let
    global order
    cho_let='X'
    order.append('X')
    order.append('O')
    print(order)
    label.destroy()
    button_x.destroy()
    button_o.destroy()
    return game()
def chosen_o():
    global cho_let
    global order
    cho_let='O'
    order.append('O')
    order.append('X')
    print(order)
    label.destroy()
    button_x.destroy()
    button_o.destroy()
    print("chosen")
    return game()

print(order)
num=0
def game():    
    print("game started")
    but_dict={}
    def button_1():
        global button1
        global num
        global but_1
        button1=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button1.grid(row=1,column=0)
        but_dict[order[num]]=(1,0)
        print(but_dict) 
        if num==1:
            num=0
        else:
            num=1
        
        print(num)
        print(cho_let)
    def button_2():
        global button2
        global num
        button2=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button2.grid(row=1,column=1)
        but_dict[order[num]]=(1,1)
        if num==1:
            num=0
        else:
            num=1
    def button_3():
        global button3
        global num
        button3=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button3.grid(row=1,column=2)
        but_dict[order[num]]=(1,2) 
        if num==1:
            num=0
        else:
            num=1
    def button_4():
        global button4
        global num
        button4=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button4.grid(row=2,column=0)
        but_dict[order[num]]=(2,0) 
        if num==1:
            num=0
        else:
            num=1
    def button_5():
        global button5
        global num
        button5=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button5.grid(row=2,column=1)
        but_dict[order[num]]=(2,1)  
        if num==1:
            num=0
        else:
            num=1
    def button_6():
        global button6
        global num
        button6=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button6.grid(row=2,column=2)
        but_dict[order[num]]=(2,2)
        if num==1:
            num=0
        else:
            num=1
    def button_7():
        global button7
        global num
        button7=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button7.grid(row=3,column=0)
        but_dict[order[num]]=(3,0)
        if num==1:
            num=0
        else:
            num=1
    def button_8():
        global button8
        global num
        button8=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button8.grid(row=3,column=1)
        but_dict[order[num]]=(3,1)
        if num==1:
            num=0
        else:
            num=1
    def button_9():
        global button9
        global num
        button9=Label(root, text=order[num], bg='white', borderwidth=0, padx=30,pady=30)
        button9.grid(row=3,column=2)
        but_dict[order[num]]=(3,2)
        if num==1:
            num=0
        else:
            num=1
            
    label=Label(root, text='TIC TAC TOE')    
    button1=Button(root, text='a', borderwidth=0, padx=29,pady=29, bg='white', command=button_1)
    button2=Button(root, text='b', borderwidth=0, padx=29,pady=29, bg='white', command=button_2)
    button3=Button(root, text='c', borderwidth=0, padx=29,pady=29, bg='white', command=button_3)
    button4=Button(root, text='d', borderwidth=0, padx=29,pady=29, bg='white', command=button_4)
    button5=Button(root, text='e', borderwidth=0, padx=29,pady=29, bg='white', command=button_5)
    button6=Button(root, text='f', borderwidth=0, padx=29,pady=29, bg='white', command=button_6)
    button7=Button(root, text='g', borderwidth=0, padx=29,pady=29, bg='white', command=button_7)
    button8=Button(root, text='h', borderwidth=0, padx=29,pady=29, bg='white', command=button_8)
    button9=Button(root, text='i', borderwidth=0, padx=29,pady=29, bg='white', command=button_9)    
    label.grid(row=0,column=0, columnspan=10) 
    button1.grid(row=1,column=0)
    button2.grid(row=1,column=1)
    button3.grid(row=1,column=2)
    button4.grid(row=2,column=0)
    button5.grid(row=2,column=1)
    button6.grid(row=2,column=2)
    button7.grid(row=3,column=0)
    button8.grid(row=3,column=1)
    button9.grid(row=3,column=2) 
    
    for key,value in but_dict.items():
        value_list=list(but_dict.values())
        for i in range(1,4):
            for j in range(1,4):
                 print('')                                   #skvsjvndidvndijvn
            
       


    

    
    
    
    



# for the first interface
label=Label(root, text='Player1 please select one of them', padx=100)
button_x=Button(root, text='X', borderwidth=10, padx=30, pady=10, command=chosen_x)
button_o=Button(root, text='O', borderwidth=10, padx=30, pady=10, command=chosen_o)


label.grid(row=0, column=0,columnspan=2)
button_x.grid(row=1, column=0)
button_o.grid(row=1, column=1)







root.mainloop()